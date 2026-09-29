/*
 * function: func_021A03D0
 * address:  0x021A03D0
 * packet:   pkt_ov021_021A03D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A0734  0x021A0734  thumb  ov021
 *   func_021A07B4  0x021A07B4  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   d_021DDE38  0x021DDE38  data  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u8 *func_02030734(u32 a, u32 b, u32 c, void *d, u32 e);
extern void func_021A0734(void *p, u32 a);
extern u32 func_021A07B4(void *p, u32 b);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u8 d_021DDE38[];

u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    u8 *p;

    p = func_02030734(f, 0x490, 1, d_021DDE38, 0x167);
    *(u16 *)(p + 2) = c;
    func_021A0734(p, a);
    *(u16 *)(p + 0x38a) = 1;
    *(u32 *)(p + 0x350) = func_021A07B4(p, b);
    func_02082D44(p + 0x10 + *(u32 *)(p + 0x350) * 0x34, p + 0x356, 0x34);
    *(u32 *)(p + 0x38c) = 1;
    *(u32 *)(p + 8) = d;
    *(u32 *)(p + 4) = e;
    return p;
}
