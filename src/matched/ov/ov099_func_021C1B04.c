/*
 * function: WIFICLUB_UpdateSlotPanel
 * address: 0x021C1B04
 * packet: pkt_ov099_021C1B04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte addition of 254 emits adds #0xfe; subtraction emits subs #2.
 * prototype: B9800/B984C leave their C4864 result live; this caller reads r0.
 * symbols:
 *   WIFICLUBACTOR_GetCursorTileAttr 0x021B9800 thumb ov099
 *   WIFICLUBACTOR_GetCursorTileBelowAttr 0x021B984C thumb ov099
 *   WIFICLUB_EmptyHook 0x021C208C thumb ov099
 *   WIFICLUB_OpenPartnerPanelWithBg 0x021BB2F0 thumb ov099
 *   WIFICLUB_DeleteTrainerActor 0x021BB42C thumb ov099
 *   WIFICLUB_DeleteTouchBar 0x021BB4D0 thumb ov099
 *   WIFICLUB_LoadPanelGraphics 0x021BB4EC thumb ov099
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   WIFICLUB_TickSlotBlink 0x021C1CD4 thumb ov099
 *   WIFICLUB_RedrawSlotPanels 0x021C2090 thumb ov099
 *   WIFICLUB_IsSlotPanelDismissed 0x021C1C10 thumb ov099
 *   WIFICLUB_ClosePartnerPanel 0x021C19DC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 WIFICLUBACTOR_GetCursorTileAttr(void *);
extern u32 WIFICLUBACTOR_GetCursorTileBelowAttr(void *);
extern void WIFICLUB_EmptyHook(char *);
extern void WIFICLUB_OpenPartnerPanelWithBg(char *, int);
extern void WIFICLUB_DeleteTrainerActor(void *);
extern void WIFICLUB_DeleteTouchBar(char *);
extern void WIFICLUB_LoadPanelGraphics(void *);
typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void WIFICLUB_TickSlotBlink(void *);
extern void WIFICLUB_RedrawSlotPanels(char *);
extern int WIFICLUB_IsSlotPanelDismissed(void *);
extern void WIFICLUB_ClosePartnerPanel(char *, int);
u8 WIFICLUB_UpdateSlotPanel(char *p, int heap)
{
    u32 first, second;
    first = WIFICLUBACTOR_GetCursorTileAttr(p + 0x274);
    second = WIFICLUBACTOR_GetCursorTileBelowAttr(p + 0x274);
    if (second >= 3 && second <= 6) first = second;
    if (first >= 3 && first <= 6 && ((struct Obj00008 *)p)->f8EC != first - 3) {
        ((struct Obj00008 *)p)->f8EC = first - 3;
        WIFICLUB_EmptyHook(p);
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    if (((struct Obj00008 *)p)->f8EF == 1) {
        ((struct Obj00008 *)p)->f8EF = 2;
        WIFICLUB_OpenPartnerPanelWithBg(p, heap);
    }
    if (((struct Obj00008 *)p)->f8EF == 0) {
        WIFICLUB_DeleteTrainerActor(p);
        WIFICLUB_DeleteTouchBar(p);
        WIFICLUB_LoadPanelGraphics(p);
        BUTTON_MAN_UpdateSlots(((struct Obj00008 *)p)->f8C8);
        WIFICLUB_TickSlotBlink(p);
        if (((struct Obj00008 *)p)->f8F1 == 1) {
            WIFICLUB_RedrawSlotPanels(p);
            ((struct Obj00008 *)p)->f8F1 = 0;
        }
    }
    if ((u8)(((struct Obj00008 *)p)->f8EF + 254) <= 1 && WIFICLUB_IsSlotPanelDismissed(p) == 1) {
        ((struct Obj00008 *)p)->f8ED = 0;
        ((struct Obj00008 *)p)->f8EE = 0;
        ((struct Obj00008 *)p)->f8F1 = 1;
        ((struct Obj00008 *)p)->f8F4 = 1;
        WIFICLUB_ClosePartnerPanel(p, heap);
        ((struct Obj00008 *)p)->f8EF = 0;
        ((struct Obj00008 *)p)->f8F4 = 1;
    }
    return ((struct Obj00008 *)p)->f8ED;
}
