/*
 * file:     bsubway_record_list.c
 * unit:     yes
 * function: BSUBWAY_RECORD_LIST_Init, BSUBWAY_RECORD_LIST_Main, BSUBWAY_RECORD_LIST_Exit, BSUBWAY_RECORD_LIST_VBlankTask, BSUBWAY_RECORD_LIST_InitWork, BSUBWAY_RECORD_LIST_FreeWork, BSUBWAY_RECORD_LIST_SetupVramBanks, BSUBWAY_RECORD_LIST_SetupBgLayers, BSUBWAY_RECORD_LIST_ReleaseBgLayers, BSUBWAY_RECORD_LIST_LoadGraphics, BSUBWAY_RECORD_LIST_DeleteFrames, BSUBWAY_RECORD_LIST_SetupActors, BSUBWAY_RECORD_LIST_CreateActors, BSUBWAY_RECORD_LIST_DeleteActors, BSUBWAY_RECORD_LIST_CreateWindows, BSUBWAY_RECORD_LIST_DeleteWindows, BSUBWAY_RECORD_LIST_InitText, BSUBWAY_RECORD_LIST_ExitText, BSUBWAY_RECORD_LIST_UpdateText, BSUBWAY_RECORD_LIST_RunInputState, BSUBWAY_RECORD_LIST_StateFadeIn, BSUBWAY_RECORD_LIST_StateInput, BSUBWAY_RECORD_LIST_StateBackAnim, BSUBWAY_RECORD_LIST_StateFadeOutStart, BSUBWAY_RECORD_LIST_StateFadeOutWait, BSUBWAY_RECORD_LIST_InitCursor, BSUBWAY_RECORD_LIST_DeleteCursor, BSUBWAY_RECORD_LIST_CursorCallbackMoved, BSUBWAY_RECORD_LIST_CursorCallbackMovedAlt, BSUBWAY_RECORD_LIST_PlaceCursorActor, BSUBWAY_RECORD_LIST_ShowRecordDetails, BSUBWAY_RECORD_LIST_PollTouchAndCancel, BSUBWAY_RECORD_LIST_HandleAction, BSUBWAY_RECORD_LIST_InitPageCount, BSUBWAY_RECORD_LIST_UpdateArrowVisibility, BSUBWAY_RECORD_LIST_ChangePage, BSUBWAY_RECORD_LIST_ShowPage, BSUBWAY_RECORD_LIST_GetRowCountOnPage, BSUBWAY_RECORD_LIST_DrawPageRows, BSUBWAY_RECORD_LIST_DrawRowName
 * address:  0x021B95A0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   BSUBWAY_RECORD_LIST_CreateActors  0x021B9B44  thumb  ov069
 *   BSUBWAY_RECORD_LIST_CreateWindows  0x021B9C44  thumb  ov069
 *   BSUBWAY_RECORD_LIST_InitText  0x021B9D08  thumb  ov069
 *   BSUBWAY_RECORD_LIST_InitCursor  0x021B9F24  thumb  ov069
 *   BSUBWAY_RECORD_LIST_UpdateArrowVisibility  0x021BA384  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ShowPage  0x021BA438  thumb  ov069
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BSUBWAY_RECORD_LIST_RunInputState 0x021B9E44 thumb ov069
 *   BSUBWAY_RECORD_LIST_UpdateText 0x021B9DFC thumb ov069
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BSUBWAY_RECORD_LIST_DeleteCursor  0x021B9F58  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ExitText  0x021B9DE8  thumb  ov069
 *   BSUBWAY_RECORD_LIST_DeleteWindows  0x021B9CD8  thumb  ov069
 *   BSUBWAY_RECORD_LIST_DeleteActors  0x021B9BF0  thumb  ov069
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_GetHeapHeadChecked  0x0203084C  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Create  0x0201EC74  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   BSUBWAY_RECORD_LIST_InitPageCount  0x021BA350  thumb  ov069
 *   GFL_HEAP_Free  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   sRecordListVramBanks 0x021BA620 data a4
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   sRecordListDispConfig  0x021BA65C  data  a4
 *   sRecordListBgTemplates  0x021BA7A0  data  a4
 *   sRecordListBgIds  0x021BA60C  data  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BGWINFRM_SetFrameDataArcHandle  0x0202CB18  thumb
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb
 *   sRecordListFramePositions     0x021BA66C  data  a4
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   CLACT_CreateUnit  0x0204B100  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   sActorTemplates  0x021BA6BC  data  a4
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   sWindowTemplates  0x021BA874  data  a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   sInputStateFuncs 0x021BA860 data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   CURSOR_MOVE_PollInput  0x02025D2C  thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   sCursorEntries 0x021BA71C data a4
 *   sCursorCallbacks 0x021BA5EC data a4
 *   CURSOR_MOVE_Delete 0x02025D14 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_GetEntry 0x0202616C thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   sTouchRects 0x021BA5FC data a4
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BSUBWAY_RECORD_LIST_DrawRowName  0x021BA520  thumb  ov069
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BGWINFRM_ShowFrame  0x0202CC58  thumb
 */
