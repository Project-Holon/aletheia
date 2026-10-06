/*
 * function: func_021BFCE4
 * address: 0x021BFCE4
 * packet: pkt_ov210_021BFCE4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEE04 0x021BEE04 thumb
 *   func_021BEE58 0x021BEE58 thumb
 *   func_021BEE38 0x021BEE38 thumb
 *   func_021BEDF0 0x021BEDF0 thumb
 */
typedef unsigned int u32;
extern int func_021BEE04(int p, int i);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
extern void func_021BEDF0(int p, int i, int v);

void func_021BFCE4(char *p, int dx)
{
    u32 i;
    struct { short x; short y; } pos;

    for (i = 0xF; i < 0x1D; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 0);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 0);
            if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
                func_021BEDF0((int)p, i, 0);
            }
        }
    }
    func_021BEE58(p, 9, &pos.y, &pos.x, 0);
    func_021BEE38(p, 9, pos.y, (short)(pos.x + dx), 0);
    if (pos.x + dx <= -20 || pos.x + dx >= 0xDC) {
        func_021BEDF0((int)p, 9, 0);
    }
    for (i = 0x1D; i < 0x2B; i++) {
        if (func_021BEE04((int)p, i)) {
            func_021BEE58(p, i, &pos.y, &pos.x, 1);
            func_021BEE38(p, i, pos.y, (short)(pos.x + dx), 1);
            func_021BEE38(p, i + 0xE, pos.y, (short)(pos.x + dx), 1);
            if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
                func_021BEDF0((int)p, i, 0);
                func_021BEDF0((int)p, (int)i + 0xE, 0);
            }
        }
    }
    func_021BEE58(p, 0xB, &pos.y, &pos.x, 1);
    func_021BEE38(p, 0xB, pos.y, (short)(pos.x + dx), 1);
    func_021BEE38(p, 0xD, pos.y, (short)(pos.x + dx), 1);
    if (pos.x + dx <= -28 || pos.x + dx >= 0xD4) {
        func_021BEDF0((int)p, 0xB, 0);
        func_021BEDF0((int)p, 0xD, 0);
    }
}
