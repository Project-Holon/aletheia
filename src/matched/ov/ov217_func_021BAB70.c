/*
 * function: func_021BAB70
 * address:  0x021BAB70
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021BAB70  0x021BAB70  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0203D34C(u32 a, u32 b);
void func_021BAB70(u32 a0)
{
    func_0203D34C(1, *(u16*)(((u8*)a0 + 0) + 4));
}

