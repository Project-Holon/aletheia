/*
 * function: func_021C3510
 * address:  0x021C3510
 * packet:   pkt_ov021_021C3510
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Saturating 32-bit add (EXACT*: pad).
 */

typedef unsigned int u32;
typedef unsigned long long u64;

u32 func_021C3510(u32 a, u32 b)
{
    u64 s = (u64)a + b;

    if (s > 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return s;
}
