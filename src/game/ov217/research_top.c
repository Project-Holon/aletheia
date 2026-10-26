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
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   RESEARCH_COMMON_SetScreen  0x021C09BC  thumb  ov217
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *   ListViewState_Reset  0x021C0DE4  thumb  ov217
 *   ListViewState_Destroy  0x021C0DDC  thumb  ov217
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   GFL_HEAP_Free 0x020307B0 arm
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
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 *   BG_SYS_FreeTiles  0x02040DA8  arm
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
 *   GFL_USE_SetVBlankHook  0x02005654  thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   FADE_Start  0x0204E720  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm
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
 *   BG_SYS_SetLcdSwap  0x0204363C  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 *   GFL_USE_ClearVBlankHook  0x0200566C  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"
struct TcbTask;
union TouchHitTable;
struct ActorInitParam;
struct ClactActor;
struct Unit;
#include "../arm9/game_data.h"
#include "../arm9/arc_tool.h"
#include "research_common.h"
#include "research_shared_types.h"

#include "../arm9/bg_sys_types.h"

struct Proc;

struct Proc;

struct NitroFileHeader;

/* The process callback's subSeq counter (procsys.c passes &proc->subSeq). */
struct ProcSubSeq { u32 subSeq; };

/* The caller argument buffer; the first word is the app resource handle. */
struct ProcArg { void *appResource; };

struct LabelTemplate { u8 params[11]; u32 messageIndex; };

struct LabelEntry { struct LabelTemplate template; u32 messageId; u32 extraId; };

struct ArcMember { u8 pad0[12]; void *data; };

#include "../arm9/nns_g2d_res_types.h"

struct ResearchTopActorSpawnPos { short x, y, z; unsigned char a, b; };

struct ActorSpawnTemplate { struct ResearchTopActorSpawnPos pos; u32 firstSource, secondSource, thirdSource, fourthSource; u16 arg, pad; };

struct PaletteAnimeBinding { u16 *palette, *source; u8 mode; u8 pad[11]; };

struct ResearchObjC {
    struct ResearchCommon *owner;
    u16 heapId;
    u16 pad6;
    struct GfFont *font;
    struct MsgBank *messages[2];
    struct RingQueue *commandQueue;
    u32 command;
    u32 commandTimer;
    u32 stateTimer;
    u32 stateTimerLimit;
    u32 selection;
    u8 paletteRows[3][4];
    struct PaletteAnime *paletteAnime[5];
    struct BgTextLabel *labels[4];
    union {
        struct { u32 cursorCharacter, cursorPalette, cursorCell, entryCharacter, entryPalette, entryCell; };
        u32 resources[6];
    };
    struct Unit *units[2];
    struct ClactActor *actor;
    u32 commandReady;
    u32 questionnaireLatched;
    u32 exitRequested;
    u32 mode;
};

struct ResearchProc {
    u16 heapId;
    u16 pad2;
    void *appResource;
    u32 frameCount;
    struct ResearchCommon *common;
    struct ResearchObjC *listObject;
    void *graphObject;
    void *detailObject;
    struct ListViewState *listViewState;
};

#include "../arm9/procsys.h"

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BG_SYS_SetLcdSwap(u32 swap);

struct GameSystem;

#include "../arm9/gamesystem.h"
struct ResearchCommon;


#include "../arm9/wih_dwc.h"
struct GameData;


struct FieldState;


#include "../arm9/net.h"




#include "research_list_recovery.h"
struct ListViewState;



extern void BG_SYS_Create(unsigned short heapId);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_Delete(void);

extern void BG_SYS_FreeLayerBuf(u32 i);



#include "../arm9/nns_g2d_anim_bank.h"

extern void BG_SYS_LoadPltt(u32 bgId, void *src, u16 size, u16 offset);

#include "../arm9/gfl_heap_wrap.h"


extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

#include "../arm9/nns_g2d_load.h"




