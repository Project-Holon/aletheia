/*
 * file:     guru2_receipt.c
 * unit:     yes
 * function: GURU2_RECEIPT_ProcInit, GURU2_RECEIPT_GetUnionApp, GURU2_RECEIPT_SendMemberCount, GURU2_RECEIPT_UnionAppNoop, GURU2_RECEIPT_ProcMain, GURU2_RECEIPT_ProcExit, GURU2_RECEIPT_AnimatePalette, GURU2_RECEIPT_VBlank, GURU2_RECEIPT_UpdateQueues, GURU2_RECEIPT_SetVramBanks, GURU2_RECEIPT_InitBg, GURU2_RECEIPT_InitStrings, GURU2_RECEIPT_FreeStrings, GURU2_RECEIPT_ExitBg, GURU2_RECEIPT_LoadGraphics, GURU2_RECEIPT_InitActors, GURU2_RECEIPT_FreeActors, GURU2_RECEIPT_CreatePlayerActors, GURU2_RECEIPT_CreateWindows, GURU2_RECEIPT_PrintTitle, GURU2_RECEIPT_DeleteWindows, GURU2_RECEIPT_StateInit, GURU2_RECEIPT_StateIdleStart, GURU2_RECEIPT_HandleKeys, GURU2_RECEIPT_Noop, GURU2_RECEIPT_StateGoToMessage, GURU2_RECEIPT_SetPendingState, GURU2_RECEIPT_StateWaitMessage, GURU2_RECEIPT_StateReopenRecruit, GURU2_RECEIPT_StateOpenStartMenu, GURU2_RECEIPT_StateStartMenu, GURU2_RECEIPT_StateResetWait, GURU2_RECEIPT_StateWaitAnswers, GURU2_RECEIPT_StateAnswersDone, GURU2_RECEIPT_StateOpenCancelMenu, GURU2_RECEIPT_StateCancelMenu, GURU2_RECEIPT_StateSendStartRequest, GURU2_RECEIPT_StateWaitStartReady, GURU2_RECEIPT_StateShowStartMessage, GURU2_RECEIPT_StateWaitEndWipe, GURU2_RECEIPT_StateOpenQuitMenu, GURU2_RECEIPT_StateQuitMenu, GURU2_RECEIPT_StateShowQuitMessage, GURU2_RECEIPT_StateQuitDelay, GURU2_RECEIPT_StateSetSyncToken, GURU2_RECEIPT_StateCheckSyncToken, GURU2_RECEIPT_StateWaitMessageToError, GURU2_RECEIPT_StateWaitMessageToStart, GURU2_RECEIPT_StateShowTimeoutMessage, GURU2_RECEIPT_StateArmTimeout, GURU2_RECEIPT_StateTimeout, GURU2_RECEIPT_StateEndSession, GURU2_RECEIPT_SetStateFromParent, GURU2_RECEIPT_SetStateFromChild, GURU2_RECEIPT_CountMembers, GURU2_RECEIPT_PrintMemberList, GURU2_RECEIPT_Noop2, GURU2_RECEIPT_GetMemberCount, GURU2_RECEIPT_GetJoinedBits, GURU2_RECEIPT_UpdateMemberSlots, GURU2_RECEIPT_PrintMessage, GURU2_RECEIPT_IsMessageDone, GURU2_RECEIPT_ClearMessageFrame, GURU2_RECEIPT_UpdatePlayerActors, GURU2_RECEIPT_LoadCharBuffer, GURU2_RECEIPT_FreeCharBuffer, GURU2_RECEIPT_SetPlayerIcon, GURU2_RECEIPT_UpdateMemberChange, GURU2_RECEIPT_GetKeyTrg
 * address:  0x021DCE10
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from guru2_main.c by tools/splitfile.py.
 *
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_SetStateFromParent 0x021DE08C thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   GURU2_RECEIPT_SetStateFromChild 0x021DE17C thumb ov137
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GURU2_RECEIPT_InitBg 0x021DD1E0 thumb ov137
 *   GURU2_RECEIPT_LoadGraphics 0x021DD3D8 thumb ov137
 *   GURU2_RECEIPT_InitStrings 0x021DD2E0 thumb ov137
 *   GURU2_RECEIPT_InitActors 0x021DD4A8 thumb ov137
 *   GURU2_RECEIPT_CreatePlayerActors 0x021DD5AC thumb ov137
 *   GURU2_RECEIPT_CreateWindows 0x021DD638 thumb ov137
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   UNION_APP_SetCallbacks 0x021840FC thumb ov022
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   GURU2_RECEIPT_PrintMemberList 0x021DE248 thumb ov137
 *   GURU2_RECEIPT_UpdatePlayerActors 0x021DE5D0 thumb ov137
 *   GURU2_RECEIPT_UpdateMemberChange 0x021DE738 thumb ov137
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   gGuru2LobbyStateTable 0x021E1C20 data a4
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   GURU2_RECEIPT_FreeActors 0x021DD570 thumb ov137
 *   GURU2_RECEIPT_DeleteWindows 0x021DD760 thumb ov137
 *   GURU2_RECEIPT_ExitBg 0x021DD3B0 thumb ov137
 *   MSGDATA_Delete 0x02045C04 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 *   GURU2_RECEIPT_GetJoinedBits 0x021DE37C thumb ov137
 *   GURU2_RECEIPT_FreeStrings 0x021DD380 thumb ov137
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   gGuru2MemberPaletteStepThreshold 0x021E1AEE data a1
 *   gGuru2MemberPaletteStepIndex 0x021E1AEF data a1
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   gGuru2LobbyVramBanks 0x021E1B40 data a4
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   gGuru2LobbyDispConfig 0x021E1B70 data a4
 *   gGuru2LobbyBg0Template 0x021E1BE0 data a4
 *   gGuru2LobbyBg1Template 0x021E1B80 data a4
 *   gGuru2LobbyBg2Template 0x021E1BA0 data a4
 *   gGuru2LobbyBg3Template 0x021E1BC0 data a4
 *   gGuru2LobbyBg4Template 0x021E1C00 data a4
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_Close 0x02184114 thumb ov022
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   gGuru2YesNoMenuTemplate 0x021E1AE8 data a2
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   PRINTSYS_PrintStreamStop 0x0201CE0C thumb
 *   MYSTATUS_GetIdLow16 0x02008534 thumb
 *   MYSTATUS_NameToStrbuf 0x02008500 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   MYSTATUS_GetTrainerView 0x02008554 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   gGuru2MemberPaletteIndex 0x021E1AF8 data a1
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   gGuru2LobbyActorResourceIds 0x021E1B20 data a4
 *   gGuru2LobbyCellIds 0x021E1B30 data a4
 *   gGuru2LobbyCellAnimIds 0x021E1B38 data a4
 *   gGuru2MemberPositionTable 0x021E1B08 data a2
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   GURU2_COMM_RegisterCommands 0x021DCB78 thumb ov137
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm  arm9
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm  arm9
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm  arm9
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm  arm9
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm  arm9
 *   ARC_UTIL_UploadBgCharFromArchive 0x02049624  arm
 */
#include "ov137_types.h"
#include "guru2_shared_types.h"
#include "guru2_comm_shared_types.h"
#include "guru2_receipt_shared_types.h"
#include "guru2_types.h"

struct Tcbl;

struct S02031140;


