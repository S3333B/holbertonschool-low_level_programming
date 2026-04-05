#include <stdlib.h>
#include <string.h>
#include "store.h"

void store_init(store_t *st)
{
	if (st)
		st->head = NULL;
}

static node_t *node_create(session_t *s)
{
	node_t *n = (node_t *)malloc(sizeof(*n));
	if (!n)
		return NULL;
	n->sess = s;
	n->next = NULL;
	return n;
}

static void node_release(node_t *n)
{
	if (!n)
		return;

	n->sess = NULL;
	n->next = NULL;
	free(n);
}

static int store_add_reject(session_t *s)
{
	if (s)
		session_destroy(s);
	return 0;
}

int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	if (!s)
		return 0;
	if (!st || !s->id)
		return store_add_reject(s);

	cur = st->head;
	while (cur) {
		if (cur->sess == s)
			return 0;
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, s->id) == 0)
			return store_add_reject(s);
		cur = cur->next;
	}

	n = node_create(s);
	if (!n)
		return store_add_reject(s);

	n->next = st->head;
	st->head = n;
	return 1;
}

session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return NULL;

	cur = st->head;
	while (cur) {
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
			return cur->sess;
		cur = cur->next;
	}
	return NULL;
}

int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;
	session_t *removed;

	if (out)
		*out = NULL;

	if (!st || !id)
		return 0;

	prev = NULL;
	cur = st->head;

	while (cur) {
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0) {
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;

			removed = cur->sess;

			if (out)
				*out = removed;
			else
				session_destroy(removed);
			cur->sess = NULL;
			node_release(cur);
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}

	return 0;
}

void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;
	st->head = NULL;
	while (cur) {
		next = cur->next;
		cur->next = NULL;

		session_destroy(cur->sess);
		cur->sess = NULL;
		node_release(cur);

		cur = next;
	}
}
