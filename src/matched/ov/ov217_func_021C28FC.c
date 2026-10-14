/*
 * function: PERCENTAGE_Alloc
 * address:  0x021C28FC
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
 *   PERCENTAGE_Alloc  0x021C28FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
u32 PERCENTAGE_Alloc(u32 a0)
{
    return (u32)func_02030734(a0, 52, 0, (const char *)0x21C407C, 420);
}

