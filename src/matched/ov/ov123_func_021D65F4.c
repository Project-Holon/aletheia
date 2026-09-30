/*
 * function: func_021D65F4
 * address: 0x021D65F4
 * packet: pkt_ov123_021D65F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_02005624 0x02005624 thumb
 *   func_021D6548 0x021D6548 thumb ov123
 *   func_02024230 0x02024230 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32, u32);
extern void func_02049990(void *, u32, u32, u32, u16, u32, u32, u16);
extern void func_02049238(void *);
extern void func_021D6548(void *, u8 *);
extern void *func_02005624(void (*)(void *, u8 *), u8 *, int);
extern void func_02024230(void *, int, int, int);
void func_021D65F4(u8 *p)
{
    void *h;
    h = func_020490F4(143, *(u16 *)(p + 0x43c4));
    func_02049990(h, 22, 3, 0, (u16)*(u32 *)(p + 4), 0, 0, *(u16 *)(p + 0x43c4));
    func_02049238(h);
    *(void **)(p + 0x14) = func_02005624(func_021D6548, p, 0);
    func_02024230(p + 0x43c8, 192, 0x5b0, 0x1800);
}
