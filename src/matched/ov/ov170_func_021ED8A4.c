/*
 * function: func_021ED8A4
 * address: 0x021ED8A4
 * packet: pkt_ov170_021ED8A4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 */
extern void func_0202CF98(int, int, signed char *, signed char *);
extern void func_021EC08C(char *, int, short, short, short);
void func_021ED8A4(char *p)
{
    signed char t[2];
    unsigned i;
    short x, y;
    func_0202CF98(*(int *)(*(char **)(p + 0x2c) + 0x74), 7, &t[1], &t[0]);
    i = 0;
    y = t[0] * 8 + 8;
    x = t[1] * 8 + 0x17;
    for (; i < 6; i++)
        func_021EC08C(*(char **)(p + 0x2c), i + 0xd, x + (i % 2) * 0x20, y + (i / 2) * 0x18, 0);
}
