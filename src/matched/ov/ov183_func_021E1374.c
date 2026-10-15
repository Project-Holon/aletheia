/*
 * function: BR_CODEIN_ProfileSetAnimSeq
 * address:  0x021E1374
 * packet:   pkt_021E1374
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00143.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void BR_CODEIN_ProfileSetAnimSeq(char *p, int v)
{
    ((struct Obj00143 *)p)->f22C = v;
    ((struct Obj00143 *)p)->f230 = 0;
    ((struct Obj00143 *)p)->f234 = 0;
    ((struct Obj00143 *)p)->f238 = 0;
}