#include "bsubway_record_list_types.h"

struct BsubwayWifiData;
struct BsubwayWifiRecordList;
struct Proc;
struct DispVram;
struct ActorSystemConfig;

typedef struct {
    int x;
    int y;
} Pos;

/* Display configuration, four words. */
struct DispConfig {
    u32 word[4];
};

/* Background template, eight words. */
struct BgTemplate {
    u32 word[8];
};

struct BgTemplateSet {
    struct BgTemplate bg[5];
};

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heap);
extern void  MIi_CpuClearFast(u32 val, void *dst, u32 size);
extern void  WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void BSUBWAY_RECORD_LIST_CreateActors(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_CreateWindows(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_InitText(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_InitCursor(BsubwayRecordListWork *work);
extern void  BSUBWAY_RECORD_LIST_UpdateArrowVisibility(BsubwayRecordListWork *work, int page, int pageCount);
extern void BSUBWAY_RECORD_LIST_ShowPage(BsubwayRecordListWork *work, int page);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern void  GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int BSUBWAY_RECORD_LIST_RunInputState(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_UpdateText(BsubwayRecordListWork *work);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void CLACT_DrawSystem(void);
extern int BSUBWAY_RECORD_LIST_DeleteCursor(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_ExitText(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_DeleteWindows(BsubwayRecordListWork *work);
extern void BSUBWAY_RECORD_LIST_DeleteActors(BsubwayRecordListWork *work);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void *GFL_HEAP_GetHeapHeadChecked(u32 heapId);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u16 *STRBUF_GetChars(struct Strbuf *vec);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern void *GFL_USE_AddMainTask(void (*fn)(void), void *arg, u32 priority);
extern void *GAME_DATA_GetSaveBlock3B(struct GameData *gameData);
extern struct BsubwayWifiRecordList *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct BsubwayWifiData *saveBlock, u32 heap);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct BsubwayWifiRecordList *recordList);
extern void BSUBWAY_RECORD_LIST_InitPageCount(BsubwayRecordListWork *work);
extern u32 GFL_HEAP_Free(void *p);
extern void STRBUF_Delete(struct Strbuf *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void TCB_DeleteTask(void *task);
extern void ARC_TOOL_DeleteHandle(void *p);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u8);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(u32 layer);
extern void BG_SYS_Delete(void);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);
extern struct WinMgr *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void CLACT_InitSystem(const struct ActorSystemConfig *cfg, const struct DispVram *vram, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_Update(void);
int BSUBWAY_RECORD_LIST_Init(void *proc, u32 unusedSeq, BsubwayRecordListArgs *args);
int BSUBWAY_RECORD_LIST_Main(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_Exit(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_VBlankTask(void);
void BSUBWAY_RECORD_LIST_InitWork(BsubwayRecordListWork *work, BsubwayRecordListArgs *args);
void BSUBWAY_RECORD_LIST_FreeWork(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_SetupVramBanks(void);
void BSUBWAY_RECORD_LIST_SetupBgLayers(BsubwayRecordListWork *unusedWork);
void BSUBWAY_RECORD_LIST_ReleaseBgLayers(BsubwayRecordListWork *unusedWork);
void BSUBWAY_RECORD_LIST_LoadGraphics(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_DeleteFrames(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_SetupActors(BsubwayRecordListWork *work);
extern const struct DispVram sRecordListVramBanks;
extern const struct DispConfig sRecordListDispConfig;
extern const struct BgTemplateSet sRecordListBgTemplates;
extern const u32 sRecordListBgIds[];
extern const Pos sRecordListFramePositions[];
extern const struct ActorSystemConfig gClActorInitParam;


#define SE_CURSOR_MOVE 0x548
#define SE_CANCEL      0x551
#define KEY_B_BUTTON   2
#define ARROW_ANIM_PREV 12
#define ARROW_ANIM_NEXT 13
#define BACK_ANIM_PRESS 9

struct Bitmap;
struct Strbuf;
struct WordSet;
struct Vec2;

typedef short s16;

/* Sprite template: position and the resource indexes (into spriteRes). */
typedef struct ActorTemplate {
    int x;
    int y;
    int z;
    int charRes;
    int palRes;
    int cellRes;
} ActorTemplate;

typedef struct ActorSetup {
    s16 x;
    s16 y;
    s16 z;
    u8 animIndex;
    u8 bgPriority;
} ActorSetup;

/* Window template of the text windows. */
typedef struct BmpWinTemplate {
    u32 layer;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u16 charBase;
} BmpWinTemplate;

typedef struct CursorPos {
    u16 x;
    u16 y;
} CursorPos;

typedef int (*InputStateFunc)(BsubwayRecordListWork *work);

extern struct Actor *CLACT_CreateActor(struct Bank *bank, unsigned int charRes, unsigned int palRes, unsigned int cellRes, const ActorSetup *setup, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, unsigned int enabled);
extern void CLACT_ReleaseCharacter(u32 res);
extern void CLACT_ReleasePalette(u32 res);
extern void CLACT_ReleaseCellAnim(u32 res);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Init(u16 heapId);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 charBase, u8 palette);
extern struct Bitmap *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bitmap *bitmap, u8 fill);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void BMP_WIN_Exit(void);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern struct PrintSys *PRINTSYS_QUE_Create(u32 heapId);
extern void PRINTSYS_PrintQueColor(struct PrintSys *printSys, struct Bitmap *bitmap, u32 x, u32 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void PRINTSYS_QUE_Delete(struct PrintSys *printSys);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *printSys);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *printSys, struct Bitmap *bitmap);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *printSys);
extern int CURSOR_MOVE_PollInput(struct CursorMove *cursor);
extern u32 CLACT_IsActorAnimActive(struct Actor *actor);
extern struct CursorMove *CURSOR_MOVE_Create(const void *entries, const void *callbacks, void *work, u32 state, u8 start, u16 heapId);
extern u32 CURSOR_MOVE_Delete(struct CursorMove *cursor);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern const u8 *CURSOR_MOVE_GetEntry(struct CursorMove *cursor, unsigned int index);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, const struct Vec2 *delta, u32 which);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *wordSet, u32 index, u32 trainerClass);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *wordSet, u32 index, u32 trainerClass, u32 trainerIndex);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, void *dst, void *src);
extern void STRBUF_SetStringN(struct Strbuf *dst, const u16 *src, u32 len);
extern struct Strbuf *PMSI_PARAM_ToString(const BsubwayPmsData *pms, unsigned int heap);
extern void BG_SYS_SetFlagField06(u32);
extern int TOUCHPANEL_HitTrg(const void *rects);
extern unsigned KEY_GetTrg(void);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 animIndex);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int enabled);
extern u8 CURSOR_MOVE_GetCurrent(struct CursorMove *cursor);
extern void BSUBWAY_RECORD_LIST_DrawRowName(BsubwayRecordListWork *work, int row, struct Strbuf *name, int isFemale);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
int BSUBWAY_RECORD_LIST_StateFadeIn(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateInput(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateBackAnim(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateFadeOutStart(BsubwayRecordListWork *work);
int BSUBWAY_RECORD_LIST_StateFadeOutWait(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_CursorCallbackNop0(void);
void BSUBWAY_RECORD_LIST_CursorCallbackNop1(void);
void BSUBWAY_RECORD_LIST_CursorCallbackMoved(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_CursorCallbackMovedAlt(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_PlaceCursorActor(BsubwayRecordListWork *work, int row);
void BSUBWAY_RECORD_LIST_ShowRecordDetails(BsubwayRecordListWork *work, BsubwayWifiRecord *records, int index);
int BSUBWAY_RECORD_LIST_PollTouchAndCancel(BsubwayRecordListWork *work);
void BSUBWAY_RECORD_LIST_HandleAction(BsubwayRecordListWork *work, int action);
int BSUBWAY_RECORD_LIST_ChangePage(BsubwayRecordListWork *work, int direction);
int BSUBWAY_RECORD_LIST_GetRowCountOnPage(int page, int pageCountUnused, int entryCount);
void BSUBWAY_RECORD_LIST_DrawPageRows(BsubwayRecordListWork *work);
extern const ActorTemplate sActorTemplates[];
extern const BmpWinTemplate *sWindowTemplates[];
extern InputStateFunc sInputStateFuncs[];
extern const char sCursorEntries[], sCursorCallbacks[];
extern const char sTouchRects[];

struct GfFont;


extern void PRINTSYS_PrintColor(struct Bitmap *bitmap, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, struct BmpWin *win);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);



int BSUBWAY_RECORD_LIST_Init(void *proc, u32 unusedSeq, BsubwayRecordListArgs *args)
{
    BsubwayRecordListWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x80, 0x20000);
    work = PROCSYS_AllocProcWork(proc, sizeof(BsubwayRecordListWork), 0x80);
    MIi_CpuClearFast(0, work, sizeof(BsubwayRecordListWork));
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    BSUBWAY_RECORD_LIST_InitWork(work, args);
    BSUBWAY_RECORD_LIST_SetupVramBanks();
    BSUBWAY_RECORD_LIST_SetupBgLayers(work);
    BSUBWAY_RECORD_LIST_LoadGraphics(work);
    BSUBWAY_RECORD_LIST_SetupActors(work);
    BSUBWAY_RECORD_LIST_CreateActors(work);
    BSUBWAY_RECORD_LIST_CreateWindows(work);
    BSUBWAY_RECORD_LIST_InitText(work);
    BSUBWAY_RECORD_LIST_InitCursor(work);
    BSUBWAY_RECORD_LIST_UpdateArrowVisibility(work, work->page, work->pageCount);
    BSUBWAY_RECORD_LIST_ShowPage(work, work->page);
    WIPE_SYS_Start(0, 1, 1, 0, 0x10, 1, 0x80);
    GFL_NET_RestartWithDefaultTimeout(1, 0x80);
    return 1;
}


int BSUBWAY_RECORD_LIST_Main(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work)
{
    if (BSUBWAY_RECORD_LIST_RunInputState(work) == 0)
        return 1;
    BSUBWAY_RECORD_LIST_UpdateText(work);
    BGWINFRM_UpdateMoves(work->frameMgr);
    CLACT_DrawSystem();
    return 0;
}



int BSUBWAY_RECORD_LIST_Exit(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work)
{
    BSUBWAY_RECORD_LIST_DeleteCursor(work);
    BSUBWAY_RECORD_LIST_ExitText(work);
    BSUBWAY_RECORD_LIST_DeleteWindows(work);
    BSUBWAY_RECORD_LIST_DeleteActors(work);
    BSUBWAY_RECORD_LIST_DeleteFrames(work);
    BSUBWAY_RECORD_LIST_ReleaseBgLayers(work);
    BSUBWAY_RECORD_LIST_FreeWork(work);
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_GetHeapHeadChecked(0x80);
    GFL_HEAP_DeleteChecked(0x80);
    return 1;
}


void BSUBWAY_RECORD_LIST_VBlankTask(void)
{
    CLACT_VBlankSystem();
    BG_SYS_Update();
}



void BSUBWAY_RECORD_LIST_InitWork(BsubwayRecordListWork *work, BsubwayRecordListArgs *args)
{
    int i;

    work->args = args;
    work->chosenEntry = 0;
    work->arcHandle = ARC_TOOL_CreateHandle(0xc7, 0x80);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x39, 0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_MESSAGE_COUNT; i++) {
        work->messages[i] = MSGDATA_AllocString(work->msgBank, i);
        STRBUF_GetChars(work->messages[i]);
    }
    work->textBuf = STRBUF_Create(0x40, 0x80);
    work->wordSet = WORDSET_Create(8, 0x40, 0x80);
    work->vblankTask = GFL_USE_AddMainTask(BSUBWAY_RECORD_LIST_VBlankTask, work, 0);
    work->recordList = BSUBWAY_SAVEDATA_AllocHistoryCopy(GAME_DATA_GetSaveBlock3B(work->args->gameData), 0x80);
    work->entryCount = BSUBWAY_SAVEDATA_CountHistoryEntries(work->recordList);
    BSUBWAY_RECORD_LIST_InitPageCount(work);
}



void BSUBWAY_RECORD_LIST_FreeWork(BsubwayRecordListWork *work)
{
    int i;

    GFL_HEAP_Free(work->recordList);
    for (i = 0; i < BSUBWAY_RECORD_LIST_MESSAGE_COUNT; i++) {
        STRBUF_Delete(work->messages[i]);
    }
    STRBUF_Delete(work->textBuf);
    WORDSET_DeleteStrbufED04(work->wordSet);
    MSGDATA_Delete(work->msgBank);
    TCB_DeleteTask(work->vblankTask);
    ARC_TOOL_DeleteHandle(work->arcHandle);
}


void BSUBWAY_RECORD_LIST_SetupVramBanks(void) { BG_SYS_SetVramBanks(&sRecordListVramBanks); *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000); }



void BSUBWAY_RECORD_LIST_SetupBgLayers(BsubwayRecordListWork *unusedWork)
{
    struct DispConfig dispConfig;
    struct BgTemplateSet bgTemplates;
    u32 i;
    u32 bgId;

    BG_SYS_Create(0x80);
    dispConfig = sRecordListDispConfig;
    BG_SYS_SetGraphicsMode(&dispConfig);
    bgTemplates = sRecordListBgTemplates;
    for (i = 0; i < 5; i++) {
        bgId = sRecordListBgIds[i];
        BG_SYS_InitBgLayer((u8)bgId, &bgTemplates.bg[i], 0);
        BG_SYS_ClearSlot(bgId);
        BG_SYS_InitRun(bgId, 0x20, 0, 0x80);
        BG_SYS_SetPlaneVisible(bgId, 1);
    }
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_SetPlaneVisible(3, 0);
}


void BSUBWAY_RECORD_LIST_ReleaseBgLayers(BsubwayRecordListWork *unusedWork) { u32 i; for(i=0;i<5;i++) BG_SYS_FreeLayerBuf((u8)sRecordListBgIds[i]); BG_SYS_Delete(); }



void BSUBWAY_RECORD_LIST_LoadGraphics(BsubwayRecordListWork *work)
{
    void *uiArc = work->arcHandle;
    void *spriteArc;
    int i;

    ARC_UTIL_UploadBgCharFromHandle(uiArc, 5, 5, 0, 0, 1, 0x80);
    ARC_UTIL_UploadBgPaletteFromHandle(uiArc, 4, 5, 0, 0, 1, 0x80);
    ARC_UTIL_UploadPaletteFromHandleWhole(uiArc, 6, 4, 0, 0, 0x80);
    ARC_UTIL_UploadBgCharFromHandle(uiArc, 1, 2, 0, 0, 1, 0x80);
    ARC_UTIL_UploadBgPaletteFromHandle(uiArc, 0, 2, 0, 0, 1, 0x80);
    ARC_UTIL_UploadPaletteFromHandleWhole(uiArc, 2, 0, 0, 0, 0x80);
    ARC_UTIL_UploadBgCharFromHandle(uiArc, 1, 1, 0, 0, 1, 0x80);
    ARC_UTIL_UploadBgPaletteFromHandle(uiArc, 0, 1, 0, 0, 1, 0x80);
    spriteArc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x80);
    ARC_UTIL_UploadBgCharFromHandle(spriteArc, APP_ICON_GetStatusFrameFileId(), 1, 0, 0, 0, 0x80);
    ARC_UTIL_UploadBgPaletteFromHandle(spriteArc, APP_ICON_GetStatusDataFileId(), 1, 0, 0, 0, 0x80);
    ARC_UTIL_UploadPaletteFromHandle(spriteArc, APP_ICON_GetStatusAnimFileId(), 0, 0, 0x1C0, 0x20, 0x80);
    BG_SYS_FillTileMap(1, 0, 0x15, 0x20, 3, 0xE);
    BG_SYS_PushTile(1);
    ARC_TOOL_DeleteHandle(spriteArc);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1E0, 0x20, 0x80);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1E0, 0x20, 0x80);
    work->frameMgr = BGWINFRM_Create(2, 10, 0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE; i++) {
        BGWINFRM_AddFrame(work->frameMgr, i, 1, 0xE, 4);
        BGWINFRM_SetFrameDataArcHandle(work->frameMgr, i, uiArc, 3, 1);
        BGWINFRM_PutFrame(work->frameMgr, i, sRecordListFramePositions[i].x, sRecordListFramePositions[i].y);
    }
}


