#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: null-terminated string to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t text_len;
	ssize_t bytes_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	text_len = 0;
	if (text_content != NULL)
	{
		while (text_content[text_len] != '\0')
			text_len++;
	}

	bytes_written = 0;
	if (text_len > 0)
		bytes_written = write(fd, text_content, text_len);

	if ((text_len > 0 && bytes_written == -1) ||
	    (text_len > 0 && (size_t)bytes_written != text_len) ||
	    close(fd) == -1)
		return (-1);

	return (1);
}
