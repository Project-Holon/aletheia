/*
 * function: func_0200725C
 * address:  0x0200725C
 * packet:   pkt_02007248
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen: 10 bytes - the spill of the third argument lands two instructions later than the original's; the callee's argument address is computed into a register in the original after the spill.  See docs/notes/pkt_02007248.c.txt
 *
 * symbols:
 *   g_0209D950     0x0209D950  data
 *   func_0203192C  0x0203192C  arm
 *   func_02008784  0x02008784  thumb
 *   func_020087D4  0x020087D4  thumb
 *   func_02031DC0  0x02031DC0  arm
 *
 * Open slot `a1` of a 0x14-stride table hanging off the object: create the
 * resource at 0x18*a1 into g_0209D950 and store its handle at
 * `obj[0x14 + 4*a1]`, then register it.  The `if (...) return 0;` arm runs
 * *after* the table entry is written, so the guard cannot be moved up; the
 * slot is re-loaded for the final call rather than kept in a register
 * because func_020087D4 is extern and may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200725C.c \
 *       --func func_0200725C --addr 0x0200725C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char  g_0209D950[];
extern u32   func_0203192C(char *p, u32 a);
extern u32   func_02008784(char *p, u32 idx);
extern u32  *func_020087D4(char *p, u32 idx);
extern u32   func_02031DC0(u32 handle, u32 a, u32 b);

u32 func_0200725C(char *a0, u32 a1, u32 a2)
{
    u32 *slot = (u32 *)(a0 + 0x14);
    char *tbl;
    u32 *q;

    tbl = g_0209D950 + 0x18 * a1;
    slot[a1] = func_0203192C(tbl, a2);
    if (func_02008784(a0, a1) == 0) {
        return 0;
    }
    q = func_020087D4(a0, a1);
    return func_02031DC0(slot[a1], a2, q[0]);
}
