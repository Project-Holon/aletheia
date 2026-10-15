/*
 * function: WIFICLUB_StateRestartMatch
 * address: 0x021BE9C8
 * packet: pkt_ov099_021BE9C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enclosing guard shares the final return and keeps the original callee-saved register assignment.
 * prototypes: SDK 414AC and 49238 preserve their original live R0 inputs despite void(void) assembly declarations.
 * symbols:
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIFICLUB_ClearPeerActors 0x021BE26C thumb ov099
 *   CLACT_FlushOamIfPending 0x0204A698 arm
 *   WIFICLUB_IsSlotPanelOpen 0x021C1A44 thumb ov099
 *   WIFICLUB_CloseSlotPanel 0x021C1AC0 thumb ov099
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020490F4 0x020490F4 arm
 *   WIFICLUB_InitPlanesAndText 0x021BE53C thumb ov099
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFICLUB_DrawHeaderWindow 0x021BB050 thumb ov099
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj02802.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 GFL_NET_IsIdle(void);
extern int WIFICLUBACTOR_IsReady(int *);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void WIFICLUB_ClearPeerActors(char *);
extern void CLACT_FlushOamIfPending(void);
extern int WIFICLUB_IsSlotPanelOpen(char *);
extern void WIFICLUB_CloseSlotPanel(char *);
extern int WIFICLUB_DeleteWindow(void *);
extern void BG_SYS_FreeSlot(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIFICLUB_InitPlanesAndText(char *p, int v);
extern void ARC_TOOL_DeleteHandle(void *);
struct Descriptor;
struct Obj;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void MI_CpuFill8(void *, u32, u32);
extern void WIFICLUB_DrawHeaderWindow(void *);
extern void WIFICLUB_StartNetSession(void *, int);
extern void GFL_NET_STATE_WifiStartMatch(void);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_StateRestartMatch(char *p, int v)
{
    void *h;
    if (GFL_NET_IsIdle() == 0) {
        if (WIFICLUBACTOR_IsReady((int *)(p + 0x274)) == 1) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x21);
            WIFICLUB_ClearPeerActors(p);
            CLACT_FlushOamIfPending();
        }
        if (WIFICLUB_IsSlotPanelOpen(p) == 1) WIFICLUB_CloseSlotPanel(p);
        ((struct Obj02802 *)p)->f198 = (void *)WIFICLUB_DeleteWindow(((struct Obj02802 *)p)->f198);
        BG_SYS_FreeSlot(3);
        h = func_020490F4(0x21, 0x21);
        WIFICLUB_InitPlanesAndText(p, (int)h);
        ARC_TOOL_DeleteHandle(h);
        ((struct Obj02802 *)p)->f1328 = 1;
        if (((struct Obj02802 *)p)->fB0 != 0) {
            BMP_WIN_Delete(((struct Obj02802 *)p)->f1A0);
            BMP_MENULIST_Delete(((struct Obj02802 *)p)->fB4, 0, 0);
            ((struct Obj02802 *)p)->fB4 = 0;
            BMP_MENUWORK_Delete(((struct Obj02802 *)p)->fB0);
            ((struct Obj02802 *)p)->fB0 = 0;
        }
        MI_CpuFill8(p + 0x10, 0, 0x20);
        MI_CpuFill8(p + 0x30, 0, 0x20);
        MI_CpuFill8(p + 0x50, 0, 0x20);
        MI_CpuFill8(p + 0x70, 0, 0x20);
        MI_CpuFill8(p + 0x90, 0, 0x20);
        WIFICLUB_DrawHeaderWindow(p);
        WIFICLUB_StartNetSession(p, 0);
        GFL_NET_STATE_WifiStartMatch();
        WIFICLUB_ShowStreamedMessage(p, 0x17, 1);
        ((struct Obj02802 *)p)->f1CC = 5;
    }
    return v;
}
