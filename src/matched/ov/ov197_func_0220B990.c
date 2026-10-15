/*
 * function: func_0220B990
 * address:  0x0220B990
 * packet:   pkt_0220B990
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_APP_TOOL_ShowWindows  0x0220B094  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25010.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 B_APP_TOOL_ShowWindows(u8 *, u32);

u32 func_0220B990(u8 *p)
{
    return B_APP_TOOL_ShowWindows(p + 0x28, ((struct Obj25010 *)p)->f59C);
}

