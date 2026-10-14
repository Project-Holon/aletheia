/*
 * function: CircleGraph_GetLabelPositionByKey
 * address:  0x021C11FC
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
 *   CircleGraph_GetSliceByKey  0x021C1AC0  thumb  ov217
 *   CircleGraph_GetSliceMiddle  0x021C1B74  thumb  ov217
 *   CircleGraph_ProjectToScreen  0x021C1F44  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *CircleGraph_GetSliceByKey(u8 *p, u8 key);
extern void CircleGraph_GetSliceMiddle(u8 *p, u8 *rec, s16 *out);
extern void CircleGraph_ProjectToScreen(const s16 *p, s32 *px, s32 *py);

void CircleGraph_GetLabelPositionByKey(u8 *h, u8 key, s32 *px, s32 *py)
{
    s16 s[4];
    CircleGraph_GetSliceMiddle(h, CircleGraph_GetSliceByKey(h, key), s);
    CircleGraph_ProjectToScreen(s, px, py);
}


