/*
 * function: SHINKA_DEMO_VIEW_IsGridState1
 * address:  0x022083DC
 * packet:   pkt_022083DC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24977.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int SHINKA_DEMO_VIEW_IsGridState1(char *p, u16 heap)
{
    return ((struct Obj24977 *)p)->f28 == 1;
}
