/*
 * function: func_021F76D8
 * address: 0x021F76D8
 * packet: pkt_ov135_021F76D8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 *   func_02049658 0x02049658 arm
 *   func_02049238 0x02049238 arm
 *   func_02200B34 0x02200B34 thumb ov135
 */
typedef unsigned u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern void func_02200B34(u8 *p);
void func_021F76D8(void *p)
{
    void *h = func_020490F4(0x60, 0x48);
    func_02049B40(0x60, 0, 0, 0, 0x40, 0x48);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x48);
    func_0201F5BC(0, 1, 14, 0, 0x48);
    func_0201F5BC(0, 31, 11, 0, 0x48);
    func_02049624((void *)0x60, (void *)9, (void *)1, 0, 0, 1, 0x48);
    func_0204989C(0x60, 20, 1, 0, 0x600, 1, 0x48);
    func_02049658(h, 12, 2, 0, 0, 1, 0x48);
    func_02200B34(p);
    func_02049238(h);
}
