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
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   RESEARCH_COMMON_SetScreen  0x021C09BC  thumb  ov217
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *   ListViewState_Reset  0x021C0DE4  thumb  ov217
 *   ListViewState_Destroy  0x021C0DDC  thumb  ov217
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   NNS_G2dGetUnpackedCharacterDataEx 0x02062A4C arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
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
 *   GAME_DATA_GetEventWork 0x0201296C thumb
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
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
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
 *   BG_SYS_FillTileMap 0x020413B0 arm
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
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_Init  0x02040C14  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *   BMP_SetDisplaySwap  0x0204363C  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 */
#include "research_shared_types.h"

struct DispVram;

struct Proc;

struct Proc;

struct NitroFileHeader;

/* The process callback's subSeq counter (procsys.c passes &proc->subSeq). */
struct ProcSubSeq { u32 subSeq; };

/* The caller argument buffer; the first word is the app resource handle. */
struct ProcArg { u32 appResource; };

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

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BMP_SetDisplaySwap(u32 swap);

extern void func_020315D4(struct Proc *);

extern u32 ICA_ANIME_GetUnk330(const struct Ctx *);

extern void RESEARCH_COMMON_SetInputFlag(void *);

extern u32 WIH_DWC_PollStatus(void *key);

extern void *ICA_ANIME_GetField1C(const struct Ctx *p);

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void RESEARCH_COMMON_SetScreen(void *p, u32 v);

extern int RESEARCH_COMMON_Create(int a0, int a1);

extern u32 RESEARCH_COMMON_Destroy(void *a0);

extern u32 ListViewState_Create(u32 a0);

extern void ListViewState_Reset(void *p);

extern void ListViewState_Destroy(void *a0);

extern void BG_SYS_Create(unsigned short heapId);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 BG_SYS_Delete();

extern u32 BG_SYS_FreeLayerBuf(u32 i);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *, void **);

extern void BG_SYS_LoadPltt(u32, void *, u32, u32);

extern u32 func_020307B0(void *p);

extern int NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *, void **);

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

extern int NNS_G2dGetUnpackedScreenData(void *, void **);

extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);


extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_FillTileMap(int index, int x0, int y0, int w, int h, int pal);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern u32 GFL_HEAP_Free(void *p);

extern void BG_SYS_PushTile(u32);

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

extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);

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

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern u32 BG_SYS_ClearSlot();

extern void BG_SYS_SetTileUnit(u32, u32, u32);

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

u32 RESEARCH_TOP_InitProc(u32 procsys, u32 state, u8 *work, u32 proc);

u32 RESEARCH_TOP_ReleaseProc(u32 procsys, u32 unused1, u32 unused2, u32 proc);

int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, u32 *proc);

void RESEARCH_TOP_UpdateNetwork(u32 proc);

void RESEARCH_TOP_ChangeScreen(void *proc, int *state, int nextState);

void RESEARCH_TOP_CloseSubState(u32 *proc, u32 *state);

void RESEARCH_TOP_OpenSubState(u32 *proc, u32 *state, u32 kind);

int RESEARCH_TOP_StateIdle(void *proc);

u32 RESEARCH_TOP_StateList(u8 *proc);

u32 RESEARCH_TOP_StateGraph(u32 proc);

u32 RESEARCH_TOP_StateDetail(u32 proc);

u32 RESEARCH_TOP_GetFrameCount(const void *proc);

void RESEARCH_TOP_IncFrameCount(void *proc);

void RESEARCH_TOP_ResetProc(void *proc, u32 appResource);

void RESEARCH_TOP_CreateCommon(u32 proc);

u32 RESEARCH_TOP_DestroyCommon(u32 proc);

void RESEARCH_TOP_CreateListView(u32 proc);

u32 RESEARCH_TOP_DestroyListView(u32 proc);

void RESEARCH_TOP_InitBackgrounds(unsigned short heapId);

u32 RESEARCH_TOP_ExitBackgrounds(void);

void RESEARCH_TOP_LoadSubAssets(u32 heap);

void RESEARCH_TOP_UpdateFrameGraphic(const void *proc);

void RESEARCH_TOP_LoadTopAssets(u32 heap);

u32 RESEARCH_TOP_CreateListObject(void *owner);

u32 RESEARCH_TOP_DestroyListObject(void *obj);

void RESEARCH_TOP_UpdateListObject(char *obj);

int RESEARCH_TOP_IsListObjectDone(void *obj);

u32 RESEARCH_TOP_GetListObjectMode(void *obj);

void RESEARCH_TOP_InitListObject(char *obj);

void RESEARCH_TOP_HandleListInput(char *obj);

void RESEARCH_TOP_HandleListInputAlt(char *obj);

void RESEARCH_TOP_AdvanceListScroll(u32 obj);

void RESEARCH_TOP_StepExitFade(u32 obj);

void RESEARCH_TOP_CleanupListObject(u32 obj);

void RESEARCH_TOP_PushCommand(u8 *obj, u32 command);

void RESEARCH_TOP_SetCommandReady(void *obj);

void RESEARCH_TOP_ProcessCommand(u32 obj);

void RESEARCH_TOP_StartCommand(void *obj, u32 command);

u32 RESEARCH_TOP_GetCommandTimer(void *obj);

void RESEARCH_TOP_IncCommandTimer(void *obj);

u32 RESEARCH_TOP_GetTransitionKind(u8 *obj);

void RESEARCH_TOP_SetEntryHandled(u8 *obj, u32 handled);

void RESEARCH_TOP_SetMode(void *obj, u32 mode);

void RESEARCH_TOP_CheckQuestionnaire(u32 obj);

void RESEARCH_TOP_SelectPrev(u32 obj);

void RESEARCH_TOP_SelectNext(u32 obj);

void RESEARCH_TOP_SelectDirect(u32 obj, u32 selection);

void RESEARCH_TOP_DrawSelector(int selection);

void RESEARCH_TOP_DrawSelectorIdle(int selection);

