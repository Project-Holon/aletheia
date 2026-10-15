/*
 * function: B_BAG_MAIN_StartFingerCursor
 * address:  0x0220C6F8
 * packet:   pkt_0220C6F8
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25046.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BTLV_FINGER_CURSOR_Start(u32, u32, u32, u32, u32, u32);

void B_BAG_MAIN_StartFingerCursor(u8 *p, u32 a, u32 b)
{
    BTLV_FINGER_CURSOR_Start(((struct Obj25046 *)p)->f14C, a, b, 2, 6, 0x14);
}

