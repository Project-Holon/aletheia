/*
 * unit: yes
 * function: WIFICLUB_StatePollRuleChoicePrompt, WIFICLUB_StateShowMenuReject
 * address: 0x021BD888
 * packet: pkt_ov099_021BD888
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
#include "../include/Obj13693.h"
#include "../include/Obj13694.h"
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StatePollRuleChoicePrompt(char *p, int v)
{
    int t;
    GF_FONT_SetDefaultTextColor();
    t = WIFICLUB_PollYesNoMenu(p);
    if (t == -1) return v;
    if (t == 0) {
        ((struct Obj13693 *)p)->f1CC = 0x80;
    } else {
        ((struct Obj13693 *)p)->f1CC = 0x86;
    }
    WIFICLUB_ClearTalkWindow(p);
    return v;
}
int WIFICLUB_StateShowMenuReject(char *p, int v)
{
    ((struct Obj13694 *)p)->f1353 = 0x4a;
    ((struct Obj13694 *)p)->f1CC = 0x8a;
    return v;
}
