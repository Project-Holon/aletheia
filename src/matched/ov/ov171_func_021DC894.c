/*
 * function: DENDOU_VIEW_ProcMain
 * address:  0x021DC894
 * packet:   pkt_021DC894
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DENDOU_VIEW_RunState  0x021DCE70  thumb  ov171
 */

typedef unsigned char  u8;
extern int DENDOU_VIEW_RunState(u8 *p);

int DENDOU_VIEW_ProcMain(int a, int b, int c, int d)
{
    if (DENDOU_VIEW_RunState((u8 *)d))
        return 0;
    return 1;
}
