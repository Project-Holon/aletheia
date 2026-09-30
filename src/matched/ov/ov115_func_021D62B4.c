/*
 * function: func_021D62B4
 * address: 0x021D62B4
 * packet: pkt_ov115_021D62B4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D630C 0x021D630C thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u16, u32, u32, u32);
extern void func_02005E30(u32);
extern void func_021D6134(void *, void (*)(void), int);
extern void func_021D630C(void);
void func_021D62B4(u8 *p) {
    int color;
    u8 *q = *(u8 **)(p + 16);
    if (*(u32 *)(q + 16) & 16) color = 0x7fff;
    else color = 0;
    if (*(u32 *)(q + 12) == 0) func_02005E30(6);
    func_0202208C(0, 0, 0, color, 6, 1, *(u16 *)(p + 20));
    func_021D6134(p, func_021D630C, 0x213);
}
