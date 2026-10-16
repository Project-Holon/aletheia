/*
 * file:     guru2_receipt.c
 * unit:     yes
 * function: GURU2_RECEIPT_ProcInit, GURU2_RECEIPT_GetUnionApp, GURU2_RECEIPT_SendMemberCount, GURU2_RECEIPT_UnionAppNoop, GURU2_RECEIPT_ProcMain, GURU2_RECEIPT_ProcExit, GURU2_RECEIPT_AnimatePalette, GURU2_RECEIPT_VBlank, GURU2_RECEIPT_UpdateQueues, GURU2_RECEIPT_SetVramBanks, GURU2_RECEIPT_InitBg, GURU2_RECEIPT_InitStrings, GURU2_RECEIPT_FreeStrings, GURU2_RECEIPT_ExitBg, GURU2_RECEIPT_LoadGraphics, GURU2_RECEIPT_InitActors, GURU2_RECEIPT_FreeActors, GURU2_RECEIPT_CreatePlayerActors, GURU2_RECEIPT_CreateWindows, GURU2_RECEIPT_PrintTitle, GURU2_RECEIPT_DeleteWindows, GURU2_RECEIPT_StateInit, GURU2_RECEIPT_StateIdleStart, GURU2_RECEIPT_HandleKeys, GURU2_RECEIPT_Noop, GURU2_RECEIPT_StateGoToMessage, GURU2_RECEIPT_SetPendingState, GURU2_RECEIPT_StateWaitMessage, GURU2_RECEIPT_StateReopenRecruit, GURU2_RECEIPT_StateOpenStartMenu, GURU2_RECEIPT_StateStartMenu, GURU2_RECEIPT_StateResetWait, GURU2_RECEIPT_StateWaitAnswers, GURU2_RECEIPT_StateAnswersDone, GURU2_RECEIPT_StateOpenCancelMenu, GURU2_RECEIPT_StateCancelMenu, GURU2_RECEIPT_StateSendStartRequest, GURU2_RECEIPT_StateWaitStartReady, GURU2_RECEIPT_StateShowStartMessage, GURU2_RECEIPT_StateWaitEndWipe, GURU2_RECEIPT_StateOpenQuitMenu, GURU2_RECEIPT_StateQuitMenu, GURU2_RECEIPT_StateShowQuitMessage, GURU2_RECEIPT_StateQuitDelay, GURU2_RECEIPT_StateSetSyncToken, GURU2_RECEIPT_StateCheckSyncToken, GURU2_RECEIPT_StateWaitMessageToError, GURU2_RECEIPT_StateWaitMessageToStart, GURU2_RECEIPT_StateShowTimeoutMessage, GURU2_RECEIPT_StateArmTimeout, GURU2_RECEIPT_StateTimeout, GURU2_RECEIPT_StateEndSession, GURU2_RECEIPT_SetStateFromParent, GURU2_RECEIPT_SetStateFromChild, GURU2_RECEIPT_CountMembers, GURU2_RECEIPT_PrintMemberList, GURU2_RECEIPT_Noop2, GURU2_RECEIPT_GetMemberCount, GURU2_RECEIPT_GetJoinedBits, GURU2_RECEIPT_UpdateMemberSlots, GURU2_RECEIPT_PrintMessage, GURU2_RECEIPT_IsMessageDone, GURU2_RECEIPT_ClearMessageFrame, GURU2_RECEIPT_UpdatePlayerActors, GURU2_RECEIPT_LoadCharBuffer, GURU2_RECEIPT_FreeCharBuffer, GURU2_RECEIPT_SetPlayerIcon, GURU2_RECEIPT_CheckMemberChange, GURU2_RECEIPT_GetKeyTrg
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
 *   func_020315D4 0x020315D4 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_SetStateFromParent 0x021DE08C thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   GURU2_RECEIPT_SetStateFromChild 0x021DE17C thumb ov137
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   func_020490F4 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_020056A0 0x020056A0 thumb
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
 *   GURU2_RECEIPT_CheckMemberChange 0x021DE738 thumb ov137
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   gGuru2LobbyStateTable 0x021E1C20 data a4
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   GURU2_RECEIPT_FreeActors 0x021DD570 thumb ov137
 *   GURU2_RECEIPT_DeleteWindows 0x021DD760 thumb ov137
 *   GURU2_RECEIPT_ExitBg 0x021DD3B0 thumb ov137
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
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
 *   func_02045CAC 0x02045CAC arm
 *   func_02049F78 0x02049F78 arm
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
 *   func_0201D304 0x0201D304 thumb
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
 *   func_02008534 0x02008534 thumb
 *   func_02008500 0x02008500 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02008530 0x02008530 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02049F34 0x02049F34 arm
 *   gGuru2MemberPaletteIndex 0x021E1AF8 data a1
 *   func_02049E34 0x02049E34 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   gGuru2LobbyActorResourceIds 0x021E1B20 data a4
 *   gGuru2LobbyCellIds 0x021E1B30 data a4
 *   gGuru2LobbyCellAnimIds 0x021E1B38 data a4
 *   gGuru2MemberPositionTable 0x021E1B08 data a2
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   GURU2_COMM_RegisterCommands 0x021DCB78 thumb ov137
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "ov137_types.h"
#include "guru2_shared_types.h"
#include "guru2_comm_shared_types.h"
#include "guru2_receipt_shared_types.h"
#include "guru2_types.h"

struct Tcbl;

struct S02031140;

typedef void (*Cb)(void);

struct State { u32 enable; u32 index; int counter; u32 spare; u8 *object; };

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern void func_020315D4(struct Proc *);

extern u32 func_020307B0(void *p);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern int UNION_APP_GetMemberCount(unsigned char *p);

extern u8 UNION_APP_GetJoinedBits(u8 *);

extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);

extern void *func_020490F4(u32 id, u32 heap);

extern void BG_SYS_Create(u16);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern void GURU2_RECEIPT_SetVramBanks(void),GURU2_RECEIPT_InitBg(void);

extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

void GURU2_RECEIPT_LoadGraphics(void *p,void *arc);

extern void *func_020056A0(void (*)(int,void *),void *,u32);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern u32 PRINTSYS_QUE_Create(void *);

void GURU2_RECEIPT_InitStrings(u8 *p,void *q);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 func_0200FB24(void);

extern void UNION_APP_Open(u8 *p);

extern void UNION_APP_RequestReset(u8 *p);

extern u32 UNION_APP_IsResetDone(u8 *);

extern void UNION_APP_SetCallbacks(u8 *,Cb,Cb,void *);

typedef struct { void *current; void *previous; } Entry;
typedef struct { char pad[0x38]; void *font; void *formatter; void *bank; void *names[5]; char pad58[0xe0]; Entry entries[5]; } Context;


void GURU2_RECEIPT_InitActors();

void GURU2_RECEIPT_CreatePlayerActors();

void GURU2_RECEIPT_CreateWindows();

extern void CLACT_DrawSystem(void);

int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,Context *p);

void GURU2_RECEIPT_UpdatePlayerActors(u8 *p);

int GURU2_RECEIPT_CheckMemberChange(FrameObj *obj);

extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned);

extern void TCBL_DeleteAllTasks(struct Tcbl *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern void PRINTSYS_QUE_Clear(struct PrintSys *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

void GURU2_RECEIPT_FreeActors(u8 *p);

void GURU2_RECEIPT_DeleteWindows(u8 *p);

void GURU2_RECEIPT_ExitBg(u32 a0);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void func_02030EAC(struct Node *n);

int GURU2_RECEIPT_GetMemberCount(void *p);

unsigned GURU2_RECEIPT_GetJoinedBits(void *p);

void GURU2_RECEIPT_FreeStrings(u8 *p);

extern void GFL_HEAP_DeleteChecked(u32);

extern void GX_LoadOBJPltt(void *, int, int);

extern void CLACT_VBlankSystem(void);

extern void BG_SYS_Update(void);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void TCBL_Main(struct Tcbl *p);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

void GURU2_COMM_RegisterCommands(u32 a);

extern int GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);

int GURU2_RECEIPT_ProcInit(void *a,u32 *state,u8 *ctx);

extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);

void GURU2_RECEIPT_SendMemberCount(int a,int b,struct Guru2MainCtx *p);

void GURU2_RECEIPT_UnionAppNoop(void);

int GURU2_RECEIPT_ProcMain(int a,int b,int c,u8 *p);

int GURU2_RECEIPT_ProcExit(void *a,int b,void *c,u8 *p);

void GURU2_RECEIPT_AnimatePalette(void *unused, u8 *p);

void GURU2_RECEIPT_VBlank(void *a0, void *work);

void GURU2_RECEIPT_UpdateQueues(u8 *p);

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
 * func_020490F4 0x020490F4 arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * BG_SYS_Create 0x0203F8F4 arm
 * func_02045B38 0x02045B38 arm
 * TCBL_Create 0x0203101C arm
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * WORDSET_CreateDefault 0x0201EC64 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * WIPE_SYS_Start 0x0202208C thumb
 * func_020056A0 0x020056A0 thumb
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
int GURU2_RECEIPT_ProcInit(void *a,u32 *state,u8 *ctx)
{
    u8 *p;
    void *arc;
    switch(*state) {
    case 0:
        BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
        *(volatile u32 *)0x04000000&=0xffffe0ff;
        *(volatile u32 *)0x04001000&=0xffffe0ff;
        GFL_HEAP_CreateChildHeap((u32)((void *)1),114,0x80000);
        arc=func_020490F4(184,114);
        p=PROCSYS_AllocProcWork(a,0x4874,114);
        MI_CpuFill8(p,0,0x4874);
        *(u8 **)(ctx+32)=p; *(u8 **)(p+12)=ctx;
        *(void **)(p+16)=*(void **)(ctx+24);
        BG_SYS_Create(114);
        *(void **)(p+60)=WORDSET_CreateDefault(114);
        *(void **)(p+64)=func_02045B38(0,2,42,114);
        *(void **)(p+56)=GF_FONT_Create(23,0,0,0,114);
        GURU2_RECEIPT_SetVramBanks(); GURU2_RECEIPT_InitBg();
        WIPE_SYS_Start(0,1,1,0,16,1,114);
        GURU2_RECEIPT_LoadGraphics(p,arc);
        *(void **)(p+48)=func_020056A0((void (*)(int, void *))GURU2_RECEIPT_VBlank,p,1);
        *(void **)(p+244)=TCBL_Create(114,114,32,32);
        *(u32 *)(p+236)=PRINTSYS_QUE_Create((void *)114);
        GURU2_RECEIPT_InitStrings(p,arc); GURU2_RECEIPT_InitActors(p,arc); GURU2_RECEIPT_CreatePlayerActors(p); GURU2_RECEIPT_CreateWindows(p);
        GURU2_COMM_RegisterCommands((u32)(*(void **)(ctx+24)));
        GFL_NET_RestartWithDefaultTimeout(1,114); ARC_TOOL_DeleteHandle(arc);
        (*state)++;
        break;
    case 1:
        *state=0;
        return 1;
    }
    return 0;
}

void *GURU2_RECEIPT_GetUnionApp(u8 *p) {return ((struct Guru2Session *)((struct Guru2MainCtx *)p)->fC)->param->unionApp;}

void GURU2_RECEIPT_SendMemberCount(int a,int b,struct Guru2MainCtx *p) {u8 v;if(GFL_NET_SYSTEM_GetCurrentAid()==0) {v=a;GURU2_COMM_Send(p->f10,10240,&v,1);}}

/*
 * extent: two zero alignment bytes before GURU2_RECEIPT_ProcMain.
 */
