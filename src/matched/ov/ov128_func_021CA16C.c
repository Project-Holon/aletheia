/*
 * function: WF2DMAP_TOUCH_SetTopHighlight3
 * address:  0x021CA16C
 * packet:   pkt_021CA16C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_TOUCH_DrawTopHighlight  0x021CA124  thumb
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00329.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct CodeIn;
extern void WF2DMAP_TOUCH_DrawTopHighlight(u32 a, u32 b);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void WF2DMAP_TOUCH_SetTopHighlight3(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawTopHighlight(a, 3);
    BLINK_PALANM_ResetPhase(((struct Obj00329 *)p)->f184);
}
