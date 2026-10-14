/*
 * function: CircleGraph_Init
 * address:  0x021C1D64
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
 *   CircleGraph_CreateQueue  0x021C1DF0  thumb  ov217
 *   CircleGraph_BuildCirclePoints  0x021C1E0C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void CircleGraph_CreateQueue(char *p);
extern u32 CircleGraph_BuildCirclePoints();
u32 CircleGraph_Init(u32 a0)
{
    CircleGraph_CreateQueue((char *)a0);
    return CircleGraph_BuildCirclePoints(a0);
}

