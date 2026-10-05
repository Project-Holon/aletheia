/*
 * function: func_0215A6D0
 * address:  0x0215A6D0
 * packet:   pkt_ov010_0215A6D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, blocker of ov021 func_021B6AE0: stores the word at +0x10C of the record held at +0x20.
 * (Also compiled inside the ov010_func_0215A684 unit, whose header names only its first function.)
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18797.h"
#include "../include/Obj18798.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_0215A6D0(void *p, u32 v)
{
    ((struct Obj18798 *)(*(char * *)&((struct Obj18797 *)p)->f20))->f10C = v;
}
