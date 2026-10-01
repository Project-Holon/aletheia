/*
 * function: func_021F5374
 * address: 0x021F5374
 * packet: pkt_ov135_021F5374
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021F541E follow the body.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020490F4(u32, u32);
extern void func_02049B68(void *, u32, u32, u32, u32, u32);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern void func_0201F5BC(u32, u32, u32, u32, u32);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u32);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u32);
extern void func_02049238(void *);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
void func_021F5374(u8 *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 1, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xa, 1, 0, 0xa00, 1, 0x48);
    func_020498F4(h, 0x15, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
    func_02200AB4(p);
    func_02200B34(p);
}