struct Guru2ReceiptState { u32 enable; u32 index; int counter; u32 spare; u8 *object; };

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"


#include "../arm9/gfl_heap_wrap.h"
struct GFLNetHandle;

#include "../arm9/net_handle.h"

#include "../arm9/net_system.h"
struct UnionAppWork;

#include "../ov022/union_app.h"



#include "../arm9/gfl_heap.h"

#include "../arm9/arc_tool.h"

#include "../arm9/bg_sys.h"
struct WordSet;

#include "../arm9/gf_font.h"

#include "../arm9/msgdata.h"


extern void GURU2_RECEIPT_SetVramBanks(void);
extern void GURU2_RECEIPT_InitBg(void);

#include "../arm9/wipe.h"

void GURU2_RECEIPT_LoadGraphics(struct Guru2Lobby *p,void *arc);
struct TcbTask;

#include "../arm9/gfl_use.h"
struct TcblSystem;

#include "../arm9/tcbl.h"
struct PrintQueue;

#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_hdr
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
void PRINTSYS_PrintColor(struct Bmp *bmp, short x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
#endif

void GURU2_RECEIPT_InitStrings(struct Guru2Lobby *p,void *q);

#include "../arm9/net.h"



#include "../arm9/net_err.h"






void GURU2_RECEIPT_InitActors();

void GURU2_RECEIPT_CreatePlayerActors();

void GURU2_RECEIPT_CreateWindows();

#include "../arm9/clact.h"

int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,struct Guru2Lobby *p);

void GURU2_RECEIPT_UpdatePlayerActors(struct Guru2Lobby *p);

int GURU2_RECEIPT_UpdateMemberChange(struct Guru2Lobby *obj, int unused);

#include "../arm9/net_command.h"





void GURU2_RECEIPT_FreeActors(struct Guru2Lobby *p);

void GURU2_RECEIPT_DeleteWindows(struct Guru2Lobby *p);

void GURU2_RECEIPT_ExitBg(void);


#include "../arm9/wordset.h"

struct TcbTask;

#include "../arm9/tcb_list.h"

int GURU2_RECEIPT_GetMemberCount(struct Guru2Lobby *p);

unsigned GURU2_RECEIPT_GetJoinedBits(struct Guru2Lobby *p);

void GURU2_RECEIPT_FreeStrings(struct Guru2Lobby *p);


#include "../arm9/gx_load2d.h"






#include "guru2_comm.h"
#include "../sdk_ioreg.h"
struct Guru2Comm;


int GURU2_RECEIPT_ProcInit(void *a,u32 *state,struct Guru2Session *ctx);

extern void *GURU2_RECEIPT_GetUnionApp(struct Guru2Lobby *p);

void GURU2_RECEIPT_SendMemberCount(int memberCount, struct UnionAppEntry *unused, void *pArg);

void GURU2_RECEIPT_UnionAppNoop(int netId, struct UnionAppEntry *entry, void *arg);

int GURU2_RECEIPT_ProcMain(int a,int b,int c,struct Guru2Lobby *p);

int GURU2_RECEIPT_ProcExit(void *a,int b,void *c,struct Guru2Lobby *p);

void GURU2_RECEIPT_AnimatePalette(void *unused, struct Guru2Lobby *p);

void GURU2_RECEIPT_VBlank(struct TcbTask *task, void *work);

void GURU2_RECEIPT_UpdateQueues(struct Guru2Lobby *p);

void GURU2_RECEIPT_SetVramBanks(void);

extern const u8 gGuru2MemberPaletteStepThreshold[];

extern const u8 gGuru2MemberPaletteStepIndex[];

extern const u32 gGuru2LobbyVramBanks[];

/*
 * nested functions. Verified wrapper is MATCH (16 bytes; 020434B4 unresolved).
 * extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 * void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * Blocker symbols: BG_SYS_ClearMainBgPlanes 0x0204349C arm; BG_SYS_ClearMainObjPlane 0x020434B4 arm.
 * Verified wrapper is EXACT (16 bytes), fixed compiler/flags ARM.
 * extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 * void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * Blocker symbols: BG_SYS_ClearSubBgPlanes 0x02043558 arm; BG_SYS_ClearSubObjPlane 0x02043570 arm.
 * volatile: hardware DISPCNT reads at 021DCE34 and 021DCE3E.
 * lever: PROCSYS_AllocProcWork leaves its allocator result in r0, used by the caller.
 * BG_SYS_ClearMainPlanes 0x020434CC arm
 * BG_SYS_ClearSubPlanes 0x02043588 arm
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * ARC_TOOL_CreateHandle 0x020490F4 arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * BG_SYS_Create 0x0203F8F4 arm
 * MSGDATA_CreateFromArchive 0x02045B38 arm
 * TCBL_Create 0x0203101C arm
 * GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * WORDSET_CreateDefault 0x0201EC64 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * WIPE_SYS_Start 0x0202208C thumb
 * GFL_USE_AddMainTask 0x020056A0 thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * GURU2_RECEIPT_SetVramBanks 0x021DD1D0 thumb ov137
 * GURU2_RECEIPT_InitBg 0x021DD1E0 thumb ov137
 * GURU2_RECEIPT_LoadGraphics 0x021DD3D8 thumb ov137
 * GURU2_RECEIPT_VBlank 0x021DD1A4 thumb ov137
 * GURU2_RECEIPT_InitStrings 0x021DD2E0 thumb ov137
 * GURU2_RECEIPT_InitActors 0x021DD4A8 thumb ov137
 * GURU2_RECEIPT_CreatePlayerActors 0x021DD5AC thumb ov137
 * GURU2_RECEIPT_CreateWindows 0x021DD638 thumb ov137
 * GURU2_COMM_RegisterCommands 0x021DCB78 thumb ov137
 */
int GURU2_RECEIPT_ProcInit(void *proc,u32 *state,struct Guru2Session *ctx)
{
    struct Guru2Lobby *p;
    void *arc;
    switch(*state) {
    case 0:
        BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
        *(volatile u32 *)REG_DISPCNT_ADDR&=0xffffe0ff;
        *(volatile u32 *)REG_DB_DISPCNT_ADDR&=0xffffe0ff;
        GFL_HEAP_CreateChildHeap(1,114,0x80000);
        arc=ARC_TOOL_CreateHandle(184,114);
        p=PROCSYS_AllocProcWork(proc,sizeof(struct Guru2Lobby),114);
        MI_CpuFill8(p,0,sizeof(struct Guru2Lobby));
        ctx->lobbyWork=p; p->session=ctx;
        p->comm=ctx->comm;
        BG_SYS_Create(114);
        p->wordSet=WORDSET_CreateDefault(114);
        p->msgData=MSGDATA_CreateFromArchive(0,2,42,114);
        p->font=GF_FONT_Create(23,0,0,0,114);
        GURU2_RECEIPT_SetVramBanks(); GURU2_RECEIPT_InitBg();
        WIPE_SYS_Start(0,1,1,0,16,1,114);
        GURU2_RECEIPT_LoadGraphics(p,arc);
        p->vblankTask=GFL_USE_AddMainTask(GURU2_RECEIPT_VBlank,(void *)p,1);
        p->tcbl=TCBL_Create(114,114,32,32);
        p->printQue=PRINTSYS_QUE_Create((unsigned int)114);
        GURU2_RECEIPT_InitStrings(p,arc); GURU2_RECEIPT_InitActors(p,arc); GURU2_RECEIPT_CreatePlayerActors(p); GURU2_RECEIPT_CreateWindows(p);
        GURU2_COMM_RegisterCommands(ctx->comm);
        GFL_NET_RefreshWmIconAtTopRight(1,114); ARC_TOOL_DeleteHandle(arc);
        (*state)++;
        break;
    case 1:
        *state=0;
        return 1;
    }
    return 0;
}