void GURU2_RECEIPT_UnionAppNoop(void) {}

extern int (*const gGuru2LobbyStateTable[])(u8 *,u32);

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
 * GURU2_RECEIPT_CheckMemberChange 0x021DE738 thumb ov137
 * GURU2_RECEIPT_UpdateQueues 0x021DD1B4 thumb ov137
 * GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 * CLACT_DrawSystem 0x0204A600 arm
 * WIPE_SYS_EndCheck 0x020221A4 thumb
 * func_0200FB24 0x0200FB24 thumb
 * gGuru2LobbyStateTable 0x021E1C20 data a4
 */
int GURU2_RECEIPT_ProcMain(int a,int b,int c,u8 *p)
{
    int v;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0 && ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30!=0)
        ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30&=UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));
    switch(*(unsigned int *)&((struct Guru2MainCtx *)p)->f0) {
    case 0:
        if(WIPE_SYS_EndCheck()) {
            *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=1;
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp(p));
            UNION_APP_SetCallbacks(GURU2_RECEIPT_GetUnionApp(p),(Cb)GURU2_RECEIPT_SendMemberCount,GURU2_RECEIPT_UnionAppNoop,p);
        }
        break;
    case 1:
        if(gGuru2LobbyStateTable[*(unsigned int *)&((struct Guru2MainCtx *)p)->f118]) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=gGuru2LobbyStateTable[*(u32 *)&((struct Guru2MainCtx *)p)->f118](p,*(unsigned int *)&((struct Guru2MainCtx *)p)->f0);
        if(((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f24==0) GURU2_RECEIPT_PrintMemberList(((struct Guru2MainCtx *)p)->fD0,0,1152,(Context *)p);
        GURU2_RECEIPT_UpdatePlayerActors(p);
        if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
            v=((int (*)(void *,int))GURU2_RECEIPT_CheckMemberChange)(p,1);
            if(*(unsigned int *)&((struct Guru2MainCtx *)p)->f0==1) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=v;
        }
        break;
    case 2:
        if(gGuru2LobbyStateTable[*(unsigned int *)&((struct Guru2MainCtx *)p)->f118]) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=gGuru2LobbyStateTable[*(u32 *)&((struct Guru2MainCtx *)p)->f118](p,*(unsigned int *)&((struct Guru2MainCtx *)p)->f0);
        break;
    case 3:
        if(WIPE_SYS_EndCheck()) {
            if(*(unsigned int *)&((struct Guru2MainCtx *)p)->f8) return 1;
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(GURU2_RECEIPT_GetUnionApp(p));
            *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=4;
        }
        break;
    case 4:
        if(UNION_APP_IsResetDone(GURU2_RECEIPT_GetUnionApp(p))) return 1;
        break;
    }
    if(WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
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
 * func_02030EAC 0x02030EAC arm
 * GURU2_RECEIPT_GetMemberCount 0x021DE354 thumb ov137
 * GURU2_RECEIPT_GetJoinedBits 0x021DE37C thumb ov137
 * GURU2_RECEIPT_FreeStrings 0x021DD380 thumb ov137
 * func_020315D4 0x020315D4 arm
 * GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
int GURU2_RECEIPT_ProcExit(void *a,int b,void *c,u8 *p)
{
    TCBL_DeleteAllTasks((struct Tcbl *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fF4)); TCBL_Destroy((struct S02031140 *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fF4));
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fEC)); PRINTSYS_QUE_Delete((struct PrintSys *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fEC));
    GURU2_RECEIPT_FreeActors(p); GURU2_RECEIPT_ExitBg(((u32 (*)(void *))GURU2_RECEIPT_DeleteWindows)(p));
    MSGDATA_Delete((struct Rec *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f40)); WORDSET_DeleteStrbufED04((struct WordSet *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f3C)); GF_FONT_Delete((void *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f38));
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_02030EAC((struct Node *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f30));
    ((struct Guru2Session *)((struct Guru2MainCtx *)p)->fC)->startConfirmed=*(unsigned int *)&((struct Guru2MainCtx *)p)->f8;
    ((struct Guru2Session *)((struct Guru2MainCtx *)p)->fC)->playerCount=GURU2_RECEIPT_GetMemberCount(p);
    ((struct Guru2Session *)((struct Guru2MainCtx *)p)->fC)->memberMask=GURU2_RECEIPT_GetJoinedBits(p);
    GURU2_RECEIPT_FreeStrings(p); func_020315D4(a); GFL_HEAP_DeleteChecked(114);
    return 1;
}

