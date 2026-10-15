/*
 * function: STA_ACTING_ShowAnim
 * address:  0x021F9D80
 * packet:   pkt_021F9D80
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STA_ACT_BUTTON_SetVisible  0x021FAAB8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23210.h"

extern void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag);

void STA_ACTING_ShowAnim(char *p)
{
    STA_ACT_BUTTON_SetVisible(((struct Obj23210 *)p)->fA4, 1);
}