void *GURU2_RECEIPT_GetUnionApp(struct Guru2Lobby *p) {return ((struct Guru2Session *)p->session)->param->unionApp;}

void GURU2_RECEIPT_SendMemberCount(int memberCount, struct UnionAppEntry *unused, void *pArg) {
    struct Guru2Lobby *p = pArg;u8 v;if(GFL_NET_SYSTEM_GetCurrentAid()==0) {v=memberCount;GURU2_COMM_Send(p->comm,10240,&v,1);}}

/*
 * extent: two zero alignment bytes before GURU2_RECEIPT_ProcMain.
 */
void GURU2_RECEIPT_UnionAppNoop(int netId, struct UnionAppEntry *entry, void *arg) {}

extern int (*const gGuru2LobbyStateTable[])(struct Guru2Lobby *,u32);

/*
 * lever: Table callbacks receive the switch value as their second argument.
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 * GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 * UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 * UNION_APP_Open 0x02184134 thumb ov022
 * UNION_APP_SetCallbacks 0x021840FC thumb ov022
 * UNION_APP_RequestReset 0x02184174 thumb ov022
 * UNION_APP_IsResetDone 0x0218417C thumb ov022
 * GURU2_RECEIPT_SendMemberCount 0x021DCF58 thumb ov137
 * GURU2_RECEIPT_UnionAppNoop 0x021DCF7C thumb ov137
 * GURU2_RECEIPT_PrintMemberList 0x021DE248 thumb ov137
 * GURU2_RECEIPT_UpdatePlayerActors 0x021DE5D0 thumb ov137
 * GURU2_RECEIPT_UpdateMemberChange 0x021DE738 thumb ov137
 * GURU2_RECEIPT_UpdateQueues 0x021DD1B4 thumb ov137
 * GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 * CLACT_DrawSystem 0x0204A600 arm
 * WIPE_SYS_EndCheck 0x020221A4 thumb
 * GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 * gGuru2LobbyStateTable 0x021E1C20 data a4
 */
int GURU2_RECEIPT_ProcMain(int proc,int seq,int parentWork,struct Guru2Lobby *p)
{
    int v;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0 && ((struct Guru2Comm *)p->comm)->joinedMask!=0)
        ((struct Guru2Comm *)p->comm)->joinedMask&=UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));
    switch(*(unsigned int *)&p->state) {
    case 0:
        if(WIPE_SYS_EndCheck()) {
            p->state=1;
            UNION_APP_Open((UnionAppWork *)GURU2_RECEIPT_GetUnionApp(p));
            UNION_APP_SetCallbacks((UnionAppWork *)GURU2_RECEIPT_GetUnionApp(p),GURU2_RECEIPT_SendMemberCount,GURU2_RECEIPT_UnionAppNoop,(void *)p);
        }
        break;
    case 1:
        if(gGuru2LobbyStateTable[p->stateIndex]) p->state=gGuru2LobbyStateTable[p->stateIndex](p,*(unsigned int *)&p->state);
        if(((struct Guru2Comm *)p->comm)->sessionClosed==0) GURU2_RECEIPT_PrintMemberList(p->memberWindow,0,1152,p);
        GURU2_RECEIPT_UpdatePlayerActors(p);
        if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
            v=GURU2_RECEIPT_UpdateMemberChange(p,1);
            if(p->state==1) p->state=v;
        }
        break;
    case 2:
        if(gGuru2LobbyStateTable[p->stateIndex]) p->state=gGuru2LobbyStateTable[p->stateIndex](p,*(unsigned int *)&p->state);
        break;
    case 3:
        if(WIPE_SYS_EndCheck()) {
            if(p->startConfirmed) return 1;
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(GURU2_RECEIPT_GetUnionApp(p));
            p->state=4;
        }
        break;
    case 4:
        if(UNION_APP_IsResetDone(GURU2_RECEIPT_GetUnionApp(p))) return 1;
        break;
    }
    if(WIPE_SYS_EndCheck() && GFL_NET_ERR_GetErrorLevel()) return 1;
    CLACT_DrawSystem(); GURU2_RECEIPT_UpdateQueues(p);
    return 0;
}

/*
 * volatile: 021DD10A reads and 021DD110 writes hardware register 0x04000304
 * TCBL_DeleteAllTasks 0x0203115C arm
 * TCBL_Destroy 0x02031140 arm
 * GURU2_RECEIPT_FreeActors 0x021DD570 thumb ov137
 * GURU2_RECEIPT_DeleteWindows 0x021DD760 thumb ov137
 * GURU2_RECEIPT_ExitBg 0x021DD3B0 thumb ov137
 * MSGDATA_Delete 0x02045C04 arm
 * TCB_DeleteTask 0x02030EAC arm
 * GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 * GURU2_RECEIPT_GetJoinedBits 0x021DE37C thumb ov137
 * GURU2_RECEIPT_FreeStrings 0x021DD380 thumb ov137
 * PROCSYS_FreeProcWork 0x020315D4 arm
 * GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
int GURU2_RECEIPT_ProcExit(void *proc,int seq,void *parentWork,struct Guru2Lobby *p)
{
    TCBL_DeleteAllTasks(p->tcbl); TCBL_Destroy(p->tcbl);
    PRINTSYS_QUE_Clear(p->printQue); PRINTSYS_QUE_Delete(p->printQue);
    GURU2_RECEIPT_FreeActors(p); GURU2_RECEIPT_DeleteWindows(p); GURU2_RECEIPT_ExitBg();
    MSGDATA_Delete(p->msgData); WORDSET_Delete(p->wordSet); GF_FONT_Delete(p->font);
    *(volatile u16 *)REG_POWCNT1_ADDR |= 0x8000;
    TCB_DeleteTask(p->vblankTask);
    ((struct Guru2Session *)p->session)->startConfirmed=p->startConfirmed;
    ((struct Guru2Session *)p->session)->playerCount=GURU2_RECEIPT_GetMemberCount(p);
    ((struct Guru2Session *)p->session)->memberMask=GURU2_RECEIPT_GetJoinedBits(p);
    GURU2_RECEIPT_FreeStrings(p); PROCSYS_FreeProcWork(proc); GFL_HEAP_DeleteChecked(114);
    return 1;
}

#pragma opt_propagation off

void GURU2_RECEIPT_AnimatePalette(void *unused, struct Guru2Lobby *p)
{
    struct Guru2ReceiptState *v = (struct Guru2ReceiptState *)&p->paletteAnimEnabled;
    int c;
    u32 i;
    if (v->enable) {
        c = v->counter;
        i = v->index;
        if (c > gGuru2MemberPaletteStepThreshold[i * 2]) {
            v->index = i + 1;
            v->counter = 0;
            if (gGuru2MemberPaletteStepIndex[v->index * 2] == 255) v->index = 0;
#ifdef __MWERKS__
            GX_LoadOBJPltt(*(u8 **)(v->object + 12) + (gGuru2MemberPaletteStepIndex[v->index * 2] << 5), 0, 32);
#else
            GX_LoadOBJPltt((u8 *)((struct NNSG2dPaletteData *)p->paletteData)->pRawData + (gGuru2MemberPaletteStepIndex[v->index * 2] << 5), 0, 32);
#endif
            return;
        }
        p->paletteAnimCounter += 1;
    }
}

#pragma opt_propagation reset

/*
 * Addresses are Black-image addresses.
 */