void BSUBWAY_RECORD_LIST_DeleteFrames(BsubwayRecordListWork *work)
{
    BGWINFRM_Delete(work->frameMgr);
}



void BSUBWAY_RECORD_LIST_SetupActors(BsubwayRecordListWork *work)
{
    void *spriteArc;
    u32 cellAnimId;

    spriteArc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x80);
    CLACT_InitSystem(&gClActorInitParam, &sRecordListVramBanks, 0x80);
    work->actorBank = CLACT_CreateUnit(4, 1, 0x80);
    work->subActorBank = CLACT_CreateUnit(2, 1, 0x80);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    work->spriteRes[1] = CLACT_RegisterCharacter(work->arcHandle, 7, 1, 2, 0x80);
    work->spriteRes[0] = CLACT_RegisterPalette(work->arcHandle, 10, 2, 0, 0x80);
    work->spriteRes[2] = CLACT_RegisterCellAnim(work->arcHandle, 8, 9, 0x80);
    work->spriteRes[4] = CLACT_RegisterCharacter(spriteArc, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x80);
    work->spriteRes[3] = CLACT_RegisterPaletteEx(spriteArc, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x160, 0, 3, 0x80);
    cellAnimId = APP_ICON_GetStatusCellFileId(0);
    work->spriteRes[5] = CLACT_RegisterCellAnim(spriteArc, cellAnimId, APP_ICON_GetStatusPaletteFileId(0), 0x80);
    ARC_TOOL_DeleteHandle(spriteArc);
}




