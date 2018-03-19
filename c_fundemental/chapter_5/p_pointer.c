#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];


int readliness(char *lineptr[], int nlines);
void writeliness(char *lineptr[], int nlines);


void qsorts(char *lineptr[], int left, int right)
{
    int nlines;

    if ((nlines = readliness(lineptr, MAXLINES)) > 0){
        qsorts(lineptr, 0, nlines-1);
        writeliness(lineptr, nlines);
        return 0;
    }else{
        printf("error,: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getLine(char *, int);
char *allocs(int);

int readliness(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len=getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p = alloc(len) == NULL)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}