void GURU2_RECEIPT_VBlank(struct TcbTask *task, void *work)
{
    GURU2_RECEIPT_AnimatePalette(task, work);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}

void GURU2_RECEIPT_UpdateQueues(struct Guru2Lobby *p)
{
    if (p->printQue)
        PRINTSYS_QUE_Main(p->printQue);
    TCBL_Main(p->tcbl);
}

void GURU2_RECEIPT_SetVramBanks(void) {BG_SYS_SetVramBanks((const struct DispVram *)gGuru2LobbyVramBanks);}

struct StrObj;

struct BmpMenu;

struct Rec3;

struct Sub0204A9D0;

#include "../arm9/bmp_menu_types.h"

#include "../types.h"

typedef union { struct { u32 a,b; } words; u64 wide; } WordPair;

typedef struct { char pad[0x4824]; WordPair current,previous; } FrameRecord;




struct Strbuf;

#include "../arm9/strbuf.h"


#include "../arm9/arc_util.h"










#include "../arm9/bmp_menuwork.h"

struct GameData;
struct MyStatus;

#include "../arm9/game_data.h"

#ifdef __MWERKS__
#define MYSTATUS_GetSex MYSTATUS_GetSex_hdr
#endif
#include "../arm9/mystatus.h"
#ifdef __MWERKS__
#undef MYSTATUS_GetSex
u8 MYSTATUS_GetSex(struct MyStatus *mystatus);
#endif
struct DispVramCfg;
struct SysInit;











struct ClactActor;






#include "../arm9/bmp_win.h"
struct BmpWin;

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"







#include "../arm9/bmp_menu.h"








struct UnionAppEntry;




struct TextPrinter;












#include "../arm9/key.h"









void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font);