/*
 * Creates four sprites from a const 6-word template table (x, y, z, then
 * three resource-slot indices).  The table must be `const`: a non-const
 * table lets the stores into the stack record alias it, and the index loads
 * are then scheduled after the stack-argument stores (42 bytes of DIFF).
 * Twin: VIEWER_ACTOR_CreateObjects.
 */
void BSUBWAY_RECORD_LIST_CreateActors(BsubwayRecordListWork *work)
{
    int i;
    ActorSetup setup;

    for (i = 0; i < 4; i++) {
        setup.x = sActorTemplates[i].x;
        setup.y = sActorTemplates[i].y;
        setup.z = sActorTemplates[i].z;
        setup.bgPriority = 0;
        setup.animIndex = 0;
        work->actors[i] = CLACT_CreateActor(work->actorBank, work->spriteRes[sActorTemplates[i].charRes], work->spriteRes[sActorTemplates[i].palRes], work->spriteRes[sActorTemplates[i].cellRes], &setup, 0, 0x80);
        CLACT_SetActorAutoAnim(work->actors[i], 1);
    }
}



void BSUBWAY_RECORD_LIST_DeleteActors(BsubwayRecordListWork *work)
{
    CLACT_ReleaseCharacter(work->spriteRes[4]);
    CLACT_ReleasePalette(work->spriteRes[3]);
    CLACT_ReleaseCellAnim(work->spriteRes[5]);
    CLACT_ReleaseCharacter(work->spriteRes[1]);
    CLACT_ReleasePalette(work->spriteRes[0]);
    CLACT_ReleaseCellAnim(work->spriteRes[2]);
    CLACT_DeleteUnit(work->subActorBank);
    CLACT_DeleteUnit(work->actorBank);
    CLACT_ExitSystem();
}