#pragma opt_propagation off

void GURU2_RECEIPT_AnimatePalette(void *unused, u8 *p)
{
    struct State *v = (struct State *)(p + 24);
    int c;
    u32 i;
    if (v->enable) {
        c = v->counter;
        i = v->index;
        if (c > gGuru2MemberPaletteStepThreshold[i * 2]) {
            v->index = i + 1;
            v->counter = 0;
            if (gGuru2MemberPaletteStepIndex[v->index * 2] == 255) v->index = 0;
            GX_LoadOBJPltt(*(u8 **)(v->object + 12) + (gGuru2MemberPaletteStepIndex[v->index * 2] << 5), 0, 32);
            return;
        }
        *(u32 *)(p + 32) += 1;
    }
}

#pragma opt_propagation reset

/*
 * Addresses are Black-image addresses.
 */
void GURU2_RECEIPT_VBlank(void *a0, void *work)
{
    GURU2_RECEIPT_AnimatePalette(a0, work);
    CLACT_VBlankSystem();
    BG_SYS_Update();
}

void GURU2_RECEIPT_UpdateQueues(u8 *p)
{
    if (((struct Guru2MainCtx *)p)->fEC)
        PRINTSYS_QUE_Main(((struct Guru2MainCtx *)p)->fEC);
    TCBL_Main(((struct Guru2MainCtx *)p)->fF4);
}

void GURU2_RECEIPT_SetVramBanks(void) {BG_SYS_SetVramBanks((const struct DispVram *)gGuru2LobbyVramBanks);}

struct StrObj;

struct BmpMenu;

struct Rec3;

struct Sub0204A9D0;

typedef struct {u8 frame,x,y,pal;u16 chr;} WinDat;

typedef unsigned long long u64;

typedef union { struct { u32 a,b; } words; u64 wide; } WordPair;

typedef struct { char pad[0x4824]; WordPair current,previous; } FrameRecord;

extern void BG_SYS_SetGraphicsMode(struct DispConfig *);

extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);

extern void BG_SYS_ClearSlot(u32);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BG_SYS_FreeLayerBuf(u32);

extern void BG_SYS_Delete(void);

extern void func_02049B68(void *,u32,u32,u32,u32,u16);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);

extern void func_02049B40(u32,u32,u32,u32,u32,u16);

extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

extern void func_0204989C(u32,u32,u32,u32,u32,u32,u16);

extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u8 *GAME_DATA_GetMyStatus(void *);

extern u8 func_02008550(const struct Sub0200852CObj *obj);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);

extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);

extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern struct FrameObj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorAutoAnim(struct FrameObj *,unsigned int);

extern void CLACT_SetActorAnimSeq(struct FrameObj *p, u16 value);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void CLACT_SetActorDrawEnable(struct FrameObj *,unsigned int);

extern void BMP_WIN_Init(u16);

extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void BG_SYS_PushTile(u32 index);

extern void BMP_MENU_DeleteYesNo(u8 *o);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern void GFL_NET_SetAutoExit(unsigned char a0);

extern int UNION_APP_Close(unsigned char *p);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern struct BmpMenu *BMP_MENU_CreateYesNo(const WinDat *,u16,u8,u8,u16);

extern u32 BMP_MENU_ProcessYesNo(u8 *p);

extern void GFL_NET_SetLoginOption(u8 a0);

extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);


extern void PRINTSYS_PrintStreamStop(void *);

extern u16 func_02008534(const struct Sub0200852CObj *obj);

extern void func_02008500(void *,void *);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 func_02008530(const struct Sub0200852CObj *obj);

extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, int, void *, int, u16, u16);

extern u32 PRINTSYS_PrintStreamGetState(void *p);

extern unsigned int KEY_GetCont(void);

extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);

extern u32 KEY_GetTrg(void);

