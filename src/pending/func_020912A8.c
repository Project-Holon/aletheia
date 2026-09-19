/*
 * function: func_020912A8
 * address:  0x020912A8
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH (byte-correct, one relocation site unwitnessed)
 *
 * blocker:  label - the only branch in the whole image to func_0209D728 is the
 *           `bl` at +0x90 inside this very function.  `label` needs a site from
 *           outside 020912A8..02091374 and there is none, and func_0209D728 is
 *           itself parked at MATCH in src/pending/func_0209D728.c, so the
 *           `matched` class has no manifest entry to cite either.  Filing the
 *           callee is the fix, but it lives in pkt_0209D728, which is not one
 *           of this lane's packets (write-set rule 9).
 *
 * harness output:
 *   MATCH  compiled 204 = original 204, 7 of 8 sites resolved
 *     +0010 func_020860D0 [label x20]   +0070 func_02086028 [label x25]
 *     +0090 func_0209D728 [UNRESOLVED - no witness outside this range]
 *     +00B0 func_02086078 [label x25]
 *     +00BC g_02153BD4 [literal x15]    +00C0 g_02150FEC [literal x60]
 *     +00C4 g_02153B8C [literal x15]    +00C8 g_02153BB0 [literal x15]
 *   every concrete byte right, no wildcard byte is inside a branch opcode.
 *
 * symbols:
 *   func_02086028    0x02086028  arm
 *   func_020860D0    0x020860D0  arm
 *   func_02086078    0x02086078  arm
 *   func_0209D728    0x0209D728  arm
 *   g_02150FEC       0x02150FEC  data
 *   g_02153B8C       0x02153B8C  data
 *   g_02153BB0       0x02153BB0  data
 *   g_02153BD4       0x02153BD4  data
 */

typedef unsigned int u32;

extern void func_02086028(void *a0);
extern int func_020860D0(void *a0);
extern void func_02086078(void *a0);
extern u32 func_0209D728(u32 a0);

extern u32 g_02150FEC[];
extern u32 g_02153B8C;
extern u32 g_02153BB0;
extern u32 g_02153BD4;

u32 func_020912A8(u32 a0)
{
    u32 r;

    if (func_020860D0(&g_02153BD4) == 0) {
        g_02153B8C = *(u32 *)(g_02150FEC[1] + 0x6C);
        g_02153BB0 = 1;
    } else if (g_02153B8C == *(u32 *)(g_02150FEC[1] + 0x6C)) {
        g_02153BB0 = g_02153BB0 + 1;
    } else {
        func_02086028(&g_02153BD4);
        g_02153B8C = *(u32 *)(g_02150FEC[1] + 0x6C);
        g_02153BB0 = 1;
    }
    r = func_0209D728(a0);
    if (--g_02153BB0 == 0) {
        func_02086078(&g_02153BD4);
    }
    return r;
}