/* The DS code was built against other parameter widths for BG_SYS_FillTileMap (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_FillTileMap(int index, int x0, int y0, int w, int h, int pal);
extern void BG_SYS_DrawTile(unsigned int index, void *src, unsigned char dx, unsigned char dy, unsigned char cw, unsigned char ch);
#else
#include "../arm9/bg_sys.h"
#endif



extern void BG_SYS_PushTile(u32);



#include "../arm9/clact.h"

#include "../arm9/key.h"

extern int TOUCHPANEL_HitTrg(const union TouchHitTable *);


extern void GFL_USE_PlaySeDefaultVolume(u32 a);

#include "../arm9/fade.h"


struct RingQueue;

#include "queue.h"






#include "../arm9/game_beacon.h"
struct BgTextLabel;

#include "bg_font.h"

struct Actor;





struct PaletteAnime;

#include "palette_anime.h"




struct EventWork;

#include "../arm9/zonedata.h"



#include "../arm9/gf_font.h"


#include "../arm9/msgdata.h"




extern void G2x_SetBlendAlpha_(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);

#include "../arm9/bmp_win.h"


extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern void BG_SYS_ClearSlot(u8 slot);

extern void BG_SYS_FreeTiles(u32, u32, u32);
struct BgTextLabelConfig;




















extern u32 GFL_USE_SetVBlankHook(void (*)(struct TcbTask *, void *), void *);

extern void GFL_USE_ClearVBlankHook(void);

u32 RESEARCH_TOP_InitProc(struct Proc *procsys, struct ProcSubSeq *state, struct ProcArg *work, struct ResearchProc *proc);

u32 RESEARCH_TOP_ReleaseProc(struct Proc *procsys, u32 unused1, u32 unused2, struct ResearchProc *proc);

int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, struct ResearchProc *proc);

void RESEARCH_TOP_UpdateNetwork(struct ResearchProc *proc);

void RESEARCH_TOP_ChangeScreen(struct ResearchProc *proc, int *state, int nextState);

void RESEARCH_TOP_CloseSubState(struct ResearchProc *proc, u32 *state);

void RESEARCH_TOP_OpenSubState(struct ResearchProc *proc, u32 *state, u32 kind);

int RESEARCH_TOP_StateIdle(struct ResearchProc *proc);

u32 RESEARCH_TOP_StateList(struct ResearchProc *proc);

u32 RESEARCH_TOP_StateGraph(struct ResearchProc *proc);

u32 RESEARCH_TOP_StateDetail(struct ResearchProc *proc);

u32 RESEARCH_TOP_GetFrameCount(const struct ResearchProc *proc);

void RESEARCH_TOP_IncFrameCount(struct ResearchProc *proc);

void RESEARCH_TOP_ResetProc(struct ResearchProc *proc, void *appResource);

void RESEARCH_TOP_CreateCommon(struct ResearchProc *proc);

u32 RESEARCH_TOP_DestroyCommon(struct ResearchProc *proc);

void RESEARCH_TOP_CreateListView(struct ResearchProc *proc);

u32 RESEARCH_TOP_DestroyListView(struct ResearchProc *proc);

void RESEARCH_TOP_InitBackgrounds(unsigned short heapId);

void RESEARCH_TOP_ExitBackgrounds(void);

void RESEARCH_TOP_LoadSubAssets(u32 heap);

void RESEARCH_TOP_UpdateFrameGraphic(const struct ResearchProc *proc);

void RESEARCH_TOP_LoadTopAssets(u32 heap);

struct ResearchObjC *RESEARCH_TOP_CreateListObject(struct ResearchCommon *owner);

u32 RESEARCH_TOP_DestroyListObject(struct ResearchObjC *obj);

void RESEARCH_TOP_UpdateListObject(struct ResearchObjC *obj);

int RESEARCH_TOP_IsListObjectDone(struct ResearchObjC *obj);

u32 RESEARCH_TOP_GetListObjectMode(struct ResearchObjC *obj);

void RESEARCH_TOP_InitListObject(struct ResearchObjC *obj);

void RESEARCH_TOP_HandleListInput(struct ResearchObjC *obj);

void RESEARCH_TOP_HandleListInputAlt(struct ResearchObjC *obj);

void RESEARCH_TOP_AdvanceListScroll(struct ResearchObjC *obj);

void RESEARCH_TOP_StepExitFade(struct ResearchObjC *obj);

void RESEARCH_TOP_CleanupListObject(struct ResearchObjC *obj);

void RESEARCH_TOP_PushCommand(struct ResearchObjC *obj, u32 command);

void RESEARCH_TOP_SetCommandReady(struct ResearchObjC *obj);

void RESEARCH_TOP_ProcessCommand(struct ResearchObjC *obj);

void RESEARCH_TOP_StartCommand(struct ResearchObjC *obj, u32 command);

u32 RESEARCH_TOP_GetCommandTimer(struct ResearchObjC *obj);

void RESEARCH_TOP_IncCommandTimer(struct ResearchObjC *obj);

u32 RESEARCH_TOP_GetTransitionKind(struct ResearchObjC *obj);

void RESEARCH_TOP_SetEntryHandled(struct ResearchObjC *obj, u32 handled);

void RESEARCH_TOP_SetMode(struct ResearchObjC *obj, u32 mode);

void RESEARCH_TOP_CheckQuestionnaire(struct ResearchObjC *obj);

void RESEARCH_TOP_SelectPrev(struct ResearchObjC *obj);

void RESEARCH_TOP_SelectNext(struct ResearchObjC *obj);

void RESEARCH_TOP_SelectDirect(struct ResearchObjC *obj, u32 selection);

void RESEARCH_TOP_DrawSelector(int selection);

void RESEARCH_TOP_DrawSelectorIdle(int selection);

void RESEARCH_TOP_SetupTextLabel(struct ResearchObjC *obj);

void RESEARCH_TOP_StartPaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_ShowEntryActor(struct ResearchObjC *obj);

void RESEARCH_TOP_FadeIn(void);

void RESEARCH_TOP_FadeOut(void);

void RESEARCH_TOP_IncStateTimer(struct ResearchObjC *obj);

u32 RESEARCH_TOP_GetStateTimer(struct ResearchObjC *obj);

void RESEARCH_TOP_SetStateTimer(struct ResearchObjC *obj, u32 limit);

u32 RESEARCH_TOP_GetStateTimerLimit(struct ResearchObjC *obj);

void RESEARCH_TOP_MoveSelection(struct ResearchObjC *obj, int delta);

void RESEARCH_TOP_SetSelection(struct ResearchObjC *obj, u32 selection);

u32 RESEARCH_TOP_IsSelectionValid(struct ResearchObjC *obj, u32 selection);

u32 RESEARCH_TOP_GetEntryActorSource(struct ResearchObjC *obj, u32 index);

struct Unit *RESEARCH_TOP_GetEntryLabelSource(struct ResearchObjC *obj, u32 index);

struct ClactActor *RESEARCH_TOP_GetEntryIconSource(struct ResearchObjC *obj, u32 index);

void RESEARCH_TOP_StartEntryPaletteAnime(struct ResearchObjC *obj, int slot);

void RESEARCH_TOP_StopEntryPaletteAnime(struct ResearchObjC *obj, u32 slot);

void RESEARCH_TOP_UpdateEntryPaletteAnime(struct ResearchObjC *obj);

unsigned char RESEARCH_TOP_CountUnlockedEntries(struct ResearchObjC *obj);

struct ResearchCommon *RESEARCH_TOP_GetOwner(struct ResearchObjC *obj);

void RESEARCH_TOP_SetOwner(struct ResearchObjC *obj, struct ResearchCommon *owner);

void RESEARCH_TOP_SetHeapId(struct ResearchObjC *obj, u32 heapId);

u32 RESEARCH_TOP_GetInputFlag(struct ResearchObjC *obj);

struct ResearchObjC *RESEARCH_TOP_AllocListObject(u32 heapId);

u32 RESEARCH_TOP_FreeListObject(struct ResearchObjC *obj);

void RESEARCH_TOP_InitFields(struct ResearchObjC *obj);

void RESEARCH_TOP_InitSelection(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearFont(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateFont(struct ResearchObjC *obj);

void RESEARCH_TOP_DeleteFont(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearMessages(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateMessages(struct ResearchObjC *obj);

void RESEARCH_TOP_DeleteMessages(struct ResearchObjC *obj);

void RESEARCH_TOP_InitPaletteRows(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearCommandQueue(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateCommandQueue(struct ResearchObjC *obj);

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *obj);

void RESEARCH_TOP_InitOverlayBackgrounds(struct ResearchObjC *obj);

void RESEARCH_TOP_ExitOverlayBackgrounds(struct ResearchObjC *obj);

void RESEARCH_TOP_LoadBackground6(struct ResearchObjC *obj);

void RESEARCH_TOP_DummyBg7(struct ResearchObjC *unused);

void RESEARCH_TOP_UpdateBackground7(struct ResearchObjC *obj);

void RESEARCH_TOP_ShowBackground7(struct ResearchObjC *obj);

void RESEARCH_TOP_LoadBackground2(struct ResearchObjC *obj);

void RESEARCH_TOP_DummyBg3(struct ResearchObjC *unused);

void RESEARCH_TOP_UpdateBackground3(struct ResearchObjC *obj);

void RESEARCH_TOP_ShowBackground3(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearLabels(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateLabels(struct ResearchObjC *obj);

void RESEARCH_TOP_DestroyLabels(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearResources(struct ResearchObjC *obj);

void RESEARCH_TOP_RegisterEntryResources(struct ResearchObjC *p);

void RESEARCH_TOP_ReleaseEntryResources(struct ResearchObjC *obj);

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p);

void RESEARCH_TOP_ReleaseCursorResources(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearUnits(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateUnits(struct ResearchObjC *obj);

void RESEARCH_TOP_DeleteUnits(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearActor(struct ResearchObjC *obj);

void RESEARCH_TOP_CreateActor(struct ResearchObjC *obj);

void RESEARCH_TOP_DeleteActor(struct ResearchObjC *obj);

void RESEARCH_TOP_ClearPaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_CreatePaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_DestroyPaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_BindPaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_RestorePaletteAnime(struct ResearchObjC *obj);

void RESEARCH_TOP_UpdateVBlank(struct TcbTask *unused, void *unused2);

void RESEARCH_TOP_RegisterVBlank(struct ResearchObjC *obj);

void RESEARCH_TOP_UnregisterVBlank(void);

void RESEARCH_TOP_RestartNetwork(struct ResearchObjC *obj);

#include "research_list.h"





#include "research_graph.h"





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

u32 RESEARCH_TOP_InitProc(struct Proc *procsys, struct ProcSubSeq *state, struct ProcArg *work, struct ResearchProc *proc)
{
    switch (state->subSeq) {
    case 0:
    PROCSYS_AllocProcWork(procsys, sizeof(struct ResearchProc), 1);
    state->subSeq = (u32)(state->subSeq + 1);
    break;
    case 1:
    RESEARCH_TOP_ResetProc(proc, work->appResource);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    BG_SYS_SetLcdSwap(0);
    RESEARCH_TOP_InitBackgrounds(proc->heapId);
    RESEARCH_TOP_LoadTopAssets(proc->heapId);
    RESEARCH_TOP_LoadSubAssets(proc->heapId);
    RESEARCH_TOP_CreateCommon(proc);
    RESEARCH_TOP_CreateListView(proc);
    return 1;
    }
    return 0;
}

u32 RESEARCH_TOP_ReleaseProc(struct Proc *procsys, u32 unused1, u32 unused2, struct ResearchProc *proc)
{
    RESEARCH_TOP_DestroyListView(proc);
    RESEARCH_TOP_DestroyCommon(proc);
    RESEARCH_TOP_ExitBackgrounds();
    PROCSYS_FreeProcWork(procsys);
    return 1;
}

/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int RESEARCH_TOP_MainProc(void *unused, u32 *state, u32 unused2, struct ResearchProc *proc)
{
    u32 next;
    RESEARCH_TOP_UpdateNetwork(proc);
    if (GAMESYSTEM_IsNetOffBySleep((struct GameSystem *)proc->appResource) != 0)
        RESEARCH_COMMON_SetInputFlag(proc->common);
    switch (*state) {
    case 0: next = RESEARCH_TOP_StateIdle(proc); break;
    case 1: next = RESEARCH_TOP_StateList(proc); break;
    case 2: next = RESEARCH_TOP_StateGraph(proc); break;
    case 3: next = RESEARCH_TOP_StateDetail(proc); break;
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
void RESEARCH_TOP_UpdateNetwork(struct ResearchProc *proc)
{
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(proc->appResource)));
    if (GAMESYSTEM_TryStartAutoComm((struct GameSystem *)(proc->appResource)) != 0) {
    GFL_NET_RefreshWmIconAtTopRight(1, proc->heapId);
    }
}

void RESEARCH_TOP_ChangeScreen(struct ResearchProc *proc, int *state, int nextState)
{
    RESEARCH_TOP_CloseSubState(proc, (u32 *)state);
    RESEARCH_TOP_OpenSubState(proc, (u32 *)state, nextState);
    switch (*state) {
    case 1:
        RESEARCH_COMMON_SetScreen(proc->common, 1);
        break;
    case 2:
        RESEARCH_COMMON_SetScreen(proc->common, 2);
        break;
    case 3:
        RESEARCH_COMMON_SetScreen(proc->common, 3);
        break;
    }
}

/*
 * tail: zero halfword alignment at 021B9772.
 */