void RESEARCH_TOP_SetupTextLabel(u32 obj);

void RESEARCH_TOP_StartPaletteAnime(u8 *obj);

u32 RESEARCH_TOP_ShowEntryActor(u32 obj);

void RESEARCH_TOP_FadeIn(void);

void RESEARCH_TOP_FadeOut(void);

void RESEARCH_TOP_IncStateTimer(void *obj);

u32 RESEARCH_TOP_GetStateTimer(void *obj);

void RESEARCH_TOP_SetStateTimer(void *obj, u32 limit);

u32 RESEARCH_TOP_GetStateTimerLimit(void *obj);

void RESEARCH_TOP_MoveSelection(char *obj, int delta);

void RESEARCH_TOP_SetSelection(void *obj, u32 selection);

u32 RESEARCH_TOP_IsSelectionValid(u32 obj, u32 selection);

u32 RESEARCH_TOP_GetEntryActorSource(void *obj, u32 index);

u32 RESEARCH_TOP_GetEntryLabelSource(void *obj, u32 index);

u32 RESEARCH_TOP_GetEntryIconSource(void *obj, u32 index);

void RESEARCH_TOP_StartEntryPaletteAnime(char *obj, int slot);

void RESEARCH_TOP_StopEntryPaletteAnime(u8 *obj, u32 slot);

void RESEARCH_TOP_UpdateEntryPaletteAnime(int *obj);

unsigned char RESEARCH_TOP_CountUnlockedEntries(char *obj);

u32 RESEARCH_TOP_GetOwner(void *obj);

void RESEARCH_TOP_SetOwner(void *obj, u32 owner);

void RESEARCH_TOP_SetHeapId(void *obj, u32 heapId);

u32 RESEARCH_TOP_GetInputFlag(void *obj);

u32 RESEARCH_TOP_AllocListObject(u32 heapId);

u32 RESEARCH_TOP_FreeListObject(void *obj);

void RESEARCH_TOP_InitFields(char *obj);

void RESEARCH_TOP_InitSelection(char *obj);

void RESEARCH_TOP_ClearFont(void *obj);

void RESEARCH_TOP_CreateFont(u32 obj);

void RESEARCH_TOP_DeleteFont(u8 *obj);

void RESEARCH_TOP_ClearMessages(void *obj);

void RESEARCH_TOP_CreateMessages(char *obj);

void RESEARCH_TOP_DeleteMessages(int *obj);

void RESEARCH_TOP_InitPaletteRows(u8 *obj);

void RESEARCH_TOP_ClearCommandQueue(void *obj);

void RESEARCH_TOP_CreateCommandQueue(u32 obj);

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *obj);

void RESEARCH_TOP_InitOverlayBackgrounds(char *obj);

void RESEARCH_TOP_ExitOverlayBackgrounds(u32 obj);

void RESEARCH_TOP_LoadBackground6(char *obj);

void RESEARCH_TOP_DummyBg7(u32 unused);

u32 RESEARCH_TOP_UpdateBackground7(void *obj);

void RESEARCH_TOP_ShowBackground7(u32 obj);

void RESEARCH_TOP_LoadBackground2(char *obj);

void RESEARCH_TOP_DummyBg3(u32 unused);

u32 RESEARCH_TOP_UpdateBackground3(void *obj);

void RESEARCH_TOP_ShowBackground3(u32 obj);

void RESEARCH_TOP_ClearLabels(void *obj);

void RESEARCH_TOP_CreateLabels(char *obj);

void RESEARCH_TOP_DestroyLabels(int *obj);

void RESEARCH_TOP_ClearResources(void *obj);

void RESEARCH_TOP_RegisterEntryResources(struct ResearchObjC *p);

u32 RESEARCH_TOP_ReleaseEntryResources(u32 obj);

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p);

u32 RESEARCH_TOP_ReleaseCursorResources(u32 obj);

void RESEARCH_TOP_ClearUnits(void *obj);

void RESEARCH_TOP_CreateUnits(char *obj);

void RESEARCH_TOP_DeleteUnits(int *obj);

void RESEARCH_TOP_ClearActor(void *obj);

void RESEARCH_TOP_CreateActor(char *obj);

void RESEARCH_TOP_DeleteActor(u8 *obj);

void RESEARCH_TOP_ClearPaletteAnime(void *obj);

void RESEARCH_TOP_CreatePaletteAnime(char *obj);

void RESEARCH_TOP_DestroyPaletteAnime(int *obj);

void RESEARCH_TOP_BindPaletteAnime(char *obj);

void RESEARCH_TOP_RestorePaletteAnime(char *obj);

void RESEARCH_TOP_UpdateVBlank(void);

void RESEARCH_TOP_RegisterVBlank(void *obj);

void RESEARCH_TOP_UnregisterVBlank(void);

void RESEARCH_TOP_RestartNetwork(u32 obj);

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

u32 RESEARCH_TOP_InitProc(u32 procsys, u32 state, u8 *work, u32 proc)
{
    switch (((struct ProcSubSeq *)((u8*)state))->subSeq) {
    case 0:
    PROCSYS_AllocProcWork((struct Proc *)procsys, 32, 1);
    ((struct ProcSubSeq *)((u8*)state))->subSeq = (u32)(((struct ProcSubSeq *)((u8*)state))->subSeq + 1);
    break;
    case 1:
    RESEARCH_TOP_ResetProc((void *)proc, ((struct ProcArg *)((u8*)work))->appResource);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    BMP_SetDisplaySwap(0);
    RESEARCH_TOP_InitBackgrounds(((struct ResearchProc *)proc)->heapId);
    RESEARCH_TOP_LoadTopAssets(((struct ResearchProc *)proc)->heapId);
    RESEARCH_TOP_LoadSubAssets(((struct ResearchProc *)proc)->heapId);
    RESEARCH_TOP_CreateCommon(proc);
    RESEARCH_TOP_CreateListView(proc);
    return 1;
    }
    return 0;
}

