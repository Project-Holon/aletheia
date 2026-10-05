/*
 * function: func_0216E2E0
 * address:  0x0216E2E0
 * packet:   pkt_ov010_0216E2E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, blocker of ov021 func_0219C680: count halfword of the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12404.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0216E2E0(void *p)
{
    return **(u16 * *)&((struct Obj12404 *)p)->f44;
}
