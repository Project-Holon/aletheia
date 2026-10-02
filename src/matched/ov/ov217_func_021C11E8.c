/*
 * function: func_021C11E8
 * address:  0x021C11E8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021C1AB4(void *, u32);
u32 func_021C11E8(void *p, u32 n)
{
    return *(u8*)(((u8*)func_021C1AB4(p, n)) + 8);
}

