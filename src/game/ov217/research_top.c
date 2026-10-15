/*
 * file:     research_top.c
 * unit:     yes
 * function: RESEARCH_TOP_InitProc, RESEARCH_TOP_ReleaseProc, RESEARCH_TOP_MainProc, RESEARCH_TOP_UpdateNetwork, RESEARCH_TOP_ChangeScreen, RESEARCH_TOP_CloseSubState, RESEARCH_TOP_OpenSubState, RESEARCH_TOP_StateIdle, RESEARCH_TOP_StateList, RESEARCH_TOP_StateGraph, RESEARCH_TOP_StateDetail, RESEARCH_TOP_GetFrameCount, RESEARCH_TOP_IncFrameCount, RESEARCH_TOP_ResetProc, RESEARCH_TOP_CreateCommon, RESEARCH_TOP_DestroyCommon, RESEARCH_TOP_CreateListView, RESEARCH_TOP_DestroyListView, RESEARCH_TOP_InitBackgrounds, RESEARCH_TOP_ExitBackgrounds, RESEARCH_TOP_LoadSubAssets, RESEARCH_TOP_UpdateFrameGraphic, RESEARCH_TOP_LoadTopAssets, RESEARCH_TOP_CreateListObject, RESEARCH_TOP_DestroyListObject, RESEARCH_TOP_UpdateListObject, RESEARCH_TOP_IsListObjectDone, RESEARCH_TOP_GetListObjectMode, RESEARCH_TOP_InitListObject, RESEARCH_TOP_HandleListInput, RESEARCH_TOP_HandleListInputAlt, RESEARCH_TOP_AdvanceListScroll, RESEARCH_TOP_StepExitFade, RESEARCH_TOP_CleanupListObject, RESEARCH_TOP_PushCommand, RESEARCH_TOP_SetCommandReady, RESEARCH_TOP_ProcessCommand, RESEARCH_TOP_StartCommand, RESEARCH_TOP_GetCommandTimer, RESEARCH_TOP_IncCommandTimer, RESEARCH_TOP_GetTransitionKind, RESEARCH_TOP_SetEntryHandled, RESEARCH_TOP_SetMode, RESEARCH_TOP_CheckQuestionnaire, RESEARCH_TOP_SelectPrev, RESEARCH_TOP_SelectNext, RESEARCH_TOP_SelectDirect, RESEARCH_TOP_DrawSelector, RESEARCH_TOP_DrawSelectorIdle, RESEARCH_TOP_SetupTextLabel, RESEARCH_TOP_StartPaletteAnime, RESEARCH_TOP_ShowEntryActor, RESEARCH_TOP_FadeIn, RESEARCH_TOP_FadeOut, RESEARCH_TOP_IncStateTimer, RESEARCH_TOP_GetStateTimer, RESEARCH_TOP_SetStateTimer, RESEARCH_TOP_GetStateTimerLimit, RESEARCH_TOP_MoveSelection, RESEARCH_TOP_SetSelection, RESEARCH_TOP_IsSelectionValid, RESEARCH_TOP_GetEntryActorSource, RESEARCH_TOP_GetEntryLabelSource, RESEARCH_TOP_GetEntryIconSource, RESEARCH_TOP_StartEntryPaletteAnime, RESEARCH_TOP_StopEntryPaletteAnime, RESEARCH_TOP_UpdateEntryPaletteAnime, RESEARCH_TOP_CountUnlockedEntries, RESEARCH_TOP_GetOwner, RESEARCH_TOP_SetOwner, RESEARCH_TOP_SetHeapId, RESEARCH_TOP_GetInputFlag, RESEARCH_TOP_AllocListObject, RESEARCH_TOP_FreeListObject, RESEARCH_TOP_InitFields, RESEARCH_TOP_InitSelection, RESEARCH_TOP_ClearFont, RESEARCH_TOP_CreateFont, RESEARCH_TOP_DeleteFont, RESEARCH_TOP_ClearMessages, RESEARCH_TOP_CreateMessages, RESEARCH_TOP_DeleteMessages, RESEARCH_TOP_InitPaletteRows, RESEARCH_TOP_ClearCommandQueue, RESEARCH_TOP_CreateCommandQueue, RESEARCH_TOP_DestroyCommandQueue, RESEARCH_TOP_InitOverlayBackgrounds, RESEARCH_TOP_ExitOverlayBackgrounds, RESEARCH_TOP_LoadBackground6, RESEARCH_TOP_DummyBg7, RESEARCH_TOP_UpdateBackground7, RESEARCH_TOP_ShowBackground7, RESEARCH_TOP_LoadBackground2, RESEARCH_TOP_DummyBg3, RESEARCH_TOP_UpdateBackground3, RESEARCH_TOP_ShowBackground3, RESEARCH_TOP_ClearLabels, RESEARCH_TOP_CreateLabels, RESEARCH_TOP_DestroyLabels, RESEARCH_TOP_ClearResources, RESEARCH_TOP_RegisterEntryResources, RESEARCH_TOP_ReleaseEntryResources, RESEARCH_TOP_RegisterCursorResources, RESEARCH_TOP_ReleaseCursorResources, RESEARCH_TOP_ClearUnits, RESEARCH_TOP_CreateUnits, RESEARCH_TOP_DeleteUnits, RESEARCH_TOP_ClearActor, RESEARCH_TOP_CreateActor, RESEARCH_TOP_DeleteActor, RESEARCH_TOP_ClearPaletteAnime, RESEARCH_TOP_CreatePaletteAnime, RESEARCH_TOP_DestroyPaletteAnime, RESEARCH_TOP_BindPaletteAnime, RESEARCH_TOP_RestorePaletteAnime, RESEARCH_TOP_UpdateVBlank, RESEARCH_TOP_RegisterVBlank, RESEARCH_TOP_UnregisterVBlank, RESEARCH_TOP_RestartNetwork
 * address:  0x021B95A0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, ov217_func_021C2E20.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   RESEARCH_COMMON_SetScreen  0x021C09BC  thumb  ov217
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *   ListViewState_Reset  0x021C0DE4  thumb  ov217
 *   ListViewState_Destroy  0x021C0DDC  thumb  ov217
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   sub_020307B0 0x020307B0 arm
 *   sub_020409B4 0x020409B4 arm
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RESEARCH_COMMON_GetPreviousScreen  0x021C09C8  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   GAME_BEACON_PopQuestionnaireUpdated  0x020270E0  thumb
 *   BgTextLabel_SetPalette  0x021C1038  thumb  ov217
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   d_021C3008  0x021C3008  data  a4
 *   d_021C3004  0x021C3004  data  a4
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   d_021C2ED8  0x021C2ED8  data  a4
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_021C2EE0  0x021C2EE0  data  a4
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 *   func_02040DA8  0x02040DA8  arm
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   d_021C2F98 0x021C2F98 data a4
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   d_021C2ED2  0x021C2ED2  data  a4
 *   d_021C2ED0  0x021C2ED0  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021C2EFC 0x021C2EFC data a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   d_021C2FF8  0x021C2FF8  data  a4
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_02005654  0x02005654  thumb
 *   func_020413B0 0x020413B0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_02045B38 0x02045B38 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   FADE_Start  0x0204E720  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   func_02030734  0x02030734  arm
 *   RESEARCH_LIST_Create 0x021BAB80 thumb ov217
 *   RESEARCH_LIST_Destroy 0x021BABB4 thumb ov217
 *   RESEARCH_LIST_Update 0x021BABC4 thumb ov217
 *   RESEARCH_LIST_GetVisible 0x021BAC90 thumb ov217
 *   RESEARCH_LIST_GetActive 0x021BAC98 thumb ov217
 *   RESEARCH_GRAPH_Create 0x021BD5F4 thumb ov217
 *   RESEARCH_GRAPH_Destroy 0x021BD61C thumb ov217
 *   RESEARCH_GRAPH_Update 0x021BD62C thumb ov217
 *   RESEARCH_GRAPH_GetVisible 0x021BD708 thumb ov217
 *   RESEARCH_GRAPH_GetActive 0x021BD710 thumb ov217
 */
