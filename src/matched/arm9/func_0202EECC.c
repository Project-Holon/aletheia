/*
 * function: func_0202EECC
 * address:  0x0202EECC
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC   0x020056EC  thumb
 *   func_0204384C   0x0204384C  arm
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   func_02045778   0x02045778  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02045374   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *
 * Fills in a freshly allocated record: the id, then a surface from the
 * caller's six size queries (width and height are each the sum of two of
 * them minus two, truncated to a byte).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EECC.c \
 *       --func func_0202EECC --addr 0x0202EECC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u32 func_020056EC(u32 range);
extern u32  func_0204384C(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02045730(u32 a);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045778(struct Descriptor *p);
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045374(u32 cfg);
extern void func_02041B6C(u32 a);

void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    *(u16 *)(p + 0x10) = a4;
    *(u8 *)(p + 0x13) = 0;
    *(u8 *)(p + 0x12) = a2;
    *(u8 *)(p + 0x14) = a3;
    *(u8 *)(p + 0x15) = func_020056EC(8);
    *(u32 *)(p + 0xC) = func_0204384C(0xC6, 0, 1, *(u16 *)(p + 0x10));

    v0 = func_02045730((u32)a1);
    v6 = func_02045758(a1);
    v7 = func_02045738(a1);
    v3 = func_02045760(a1);
    v2 = func_02045740(a1);
    v4 = func_02045778(a1);

    func_02045374(*(u32 *)(p + 8) = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1));
    func_02041B6C(func_02045730(*(u32 *)(p + 8)));
}
