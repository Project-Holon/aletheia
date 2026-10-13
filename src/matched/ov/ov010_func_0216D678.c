/*
 * function: FLDMMDL_GetDrawStatus
 * address:  0x0216D678
 * packet:   pkt_ov010_0216D678
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ten ov021 callers: reads the halfword at +0x2A.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19127.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 FLDMMDL_GetDrawStatus(void *p)
{
    return ((struct Obj19127 *)p)->f2A;
}
