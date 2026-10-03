/*
 * function: func_022016CC
 * address: 0x022016CC
 * packet: pkt_ov135_022016CC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8C68 0x021C8C68 arm ov114
 *   func_0220251C 0x0220251C thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C8C68(u32, const void *, u32, const void *, u32);
typedef unsigned short u16;
extern void func_0220251C(u8 *p, u16 a, u16 b);
int func_022016CC(u8 *p)
{
    func_021C8C68(*(u32 *)(p + *(u32 *)(p + 0xd4) * 0x128 + 0x314), p + 0xe4, (u32)(p + 0xa24), p + 0x10ec, 0x80);
    func_0220251C(p, 0x12, 0x14);
    *(u32 *)(p + 0x28) = 0x11;
    *(u32 *)(p + 0xf8c) = 0;
    return 2;
}
