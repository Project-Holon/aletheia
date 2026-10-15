/*
 * function: BTL_REC_SEL_StartFade
 * address:  0x021B9EB8
 * packet:   pkt_021B9EB8
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj05548.h"
#include "../include/Obj25721.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void BTL_REC_SEL_StartFade(char *a, int b, char *c, int d, int e, int f, int g, int h, int i)
{
    ((struct Obj25721 *)a)->f0 = 0;
    ((struct Obj05548 *)c)->f1C = d;
    ((struct Obj05548 *)c)->f20 = e;
    ((struct Obj05548 *)c)->f24 = f;
    ((struct Obj05548 *)c)->f28 = g;
    ((struct Obj05548 *)c)->f2C = h;
    ((struct Obj05548 *)c)->f30 = i;
}
