/*
 * function: func_021BF618
 * address: 0x021BF618
 * packet: pkt_ov210_021BF618
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BED98 0x021BED98 thumb ov210
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 */
extern void func_021BED98(char *, int, int);
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, unsigned short a, unsigned short b, unsigned short c);
void func_021BF618(char *p)
{
    unsigned char v = (*(unsigned char **)(*(char **)p + 8))[6];
    if (v != 0xff) {
        func_021BED98(p, 7, v);
        func_021BEE38(p, 7, 0x40, 0x68, 0);
        func_021BEDF0((int)p, 7, 1);
    } else {
        func_021BEDF0((int)p, 7, 0);
    }
}
