/*
 * function: func_021BFBF8
 * address:  0x021BFBF8
 * packet:   pkt_ov210_021BFBF8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BEE04 0x021BEE04 thumb ov210
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 * Addresses are Black-image addresses.
 */

extern int func_021BEE04(int p, int i);
extern void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in);
extern void func_021BEE38(int p, int i, short y, short x, int d);
extern void func_021BEDF0(int p, int i, int v);

void func_021BFBF8(int p, int v)
{
    unsigned i;
    short pos[2];

    for (i = 9; i <= 10; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 0);
            func_021BEE38(p, i, pos[1], pos[0] + v, 0);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc)
                func_021BEDF0(p, i, 0);
        }
    }
    for (i = 11; i <= 12; i++) {
        if (func_021BEE04(p, i) != 0) {
            int t;

            func_021BEE58((char *)p, i, &pos[1], &pos[0], 1);
            func_021BEE38(p, i, pos[1], pos[0] + v, 1);
            func_021BEE38(p, i + 2, pos[1], pos[0] + v, 1);
            t = pos[0] + v;
            if (t <= -12 || t >= 0xcc) {
                func_021BEDF0(p, i, 0);
                func_021BEDF0(p, i + 2, 0);
            }
        }
    }
}
