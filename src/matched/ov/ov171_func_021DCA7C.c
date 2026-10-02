/*
 * function: func_021DCA7C
 * address:  0x021DCA7C
 * packet:   pkt_021DCA7C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02041090  0x02041090  arm
 *   func_02049B40  0x02049B40  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;

extern u8 *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(u8 *p, int a, int b, int c, int d, int e);
extern void func_02049658(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_020498F4(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_02049238(u8 *p);
extern u32 func_0204162C(int a);
extern void func_02041090(int a, u32 b, int c, int d, int e, int f);
extern void func_02049B40(int a, int b, int c, int d, int e, int f);

void func_021DCA7C(void)
{
    u8 *p = func_020490F4(0xd5, 0x808c);

    func_02049B68(p, 1, 0, 0, 0x80, 0x8c);
    func_02049B68(p, 6, 4, 0, 0x40, 0x8c);
    func_02049658(p, 0, 0, 0, 0, 1, 0x8c);
    func_02049658(p, 5, 4, 0, 0, 1, 0x8c);
    func_020498F4(p, 2, 0, 0, 0, 1, 0x8c);
    func_020498F4(p, 3, 1, 0, 0, 1, 0x8c);
    func_020498F4(p, 4, 2, 0, 0, 1, 0x8c);
    func_020498F4(p, 7, 4, 0, 0, 1, 0x8c);
    func_02049238(p);
    func_02041090(3, func_0204162C(0) + 0x540, 0, 0x15, 0x20, 3);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x8c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x8c);
}
