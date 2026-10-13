/*
 * function: WIFICLUB_StateOpenRuleChoicePrompt
 * address:  0x021BD864
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
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x7F.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_UpdateTalkStream(void *p);
extern void WIFICLUB_OpenYesNoMenu(char *p);

int WIFICLUB_StateOpenRuleChoicePrompt(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p) == 0) {
        return v;
    }

    WIFICLUB_OpenYesNoMenu(p);
    *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x7F;
    return v;
}
