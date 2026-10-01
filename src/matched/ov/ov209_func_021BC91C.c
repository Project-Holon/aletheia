/*
 * function: func_021BC91C
 * address: 0x021BC91C
 * packet: pkt_ov209_021BC91C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 */
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02041EE4(u32, u32, u32);
extern void func_021BD958(char *, int, s16 *, s16 *, u16);
extern void func_021BD934(char *, int, int, int, u16);
int func_021BC91C(char *p)
{
    unsigned i;
    s16 pair[2];
    int d;
    if (*(u16 *)(p + 0xC40) == 0) return 0;
    func_02041EE4(5, 4, *(s16 *)(p + 0xC42));
    func_02041EE4(1, 5, *(s16 *)(p + 0xC42));
    for (i = 3; i <= 9; i++) {
        func_021BD958(p, i, &pair[1], &pair[0], 0);
        pair[0] += *(s16 *)(p + 0xC42);
        func_021BD934(p, i, pair[1], pair[0], 0);
    }
    d = *(s16 *)(p + 0xC42);
    if (d < 0) d = -d;
    *(u16 *)(p + 0xC40) -= d;
    return 1;
}
