/*
 * function: func_021A1934
 * address:  0x021A1934
 * packet:   pkt_ov021_021A1934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * G3_MaterialColorDiffAmb(white, white, TRUE) as a literal, then the SDK
 * G3_PolygonAttr inline (int parameters) with polygon id +0x1E, alpha +0x1F.
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

static inline void G3_PolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc)
{
    *(volatile u32 *)0x040004A4 = (u32)((light << 0) | (polyMode << 4) | (cullMode << 6) | misc |
                                        (polygonID << 24) | (alpha << 16));
}

void func_021A1934(u8 *p)
{
    *(volatile u32 *)0x040004C0 = 0x7FFFFFFF;
    G3_PolygonAttr(0, 0, 2, p[0x1E], p[0x1F], 0x8000);
}
