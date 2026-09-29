/*
 * function: func_021F1BE0
 * address:  0x021F1BE0
 * packet:   pkt_ov107_021F1BE0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_CommIsBootable (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 */

extern char *g_021F6FA0;
extern int func_021F2EE8(unsigned short child_aid);

int func_021F1BE0(unsigned short child_aid)
{
    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        if (((int *)(g_021F6FA0 + 0x14E8))[child_aid - 1] == 7)
            return 1;
    }
    return 0;
}