extern void PRINTSYS_PrintStreamReleasePause(void *);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern u8 func_02008554(const struct Sub0200852CObj *obj);

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);

extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);





void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font);

int GURU2_RECEIPT_StateInit(char *p, int state);

int GURU2_RECEIPT_StateIdleStart(char *p,int a);

void GURU2_RECEIPT_HandleKeys(char *p);

void GURU2_RECEIPT_Noop(char *p);

int GURU2_RECEIPT_StateGoToMessage(char *p,int state);

void GURU2_RECEIPT_SetPendingState(char *p, int v);

int GURU2_RECEIPT_StateWaitMessage(char *p,int state);

int GURU2_RECEIPT_StateReopenRecruit(char *p,int state);

int GURU2_RECEIPT_StateOpenStartMenu(char *p,int state);

int GURU2_RECEIPT_StateStartMenu(char *p,int state);

int GURU2_RECEIPT_StateResetWait(char *p,int state);

int GURU2_RECEIPT_StateWaitAnswers(char *p, int state);

int GURU2_RECEIPT_StateAnswersDone(char *p,int state);

int GURU2_RECEIPT_StateOpenCancelMenu(char *p,int state);

int GURU2_RECEIPT_StateCancelMenu(char *p, int state);

int GURU2_RECEIPT_StateSendStartRequest(struct Guru2MainCtx *p,int state);

int GURU2_RECEIPT_StateWaitStartReady(struct Guru2MainCtx *p,int state);

int GURU2_RECEIPT_StateShowStartMessage(char *p,int state);

int GURU2_RECEIPT_StateWaitEndWipe(char *p,int state);

int GURU2_RECEIPT_StateOpenQuitMenu(char *p,int state);

int GURU2_RECEIPT_StateQuitMenu(char *p, int state);

int GURU2_RECEIPT_StateShowQuitMessage(char *p, int state);

int GURU2_RECEIPT_StateQuitDelay(char *p,int state);

int GURU2_RECEIPT_StateSetSyncToken(char *p, int state);

int GURU2_RECEIPT_StateCheckSyncToken(char *p, int state);

int GURU2_RECEIPT_StateWaitMessageToError(char *p,int state);

int GURU2_RECEIPT_StateWaitMessageToStart(char *p,int state);

int GURU2_RECEIPT_StateShowTimeoutMessage(char *p, int state);

int GURU2_RECEIPT_StateArmTimeout(char *p,int state);

int GURU2_RECEIPT_StateTimeout(char *p, int state);

int GURU2_RECEIPT_StateEndSession(char *p);

void GURU2_RECEIPT_SetStateFromParent(char *p,int state,int player);

void GURU2_RECEIPT_SetStateFromChild(struct Guru2MainCtx *p, int command, int player);

int GURU2_RECEIPT_CountMembers(void *p);

void GURU2_RECEIPT_Noop2(char *a0);

int GURU2_RECEIPT_UpdateMemberSlots(char *p);

void GURU2_RECEIPT_PrintMessage(char *p, int message, int unused);

int GURU2_RECEIPT_IsMessageDone(char *p);

void GURU2_RECEIPT_ClearMessageFrame(u8 *p);

void GURU2_RECEIPT_LoadCharBuffer(char *p, void *a1);

void GURU2_RECEIPT_FreeCharBuffer(u8 *p);

void GURU2_RECEIPT_SetPlayerIcon(u8 *p, u8 *q, int i, int j, int unused);

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
 * func_02045CAC 0x02045CAC arm
 * func_02049F78 0x02049F78 arm
 * GURU2_RECEIPT_LoadCharBuffer 0x021DE6C0 thumb ov137
 */
void GURU2_RECEIPT_InitStrings(u8 *p,void *q)
{
    int i;
    u32 v;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+68)=(u32)STRBUF_Create(8,114);
        *(u32 *)(p+i*8+312)=0; *(u32 *)(p+i*8+316)=0;
        *(u32 *)(p+i*4+352)=0;
    }
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f5C=(u32)STRBUF_Create(180,114);
    v=(u32)STRBUF_Create(40,114); *(unsigned int *)&((struct Guru2MainCtx *)p)->f60=v;
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f118=0;
    func_02045CAC((struct MsgBank *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f40),17,(void *)v);
    GURU2_RECEIPT_LoadCharBuffer((char *)p,q);
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f18=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->f20=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->f1C=0;
    *(unsigned int *)&((struct Guru2MainCtx *)p)->f24=(u32)func_02049F78(q,2,(u32)(p+40),114);
    ((struct Guru2MainCtx *)p)->f4804=0; *(unsigned int *)&((struct Guru2MainCtx *)p)->fE8=0;
    ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C=2;
}

void GURU2_RECEIPT_FreeStrings(u8 *p) {int i;GURU2_RECEIPT_FreeCharBuffer(p);func_020307B0(((struct Guru2MainCtx *)p)->f24);for(i=0;i<5;i++)STRBUF_Delete(*(void **)((u32)p+i*4+68));STRBUF_Delete(((struct Guru2MainCtx *)p)->f60);STRBUF_Delete(((struct Guru2MainCtx *)p)->f5C);}

void GURU2_RECEIPT_ExitBg(u32 a0) {BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(0);BG_SYS_Delete();}

/*
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 ARC_UTIL_LoadMember(void *,void *,u32,u16);
 * extern u32 func_0204968C(u32,void *,void *,u32,u32);
 * u32 func_02049624(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=ARC_UTIL_LoadMember(a,b,f,g); return func_0204968C(r,c,d,e,f);
 * }
 * Blocker symbols: ARC_UTIL_LoadMember 0x0204A1BC arm; func_0204968C 0x0204968C arm.
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049B40 0x02049B40 arm
 * func_02049624 0x02049624 arm
 * func_0204989C 0x0204989C arm
 * func_02040588 0x02040588 arm
 * BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 */
void GURU2_RECEIPT_LoadGraphics(void *p,void *arc)
{
    func_02049B68(arc,1,0,0,512,114);
    func_02049658(arc,7,1,0,8192,0,114);
    func_020498F4(arc,13,1,0,1536,0,114);
    func_02049B40(23,5,0,416,32,114);
    func_02049B40(30,13,4,0,352,114);
    func_02049624((void *)30,(void *)14,(void *)6,0,0,0,114);
    func_0204989C(30,3,6,0,0,0,114);
    BMP_MENUWORK_LoadCharAndPltt(0,1,10,0,114);
    BMP_MENUWORK_LoadCharAndPltt(0,31,11,0,114);
    func_02040588(0,1);
    func_02040588(1,1);
    func_02040588(6,1);
}

