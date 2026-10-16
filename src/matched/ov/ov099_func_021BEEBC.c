/*
 * function: WIFICLUB_ResetClubScreen
 * address: 0x021BEEBC
 * packet: pkt_ov099_021BEEBC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a named enabled result before kind initialization preserves call/store scheduling.
 * symbols:
 *   DWC_RAP_SetAcceptFriendCallback 0x02155664 thumb ov009
 *   WIFICLUB_IsFriendRequestFromPeer 0x021BEE64 thumb ov099
 *   func_020490F4 0x020490F4 arm
 *   WIFICLUB_ResetOwnSeatStatus 0x021C19A8 thumb ov099
 *   WIFICLUB_ClosePartnerMenu 0x021C0290 thumb ov099
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02009A54 0x02009A54 thumb
 *   WIFICLUBACTOR_Init 0x021B95A0 thumb ov099
 *   WIFICLUBACTOR_SpawnCursorActor 0x021B9900 thumb ov099
 *   WIFICLUB_AddPeerActor 0x021BE21C thumb ov099
 *   WIFICLUB_IsSlotPanelOpen 0x021C1A44 thumb ov099
 *   WIFICLUB_OpenSlotPanel 0x021C1A58 thumb ov099
 *   WIFICLUB_CopyZeroToDeviceAddr 0x021C282C thumb ov099
 *   WIFICLUB_OpenPanelOrRedrawPage 0x021C205C thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_RefreshVisibleList 0x021BE788 thumb ov099
 *   WIFICLUB_CreateTitleWindows 0x021BEDA0 thumb ov099
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
struct Sub020097BCObj;
extern void DWC_RAP_SetAcceptFriendCallback(void (*callback)(void));
struct Sub0200852CObj;
extern int WIFICLUB_IsFriendRequestFromPeer(void *a, char *b);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIFICLUB_ResetOwnSeatStatus(char *);
extern void WIFICLUB_ClosePartnerMenu(char *);
extern void MI_CpuFill8(void *,int,int);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern int WIFICLUBACTOR_IsReady(int *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02009A54(struct Sub020097BCObj *obj);
extern void WIFICLUBACTOR_Init(char *p, int heap, u32 x2, u32 x3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u8 *WIFICLUBACTOR_SpawnCursorActor(u8 *p, int v);
extern void WIFICLUB_AddPeerActor(char *,void *);
extern int WIFICLUB_IsSlotPanelOpen(char *);
extern void WIFICLUB_OpenSlotPanel(char *,int,int);
extern int WIFICLUB_CopyZeroToDeviceAddr(u8 *p);
extern void WIFICLUB_OpenPanelOrRedrawPage(u8 *p, int v);
extern void WIFICLUB_ClearTalkWindow(char *);
extern int WIFICLUB_RefreshVisibleList(char *);
extern void WIFICLUB_CreateTitleWindows(char *);
extern void WIFICLUB_StartNetSession(void *p, int on);
extern void ARC_TOOL_DeleteHandle(void *);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void WIFICLUB_ResetClubScreen(char *p)
{
    void *h;
    int kind, enabled;
    DWC_RAP_SetAcceptFriendCallback((void (*)(void))WIFICLUB_IsFriendRequestFromPeer);
    h=func_020490F4(33,33);
    WIFICLUB_ResetOwnSeatStatus(p);
    WIFICLUB_ClosePartnerMenu(p);
    MI_CpuFill8(p+0x30,0,32);
    if(((struct Obj00008 *)p)->fB0){
        BMP_WIN_Delete(((struct Obj00008 *)p)->f1A0);
        BMP_MENULIST_Delete(((struct Obj00008 *)p)->fB4,0,0);
        ((struct Obj00008 *)p)->fB4=0;
        BMP_MENUWORK_Delete(((struct Obj00008 *)p)->fB0);
        ((struct Obj00008 *)p)->fB0=0;
    }
    if(!WIFICLUBACTOR_IsReady((int *)(p+0x274))){
        enabled=func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj00008 *)p)->fC4));
        kind=16;
        if(enabled)kind=17;
        ((struct Obj00008 *)p)->f132A=func_02009A54(((struct Obj00008 *)p)->f4);
        WIFICLUBACTOR_Init(p+0x274,33,(u32)h,kind,((struct Obj00008 *)p)->f132A,33,(u32)(((struct Obj00008 *)p)->f110),(u32)(((struct Obj00008 *)p)->f114));
        WIFICLUB_AddPeerActor(p,WIFICLUBACTOR_SpawnCursorActor((u8 *)(p+0x274),kind));
    }
    if(!WIFICLUB_IsSlotPanelOpen(p))WIFICLUB_OpenSlotPanel(p,(int)h,33);
    WIFICLUB_CopyZeroToDeviceAddr(((struct Obj00008 *)p)->f8);
    ((struct Obj00008 *)p)->f1351=0;
    WIFICLUB_OpenPanelOrRedrawPage((u8 *)p,33);
    WIFICLUB_ClearTalkWindow(p);
    WIFICLUB_RefreshVisibleList(p);
    WIFICLUB_CreateTitleWindows(p);
    WIFICLUB_StartNetSession(p,0);
    ((struct Obj00008 *)p)->f1F0=-1;
    ARC_TOOL_DeleteHandle(h);
    WIPE_SYS_Start(0,1,1,0,6,1,33);
}
