/*
 * unit: yes
 * function: WIFICLUB_ExitScreen, WIFICLUB_VBlankTask
 * address: 0x021BDF7C
 * packet: pkt_ov099_021BDF7C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   WIFICLUB_DeleteTrainerActor 0x021BB42C thumb ov099
 *   WIFICLUB_DeleteTouchBar 0x021BB4D0 thumb ov099
 *   WIFICLUB_LoadPanelGraphics 0x021BB4EC thumb ov099
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   WIFICLUB_ClearPeerActors 0x021BE26C thumb ov099
 *   WIFICLUB_IsSlotPanelOpen 0x021C1A44 thumb ov099
 *   WIFICLUB_CloseSlotPanel 0x021C1AC0 thumb ov099
 *   WIFICLUB_FreeBgResources 0x021BE384 thumb ov099
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   WIFICLUB_DeleteAllWindows 0x021BB0B4 thumb ov099
 *   WIFICLUB_ExitHook 0x021BE538 thumb ov099
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj00008.h"
struct Bank;
struct Node;
struct Rec;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void WIFICLUB_DeleteTrainerActor(void *p);
extern void WIFICLUB_DeleteTouchBar(char *p);
extern void WIFICLUB_LoadPanelGraphics(void *p);
extern int WIFICLUBACTOR_IsReady(int *p);
extern void WIFICLUB_ClearPeerActors(char *p);
extern int WIFICLUB_IsSlotPanelOpen(char *p);
extern void WIFICLUB_CloseSlotPanel(char *p);
extern void WIFICLUB_FreeBgResources(void *p);
extern void CLACT_DeleteRenderer(void *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void WIFICLUB_DeleteAllWindows(char *p);
extern void WIFICLUB_ExitHook(char *p);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_Delete(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void CLACT_VBlankSystem(void);
void WIFICLUB_ExitScreen(char *p)
{
    if (((struct Obj00008 *)p)->f0 != 0) func_02030EAC(((struct Obj00008 *)p)->f0);
    WIFICLUB_DeleteTrainerActor(p);
    WIFICLUB_DeleteTouchBar(p);
    WIFICLUB_LoadPanelGraphics(p);
    if (WIFICLUBACTOR_IsReady((int *)(p + 0x274)) == 1) WIFICLUB_ClearPeerActors(p);
    if (WIFICLUB_IsSlotPanelOpen(p) == 1) WIFICLUB_CloseSlotPanel(p);
    WIFICLUB_FreeBgResources(p + 0x898);
    CLACT_DeleteRenderer(((struct Obj00008 *)p)->f114);
    CLACT_DeleteUnit(((struct Obj00008 *)p)->f110);
    CLACT_ExitSystem();
    WIFICLUB_DeleteAllWindows(p);
    WIFICLUB_ExitHook(p);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MSGDATA_Delete(((struct Obj00008 *)p)->fE4);
    MSGDATA_Delete(((struct Obj00008 *)p)->fE0);
    WORDSET_Delete(((struct Obj00008 *)p)->fDC);
    GF_FONT_Delete(((struct Obj00008 *)p)->fEC);
    GF_FONT_Delete(((struct Obj00008 *)p)->fE8);
}
void WIFICLUB_VBlankTask(void)
{
    CLACT_VBlankSystem();
}
