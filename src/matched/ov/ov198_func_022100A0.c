/*
 * function: B_PLIST_MAIN_EnterState1A
 * address:  0x022100A0
 * packet:   pkt_022100A0
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_DRAW_PrintWordAndRefresh  0x0220D6AC  thumb  ov198
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14566.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void B_PLIST_DRAW_PrintWordAndRefresh(u8 *);

u32 B_PLIST_MAIN_EnterState1A(u8 *p)
{
    B_PLIST_DRAW_PrintWordAndRefresh(p);
    ((struct Obj14566 *)p)->f2193 = 1;
    ((struct Obj14566 *)p)->f217C = 0x1a;
    return 0x17;
}

