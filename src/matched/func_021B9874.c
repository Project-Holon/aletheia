/*
 * function: func_021B9874
 * address:  0x021B9874
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
 *   func_021C097C  0x021C097C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C097C();
void func_021B9874(u32 a0)
{
    *(u32*)(((u8*)a0 + 0) + 12) = func_021C097C(*(u16*)(((u8*)a0 + 0)), *(u32*)(((u8*)a0 + 0) + 4));
}

