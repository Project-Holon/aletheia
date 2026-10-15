/*
 * function: SHINKA_DEMO_VIEW_IsGridState4
 * address:  0x02208420
 * packet:   pkt_02208420
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24979.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int SHINKA_DEMO_VIEW_IsGridState4(char *p, u16 heap)
{
    return ((struct Obj24979 *)p)->f28 == 4;
}
