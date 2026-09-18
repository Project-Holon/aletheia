/*
 * function: func_020944CC
 * address:  0x020944CC
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  callee 0x02093BDC has no witness outside 020944CC..02094530.
 *           That address is the home-area `push {r0,r1,r2,r3}` start of
 *           the function disasm.py labels at 0x02093BE0 (worklist pkt_020933B8,
 *           size 4); four bytes of caller-save home area cannot be produced
 *           from C, so no source file can ever earn the shard entry that
 *           would attest it.  The other site (func_02094488) resolved as
 *           `matched` once this packet's own shard was written.
 *
 * symbols:
 *   func_02094488  0x02094488  arm
 *   func_02093BDC  0x02093BDC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_02094488(u8 *p, const void *src, u32 n);
extern u32 func_02093BDC(u32 writer, void *s);

u32 func_020944CC(u8 *dst, u32 n, u32 arg2, u32 arg3)
{
    u32 state[4];
    u32 len;

    state[1] = (u32)dst;
    state[2] = n;
    state[3] = 0;
    state[0] = 0;
    len = func_02093BDC((u32)func_02094488, &state[1]);
    if (dst == 0)
        return len;
    if (len < n) {
        dst[len] = 0;
        return len;
    }
    if (n != 0)
        *(u8 *)((char *)dst + n - 1) = 0;
    return len;
}
