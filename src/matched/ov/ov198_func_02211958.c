/*
 * function: B_PLIST_MAIN_CheckCancel
 * address:  0x02211958
 * packet:   pkt_02211958
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   B_PLIST_MAIN_ClearSelection  0x02211944  thumb  ov198
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25284.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void B_PLIST_MAIN_ClearSelection(u8 **);

u32 B_PLIST_MAIN_CheckCancel(u8 **p)
{
    if (((struct Obj25284 *)(*p))->f30 == 1) {
        B_PLIST_MAIN_ClearSelection(p);
        return 1;
    }
    return 0;
}

