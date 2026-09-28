/*
 * function: func_021EC768
 * address:  0x021EC768
 * packet:   pkt_ov170_021EC768
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC030 0x021EC030 thumb
 *   func_021EC048 0x021EC048 thumb
 */

extern void func_021EC030(char *p, int i, int c);
extern void func_021EC048(char *p, int i, int c);

void func_021EC768(char *p, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        func_021EC030(p, c, 0);
        func_021EC048(p, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        func_021EC030(p, c, 3);
    else
        func_021EC030(p, c, 1);
    func_021EC048(p, c, 0x75 - i * 2);
}
