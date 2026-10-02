/*
 * function: func_020944CC
 * address:  0x020944CC
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
extern u32 func_02093BDC(u32 writer, void *s, const u8 *format, u8 *ap, int is_secure);

u32 func_020944CC(u8 *dst, u32 n, const u8 *format, u8 *ap)
{
    u32 state[3];
    u32 len;

    state[0] = (u32)dst;
    state[1] = n;
    state[2] = 0;
    len = func_02093BDC((u32)func_02094488, state, format, ap, 0);
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
