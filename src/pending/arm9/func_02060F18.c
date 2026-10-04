/*
 * function: func_02060F18
 * address:  0x02060F18
 * packet:   pkt_02060F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * Setter: replaces bit 0 of the halfword at +0x36 and returns the old bit 0.
 *
 * 2026-10-04 (wave D2 lane 04): ops and order match, 13 bytes differ. The
 * compiler sinks `old &= 1` below the final or (original: and r3,r3,#1 before
 * the orr, result moved to r0 last). Tried u16/u32 locals, bitfield (gives
 * lsl/lsr), compound |= (gives a pool mask), temp ordering.
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned int u32;

u32 func_02060F18(char *p, u32 v)
{
    u32 old = *(u16 *)(p + 0x36);
    v &= 1;
    *(u16 *)(p + 0x36) = old & ~1;
    u32 t = *(u16 *)(p + 0x36);
    old &= 1;
    t |= v;
    *(u16 *)(p + 0x36) = t;
    return old;
}
