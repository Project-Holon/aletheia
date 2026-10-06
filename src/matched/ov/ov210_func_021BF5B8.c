/*
 * function: func_021BF5B8
 * address: 0x021BF5B8
 * packet: pkt_ov210_021BF5B8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_021BF618 0x021BF618 thumb ov210
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, unsigned short a, int b, unsigned short c);
extern void func_021BF618(char *);
void func_021BF5B8(char *p)
{
    func_021BEDF0((int)p, 3, 0);
    func_021BEDF0((int)p, 4, 0);
    func_021BEDF0((int)p, 2, 1);
    func_021BEDF0((int)p, 5, 1);
    func_021BEDF0((int)p, 6, 1);
    func_021BEDF0((int)p, 0, 1);
    func_021BEDF0((int)p, 1, 1);
    func_021BEE38(p, 0, 0xfc, 12, 0);
    func_021BF618(p);
}
