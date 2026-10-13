/*
 * function: WIFICLUB_OpenPanelOrRedrawPage
 * address:  0x021C205C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_OpenPartnerPanelWithBg  0x021BB2F0  thumb  ov099
 *   WIFICLUB_RedrawSlotPanels  0x021C2090  thumb  ov099
 *
 * Routes on the flag byte 0x8EF bytes in: hands the selector on to WIFICLUB_OpenPartnerPanelWithBg
 * when it is set, otherwise raises the word at +0x8F4 and calls WIFICLUB_RedrawSlotPanels.
 * The selector stays live into the first branch, which is what keeps the 0x8EF
 * constant out of r1 and gives the image its `adds r1, r2, #5`.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUB_OpenPartnerPanelWithBg(char *p, int v);
extern void WIFICLUB_RedrawSlotPanels(char *p);

void WIFICLUB_OpenPanelOrRedrawPage(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        WIFICLUB_OpenPartnerPanelWithBg((char *)p, v);
        return;
    }

    *(u32 *)&((struct Obj00008 *)p)->f8F4 = 1;
    WIFICLUB_RedrawSlotPanels((char *)p);
}
