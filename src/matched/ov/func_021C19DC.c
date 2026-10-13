/*
 * function: WIFICLUB_ClosePartnerPanel
 * address:  0x021C19DC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_DeleteTrainerActor  0x021BB42C  thumb  ov099
 *   WIFICLUB_DeleteTouchBar  0x021BB4D0  thumb  ov099
 *   WIFICLUB_LoadPanelGraphics  0x021BB4EC  thumb  ov099
 *   WIFICLUB_ResetSlotSelection  0x021C1C70  thumb  ov099
 *   WIFICLUB_ReleaseSlotActors  0x021BF29C  thumb  ov099
 *   WIFICLUBACTOR_HideMarker  0x021B98F0  thumb  ov099
 *   WIFICLUB_OpenPanelOrRedrawPage  0x021C205C  thumb  ov099
 *
 * The ordered teardown of the block: five one-argument steps on p, the re-arm
 * of the 0x274-offset sub-object, and finally WIFICLUB_OpenPanelOrRedrawPage with the selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUB_DeleteTrainerActor(void *p, int v);
extern void WIFICLUB_DeleteTouchBar(char *p);
extern void WIFICLUB_LoadPanelGraphics(void *p);
extern void WIFICLUB_ResetSlotSelection(char *p);
extern void WIFICLUB_ReleaseSlotActors(char *p);
extern void WIFICLUBACTOR_HideMarker(void *p);
extern void WIFICLUB_OpenPanelOrRedrawPage(u8 *p, int v);

void WIFICLUB_ClosePartnerPanel(char *p, int v)
{
    WIFICLUB_DeleteTrainerActor(p, v);
    WIFICLUB_DeleteTouchBar(p);
    WIFICLUB_LoadPanelGraphics(p);
    WIFICLUB_ResetSlotSelection(p);
    WIFICLUB_ReleaseSlotActors(p);
    WIFICLUBACTOR_HideMarker(p + 0x274);
    WIFICLUB_OpenPanelOrRedrawPage((u8 *)p, v);
}
