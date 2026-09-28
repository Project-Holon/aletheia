/*
 * function: func_021B6360
 * address:  0x021B6360
 * packet:   pkt_021B6360
 * region:   ov180
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
 */
typedef unsigned char u8;

extern u8 *func_020490F4(int a, int b);
extern void func_02049B68(u8 *p, int a, int b, int c, int d, int e);
extern void func_02049658(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_020498F4(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_02049238(u8 *p);

void func_021B6360(void)
{
    u8 *p = func_020490F4(0xd8, 0x8d);
    func_02049B68(p, 1, 2, 0x6000, 0x20, 0x8d);
    func_02049B68(p, 1, 6, 0x6000, 0x20, 0x8d);
    func_02049658(p, 0x16, 3, 0, 0, 0, 0x8d);
    func_02049658(p, 0x16, 7, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 3, 0, 0, 0, 0x8d);
    func_020498F4(p, 0x1c, 7, 0, 0, 0, 0x8d);
    func_02049238(p);
}
