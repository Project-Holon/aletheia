/*
 * function: WF2DMAP_TOUCH_SetItemHighlight
 * address:  0x021CA2C4
 * packet:   pkt_021CA2C4
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WF2DMAP_TOUCH_SetItemHighlight1  0x021CA294  thumb
 *   WF2DMAP_TOUCH_SetItemHighlight3  0x021CA2AC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void WF2DMAP_TOUCH_SetItemHighlight1(u8 *, int);
extern void WF2DMAP_TOUCH_SetItemHighlight3(u8 *, int);

void WF2DMAP_TOUCH_SetItemHighlight(u8 *p, int a, int b)
{
    WF2DMAP_TOUCH_SetItemHighlight1(p, b);
    WF2DMAP_TOUCH_SetItemHighlight3(p, a);
}
