/*
 * function: func_021C0E78
 * address:  0x021C0E78
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
 *   func_021C0E78  0x021C0E78  thumb  ov217
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
void func_021C0E78(u32 a0, u32 a1, u32 a2)
{
    *(u32*)(((u8*)a0)) = func_02030734(a2, ((u32)a1 << 2), 0, 0x21C4050, 211);
    *(u32*)(((u8*)a0) + 4) = a1;
}

