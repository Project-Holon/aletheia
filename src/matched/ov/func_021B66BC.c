/*
 * function: func_021B66BC
 * address:  0x021B66BC
 * packet:   pkt_021B66BC
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02049658(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_020498F4(u8 *p, int a, int b, int c, int d, int e, int f);
extern void func_02049B68(u8 *p, int a, int b, int c, int d, int e);
extern u32 func_02049EF4(u8 *p, int a, int b, u32 c, int d);
extern void func_02049B40(int a, int b, int c, int d, int e, int f);
extern void func_0201F5BC(int a, int b, int c, int d, int e);

void func_021B66BC(u8 *p, u8 *q)
{
    u32 v = 1 << 0xb;
    u32 t;

    func_02049658(q, 1, 3, 0, 0, 0, 0x4f);
    func_020498F4(q, 4, 3, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 0, 0, 0, 0x4f);
    func_02049658(q, 1, 7, 0, 0, 0, 0x4f);
    func_020498F4(q, 2, 7, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 4, 0, 0, 0x4f);
    t = func_02049EF4(q, 3, 0, (u32)(p + 0x1c4), 0x4f);
    *(u32 *)(p + 0x1c0) = t;
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    func_0201F5BC(4, 1, 0xd, 0, 0x4f);
}
