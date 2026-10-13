/*
 * function: WIFICLUB_StateOpenNoticeYesNo
 * address:  0x021BC43C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   WIFICLUB_OpenYesNoMenu  0x021BA828  thumb  ov099
 *
 * Re-arms, then runs the setup and stamps 0xA5 when the guard answers true.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_TickBlink(char *p);
extern int WIFICLUB_UpdateTalkStream(void *p);
extern void WIFICLUB_OpenYesNoMenu(char *p);

int WIFICLUB_StateOpenNoticeYesNo(char *p, int v)
{
    WIFICLUBACTOR_TickBlink(p + 0x274);

    if (WIFICLUB_UpdateTalkStream(p) != 0) {
        WIFICLUB_OpenYesNoMenu(p);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0xA5;
    }

    return v;
}
