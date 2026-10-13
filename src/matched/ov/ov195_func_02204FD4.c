/*
 * function: func_02204FD4
 * address:  0x02204FD4
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to func_02204F24 and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 *
 * symbols:
 *   func_02204F24  0x02204F24  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
extern void func_02204F24(int, int *);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

void func_02204FD4(int a, int *p)
{
    if (p[0xc] == 4) {
        func_02204F24(a, p);
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        p[0xc] = 9;
    }
}