/*
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * GAME_DATA_GetMyStatus 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
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
void GURU2_RECEIPT_InitActors(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    CLACT_InitSystem(&gClActorInitParam,(u32)gGuru2LobbyVramBanks,114);
    *(void **)(p+104)=CLACT_CreateUnit(30,1,114);
    i=0;
    table=gGuru2LobbyActorResourceIds+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=CLACT_RegisterCharacter(arc,a,0,0,114);
        *(int *)(p+i*4+108)=CLACT_RegisterPaletteEx(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=CLACT_RegisterCellAnim(arc,gGuru2LobbyCellIds[v],gGuru2LobbyCellAnimIds[v],114);
    ARC_TOOL_DeleteHandle(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}

void GURU2_RECEIPT_FreeActors(u8 *p) {int i;u8 *q;ARC_TOOL_DeleteHandle(*(void * *)&((struct Guru2MainCtx *)p)->f34);for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);CLACT_ReleaseCharacter(((struct Guru2MainCtx *)q)->f6C);CLACT_ReleasePalette(((struct Guru2MainCtx *)q)->f80);}CLACT_ReleaseCellAnim(((struct Guru2MainCtx *)p)->f94);CLACT_DeleteUnit(((struct Guru2MainCtx *)p)->f68);CLACT_ExitSystem();}

/*
 * CLACT_CreateActor 0x0204B294 arm
 * CLACT_SetActorAutoAnim 0x0204B92C arm
 * CLACT_SetActorAnimSeq 0x0204B878 arm
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * BG_SYS_SetMainPlaneVisible 0x020434DC arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * gGuru2MemberPositionTable 0x021E1B08 data a2
 */
void GURU2_RECEIPT_CreatePlayerActors(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=gGuru2MemberPositionTable[i*2+2]; s.b=gGuru2MemberPositionTable[i*2+3];
        *(u32 *)(p+i*4+156)=(u32)(struct Obj *)CLACT_CreateActor((void *)*(unsigned int *)&((struct Guru2MainCtx *)p)->f68,*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),((struct Guru2MainCtx *)p)->f94,&s,0,114);
        CLACT_SetActorAutoAnim((struct FrameObj *)*(u32 *)(p+i*4+156),1);
        CLACT_SetActorAnimSeq((struct FrameObj *)(*(u32 *)(p+i*4+156)),0);
        CLACT_SetActorDrawEnable((struct FrameObj *)*(u32 *)(p+i*4+156),0);
    }
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,0);
}

/*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 */
void GURU2_RECEIPT_CreateWindows(struct Guru2MainCtx *p) {
    BMP_WIN_Init(0x72);
    *(u32 *)&p->fD8=BMP_WIN_Create(5,26,20,6,2,13,1);
    BMP_Clear(BMP_WIN_GetBmp(p->fD8),0);
    *(u32 *)&p->fD4=BMP_WIN_Create(0,2,19,27,4,13,1);
    BMP_Clear(BMP_WIN_GetBmp(p->fD4),15);
    *(u32 *)&p->fDC=BMP_WIN_Create(0,3,1,26,2,15,1);
    GURU2_RECEIPT_PrintTitle(p->fDC,p->f60,p->f38);
    *(u32 *)&p->fD0=BMP_WIN_Create(0,2,6,16,11,15,1);
    BMP_Clear(BMP_WIN_GetBmp(p->fD0),0);
    GURU2_RECEIPT_PrintMemberList(p->fD0, 0, 0x480, (Context *)p);
    p->fF8=p->fDC;
    p->fFC=0;
}

void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, (u32)font, 0);
    BMP_Clear(BMP_WIN_GetBmp(p), 0);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p), (208-width)/2, 1, text, font, 0x480);
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    BG_SYS_PushTile((u32)BMP_WIN_GetBgLayer(p));
}

void GURU2_RECEIPT_DeleteWindows(u8 *p) {if(((struct Guru2MainCtx *)p)->fE8!=0)BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);BMP_WIN_Delete(((struct Guru2MainCtx *)p)->fD0);BMP_WIN_Delete(((struct Guru2MainCtx *)p)->fDC);BMP_WIN_Delete(((struct Guru2MainCtx *)p)->fD8);BMP_WIN_Delete(((struct Guru2MainCtx *)p)->fD4);BMP_WIN_Exit();}

int GURU2_RECEIPT_StateInit(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        int zero = 0;
        GFL_NET_SetAutoExit(0);
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) >= 2)
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
int GURU2_RECEIPT_StateIdleStart(char *p,int a) {GURU2_RECEIPT_HandleKeys(p);if(GFL_NET_SYSTEM_GetCurrentAid()==0) {if(GURU2_RECEIPT_CountMembers(p)==1) {} else GURU2_RECEIPT_Noop2(p);}else GURU2_RECEIPT_Noop2(p);return a;}

void GURU2_RECEIPT_HandleKeys(char *p) {
    char *q;
    if (GURU2_RECEIPT_GetKeyTrg()&1) {
        if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
            q=*(char * *)&((struct Guru2MainCtx *)p)->f10;
            if (((struct Guru2MainCtx *)q)->f2C==GURU2_RECEIPT_GetMemberCount(p) && *(unsigned int *)&((struct Guru2MainCtx *)q)->f30==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp((u8 *)p))) {
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    GURU2_RECEIPT_PrintMessage(p,3,0);
                    GURU2_RECEIPT_SetPendingState(p,22);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else if (GURU2_RECEIPT_GetKeyTrg()&2) {
        if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
            if (*(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f28==0) {
                GURU2_RECEIPT_PrintMessage(p,4,0);
                GURU2_RECEIPT_SetPendingState(p,4);
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        } else {
            q=*(char * *)&((struct Guru2MainCtx *)p)->f10;
            if (((struct Guru2MainCtx *)q)->f2C==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) && *(unsigned int *)&((struct Guru2MainCtx *)q)->f30==0) {
                if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp((u8 *)p))) {
                    GURU2_RECEIPT_PrintMessage(p,4,0);
                    GURU2_RECEIPT_SetPendingState(p,4);
                    GFL_USE_PlaySeDefaultVolume(0x551);
                }
            } else GFL_USE_PlaySeDefaultVolume(0x548);
        }
    } else {
        if (*(unsigned int *)&((struct Guru2MainCtx *)p)->f4808==0 && GFL_NET_SYSTEM_GetCurrentAid()==0 &&
            ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)))
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
    }
}

void GURU2_RECEIPT_Noop(char *p) {}

