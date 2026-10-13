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
 * action key is held (KEY_GetTrg & 3) or the touch probe fires; it hands
 * the pressed/released flag to func_020355D8.  The two arms must be separate
 * call statements, not a selected value: only then does mwccarm tail-merge
 * them with the original's `beq`-to-true orientation.
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);

int func_0220546C(void)
{
    if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
        if ((KEY_GetTrg() & 3) != 0)
            func_020355D8(0);
        else
            func_020355D8(1);
        return 1;
    }
    return 0;
}
