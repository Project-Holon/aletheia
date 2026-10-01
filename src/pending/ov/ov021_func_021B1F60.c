/*
 * function: func_021B1F60
 * address:  0x021B1F60
 * packet:   pkt_ov021_021B1F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: every byte right except two branch displacements: the image
 * sends cases 2 and 3 to case 1's "b store" (a cross-jumped branch onto a
 * branch); this source sends them straight to the store. Tried result
 * variable, int/u16 inline return, nested inline: no change.
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 *func_02158F58(u32);
extern u32 func_02188CB4(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_021A3098(u32);

static inline int func_021B1F60_conv(int v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    return 0;
}

int func_021B1F60(u32 a, u32 b)
{
    u32 x = func_02188CB4(func_02158F58(func_0215A5F4(b))[1]);
    u16 *o = func_02159AE8(a, b);

    *o = func_021B1F60_conv(func_021A3098(x));
    return 0;
}
