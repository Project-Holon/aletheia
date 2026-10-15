/*
 * function: MBi_CommChangeParentState
 * address:  0x021F1D0C
 * packet:   pkt_ov107_021F1D0C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommChangeParentState (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 *   func_021F1D58  0x021F1D58  thumb  ov107
 */

extern char *g_021F6FA0;
extern int func_021F2EE8(unsigned short child_aid);
extern void func_021F1D58(unsigned short child, int state, void *arg);

void MBi_CommChangeParentState(unsigned short child, int state, void *arg)
{
    if (func_021F2EE8(child))
        ((int *)(g_021F6FA0 + 0x14E8))[child - 1] = state;
    func_021F1D58(child, state, arg);
}
