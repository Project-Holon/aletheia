/*
 * function: func_0204E804
 * address:  0x0204E804
 * packet:   pkt_0204E804
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Direct non-SDK callee of the ov195 dependency tree rooted at
 * func_022040E0: an ARM9 boolean accessor, `g->f0 != 0`, reached by
 * `blx 0x0204E804` from the root's state 23 case.
 *
 * symbols:
 *   g_02146A7C  0x02146A7C  data
 */
typedef struct {
    int f0;
} G_02146A7C;

extern G_02146A7C *g_02146A7C;

int func_0204E804(void)
{
    return g_02146A7C->f0 != 0;
}
