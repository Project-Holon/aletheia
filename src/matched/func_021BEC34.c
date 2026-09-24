/*
 * function: func_021BEC34
 * address:  0x021BEC34
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BEC34  0x021BEC34  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0209C0A4();
void func_021BEC34(u32 a0)
{
    u32 v4 = func_0209C0A4(*(u8*)(((u8*)a0) + 9) + 62, 3);
    u32 v6 = func_0209C0A4(*(u8*)(((u8*)a0) + 10) + 62, 3);
    *(u8*)(((u8*)a0) + 11) = func_0209C0A4(*(u8*)(((u8*)a0) + 8) + 62, 3);
    *(u8*)(((u8*)a0) + 12) = v4;
    *(u8*)(((u8*)a0) + 13) = v6;
}