void BSUBWAY_RECORD_LIST_CreateWindows(BsubwayRecordListWork *work)
{
    int i;
    int j;
    struct BmpWin *win;
    const BmpWinTemplate *tmpl;

    BMP_WIN_Init(0x80);
    for (i = 0; i < 8; i++) {
        tmpl = sWindowTemplates[i];
        work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i] = BMP_WIN_Create((u8)tmpl->layer, tmpl->x, tmpl->y, tmpl->width, tmpl->height, tmpl->charBase, 1);
        BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i]), 0);
        win = work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i];
        BMP_WIN_TransferChars(win);
        BMP_WIN_MakeScreen(win);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    }
    for (j = 0; j < 10; j++) {
        work->windows[j] = BMP_WIN_Create(1, 2, 1, 10, 2, 1, 1);
        BMP_Clear(BMP_WIN_GetBmp(work->windows[j]), 4);
    }
}


/*
 * extent: final two bytes are alignment padding before next labelled function.
 */
void BSUBWAY_RECORD_LIST_DeleteWindows(BsubwayRecordListWork *work)
{
    int i;

    for (i = 0; i < 10; i++)
        BMP_WIN_Delete(work->windows[i]);
    for (i = 0; i < 8; i++)
        BMP_WIN_Delete(work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i]);
    BMP_WIN_Exit();
}



