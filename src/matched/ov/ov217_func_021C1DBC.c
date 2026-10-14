/*
 * function: CircleGraph_Alloc
 * address:  0x021C1DBC
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
 *   CircleGraph_InitFields  0x021C1D7C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 CircleGraph_InitFields();
u32 CircleGraph_Alloc(u32 a0)
{
    u32 v1 = (u32)func_02030734(a0, 4044, 0, (const char *)0x21C4064, 1588);
    CircleGraph_InitFields(v1, a0);
    return v1;
}

