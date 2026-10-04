/*
 * function: func_021D6150
 * address: 0x021D6150
 * packet: pkt_ov115_021D6150
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6198 0x021D6198 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u16, u32, u32, u32);
extern void func_021D6134(void *, void (*)(void), int);
extern void func_021D6198(u8 *p);
void func_021D6150(u8 *p) {
    int color;
    if (*(u32 *)(*(u8 **)(p + 16) + 16) & 8) color = 0x7fff;
    else color = 0;
    func_0202208C(0, 1, 1, color, 6, 1, *(u16 *)(p + 20));
    func_021D6134(p, (void (*)(void))func_021D6198, 0x15b);
}