#include "../../matched/include/Obj10952.h"
#include "../../matched/include/Obj25801.h"
#include "../../matched/include/Obj25805.h"
#include "research_shared_types.h"

struct DispVram;

struct Obj0203159C;

struct S020315D4;

struct NitroFileHeader;

struct LabelTemplate { u8 params[11]; u32 messageIndex; };

struct LabelEntry { struct LabelTemplate template; u32 messageId; u32 extraId; };

struct ArcMember { u8 pad0[12]; void *data; };

struct CharAnimMember { u8 pad0[0x10]; u32 size; void *data; };

struct ActorSpawnPos { short x, y, z; unsigned char a, b; };

struct ActorSpawnTemplate { struct ActorSpawnPos pos; u32 firstSource, secondSource, thirdSource, fourthSource; u16 arg, pad; };

struct PaletteAnimeBinding { u32 palette, source; u8 mode; u8 pad[11]; };

struct ResearchObjC {
    union { void *owner; u32 ownerHandle; };
    u16 heapId;
    u16 pad6;
    u32 font;
    u32 messages[2];
    u32 commandQueue;
    u32 command;
    u32 commandTimer;
    u32 stateTimer;
    u32 stateTimerLimit;
    u32 selection;
    u8 paletteRows[3][4];
    u32 paletteAnime[5];
    u32 labels[4];
    union {
        struct { u32 cursorCharacter, cursorPalette, cursorCell, entryCharacter, entryPalette, entryCell; };
        u32 resources[6];
    };
    u32 units[2];
    void *actor;
    u32 commandReady;
    u32 questionnaireLatched;
    u32 exitRequested;
    u32 mode;
};

struct ResearchProc {
    u16 heapId;
    u16 pad2;
    union { void *appResource; u32 appResourceU; };
    u32 frameCount;
    u32 common;
    u32 listObject;
    union { u32 graphObject; void *graphObjectP; };
    u32 detailObject;
    u32 listViewState;
};

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_0204363C(u32 swap);

extern void func_020315D4(struct S020315D4 *);

extern u32 func_02012204(const struct Ctx *);

extern void RESEARCH_COMMON_SetInputFlag(void *);

extern u32 WIH_DWC_PollStatus(void *key);

extern void *func_020120F4(const struct Ctx *p);

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern u32 func_0201283C(const struct BigObj *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void RESEARCH_COMMON_SetScreen(void *p, u32 v);

extern int RESEARCH_COMMON_Create(int a0, int a1);

extern u32 RESEARCH_COMMON_Destroy(void *a0);

extern u32 ListViewState_Create(u32 a0);

extern void ListViewState_Reset(void *p);

extern void ListViewState_Destroy(void *a0);

extern void func_0203F8F4(unsigned short heapId);

extern void func_0203FC28(struct DispConfig *cfg);

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 func_0203F9B4();

extern u32 func_020403F4(u32 i);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern int func_02062A98(struct NitroFileHeader *, void **);

extern void func_02040E78(u32, void *, u32, u32);

extern u32 func_020307B0(void *p);

extern int func_02062A4C(struct NitroFileHeader *, void **);

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);

extern int func_02062B30(void *, void **);

extern void func_02041090(u32, u32, u32, u32, u8, u8);

extern int func_020409B4(int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_020413B0(int index, int x0, int y0, int w, int h, int pal);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern u32 sub_020307B0(void *p);

extern void sub_020409B4(u32);

extern u32 RESEARCH_COMMON_GetHeapId(void *);

extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);

extern void CLACT_DrawSystem();

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const void *);

extern void * RESEARCH_COMMON_GetTouchRects(void *);

extern u32 GFL_USE_PlaySeDefaultVolume(u32 a);

extern int FADE_IsActive(void);

extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);

extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);

extern void RingQueue_Push(u32, u32);

extern u32 RingQueue_Pop(struct Ring *r);

extern u32 RingQueue_IsEmpty();

extern u32 RESEARCH_COMMON_GetPreviousScreen(void *p);

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);

extern void BgTextLabel_SetPalette(u8 *p, u8 palette);

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern u32 CLACT_SetActorAnimFrame();

extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);

extern void PALETTE_ANIME_Stop(u32 a0);

extern void PALETTE_ANIME_Update(int);

extern unsigned RESEARCH_COMMON_GetAppResource(void *);

extern u32 func_0201296C(const struct BigObj *p);

extern unsigned ZONEDATA_CheckEventFlag(void *,int);

extern u32 RESEARCH_COMMON_GetInputFlag(void *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern int RingQueue_Create(int a0, int a1);

extern void RingQueue_Destroy(void *p);

extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);

extern void BMP_WIN_Init(u16);

extern void BMP_WIN_Exit(void);

extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);

extern u32 func_020414EC();

extern void func_02040DA8(u32, u32, u32);

extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);

u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);

extern void BgTextLabel_Destroy(u8 *p);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern u32 CLACT_ReleasePalette(u32 i);

extern u32 CLACT_ReleaseCellAnim();

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 PALETTE_ANIME_Create(u32 a0);

extern u32 PALETTE_ANIME_Destroy(void *a0);

extern void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d);

extern int PALETTE_ANIME_Restore(char *p);

extern void CLACT_VBlankSystem(void);

extern int func_02005654(int a, int b);

extern void func_0200566C(void);

u32 RESEARCH_TOP_InitProc(u32 a0, u32 a1, u8 *a2, u32 a3);

u32 RESEARCH_TOP_ReleaseProc(u32 a0, u32 a1, u32 a2, u32 a3);

int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, u32 *p);

