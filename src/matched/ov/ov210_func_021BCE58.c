/*
 * function: func_021BCE58
 * address: 0x021BCE58
 * packet: pkt_ov210_021BCE58
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202CD94 0x0202CD94 thumb
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
typedef unsigned short u16;
typedef signed short s16;
struct Unk;
extern void func_02041EE4(unsigned int, unsigned int, int);
extern void func_0202CD94(struct Unk *);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *, int, int, int, unsigned short);
int func_021BCE58(char *p)
{
    unsigned int i;
    short x, y;
    int magnitude;
    if (*(u16 *)(p + 0x2c8) == 0) return 0;
    func_0202CD94(*(struct Unk **)(p + 0x20));
    func_02041EE4(4, 4, *(s16 *)(p + 0x2ca));
    func_02041EE4(7, 4, *(s16 *)(p + 0x2ca));
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += *(s16 *)(p + 0x2ca);
        func_021BEE38(p, i, x, y, 0);
    }
    magnitude = *(s16 *)(p + 0x2ca);
    if (magnitude < 0) magnitude = -magnitude;
    *(u16 *)(p + 0x2c8) -= (u16)magnitude;
    return 1;
}
