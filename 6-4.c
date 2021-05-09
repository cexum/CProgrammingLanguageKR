#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define	WORD	16

typedef struct tnode Tnode;

struct tnode {
	char *word;
	int count;
	Tnode *left;
	Tnode *right;
};

Tnode		*talloc();
Tnode		*addntree(Tnode *, int, char *);
Tnode		*pushdest(Tnode *, Tnode *);
Tnode		*addtree(Tnode *, char *);
void		treeprint(Tnode *);
int 		getwd(FILE *, char *, int);

void main(int argc, char **argv)
{
	FILE *fp;
	int c;
	char word[WORD];
	Tnode *src, *dest;

	if (argv[1] == NULL)
		exit(1);
	if ((fp = fopen(argv[1], "r")) == NULL)
		exit(1);
	src = dest = NULL;
	while (getwd(fp, word, WORD))
		src = addtree(src, word);
	dest = pushdest(src, dest);
	treeprint(dest);
	exit(0);
}

/* getwd: copies up to max bytes from fp into word */
int getwd(FILE *fp, char *word, int max)
{
	int c, len;

	while ((c = fgetc(fp)) && c != EOF && !isalpha(c))
		;
	ungetc(c, fp); // read too many, put it back
	len = 0;
	while ((c = fgetc(fp)) && c != EOF && isalpha(c))
		if (len < max - 1)
			word[len++] = c;
	word[len] = 0;
	return len;
}

/* addtree: pushes new incoming data to Tnode or increments count */
Tnode *addtree(Tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = 0;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

/* talloc: returns pointer to new node */
Tnode *talloc(void)
{
	return (Tnode*) malloc(sizeof(Tnode));
}

/* pushdest: an outer recursive function which walks a source Tnode */
Tnode *pushdest(Tnode *src, Tnode *dest)
{
        if (src != NULL) {
                dest = addntree(dest, src->count, src->word);
                pushdest(src->left, dest);
                pushdest(src->right, dest);
        }
	return dest;
}

/* addntree: copies data from source Tnode into a destination Tnode */
Tnode *addntree(Tnode *dest, int count, char *word)
{
	if (dest == NULL) {
		dest = talloc();
		dest->word = strdup(word);
		dest->count = count;
		dest->right = dest->left = NULL;
	} else if (dest->count < count) {
		dest->left = addntree(dest->left, count, word);
	} else {
		dest->right = addntree(dest->right, count, word);
	}
	return dest;
}

/* treeprint: prints data at each node */
void treeprint(Tnode *p)
{
	if (p) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
