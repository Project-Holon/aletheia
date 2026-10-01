/*
 * function: func_0218ED64
 * address:  0x0218ED64
 * packet:   pkt_ov021_0218ED64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern s16 FX_SinCosTable_[];
extern void func_02048B80(u32 a, int v);
extern void func_02048B94(u32 a, int v);

void func_0218ED64(u8 *a, u16 angle)
{
    *(u16 *)(a + 0x80) = angle;
    func_02048B80(*(u32 *)(a + 0xc), FX_SinCosTable_[(*(u16 *)(a + 0x80) >> 4) * 2]);
    func_02048B94(*(u32 *)(a + 0xc), FX_SinCosTable_[(*(u16 *)(a + 0x80) >> 4) * 2 + 1]);
}
