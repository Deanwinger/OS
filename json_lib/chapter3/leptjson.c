#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#include "leptjson.h"
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef LEPT_PARSE_STACK_INIT_SIZE
#define LEPT_PARSE_STACK_INIT_SIZE 256
#endif

#define EXPECT(c, ch) do { assert(*c->json == (ch)); c->json++; } while(0)
#define ISDIGIT(ch) ((ch) > '0' && (ch) <= '9')
#define ISDIGIT1TO9(ch) ((ch) >= '1' && (ch) <= '9')
#define PUTC(c, ch)  do{ *(char*)lept_context_push(c, sizeof(char)) = (ch); } while(0)

typedef struct {
    const char *json;
    char *stack;
    size_t size, top;
} lept_context;

static void *lept_context_push(lept_context *c, size_t size) {
    void *ret;
    assert(size > 0);
    if ()
}