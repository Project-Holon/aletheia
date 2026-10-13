/*
 * function: WIFICLUB_StatePollLeavePrompt
 * address: 0x021BDAC8
 * packet: pkt_ov099_021BDAC8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned byte stores materialize 0xa8 as movs, rather than a signed subtraction.
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj10206.h"
typedef unsigned char u8;
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);
int WIFICLUB_StatePollLeavePrompt(char *p, int result)
{
    int v;
    GF_FONT_SetDefaultTextColor();
    v = WIFICLUB_PollYesNoMenu(p);
    if (v == -1) return result;
    if (v == 0) ((struct Obj10206 *)p)->f1353 = 0x44;
    else ((struct Obj10206 *)p)->f1353 = 0xa8;
    WIFICLUB_ClearTalkWindow(p);
    ((struct Obj10206 *)p)->f1CC = 0x8a;
    return result;
}