void BSUBWAY_RECORD_LIST_InitText(BsubwayRecordListWork *work)
{
    int i;
    struct PrintSys *printSys;

    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x80);
    work->printSys = PRINTSYS_QUE_Create(0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_WIN_COUNT; i++) {
        work->printJobs[i].window = work->windows[i];
        work->printJobs[i].isPending = 0;
    }
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_TITLE].window), 0, 0,
                  work->messages[0], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_TITLE].isPending = 1;
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_B].window), 0, 0,
                  work->messages[3], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_B].isPending = 1;
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_C].window), 0, 0,
                  work->messages[6], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_C].isPending = 1;
}


void BSUBWAY_RECORD_LIST_ExitText(BsubwayRecordListWork *work) { PRINTSYS_QUE_Delete(work->printSys); GF_FONT_Delete(work->font); }



void BSUBWAY_RECORD_LIST_UpdateText(BsubwayRecordListWork *work)
{
    int i;
    struct PrintSys *printSys;

    PRINTSYS_QUE_Main(work->printSys);
    for (i = 0; i < BSUBWAY_RECORD_LIST_WIN_COUNT; i++) {
        printSys = work->printSys;
        if (work->printJobs[i].isPending != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->printJobs[i].window)) == 0) {
                BMP_WIN_TransferChars(work->printJobs[i].window);
                work->printJobs[i].isPending = 0;
            }
        }
    }
}


int BSUBWAY_RECORD_LIST_RunInputState(BsubwayRecordListWork *work) { return sInputStateFuncs[work->state](work); }


int BSUBWAY_RECORD_LIST_StateFadeIn(BsubwayRecordListWork *work) { if (WIPE_SYS_EndCheck()) work->state = BSUBWAY_RECORD_LIST_STATE_INPUT; return 1; }



int BSUBWAY_RECORD_LIST_StateInput(BsubwayRecordListWork *work)
{
    int result;

    if (PRINTSYS_QUE_IsFinished(work->printSys) == 0)
        return 1;
    if (BSUBWAY_RECORD_LIST_PollTouchAndCancel(work) == -1) {
        result = CURSOR_MOVE_PollInput(work->cursorMove);
        if (result == -6)
            BSUBWAY_RECORD_LIST_HandleAction(work, 0);
        else if (result == -5)
            BSUBWAY_RECORD_LIST_HandleAction(work, 1);
    }
    return 1;
}


int BSUBWAY_RECORD_LIST_StateBackAnim(BsubwayRecordListWork *work) { if (CLACT_IsActorAnimActive(work->actors[BSUBWAY_RECORD_LIST_ACTOR_BACK])==0) work->state = BSUBWAY_RECORD_LIST_STATE_FADE_OUT_START; return 1; }


int BSUBWAY_RECORD_LIST_StateFadeOutStart(BsubwayRecordListWork *work) { WIPE_SYS_Start(0,0,0,0,16,1,128); work->state = BSUBWAY_RECORD_LIST_STATE_FADE_OUT_WAIT; return 1; }


/*
 * extent: Two bytes of alignment padding follow.
 */
int BSUBWAY_RECORD_LIST_StateFadeOutWait(BsubwayRecordListWork *work)
{
    if (WIPE_SYS_EndCheck()) {
        work->state = BSUBWAY_RECORD_LIST_STATE_FADE_IN;
        return 0;
    }
    return 1;
}


void BSUBWAY_RECORD_LIST_InitCursor(BsubwayRecordListWork *work)
{
    work->cursorMove = CURSOR_MOVE_Create(sCursorEntries, sCursorCallbacks, work, 1, 0, 0x80);
    BSUBWAY_RECORD_LIST_PlaceCursorActor(work, 0);
}


/*
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 */
int BSUBWAY_RECORD_LIST_DeleteCursor(BsubwayRecordListWork *work)
{
    return CURSOR_MOVE_Delete(work->cursorMove);
}


