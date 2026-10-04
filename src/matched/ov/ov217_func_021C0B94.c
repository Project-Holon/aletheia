/*
 * function: func_021C0B94
 * address:  0x021C0B94
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
 *   func_021C0B94  0x021C0B94  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
void func_021C0B94(u32 a0)
{
    *(u32*)(((u8*)a0 + 0) + 32) = (u32)func_0204B100(1, 2, *(u16*)(((u8*)a0 + 0)));
}

