/*
 * function: func_021BAC74
 * address:  0x021BAC74
 * packet:   pkt_ov088_021BAC74
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02045B38(u32, u32, u32, u32);
extern u32 func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern u32 func_0201EC64(u32 heap);
extern u32 func_0201C440(u32 heap);
extern u32 func_020457B0(u32 n, u32 heap);
extern u32 func_0203101C(u32, u32, int, int);
extern u32 func_02028590(u32, u32, u32, u32);

void func_021BAC74(char *p)
{
    *(u32 *)(p + 0x5c) = func_02045B38(0, 2, 0xb3, 0xb);
    *(u32 *)(p + 0x58) = func_0201D7EC(0x17, 0, 0, 0, 0xb);
    *(u32 *)(p + 0x60) = func_0201EC64(0xb);
    *(u32 *)(p + 0x68) = func_0201C440(0xb);
    *(u32 *)(p + 0x64) = func_020457B0(0x400, 0xb);
    *(u32 *)(p + 0x70) = func_0203101C(0xb, 0xb, 1, 4);
    *(u32 *)(p + 0x74) = func_02028590(0xf, 1, 0, 0xb);
}
