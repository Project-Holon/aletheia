/*
 * function: func_021C1704
 * address:  0x021C1704
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
 *   func_021C0E5C  0x021C0E5C  thumb  ov217
 *   func_021C16FC  0x021C16FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C0E5C();
extern u32 func_021C16FC();
u32 func_021C1704(u32 a0)
{
    *(u8*)(((u8*)a0) + 428) = 0;
    func_021C0E5C(*(u32*)(((u8*)a0) + 12));
    return func_021C16FC(a0, 0);
}

