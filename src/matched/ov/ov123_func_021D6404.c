/*
 * function: func_021D6404
 * address: 0x021D6404
 * packet: pkt_ov123_021D6404
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_0204AF28 0x0204AF28 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_0201BC3C(void);
extern void *func_0204ACEC(void *, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void *func_0204AF28(void *, u32, u32, u16);
void func_021D6404(u8 *p)
{
    void *h;
    h = func_020490F4(7, *(u16 *)(p + 0x43c4));
    *(void **)(p + 0x28) = func_0204ACEC(h, func_0201BC3C(), 2, 0, *(u16 *)(p + 0x43c4));
    func_02049238(h);
    h = func_020490F4(143, *(u16 *)(p + 0x43c4));
    *(void **)(p + 0x5c) = func_0204AF28(h, 14, 27, *(u16 *)(p + 0x43c4));
    func_02049238(h);
}