void RESEARCH_TOP_UpdateNetwork(u32 a0);

void RESEARCH_TOP_ChangeScreen(void *a, int *p, int c);

void RESEARCH_TOP_CloseSubState(u32 *p, u32 *state);

void RESEARCH_TOP_OpenSubState(u32 *p, u32 *state, u32 kind);

int RESEARCH_TOP_StateIdle(void *a0);

u32 RESEARCH_TOP_StateList(u8 *a0);

u32 RESEARCH_TOP_StateGraph(u32 a0);

u32 RESEARCH_TOP_StateDetail(u32 a0);

u32 RESEARCH_TOP_GetFrameCount(const void *p);

void RESEARCH_TOP_IncFrameCount(void *p);

void RESEARCH_TOP_ResetProc(void *p, u32 value);

void RESEARCH_TOP_CreateCommon(u32 a0);

u32 RESEARCH_TOP_DestroyCommon(u32 a0);

void RESEARCH_TOP_CreateListView(u32 a0);

u32 RESEARCH_TOP_DestroyListView(u32 a0);

void RESEARCH_TOP_InitBackgrounds(unsigned short heapId);

u32 RESEARCH_TOP_ExitBackgrounds(void);

void RESEARCH_TOP_LoadSubAssets(u32 heap);

void RESEARCH_TOP_UpdateFrameGraphic(const void *p);

void RESEARCH_TOP_LoadTopAssets(u32 heap);

u32 RESEARCH_TOP_CreateListObject(void *self);

u32 RESEARCH_TOP_DestroyListObject(void *a0);

void RESEARCH_TOP_UpdateListObject(char *p);

int RESEARCH_TOP_IsListObjectDone(void *p);

u32 RESEARCH_TOP_GetListObjectMode(void *p);

void RESEARCH_TOP_InitListObject(char *p);

void RESEARCH_TOP_HandleListInput(char *p);

void RESEARCH_TOP_HandleListInputAlt(char *p);

void RESEARCH_TOP_AdvanceListScroll(u32 a0);

void RESEARCH_TOP_StepExitFade(u32 a0);

void RESEARCH_TOP_CleanupListObject(u32 a0);

void RESEARCH_TOP_PushCommand(u8 *a0, u32 a1);

void RESEARCH_TOP_SetCommandReady(void *p);

void RESEARCH_TOP_ProcessCommand(u32 a0);

void RESEARCH_TOP_StartCommand(void *p, u32 v);

u32 RESEARCH_TOP_GetCommandTimer(void *p);

void RESEARCH_TOP_IncCommandTimer(void *p);

u32 RESEARCH_TOP_GetTransitionKind(u8 *a0);

void RESEARCH_TOP_SetEntryHandled(u8 *a0, u32 a1);

void RESEARCH_TOP_SetMode(void *p, u32 v);

void RESEARCH_TOP_CheckQuestionnaire(u32 a0);

void RESEARCH_TOP_SelectPrev(u32 a0);

void RESEARCH_TOP_SelectNext(u32 a0);

void RESEARCH_TOP_SelectDirect(u32 a0, u32 a1);

void RESEARCH_TOP_DrawSelector(int sel);

void RESEARCH_TOP_DrawSelectorIdle(int sel);

void RESEARCH_TOP_SetupTextLabel(u32 a0);

void RESEARCH_TOP_StartPaletteAnime(u8 *a0);

u32 RESEARCH_TOP_ShowEntryActor(u32 a0);

void RESEARCH_TOP_FadeIn(void);

void RESEARCH_TOP_FadeOut(void);

void RESEARCH_TOP_IncStateTimer(void *p);

u32 RESEARCH_TOP_GetStateTimer(void *p);

void RESEARCH_TOP_SetStateTimer(void *p, u32 v);

u32 RESEARCH_TOP_GetStateTimerLimit(void *p);

void RESEARCH_TOP_MoveSelection(char *self, int d);

void RESEARCH_TOP_SetSelection(void *p, u32 v);

u32 RESEARCH_TOP_IsSelectionValid(u32 a0, u32 a1);

u32 RESEARCH_TOP_GetEntryActorSource(void *p, u32 i);

u32 RESEARCH_TOP_GetEntryLabelSource(void *p, u32 i);

u32 RESEARCH_TOP_GetEntryIconSource(void *p, u32 i);

void RESEARCH_TOP_StartEntryPaletteAnime(char *self, int i);

void RESEARCH_TOP_StopEntryPaletteAnime(u8 *a0, u32 a1);

void RESEARCH_TOP_UpdateEntryPaletteAnime(int *p);

unsigned char RESEARCH_TOP_CountUnlockedEntries(char *p);

u32 RESEARCH_TOP_GetOwner(void *p);

void RESEARCH_TOP_SetOwner(void *p, u32 v);

void RESEARCH_TOP_SetHeapId(void *p, u32 v);

u32 RESEARCH_TOP_GetInputFlag(void *p);

u32 RESEARCH_TOP_AllocListObject(u32 a0);

u32 RESEARCH_TOP_FreeListObject(void *a0);

void RESEARCH_TOP_InitFields(char *p);

void RESEARCH_TOP_InitSelection(char *p);

void RESEARCH_TOP_ClearFont(void *p);

void RESEARCH_TOP_CreateFont(u32 a0);

void RESEARCH_TOP_DeleteFont(u8 *a0);

void RESEARCH_TOP_ClearMessages(void *p);

void RESEARCH_TOP_CreateMessages(char *self);

void RESEARCH_TOP_DeleteMessages(int *p);

void RESEARCH_TOP_InitPaletteRows(u8 *self);

void RESEARCH_TOP_ClearCommandQueue(void *p);

void RESEARCH_TOP_CreateCommandQueue(u32 a0);

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *p);

void RESEARCH_TOP_InitOverlayBackgrounds(char *p);

void RESEARCH_TOP_ExitOverlayBackgrounds(u32 a0);

void RESEARCH_TOP_LoadBackground6(char *p);

void RESEARCH_TOP_DummyBg7(u32 a0);

u32 RESEARCH_TOP_UpdateBackground7(void *a0);

void RESEARCH_TOP_ShowBackground7(u32 a0);

void RESEARCH_TOP_LoadBackground2(char *p);

void RESEARCH_TOP_DummyBg3(u32 a0);

u32 RESEARCH_TOP_UpdateBackground3(void *a0);

void RESEARCH_TOP_ShowBackground3(u32 a0);

void RESEARCH_TOP_ClearLabels(void *p);

void RESEARCH_TOP_CreateLabels(char *p);

void RESEARCH_TOP_DestroyLabels(int *p);

void RESEARCH_TOP_ClearResources(void *p);

void RESEARCH_TOP_RegisterEntryResources(struct ResearchObjC *p);

u32 RESEARCH_TOP_ReleaseEntryResources(u32 a0);

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p);

