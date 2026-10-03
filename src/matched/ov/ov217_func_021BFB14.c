/*
 * function: func_021BFB14
 * address:  0x021BFB14
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
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int func_021C0E08(int a0, int a1);
void func_021BFB14(u32 a0)
{
    *(u32*)(((u8*)a0 + 0) + 28) = func_021C0E08(10, *(u16*)(((u8*)a0 + 0) + 4));
}

