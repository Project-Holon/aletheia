/*
 * function: func_021C1720
 * address:  0x021C1720
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
 *   func_021C1720  0x021C1720  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;


void func_021C1720(u8 *a0, u8 *a1)
{
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428)) + 28) = *(u8*)(((u8*)a1));
    *(u32*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428)) + 32) = (u32)(*(u32*)(((u8*)a1) + 4));
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 36)) = 0;
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 37)) = 0;
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 38)) = 0;
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 39)) = *(u8*)(((u8*)a1) + 8);
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 40)) = *(u8*)(((u8*)a1) + 9);
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 41)) = *(u8*)(((u8*)a1) + 10);
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 42)) = *(u8*)(((u8*)a1) + 11);
    *(u8*)(((u8*)a0 + 20 * *(u8*)(((u8*)a0) + 428) + 43)) = *(u8*)(((u8*)a1) + 12);
    *(u8*)(((u8*)a0 + *(u8*)(((u8*)a0) + 428) * 20 + 44)) = *(u8*)(((u8*)a1) + 13);
    *(u8*)(((u8*)a0) + 428) = *(u8*)(((u8*)a0) + 428) + 1;
}

