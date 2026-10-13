/*
 * function: WIFICLUB_EnableTouchBar
 * address:  0x021C23D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_SetMode  0x021B98F8  thumb  ov099
 *   WIFICLUB_ShowMessage  0x021BAADC  thumb  ov099
 *
 * Raises the state word at +0x9B4 once, re-arms the block 0x274 bytes in, and
 * runs the six/zero setup when the selector is 1.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUBACTOR_SetMode(char *p, int b);
extern void WIFICLUB_ShowMessage(char *p, int a, int b);

void WIFICLUB_EnableTouchBar(char *p, int v)
{
    if (((struct Obj00008 *)p)->f9B4 != 0) {
        return;
    }

    ((struct Obj00008 *)p)->f9B4 = 1;
    WIFICLUBACTOR_SetMode(p + 0x274, 1);

    if (v == 1) {
        WIFICLUB_ShowMessage(p, 6, 0);
    }
}
