/*
 * function: WIFICLUB_RequestSelectionRefresh
 * address:  0x021BF24C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_SyncActorsWithPeers  0x021BE7EC  thumb  ov099
 *   WIFICLUB_OpenPartnerPanel  0x021BB2B0  thumb  ov099
 *   WIFICLUB_RedrawSlotPanels  0x021C2090  thumb  ov099
 *
 * Under a positive answer from WIFICLUB_SyncActorsWithPeers, routes on the flag at +0x8EF:
 * hands the selector to WIFICLUB_OpenPartnerPanel when set, otherwise raises the word at
 * +0x8F4 and calls WIFICLUB_RedrawSlotPanels.
 */
#include "../include/Obj06353.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int WIFICLUB_SyncActorsWithPeers(char *p);
extern void WIFICLUB_OpenPartnerPanel(char *p, int v);
extern void WIFICLUB_RedrawSlotPanels(char *p);

void WIFICLUB_RequestSelectionRefresh(u8 *p, int v)
{
    if (WIFICLUB_SyncActorsWithPeers((char *)p) <= 0) {
        return;
    }

    if (p[0x8EF] != 0) {
        WIFICLUB_OpenPartnerPanel((char *)p, v);
        return;
    }

    ((struct Obj06353 *)p)->f8F4 = 1;
    WIFICLUB_RedrawSlotPanels((char *)p);
}
