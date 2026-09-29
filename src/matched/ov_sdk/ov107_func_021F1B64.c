/*
 * function: func_021F1B64
 * address:  0x021F1B64
 * packet:   pkt_ov107_021F1B64
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_CommGetChildUser (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 */

extern char *g_021F6FA0;
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern int func_021F2EE8(unsigned short child_aid);

void *func_021F1B64(unsigned short child_aid)
{
    unsigned long enabled = func_02087988();

    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        func_02082D44(g_021F6FA0 + 0x1340 + (child_aid - 1) * 22, g_021F6FA0 + 0x1772, 0x16);
        func_0208799C(enabled);
        return g_021F6FA0 + 0x1772;
    }
    func_0208799C(enabled);
    return 0;
}
