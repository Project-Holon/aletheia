/*
 * function: CircleGraph_FindSliceIndex
 * address:  0x021C11C8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to CircleGraph_FindSliceIndexImpl.
 *
 * symbols:
 *   CircleGraph_FindSliceIndexImpl  0x021C1A84  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 CircleGraph_FindSliceIndexImpl(u8 *p, u8 key);

u8 CircleGraph_FindSliceIndex(u8 *p, u8 key)
{
    return CircleGraph_FindSliceIndexImpl(p, key);
}
