/*
 * function: STA_ACTING_HideAnim
 * address: 0x021F9D90
 * packet: pkt_ov132_021F9D90
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_BUTTON_SetVisible 0x021FAAB8 thumb ov132
 */
#include "../include/Obj23211.h"
extern void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag);
void STA_ACTING_HideAnim(char *p){STA_ACT_BUTTON_SetVisible(((struct Obj23211 *)p)->fA4,0);}