u32 RESEARCH_TOP_ReleaseProc(u32 procsys, u32 unused1, u32 unused2, u32 proc)
{
    RESEARCH_TOP_DestroyListView(proc);
    RESEARCH_TOP_DestroyCommon(proc);
    RESEARCH_TOP_ExitBackgrounds();
    func_020315D4((struct Proc *)procsys);
    return 1;
}

/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, u32 *proc)
{
    u32 next;
    RESEARCH_TOP_UpdateNetwork((u32)proc);
    if (ICA_ANIME_GetUnk330((const struct Ctx *)proc[1]) != 0)
        RESEARCH_COMMON_SetInputFlag((void *)proc[3]);
    switch (*state) {
    case 0: next = RESEARCH_TOP_StateIdle(proc); break;
    case 1: next = RESEARCH_TOP_StateList((u8 *)proc); break;
    case 2: next = RESEARCH_TOP_StateGraph((u32)proc); break;
    case 3: next = RESEARCH_TOP_StateDetail((u32)proc); break;
    case 4: return 1;
    }
    RESEARCH_TOP_UpdateFrameGraphic(proc);
    RESEARCH_TOP_IncFrameCount(proc);
    if (*state != next)
        RESEARCH_TOP_ChangeScreen(proc, (int *)state, next);
    return 0;
}

/*
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_UpdateNetwork(u32 proc)
{
    WIH_DWC_PollStatus((void *)GAME_DATA_GetField1A0(ICA_ANIME_GetField1C(((struct ResearchProc *)proc)->appResource)));
    if (GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)(*(u32 *)&((struct ResearchProc *)proc)->appResource)) != 0) {
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchProc *)proc)->heapId);
    }
}

void RESEARCH_TOP_ChangeScreen(void *proc, int *state, int nextState)
{
    RESEARCH_TOP_CloseSubState(proc, (u32 *)state);
    RESEARCH_TOP_OpenSubState(proc, (u32 *)state, nextState);
    switch (*state) {
    case 1:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)proc + 0xc)), 1);
        break;
    case 2:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)proc + 0xc)), 2);
        break;
    case 3:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)proc + 0xc)), 3);
        break;
    }
}

/*
 * tail: zero halfword alignment at 021B9772.
 */
void RESEARCH_TOP_CloseSubState(u32 *proc, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: RESEARCH_TOP_DestroyListObject((void *)proc[4]); break;
    case 2: RESEARCH_LIST_Destroy((void *)proc[5]); break;
    case 3: RESEARCH_GRAPH_Destroy((void *)proc[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: proc[4] = 0; break;
    case 2: proc[5] = 0; break;
    case 3: proc[6] = 0; break;
    }
}

void RESEARCH_TOP_OpenSubState(u32 *proc, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        proc[4] = RESEARCH_TOP_CreateListObject((void *)proc[3]);
        break;
    case 2:
        proc[5] = RESEARCH_LIST_Create(proc[3], proc[7]);
        break;
    case 3:
        proc[6] = (u32)RESEARCH_GRAPH_Create((void *)proc[3]);
        break;
    }
    *state = kind;
}

int RESEARCH_TOP_StateIdle(void *proc)
{
    return 1;
}

