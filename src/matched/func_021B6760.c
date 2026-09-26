/*
 * function: func_021B6760
 * address:  0x021B6760
 * packet:   pkt_021B6760
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   func_0201DD78  0x0201DD78  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201D7EC(int a, int b, int c, int d, u32 e);
extern u32 func_02045B38(int a, int b, int c, u32 d);
extern void func_0201F5BC(int a, int b, int c, int d, u32 e);
extern u32 func_0201F548(int a);
extern void func_02049B90(int a, u32 b, int c, int d, int e, int f, u32 g);
extern void func_02049B40(int a, int b, int c, int d, int e, u32 f);
extern void func_0201DD68(void);
extern u32 func_0203101C(u32 a, u32 b, int c, int d);
extern u32 func_0201C440(u32 a);
extern u32 func_02028590(int a, int b, int c, u32 d);
extern void func_0201DD78(int a, int b, int c);

void func_021B6760(u8 *p)
{
    *(u32 *)(p + 0x60) = func_0201D7EC(0x17, 0, 0, 0, *(u16 *)p);
    *(u32 *)(p + 0x68) = func_02045B38(0, 2, 0xc6, *(u16 *)p);
    *(u32 *)(p + 0x6c) = func_02045B38(0, 2, (u16)(*(u16 *)(*(u32 *)(p + 0x30)) + 0xbf), *(u16 *)p);
    func_0201F5BC(0, 1, 0xd, 0, *(u16 *)p);
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1a0, 0x20, *(u16 *)p);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, *(u16 *)p);
    func_0201DD68();
    *(u32 *)(p + 0x58) = func_0203101C(*(u16 *)p, *(u16 *)p, 3, 0x100);
    *(u32 *)(p + 0x64) = 0;
    *(u32 *)(p + 0x5c) = 0;
    *(u32 *)(p + 0x70) = 0;
    *(u32 *)(p + 0x74) = 0;
    *(u32 *)(p + 0x78) = func_0201C440(*(u16 *)p);
    *(u32 *)(p + 0x7c) = func_02028590(0xf, 1, 1, *(u16 *)p);
    func_0201DD78(1, 2, 0xf);
}
