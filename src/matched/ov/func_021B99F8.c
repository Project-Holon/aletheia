/*
 * function: func_021B99F8
 * address:  0x021B99F8
 * packet:   pkt_021B99F8
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02040EBC  0x02040EBC  arm
 */
typedef unsigned char u8;

extern u8 *func_020490F4(int a, int b);
extern void func_02049658(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_020498F4(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_02049238(u8 *p);
extern void func_02049B68(u8 *p, int a, int b, int c, int d, int e);
extern void func_02040EBC(int a, int b);

void func_021B99F8(void)
{
    u8 *p = func_020490F4(0x1a, 0x808e);
    func_02049658(p, 0, 3, 0, 0, 1, 0x8e);
    func_020498F4(p, 1, 3, 0, 0, 1, 0x8e);
    func_02049238(p);
    p = func_020490F4(0xdc, 0x808e);
    func_02049B68(p, 0xc, 0, 0x1e0, 0x20, 0x8e);
    func_02049B68(p, 0xc, 4, 0x1e0, 0x20, 0x8e);
    func_02049238(p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
}
