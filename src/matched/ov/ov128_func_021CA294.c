/*
 * function: WF2DMAP_TOUCH_SetItemHighlight1
 * address:  0x021CA294
 * packet:   pkt_021CA294
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_TOUCH_DrawItemHighlight  0x021CA25C  thumb
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14051.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct CodeIn;
extern void WF2DMAP_TOUCH_DrawItemHighlight(u32 a, u32 b);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void WF2DMAP_TOUCH_SetItemHighlight1(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawItemHighlight(a, 1);
    BLINK_PALANM_ResetPhase(((struct Obj14051 *)p)->f184);
}
