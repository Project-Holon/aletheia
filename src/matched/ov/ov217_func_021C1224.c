/*
 * function: CircleGraph_GetLabelPositionByIndex
 * address:  0x021C1224
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
 *   CircleGraph_GetSlice  0x021C1AB4  thumb  ov217
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

extern void *CircleGraph_GetSlice(void *p, u32 n);
extern void CircleGraph_GetSliceMiddle(u8 *p, u8 *rec, s16 *out);
extern void CircleGraph_ProjectToScreen(const s16 *p, s32 *px, s32 *py);

void CircleGraph_GetLabelPositionByIndex(u8 *h, u8 n, s32 *px, s32 *py)
{
    s16 s[4];
    CircleGraph_GetSliceMiddle(h, CircleGraph_GetSlice(h, n), s);
    CircleGraph_ProjectToScreen(s, px, py);
}