int GURU2_RECEIPT_StateInit(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateIdleStart(struct Guru2Lobby *p,int a);

void GURU2_RECEIPT_HandleKeys(struct Guru2Lobby *p);

void GURU2_RECEIPT_Noop(struct Guru2Lobby *p);

int GURU2_RECEIPT_StateGoToMessage(struct Guru2Lobby *p,int state);

void GURU2_RECEIPT_SetPendingState(struct Guru2Lobby *p, int v);

int GURU2_RECEIPT_StateWaitMessage(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateReopenRecruit(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateOpenStartMenu(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateStartMenu(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateResetWait(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateWaitAnswers(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateAnswersDone(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateOpenCancelMenu(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateCancelMenu(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateSendStartRequest(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateWaitStartReady(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateShowStartMessage(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateWaitEndWipe(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateOpenQuitMenu(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateQuitMenu(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateShowQuitMessage(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateQuitDelay(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateSetSyncToken(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateCheckSyncToken(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateWaitMessageToError(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateWaitMessageToStart(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateShowTimeoutMessage(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateArmTimeout(struct Guru2Lobby *p,int state);

int GURU2_RECEIPT_StateTimeout(struct Guru2Lobby *p, int state);

int GURU2_RECEIPT_StateEndSession(struct Guru2Lobby *p);

void GURU2_RECEIPT_SetStateFromParent(struct Guru2Lobby *p,int state,int player);

void GURU2_RECEIPT_SetStateFromChild(struct Guru2Lobby *p, int command, int player);

int GURU2_RECEIPT_CountMembers(struct Guru2Lobby *p);

void GURU2_RECEIPT_Noop2(struct Guru2Lobby *unused);

int GURU2_RECEIPT_UpdateMemberSlots(struct Guru2Lobby *p);

void GURU2_RECEIPT_PrintMessage(struct Guru2Lobby *p, int message, int unused);

int GURU2_RECEIPT_IsMessageDone(struct Guru2Lobby *p);

void GURU2_RECEIPT_ClearMessageFrame(struct Guru2Lobby *p);

void GURU2_RECEIPT_LoadCharBuffer(struct Guru2Lobby *p, void *unused);

void GURU2_RECEIPT_FreeCharBuffer(struct Guru2Lobby *p);

void GURU2_RECEIPT_SetPlayerIcon(struct Guru2Lobby *p, struct NNSG2dPaletteData *paletteData, int member, int outfit, int unused);

u32 GURU2_RECEIPT_GetKeyTrg(void);

extern const struct DispConfig gGuru2LobbyDispConfig;

extern const struct BgTemplate gGuru2LobbyBg0Template,gGuru2LobbyBg1Template,gGuru2LobbyBg2Template,gGuru2LobbyBg3Template,gGuru2LobbyBg4Template;

extern const struct Cfg gClActorInitParam;

extern const u32 gGuru2LobbyVramBanks[],gGuru2LobbyActorResourceIds[],gGuru2LobbyCellIds[],gGuru2LobbyCellAnimIds[];

extern const u16 gGuru2MemberPositionTable[];

extern const WinDat gGuru2YesNoMenuTemplate;

extern const u8 gGuru2MemberPaletteIndex[];

/*
 * BG_SYS_SetGraphicsMode 0x0203FC28 arm
 * BG_SYS_InitBgLayer 0x0203FCA0 arm
 * BG_SYS_ClearSlot 0x020414EC arm
 * BG_SYS_InitRun 0x02040B94 arm
 * gGuru2LobbyDispConfig 0x021E1B70 data a4
 * gGuru2LobbyBg0Template 0x021E1BE0 data a4
 * gGuru2LobbyBg1Template 0x021E1B80 data a4
 * gGuru2LobbyBg2Template 0x021E1BA0 data a4
 * gGuru2LobbyBg3Template 0x021E1BC0 data a4
 * gGuru2LobbyBg4Template 0x021E1C00 data a4
 */
void GURU2_RECEIPT_InitBg(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f;
    d=gGuru2LobbyDispConfig;
    BG_SYS_SetGraphicsMode((struct DispConfig *)&d);
    a=gGuru2LobbyBg0Template;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)&a, 0); BG_SYS_ClearSlot(4);
    b=gGuru2LobbyBg1Template;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)&b, 0); BG_SYS_ClearSlot(5);
    c=gGuru2LobbyBg2Template;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)&c, 0); BG_SYS_InitRun(4,32,0,114);
    e=gGuru2LobbyBg3Template;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)&e, 0); BG_SYS_ClearSlot(0);
    f=gGuru2LobbyBg4Template;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)&f, 0); BG_SYS_InitRun(0,32,0,114);
}

/*
 * STRBUF_Create 0x020457B0 arm
 * MSGDATA_ReadString 0x02045CAC arm
 * ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 * GURU2_RECEIPT_LoadCharBuffer 0x021DE6C0 thumb ov137
 */
void GURU2_RECEIPT_InitStrings(struct Guru2Lobby *p,void *arc)
{
    int i;
    void *titleBuf;
    for(i=0;i<5;i++) {
        p->memberName[i]=STRBUF_Create(8,114);
        p->member[i].current=0; p->member[i].previous=0;
        p->actorState[i]=0;
    }
    p->messageBuf=STRBUF_Create(180,114);
    titleBuf=STRBUF_Create(40,114); p->titleBuf=titleBuf;
    p->stateIndex=0;
    MSGDATA_ReadString(p->msgData,17,titleBuf);
    GURU2_RECEIPT_LoadCharBuffer(p,arc);
    p->paletteAnimEnabled=0; p->paletteAnimCounter=0; p->paletteAnimIndex=0;
    p->paletteBlock=ARC_UTIL_LoadPaletteBlockFromHandle(arc,2,&p->paletteData,114);
    p->previousMemberCount=0; p->yesNoMenu=0;
    ((struct Guru2Comm *)p->comm)->expectedMemberCount=2;
}

void GURU2_RECEIPT_FreeStrings(struct Guru2Lobby *p) {int i;GURU2_RECEIPT_FreeCharBuffer(p);GFL_HEAP_Free(p->paletteBlock);for(i=0;i<5;i++)STRBUF_Delete(p->memberName[i]);STRBUF_Delete(p->titleBuf);STRBUF_Delete(p->messageBuf);}

void GURU2_RECEIPT_ExitBg(void) {BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BG_SYS_Delete();}

/*
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 ARC_UTIL_LoadMember(void *,void *,u32,u16);
 * extern u32 ARC_UTIL_UploadBgChar(u32,void *,void *,u32,u32);
 * u32 ARC_UTIL_UploadBgCharFromArchive(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=ARC_UTIL_LoadMember(a,b,f,g); return ARC_UTIL_UploadBgChar(r,c,d,e,f);
 * }
 * Blocker symbols: ARC_UTIL_LoadMember 0x0204A1BC arm; ARC_UTIL_UploadBgChar 0x0204968C arm.
 * ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 * ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 * ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 * ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 * ARC_UTIL_UploadBgCharFromArchive 0x02049624 arm
 * ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 * BG_SYS_SetPlaneVisible 0x02040588 arm
 * BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 */
void GURU2_RECEIPT_LoadGraphics(struct Guru2Lobby *p,void *arc)
{
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,1,0,0,512,114);
    ARC_UTIL_UploadBgCharFromHandle(arc,7,1,0,8192,0,114);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,13,1,0,1536,0,114);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,416,32,114);
    ARC_UTIL_UploadPaletteFromArchiveWhole(30,13,4,0,352,114);
    ARC_UTIL_UploadBgCharFromArchive(30,14,6,0,0,0,114);
    ARC_UTIL_UploadBgPaletteFromArchive(30,3,6,0,0,0,114);
    BMP_MENUWORK_LoadCharAndPltt(0,1,10,0,114);
    BMP_MENUWORK_LoadCharAndPltt(0,31,11,0,114);
    BG_SYS_SetPlaneVisible(0,1);
    BG_SYS_SetPlaneVisible(1,1);
    BG_SYS_SetPlaneVisible(6,1);
}

/*
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * GAME_DATA_GetMyStatus 0x02012944 thumb
 * MYSTATUS_GetSex 0x02008550 thumb
 * ARC_TOOL_CreateHandle 0x020490F4 arm
 * CLACT_InitSystem 0x0204A48C arm
 * CLACT_CreateUnit 0x0204B100 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * gClActorInitParam 0x020A1448 data a4
 * gGuru2LobbyVramBanks 0x021E1B40 data a4
 * gGuru2LobbyActorResourceIds 0x021E1B20 data a4
 * gGuru2LobbyCellIds 0x021E1B30 data a4
 * gGuru2LobbyCellAnimIds 0x021E1B38 data a4
 */
void GURU2_RECEIPT_InitActors(struct Guru2Lobby *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(p->session->param->gameData));
    arc=ARC_TOOL_CreateHandle(31,114);
    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&gClActorInitParam)),(const struct DispVramCfg *)gGuru2LobbyVramBanks,114);
    p->clactUnit=CLACT_CreateUnit(30,1,114);
    i=0;
    table=gGuru2LobbyActorResourceIds+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        p->charId[i]=CLACT_RegisterCharacter(arc,a,0,0,114);
        p->paletteId[i]=CLACT_RegisterPaletteEx(arc,b,0,(u16)(i*32),0,1,114);
    }
    p->cellAnimId=CLACT_RegisterCellAnim(arc,gGuru2LobbyCellIds[v],gGuru2LobbyCellAnimIds[v],114);
    ARC_TOOL_DeleteHandle(arc);
    (p->arcHandle)=ARC_TOOL_CreateHandle(32,114);
}

void GURU2_RECEIPT_FreeActors(struct Guru2Lobby *p) {int i;ARC_TOOL_DeleteHandle(p->arcHandle);for(i=0;i<5;i++) {
#ifdef BUGFIX
        /* The DS releases the character with the palette id and the palette with the character id. */
        CLACT_ReleaseCharacter(p->charId[i]);CLACT_ReleasePalette(p->paletteId[i]);
#else
        CLACT_ReleaseCharacter(p->paletteId[i]);CLACT_ReleasePalette(p->charId[i]);
#endif
    }CLACT_ReleaseCellAnim(p->cellAnimId);CLACT_DeleteUnit(p->clactUnit);CLACT_ExitSystem();}

/*
 * CLACT_CreateActor 0x0204B294 arm
 * CLACT_SetActorAutoAnim 0x0204B92C arm
 * CLACT_SetActorAnimSeq 0x0204B878 arm
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * BG_SYS_SetMainPlaneVisible 0x020434DC arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * gGuru2MemberPositionTable 0x021E1B08 data a2
 */
void GURU2_RECEIPT_CreatePlayerActors(struct Guru2Lobby *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=gGuru2MemberPositionTable[i*2+2]; s.b=gGuru2MemberPositionTable[i*2+3];
        p->memberActor[i]=CLACT_CreateActor((struct Unit *)p->clactUnit,p->charId[i],p->paletteId[i],p->cellAnimId,(const struct ActorInitParam *)&s,0,114);
        CLACT_SetActorAutoAnim((struct ClactActor *)(p->memberActor[i]),1);
        CLACT_SetActorAnimSeq(p->memberActor[i],0);
        CLACT_SetActorDrawEnable(p->memberActor[i],0);
    }
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,0);
}

/*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 */
void GURU2_RECEIPT_CreateWindows(struct Guru2Lobby *p) {
    BMP_WIN_Init(0x72);
    p->cornerWindow=BMP_WIN_Create((unsigned int)5,(unsigned int)26,(unsigned int)20,6,2,13,1);
    BMP_Clear(BMP_WIN_GetBmp(p->cornerWindow),0);
    p->messageWindow=BMP_WIN_Create((unsigned int)0,(unsigned int)2,(unsigned int)19,27,4,13,1);
    BMP_Clear(BMP_WIN_GetBmp(p->messageWindow),15);
    p->titleWindow=BMP_WIN_Create((unsigned int)0,(unsigned int)3,(unsigned int)1,26,2,15,1);
    GURU2_RECEIPT_PrintTitle(p->titleWindow,p->titleBuf,p->font);
    p->memberWindow=BMP_WIN_Create((unsigned int)0,(unsigned int)2,(unsigned int)6,16,11,15,1);
    BMP_Clear(BMP_WIN_GetBmp(p->memberWindow),0);
    GURU2_RECEIPT_PrintMemberList(p->memberWindow, 0, 0x480, p);
    p->activeWindow=p->titleWindow;
    p->printPending=0;
}

void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font) {
    int width;
    width = PRINTSYS_MeasureWidestLine(text, font, 0);
    BMP_Clear(BMP_WIN_GetBmp(p), 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p), (208-width)/2, 1, text, font, 0x480);
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    BG_SYS_PushTile((u32)BMP_WIN_GetBgLayer(p));
}

void GURU2_RECEIPT_DeleteWindows(struct Guru2Lobby *p) {if(p->yesNoMenu!=0)BMP_MENU_DeleteYesNo(p->yesNoMenu);BMP_WIN_Delete(p->memberWindow);BMP_WIN_Delete(p->titleWindow);BMP_WIN_Delete(p->cornerWindow);BMP_WIN_Delete(p->messageWindow);BMP_WIN_Exit();}

int GURU2_RECEIPT_StateInit(struct Guru2Lobby *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) >= 2)
            GURU2_RECEIPT_PrintMessage(p, 2, zero);
    } else {
        GFL_NET_SetAutoExit(1);
        GURU2_RECEIPT_PrintMessage(p, 8, 0);
    }
    GURU2_RECEIPT_SetPendingState(p, 3);
    return state;
}

