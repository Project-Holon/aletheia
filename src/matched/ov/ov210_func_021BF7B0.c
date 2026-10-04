/*
 * function: func_021BF7B0
 * address: 0x021BF7B0
 * packet: pkt_ov210_021BF7B0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *, int, unsigned short, short, unsigned short);
void func_021BF7B0(char *p, int idx, int y, int flag)
{
    int index;
    int coord;
    if (flag == 1) {
        index = idx + 9;
        func_021BEDF0((int)p, index, 1);
        coord = y + 12;
        func_021BEE38(p, index, 0x8c, coord, 0);
    } else {
        int other = idx + 11;
        func_021BEDF0((int)p, other, 1);
        coord = y + 12;
        func_021BEE38(p, other, 0x8c, coord, 1);
        index = idx + 13;
        func_021BEDF0((int)p, index, 1);
        func_021BEE38(p, index, 0x8c, coord, 1);
    }
}
