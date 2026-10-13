/*
 * function: WIFICLUB_StateVoiceYesNo
 * address:  0x021BC4D4
 * packet:   pkt_ov099_021BC4D4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_PollYesNoMenu  0x021BA858  thumb  ov099
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 */
#include "../include/Obj22028.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef enum { K274 = 0x274 } Off;

extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void WIFICLUBACTOR_TickBlink(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);

int WIFICLUB_StateVoiceYesNo(char *p, int v)
{
    int r;
    Off o;

    r = WIFICLUB_PollYesNoMenu(p);
    o = K274;
    WIFICLUBACTOR_TickBlink(p + o);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        *(u32 *)(p + (o - 0xa8)) = 0x52;
        WIFICLUB_ClearTalkWindow(p);
    } else {
        ((struct Obj22028 *)p)->f1353 = 0x90;
        *(u32 *)(p + (o - 0xa8)) = 0x8a;
    }
    return v;
}