/*
 * Lever: nested explicit empty then/else-call plus outer else-call preserves the b-to-next at +0x1c; goto spelling DIFF12/38B.
 * abi: 021DD802 visibly reloads p into r0 for 021DE350; retain that argument despite its empty matched body.
 */
int GURU2_RECEIPT_StateIdleStart(struct Guru2Lobby *p,int state) {GURU2_RECEIPT_HandleKeys(p);if(GFL_NET_SYSTEM_GetCurrentAid()==0) {if(GURU2_RECEIPT_CountMembers(p)==1) {} else GURU2_RECEIPT_Noop2(p);}else GURU2_RECEIPT_Noop2(p);return state;}

void GURU2_RECEIPT_HandleKeys(struct Guru2Lobby *p) {
    char *q;
    if (GURU2_RECEIPT_GetKeyTrg()&1) {
        if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
            q=((char *)p->comm);
            if (((struct Guru2Comm *)q)->expectedMemberCount==GURU2_RECEIPT_GetMemberCount(p) && ((struct Guru2Comm *)q)->joinedMask==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp(p))) {
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    GURU2_RECEIPT_PrintMessage(p,3,0);
                    GURU2_RECEIPT_SetPendingState(p,22);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (GURU2_RECEIPT_GetKeyTrg()&2) {
        if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
            if (*(unsigned int *)&((struct Guru2Comm *)p->comm)->unknown_28==0) {
                GURU2_RECEIPT_PrintMessage(p,4,0);
                GURU2_RECEIPT_SetPendingState(p,4);
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        } else {
            q=((char *)p->comm);
            if (((struct Guru2Comm *)q)->expectedMemberCount==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) && ((struct Guru2Comm *)q)->joinedMask==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp(p))) {
                    GURU2_RECEIPT_PrintMessage(p,4,0);
                    GURU2_RECEIPT_SetPendingState(p,4);
                    GFL_USE_PlaySeDefaultVolume(0x551);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else {
        if (p->recruitClosed==0 && GFL_NET_SYSTEM_GetCurrentAid()==0 &&
            ((struct Guru2Comm *)p->comm)->expectedMemberCount==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)))
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
    }
}

void GURU2_RECEIPT_Noop(struct Guru2Lobby *p) {}

/*
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int GURU2_RECEIPT_StateGoToMessage(struct Guru2Lobby *p,int state) {p->stateIndex=2;GURU2_RECEIPT_Noop(p);return state;}

void GURU2_RECEIPT_SetPendingState(struct Guru2Lobby *p, int nextState)
{
    p->stateIndex = 0x1A;
    p->nextStateIndex = nextState;
}

int GURU2_RECEIPT_StateWaitMessage(struct Guru2Lobby *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) p->stateIndex=p->nextStateIndex;GURU2_RECEIPT_Noop(p);return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int GURU2_RECEIPT_StateReopenRecruit(struct Guru2Lobby *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));p->stateIndex=3;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenStartMenu(struct Guru2Lobby *p,int state) {p->yesNoMenu=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);p->stateIndex=5;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateStartMenu(struct Guru2Lobby *p,int state) {
    unsigned count;
    unsigned result;
    u8 msg[4];
    if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
        if (*(unsigned int *)&((struct Guru2Comm *)p->comm)->unknown_28!=0) {
            if (GURU2_RECEIPT_GetKeyTrg()&0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
            GURU2_RECEIPT_Noop(p);
            return state;
        }
    } else {
        if (((struct Guru2Comm *)p->comm)->joinedMask!=0) {
            if (GURU2_RECEIPT_GetKeyTrg()&0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
            GURU2_RECEIPT_Noop(p);
            return state;
        }
    }
    count=GURU2_RECEIPT_GetMemberCount(p);
    if (count!=UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p))) {
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result=BMP_MENU_ProcessYesNo(p->yesNoMenu);
    if (result!=-1) {
        if (result==-2) {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
            p->stateIndex=0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
                GURU2_RECEIPT_SetPendingState(p,11);
                GURU2_RECEIPT_PrintMessage(p,14,0);
            } else {
                MI_CpuFill8(msg,0,4);
                msg[2]=0;
                msg[0]=GFL_NET_SYSTEM_GetCurrentAid();
                if (GURU2_COMM_Send(p->comm,0x2801,msg,4)) {
                    p->answerSent=1;
                    *(unsigned short *)&p->answerWaitFrames=0;
                    p->stateIndex=6;
                } else p->stateIndex=0;
            }
        }
        p->yesNoMenu=0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateResetWait(struct Guru2Lobby *p,int state) {*(unsigned short *)&p->answerWaitFrames=0;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitAnswers(struct Guru2Lobby *p, int state) {
    unsigned char buf[4];
    if (((struct Guru2Comm *)p->comm)->acceptedCount != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) ||
        ((struct Guru2Comm *)p->comm)->acceptedCount != GURU2_RECEIPT_GetMemberCount(p)) {
        p->answerWaitFrames = 0;
        p->stateIndex = 8;
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    ++*(volatile s16 *)&p->answerWaitFrames;
    if (*(volatile s16 *)&p->answerWaitFrames > 30) {
        int zero = 0;
        MI_CpuFill8(buf, 0, 4);
        buf[2] = 1;
        buf[0] = GFL_NET_SYSTEM_GetCurrentAid();
        GURU2_COMM_Send(p->comm, 0x2801, buf, 4);
        p->answerWaitFrames = zero;
        p->stateIndex = 9;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateAnswersDone(struct Guru2Lobby *p,int state) {p->answerSent=0;GURU2_RECEIPT_SetPendingState(p,0);GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenCancelMenu(struct Guru2Lobby *p,int state) {p->yesNoMenu=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);p->stateIndex=23;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateCancelMenu(struct Guru2Lobby *p, int state) {
    char *q = ((char *)p->comm);
    unsigned result;
    if (((struct Guru2Comm *)q)->expectedMemberCount != GURU2_RECEIPT_GetMemberCount(p) || ((struct Guru2Comm *)q)->joinedMask != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(p->yesNoMenu);
    if (result != -1) {
        if (result == -2) {
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
            p->stateIndex = 0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                p->stateIndex = 0x18;
                p->cancelMemberCount = GURU2_RECEIPT_GetMemberCount(p);
            }
        }
        p->yesNoMenu = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

/*
 * prototype: original cmp r0,#1 at 021DDC96 uses GURU2_COMM_Send's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to GFL_NET_SetLoginOption despite its filed no-argument prototype.
 */
