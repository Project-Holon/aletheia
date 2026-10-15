/*
 * function: SHINKA_DEMO_VIEW_IsGridState0
 * address:  0x022083CC
 * packet:   pkt_022083CC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24976.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int SHINKA_DEMO_VIEW_IsGridState0(char *p, u16 a1)
{
    return ((struct Obj24976 *)p)->f28 == 0;
}