u32 RESEARCH_TOP_ReleaseCursorResources(u32 a0);

void RESEARCH_TOP_ClearUnits(void *p);

void RESEARCH_TOP_CreateUnits(char *self);

void RESEARCH_TOP_DeleteUnits(int *p);

void RESEARCH_TOP_ClearActor(void *p);

void RESEARCH_TOP_CreateActor(char *p);

void RESEARCH_TOP_DeleteActor(u8 *a0);

void RESEARCH_TOP_ClearPaletteAnime(void *p);

void RESEARCH_TOP_CreatePaletteAnime(char *p);

void RESEARCH_TOP_DestroyPaletteAnime(int *p);

void RESEARCH_TOP_BindPaletteAnime(char *self);

void RESEARCH_TOP_RestorePaletteAnime(char *self);

void RESEARCH_TOP_UpdateVBlank(void);

void RESEARCH_TOP_RegisterVBlank(void *a0);

void RESEARCH_TOP_UnregisterVBlank(void);

void RESEARCH_TOP_RestartNetwork(u32 a0);

u32 RESEARCH_LIST_Create(u32 a0, u32 a1);

u32 RESEARCH_LIST_Destroy(void *a0);

void RESEARCH_LIST_Update(void *self);

u32 RESEARCH_LIST_GetVisible(void *p);

u32 RESEARCH_LIST_GetActive(void *p);

void *RESEARCH_GRAPH_Create(void *p);

u32 RESEARCH_GRAPH_Destroy(void *a0);

void RESEARCH_GRAPH_Update(unsigned char *p);

u32 RESEARCH_GRAPH_GetVisible(void *p);

u32 RESEARCH_GRAPH_GetActive(void *p);

extern int d_021C2E30;

extern int d_021C2E60;

extern int d_021C2E40;

extern int d_021C2E80;

extern u8 d_021C3008[];

extern u8 d_021C3004[];

extern u32 d_021C2ED8[];

extern u8 d_021C2EE0[];

extern struct DispConfig d_021C2EEC;

extern const struct BgTemplate d_021C2F78,d_021C2F18,d_021C2F38,d_021C2F58;

extern const struct LabelEntry d_021C2F98[];

extern u16 d_021C2ED2[];

extern u8 d_021C2ED0[];

extern const struct ActorSpawnTemplate d_021C2EFC;

extern struct PaletteAnimeBinding d_021C2FF8[];

