/*
 * function: func_022119E8
 * address:  0x022119E8
 * packet:   pkt_022119E8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *
 * blocker: +000C ABS32 CURSOR_MOVE_Delete          -> unresolved: 02025D14 (arm, from name) has no witness outside 022119E8..022119F8
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25290.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 CURSOR_MOVE_Delete(void *a0);

u32 func_022119E8(u8 *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj25290 *)p)->f2184));
}

