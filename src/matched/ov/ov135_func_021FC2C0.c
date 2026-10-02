/*
 * function: func_021FC2C0
 * address: 0x021FC2C0
 * packet: pkt_ov135_021FC2C0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200B34 0x02200B34 thumb ov135
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u32);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern void func_0201F5BC(u32, u32, u32, u32, u32);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u32);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u32);
extern void func_02049238(void *);
extern void func_02200B34(void *);
void func_021FC2C0(void *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(2, 1, 0xe, 0, 0x48);
    func_0201F5BC(2, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0x10, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x16, 1, 0, 0x600, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    func_02200B34(p);
    func_02049238(h);
}