u32 RESEARCH_TOP_InitProc(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    PROCSYS_AllocProcWork((struct Obj0203159C *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    RESEARCH_TOP_ResetProc((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    func_0204363C(0);
    RESEARCH_TOP_InitBackgrounds(((struct ResearchProc *)a3)->heapId);
    RESEARCH_TOP_LoadTopAssets(((struct ResearchProc *)a3)->heapId);
    RESEARCH_TOP_LoadSubAssets(((struct ResearchProc *)a3)->heapId);
    RESEARCH_TOP_CreateCommon(a3);
    RESEARCH_TOP_CreateListView(a3);
    return 1;
    }
    return 0;
}

u32 RESEARCH_TOP_ReleaseProc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    RESEARCH_TOP_DestroyListView(a3);
    RESEARCH_TOP_DestroyCommon(a3);
    RESEARCH_TOP_ExitBackgrounds();
    func_020315D4((struct S020315D4 *)a0);
    return 1;
}

/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    RESEARCH_TOP_UpdateNetwork((u32)p);
    if (func_02012204((const struct Ctx *)p[1]) != 0)
        RESEARCH_COMMON_SetInputFlag((void *)p[3]);
    switch (*state) {
    case 0: next = RESEARCH_TOP_StateIdle(p); break;
    case 1: next = RESEARCH_TOP_StateList((u8 *)p); break;
    case 2: next = RESEARCH_TOP_StateGraph((u32)p); break;
    case 3: next = RESEARCH_TOP_StateDetail((u32)p); break;
    case 4: return 1;
    }
    RESEARCH_TOP_UpdateFrameGraphic(p);
    RESEARCH_TOP_IncFrameCount(p);
    if (*state != next)
        RESEARCH_TOP_ChangeScreen(p, (int *)state, next);
    return 0;
}

/*
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_UpdateNetwork(u32 a0)
{
    WIH_DWC_PollStatus((void *)func_0201283C(func_020120F4(((struct ResearchProc *)a0)->appResource)));
    if (GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)(*(u32 *)&((struct ResearchProc *)a0)->appResource)) != 0) {
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchProc *)a0)->heapId);
    }
}

void RESEARCH_TOP_ChangeScreen(void *a, int *p, int c)
{
    RESEARCH_TOP_CloseSubState(a, (u32 *)p);
    RESEARCH_TOP_OpenSubState(a, (u32 *)p, c);
    switch (*p) {
    case 1:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 1);
        break;
    case 2:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 2);
        break;
    case 3:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 3);
        break;
    }
}

/*
 * tail: zero halfword alignment at 021B9772.
 */
void RESEARCH_TOP_CloseSubState(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: RESEARCH_TOP_DestroyListObject((void *)p[4]); break;
    case 2: RESEARCH_LIST_Destroy((void *)p[5]); break;
    case 3: RESEARCH_GRAPH_Destroy((void *)p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}

void RESEARCH_TOP_OpenSubState(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = RESEARCH_TOP_CreateListObject((void *)p[3]);
        break;
    case 2:
        p[5] = RESEARCH_LIST_Create(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)RESEARCH_GRAPH_Create((void *)p[3]);
        break;
    }
    *state = kind;
}

int RESEARCH_TOP_StateIdle(void *a0)
{
    return 1;
}

u32 RESEARCH_TOP_StateList(u8 *a0)
{
    RESEARCH_TOP_UpdateListObject((char *)(((struct ResearchProc *)a0)->listObject));
    if (RESEARCH_TOP_IsListObjectDone((void *)(((struct ResearchProc *)a0)->listObject)) != 0) {
    switch (RESEARCH_TOP_GetListObjectMode((void *)(((struct ResearchProc *)a0)->listObject))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}

u32 RESEARCH_TOP_StateGraph(u32 a0)
{
    RESEARCH_LIST_Update((void *)(((struct ResearchProc *)a0)->graphObject));
    if (RESEARCH_LIST_GetVisible((void *)(((struct ResearchProc *)a0)->graphObject)) != 0) {
    if (RESEARCH_LIST_GetActive((void *)(((struct ResearchProc *)a0)->graphObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}

u32 RESEARCH_TOP_StateDetail(u32 a0)
{
    RESEARCH_GRAPH_Update((unsigned char *)(((struct ResearchProc *)a0)->detailObject));
    if (RESEARCH_GRAPH_GetVisible((void *)(((struct ResearchProc *)a0)->detailObject)) != 0) {
    if (RESEARCH_GRAPH_GetActive((void *)(((struct ResearchProc *)a0)->detailObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}

u32 RESEARCH_TOP_GetFrameCount(const void *p)
{
    return *(const u32 *)&((struct ResearchProc *)p)->frameCount;
}

void RESEARCH_TOP_IncFrameCount(void *p)
{
    u32 *counter = (u32 *)((char *)p + 8);
    *counter += 1;
}

void RESEARCH_TOP_ResetProc(void *p, u32 value)
{
    ((struct ResearchProc *)p)->heapId = 1;
    ((struct ResearchProc *)p)->appResourceU = value;
    ((struct ResearchProc *)p)->frameCount = 0;
    ((struct ResearchProc *)p)->common = 0;
    ((struct ResearchProc *)p)->listObject = 0;
    ((struct ResearchProc *)p)->graphObject = 0;
    ((struct ResearchProc *)p)->detailObject = 0;
    ((struct ResearchProc *)p)->listViewState = 0;
}

void RESEARCH_TOP_CreateCommon(u32 a0)
{
    ((struct ResearchProc *)a0)->common = RESEARCH_COMMON_Create(((struct ResearchProc *)a0)->heapId, ((struct ResearchProc *)a0)->appResourceU);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_DestroyCommon(u32 a0)
{
    RESEARCH_COMMON_Destroy((void *)(((struct ResearchProc *)a0)->common));
    ((struct ResearchProc *)a0)->common = 0;
    return 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CreateListView(u32 a0)
{
    u32 r = ListViewState_Create(((struct ResearchProc *)a0)->heapId);
    ((struct ResearchProc *)a0)->listViewState = r;
    ListViewState_Reset((void *)r);
}

u32 RESEARCH_TOP_DestroyListView(u32 a0)
{
    ListViewState_Destroy((void *)(((struct ResearchProc *)a0)->listViewState));
    ((struct ResearchProc *)a0)->listViewState = 0;
    return 0;
}

/*
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 */
void RESEARCH_TOP_InitBackgrounds(unsigned short heapId)
{
    func_0203F8F4(heapId);
    func_0203FC28((struct DispConfig *)(&d_021C2E30));
    func_0203FCA0(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    func_0203FCA0(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}

u32 RESEARCH_TOP_ExitBackgrounds(void)
{
    func_020403F4(1);
    func_020403F4(4);
    return func_0203F9B4();
}

void RESEARCH_TOP_LoadSubAssets(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = ARC_TOOL_LoadHandleMember(arc, 9, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(4, ((struct ArcMember *)palette)->data, 512, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 10, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(4, ((struct CharAnimMember *)character)->data, ((struct CharAnimMember *)character)->size, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 11, heap);
    func_02062B30(buffer, &screen);
    func_02041090(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_020409B4(4);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 12, heap);
    func_02062B30(buffer, &screen2);
    func_02041090(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    func_020409B4(5);
    func_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_UpdateFrameGraphic(const void *p)
{
    u32 t = RESEARCH_TOP_GetFrameCount(p) / 10;
    u32 m = (u8)(t % 6);
    func_020413B0(5, 0, 0, 0x20, 0x18, (u8)m);
    func_020409B4(5);
}

void RESEARCH_TOP_LoadTopAssets(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = ARC_TOOL_CreateHandle(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = ARC_TOOL_LoadHandleMember(arc, 0, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(1, ((struct ArcMember *)palette)->data, 512, 0);
    sub_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 1, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(1, ((struct CharAnimMember *)character)->data, ((struct CharAnimMember *)character)->size, 0);
    sub_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 2, heap);
    func_02062B30(buffer, &screen);
    func_02041090(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    sub_020409B4(1);
    sub_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_CreateListObject(void *self)
{
    u32 v = RESEARCH_COMMON_GetHeapId(self);
    u32 o = RESEARCH_TOP_AllocListObject(v);
    RESEARCH_TOP_InitFields((char *)o);
    RESEARCH_TOP_SetHeapId((void *)o, v);
    RESEARCH_TOP_SetOwner((void *)o, (u32)self);
    return o;
}

u32 RESEARCH_TOP_DestroyListObject(void *a0)
{
    RESEARCH_TOP_DestroyCommandQueue((void *)a0);
    return RESEARCH_TOP_FreeListObject(a0);
}

void RESEARCH_TOP_UpdateListObject(char *p)
{
    switch (((struct ResearchObjC *)p)->command) {
    case 0:RESEARCH_TOP_InitListObject(p);break;
    case 1:RESEARCH_TOP_HandleListInput(p);break;
    case 2:RESEARCH_TOP_HandleListInputAlt(p);break;
    case 3:RESEARCH_TOP_AdvanceListScroll((unsigned)p);break;
    case 4:RESEARCH_TOP_StepExitFade((unsigned)p);break;
    case 5:RESEARCH_TOP_CleanupListObject((unsigned)p);break;
    case 6:return;
    }
    if (RESEARCH_TOP_IsListObjectDone(p)==0) {
        RESEARCH_TOP_CheckQuestionnaire((unsigned)p);RESEARCH_TOP_UpdateEntryPaletteAnime((int *)p);
        RESEARCH_COMMON_UpdatePaletteAnime(*(unsigned *)&((struct ResearchObjC *)p)->owner);CLACT_DrawSystem();
    }
    RESEARCH_TOP_IncStateTimer(p);RESEARCH_TOP_ProcessCommand((unsigned)p);
}

int RESEARCH_TOP_IsListObjectDone(void *p)
{
    if (((struct ResearchObjC *)p)->exitRequested != 0) {
        return 1;
    }
    return 0;
}

/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetListObjectMode(void *p)
{
    return ((struct ResearchObjC *)p)->mode;
}

void RESEARCH_TOP_InitListObject(char *p)
{
    unsigned kind;
    RESEARCH_TOP_CreateCommandQueue((unsigned)p);RESEARCH_TOP_CreateFont((unsigned)p);
    RESEARCH_TOP_CreateMessages(p);RESEARCH_TOP_InitPaletteRows((u8 *)p);RESEARCH_TOP_InitSelection(p);
    RESEARCH_TOP_InitOverlayBackgrounds(p);RESEARCH_TOP_LoadBackground6(p);RESEARCH_TOP_UpdateBackground7(p);
    RESEARCH_TOP_LoadBackground2(p);RESEARCH_TOP_UpdateBackground3(p);RESEARCH_TOP_CreateLabels(p);
    RESEARCH_TOP_RegisterEntryResources((struct ResearchObjC *)p);RESEARCH_TOP_RegisterCursorResources((struct ResearchObjC *)p);
    RESEARCH_TOP_CreateUnits(p);RESEARCH_TOP_CreateActor(p);RESEARCH_TOP_CreatePaletteAnime(p);
    RESEARCH_TOP_BindPaletteAnime(p);RESEARCH_TOP_RestartNetwork((unsigned)p);RESEARCH_TOP_RegisterVBlank(p);
    if (RESEARCH_TOP_IsSelectionValid((unsigned)p,0)==0)RESEARCH_TOP_SetupTextLabel((unsigned)p);
    kind=RESEARCH_TOP_GetTransitionKind((unsigned char *)p);
    RESEARCH_TOP_PushCommand((unsigned char *)p,RESEARCH_TOP_GetTransitionKind((unsigned char *)p));
    if (kind==2) {RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)p)->selection);RESEARCH_TOP_StartEntryPaletteAnime((char *)((unsigned)p),0);}
    RESEARCH_TOP_FadeIn();RESEARCH_TOP_SetCommandReady(p);
}

/*
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 */
void RESEARCH_TOP_HandleListInput(char *p)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)p)->owner));
    if(RESEARCH_TOP_GetInputFlag(p)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);return;
    }
    if(keys&2) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,0);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)p)->selection);RESEARCH_TOP_StartEntryPaletteAnime(p,0);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,2);return;
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,0)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SetMode(p,0);RESEARCH_TOP_SelectDirect((u32)p,0);RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)p)->selection);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,1)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SetMode(p,1);RESEARCH_TOP_SelectDirect((u32)p,1);RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)p)->selection);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    }
}

