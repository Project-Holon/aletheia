/*
 * function: WF2DMAP_TOUCH_SetTopHighlight
 * address:  0x021CA184
 * packet:   pkt_021CA184
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WF2DMAP_TOUCH_SetTopHighlight1  0x021CA154  thumb
 *   WF2DMAP_TOUCH_SetTopHighlight3  0x021CA16C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void WF2DMAP_TOUCH_SetTopHighlight1(u8 *, int);
extern void WF2DMAP_TOUCH_SetTopHighlight3(u8 *, int);

void WF2DMAP_TOUCH_SetTopHighlight(u8 *p, int a, int b)
{
    WF2DMAP_TOUCH_SetTopHighlight1(p, b);
    WF2DMAP_TOUCH_SetTopHighlight3(p, a);
}
