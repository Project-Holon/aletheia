/*
 * function: WIFICLUB_StateWaitPrompt
 * address:  0x021C01A0
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
 * Re-arms the block 0x274 bytes in, then runs the setup and stamps selector
 * 0x21 when the guard answers true; returns the selector.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUBACTOR_TickBlink(char *p);
extern int WIFICLUB_UpdateTalkStream(void *p);
extern void WIFICLUB_OpenYesNoMenu(char *p);

int WIFICLUB_StateWaitPrompt(char *p, int v)
{
    WIFICLUBACTOR_TickBlink(p + 0x274);

    if (WIFICLUB_UpdateTalkStream(p) != 0) {
        WIFICLUB_OpenYesNoMenu(p);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x21;
    }

    return v;
}
