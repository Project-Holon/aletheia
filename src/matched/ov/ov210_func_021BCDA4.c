/*
 * function: func_021BCDA4
 * address: 0x021BCDA4
 * packet: pkt_ov210_021BCDA4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding at 0x021BCE0A.
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CD94 0x0202CD94 thumb
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
struct WinMgr;
struct Unk;
extern void func_02041EE4(unsigned int, unsigned int, int);
extern void func_0202CB4C(struct WinMgr *, unsigned int, int, int);
extern void func_0202CD94(struct Unk *);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *, int, int, int, unsigned short);
void func_021BCDA4(char *p)
{
    unsigned int i;
    short x, y;
    func_02041EE4(4, 3, 48);
    func_02041EE4(7, 3, 48);
    func_0202CB4C(*(struct WinMgr **)(p + 0x20), 0, 0, 27);
    func_0202CD94(*(struct Unk **)(p + 0x20));
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += 48;
        func_021BEE38(p, i, x, y, 0);
    }
}