/*
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int GURU2_RECEIPT_StateGoToMessage(char *p,int state) {((struct Guru2MainCtx *)p)->f118=2;GURU2_RECEIPT_Noop(p);return state;}

void GURU2_RECEIPT_SetPendingState(char *p, int v)
{
    ((struct Guru2MainCtx *)p)->f118 = 0x1A;
    ((struct Guru2MainCtx *)p)->f11C = v;
}

int GURU2_RECEIPT_StateWaitMessage(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) ((struct Guru2MainCtx *)p)->f118=((struct Guru2MainCtx *)p)->f11C;GURU2_RECEIPT_Noop(p);return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 */
int GURU2_RECEIPT_StateReopenRecruit(char *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));((struct Guru2MainCtx *)p)->f118=3;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenStartMenu(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);((struct Guru2MainCtx *)p)->f118=5;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateStartMenu(char *p,int state) {
    unsigned count;
    unsigned result;
    u8 msg[4];
    if (GFL_NET_SYSTEM_GetCurrentAid()!=0) {
        if (*(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f28!=0) {
            if (GURU2_RECEIPT_GetKeyTrg()&0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
            GURU2_RECEIPT_Noop(p);
            return state;
        }
    } else {
        if (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30!=0) {
            if (GURU2_RECEIPT_GetKeyTrg()&0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
            GURU2_RECEIPT_Noop(p);
            return state;
        }
    }
    count=GURU2_RECEIPT_GetMemberCount(p);
    if (count!=UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p))) {
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result=BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result!=-1) {
        if (result==-2) {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
            ((struct Guru2MainCtx *)p)->f118=0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid()==0) {
                GURU2_RECEIPT_SetPendingState(p,11);
                GURU2_RECEIPT_PrintMessage(p,14,0);
            } else {
                MI_CpuFill8(msg,0,4);
                msg[2]=0;
                msg[0]=GFL_NET_SYSTEM_GetCurrentAid();
                if (GURU2_COMM_Send(((struct Guru2MainCtx *)p)->f10,0x2801,msg,4)) {
                    ((struct Guru2MainCtx *)p)->f4810=1;
                    *(unsigned short *)&((struct Guru2MainCtx *)p)->f4820=0;
                    ((struct Guru2MainCtx *)p)->f118=6;
                } else ((struct Guru2MainCtx *)p)->f118=0;
            }
        }
        ((struct Guru2MainCtx *)p)->fE8=0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateResetWait(char *p,int state) {*(unsigned short *)&((struct Guru2MainCtx *)p)->f4820=0;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitAnswers(char *p, int state) {
    unsigned char buf[4];
    if (((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f38 != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)) ||
        ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f38 != GURU2_RECEIPT_GetMemberCount(p)) {
        ((struct Guru2MainCtx *)p)->f4820 = 0;
        ((struct Guru2MainCtx *)p)->f118 = 8;
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    ++*(volatile s16 *)&((struct Guru2MainCtx *)p)->f4820;
    if (*(volatile s16 *)&((struct Guru2MainCtx *)p)->f4820 > 30) {
        int zero = 0;
        MI_CpuFill8(buf, 0, 4);
        buf[2] = 1;
        buf[0] = GFL_NET_SYSTEM_GetCurrentAid();
        GURU2_COMM_Send(((struct Guru2MainCtx *)p)->f10, 0x2801, buf, 4);
        ((struct Guru2MainCtx *)p)->f4820 = zero;
        ((struct Guru2MainCtx *)p)->f118 = 9;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateAnswersDone(char *p,int state) {((struct Guru2MainCtx *)p)->f4810=0;GURU2_RECEIPT_SetPendingState(p,0);GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenCancelMenu(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);((struct Guru2MainCtx *)p)->f118=23;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateCancelMenu(char *p, int state) {
    char *q = *(char * *)&((struct Guru2MainCtx *)p)->f10;
    unsigned result;
    if (((struct Guru2MainCtx *)q)->f2C != GURU2_RECEIPT_GetMemberCount(p) || *(unsigned int *)&((struct Guru2MainCtx *)q)->f30 != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
            ((struct Guru2MainCtx *)p)->f118 = 0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                ((struct Guru2MainCtx *)p)->f118 = 0x18;
                ((struct Guru2MainCtx *)p)->f4812 = GURU2_RECEIPT_GetMemberCount(p);
            }
        }
        ((struct Guru2MainCtx *)p)->fE8 = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

/*
 * prototype: original cmp r0,#1 at 021DDC96 uses GURU2_COMM_Send's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to GFL_NET_SetLoginOption despite its filed no-argument prototype.
 */
int GURU2_RECEIPT_StateSendStartRequest(struct Guru2MainCtx *p,int state) {if(p->f4813==0) {if(GURU2_COMM_Send(p->f10,0x2804,0,0)==1) {p->f118=27;GFL_NET_SetLoginOption(1);}}return state;}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int GURU2_RECEIPT_StateWaitStartReady(struct Guru2MainCtx *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));if(((struct Guru2MainCtx2 *)p->f10)->f20==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p))) p->f118=27;return state;}

int GURU2_RECEIPT_StateShowStartMessage(char *p,int state) {GURU2_RECEIPT_PrintMessage(p,5,0);GURU2_RECEIPT_SetPendingState(p,10);GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitEndWipe(char *p,int state) {if(++((struct Guru2MainCtx *)p)->f124>60) {WIPE_SYS_Start(0,0,0,0,16,1,114);state=3;}GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateOpenQuitMenu(char *p,int state) {*(struct BmpMenu * *)&((struct Guru2MainCtx *)p)->fE8=BMP_MENU_CreateYesNo(&gGuru2YesNoMenuTemplate,31,11,0,114);((struct Guru2MainCtx *)p)->f118=12;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateQuitMenu(char *p, int state) {
    char *q = *(char * *)&((struct Guru2MainCtx *)p)->f10;
    unsigned result;
    if (((struct Guru2MainCtx *)q)->f2C != GURU2_RECEIPT_GetMemberCount(p) || *(unsigned int *)&((struct Guru2MainCtx *)q)->f30 != 0) {
        if (GURU2_RECEIPT_GetKeyTrg() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x54c);
        GURU2_RECEIPT_Noop(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Guru2MainCtx *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Guru2MainCtx *)p)->f118 = 0;
            UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));
        } else {
            ((struct Guru2MainCtx *)p)->f118 = 0xd;
            GURU2_COMM_Send(((struct Guru2MainCtx *)p)->f10, 0x2802, 0, 0);
            WORDSET_SetSlotMyStatus(((struct Guru2MainCtx *)p)->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), 0));
        }
        ((struct Guru2MainCtx *)p)->fE8 = 0;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateShowQuitMessage(char *p, int state) {
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        GURU2_RECEIPT_PrintMessage(p, 5, 0);
    } else {
        WORDSET_SetSlotMyStatus(((struct Guru2MainCtx *)p)->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), 0));
        GURU2_RECEIPT_PrintMessage(p, 0x10, 0);
    }
    GURU2_RECEIPT_SetPendingState(p, 0xe);
    ((struct Guru2MainCtx *)p)->f124 = 0;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateQuitDelay(char *p,int state) {if(++((struct Guru2MainCtx *)p)->f124>45) ((struct Guru2MainCtx *)p)->f118=15;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateSetSyncToken(char *p, int state) {
    GFL_NET_HANDLE_GetCurrentHandle();
    ((struct Guru2MainCtx *)p)->f4814 = ((struct Guru2MainCtx *)p)->f480C ^ GURU2_RECEIPT_GetJoinedBits(p);
    GFL_NET_HANDLE_SetUserInfo((char *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28, (u16)(((struct Guru2MainCtx *)p)->f4814));
    ((struct Guru2MainCtx *)p)->f118 = 0x10;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateCheckSyncToken(char *p, int state) {
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28) != 0 ||
        ((struct Guru2MainCtx *)p)->f4814 != (GURU2_RECEIPT_GetJoinedBits(p) ^ ((struct Guru2MainCtx *)p)->f480C)) {
        GFL_NET_SetAutoExit(0);
        WIPE_SYS_Start(0,0,0,0,0x10,1,0x72);
        state = 3;
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateWaitMessageToError(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) {GURU2_RECEIPT_PrintMessage(p,7,0);((struct Guru2MainCtx *)p)->f118=18;}GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateWaitMessageToStart(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) ((struct Guru2MainCtx *)p)->f118=10;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateShowTimeoutMessage(char *p, int state) {
    GURU2_RECEIPT_PrintMessage(p, 15, 1);
    *(int *)(p + 0x118) = 20;
    GFL_NET_SYSTEM_GetCurrentAid();
    *(int *)(p + 0x481C) = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
    *(int *)(p + 0x4818) = 300;
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateArmTimeout(char *p,int state) {if(((struct Guru2MainCtx *)p)->f481C){if(((struct Guru2MainCtx *)p)->f481C!=(u32)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p))) ((struct Guru2MainCtx *)p)->f481C=0;}((struct Guru2MainCtx *)p)->f118=21;((struct Guru2MainCtx *)p)->f124=0;GURU2_RECEIPT_Noop(p);return state;}

int GURU2_RECEIPT_StateTimeout(char *p, int state) {
    if (((struct Guru2MainCtx *)p)->f481C != 0) {
        if (((struct Guru2MainCtx *)p)->f481C != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)))
            ((struct Guru2MainCtx *)p)->f481C = 0;
    }
    if (--((struct Guru2MainCtx *)p)->f4818 < 0)
        ((struct Guru2MainCtx *)p)->f481C = 0;
    if (++((struct Guru2MainCtx *)p)->f124 > 60 && ((struct Guru2MainCtx *)p)->f481C == 0) {
        ((struct Guru2MainCtx *)p)->f118 = 0;
        GFL_NET_SYSTEM_GetCurrentAid();
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}

int GURU2_RECEIPT_StateEndSession(char *p) {WIPE_SYS_Start(0,0,0,0,16,1,114);*(int *)&((struct Guru2MainCtx *)p)->f8=1;GURU2_RECEIPT_Noop(p);return 3;}

void GURU2_RECEIPT_SetStateFromParent(char *p,int state,int player) {
    switch(state) {
    case 2:
        GURU2_RECEIPT_ClearMessageFrame((u8 *)p);
        break;
    case 13:
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 25:
        GURU2_RECEIPT_PrintMessage(p,12,0);
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 19:
        if (((struct Guru2MainCtx *)p)->f4810==1) return;
        WORDSET_SetSlotMyStatus(((struct Guru2MainCtx *)p)->f3C,0,UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p),player));
        if (player==GFL_NET_SYSTEM_GetCurrentAid()) return;
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        if (GFL_NET_SYSTEM_GetCurrentAid()==0)
            ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30&=player^0xffff;
        break;
    case 27:
        if (!GURU2_RECEIPT_IsMessageDone(p)) PRINTSYS_PrintStreamStop(((struct Guru2MainCtx *)p)->fF0);
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8=0;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    ((struct Guru2MainCtx *)p)->f118=state;
}

