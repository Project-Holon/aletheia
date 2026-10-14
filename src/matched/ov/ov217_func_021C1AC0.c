/*
 * function: CircleGraph_GetSliceByKey
 * address:  0x021C1AC0
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
 *   CircleGraph_FindSliceIndexImpl  0x021C1A84  thumb  ov217
 *   CircleGraph_GetSlice  0x021C1AB4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 CircleGraph_FindSliceIndexImpl(u8 *p, u8 key);
extern void *CircleGraph_GetSlice(void *p, u32 n);

void *CircleGraph_GetSliceByKey(u8 *p, u8 key)
{
    return CircleGraph_GetSlice(p, CircleGraph_FindSliceIndexImpl(p, key));
}


