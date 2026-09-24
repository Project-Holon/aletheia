/*
 * function: func_021BC8B4
 * address:  0x021BC8B4
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
 *   func_021BC8B4  0x021BC8B4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0201D7EC();
void func_021BC8B4(u32 a0)
{
    u8 s[4];
    *(u32*)(((u8*)a0) + 12) = func_0201D7EC(23, 0, 0, 0, (u32)(*(u16*)(((u8*)a0) + 8)));
}

