/*
 * function: func_0216E400
 * address:  0x0216E400
 * packet:   pkt_0216E400
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   d_021D5E04  0x021D5E04  data  a4
 *
 * blocker: sole-ref/data refused -- 0x021D5E04 has no referrer outside the
 *          compared range (the only pool word naming it is inside the function).
 */

typedef unsigned int u32;

extern u32 d_021D5E04[];

u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}
