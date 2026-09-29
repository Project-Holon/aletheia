/*
 * function: func_021BBE48
 * address:  0x021BBE48
 * packet:   pkt_ov088_021BBE48
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BBA64  0x021BBA64  thumb  ov088
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02045B38(u32, u32, u32, u32);
extern int func_020450F0(int, int, int, int, int, int, int);
extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_02045770(u32 p);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, u32 text, u32 f, u16 color);
extern void func_02045808(u32 a);
extern void func_02045C04(u32 a);
extern void func_02045374(u32 win);
extern void func_02041B6C(u32);
extern void func_021BBA64(int, int, int, int, int);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BB9DC(char *, int);

void func_021BBE48(char *p)
{
    u32 msg = func_02045B38(0, 2, 0xe8, 0x800b);
    u32 s;
    u32 a;

    *(u32 *)(p + 0xf0) = func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    s = func_02045EC0(msg, 0x20);
    a = *(u32 *)(p + 0x68);
    func_0201C724(a, func_02045770(*(u32 *)(p + 0xf0)), 0, 0, s, *(u32 *)(p + 0x58), 0x440);
    *(u8 *)(p + 0xf4) = 1;
    func_02045808(s);
    func_02045C04(msg);

    func_02045374(*(u32 *)(p + 0xf0));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(p, 0);
}
