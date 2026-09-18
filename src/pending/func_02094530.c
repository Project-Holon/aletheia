/*
 * function: func_02094530
 * address:  0x02094530
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * note:     this is the REAL start of the function the worklist and the
 *           listing label at 0x02094534: the first instruction is the
 *           argument home area `push {r0,r1,r2,r3}`, which saves no lr, so
 *           disasm.py put its label four bytes late.  Wants a seed at
 *           0x02094530 in layout/function_starts.txt and the label at
 *           0x02094534 removed.
 *
 * blocker:  callee func_020944CC has no shard entry of its own (it is parked
 *           in this packet because its own `bl 0x02093BDC` site cannot be
 *           attested), so the single call site here stays wildcarded.  The C
 *           itself is byte-correct: 36 bytes, home push included.
 *
 * symbols:
 *   func_020944CC  0x020944CC  arm
 */

typedef unsigned int u32;

extern u32 func_020944CC(char *dst, u32 n, u32 v, u32 *ap);

u32 func_02094530(char *dst, u32 n, ...)
{
    u32 *p = (u32 *)((u32)&n & ~3u);

    return func_020944CC(dst, 0xFFFFFFFFu, n, p + 1);
}
