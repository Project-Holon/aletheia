/*
 * function: WIFICLUB_StatePollEntryPrompt
 * address:  0x021BCFB4
 * packet:   pkt_ov099_021BCFB4
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
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 */
#include "../include/Obj06356.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void GF_FONT_SetDefaultTextColor(void);
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StatePollEntryPrompt(char *p, int v)
{
    int r;

    GF_FONT_SetDefaultTextColor();
    r = WIFICLUB_PollYesNoMenu(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj06356 *)p)->f1CC = 0x62;
        WIFICLUB_ClearTalkWindow(p);
    } else {
        if ((unsigned)(((struct Obj06356 *)p)->f135C - 1) <= 1) {
            ((struct Obj06356 *)p)->f1353 = 0x4A;
            WIFICLUB_ShowStreamedMessage(p, 0x4A, 0);
        } else {
            ((struct Obj06356 *)p)->f1353 = 0x90;
        }
        ((struct Obj06356 *)p)->f1CC = 0x8A;
    }
    return v;
}
