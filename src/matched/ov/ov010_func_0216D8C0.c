/*
 * function: func_0216D8C0
 * address:  0x0216D8C0
 * packet:   pkt_ov010_0216D8C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: copies a 12-byte vector
 * into the object at +0x50.
 */

typedef unsigned char u8;

typedef struct { int x, y, z; } Vec;

void func_0216D8C0(u8 *p, const Vec *v)
{
    *(Vec *)(p + 0x50) = *v;
}
