#include 	<stdio.h>
#include 	<stdlib.h>
#define		HASHSIZE	101

typedef struct nlist Nlist;

struct nlist {
	Nlist *next;
	char *name;
	char *defn;
};

unsigned	hash(char *);
Nlist		*lalloc();
Nlist		*lookup(char *);
Nlist		*install(char *, char *);
void		undef(char *);
char		*sdup(char *);
int		scmp(char *, char *);
void		scpy(char *, char *);
int		slen(char *);

static Nlist *hashtab[HASHSIZE];

void main()
{
	Nlist *l;
	l = install("IN", "1");
	l = install("IN", "0");
	l = lookup("IN");
	if (l)
		printf("result: %s\tval: %s\n", l->name, l->defn); 
	undef("TEST");
	undef("IN");
	undef("IN");
	l = lookup("IN");
	if (l)
		printf("result: %s\tval: %s\n", l->name, l->defn); 

}

void undef(char *def)
{
	Nlist *np;

	if (!(np = lookup(def))) {
		printf("undef: %s not defined\n", def);
		return;
	}
	free(np->next);
	free(np->name);
	free(np->defn);
	free(np);
	hashtab[hash(def)] = 0;
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != 0; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

Nlist *install(char *name, char *defn)
{
	Nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == 0) {
		np = lalloc();
		if (np == 0 || (np->name = sdup(name)) == 0)
			return 0;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);	
	if ((np->defn = sdup(defn)) == 0) 
		return 0;
	return np;
}

Nlist *lookup(char *s)
{
	Nlist *np;
	for (np = hashtab[hash(s)]; np != 0; np = np->next) 
		if (scmp(s, np->name) == 0) 
			return np;
	return 0;
}

int scmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] == s2[c]; c++) {
		if (s1[c] == 0)
			return 0;
	}
	return s1[c] - s2[c];
}

Nlist *lalloc()
{
	return (Nlist *) malloc(sizeof(Nlist));
}

/* does not protect from overflow: user beware */
void scpy(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c]; c++) 
		s2[c] = s1[c];
}

int slen(char *s)
{
	int c;

	for (c = 0; s[c]; c++)
		;
	return c;
}

char *sdup(char *s)
{
	char *str;

	str = malloc(slen(s) + 1);
	scpy(s, str);
	return str;
}