u32 RESEARCH_TOP_StateList(u8 *proc)
{
    RESEARCH_TOP_UpdateListObject((char *)(((struct ResearchProc *)proc)->listObject));
    if (RESEARCH_TOP_IsListObjectDone((void *)(((struct ResearchProc *)proc)->listObject)) != 0) {
    switch (RESEARCH_TOP_GetListObjectMode((void *)(((struct ResearchProc *)proc)->listObject))) {
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

u32 RESEARCH_TOP_StateGraph(u32 proc)
{
    RESEARCH_LIST_Update((void *)(((struct ResearchProc *)proc)->graphObject));
    if (RESEARCH_LIST_GetVisible((void *)(((struct ResearchProc *)proc)->graphObject)) != 0) {
    if (RESEARCH_LIST_GetActive((void *)(((struct ResearchProc *)proc)->graphObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}

u32 RESEARCH_TOP_StateDetail(u32 proc)
{
    RESEARCH_GRAPH_Update((unsigned char *)(((struct ResearchProc *)proc)->detailObject));
    if (RESEARCH_GRAPH_GetVisible((void *)(((struct ResearchProc *)proc)->detailObject)) != 0) {
    if (RESEARCH_GRAPH_GetActive((void *)(((struct ResearchProc *)proc)->detailObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}

u32 RESEARCH_TOP_GetFrameCount(const void *proc)
{
    return *(const u32 *)&((struct ResearchProc *)proc)->frameCount;
}

void RESEARCH_TOP_IncFrameCount(void *proc)
{
    u32 *counter = (u32 *)((char *)proc + 8);
    *counter += 1;
}

void RESEARCH_TOP_ResetProc(void *proc, u32 appResource)
{
    ((struct ResearchProc *)proc)->heapId = 1;
    ((struct ResearchProc *)proc)->appResourceU = appResource;
    ((struct ResearchProc *)proc)->frameCount = 0;
    ((struct ResearchProc *)proc)->common = 0;
    ((struct ResearchProc *)proc)->listObject = 0;
    ((struct ResearchProc *)proc)->graphObject = 0;
    ((struct ResearchProc *)proc)->detailObject = 0;
    ((struct ResearchProc *)proc)->listViewState = 0;
}

void RESEARCH_TOP_CreateCommon(u32 proc)
{
    ((struct ResearchProc *)proc)->common = RESEARCH_COMMON_Create(((struct ResearchProc *)proc)->heapId, ((struct ResearchProc *)proc)->appResourceU);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_DestroyCommon(u32 proc)
{
    RESEARCH_COMMON_Destroy((void *)(((struct ResearchProc *)proc)->common));
    ((struct ResearchProc *)proc)->common = 0;
    return 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CreateListView(u32 proc)
{
    u32 r = ListViewState_Create(((struct ResearchProc *)proc)->heapId);
    ((struct ResearchProc *)proc)->listViewState = r;
    ListViewState_Reset((void *)r);
}

u32 RESEARCH_TOP_DestroyListView(u32 proc)
{
    ListViewState_Destroy((void *)(((struct ResearchProc *)proc)->listViewState));
    ((struct ResearchProc *)proc)->listViewState = 0;
    return 0;
}

/*
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 */
void RESEARCH_TOP_InitBackgrounds(unsigned short heapId)
{
    BG_SYS_Create(heapId);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021C2E30));
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}

u32 RESEARCH_TOP_ExitBackgrounds(void)
{
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(4);
    return BG_SYS_Delete();
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
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(4, ((struct ArcMember *)palette)->data, 512, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 10, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(4, ((struct CharAnimMember *)character)->data, ((struct CharAnimMember *)character)->size, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 11, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(4);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 12, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen2);
    BG_SYS_DrawTile(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(5);
    func_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_UpdateFrameGraphic(const void *proc)
{
    u32 frame = RESEARCH_TOP_GetFrameCount(proc) / 10;
    u32 index = (u8)(frame % 6);
    BG_SYS_FillTileMap(5, 0, 0, 0x20, 0x18, (u8)index);
    BG_SYS_PushTile(5);
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
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(1, ((struct ArcMember *)palette)->data, 512, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 1, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(1, ((struct CharAnimMember *)character)->data, ((struct CharAnimMember *)character)->size, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 2, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(1);
    GFL_HEAP_Free(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_CreateListObject(void *owner)
{
    u32 heapId = RESEARCH_COMMON_GetHeapId(owner);
    u32 obj = RESEARCH_TOP_AllocListObject(heapId);
    RESEARCH_TOP_InitFields((char *)obj);
    RESEARCH_TOP_SetHeapId((void *)obj, heapId);
    RESEARCH_TOP_SetOwner((void *)obj, (u32)owner);
    return obj;
}

u32 RESEARCH_TOP_DestroyListObject(void *obj)
{
    RESEARCH_TOP_DestroyCommandQueue((void *)obj);
    return RESEARCH_TOP_FreeListObject(obj);
}

void RESEARCH_TOP_UpdateListObject(char *obj)
{
    switch (((struct ResearchObjC *)obj)->command) {
    case 0:RESEARCH_TOP_InitListObject(obj);break;
    case 1:RESEARCH_TOP_HandleListInput(obj);break;
    case 2:RESEARCH_TOP_HandleListInputAlt(obj);break;
    case 3:RESEARCH_TOP_AdvanceListScroll((unsigned)obj);break;
    case 4:RESEARCH_TOP_StepExitFade((unsigned)obj);break;
    case 5:RESEARCH_TOP_CleanupListObject((unsigned)obj);break;
    case 6:return;
    }
    if (RESEARCH_TOP_IsListObjectDone(obj)==0) {
        RESEARCH_TOP_CheckQuestionnaire((unsigned)obj);RESEARCH_TOP_UpdateEntryPaletteAnime((int *)obj);
        RESEARCH_COMMON_UpdatePaletteAnime(*(unsigned *)&((struct ResearchObjC *)obj)->owner);CLACT_DrawSystem();
    }
    RESEARCH_TOP_IncStateTimer(obj);RESEARCH_TOP_ProcessCommand((unsigned)obj);
}

int RESEARCH_TOP_IsListObjectDone(void *obj)
{
    if (((struct ResearchObjC *)obj)->exitRequested != 0) {
        return 1;
    }
    return 0;
}

/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetListObjectMode(void *obj)
{
    return ((struct ResearchObjC *)obj)->mode;
}

void RESEARCH_TOP_InitListObject(char *obj)
{
    unsigned kind;
    RESEARCH_TOP_CreateCommandQueue((unsigned)obj);RESEARCH_TOP_CreateFont((unsigned)obj);
    RESEARCH_TOP_CreateMessages(obj);RESEARCH_TOP_InitPaletteRows((u8 *)obj);RESEARCH_TOP_InitSelection(obj);
    RESEARCH_TOP_InitOverlayBackgrounds(obj);RESEARCH_TOP_LoadBackground6(obj);RESEARCH_TOP_UpdateBackground7(obj);
    RESEARCH_TOP_LoadBackground2(obj);RESEARCH_TOP_UpdateBackground3(obj);RESEARCH_TOP_CreateLabels(obj);
    RESEARCH_TOP_RegisterEntryResources((struct ResearchObjC *)obj);RESEARCH_TOP_RegisterCursorResources((struct ResearchObjC *)obj);
    RESEARCH_TOP_CreateUnits(obj);RESEARCH_TOP_CreateActor(obj);RESEARCH_TOP_CreatePaletteAnime(obj);
    RESEARCH_TOP_BindPaletteAnime(obj);RESEARCH_TOP_RestartNetwork((unsigned)obj);RESEARCH_TOP_RegisterVBlank(obj);
    if (RESEARCH_TOP_IsSelectionValid((unsigned)obj,0)==0)RESEARCH_TOP_SetupTextLabel((unsigned)obj);
    kind=RESEARCH_TOP_GetTransitionKind((unsigned char *)obj);
    RESEARCH_TOP_PushCommand((unsigned char *)obj,RESEARCH_TOP_GetTransitionKind((unsigned char *)obj));
    if (kind==2) {RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)obj)->selection);RESEARCH_TOP_StartEntryPaletteAnime((char *)((unsigned)obj),0);}
    RESEARCH_TOP_FadeIn();RESEARCH_TOP_SetCommandReady(obj);
}

/*
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 */
void RESEARCH_TOP_HandleListInput(char *obj)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(obj+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)obj)->owner));
    if(RESEARCH_TOP_GetInputFlag(obj)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime((u8 *)obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);return;
    }
    if(keys&2) {
        RESEARCH_TOP_SetEntryHandled((u8 *)obj,0);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime((u8 *)obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)obj)->selection);RESEARCH_TOP_StartEntryPaletteAnime(obj,0);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,2);return;
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid((u32)obj,0)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SetMode(obj,0);RESEARCH_TOP_SelectDirect((u32)obj,0);RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)obj)->selection);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid((u32)obj,1)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SetMode(obj,1);RESEARCH_TOP_SelectDirect((u32)obj,1);RESEARCH_TOP_DrawSelector(*(int *)&((struct ResearchObjC *)obj)->selection);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    }
}

void RESEARCH_TOP_HandleListInputAlt(char *obj)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(obj+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)obj)->owner));
    if(RESEARCH_TOP_GetInputFlag(obj)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime((u8 *)obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);return;
    }
    if(keys&64)RESEARCH_TOP_SelectPrev((u32)obj);
    if(keys&128)RESEARCH_TOP_SelectNext((u32)obj);
    if(keys&1) {
        RESEARCH_TOP_SetEntryHandled((u8 *)obj,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
        switch(((struct ResearchObjC *)obj)->selection) {
        case 0:RESEARCH_TOP_SetMode(obj,0);return;
        case 1:RESEARCH_TOP_SetMode(obj,1);return;
        default:RESEARCH_TOP_SetMode(obj,2);return;
        }
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid((u32)obj,0)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SelectDirect((u32)obj,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(obj,0);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid((u32)obj,1)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)obj,1);RESEARCH_TOP_SelectDirect((u32)obj,1);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(obj,1);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(keys&2) {
        RESEARCH_TOP_StartPaletteAnime((u8 *)obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand((u8 *)obj,3);RESEARCH_TOP_PushCommand((u8 *)obj,4);RESEARCH_TOP_PushCommand((u8 *)obj,5);
    }
}

/*
 * Steps the record through RESEARCH_TOP_SetCommandReady while the running count is below
 * RESEARCH_TOP_GetStateTimer().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_AdvanceListScroll(u32 obj)
{
    u32 limit = RESEARCH_TOP_GetStateTimerLimit((void *)obj);
    if (limit < RESEARCH_TOP_GetStateTimer((void *)obj)) {
    RESEARCH_TOP_SetCommandReady((void *)obj);
    }
}

void RESEARCH_TOP_StepExitFade(u32 obj)
{
    switch (RESEARCH_TOP_GetCommandTimer((void *)obj)) {
    case 0:
    RESEARCH_TOP_FadeOut();
    RESEARCH_TOP_IncCommandTimer((void *)obj);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_TOP_SetCommandReady((void *)obj);
    }
    break;
    }
}

void RESEARCH_TOP_CleanupListObject(u32 obj)
{
    RESEARCH_TOP_UnregisterVBlank();
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjC *)obj)->owner);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjC *)obj)->owner);
    RESEARCH_TOP_RestorePaletteAnime((char *)obj);
    RESEARCH_TOP_DestroyPaletteAnime((int *)obj);
    RESEARCH_TOP_DeleteActor((u8 *)obj);
    RESEARCH_TOP_DeleteUnits((int *)obj);
    RESEARCH_TOP_ReleaseEntryResources(obj);
    RESEARCH_TOP_ReleaseCursorResources(obj);
    RESEARCH_TOP_DestroyLabels((int *)obj);
    RESEARCH_TOP_ShowBackground3(obj);
    RESEARCH_TOP_DummyBg3(obj);
    RESEARCH_TOP_ShowBackground7(obj);
    RESEARCH_TOP_DummyBg7(obj);
    RESEARCH_TOP_ExitOverlayBackgrounds(obj);
    RESEARCH_TOP_DeleteMessages((int *)obj);
    RESEARCH_TOP_DeleteFont((u8 *)obj);
    ((struct ResearchObjC *)obj)->exitRequested = 1;
    RESEARCH_TOP_PushCommand((u8 *)obj, 6);
    RESEARCH_TOP_SetCommandReady((void *)obj);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_PushCommand(u8 *obj, u32 command)
{
    RingQueue_Push((u32)(((struct ResearchObjC *)obj)->commandQueue), command);
}

void RESEARCH_TOP_SetCommandReady(void *obj)
{
    ((struct ResearchObjC *)obj)->commandReady = 1;
}

void RESEARCH_TOP_ProcessCommand(u32 obj)
{
    if (((struct ResearchObjC *)obj)->commandReady != 0) {
    if (RingQueue_IsEmpty(((struct ResearchObjC *)obj)->commandQueue) == 0) {
    RESEARCH_TOP_StartCommand((void *)obj, RingQueue_Pop((struct Ring *)(((struct ResearchObjC *)obj)->commandQueue)));
    }
    }
}

/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StartCommand(void *obj, u32 command)
{
    ((struct ResearchObjC *)obj)->command = command;
    ((struct ResearchObjC *)obj)->commandTimer = 0;
    ((struct ResearchObjC *)obj)->stateTimer = 0;
    ((struct ResearchObjC *)obj)->commandReady = 0;
}

u32 RESEARCH_TOP_GetCommandTimer(void *obj)
{
    return ((struct ResearchObjC *)obj)->commandTimer;
}

void RESEARCH_TOP_IncCommandTimer(void *obj)
{
    u32 *counter = (u32 *)((char *)obj + 0x1c);
    *counter += 1;
}

u32 RESEARCH_TOP_GetTransitionKind(u8 *obj)
{
    u32 owner = ((struct ResearchObjC *)obj)->ownerHandle;
    u32 prevScreen = RESEARCH_COMMON_GetPreviousScreen((void *)owner);
    u32 entryHandled = RESEARCH_COMMON_GetEntryHandled((void *)owner);
    if (prevScreen != 0 && entryHandled == 0) {
    return 2;
    }
    return 1;
}

void RESEARCH_TOP_SetEntryHandled(u8 *obj, u32 handled)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchObjC *)obj)->owner, handled);
}

void RESEARCH_TOP_SetMode(void *obj, u32 mode)
{
    ((struct ResearchObjC *)obj)->mode = mode;
}

/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CheckQuestionnaire(u32 obj)
{
    if (((struct ResearchObjC *)obj)->questionnaireLatched == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    ((struct ResearchObjC *)obj)->questionnaireLatched = 1;
    RESEARCH_TOP_ShowEntryActor(obj);
    }
    }
}

void RESEARCH_TOP_SelectPrev(u32 obj)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)obj)->selection);
    RESEARCH_TOP_MoveSelection((char *)obj, -1);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)obj)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)obj, 1);
}

void RESEARCH_TOP_SelectNext(u32 obj)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)obj)->selection);
    RESEARCH_TOP_MoveSelection((char *)obj, 1);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)obj)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)obj, 1);
}

void RESEARCH_TOP_SelectDirect(u32 obj, u32 selection)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct ResearchObjC *)obj)->selection);
    RESEARCH_TOP_SetSelection((void *)obj, selection);
    RESEARCH_TOP_DrawSelector(((struct ResearchObjC *)obj)->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)obj, 1);
}

void RESEARCH_TOP_DrawSelector(int selection)
{
    int index, x, y, w, h, palette;
    switch (selection) {
    case 0:
        index = 2; x = 3; y = 5; w = 0x1a; h = 5; palette = 0xa;
        break;
    case 1:
        index = 2; x = 3; y = 0xc; w = 0x1a; h = 5; palette = 0xa;
        break;
    default:
        return;
    }
    BG_SYS_FillTileMap(index, x, y, w, h, palette);
    BG_SYS_PushTile(index);
}

void RESEARCH_TOP_DrawSelectorIdle(int selection)
{
    int index, x, y, w, h, palette;
    switch (selection) {
    case 0:
        index = 2; x = 3; y = 5; w = 0x1a; h = 5; palette = 5;
        break;
    case 1:
        index = 2; x = 3; y = 0xc; w = 0x1a; h = 5; palette = 6;
        break;
    default:
        return;
    }
    BG_SYS_FillTileMap(index, x, y, w, h, palette);
    BG_SYS_PushTile(index);
}

void RESEARCH_TOP_SetupTextLabel(u32 obj)
{
    BgTextLabel_SetPalette((u8 *)(((struct ResearchObjC *)obj)->labels[2]), 15);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)obj, 3);
    RESEARCH_TOP_StartEntryPaletteAnime((char *)obj, 4);
}

void RESEARCH_TOP_StartPaletteAnime(u8 *obj)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(((struct ResearchObjC *)obj)->ownerHandle), 0);
}

u32 RESEARCH_TOP_ShowEntryActor(u32 obj)
{
    u32 actor = RESEARCH_TOP_GetEntryIconSource((void *)obj, 0);
    CLACT_SetActorDrawEnable((struct Obj *)actor, 1);
    CLACT_SetActorAutoAnim((struct Obj *)actor, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)actor, 4096);
    return CLACT_SetActorAnimFrame(actor, 0);
}

void RESEARCH_TOP_FadeIn(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void RESEARCH_TOP_FadeOut(void)
{
    FADE_Start(3, 0, 16, 0);
}

void RESEARCH_TOP_IncStateTimer(void *obj)
{
    u32 *counter = (u32 *)((char *)obj + 0x20);
    *counter += 1;
}

u32 RESEARCH_TOP_GetStateTimer(void *obj)
{
    return ((struct ResearchObjC *)obj)->stateTimer;
}

/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetStateTimer(void *obj, u32 limit)
{
    ((struct ResearchObjC *)obj)->stateTimerLimit = limit;
}

u32 RESEARCH_TOP_GetStateTimerLimit(void *obj)
{
    return ((struct ResearchObjC *)obj)->stateTimerLimit;
}

void RESEARCH_TOP_MoveSelection(char *obj, int delta)
{
    int selection = *(int *)&((struct ResearchObjC *)obj)->selection;
    do {
        selection = (selection + delta + 2) % 2;
    } while (!RESEARCH_TOP_IsSelectionValid((u32)obj, selection));
    *(int *)&((struct ResearchObjC *)obj)->selection = selection;
}

/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetSelection(void *obj, u32 selection)
{
    ((struct ResearchObjC *)obj)->selection = selection;
}

u32 RESEARCH_TOP_IsSelectionValid(u32 obj, u32 selection)
{
    if (selection == 0) {
    if (RESEARCH_TOP_CountUnlockedEntries((char *)obj) > 1) {
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
u32 RESEARCH_TOP_GetEntryActorSource(void *obj, u32 index)
{
    return *(u32 *)((char *)obj + index * 4 + 0x5c);
}

/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetEntryLabelSource(void *obj, u32 index)
{
    return *(u32 *)((char *)obj + index * 4 + 0x74);
}

/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetEntryIconSource(void *obj, u32 index)
{
    return *(u32 *)((char *)obj + index * 4 + 0x7c);
}

void RESEARCH_TOP_StartEntryPaletteAnime(char *obj, int slot)
{
    PALETTE_ANIME_Start(*(void **)(obj + slot * 4 + 0x38),
                  *(u32 *)(d_021C3004 + slot * 0x14),
                  *(u16 *)(d_021C3008 + slot * 0x14));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StopEntryPaletteAnime(u8 *obj, u32 slot)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(obj + (slot)*4 + 56)));
}

void RESEARCH_TOP_UpdateEntryPaletteAnime(int *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Update(obj[i + 0x0E]);
}

/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char RESEARCH_TOP_CountUnlockedEntries(char *obj)
{
    void *bitmap=(void *)GAME_DATA_GetEventWork((const struct BigObj *)RESEARCH_COMMON_GetAppResource(((struct ResearchObjC *)obj)->owner));
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

u32 RESEARCH_TOP_GetOwner(void *obj)
{
    return ((struct ResearchObjC *)obj)->ownerHandle;
}

void RESEARCH_TOP_SetOwner(void *obj, u32 owner)
{
    ((struct ResearchObjC *)obj)->ownerHandle = owner;
}

/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetHeapId(void *obj, u32 heapId)
{
    ((struct ResearchObjC *)obj)->heapId = heapId;
}

u32 RESEARCH_TOP_GetInputFlag(void *obj)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_TOP_GetOwner(obj));
}

u32 RESEARCH_TOP_AllocListObject(u32 heapId)
{
    return (u32)func_02030734(heapId, 144, 0, (const char *)0x21C3FEC, 1486);
}

u32 RESEARCH_TOP_FreeListObject(void *obj)
{
    return func_020307B0(obj);
}

/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void RESEARCH_TOP_InitFields(char *obj)
{
    ((struct ResearchObjC *)obj)->commandReady=0;((struct ResearchObjC *)obj)->questionnaireLatched=0;((struct ResearchObjC *)obj)->exitRequested=0;
    ((struct ResearchObjC *)obj)->command=0;((struct ResearchObjC *)obj)->stateTimer=0;((struct ResearchObjC *)obj)->stateTimerLimit=0;
    ((struct ResearchObjC *)obj)->selection=0;((struct ResearchObjC *)obj)->mode=2;((struct ResearchObjC *)obj)->commandTimer=0;
    RESEARCH_TOP_ClearResources(obj);RESEARCH_TOP_ClearCommandQueue(obj);RESEARCH_TOP_ClearMessages(obj);RESEARCH_TOP_ClearFont(obj);
    RESEARCH_TOP_ClearLabels(obj);RESEARCH_TOP_ClearUnits(obj);RESEARCH_TOP_ClearActor(obj);RESEARCH_TOP_ClearPaletteAnime(obj);
}

void RESEARCH_TOP_InitSelection(char *obj)
{
    void *owner=((struct ResearchObjC *)obj)->owner;
    unsigned prevScreen=RESEARCH_COMMON_GetPreviousScreen(owner),entryHandled=RESEARCH_COMMON_GetEntryHandled(owner);
    if(prevScreen!=0 && entryHandled==0) {
        unsigned mode;
        switch(prevScreen) {case 2:default:mode=0;break;case 3:mode=1;break;}
        RESEARCH_TOP_SetSelection(obj,mode);
    } else {
        if(RESEARCH_TOP_IsSelectionValid((unsigned)obj,0)!=0) RESEARCH_TOP_SetSelection(obj,0);
        else RESEARCH_TOP_SetSelection(obj,1);
    }
}

void RESEARCH_TOP_ClearFont(void *obj)
{
    ((struct ResearchObjC *)obj)->font = 0;
}

void RESEARCH_TOP_CreateFont(u32 obj)
{
    u8 scratch[4];
    ((struct ResearchObjC *)obj)->font = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjC *)obj)->heapId));
}

void RESEARCH_TOP_DeleteFont(u8 *obj)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjC *)obj)->font)));
}

/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearMessages(void *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)obj + i * 4 + 0xc) = 0;
}

void RESEARCH_TOP_CreateMessages(char *obj)
{
    int i = 0;
    do {
        int offset = i * 4;
        *(u32 *)(obj + offset + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + offset)), (u16)(((struct ResearchObjC *)obj)->heapId));
        i++;
    } while (i < 2);
}

void RESEARCH_TOP_DeleteMessages(int *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)obj[i + 3]);
}

void RESEARCH_TOP_InitPaletteRows(u8 *obj)
{
    int i = 0;
    do {
        int offset = i * 4;
        u8 *src = d_021C2EE0 + offset;
        obj[offset + 0x2e] = src[0];
        obj[offset + 0x2f] = src[1];
        obj[offset + 0x2c] = src[2];
        obj[offset + 0x2d] = src[3];
        i++;
    } while (i < 3);
}

void RESEARCH_TOP_ClearCommandQueue(void *obj)
{
    ((struct ResearchObjC *)obj)->commandQueue = 0;
}

void RESEARCH_TOP_CreateCommandQueue(u32 obj)
{
    ((struct ResearchObjC *)obj)->commandQueue = RingQueue_Create(10, ((struct ResearchObjC *)obj)->heapId);
}

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *obj)
{
    RingQueue_Destroy((void *)obj->commandQueue);
}

void RESEARCH_TOP_InitOverlayBackgrounds(char *obj)
{
    BG_SYS_SetGraphicsMode(&d_021C2EEC);
    BG_SYS_InitBgLayer(6,&d_021C2F78,0);BG_SYS_InitBgLayer(7,&d_021C2F18,0);
    BG_SYS_InitBgLayer(2,&d_021C2F38,0);BG_SYS_InitBgLayer(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    BMP_WIN_Init(((struct ResearchObjC *)obj)->heapId);
}

void RESEARCH_TOP_ExitOverlayBackgrounds(u32 obj)
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
}

void RESEARCH_TOP_LoadBackground6(char *obj)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)obj)->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,13,((struct ResearchObjC *)obj)->heapId);
    void *data;
    NNS_G2dGetUnpackedScreenData(file,&data);
    BG_SYS_DrawTile(6,(unsigned)((char *)data+12),0,0,32,24);
    BG_SYS_PushTile(6);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg7(u32 unused)
{
}

u32 RESEARCH_TOP_UpdateBackground7(void *obj)
{
    BG_SYS_Init(7, 0, 1, 0);
    return BG_SYS_ClearSlot(7);
}

void RESEARCH_TOP_ShowBackground7(u32 obj)
{
    BG_SYS_SetTileUnit(7, 1, 0);
}

void RESEARCH_TOP_LoadBackground2(char *obj)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)obj)->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,4,((struct ResearchObjC *)obj)->heapId);
    void *data;
    NNS_G2dGetUnpackedScreenData(file,&data);
    BG_SYS_DrawTile(2,(unsigned)((char *)data+12),0,0,32,24);
    BG_SYS_PushTile(2);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg3(u32 unused)
{
}

u32 RESEARCH_TOP_UpdateBackground3(void *obj)
{
    BG_SYS_Init(3, 0, 1, 0);
    return BG_SYS_ClearSlot(3);
}

void RESEARCH_TOP_ShowBackground3(u32 obj)
{
    BG_SYS_SetTileUnit(3, 1, 0);
}

void RESEARCH_TOP_ClearLabels(void *obj)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)obj + i * 4 + 0x4c) = 0;
}

void RESEARCH_TOP_CreateLabels(char *obj)
{
    struct LabelTemplate tmpl;
    int i;
    for(i=0;i<4;i++) {
        const struct LabelEntry *entry=&d_021C2F98[i];
        tmpl.params[0]=entry->template.params[0];tmpl.params[1]=entry->template.params[1];tmpl.params[2]=entry->template.params[2];tmpl.params[3]=entry->template.params[3];
        tmpl.params[4]=entry->template.params[4];tmpl.params[5]=entry->template.params[5];tmpl.params[6]=entry->template.params[6];tmpl.params[7]=entry->template.params[7];
        tmpl.params[8]=entry->template.params[8];tmpl.params[9]=entry->template.params[9];tmpl.params[10]=entry->template.params[10];tmpl.messageIndex=entry->extraId;
        *(unsigned *)(obj+i*4+0x4c)=(unsigned int)BgTextLabel_Create((const struct Config *)(&tmpl),((struct ResearchObjC *)obj)->font,*(unsigned *)(obj+entry->template.messageIndex*4+0xc),((struct ResearchObjC *)obj)->heapId);
        BgTextLabel_PrintMessage(*(unsigned *)(obj+i*4+0x4c),entry->messageId);
    }
}

void RESEARCH_TOP_DestroyLabels(int *obj)
{
    int i;
    for (i = 0; i < 4; i++) {
        BgTextLabel_Destroy((u8 *)obj[i + 0x13]);
        obj[i + 0x13] = 0;
    }
}

/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearResources(void *obj)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)obj + i * 4 + 0x5c) = 0;
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
    int charHandle=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,1,heap);
    int paletteHandle=CLACT_RegisterPalette((void *)arc,16,1,0,heap);
    int cellHandle=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->entryCharacter=charHandle;p->entryPalette=paletteHandle;p->entryCell=cellHandle;
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_ReleaseEntryResources(u32 obj)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)obj)->entryCharacter);
    CLACT_ReleasePalette(((struct ResearchObjC *)obj)->entryPalette);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)obj)->entryCell);
}

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p)
{
    u16 heap=p->heapId;
    void *arc=func_020490F4(192,heap);
    int charHandle=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,0,heap);
    int paletteHandle=CLACT_RegisterPaletteEx((void *)((unsigned)arc),16,0,192,0,4,heap);
    int cellHandle=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->cursorCharacter=charHandle;p->cursorPalette=paletteHandle;p->cursorCell=cellHandle;
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_TOP_ReleaseCursorResources(u32 obj)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)obj)->cursorCharacter);
    CLACT_ReleasePalette(((struct ResearchObjC *)obj)->cursorPalette);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)obj)->cursorCell);
}

void RESEARCH_TOP_ClearUnits(void *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)obj + i * 4 + 0x74) = 0;
}

void RESEARCH_TOP_CreateUnits(char *obj)
{
    int i = 0;
    do {
        *(u32 *)(obj + i * 4 + 0x74) = (u32)CLACT_CreateUnit(d_021C2ED2[i], d_021C2ED0[i], ((struct ResearchObjC *)obj)->heapId);
        i++;
    } while (i < 2);
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_DeleteUnits(int *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        CLACT_DeleteUnit((struct Bank *)obj[i + 0x1D]);
}

/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearActor(void *obj)
{
    ((struct ResearchObjC *)obj)->actor = 0;
}

/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void RESEARCH_TOP_CreateActor(char *obj)
{
    struct ActorSpawnPos pos;
    unsigned labelSource,actorSourceA,actorSourceB,actorSourceC;
    pos.x=d_021C2EFC.pos.x;pos.y=d_021C2EFC.pos.y;pos.z=d_021C2EFC.pos.z;
    pos.a=d_021C2EFC.pos.a;pos.b=d_021C2EFC.pos.b;
    labelSource=RESEARCH_TOP_GetEntryLabelSource(obj,d_021C2EFC.firstSource);
    actorSourceA=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.secondSource);
    actorSourceB=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.thirdSource);
    actorSourceC=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.fourthSource);
    *(unsigned *)&((struct ResearchObjC *)obj)->actor=(unsigned)CLACT_CreateActor((void *)labelSource,actorSourceA,actorSourceB,actorSourceC,&pos,d_021C2EFC.arg,((struct ResearchObjC *)obj)->heapId);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ResearchObjC *)obj)->actor,0);
}

void RESEARCH_TOP_DeleteActor(u8 *obj)
{
    CLACT_DeleteActor((struct Obj *)((u32)(((struct ResearchObjC *)obj)->actor)));
}

/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearPaletteAnime(void *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)obj + i * 4 + 0x38) = 0;
}

void RESEARCH_TOP_CreatePaletteAnime(char *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        ((int *)(obj + 0x38))[i] = PALETTE_ANIME_Create(((struct ResearchObjC *)obj)->heapId);
}

void RESEARCH_TOP_DestroyPaletteAnime(int *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Destroy((void *)obj[i + 0x0E]);
}

void RESEARCH_TOP_BindPaletteAnime(char *obj)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Bind((void *)(*(int *)(obj + i * 4 + 0x38)), d_021C2FF8[i].palette, d_021C2FF8[i].source, d_021C2FF8[i].mode);
    }
}

void RESEARCH_TOP_RestorePaletteAnime(char *obj)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Restore((char *)(*(int *)(obj + i * 4 + 0x38)));
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

void RESEARCH_TOP_RegisterVBlank(void *obj)
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

void RESEARCH_TOP_RestartNetwork(u32 obj)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchObjC *)obj)->heapId);
}