void GURU2_RECEIPT_SetStateFromChild(struct Guru2MainCtx *p, int command, int player) {
    void *target;
    if (p->f118 == 3) {
        switch (command) {
        case 1:
            target = UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), player);
            if (target != 0)
                WORDSET_SetSlotMyStatus(p->f3C, 0, target);
            p->f118 = command;
            ((struct Guru2MainCtx2 *)p->f10)->f2C = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
            ((struct Guru2MainCtx2 *)p->f10)->f30 = 0;
            return;
        case 19:
            WORDSET_SetSlotMyStatus(p->f3C, 0, UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p), player));
            if (player != GFL_NET_SYSTEM_GetCurrentAid()) {
                if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
                    ((struct Guru2MainCtx2 *)p->f10)->f30 &= player ^ 0xffff;
                p->f118 = command;
            }
            break;
        }
    } else {
        if (command == 1) {
            ((struct Guru2MainCtx2 *)p->f10)->f30 = 0;
            ((struct Guru2MainCtx2 *)p->f10)->f2C = UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));
        }
    }
}

int GURU2_RECEIPT_CountMembers(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i)) n++;return n;}

/*
 * extent: Two-byte alignment padding at 0x021DE34E.
 * lever: Struct members avoid cached element addresses; block scopes and expanding the first y argument settle the two spill slots.
 */
int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,Context *p) {
    int player;
    void *format;
    u16 value;
    void *text;
    int i;
    u16 ink;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    if (!GURU2_RECEIPT_UpdateMemberSlots((char *)p)) return 0;
    BMP_Clear(BMP_WIN_GetBmp(window),0);
    for(i=0;i<5;i++) {
      do {
        if (p->entries[i].current) {
            int y;
            value=func_02008534(p->entries[i].current);
            text=STRBUF_Create(16,0x72);
            func_02008500(p->entries[i].current,p->names[i]);
            WORDSET_SetSlotNumber(p->formatter,0,value,5,2,1);
            format=func_02045EC0(p->bank,1);
            WORDSET_CopyTaggedText(p->formatter,text,format);
            if (player==i) ink=0x860; else ink=color;
            y=18*i+1;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(window),5,18*i+1,p->names[i],p->font,ink);
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

void GURU2_RECEIPT_Noop2(char *a0) {}

int GURU2_RECEIPT_GetMemberCount(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp(p),(u8)i)) n++;return n;}

unsigned GURU2_RECEIPT_GetJoinedBits(void *p) {return UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p));}

