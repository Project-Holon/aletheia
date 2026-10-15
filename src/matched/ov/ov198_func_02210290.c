/*
 * function: B_PLIST_MAIN_RefreshAndState16
 * address:  0x02210290
 * packet:   pkt_02210290
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   B_PLIST_DRAW_ClearAndPrintStream  0x0220E13C  thumb  ov198
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25234.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void B_PLIST_DRAW_ClearAndPrintStream(u8 *);

u32 B_PLIST_MAIN_RefreshAndState16(u8 *p)
{
    B_PLIST_DRAW_ClearAndPrintStream(p);
    ((struct Obj25234 *)p)->f217C = 0x16;
    return 0x17;
}