int GURU2_RECEIPT_StateSendStartRequest(struct Guru2Lobby *p,int state) {if(p->startRequestBlocked==0) {if(GURU2_COMM_Send(p->comm,0x2804,0,0)==1) {p->stateIndex=27;GFL_NET_SetLoginOption(1);}}return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int GURU2_RECEIPT_StateWaitStartReady(struct Guru2Lobby *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));if(((struct Guru2Comm *)p->comm)->acceptingJoins==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p))) p->stateIndex=27;return state;}

int GURU2_RECEIPT_StateShowStartMessage(struct Guru2Lobby *p,int state) {GURU2_RECEIPT_PrintMessage(p,5,0);GURU2_RECEIPT_SetPendingState(p,10);GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitEndWipe(struct Guru2Lobby *p,int state) {if(++p->delayCounter>60) {WIPE_SYS_Start(0,0,0,0,16,1,114);state=3;}GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenQuitMenu(struct Guru2Lobby *p,int state) {p->yesNoMenu=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);p->stateIndex=12;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateQuitMenu(struct Guru2Lobby *p, int state) {
    char *q = ((char *)p->comm);
    unsigned result;
    if (((struct Guru2Comm *)q)->expectedMemberCount != GURU2_RECEIPT_GetMemberCount(p) || ((struct Guru2Comm *)q)->joinedMask != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x54c);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(p->yesNoMenu);
    if (result != -1) {
        if (result == -2) {
            p->stateIndex = 0;
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
        } else {
            p->stateIndex = 0xd;
            GURU2_COMM_Send(p->comm, 0x2802, 0, 0);
            WORDSET_SetSlotMyStatus(p->wordSet, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p), 0));
        }
        p->yesNoMenu = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateShowQuitMessage(struct Guru2Lobby *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        GURU2_RECEIPT_PrintMessage(p, 5, 0);
    } else {
        WORDSET_SetSlotMyStatus(p->wordSet, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p), 0));
        GURU2_RECEIPT_PrintMessage(p, 0x10, 0);
    }
    GURU2_RECEIPT_SetPendingState(p, 0xe);
    p->delayCounter = 0;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateQuitDelay(struct Guru2Lobby *p,int state) {if(++p->delayCounter>45) p->stateIndex=15;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateSetSyncToken(struct Guru2Lobby *p, int state) {
    GFL_NET_HANDLE_GetCurrentHandle();
    p->syncToken = p->syncKey ^ GURU2_RECEIPT_GetJoinedBits(p);
    GFL_NET_HANDLE_SetUserInfo((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28, (u16)(p->syncToken));
    p->stateIndex = 0x10;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateCheckSyncToken(struct Guru2Lobby *p, int state) {
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28) != 0 ||
        p->syncToken != (GURU2_RECEIPT_GetJoinedBits(p) ^ p->syncKey)) {
        GFL_NET_SetAutoExit(0);
        WIPE_SYS_Start(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateWaitMessageToError(struct Guru2Lobby *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) {GURU2_RECEIPT_PrintMessage(p,7,0);p->stateIndex=18;}GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitMessageToStart(struct Guru2Lobby *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) p->stateIndex=10;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateShowTimeoutMessage(struct Guru2Lobby *p, int state) {
    GURU2_RECEIPT_PrintMessage(p, 15, 1);
    p->stateIndex = 20;
    GFL_NET_SYSTEM_GetCurrentAid();
    p->timeoutMemberCount = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
    p->timeoutFrames = 300;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateArmTimeout(struct Guru2Lobby *p,int state) {if(p->timeoutMemberCount){if(p->timeoutMemberCount!=(u32)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p))) p->timeoutMemberCount=0;}p->stateIndex=21;p->delayCounter=0;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateTimeout(struct Guru2Lobby *p, int state) {
    if (p->timeoutMemberCount != 0) {
        if (p->timeoutMemberCount != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)))
            p->timeoutMemberCount = 0;
    }
    if (--p->timeoutFrames < 0)
        p->timeoutMemberCount = 0;
    if (++p->delayCounter > 60 && p->timeoutMemberCount == 0) {
        p->stateIndex = 0;
        GFL_NET_SYSTEM_GetCurrentAid();
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateEndSession(struct Guru2Lobby *p) {WIPE_SYS_Start(0,0,0,0,16,1,114);p->startConfirmed=1;GURU2_RECEIPT_Noop(p);return 3;}

void GURU2_RECEIPT_SetStateFromParent(struct Guru2Lobby *p,int state,int player) {
    switch(state) {
    case 2:
        GURU2_RECEIPT_ClearMessageFrame(p);
        break;
    case 13:
        if (p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu=0;
        }
        break;
    case 25:
        GURU2_RECEIPT_PrintMessage(p,12,0);
        if (p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu=0;
        }
        break;
    case 19:
        if (p->answerSent==1) return;
        WORDSET_SetSlotMyStatus(p->wordSet,0,UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),player));
        if (player==GFL_NET_SYSTEM_GetCurrentAid()) return;
        if (p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu=0;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid()==0)
            ((struct Guru2Comm *)p->comm)->joinedMask&=player^0xffff;
        break;
    case 27:
        if (!GURU2_RECEIPT_IsMessageDone(p)) PRINTSYS_PrintStreamStop(p->printStream);
        if (p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    p->stateIndex=state;
}

void GURU2_RECEIPT_SetStateFromChild(struct Guru2Lobby *p, int command, int player) {
    void *target;
    if (p->stateIndex == 3) {
        switch (command) {
        case 1:
            target = UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p), player);
            if (target != 0)
                WORDSET_SetSlotMyStatus(p->wordSet, 0, target);
            p->stateIndex = command;
            ((struct Guru2Comm *)p->comm)->expectedMemberCount = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
            ((struct Guru2Comm *)p->comm)->joinedMask = 0;
            return;
        case 19:
            WORDSET_SetSlotMyStatus(p->wordSet, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p), player));
            if (player != GFL_NET_SYSTEM_GetCurrentAid()) {
                if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
                    ((struct Guru2Comm *)p->comm)->joinedMask &= player ^ 0xffff;
                p->stateIndex = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Guru2Comm *)p->comm)->joinedMask = 0;
            ((struct Guru2Comm *)p->comm)->expectedMemberCount = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
        }
    }
}

int GURU2_RECEIPT_CountMembers(struct Guru2Lobby *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i)) n++;return n;}

/*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 */
int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,struct Guru2Lobby *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    if (!GURU2_RECEIPT_UpdateMemberSlots(p)) return 0;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->member[i].current) {
            int y;
            value=MYSTATUS_GetIdLow16(p->member[i].current);
            text=STRBUF_Create(16,0x72);
            MYSTATUS_NameToStrbuf(p->member[i].current,p->memberName[i]);
            WORDSET_SetSlotNumber(p->wordSet,0,value,5,2,1);
            format=MSGDATA_AllocString(p->msgData,1);
            WORDSET_CopyTaggedText(p->wordSet,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(window),5,18*i+1,p->memberName[i],p->font,ink);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(window),70,y,text,p->font,ink);
            STRBUF_Delete(text);
            do { STRBUF_Delete(format); } while (0);
        }
      } while (0);
    }
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
    return 1;
}

