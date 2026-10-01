/*
 * function: func_021BC8B4
 * address: 0x021BC8B4
 * packet: pkt_ov209_021BC8B4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding
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
void func_021BC8B4(char *p)
{
    unsigned i;
    s16 pair[2];
    func_02041EE4(5, 3, 48);
    func_02041EE4(1, 3, -48);
    for (i = 3; i <= 9; i++) {
        func_021BD958(p, i, &pair[1], &pair[0], 0);
        pair[0] += 48;
        func_021BD934(p, i, pair[1], pair[0], 0);
    }
}
