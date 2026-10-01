/*
 * function: func_021F8668
 * address: 0x021F8668
 * packet: pkt_ov135_021F8668
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8554 0x021F8554 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021F8554(u8 *dst, void *p);
void func_021F8668(u8 *dst, u8 *p)
{
    func_021F8554(dst, p);
    *(u16 *)(dst + 0xEC) = *(u16 *)(p + 0xB4C);
    *(u16 *)(dst + 0xEE) = *(u16 *)(p + 0xB4E);
    *(u16 *)(dst + 0xF0) = *(u16 *)(p + 0xB50);
    *(u16 *)(dst + 0xF2) = *(u16 *)(p + 0xB52);
    *(u16 *)(dst + 0xF4) = *(u16 *)(p + 0xB54);
}
