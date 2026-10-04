/*
 * function: func_0216E2AC
 * address:  0x0216E2AC
 * packet:   pkt_ov010_0216E2AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_0219C680: copies record i (28 bytes) from the table at +0x44.
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

typedef struct {
    u16 w[14];
} Rec;

void func_0216E2AC(void *p, u32 i, Rec *out)
{
    u16 *t = *(u16 * *)&((struct Obj12404 *)p)->f44;

    if (i < t[0]) {
        u16 k = (t[0] + 1) / 2 * 2;
        Rec *r = (Rec *)(t + (k + 2));

        *out = r[i];
    }
}
