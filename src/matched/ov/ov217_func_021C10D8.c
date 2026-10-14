/*
 * function: CircleGraph_Destroy
 * address:  0x021C10D8
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
 *   CircleGraph_DestroyQueueImpl  0x021C1D74  thumb  ov217
 *   CircleGraph_Free  0x021C1DE8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void CircleGraph_DestroyQueueImpl(u32);
extern u32 CircleGraph_Free(void *a0);
u32 CircleGraph_Destroy(void *a0)
{
    CircleGraph_DestroyQueueImpl((u32)a0);
    return CircleGraph_Free(a0);
}

