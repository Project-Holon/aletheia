/*
 * function: func_021E0BA4
 * address:  0x021E0BA4
 * packet:   pkt_021E0BA4
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14239.h"
#include "../include/Obj23784.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021E0BA4(char *p, char *q)
{
    char *r = p + 0x8D0 + ((struct Obj23784 *)q)->f10 * 0x68;

    ((struct Obj14239 *)r)->f0 = 1;
    *(char * *)&((struct Obj14239 *)r)->f64 = q;
}
