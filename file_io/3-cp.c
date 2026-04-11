#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * close_fd_or_exit - closes a file descriptor or exits on failure
 * @fd: file descriptor to close
 */
void close_fd_or_exit(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * write_all - writes all bytes from a buffer to a file descriptor
 * @fd: file descriptor to write to
 * @buffer: buffer containing data to write
 * @count: number of bytes to write
 *
 * Return: 1 on success, -1 on failure
 */
int write_all(int fd, char *buffer, ssize_t count)
{
	ssize_t total_written;
	ssize_t bytes_written;

	total_written = 0;
	while (total_written < count)
	{
		bytes_written = write(fd, buffer + total_written, count - total_written);
		if (bytes_written <= 0)
			return (-1);
		total_written += bytes_written;
	}

	return (1);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;
	ssize_t bytes_read;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd_or_exit(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	bytes_read = read(fd_from, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		if (write_all(fd_to, buffer, bytes_read) == -1)
		{
			close_fd_or_exit(fd_from);
			close_fd_or_exit(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

		bytes_read = read(fd_from, buffer, sizeof(buffer));
	}

	if (bytes_read == -1)
	{
		close_fd_or_exit(fd_from);
		close_fd_or_exit(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_fd_or_exit(fd_from);
	close_fd_or_exit(fd_to);

	return (0);
}
