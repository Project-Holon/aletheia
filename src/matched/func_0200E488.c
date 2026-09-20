/*
 * function: func_0200E488
 * address:  0x0200E488
 * packet:   pkt_0200E488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0216736C - overlay call; two overlays hold the address (ov009, ov010) and neither carries a func_ label there, and this call is the only branch to it.  All 18 bytes right; note the source shape that works: the a1-1 must be a named local computed before the call (see the file), writing `f(a0) + (a1 - 1)` gives `adds r0, r1, r0` instead of `adds r0, r0, r1`.
 * symbols:
 *   func_0216736C    0x0216736C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0216736C(u8 v);

u32 func_0200E488(u32 a0, u32 a1)
{
    u32 n = a1 - 1;
    u32 v = func_0216736C((u8)a0);

    return v + n;
}
