/*
 * function: func_02206750
 * address:  0x02206750
 * packet:   pkt_02206750
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj08348.h"
#include "../include/Obj24968.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_02206750(char *p)
{
    char *q = *(char * *)&((struct Obj08348 *)p)->f58;
    int *r = *(int * *)&((struct Obj24968 *)q)->f8;
    int v = r[0x28 / 4];

    if (v == 1) return;
    if (v == 2) return;
    if (v == 3) return;
    r[0x28 / 4] = 1;
}
