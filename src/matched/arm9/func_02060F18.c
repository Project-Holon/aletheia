/*
 * function: func_02060F18
 * address:  0x02060F18
 * packet:   pkt_02060F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter: replaces bit 0 of the halfword at +0x36 and returns the old bit 0.
 * 2026-10-05 (wave D7 lane 18): closed by reading the old bit first
 * (`old = *h & 1`, which places the and before the orr) and doing the two
 * stores through a named u16 pointer local (plain `*h = *h & ~1; *h = *h | (v & 1)`).
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned int u32;

u32 func_02060F18(char *p, u32 v)
{
    u32 old = *(u16 *)(p + 0x36) & 1;
    u16 *h = (u16 *)(p + 0x36);
    *h = *h & ~1;
    *h = *h | (v & 1);
    return old;
}
