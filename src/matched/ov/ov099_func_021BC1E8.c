/*
 * function: WIFICLUB_StateInviteYesNo
 * address:  0x021BC1E8
 * packet:   pkt_ov099_021BC1E8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   WIFICLUB_PollYesNoMenu  0x021BA858  thumb  ov099
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 */
#include "../include/Obj10203.h"

typedef unsigned char u8;

extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);

int WIFICLUB_StateInviteYesNo(char *p, int r)
{
    int v;

    GF_FONT_SetDefaultTextColor();
    v = WIFICLUB_PollYesNoMenu(p);
    if (v == -1)
        return r;
    if (v == 0)
        ((struct Obj10203 *)p)->f1353 = 0x44;
    else
        ((struct Obj10203 *)p)->f1353 = 0x4A;
    WIFICLUB_ClearTalkWindow(p);
    ((struct Obj10203 *)p)->f1CC = 0x8A;
    return r;
}
