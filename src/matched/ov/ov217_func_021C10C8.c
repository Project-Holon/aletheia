/*
 * function: CircleGraph_Create
 * address:  0x021C10C8
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
 *   CircleGraph_Init  0x021C1D64  thumb  ov217
 *   CircleGraph_Alloc  0x021C1DBC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 CircleGraph_Init(u32);
extern u32 CircleGraph_Alloc(u32);
u32 CircleGraph_Create(u32 a0)
{
    u32 v1 = CircleGraph_Alloc(a0);
    CircleGraph_Init(v1);
    return v1;
}

