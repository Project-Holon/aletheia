/*
 * function: func_0215910C
 * address:  0x0215910C
 * packet:   pkt_ov010_0215910C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_021D1A54/021D1A74/021D1AB0: reads the word at +0x140.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18757.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_0215910C(void *p)
{
    return ((struct Obj18757 *)p)->f140;
}