/* Cursor callback table slots 0 and 1: no action. */
void BSUBWAY_RECORD_LIST_CursorCallbackNop0(void) {}


void BSUBWAY_RECORD_LIST_CursorCallbackNop1(void) {}


/* Cursor callback table slot 2: the cursor moved to row "row". */
void BSUBWAY_RECORD_LIST_CursorCallbackMoved(BsubwayRecordListWork *work, int row)
{
    BSUBWAY_RECORD_LIST_ShowRecordDetails(work, work->recordList->records, (int)((unsigned)row + (unsigned)work->page * 10u));
    BSUBWAY_RECORD_LIST_PlaceCursorActor(work, row);
    GFL_USE_PlaySeDefaultVolume(SE_CURSOR_MOVE);
}


/* Cursor callback table slot 3: same body as slot 2 (two functions, both are table targets). */
void BSUBWAY_RECORD_LIST_CursorCallbackMovedAlt(BsubwayRecordListWork *work, int row)
{
    BSUBWAY_RECORD_LIST_ShowRecordDetails(work, work->recordList->records, (int)((unsigned)row + (unsigned)work->page * 10u));
    BSUBWAY_RECORD_LIST_PlaceCursorActor(work, row);
    GFL_USE_PlaySeDefaultVolume(SE_CURSOR_MOVE);
}


void BSUBWAY_RECORD_LIST_PlaceCursorActor(BsubwayRecordListWork *work, int row)
{
    CursorPos pos;
    const u8 *entry;

    entry = CURSOR_MOVE_GetEntry(work->cursorMove, row);
    pos.x = entry[0];
    pos.y = entry[1];
    CLACT_AddActorSurfacePos(work->actors[BSUBWAY_RECORD_LIST_ACTOR_CURSOR], (const struct Vec2 *)(&pos), 0);
}


void BSUBWAY_RECORD_LIST_ShowRecordDetails(BsubwayRecordListWork *work, BsubwayWifiRecord *records, int index)
{
    u32 trainerClass;
    u32 trainerIndex;
    BsubwayWifiRecord *record;
    BsubwayPmsData *greeting;
    int offset;
    struct Strbuf *nameStr;
    struct BmpWin *win;
    int nameLen;
    struct PrintSys *printSys;
    struct Strbuf *greetingStr;

    offset = index * 0x22;
    record = &records[index];
    trainerClass = record->trainerClass;
    trainerIndex = record->trainerIndex;
    greeting = &record->greeting;
    nameStr = STRBUF_Create(0x10, 0x80);
    WORDSET_SetSlotNumber(work->wordSet, 0, work->args->wordNumber0, 2, 0, 1);
    WORDSET_SetSlotNumber(work->wordSet, 1, work->args->wordNumber1, 3, 0, 1);
    WORDSET_SetSlotFromMsgE7(work->wordSet, 2, trainerClass);
    WORDSET_DeleteMsgdataF094(work->wordSet, 3, trainerClass, trainerIndex);
    BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_WIN_SUMMARY]), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE]), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_WIN_NAME]), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_WIN_SCORE]), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->windows[BSUBWAY_RECORD_LIST_WIN_GREETING]), 0);
    if (index < work->entryCount) {
        nameLen = 8;
        /* stand-in: record->trainerName changes the bytes; the byte offset (index * 0x22) must be computed first. */
        STRBUF_SetStringN(nameStr, (const u16 *)((char *)records + offset), nameLen);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_NAME].window), 0, 0, nameStr, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_NAME].isPending = 1;
        WORDSET_CopyTaggedText(work->wordSet, work->textBuf, work->messages[1]);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SUMMARY].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SUMMARY].isPending = 1;
        WORDSET_CopyTaggedText(work->wordSet, work->textBuf, work->messages[2]);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE].isPending = 1;
        WORDSET_CopyTaggedText(work->wordSet, work->textBuf, work->messages[4]);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].isPending = 1;
        WORDSET_CopyTaggedText(work->wordSet, work->textBuf, work->messages[5]);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].window), 0, 0x10, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].isPending = 1;
        greetingStr = PMSI_PARAM_ToString(greeting, 0x80);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, BMP_WIN_GetBmp(work->printJobs[BSUBWAY_RECORD_LIST_WIN_GREETING].window), 0, 0, greetingStr, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_GREETING].isPending = 1;
        STRBUF_Delete(greetingStr);
    } else {
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_NAME];
        BMP_WIN_TransferChars(win); BMP_WIN_MakeScreen(win); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_SCORE];
        BMP_WIN_TransferChars(win); BMP_WIN_MakeScreen(win); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_GREETING];
        BMP_WIN_TransferChars(win); BMP_WIN_MakeScreen(win); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(win));
    }
    STRBUF_Delete(nameStr);
}


int BSUBWAY_RECORD_LIST_PollTouchAndCancel(BsubwayRecordListWork *work)
{
    int touched;

    touched = TOUCHPANEL_HitTrg(sTouchRects);
    if (KEY_GetTrg() & KEY_B_BUTTON) {
        GFL_USE_PlaySeDefaultVolume(SE_CANCEL);
        touched = 2;
    }
    BSUBWAY_RECORD_LIST_HandleAction(work, touched);
    return touched;
}



