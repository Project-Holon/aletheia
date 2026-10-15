/*
 * function: BR_CODEIN_ProfileClear
 * address:  0x021E1C00
 * packet:   pkt_021E1C00
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00478.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void BR_CODEIN_ProfileClear(char *p)
{
    ((struct Obj00478 *)p)->f318 = 0;
    ((struct Obj00478 *)p)->f31C = 0;
    ((struct Obj00478 *)p)->f320 = 0;
}
