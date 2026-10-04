/*
 * function: func_021BFA14
 * address: 0x021BFA14
 * packet: pkt_ov210_021BFA14
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *, int, unsigned short, short, unsigned short);
void func_021BFA14(char *p, int y, int flag)
{
    int coord;
    if (flag == 1) {
        func_021BEDF0((int)p, 9, 1);
        coord = y + 20;
        func_021BEE38(p, 9, 0x8c, coord, 0);
    } else {
        func_021BEDF0((int)p, 11, 1);
        coord = y + 20;
        func_021BEE38(p, 11, 0x8c, coord, 1);
        func_021BEDF0((int)p, 13, 1);
        func_021BEE38(p, 13, 0x8c, coord, 1);
    }
}