void GURU2_RECEIPT_Noop2(struct Guru2Lobby *unused) {}

int GURU2_RECEIPT_GetMemberCount(struct Guru2Lobby *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i)) n++;return n;}

unsigned GURU2_RECEIPT_GetJoinedBits(struct Guru2Lobby *p) {return UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));}

int GURU2_RECEIPT_UpdateMemberSlots(struct Guru2Lobby *p) {
#ifdef __MWERKS__
    int changed;
    int i;
    u32 *slot;
    FrameRecord *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)((u8 *)p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(uptr)UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i);
        record=(FrameRecord *)((u8 *)p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=MYSTATUS_GetId((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)((u8 *)p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)((u8 *)p+i*4+0x160)=3;
            else *(u32 *)((u8 *)p+i*4+0x160)=1;
        } else {
            record=(FrameRecord *)((u8 *)p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)((u8 *)p+i*4+0x160)=3;
                else *(u32 *)((u8 *)p+i*4+0x160)=1;
            }
        }
    }
    return changed;
#else
    int changed;
    int i;
    struct Guru2LobbyMember *slot;
    struct Guru2LobbyFrame *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=&p->member[i];
        slot->previous=slot->current;
        slot->current=UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i);
        record=&p->frame[i];
        record->previous=record->current;
        if (slot->current) {
            record->current.a=MYSTATUS_GetId(slot->current);
            record->current.b=1;
        } else {
            record->current.a=0;
            record->current.b=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=&p->member[i];
        if (slot->previous!=slot->current) {
            changed=1;
            if (slot->current==0) p->actorState[i]=3;
            else p->actorState[i]=1;
        } else {
            record=&p->frame[i];
            if (record->current.a!=record->previous.a || record->current.b!=record->previous.b) {
                changed=1;
                if (record->current.b==0) p->actorState[i]=3;
                else p->actorState[i]=1;
            }
        }
    }
    return changed;
#endif
}

void GURU2_RECEIPT_PrintMessage(struct Guru2Lobby *p, int message, int unused) {
    void *text;
    void *window;
    text = STRBUF_Create(0xb4, 0x72);
    MSGDATA_ReadString(p->msgData, message, text);
    WORDSET_CopyTaggedText(p->wordSet, p->messageBuf, text);
    STRBUF_Delete(text);
    BMP_Clear(BMP_WIN_GetBmp(p->messageWindow), 0xf);
    BMP_MENUWORK_DrawWindow(p->messageWindow, 0, 1, 0xa);
    if (p->printStream != 0)
        PRINTSYS_PrintStreamDelete(p->printStream);
    p->printStream = PRINTSYS_PrintStream(p->messageWindow, 0, 0, p->messageBuf, p->font, 0, p->tcbl, 0, 0x72, 0xf);
    window = p->messageWindow;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

int GURU2_RECEIPT_IsMessageDone(struct Guru2Lobby *p) {
    int state;
    if (p->printStream == 0) return 1;
    state = PRINTSYS_PrintStreamGetState(p->printStream);
    if (state == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(p->printStream, 0);
    } else if (state == 1) {
        if (KEY_GetTrg() & 1)
            PRINTSYS_PrintStreamReleasePause(p->printStream);
    } else if (state == 2) {
        PRINTSYS_PrintStreamDelete(p->printStream);
        p->printStream = 0;
        return 1;
    }
    return 0;
}

/*
 * Addresses are Black-image addresses.
 */
void GURU2_RECEIPT_ClearMessageFrame(struct Guru2Lobby *p)
{
    BMP_MENUWORK_DrawWindowBorder(p->messageWindow, 0);
}

void GURU2_RECEIPT_UpdatePlayerActors(struct Guru2Lobby *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(p->actorState[i]) {
        case 0: break;
        case 1:
            a=MYSTATUS_GetSex(p->member[i].current);
            b=MYSTATUS_GetTrainerView(p->member[i].current);
            if (i==GFL_NET_SYSTEM_GetCurrentAid()) {
                CLACT_SetActorAnimSeq(p->memberActor[i], 4);
            } else {
                GURU2_RECEIPT_SetPlayerIcon(p,(p->iconPaletteData),i,b,a);
                CLACT_SetActorAnimSeq(p->memberActor[i], 4);
            }
            CLACT_SetActorDrawEnable(p->memberActor[i], 1);
            p->actorState[i]=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==GFL_NET_SYSTEM_GetCurrentAid()) {
                MYSTATUS_GetSex(p->member[i].current);
                CLACT_SetActorAnimSeq(p->memberActor[i], 5);
            } else {
                CLACT_SetActorAnimSeq(p->memberActor[i], 5);
            }
            p->actorState[i]=0;
            break;
        }
    }
    if(flag) GFL_USE_PlaySeDefaultVolume(0x676);
}

void GURU2_RECEIPT_LoadCharBuffer(struct Guru2Lobby *p, void *unused) { p->iconPaletteBlock=ARC_UTIL_LoadPaletteBlockFromArchive(32,0,&p->iconPaletteData,114); }

void GURU2_RECEIPT_FreeCharBuffer(struct Guru2Lobby *p)
{
    GFL_HEAP_Free(p->iconPaletteBlock);
}

void GURU2_RECEIPT_SetPlayerIcon(struct Guru2Lobby *p, struct NNSG2dPaletteData *paletteData, int member, int outfit, int unused)
{
    void *screenData;
    NNSG2dCharacterData *screenDataPtr;
    GX_LoadOBJPltt((u8 *)paletteData->pRawData + gGuru2MemberPaletteIndex[outfit] * 32, member * 32, 32);
    screenData = ARC_UTIL_LoadScreenDataFromArchive(32, outfit + 1, 0, &screenDataPtr, 114);
    /* lever: the character ids follow the palette ids, so index past paletteId */
    CLACT_TransferCharacter(p->paletteId[member + 5], screenDataPtr);
    GFL_HEAP_Free(screenData);
}

/*
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 */
int GURU2_RECEIPT_UpdateMemberChange(struct Guru2Lobby *obj, int unused)
{
    struct Guru2Lobby *p = obj;
    int state;
    state = GURU2_RECEIPT_GetMemberCount(p);
    if (state > *(int *)&((struct Guru2Comm *)p->comm)->expectedMemberCount) {
        if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp(p))) p->recruitClosed = 1;
    } else p->recruitClosed = 0;
    if (state == obj->previousMemberCount) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) > 1 || UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p)) > 1) return 1;
        p->stateIndex = 17;
        if (p->yesNoMenu) {
            BMP_MENU_DeleteYesNo(p->yesNoMenu);
            p->yesNoMenu = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previousMemberCount)
            ((struct Guru2Comm *)p->comm)->expectedMemberCount = (unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
        break;
    case 5: break;
    }
    obj->previousMemberCount = GURU2_RECEIPT_GetMemberCount(p);
    return 1;
}

u32 GURU2_RECEIPT_GetKeyTrg(void) { return KEY_GetTrg(); }
