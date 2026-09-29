/*
 * function: func_021F1C30
 * address:  0x021F1C30
 * packet:   pkt_ov107_021F1C30
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_CommResponseRequest (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 */

extern char *g_021F6FA0;
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_021F2EE8(unsigned short child_aid);

int func_021F1C30(unsigned short child_aid, int ack)
{
    unsigned short req;
    int state;
    unsigned long enabled;

    enabled = func_02087988();

    switch (ack) {
    case 0:
        state = 10;
        req = 4;
        break;
    case 1:
        state = 10;
        req = 3;
        break;
    case 2:
        state = 14;
        req = 2;
        break;
    case 3:
        state = 7;
        req = 5;
        break;
    default:
        func_0208799C(enabled);
        return 0;
    }
    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        if (state == ((int *)(g_021F6FA0 + 0x14E8))[child_aid - 1]) {
            *(unsigned short *)(g_021F6FA0 + 0x1754 + (child_aid - 1) * 2) = req;
            func_0208799C(enabled);
            return 1;
        }
    }
    func_0208799C(enabled);
    return 0;
}
