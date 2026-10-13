/*
 * function: WIFICLUB_StatePollWaitPrompt
 * address: 0x021BD5FC
 * packet: pkt_ov099_021BD5FC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj10205.h"
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);
int WIFICLUB_StatePollWaitPrompt(char *p, int ret)
{
    int v;
    GF_FONT_SetDefaultTextColor();
    v = WIFICLUB_PollYesNoMenu(p);
    if (v == -1) return ret;
    if (v == 0) p[0x1353] = 0x44;
    else p[0x1353] = 0x4a;
    WIFICLUB_ClearTalkWindow(p);
    ((struct Obj10205 *)p)->f1CC = 0x8a;
    return ret;
}
