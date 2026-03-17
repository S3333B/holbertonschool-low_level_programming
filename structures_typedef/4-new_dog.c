#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: pointer to new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_d;
	char *name_copy;
	char *owner_copy;

	if (name == NULL || owner == NULL)
		return (NULL);

	new_d = malloc(sizeof(dog_t));
	if (new_d == NULL)
		return (NULL);

	name_copy = malloc(strlen(name) + 1);
	if (name_copy == NULL)
	{
		free(new_d);
		return (NULL);
	}
	strcpy(name_copy, name);

	owner_copy = malloc(strlen(owner) + 1);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(new_d);
		return (NULL);
	}
	strcpy(owner_copy, owner);

	new_d->name = name_copy;
	new_d->age = age;
	new_d->owner = owner_copy;

	return (new_d);
}
