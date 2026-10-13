/*
 * function: WIFICLUB_StateOpenSeatYesNo
 * address:  0x021C17D4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   WIFICLUB_OpenYesNoMenu  0x021BA828  thumb  ov099
 *
 * Runs the setup and stamps selector 0x38 when the guard answers true.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_UpdateTalkStream(void *p, int v);
extern void WIFICLUB_OpenYesNoMenu(char *p);

int WIFICLUB_StateOpenSeatYesNo(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p, v) != 0) {
        WIFICLUB_OpenYesNoMenu(p);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x38;
    }

    return v;
}
