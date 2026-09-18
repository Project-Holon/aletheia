/*
 * function: func_020072CC
 * address:  0x020072CC
 * packet:   pkt_02007248
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen: 7 bytes - same spill-order residue as func_0200725C
 *
 * symbols:
 *   g_0209D950     0x0209D950  data
 *   func_02031948  0x02031948  arm
 *   func_02008784  0x02008784  thumb
 *   func_020087D4  0x020087D4  thumb
 *   func_02031DC0  0x02031DC0  arm
 *
 * The five-argument sibling of func_0200725C: a fourth register parameter
 * plus a literal 1 in the callee's stack slot, which is why the frame opens
 * with `sub sp, #8` and the `movs r0, #1` is stored before the address
 * arithmetic.  Everything else is the same shape, the re-load of the slot
 * for the final call included.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020072CC.c \
 *       --func func_020072CC --addr 0x020072CC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char  g_0209D950[];
extern u32   func_02031948(char *p, u32 a, u32 b, u32 c, u32 d);
extern u32   func_02008784(char *p, u32 idx);
extern u32  *func_020087D4(char *p, u32 idx);
extern u32   func_02031DC0(u32 handle, u32 a, u32 b);

u32 func_020072CC(char *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 *slot = (u32 *)(a0 + 0x14);
    char *tbl;
    u32 *q;

    tbl = g_0209D950 + 0x18 * a1;
    slot[a1] = func_02031948(tbl, a2, a3, a4, 1);
    if (func_02008784(a0, a1) == 0) {
        return 0;
    }
    q = func_020087D4(a0, a1);
    return func_02031DC0(slot[a1], a2, q[0]);
}