void RESEARCH_TOP_HandleListInputAlt(char *p)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)p)->owner));
    if(RESEARCH_TOP_GetInputFlag(p)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);return;
    }
    if(keys&64)RESEARCH_TOP_SelectPrev((u32)p);
    if(keys&128)RESEARCH_TOP_SelectNext((u32)p);
    if(keys&1) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        switch(((struct ResearchObjC *)p)->selection) {
        case 0:RESEARCH_TOP_SetMode(p,0);return;
        case 1:RESEARCH_TOP_SetMode(p,1);return;
        default:RESEARCH_TOP_SetMode(p,2);return;
        }
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,0)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SelectDirect((u32)p,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(p,0);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,1)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SelectDirect((u32)p,1);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(p,1);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(keys&2) {
        RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
    }
}

/*
 * Steps the record through RESEARCH_TOP_SetCommandReady while the running count is below
 * RESEARCH_TOP_GetStateTimer().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_AdvanceListScroll(u32 a0)
{
    u32 v1 = RESEARCH_TOP_GetStateTimerLimit((void *)a0);
    if (v1 < RESEARCH_TOP_GetStateTimer((void *)a0)) {
    RESEARCH_TOP_SetCommandReady((void *)a0);
    }
}

void RESEARCH_TOP_StepExitFade(u32 a0)
{
    switch (RESEARCH_TOP_GetCommandTimer((void *)a0)) {
    case 0:
    RESEARCH_TOP_FadeOut();
    RESEARCH_TOP_IncCommandTimer((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_TOP_SetCommandReady((void *)a0);
    }
    break;
    }
}

void RESEARCH_TOP_CleanupListObject(u32 a0)
{
    RESEARCH_TOP_UnregisterVBlank();
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjC *)a0)->owner);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjC *)a0)->owner);
    RESEARCH_TOP_RestorePaletteAnime((char *)a0);
    RESEARCH_TOP_DestroyPaletteAnime((int *)a0);
    RESEARCH_TOP_DeleteActor((u8 *)a0);
    RESEARCH_TOP_DeleteUnits((int *)a0);
    RESEARCH_TOP_ReleaseEntryResources(a0);
    RESEARCH_TOP_ReleaseCursorResources(a0);
    RESEARCH_TOP_DestroyLabels((int *)a0);
    RESEARCH_TOP_ShowBackground3(a0);
    RESEARCH_TOP_DummyBg3(a0);
    RESEARCH_TOP_ShowBackground7(a0);
    RESEARCH_TOP_DummyBg7(a0);
    RESEARCH_TOP_ExitOverlayBackgrounds(a0);
    RESEARCH_TOP_DeleteMessages((int *)a0);
    RESEARCH_TOP_DeleteFont((u8 *)a0);
    ((struct ResearchObjC *)a0)->exitRequested = 1;
    RESEARCH_TOP_PushCommand((u8 *)a0, 6);
    RESEARCH_TOP_SetCommandReady((void *)a0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_PushCommand(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchObjC *)a0)->commandQueue), a1);
}

void RESEARCH_TOP_SetCommandReady(void *p)
{
    ((struct ResearchObjC *)p)->commandReady = 1;
}

void RESEARCH_TOP_ProcessCommand(u32 a0)
{
    if (((struct ResearchObjC *)a0)->commandReady != 0) {
    if (RingQueue_IsEmpty(((struct ResearchObjC *)a0)->commandQueue) == 0) {
    RESEARCH_TOP_StartCommand((void *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchObjC *)a0)->commandQueue)));
    }
    }
}

/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StartCommand(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->command = v;
    ((struct ResearchObjC *)p)->commandTimer = 0;
    ((struct ResearchObjC *)p)->stateTimer = 0;
    ((struct ResearchObjC *)p)->commandReady = 0;
}

u32 RESEARCH_TOP_GetCommandTimer(void *p)
{
    return ((struct ResearchObjC *)p)->commandTimer;
}

void RESEARCH_TOP_IncCommandTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x1c);
    *c += 1;
}

u32 RESEARCH_TOP_GetTransitionKind(u8 *a0)
{
    u32 v = ((struct ResearchObjC *)a0)->ownerHandle;
    u32 a = RESEARCH_COMMON_GetPreviousScreen((void *)v);
    u32 b = RESEARCH_COMMON_GetEntryHandled((void *)v);
    if (a != 0 && b == 0) {
    return 2;
    }
    return 1;
}

void RESEARCH_TOP_SetEntryHandled(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchObjC *)a0)->owner, a1);
}

void RESEARCH_TOP_SetMode(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->mode = v;
}

/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CheckQuestionnaire(u32 a0)
{
    if (((struct ResearchObjC *)a0)->questionnaireLatched == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    ((struct ResearchObjC *)a0)->questionnaireLatched = 1;
    RESEARCH_TOP_ShowEntryActor(a0);
    }
    }
}

void RESEARCH_TOP_SelectPrev(u32 a0)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)a0)->selection);
    RESEARCH_TOP_MoveSelection((char *)a0, -1);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)a0)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)a0, 1);
}

void RESEARCH_TOP_SelectNext(u32 a0)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)a0)->selection);
    RESEARCH_TOP_MoveSelection((char *)a0, 1);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)a0)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)a0, 1);
}

void RESEARCH_TOP_SelectDirect(u32 a0, u32 a1)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)a0)->selection);
    RESEARCH_TOP_SetSelection((void *)a0, a1);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)a0)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)a0, 1);
}

void RESEARCH_TOP_DrawSelector(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 0xa;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 0xa;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}

void RESEARCH_TOP_DrawSelectorIdle(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}

void RESEARCH_TOP_SetupTextLabel(u32 a0)
{
    BgTextLabel_SetPalette((u8 *)(((struct ResearchObjC *)a0)->labels[2]), 15);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)a0, 3);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)a0, 4);
}

void RESEARCH_TOP_StartPaletteAnime(u8 *a0)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(((struct ResearchObjC *)a0)->ownerHandle), 0);
}

u32 RESEARCH_TOP_ShowEntryActor(u32 a0)
{
    u32 v1 = RESEARCH_TOP_GetEntryIconSource((void *)a0, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnim((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)v1, 4096);
    return CLACT_SetActorAnimFrame(v1, 0);
}

void RESEARCH_TOP_FadeIn(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void RESEARCH_TOP_FadeOut(void)
{
    FADE_Start(3, 0, 16, 0);
}

void RESEARCH_TOP_IncStateTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}

u32 RESEARCH_TOP_GetStateTimer(void *p)
{
    return ((struct ResearchObjC *)p)->stateTimer;
}

/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetStateTimer(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->stateTimerLimit = v;
}

u32 RESEARCH_TOP_GetStateTimerLimit(void *p)
{
    return ((struct ResearchObjC *)p)->stateTimerLimit;
}

void RESEARCH_TOP_MoveSelection(char *self, int d)
{
    int n = *(int *)&((struct ResearchObjC *)self)->selection;
    do {
        n = (n + d + 2) % 2;
    } while (!RESEARCH_TOP_IsSelectionValid((u32)self, n));
    *(int *)&((struct ResearchObjC *)self)->selection = n;
}

/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetSelection(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->selection = v;
}

u32 RESEARCH_TOP_IsSelectionValid(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (RESEARCH_TOP_CountUnlockedEntries((char *)a0) > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}

/*
 * Indexed u32 read: element i of the table at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetEntryActorSource(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x5c);
}

/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetEntryLabelSource(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x74);
}

/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetEntryIconSource(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x7c);
}

void RESEARCH_TOP_StartEntryPaletteAnime(char *self, int i)
{
    PALETTE_ANIME_Start(*(void **)(self + i * 4 + 0x38),
                  *(u32 *)(d_021C3004 + i * 0x14),
                  *(u16 *)(d_021C3008 + i * 0x14));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StopEntryPaletteAnime(u8 *a0, u32 a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 56)));
}

void RESEARCH_TOP_UpdateEntryPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Update(p[i + 0x0E]);
}

/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char RESEARCH_TOP_CountUnlockedEntries(char *p)
{
    void *bitmap=(void *)func_0201296C((const struct BigObj *)RESEARCH_COMMON_GetAppResource(((struct ResearchObjC *)p)->owner));
    int count=1;
    if(ZONEDATA_CheckEventFlag(bitmap,240)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,241)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,242)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,243)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,244)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,245)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,246)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,247)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,248)==1)count++;
    return count;
}

u32 RESEARCH_TOP_GetOwner(void *p)
{
    return ((struct ResearchObjC *)p)->ownerHandle;
}

void RESEARCH_TOP_SetOwner(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->ownerHandle = v;
}

/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetHeapId(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->heapId = v;
}

u32 RESEARCH_TOP_GetInputFlag(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_TOP_GetOwner(p));
}

u32 RESEARCH_TOP_AllocListObject(u32 a0)
{
    return (u32)func_02030734(a0, 144, 0, (const char *)0x21C3FEC, 1486);
}

u32 RESEARCH_TOP_FreeListObject(void *a0)
{
    return func_020307B0(a0);
}

/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void RESEARCH_TOP_InitFields(char *p)
{
    ((struct ResearchObjC *)p)->commandReady=0;((struct ResearchObjC *)p)->questionnaireLatched=0;((struct ResearchObjC *)p)->exitRequested=0;
    ((struct ResearchObjC *)p)->command=0;((struct ResearchObjC *)p)->stateTimer=0;((struct ResearchObjC *)p)->stateTimerLimit=0;
    ((struct ResearchObjC *)p)->selection=0;((struct ResearchObjC *)p)->mode=2;((struct ResearchObjC *)p)->commandTimer=0;
    RESEARCH_TOP_ClearResources(p);RESEARCH_TOP_ClearCommandQueue(p);RESEARCH_TOP_ClearMessages(p);RESEARCH_TOP_ClearFont(p);
    RESEARCH_TOP_ClearLabels(p);RESEARCH_TOP_ClearUnits(p);RESEARCH_TOP_ClearActor(p);RESEARCH_TOP_ClearPaletteAnime(p);
}

void RESEARCH_TOP_InitSelection(char *p)
{
    void *owner=((struct ResearchObjC *)p)->owner;
    unsigned a=RESEARCH_COMMON_GetPreviousScreen(owner),b=RESEARCH_COMMON_GetEntryHandled(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        RESEARCH_TOP_SetSelection(p,mode);
    } else {
        if(RESEARCH_TOP_IsSelectionValid((unsigned)p,0)!=0) RESEARCH_TOP_SetSelection(p,0);
        else RESEARCH_TOP_SetSelection(p,1);
    }
}

void RESEARCH_TOP_ClearFont(void *p)
{
    ((struct ResearchObjC *)p)->font = 0;
}

void RESEARCH_TOP_CreateFont(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjC *)a0)->font = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjC *)a0)->heapId));
}

void RESEARCH_TOP_DeleteFont(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjC *)a0)->font)));
}

/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearMessages(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}

void RESEARCH_TOP_CreateMessages(char *self)
{
    int i = 0;
    do {
        int o = i * 4;
        *(u32 *)(self + o + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + o)), (u16)(((struct ResearchObjC *)self)->heapId));
        i++;
    } while (i < 2);
}

void RESEARCH_TOP_DeleteMessages(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)p[i + 3]);
}

void RESEARCH_TOP_InitPaletteRows(u8 *self)
{
    int i = 0;
    do {
        int o = i * 4;
        u8 *t = d_021C2EE0 + o;
        self[o + 0x2e] = t[0];
        self[o + 0x2f] = t[1];
        self[o + 0x2c] = t[2];
        self[o + 0x2d] = t[3];
        i++;
    } while (i < 3);
}

void RESEARCH_TOP_ClearCommandQueue(void *p)
{
    ((struct ResearchObjC *)p)->commandQueue = 0;
}

void RESEARCH_TOP_CreateCommandQueue(u32 a0)
{
    ((struct ResearchObjC *)a0)->commandQueue = RingQueue_Create(10, ((struct ResearchObjC *)a0)->heapId);
}

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *p)
{
    RingQueue_Destroy((void *)p->commandQueue);
}

void RESEARCH_TOP_InitOverlayBackgrounds(char *p)
{
    func_0203FC28(&d_021C2EEC);
    func_0203FCA0(6,&d_021C2F78,0);func_0203FCA0(7,&d_021C2F18,0);
    func_0203FCA0(2,&d_021C2F38,0);func_0203FCA0(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    BMP_WIN_Init(((struct ResearchObjC *)p)->heapId);
}

void RESEARCH_TOP_ExitOverlayBackgrounds(u32 a0)
{
    BMP_WIN_Exit();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    func_020403F4(6);
}

void RESEARCH_TOP_LoadBackground6(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,13,((struct ResearchObjC *)p)->heapId);
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg7(u32 a0)
{
}

u32 RESEARCH_TOP_UpdateBackground7(void *a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}

void RESEARCH_TOP_ShowBackground7(u32 a0)
{
    func_02040DA8(7, 1, 0);
}

void RESEARCH_TOP_LoadBackground2(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,4,((struct ResearchObjC *)p)->heapId);
    void *data;
    func_02062B30(file,&data);
    func_02041090(2,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(2);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg3(u32 a0)
{
}

u32 RESEARCH_TOP_UpdateBackground3(void *a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}

void RESEARCH_TOP_ShowBackground3(u32 a0)
{
    func_02040DA8(3, 1, 0);
}

void RESEARCH_TOP_ClearLabels(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x4c) = 0;
}

void RESEARCH_TOP_CreateLabels(char *p)
{
    struct LabelTemplate tmpl;
    int i;
    for(i=0;i<4;i++) {
        const struct LabelEntry *s=&d_021C2F98[i];
        tmpl.params[0]=s->template.params[0];tmpl.params[1]=s->template.params[1];tmpl.params[2]=s->template.params[2];tmpl.params[3]=s->template.params[3];
        tmpl.params[4]=s->template.params[4];tmpl.params[5]=s->template.params[5];tmpl.params[6]=s->template.params[6];tmpl.params[7]=s->template.params[7];
        tmpl.params[8]=s->template.params[8];tmpl.params[9]=s->template.params[9];tmpl.params[10]=s->template.params[10];tmpl.messageIndex=s->extraId;
        *(unsigned *)(p+i*4+0x4c)=(unsigned int)BgTextLabel_Create((const struct Config *)(&tmpl),((struct ResearchObjC *)p)->font,*(unsigned *)(p+s->template.messageIndex*4+0xc),((struct ResearchObjC *)p)->heapId);
        BgTextLabel_PrintMessage(*(unsigned *)(p+i*4+0x4c),s->messageId);
    }
}

void RESEARCH_TOP_DestroyLabels(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        BgTextLabel_Destroy((u8 *)p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}

/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearResources(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x5c) = 0;
}

/*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
void RESEARCH_TOP_RegisterEntryResources(struct ResearchObjC *p)
{
    u16 heap=p->heapId;
    void *arc=func_020490F4(192,heap);
    int a=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,1,heap);
    int b=CLACT_RegisterPalette((void *)arc,16,1,0,heap);
    int c=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->entryCharacter=a;p->entryPalette=b;p->entryCell=c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_ReleaseEntryResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)a0)->entryCharacter);
    CLACT_ReleasePalette(((struct ResearchObjC *)a0)->entryPalette);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)a0)->entryCell);
}

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p)
{
    u16 heap=p->heapId;
    void *arc=func_020490F4(192,heap);
    int a=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,0,heap);
    int b=CLACT_RegisterPaletteEx((void *)((unsigned)arc),16,0,192,0,4,heap);
    int c=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->cursorCharacter=a;p->cursorPalette=b;p->cursorCell=c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_ReleaseCursorResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)a0)->cursorCharacter);
    CLACT_ReleasePalette(((struct ResearchObjC *)a0)->cursorPalette);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)a0)->cursorCell);
}

void RESEARCH_TOP_ClearUnits(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x74) = 0;
}

void RESEARCH_TOP_CreateUnits(char *self)
{
    int i = 0;
    do {
        *(u32 *)(self + i * 4 + 0x74) = (u32)CLACT_CreateUnit(d_021C2ED2[i], d_021C2ED0[i], ((struct ResearchObjC *)self)->heapId);
        i++;
    } while (i < 2);
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_DeleteUnits(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0x1D]);
}

/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearActor(void *p)
{
    ((struct ResearchObjC *)p)->actor = 0;
}

/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void RESEARCH_TOP_CreateActor(char *p)
{
    struct ActorSpawnPos pos;
    unsigned first,second,third,fourth;
    pos.x=d_021C2EFC.pos.x;pos.y=d_021C2EFC.pos.y;pos.z=d_021C2EFC.pos.z;
    pos.a=d_021C2EFC.pos.a;pos.b=d_021C2EFC.pos.b;
    first=RESEARCH_TOP_GetEntryLabelSource(p,d_021C2EFC.firstSource);
    second=RESEARCH_TOP_GetEntryActorSource(p,d_021C2EFC.secondSource);
    third=RESEARCH_TOP_GetEntryActorSource(p,d_021C2EFC.thirdSource);
    fourth=RESEARCH_TOP_GetEntryActorSource(p,d_021C2EFC.fourthSource);
    *(unsigned *)&((struct ResearchObjC *)p)->actor=(unsigned)CLACT_CreateActor((void *)first,second,third,fourth,&pos,d_021C2EFC.arg,((struct ResearchObjC *)p)->heapId);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ResearchObjC *)p)->actor,0);
}

void RESEARCH_TOP_DeleteActor(u8 *a0)
{
    CLACT_DeleteActor((struct Obj *)((u32)(((struct ResearchObjC *)a0)->actor)));
}

/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearPaletteAnime(void *p)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)p + i * 4 + 0x38) = 0;
}

void RESEARCH_TOP_CreatePaletteAnime(char *p)
{
    int i;
    for (i = 0; i < 5; i++)
        ((int *)(p + 0x38))[i] = PALETTE_ANIME_Create(((struct ResearchObjC *)p)->heapId);
}

void RESEARCH_TOP_DestroyPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0x0E]);
}

void RESEARCH_TOP_BindPaletteAnime(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Bind((void *)(*(int *)(self + i * 4 + 0x38)), d_021C2FF8[i].palette, d_021C2FF8[i].source, d_021C2FF8[i].mode);
    }
}

void RESEARCH_TOP_RestorePaletteAnime(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Restore((char *)(*(int *)(self + i * 4 + 0x38)));
    }
}

/*
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for RESEARCH_TOP_RegisterVBlank (pkt_021B9850).
 */
void RESEARCH_TOP_UpdateVBlank(void)
{
    CLACT_VBlankSystem();
}

void RESEARCH_TOP_RegisterVBlank(void *a0)
{
    func_02005654((int)RESEARCH_TOP_UpdateVBlank, 0);
}

/*
 * Tail-call veneer: branch to func_0200566C.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_UnregisterVBlank(void)
{
    func_0200566C();
}

void RESEARCH_TOP_RestartNetwork(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchObjC *)a0)->heapId);
}