void BSUBWAY_RECORD_LIST_HandleAction(BsubwayRecordListWork *work, int action)
{
    switch (action) {
    case 0:
        if (BSUBWAY_RECORD_LIST_ChangePage(work, action) != 0) {
            GFL_USE_PlaySeDefaultVolume(SE_CURSOR_MOVE);
            CLACT_SetActorAnimSeq(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], ARROW_ANIM_PREV);
            BSUBWAY_RECORD_LIST_ShowPage(work, work->page);
        }
        break;
    case 1:
        if (BSUBWAY_RECORD_LIST_ChangePage(work, action) != 0) {
            GFL_USE_PlaySeDefaultVolume(SE_CURSOR_MOVE);
            CLACT_SetActorAnimSeq(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], ARROW_ANIM_NEXT);
            BSUBWAY_RECORD_LIST_ShowPage(work, work->page);
        }
        break;
    case 2:
        work->state = BSUBWAY_RECORD_LIST_STATE_BACK_ANIM;
        CLACT_SetActorAnimSeq(work->actors[BSUBWAY_RECORD_LIST_ACTOR_BACK], BACK_ANIM_PRESS);
        break;
    }
}


void BSUBWAY_RECORD_LIST_InitPageCount(BsubwayRecordListWork *work)
{
    work->page = 0;
    work->pageCount = work->entryCount / BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE;
    if (work->entryCount % BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE != 0)
        (work->pageCount)++;
}



void BSUBWAY_RECORD_LIST_UpdateArrowVisibility(BsubwayRecordListWork *work, int page, int pageCount)
{
    if (pageCount == 1) {
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 0);
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 0);
    } else if (page == 0) {
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 0);
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 1);
    } else if (page != 0 && page < pageCount - 1) {
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 1);
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 1);
    } else if (page == pageCount - 1) {
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 1);
        CLACT_SetActorDrawEnable(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 0);
    }
}


/* direction 0: previous page, 1: next page. Returns 1 when the page changed. */
int BSUBWAY_RECORD_LIST_ChangePage(BsubwayRecordListWork *work, int direction)
{
    int changed = 0;
    if (direction == 0) {
        if (work->page != 0) {
            work->page = work->page - 1;
            changed = 1;
        }
    } else if (direction == 1) {
        if (work->page < work->pageCount - 1) {
            work->page = work->page + 1;
            changed = 1;
        }
    }
    return changed;
}


/*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 */
void BSUBWAY_RECORD_LIST_ShowPage(BsubwayRecordListWork *work, int page)
{
    work->page = page;
    BSUBWAY_RECORD_LIST_UpdateArrowVisibility(work, page, work->pageCount);
    BSUBWAY_RECORD_LIST_DrawPageRows(work);
    BSUBWAY_RECORD_LIST_ShowRecordDetails(work, work->recordList->records, work->page * 10 + CURSOR_MOVE_GetCurrent(work->cursorMove));
}


/*
 * Unlabelled leaf: remaining count after a - 10 per page, capped at 10.
 */
int BSUBWAY_RECORD_LIST_GetRowCountOnPage(int page, int pageCountUnused, int entryCount)
{
    int rows = entryCount - page * 10;

    if (rows > 10)
        rows = 10;
    return rows;
}



void BSUBWAY_RECORD_LIST_DrawPageRows(BsubwayRecordListWork *work)
{
    struct Strbuf *nameStr;
    int rowCount;
    int i;

    nameStr = STRBUF_Create(0x10, 0x80);
    rowCount = BSUBWAY_RECORD_LIST_GetRowCountOnPage(work->page, work->pageCount, work->entryCount);
    i = 0;
    if (rowCount > 0) {
        do {
            STRBUF_SetStringN(nameStr, work->recordList->records[i + work->page * 10].trainerName, 8);
            BSUBWAY_RECORD_LIST_DrawRowName(work, i, nameStr, work->recordList->records[i + work->page * 10].isFemale);
            i++;
        } while (i < rowCount);
    }
    for (; i < 10; i++)
        BGWINFRM_HideFrame(work->frameMgr, i);
    STRBUF_Delete(nameStr);
}


/* Draws the trainer name of one list row into its row window and shows the row frame. */
void BSUBWAY_RECORD_LIST_DrawRowName(BsubwayRecordListWork *work, int row, struct Strbuf *name, int isFemale)
{
    BMP_Clear(BMP_WIN_GetBmp(work->windows[row]), 4);
    if (isFemale == 0)
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->windows[row]), 0, 0, name,
                      work->font, 0x3584);
    else
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->windows[row]), 0, 0, name,
                      work->font, 0x2D44);
    BMP_WIN_TransferChars(work->windows[row]);
    BGWINFRM_PutBmpWin(work->frameMgr, row, work->windows[row]);
    BGWINFRM_ShowFrame(work->frameMgr, row);
}
