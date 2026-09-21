/*
 * function: func_020913FC
 * address:  0x020913FC
 * packet:   pkt_020913FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0024 PC24 func_020913E8           -> unresolved: 020913E8 (arm, from header) has no witness outside 020913FC..0209146C; +0030 PC24 func_020913BC           -> unresolved: 020913BC (arm, from header) has no witness outside 020913FC..0209146C; +0064 PC24 func_020913E8           -> unresolved: 020913E8 (arm, from header) has no witness outside 020913FC..0209146C
 *           callees func_020913E8 and func_020913BC have no witness
 *           outside 020913FC..0209146C (the only branches to them are
 *           the three sites inside this file), so those call sites stay
 *           wildcarded.  No C change is possible; the file becomes
 *           EXACT once either callee has its own shard entry.
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_020913D0  0x020913D0  arm
 *   func_020913E8  0x020913E8  arm
 *   func_020913BC  0x020913BC  arm
 *   func_02092344  0x02092344  arm
 */

typedef unsigned int u32;

extern void *func_020913D0(u32 heap);
extern void func_020913E8(void *p);
extern u32 func_020913BC(void);
extern void func_02092344(void *dst, const void *src, u32 n);

void *func_020913FC(u32 a0, u32 a1)
{
    void *p;
    u32 n;

    if (a0 == 0)
        return func_020913D0(a1);
    if (a1 == 0) {
        func_020913E8((void *)a0);
        return 0;
    }
    n = func_020913BC();
    p = func_020913D0(a1);
    if (p != 0) {
        if (n >= a1)
            n = a1;
        func_02092344(p, (const void *)a0, n);
        func_020913E8((void *)a0);
    }
    return p;
}