void RESEARCH_TOP_CloseSubState(struct ResearchProc *proc, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: RESEARCH_TOP_DestroyListObject(proc->listObject); break;
    case 2: RESEARCH_LIST_Destroy(proc->graphObject); break;
    case 3: RESEARCH_GRAPH_Destroy(proc->detailObject); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: proc->listObject = 0; break;
    case 2: proc->graphObject = 0; break;
    case 3: proc->detailObject = 0; break;
    }
}

void RESEARCH_TOP_OpenSubState(struct ResearchProc *proc, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        proc->listObject = RESEARCH_TOP_CreateListObject(proc->common);
        break;
    case 2:
        proc->graphObject = RESEARCH_LIST_Create(proc->common, proc->listViewState);
        break;
    case 3:
        proc->detailObject = RESEARCH_GRAPH_Create(proc->common);
        break;
    }
    *state = kind;
}

int RESEARCH_TOP_StateIdle(struct ResearchProc *proc)
{
    return 1;
}

u32 RESEARCH_TOP_StateList(struct ResearchProc *proc)
{
    RESEARCH_TOP_UpdateListObject(proc->listObject);
    if (RESEARCH_TOP_IsListObjectDone((void *)(proc->listObject)) != 0) {
    switch (RESEARCH_TOP_GetListObjectMode((void *)(proc->listObject))) {
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

u32 RESEARCH_TOP_StateGraph(struct ResearchProc *proc)
{
    RESEARCH_LIST_Update((void *)(proc->graphObject));
    if (RESEARCH_LIST_GetVisible((void *)(proc->graphObject)) != 0) {
    if (RESEARCH_LIST_GetActive((void *)(proc->graphObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}

u32 RESEARCH_TOP_StateDetail(struct ResearchProc *proc)
{
    RESEARCH_GRAPH_Update((struct ResearchObjB *)(proc->detailObject));
    if (RESEARCH_GRAPH_GetVisible((void *)(proc->detailObject)) != 0) {
    if (RESEARCH_GRAPH_GetActive((void *)(proc->detailObject)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}

u32 RESEARCH_TOP_GetFrameCount(const struct ResearchProc *proc)
{
    return *(const u32 *)&proc->frameCount;
}

void RESEARCH_TOP_IncFrameCount(struct ResearchProc *proc)
{
    u32 *counter = (u32 *)&proc->frameCount;
    *counter += 1;
}

void RESEARCH_TOP_ResetProc(struct ResearchProc *proc, void *appResource)
{
    proc->heapId = 1;
    proc->appResource = appResource;
    proc->frameCount = 0;
    proc->common = 0;
    proc->listObject = 0;
    proc->graphObject = 0;
    proc->detailObject = 0;
    proc->listViewState = 0;
}

void RESEARCH_TOP_CreateCommon(struct ResearchProc *proc)
{
    proc->common = RESEARCH_COMMON_Create((u32)(proc->heapId), (struct Ctx *)(proc->appResource));
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_DestroyCommon(struct ResearchProc *proc)
{
    RESEARCH_COMMON_Destroy((void *)(proc->common));
    proc->common = 0;
    return 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CreateListView(struct ResearchProc *proc)
{
    struct ListViewState *r = ListViewState_Create(proc->heapId);
    proc->listViewState = r;
    ListViewState_Reset(r);
}

u32 RESEARCH_TOP_DestroyListView(struct ResearchProc *proc)
{
    ListViewState_Destroy(proc->listViewState);
    proc->listViewState = 0;
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
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    BG_SYS_SetPlaneVisible(1, 1);
}

void RESEARCH_TOP_ExitBackgrounds(void)
{
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_Delete();
}

void RESEARCH_TOP_LoadSubAssets(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = ARC_TOOL_CreateHandle(192, heap);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 9, heap);
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(4, ((struct ArcMember *)palette)->data, 512, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 10, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(4, ((NNSG2dCharacterData *)character)->pRawData, ((NNSG2dCharacterData *)character)->szByte, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 11, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(4, ((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(4);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 12, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen2);
    BG_SYS_DrawTile(5, ((char *)screen2 + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(5);
    GFL_HEAP_Free(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_UpdateFrameGraphic(const struct ResearchProc *proc)
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
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 0, heap);
    NNS_G2dGetUnpackedPaletteData(buffer, &palette);
    BG_SYS_LoadPltt(1, ((struct ArcMember *)palette)->data, 512, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 1, heap);
    NNS_G2dGetUnpackedCharacterDataEx(buffer, &character);
    BG_SYS_LoadTileData(1, ((NNSG2dCharacterData *)character)->pRawData, ((NNSG2dCharacterData *)character)->szByte, 0);
    GFL_HEAP_Free(buffer);
    buffer = ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc, 2, heap);
    NNS_G2dGetUnpackedScreenData(buffer, &screen);
    BG_SYS_DrawTile(1, ((char *)screen + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(1);
    GFL_HEAP_Free(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

struct ResearchObjC *RESEARCH_TOP_CreateListObject(struct ResearchCommon *owner)
{
    u32 heapId = RESEARCH_COMMON_GetHeapId(owner);
    struct ResearchObjC *obj = RESEARCH_TOP_AllocListObject(heapId);
    RESEARCH_TOP_InitFields(obj);
    RESEARCH_TOP_SetHeapId(obj, heapId);
    RESEARCH_TOP_SetOwner(obj, owner);
    return obj;
}

u32 RESEARCH_TOP_DestroyListObject(struct ResearchObjC *obj)
{
    RESEARCH_TOP_DestroyCommandQueue(obj);
    return RESEARCH_TOP_FreeListObject(obj);
}

void RESEARCH_TOP_UpdateListObject(struct ResearchObjC *obj)
{
    switch (obj->command) {
    case 0:RESEARCH_TOP_InitListObject(obj);break;
    case 1:RESEARCH_TOP_HandleListInput(obj);break;
    case 2:RESEARCH_TOP_HandleListInputAlt(obj);break;
    case 3:RESEARCH_TOP_AdvanceListScroll(obj);break;
    case 4:RESEARCH_TOP_StepExitFade(obj);break;
    case 5:RESEARCH_TOP_CleanupListObject(obj);break;
    case 6:return;
    }
    if (RESEARCH_TOP_IsListObjectDone(obj)==0) {
        RESEARCH_TOP_CheckQuestionnaire(obj);RESEARCH_TOP_UpdateEntryPaletteAnime(obj);
        RESEARCH_COMMON_UpdatePaletteAnime(obj->owner);CLACT_DrawSystem();
    }
    RESEARCH_TOP_IncStateTimer(obj);RESEARCH_TOP_ProcessCommand(obj);
}

int RESEARCH_TOP_IsListObjectDone(struct ResearchObjC *obj)
{
    if (obj->exitRequested != 0) {
        return 1;
    }
    return 0;
}

/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_TOP_GetListObjectMode(struct ResearchObjC *obj)
{
    return obj->mode;
}

void RESEARCH_TOP_InitListObject(struct ResearchObjC *obj)
{
    unsigned kind;
    RESEARCH_TOP_CreateCommandQueue(obj);RESEARCH_TOP_CreateFont(obj);
    RESEARCH_TOP_CreateMessages(obj);RESEARCH_TOP_InitPaletteRows(obj);RESEARCH_TOP_InitSelection(obj);
    RESEARCH_TOP_InitOverlayBackgrounds(obj);RESEARCH_TOP_LoadBackground6(obj);RESEARCH_TOP_UpdateBackground7(obj);
    RESEARCH_TOP_LoadBackground2(obj);RESEARCH_TOP_UpdateBackground3(obj);RESEARCH_TOP_CreateLabels(obj);
    RESEARCH_TOP_RegisterEntryResources((struct ResearchObjC *)obj);RESEARCH_TOP_RegisterCursorResources((struct ResearchObjC *)obj);
    RESEARCH_TOP_CreateUnits(obj);RESEARCH_TOP_CreateActor(obj);RESEARCH_TOP_CreatePaletteAnime(obj);
    RESEARCH_TOP_BindPaletteAnime(obj);RESEARCH_TOP_RestartNetwork(obj);RESEARCH_TOP_RegisterVBlank(obj);
    if (RESEARCH_TOP_IsSelectionValid(obj,0)==0)RESEARCH_TOP_SetupTextLabel(obj);
    kind=RESEARCH_TOP_GetTransitionKind(obj);
    RESEARCH_TOP_PushCommand(obj,RESEARCH_TOP_GetTransitionKind(obj));
    if (kind==2) {RESEARCH_TOP_DrawSelector(obj->selection);RESEARCH_TOP_StartEntryPaletteAnime(obj,0);}
    RESEARCH_TOP_FadeIn();RESEARCH_TOP_SetCommandReady(obj);
}

/*
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 */
void RESEARCH_TOP_HandleListInput(struct ResearchObjC *obj)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg((union TouchHitTable *)obj->paletteRows);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(obj->owner));
    if(RESEARCH_TOP_GetInputFlag(obj)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime(obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);return;
    }
    if(keys&2) {
        RESEARCH_TOP_SetEntryHandled(obj,0);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime(obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        RESEARCH_TOP_DrawSelector(obj->selection);RESEARCH_TOP_StartEntryPaletteAnime(obj,0);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,2);return;
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid(obj,0)!=0) {
            RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SetMode(obj,0);RESEARCH_TOP_SelectDirect(obj,0);RESEARCH_TOP_DrawSelector(obj->selection);RESEARCH_TOP_StopEntryPaletteAnime(obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid(obj,1)!=0) {
            RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SetMode(obj,1);RESEARCH_TOP_SelectDirect(obj,1);RESEARCH_TOP_DrawSelector(obj->selection);RESEARCH_TOP_StopEntryPaletteAnime(obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    }
}

void RESEARCH_TOP_HandleListInputAlt(struct ResearchObjC *obj)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg((union TouchHitTable *)obj->paletteRows);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(obj->owner));
    if(RESEARCH_TOP_GetInputFlag(obj)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_StartPaletteAnime(obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);return;
    }
    if(keys&64)RESEARCH_TOP_SelectPrev(obj);
    if(keys&128)RESEARCH_TOP_SelectNext(obj);
    if(keys&1) {
        RESEARCH_TOP_SetEntryHandled(obj,0);RESEARCH_TOP_StopEntryPaletteAnime(obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
        switch(obj->selection) {
        case 0:RESEARCH_TOP_SetMode(obj,0);return;
        case 1:RESEARCH_TOP_SetMode(obj,1);return;
        default:RESEARCH_TOP_SetMode(obj,2);return;
        }
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid(obj,0)!=0) {
            RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SelectDirect(obj,0);RESEARCH_TOP_StopEntryPaletteAnime(obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(obj,0);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid(obj,1)!=0) {
            RESEARCH_TOP_SetEntryHandled(obj,1);RESEARCH_TOP_SelectDirect(obj,1);RESEARCH_TOP_StopEntryPaletteAnime(obj,0);RESEARCH_TOP_StartEntryPaletteAnime(obj,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(obj,1);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(keys&2) {
        RESEARCH_TOP_StartPaletteAnime(obj);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetMode(obj,2);RESEARCH_TOP_SetStateTimer(obj,15);RESEARCH_TOP_SetCommandReady(obj);RESEARCH_TOP_PushCommand(obj,3);RESEARCH_TOP_PushCommand(obj,4);RESEARCH_TOP_PushCommand(obj,5);
    }
}

/*
 * Steps the record through RESEARCH_TOP_SetCommandReady while the running count is below
 * RESEARCH_TOP_GetStateTimer().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_AdvanceListScroll(struct ResearchObjC *obj)
{
    u32 limit = RESEARCH_TOP_GetStateTimerLimit(obj);
    if (limit < RESEARCH_TOP_GetStateTimer(obj)) {
    RESEARCH_TOP_SetCommandReady(obj);
    }
}

void RESEARCH_TOP_StepExitFade(struct ResearchObjC *obj)
{
    switch (RESEARCH_TOP_GetCommandTimer(obj)) {
    case 0:
    RESEARCH_TOP_FadeOut();
    RESEARCH_TOP_IncCommandTimer(obj);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_TOP_SetCommandReady(obj);
    }
    break;
    }
}

void RESEARCH_TOP_CleanupListObject(struct ResearchObjC *obj)
{
    RESEARCH_TOP_UnregisterVBlank();
    RESEARCH_COMMON_StopPaletteAnime(obj->owner);
    RESEARCH_COMMON_RestorePaletteAnime(obj->owner);
    RESEARCH_TOP_RestorePaletteAnime(obj);
    RESEARCH_TOP_DestroyPaletteAnime(obj);
    RESEARCH_TOP_DeleteActor(obj);
    RESEARCH_TOP_DeleteUnits(obj);
    RESEARCH_TOP_ReleaseEntryResources(obj);
    RESEARCH_TOP_ReleaseCursorResources(obj);
    RESEARCH_TOP_DestroyLabels(obj);
    RESEARCH_TOP_ShowBackground3(obj);
    RESEARCH_TOP_DummyBg3(obj);
    RESEARCH_TOP_ShowBackground7(obj);
    RESEARCH_TOP_DummyBg7(obj);
    RESEARCH_TOP_ExitOverlayBackgrounds(obj);
    RESEARCH_TOP_DeleteMessages(obj);
    RESEARCH_TOP_DeleteFont(obj);
    obj->exitRequested = 1;
    RESEARCH_TOP_PushCommand(obj, 6);
    RESEARCH_TOP_SetCommandReady(obj);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_PushCommand(struct ResearchObjC *obj, u32 command)
{
    RingQueue_Push((struct RingQueue *)((obj->commandQueue)), command);
}

void RESEARCH_TOP_SetCommandReady(struct ResearchObjC *obj)
{
    obj->commandReady = 1;
}

void RESEARCH_TOP_ProcessCommand(struct ResearchObjC *obj)
{
    if (obj->commandReady != 0) {
    if (RingQueue_IsEmpty((struct RingQueue *)(obj->commandQueue)) == 0) {
    RESEARCH_TOP_StartCommand(obj, RingQueue_Pop((struct RingQueue *)(obj->commandQueue)));
    }
    }
}

/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StartCommand(struct ResearchObjC *obj, u32 command)
{
    obj->command = command;
    obj->commandTimer = 0;
    obj->stateTimer = 0;
    obj->commandReady = 0;
}

u32 RESEARCH_TOP_GetCommandTimer(struct ResearchObjC *obj)
{
    return obj->commandTimer;
}

void RESEARCH_TOP_IncCommandTimer(struct ResearchObjC *obj)
{
    u32 *counter = &obj->commandTimer;
    *counter += 1;
}

u32 RESEARCH_TOP_GetTransitionKind(struct ResearchObjC *obj)
{
    struct ResearchCommon *owner = obj->owner;
    u32 prevScreen = RESEARCH_COMMON_GetPreviousScreen(owner);
    u32 entryHandled = RESEARCH_COMMON_GetEntryHandled(owner);
    if (prevScreen != 0 && entryHandled == 0) {
    return 2;
    }
    return 1;
}

void RESEARCH_TOP_SetEntryHandled(struct ResearchObjC *obj, u32 handled)
{
    RESEARCH_COMMON_SetEntryHandled((struct ResearchCommon *)(*(u8 * *)&obj->owner), handled);
}

void RESEARCH_TOP_SetMode(struct ResearchObjC *obj, u32 mode)
{
    obj->mode = mode;
}

/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_CheckQuestionnaire(struct ResearchObjC *obj)
{
    if (obj->questionnaireLatched == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    obj->questionnaireLatched = 1;
    RESEARCH_TOP_ShowEntryActor(obj);
    }
    }
}

void RESEARCH_TOP_SelectPrev(struct ResearchObjC *obj)
{
    RESEARCH_TOP_DrawSelectorIdle(obj->selection);
    RESEARCH_TOP_MoveSelection(obj, -1);
    RESEARCH_TOP_DrawSelector(obj->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime(obj, 1);
}

void RESEARCH_TOP_SelectNext(struct ResearchObjC *obj)
{
    RESEARCH_TOP_DrawSelectorIdle(obj->selection);
    RESEARCH_TOP_MoveSelection(obj, 1);
    RESEARCH_TOP_DrawSelector(obj->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime(obj, 1);
}

void RESEARCH_TOP_SelectDirect(struct ResearchObjC *obj, u32 selection)
{
    RESEARCH_TOP_DrawSelectorIdle(obj->selection);
    RESEARCH_TOP_SetSelection(obj, selection);
    RESEARCH_TOP_DrawSelector(obj->selection);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_TOP_StartEntryPaletteAnime(obj, 1);
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

void RESEARCH_TOP_SetupTextLabel(struct ResearchObjC *obj)
{
    BgTextLabel_SetPalette((struct BgTextLabel *)(obj->labels[2]), 15);
    RESEARCH_TOP_StartEntryPaletteAnime(obj, 3);
    RESEARCH_TOP_StartEntryPaletteAnime(obj, 4);
}

void RESEARCH_TOP_StartPaletteAnime(struct ResearchObjC *obj)
{
    RESEARCH_COMMON_StartPaletteAnime(obj->owner, 0);
}

void RESEARCH_TOP_ShowEntryActor(struct ResearchObjC *obj)
{
    struct ClactActor *actor = RESEARCH_TOP_GetEntryIconSource(obj, 0);
    CLACT_SetActorDrawEnable(actor, 1);
    CLACT_SetActorAutoAnim(actor, 1);
    CLACT_SetActorAutoAnimSpeed(actor, 4096);
    CLACT_SetActorAnimFrame(actor, 0);
}

void RESEARCH_TOP_FadeIn(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void RESEARCH_TOP_FadeOut(void)
{
    FADE_Start(3, 0, 16, 0);
}

void RESEARCH_TOP_IncStateTimer(struct ResearchObjC *obj)
{
    u32 *counter = &obj->stateTimer;
    *counter += 1;
}

u32 RESEARCH_TOP_GetStateTimer(struct ResearchObjC *obj)
{
    return obj->stateTimer;
}

/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetStateTimer(struct ResearchObjC *obj, u32 limit)
{
    obj->stateTimerLimit = limit;
}

u32 RESEARCH_TOP_GetStateTimerLimit(struct ResearchObjC *obj)
{
    return obj->stateTimerLimit;
}

void RESEARCH_TOP_MoveSelection(struct ResearchObjC *obj, int delta)
{
    int selection = obj->selection;
    do {
        selection = (selection + delta + 2) % 2;
    } while (!RESEARCH_TOP_IsSelectionValid(obj, selection));
    obj->selection = selection;
}

/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetSelection(struct ResearchObjC *obj, u32 selection)
{
    obj->selection = selection;
}

u32 RESEARCH_TOP_IsSelectionValid(struct ResearchObjC *obj, u32 selection)
{
    if (selection == 0) {
    if (RESEARCH_TOP_CountUnlockedEntries(obj) > 1) {
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
u32 RESEARCH_TOP_GetEntryActorSource(struct ResearchObjC *obj, u32 index)
{
    return obj->resources[index];
}

/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
struct Unit *RESEARCH_TOP_GetEntryLabelSource(struct ResearchObjC *obj, u32 index)
{
    return obj->units[index];
}

/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
struct ClactActor *RESEARCH_TOP_GetEntryIconSource(struct ResearchObjC *obj, u32 index)
{
    return (&obj->actor)[index];
}

void RESEARCH_TOP_StartEntryPaletteAnime(struct ResearchObjC *obj, int slot)
{
    PALETTE_ANIME_Start(obj->paletteAnime[slot],
                  *(u32 *)(d_021C3004 + slot * 0x14),
                  *(u16 *)(d_021C3008 + slot * 0x14));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_StopEntryPaletteAnime(struct ResearchObjC *obj, u32 slot)
{
    PALETTE_ANIME_Stop((struct PaletteAnime *)((obj->paletteAnime[slot])));
}

void RESEARCH_TOP_UpdateEntryPaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Update(obj->paletteAnime[i]);
}

/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char RESEARCH_TOP_CountUnlockedEntries(struct ResearchObjC *obj)
{
    void *bitmap=(void *)GAME_DATA_GetEventWork((struct GameData *)RESEARCH_COMMON_GetAppResource(obj->owner));
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

struct ResearchCommon *RESEARCH_TOP_GetOwner(struct ResearchObjC *obj)
{
    return obj->owner;
}

void RESEARCH_TOP_SetOwner(struct ResearchObjC *obj, struct ResearchCommon *owner)
{
    obj->owner = owner;
}

/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_SetHeapId(struct ResearchObjC *obj, u32 heapId)
{
    obj->heapId = heapId;
}

u32 RESEARCH_TOP_GetInputFlag(struct ResearchObjC *obj)
{
    return RESEARCH_COMMON_GetInputFlag(RESEARCH_TOP_GetOwner(obj));
}

struct ResearchObjC *RESEARCH_TOP_AllocListObject(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct ResearchObjC), 0, (const char *)0x21C3FEC, 1486);
}

u32 RESEARCH_TOP_FreeListObject(struct ResearchObjC *obj)
{
    return GFL_HEAP_Free(obj);
}

/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void RESEARCH_TOP_InitFields(struct ResearchObjC *obj)
{
    obj->commandReady=0;obj->questionnaireLatched=0;obj->exitRequested=0;
    obj->command=0;obj->stateTimer=0;obj->stateTimerLimit=0;
    obj->selection=0;obj->mode=2;obj->commandTimer=0;
    RESEARCH_TOP_ClearResources(obj);RESEARCH_TOP_ClearCommandQueue(obj);RESEARCH_TOP_ClearMessages(obj);RESEARCH_TOP_ClearFont(obj);
    RESEARCH_TOP_ClearLabels(obj);RESEARCH_TOP_ClearUnits(obj);RESEARCH_TOP_ClearActor(obj);RESEARCH_TOP_ClearPaletteAnime(obj);
}

void RESEARCH_TOP_InitSelection(struct ResearchObjC *obj)
{
    void *owner=obj->owner;
    unsigned prevScreen=RESEARCH_COMMON_GetPreviousScreen(owner),entryHandled=RESEARCH_COMMON_GetEntryHandled(owner);
    if(prevScreen!=0 && entryHandled==0) {
        unsigned mode;
        switch(prevScreen) {case 2:default:mode=0;break;case 3:mode=1;break;}
        RESEARCH_TOP_SetSelection(obj,mode);
    } else {
        if(RESEARCH_TOP_IsSelectionValid(obj,0)!=0) RESEARCH_TOP_SetSelection(obj,0);
        else RESEARCH_TOP_SetSelection(obj,1);
    }
}

void RESEARCH_TOP_ClearFont(struct ResearchObjC *obj)
{
    obj->font = 0;
}

void RESEARCH_TOP_CreateFont(struct ResearchObjC *obj)
{
    u8 scratch[4];
    obj->font = GF_FONT_Create(23, 0, 0, 0, (u32)(obj->heapId));
}

void RESEARCH_TOP_DeleteFont(struct ResearchObjC *obj)
{
    GF_FONT_Delete(obj->font);
}

/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearMessages(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        obj->messages[i] = 0;
}

void RESEARCH_TOP_CreateMessages(struct ResearchObjC *obj)
{
    int i = 0;
    do {
        int offset = i * 4;
        *(struct MsgBank **)((char *)obj->messages + i * (int)sizeof(void *)) = MSGDATA_CreateFromArchive((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + offset)), (u16)(obj->heapId));
        i++;
    } while (i < 2);
}

void RESEARCH_TOP_DeleteMessages(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete(obj->messages[i]);
}

void RESEARCH_TOP_InitPaletteRows(struct ResearchObjC *obj)
{
    int i = 0;
    do {
        int offset = i * 4;
        u8 *src = d_021C2EE0 + offset;
#ifdef __MWERKS__
        ((u8 *)obj)[offset + 0x2e] = src[0];
        ((u8 *)obj)[offset + 0x2f] = src[1];
        ((u8 *)obj)[offset + 0x2c] = src[2];
        ((u8 *)obj)[offset + 0x2d] = src[3];
#else
        obj->paletteRows[i][2] = src[0];
        obj->paletteRows[i][3] = src[1];
        obj->paletteRows[i][0] = src[2];
        obj->paletteRows[i][1] = src[3];
#endif
        i++;
    } while (i < 3);
}

void RESEARCH_TOP_ClearCommandQueue(struct ResearchObjC *obj)
{
    obj->commandQueue = 0;
}

void RESEARCH_TOP_CreateCommandQueue(struct ResearchObjC *obj)
{
    obj->commandQueue = RingQueue_Create(10, obj->heapId);
}

void RESEARCH_TOP_DestroyCommandQueue(struct ResearchObjC *obj)
{
    RingQueue_Destroy(obj->commandQueue);
}

void RESEARCH_TOP_InitOverlayBackgrounds(struct ResearchObjC *obj)
{
    BG_SYS_SetGraphicsMode(&d_021C2EEC);
    BG_SYS_InitBgLayer(6,&d_021C2F78,0);BG_SYS_InitBgLayer(7,&d_021C2F18,0);
    BG_SYS_InitBgLayer(2,&d_021C2F38,0);BG_SYS_InitBgLayer(3,&d_021C2F58,0);
    BG_SYS_SetPlaneVisible(4,1);BG_SYS_SetPlaneVisible(5,1);BG_SYS_SetPlaneVisible(6,1);BG_SYS_SetPlaneVisible(7,1);
    BG_SYS_SetPlaneVisible(1,1);BG_SYS_SetPlaneVisible(2,1);BG_SYS_SetPlaneVisible(3,1);
    G2x_SetBlendAlpha_((volatile unsigned *)REG_DB_BLDCNT_ADDR,2,1,7,15);
    G2x_SetBlendAlpha_((volatile unsigned *)REG_BLDCNT_ADDR,4,2,16,5);
    BMP_WIN_Init(obj->heapId);
}

void RESEARCH_TOP_ExitOverlayBackgrounds(struct ResearchObjC *obj)
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
}

void RESEARCH_TOP_LoadBackground6(struct ResearchObjC *obj)
{
    struct ArcHandle *arc=ARC_TOOL_CreateHandle(192,obj->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,13,obj->heapId);
    void *data;
    NNS_G2dGetUnpackedScreenData(file,&data);
    BG_SYS_DrawTile(6,((char *)data+12),0,0,32,24);
    BG_SYS_PushTile(6);GFL_HEAP_Free(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg7(struct ResearchObjC *unused)
{
}

void RESEARCH_TOP_UpdateBackground7(struct ResearchObjC *obj)
{
    BG_SYS_Init(7, 0, 1, 0);
    BG_SYS_ClearSlot(7);
}

void RESEARCH_TOP_ShowBackground7(struct ResearchObjC *obj)
{
    BG_SYS_FreeTiles(7, 1, 0);
}

void RESEARCH_TOP_LoadBackground2(struct ResearchObjC *obj)
{
    struct ArcHandle *arc=ARC_TOOL_CreateHandle(192,obj->heapId);
    void *file=ARC_TOOL_LoadHandleMember(arc,4,obj->heapId);
    void *data;
    NNS_G2dGetUnpackedScreenData(file,&data);
    BG_SYS_DrawTile(2,((char *)data+12),0,0,32,24);
    BG_SYS_PushTile(2);GFL_HEAP_Free(file);ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_DummyBg3(struct ResearchObjC *unused)
{
}

void RESEARCH_TOP_UpdateBackground3(struct ResearchObjC *obj)
{
    BG_SYS_Init(3, 0, 1, 0);
    BG_SYS_ClearSlot(3);
}

void RESEARCH_TOP_ShowBackground3(struct ResearchObjC *obj)
{
    BG_SYS_FreeTiles(3, 1, 0);
}

void RESEARCH_TOP_ClearLabels(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 4; i++)
        obj->labels[i] = 0;
}

void RESEARCH_TOP_CreateLabels(struct ResearchObjC *obj)
{
    struct LabelTemplate tmpl;
    int i;
    for(i=0;i<4;i++) {
        const struct LabelEntry *entry=&d_021C2F98[i];
        tmpl.params[0]=entry->template.params[0];tmpl.params[1]=entry->template.params[1];tmpl.params[2]=entry->template.params[2];tmpl.params[3]=entry->template.params[3];
        tmpl.params[4]=entry->template.params[4];tmpl.params[5]=entry->template.params[5];tmpl.params[6]=entry->template.params[6];tmpl.params[7]=entry->template.params[7];
        tmpl.params[8]=entry->template.params[8];tmpl.params[9]=entry->template.params[9];tmpl.params[10]=entry->template.params[10];tmpl.messageIndex=entry->extraId;
        obj->labels[i]=BgTextLabel_Create((struct BgTextLabelConfig *)(&tmpl),obj->font,obj->messages[entry->template.messageIndex],obj->heapId);
        BgTextLabel_PrintMessage(obj->labels[i],entry->messageId);
    }
}

void RESEARCH_TOP_DestroyLabels(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 4; i++) {
        BgTextLabel_Destroy(obj->labels[i]);
        obj->labels[i] = 0;
    }
}

/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearResources(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 6; i++)
        obj->resources[i] = 0;
}

/*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
void RESEARCH_TOP_RegisterEntryResources(struct ResearchObjC *p)
{
    u16 heap=p->heapId;
    void *arc=ARC_TOOL_CreateHandle(192,heap);
    int charHandle=CLACT_RegisterCharacter((void *)(arc),15,0,1,heap);
    int paletteHandle=CLACT_RegisterPalette((void *)arc,16,1,0,heap);
    int cellHandle=CLACT_RegisterCellAnim((void *)(arc),14,17,heap);
    p->entryCharacter=charHandle;p->entryPalette=paletteHandle;p->entryCell=cellHandle;
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_ReleaseEntryResources(struct ResearchObjC *obj)
{
    CLACT_ReleaseCharacter(obj->entryCharacter);
    CLACT_ReleasePalette(obj->entryPalette);
    CLACT_ReleaseCellAnim(obj->entryCell);
}

void RESEARCH_TOP_RegisterCursorResources(struct ResearchObjC *p)
{
    u16 heap=p->heapId;
    void *arc=ARC_TOOL_CreateHandle(192,heap);
    int charHandle=CLACT_RegisterCharacter((void *)(arc),15,0,0,heap);
    int paletteHandle=CLACT_RegisterPaletteEx((void *)(arc),16,0,192,0,4,heap);
    int cellHandle=CLACT_RegisterCellAnim((void *)(arc),14,17,heap);
    p->cursorCharacter=charHandle;p->cursorPalette=paletteHandle;p->cursorCell=cellHandle;
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_TOP_ReleaseCursorResources(struct ResearchObjC *obj)
{
    CLACT_ReleaseCharacter(obj->cursorCharacter);
    CLACT_ReleasePalette(obj->cursorPalette);
    CLACT_ReleaseCellAnim(obj->cursorCell);
}

void RESEARCH_TOP_ClearUnits(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        obj->units[i] = 0;
}

void RESEARCH_TOP_CreateUnits(struct ResearchObjC *obj)
{
    int i = 0;
    do {
        obj->units[i] = CLACT_CreateUnit(d_021C2ED2[i], d_021C2ED0[i], obj->heapId);
        i++;
    } while (i < 2);
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_DeleteUnits(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 2; i++)
        CLACT_DeleteUnit(obj->units[i]);
}

/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearActor(struct ResearchObjC *obj)
{
    obj->actor = 0;
}

/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void RESEARCH_TOP_CreateActor(struct ResearchObjC *obj)
{
    struct ResearchTopActorSpawnPos pos;
    struct Unit *labelSource; unsigned actorSourceA, actorSourceB, actorSourceC;
    pos.x=d_021C2EFC.pos.x;pos.y=d_021C2EFC.pos.y;pos.z=d_021C2EFC.pos.z;
    pos.a=d_021C2EFC.pos.a;pos.b=d_021C2EFC.pos.b;
    labelSource=RESEARCH_TOP_GetEntryLabelSource(obj,d_021C2EFC.firstSource);
    actorSourceA=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.secondSource);
    actorSourceB=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.thirdSource);
    actorSourceC=RESEARCH_TOP_GetEntryActorSource(obj,d_021C2EFC.fourthSource);
    obj->actor=CLACT_CreateActor(labelSource,actorSourceA,actorSourceB,actorSourceC,(struct ActorInitParam *)(&pos),d_021C2EFC.arg,obj->heapId);
    CLACT_SetActorDrawEnable(obj->actor,0);
}

void RESEARCH_TOP_DeleteActor(struct ResearchObjC *obj)
{
    CLACT_DeleteActor(obj->actor);
}

/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_ClearPaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        obj->paletteAnime[i] = 0;
}

void RESEARCH_TOP_CreatePaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        obj->paletteAnime[i] = PALETTE_ANIME_Create(obj->heapId);
}

void RESEARCH_TOP_DestroyPaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Destroy(obj->paletteAnime[i]);
}

void RESEARCH_TOP_BindPaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Bind((void *)(obj->paletteAnime[i]), (unsigned short *)d_021C2FF8[i].palette, (unsigned short *)d_021C2FF8[i].source, d_021C2FF8[i].mode);
    }
}

void RESEARCH_TOP_RestorePaletteAnime(struct ResearchObjC *obj)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Restore((struct PaletteAnime *)(obj->paletteAnime[i]));
    }
}

/*
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for RESEARCH_TOP_RegisterVBlank (pkt_021B9850).
 */
void RESEARCH_TOP_UpdateVBlank(struct TcbTask *unused, void *unused2)
{
    CLACT_VBlankSystem();
}

void RESEARCH_TOP_RegisterVBlank(struct ResearchObjC *obj)
{
    GFL_USE_SetVBlankHook(RESEARCH_TOP_UpdateVBlank, 0);
}

/*
 * Tail-call veneer: branch to GFL_USE_ClearVBlankHook.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_TOP_UnregisterVBlank(void)
{
    GFL_USE_ClearVBlankHook();
}

void RESEARCH_TOP_RestartNetwork(struct ResearchObjC *obj)
{
    GFL_NET_RefreshWmIconAtTopRight(1, obj->heapId);
}
