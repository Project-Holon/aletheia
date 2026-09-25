/*
 * function: func_0216E40C
 * address:  0x0216E40C
 * packet:   pkt_0216E40C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   d_021D770C  0x021D770C  data  a4
 *
 * blocker: sole-ref/data refused -- 0x021D770C has no referrer outside the
 *          compared range (the only pool word naming it is inside the function).
 */

typedef unsigned int u32;

extern u32 d_021D770C[];

u32 func_0216E40C(int i)
{
    return d_021D770C[i];
}
