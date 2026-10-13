/*
 * function: func_021BBD28
 * address:  0x021BBD28
 * packet:   pkt_021BBD28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BC740  0x021BC740  thumb  ov217
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021BC740(char *p, int i);
extern void BMP_OAM_SetPalette(u8 *g, u32 a);

void func_021BBD28(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)func_021BC740((char *)a, b), 1);
}
