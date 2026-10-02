/*
 * function: func_0220546C
 * address:  0x0220546C
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: a confirm gate.  True once the
 * action key is held (func_020362DC & 3) or the touch probe fires; it hands
 * the pressed/released flag to func_020355D8.  The two arms must be separate
 * call statements, not a selected value: only then does mwccarm tail-merge
 * them with the original's `beq`-to-true orientation.
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned int u32;
extern u32 func_020362DC(void);
extern unsigned int func_02035C60(void);
extern void func_020355D8(int);

int func_0220546C(void)
{
    if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
        if ((func_020362DC() & 3) != 0)
            func_020355D8(0);
        else
            func_020355D8(1);
        return 1;
    }
    return 0;
}
