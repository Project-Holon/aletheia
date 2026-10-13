/*
 * function: WIFICLUB_StatePollSeatYesNo
 * address: 0x021C17F4
 * packet: pkt_ov099_021C17F4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: WIFICLUB_GetStatusSeatFlag returns u8, eliminating the redundant narrowing at 021C1848.
 * symbols:
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_SetStatusSeatFlag 0x021C27E8 thumb ov099
 *   WIFICLUB_SetStatusModeFlag 0x021C2864 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   WIFICLUB_ResetOwnSeatStatus 0x021C19A8 thumb ov099
 *   WIFICLUB_DrawPlayerInfoWindow 0x021BAEDC thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj02803.h"
#include "../include/Obj22058.h"
typedef unsigned char u8;
extern int WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *, int);
extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern u8 WIFICLUB_GetStatusSeatFlag(void *);
extern void WIFICLUB_SetStatusSeatFlag(void *, u8);
extern void WIFICLUB_SetStatusModeFlag(void *, u8);
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
extern void WIFICLUB_ResetOwnSeatStatus(char *);
extern void WIFICLUB_DrawPlayerInfoWindow(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StatePollSeatYesNo(char *p, int state)
{
    void *selection;
    int result;
    selection = WIFICLUB_FindPeerActor(p, WIFICLUBACTOR_GetPickResult(p + 0x274));
    GF_FONT_SetDefaultTextColor();
    result = WIFICLUB_PollYesNoMenu(p);
    if (result == -1) return state;
    if (result == 0) {
        WIFICLUB_SetStatusSeatFlag(((struct Obj02803 *)p)->f8, 1 - WIFICLUB_GetStatusSeatFlag(((struct Obj02803 *)p)->f8));
        WIFICLUB_SetStatusModeFlag(((struct Obj02803 *)p)->f8, WIFICLUB_GetStatusSeatFlag(((struct Obj02803 *)p)->f8));
        ((struct Obj02803 *)p)->f1356 = 2 - ((struct Obj22058 *)(*(char * *)&((struct Obj02803 *)p)->f248))->f46;
        ((struct Obj02803 *)p)->f1CC = 118;
    } else {
        ((struct Obj02803 *)p)->f135C = 0;
        WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
        ((struct Obj02803 *)p)->f1F0 = -1;
        if (selection != 0) WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, selection);
        WIFICLUB_ResetOwnSeatStatus(p);
        WIFICLUB_DrawPlayerInfoWindow(p);
        ((struct Obj02803 *)p)->f1CC = 11;
    }
    WIFICLUB_ClearTalkWindow(p);
    return state;
}