int GURU2_RECEIPT_UpdateMemberSlots(char *p) {
    int changed;
    int i;
    u32 *slot;
    FrameRecord *record;
    changed=0;
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        slot[0x13c/4]=slot[0x138/4];
        slot[0x138/4]=(u32)UNION_APP_GetMemberEntry(GURU2_RECEIPT_GetUnionApp((u8 *)p),(u8)i);
        record=(FrameRecord *)(p+i*16);
        record->previous=record->current;
        if (slot[0x138/4]) {
            record->current.words.a=func_02008530((void *)slot[0x138/4]);
            record->current.words.b=1;
        } else {
            record->current.wide=0;
        }
    }
    for(i=0;i<5;i++) {
        slot=(u32 *)(p+i*8);
        if (slot[0x13c/4]!=slot[0x138/4]) {
            changed=1;
            if (slot[0x138/4]==0) *(u32 *)(p+i*4+0x160)=3;
            else *(u32 *)(p+i*4+0x160)=1;
        } else {
            record=(FrameRecord *)(p+i*16);
            if (record->current.wide!=record->previous.wide) {
                changed=1;
                if (record->current.words.b==0) *(u32 *)(p+i*4+0x160)=3;
                else *(u32 *)(p+i*4+0x160)=1;
            }
        }
    }
    return changed;
}

void GURU2_RECEIPT_PrintMessage(char *p, int message, int unused) {
    void *text;
    void *window;
    text = STRBUF_Create(0xb4, 0x72);
    func_02045CAC(*(void * *)&((struct Guru2MainCtx *)p)->f40, message, text);
    WORDSET_CopyTaggedText(((struct Guru2MainCtx *)p)->f3C, ((struct Guru2MainCtx *)p)->f5C, text);
    STRBUF_Delete(text);
    BMP_Clear(BMP_WIN_GetBmp(((struct Guru2MainCtx *)p)->fD4), 0xf);
    BMP_MENUWORK_DrawWindow(((struct Guru2MainCtx *)p)->fD4, 0, 1, 0xa);
    if (((struct Guru2MainCtx *)p)->fF0 != 0)
        PRINTSYS_PrintStreamDelete(((struct Guru2MainCtx *)p)->fF0);
    ((struct Guru2MainCtx *)p)->fF0 = PRINTSYS_PrintStream(((struct Guru2MainCtx *)p)->fD4, 0, 0, ((struct Guru2MainCtx *)p)->f5C, ((struct Guru2MainCtx *)p)->f38, 0, ((struct Guru2MainCtx *)p)->fF4, 0, 0x72, 0xf);
    window = ((struct Guru2MainCtx *)p)->fD4;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}

int GURU2_RECEIPT_IsMessageDone(char *p) {
    int state;
    if (((struct Guru2MainCtx *)p)->fF0 == 0) return 1;
    state = PRINTSYS_PrintStreamGetState(((struct Guru2MainCtx *)p)->fF0);
    if (state == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(((struct Guru2MainCtx *)p)->fF0, 0);
    } else if (state == 1) {
        if (KEY_GetTrg() & 1)
            PRINTSYS_PrintStreamReleasePause(((struct Guru2MainCtx *)p)->fF0);
    } else if (state == 2) {
        PRINTSYS_PrintStreamDelete(((struct Guru2MainCtx *)p)->fF0);
        ((struct Guru2MainCtx *)p)->fF0 = 0;
        return 1;
    }
    return 0;
}

/*
 * Addresses are Black-image addresses.
 */
void GURU2_RECEIPT_ClearMessageFrame(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Guru2MainCtx *)p)->fD4, 0);
}

void GURU2_RECEIPT_UpdatePlayerActors(u8 *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(*(u32 *)(p+i*4+0x160)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i==GFL_NET_SYSTEM_GetCurrentAid()) {
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 4);
            } else {
                GURU2_RECEIPT_SetPlayerIcon((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 4);
            }
            CLACT_SetActorDrawEnable((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==GFL_NET_SYSTEM_GetCurrentAid()) {
                func_02008550(*(void **)(p+i*8+0x138));
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 5);
            } else {
                CLACT_SetActorAnimSeq((struct FrameObj *)(*(void **)(p+i*4+0x9c)), 5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) GFL_USE_PlaySeDefaultVolume(0x676);
}

void GURU2_RECEIPT_LoadCharBuffer(char *p, void *a1) { ((struct Guru2MainCtx *)p)->f110=func_02049F34(32,0,(u32)(p+276),114); }

void GURU2_RECEIPT_FreeCharBuffer(u8 *p)
{
    func_020307B0(((struct Guru2MainCtx *)p)->f110);
}

void GURU2_RECEIPT_SetPlayerIcon(u8 *p, u8 *q, int i, int j, int unused)
{
    void *r;
    int n;
    GX_LoadOBJPltt(*(u8 * *)&((struct Guru2MainCtx *)q)->fC + gGuru2MemberPaletteIndex[j] * 32, i * 32, 32);
    r = func_02049E34(32, j + 1, 0, (u32)(&n), 114);
    CLACT_TransferCharacter((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}

/*
 * volatile: previous state at +0x4804 is read at 0x021DE764 and 0x021DE7CA.
 */
int GURU2_RECEIPT_CheckMemberChange(FrameObj *obj)
{
    u8 *p = (u8 *)obj;
    int state;
    state = GURU2_RECEIPT_GetMemberCount(p);
    if (state > *(int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C) {
        if (UNION_APP_Close(GURU2_RECEIPT_GetUnionApp(p))) ((struct Guru2MainCtx *)p)->f4808 = 1;
    } else ((struct Guru2MainCtx *)p)->f4808 = 0;
    if (state == obj->previous) return 1;
    switch (state) {
    case 0: break;
    case 1:
        if ((unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p)) > 1 || UNION_APP_GetJoinedBits(GURU2_RECEIPT_GetUnionApp(p)) > 1) return 1;
        *(int *)&((struct Guru2MainCtx *)p)->f118 = 17;
        if (((struct Guru2MainCtx *)p)->fE8) {
            BMP_MENU_DeleteYesNo(((struct Guru2MainCtx *)p)->fE8);
            ((struct Guru2MainCtx *)p)->fE8 = 0;
        }
        return 2;
    case 2: case 3: case 4:
        if (state < obj->previous)
            *(int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f2C = (unsigned)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp(p));
        break;
    case 5: break;
    }
    obj->previous = GURU2_RECEIPT_GetMemberCount(p);
    return 1;
}

u32 GURU2_RECEIPT_GetKeyTrg(void) { return KEY_GetTrg(); }
