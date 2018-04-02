#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include "leptjson.h"
#include <assert.h>  /* assert() */
#include <errno.h>   /* errno, ERANGE */
#include <math.h>    /* HUGE_VAL */
#include <stdlib.h>  /* NULL, malloc(), realloc(), free(), strtod() */
#include <string.h>  /* memcpy() */


#ifndef LEPT_PARSE_STACK_INIT_SIZE
#define LEPT_PARSE_STACK_INIT_SIZE 256

#define EXPECT(c, ch)    do { assert(*c->json == (ch)); c->json++; }while(0)
#define ISDIGIT(ch)      ((ch) >= '0' && (ch) <= '9')
#define ISDIGIT1TO9(ch)  ((ch) >= '1' && (ch) <= '9')
#define PUTC(c, ch)      do { *(char *)lept_context_push(c, sizeof(char)) = (ch); }while(0)

typedef struct {
    const char *json;
    char *stack;
    size_t size, top;
}lept_context;

static void *lept_context_push(lept_context *c, size_t size){
    void *ret;
    assert(size > 0);
    if (c->top + size >= c->size){
        if (c->size == 0)
            c->size = LEPT_PARSE_STACK_INIT_SIZE;
        while (c->top + size >= c->size)
            c->size += c->size >> 1;
        c->stack = (char *)realloc(c->stack, c->size);
    }
    ret = c->stack + c->top;
    c->size += size;
    return ret;
}

static void *lept_context_pop(lept_context *c, size_t size){
    assert(c->top >= size);
    return c->stack + (c->top -= size);
}

static void lept_parse_whitespace(lept_context *c){
    const char *p = c->json;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        p++;
    c->json = p;
}

static int lept_parse_literal(lept_context *c, lept_value *v. const char *literal, lept_type type){
    size_t i;
    EXPECT(c, literal[0]);
    for (i=0; literal[i+1]; i++)
        if (c->json[i] != literal[i+1])
        return LEPT_PARSE_INVALID_VALUE;
    c->json += 1;
    v->type = type;
    return LEPT_PARSE_OK;
}