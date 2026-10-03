/*
 * function: func_0202EF98
 * address:  0x0202EF98
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0202F099      0x0202F099  data
 *   func_020056EC   0x020056EC  thumb
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   func_02045778   0x02045778  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02045374   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   func_02030DA8   0x02030DA8  arm
 *
 * func_0202EECC's twin with the record unzeroed: the surface is built the
 * same way, then the caller's handle is attached through func_02030DA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EF98.c \
 *       --func func_0202EF98 --addr 0x0202EF98 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 g_0202F099[];

extern u32 func_020056EC(u32 range);
extern u32  func_02045730(u32 a);
extern u32  func_02045758(u32 a);
extern u32  func_02045738(u32 a);
extern u32  func_02045760(u32 a);
extern u32  func_02045740(u32 a);
extern u32  func_02045778(u32 a);
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045374(u32 cfg);
extern void func_02041B6C(u32 a);
extern u32  func_02030DA8(u32 a, u32 b, u32 c, u32 d);

void func_0202EF98(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    *(u8 *)(p + 0x13) = 0;
    *(u8 *)(p + 0x12) = a3;
    *(u8 *)(p + 0x14) = a4;
    *(u8 *)(p + 0x15) = func_020056EC(8);

    v0 = func_02045730(a2);
    v6 = func_02045758(a2);
    v7 = func_02045738(a2);
    v3 = func_02045760(a2);
    v2 = func_02045740(a2);
    v4 = func_02045778(a2);

    func_02045374(*(u32 *)(p + 8) = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1));
    func_02041B6C(func_02045730(*(u32 *)(p + 8)));

    *(u32 *)(p + 4) = 0;
    *(u32 *)p = func_02030DA8(a1, (u32)g_0202F099, (u32)p, 0);
    *(u32 *)(p + 0x18) = 1;
}
