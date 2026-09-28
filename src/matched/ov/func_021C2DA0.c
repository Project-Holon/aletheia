/*
 * function: func_021C2DA0
 * address:  0x021C2DA0
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
 *   func_021C2DA0  0x021C2DA0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02030734();
void func_021C2DA0(u32 a0)
{
    u8 s[4];
    u32 p1 = func_02030734(a0, 32, 0, 0x21C408C, 667);
    *(u16*)(((u8*)p1)) = a0;
}

