/*
 * function: WIFICLUB_IsTalkFinishedOrClosed
 * address:  0x021C14EC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_UpdateTalkStream  0x021BA928  thumb  ov099
 *   WIFICLUB_OpenYesNoMenu  0x021BA828  thumb
 *
 * True when the guard answers true or the pointer 0x190 bytes in is still unset.
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

BOOL WIFICLUB_IsTalkFinishedOrClosed(char *p)
{
    if (WIFICLUB_UpdateTalkStream(p) != 0) {
        return 1;
    }

    if (((struct Obj00008 *)p)->f190 == 0) {
        return 1;
    }

    return 0;
}
