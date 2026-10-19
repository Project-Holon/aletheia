/*
 * file:     irc_ranking.c
 * unit:     yes
 * function: IRC_RANKING_ProcInit, IRC_RANKING_ProcExit, IRC_RANKING_ProcMain, IRC_RANKING_SeqInit, IRC_RANKING_SeqClear, IRC_RANKING_SeqRun, IRC_RANKING_SeqIsDone, IRC_RANKING_SeqSetFunc, IRC_RANKING_SeqFinish, IRC_RANKING_SeqFadeIn, IRC_RANKING_SeqFadeOut, IRC_RANKING_SeqBrowse, IRC_RANKING_SeqScrollToLatest, IRC_RANKING_GfxInit, IRC_RANKING_GfxExit, IRC_RANKING_DisplayBgVBlank, IRC_RANKING_GfxGetCharRegion, IRC_RANKING_ClactInit, IRC_RANKING_ClactExit, IRC_RANKING_ClactDraw, IRC_RANKING_ClactVBlank, IRC_RANKING_ClactGetUnit, IRC_RANKING_DisplayInit, IRC_RANKING_DisplayExit, IRC_RANKING_Draw, IRC_RANKING_GetDisplay, IRC_RANKING_GetClactUnit, IRC_RANKING_DisplayVBlankTask, IRC_RANKING_ListInit, IRC_RANKING_ListExit, IRC_RANKING_ListUpdate, IRC_RANKING_ListScrollBy, IRC_RANKING_ListGetScrollPos, IRC_RANKING_ListFindLatestScrollPos, IRC_RANKING_ListGetScrollMax, IRC_RANKING_ListDrawRows, IRC_RANKING_ListTransferWindows, IRC_RANKING_ListScrollTask, IRC_RANKING_RowInit, IRC_RANKING_RowExit, IRC_RANKING_RowDraw, IRC_RANKING_RowSetScroll, IRC_RANKING_LoadRowScreens, IRC_RANKING_ClearRowScreens, IRC_RANKING_WriteRowScreen, IRC_RANKING_DataCreate, IRC_RANKING_DataDelete, IRC_RANKING_DataGetCount, IRC_RANKING_InputInit, IRC_RANKING_InputExit, IRC_RANKING_InputUpdate, IRC_RANKING_InputGetDrag, IRC_RANKING_InputGetFlick, IRC_RANKING_InputGetKeys, IRC_RANKING_InertiaInit, IRC_RANKING_InertiaExit, IRC_RANKING_InertiaUpdate, IRC_RANKING_InertiaStart, IRC_RANKING_InertiaStop, IRC_RANKING_InertiaStep, IRC_RANKING_InertiaIsActive, IRC_RANKING_PrintCentered, IRC_RANKING_CopyBmpTiles, IRC_RANKING_LabelCreate, IRC_RANKING_LabelDelete, IRC_RANKING_LabelSetText, IRC_RANKING_LabelSetColor, IRC_RANKING_LabelSetAlign, IRC_RANKING_LabelUpdate, IRC_RANKING_LabelCalcTextPos
 * address:  0x021B7560
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_Create 0x020124F4 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   gIrcRankingLabelDefs 0x021B94D4 data a4
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   VEC_DotProduct 0x0207CA68 arm
 *   gIrcRankingFlickAxis 0x021B949C data a4
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Div 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   gIrcRankingDispConfig 0x021B94A8 data
 *   gIrcRankingBgEntries 0x021B9524 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   gIrcRankingClactSysInit 0x021B94B8 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   gIrcRankingVramConfig 0x021B94F4 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BMP_Create 0x02043678 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_Delete 0x020437AC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   IRC_RANKING_GetLastSlot 0x0200A930 thumb
 *   IRC_RANKING_GetEntryMeetCount 0x0200A8E4 thumb
 *   IRC_RANKING_GetEntryProfile 0x0200A908 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   STRBUF_SetString 0x02045924 arm
 *   gIrcRankingFileName 0x021B9680 data a1
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   GF_FONT_CountLines 0x0201D42C thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   IRC_RANKING_GetFromSave  0x0200A8A0  thumb  arm9
 *   IRC_RANKING_GetEntryCount  0x0200A8AC  thumb  arm9
 *   IRC_RANKING_GetEntry  0x0200A8C8  thumb  arm9
 *   IRC_RANKING_GetEntryScore  0x0200A8D0  thumb  arm9
 *   IRC_RANKING_GetEntryGender  0x0200A8F8  thumb  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */
#include "../ov101/irc_appbar.h"
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/*
 * Infrared compatibility ranking screen.  The proc shows the 30-entry ranking
 * saved by the infrared link (rank, name, score, meet count, Pokemon icon),
 * scrolls it with the touch screen or the D-pad, and lets the player leave
 * through the app bar.
 */

#define REG_DISPCNT (*(volatile unsigned *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile unsigned *)0x04001000)
#define REG_BLDCNT (*(volatile unsigned short *)0x04000050)
#define REG_BLDCNT_SUB (*(volatile unsigned short *)0x04001050)

#define IRC_RANKING_HEAP_ID 67
#define ROW_HEIGHT 24
#define ROW_COUNT_MAX 30
#define BG_COUNT 8
#define ROW_SCREEN_BYTES 384 /* two sets of 3 rows of 32 screen entries */

#define MSG_ID_RANK_FORMAT 5
#define MSG_ID_SCORE_FORMAT 7
#define MSG_ID_MEET_COUNT_FORMAT 8

struct IrcRankingWork;
struct ProcSys;
struct GameData;
struct GfFont;
struct MsgBank;
struct PrintQue;
struct BmpWin;
struct Bmp;
struct Strbuf;
struct WordSet;
struct ClactUnit;
struct ClactActor;
struct BmpOamSys;
struct BmpOam;
struct SaveControl;
struct IrcRankSave;
struct IrcRankEntry;

/* Data tables in the overlay image, size known, layout opaque here. */
struct ClactSysInit { u8 bytes[0x1c]; };
struct DispConfig { u8 bytes[0x10]; };
struct DispVramConfig { u8 bytes[0x30]; };

typedef struct { int x, y; } Pair;
typedef struct { long x, y, z; } Vec3;

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8  screenSize;
    u8  colorMode;
    u8  screenBase;
    u8  charBase;
    u32 extPaletteSlot;
    u8  priority;
    u8  areaOver;
    u8  dummy;
    u8  mosaicFlag;
    u32 mosaic;
};

typedef struct { u32 bg; struct BgTemplate bgTemplate; u32 type; } BgEntry;

/* Position and OAM priorities of one header label. */
typedef struct {
    s16 x;
    s16 y;
    u16 unused;
    u8  drawPriority;
    u8  bgPriority;
} IrcRankingLabelPos;

/* One row of the label table: position and size in tiles. */
typedef struct {
    s16 x;
    s16 y;
    u16 widthTiles;
    u16 heightTiles;
} IrcRankingLabelDef;

/* Init data of a cell actor (CLACT_CreateActor). */
typedef struct {
    s16 x;
    s16 y;
    u16 animIndex;
    u8  drawPriority;
    u8  bgPriority;
} ActorInitParam;

typedef struct {
    s16 x;
    s16 y;
} OamPos;

/* Init data of a bitmap OAM (BMP_OAM_Create). */
typedef struct {
    struct Bmp *bmp;
    s16 x;
    s16 y;
    u32 animResId;
    u32 palette;
    u8  drawPriority;
    u8  bgPriority;
    u16 space;
    u32 engine;
} BmpOamParam;

/* One entry of the ranking as shown on screen (16 bytes). */
typedef struct {
    struct Strbuf *name;
    u32 score : 7;
    u32 meetCount : 10;
    u32 rowStyle : 8;
    u32 rank : 7;
    u16 species;
    u8  form;
    u8  gender;
    u8  isEgg;
    u8  isLatest;
    u8  padding[2];
} IrcRankingItem;

typedef struct {
    u32 count;
    IrcRankingItem items[];
} IrcRankingData;

/* Sequence runner: calls func every frame until done is set. */
typedef struct IrcSeq {
    void (*func)(struct IrcSeq *seq, int *step, struct IrcRankingWork *work);
    int done;
    int step;
    struct IrcRankingWork *work;
} IrcSeq;

/* Background and window setup (0x10 bytes). */
typedef struct {
    void *arcHandle;
    u32 charRegionMain;
    u32 charRegionSub;
    struct BmpWin *titleWin;
} IrcRankingGfx;

/* Cell actor system (0x14 bytes). */
typedef struct {
    struct ClactUnit *unit;
    u32 reserved[4];
} IrcRankingClact;

/* Screen setup (0x28 bytes). */
typedef struct {
    IrcRankingGfx gfx;
    IrcRankingClact clact;
    void *vblankTask;
} IrcRankingDisplay;

/* One scrolling list row (32 bytes). */
typedef struct {
    const IrcRankingItem *item;
    struct Bmp *textBmp;
    struct ClactActor *iconActors[2];
    s16 iconY[2];
    u32 iconCharRes;
    u32 iconCellRes;
    u16 *screenData;
} IrcRankingRow;

/* The scrolling list (0x59C bytes). */
typedef struct {
    u32 iconPaletteMain;
    u32 iconPaletteSub;
    u16 rowScreenMain[96];
    u16 rowScreenSub[96];
    IrcRankingRow rows[ROW_COUNT_MAX];
    u8  rowBgMain;
    u8  textBgMain;
    u8  rowBgSub;
    u8  textBgSub;
    IrcRankingDisplay *display;
    IrcRankingData *data;
    u16 rowCount;
    s16 scrollPos;
    s16 scrollMin;
    s16 scrollMax;
    s16 topRow;
    s16 lastDelta;
    s16 scrollDir;
    s16 dirChanged;
    s16 bgScrollMain;
    s16 bgScrollSub;
    struct BmpWin *textWin[2];
    struct GfFont *font;
    struct MsgBank *msgBank;
    u8  reserved[16];
    struct WordSet *wordSet;
    void *scrollTask;
    int needTransfer;
    int needSnap;
    int needScrollApply;
} IrcRankingList;

/* Touch and key tracking (0x2C bytes). */
typedef struct {
    Pair start;
    Pair current;
    Pair prev;
    Pair delta;
    int holdFrames;
    u32 idleFrames;
    int keyHoldFrames;
} IrcRankingInput;

/* Scroll momentum after a flick or a key hold (0x14 bytes). */
typedef struct {
    int baseSpeed;
    int damping;
    int velocity;
    int dirty;
    s8  direction;
    u8  padding[3];
} IrcRankingInertia;

/* One header label (0x24 bytes). */
typedef struct {
    struct Bmp *bmp;
    u16 printColor;
    u16 padding06;
    int pending;
    Pair offset;
    int alignMode;
    struct Strbuf *text;
    struct BmpOam *oam;
    struct PrintQue *printQue;
} IrcRankingLabel;

/* Proc work (0x648 bytes). */
typedef struct IrcRankingWork {
    IrcRankingDisplay display;
    IrcSeq seq;
    IrcRankingList list;
    IrcRankingInput input;
    IrcRankingInertia inertia;
    IrcAppBar *appBar;
    struct GfFont *font;
    struct PrintQue *printQue;
    struct MsgBank *msgBank;
    struct BmpOamSys *bmpOamSys;
    struct GameData *gameData;
    IrcRankingLabel *labels[4];
    IrcRankingData *rankData;
    s16 accelStep;
    u16 padding642;
    u32 labelPalette;
} IrcRankingWork;

extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct ProcSys *procSys, u32 size, u32 heapId);
extern struct GameData *GAMESYSTEM_GetGameData(void *param);
extern struct GameData *GAME_DATA_Create(u16);
extern struct PrintQue *PRINTSYS_QUE_Create(u32 heapId);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct BmpOamSys *BMP_OAM_CreateSys(unsigned int heapId, struct ClactUnit *unit);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleasePalette(u32 i);
extern void BMP_OAM_DeleteSys(struct BmpOamSys *sys);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void PRINTSYS_QUE_Delete(struct PrintQue *printQue);
extern void GAME_DATA_Delete(struct GameData *gameData);
extern void PROCSYS_FreeProcWork(struct ProcSys *procSys);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern u32 PRINTSYS_QUE_Main(struct PrintQue *printQue);
extern void MI_CpuFill8(void *, unsigned char, unsigned int);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern int VEC_DotProduct(const Vec3 *, const Vec3 *);
extern int FX_Div(int, int);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern unsigned int ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u32 flags);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32, u32, u32, u32, u32, u32);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *, u32);
extern struct IrcRankSave *IRC_RANKING_GetFromSave(struct SaveControl *save);
extern void *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void BG_SYS_PushTile(u32);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeTiles(u32 idx, u32 count, u32 tile);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct ClactSysInit *sysInit, const struct DispVramConfig *vramConfig, unsigned int heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *unit);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVramConfig *c);
extern void BMP_SetDisplaySwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void *GFL_USE_AddMainTask(void (*taskFunc)(void *task, void *taskWork), void *taskWork, int priority);
extern void TCB_DeleteTask(void *task);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Strbuf *STRBUF_Create(int capacity, u16 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *src);
extern u32 GF_FONT_MeasureWidestLine(struct Strbuf *s, struct GfFont *font, u32 b);
extern void PRINTSYS_Print(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *text, struct GfFont *font);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, u32 charRes, u32 palRes, u32 cellRes, const ActorInitParam *param, u16 space, u16 heapId);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 female, u32 isEgg);
extern void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 v);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void BMP_Delete(struct Bmp *bmp);
extern void CLACT_GetActorSurfacePos(struct ClactActor *actor, OamPos *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, OamPos *delta, u16 space);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 arcId, u32 fileId, u32 flag, void **outData, u16 heapId);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_DrawTile(u32 bgId, const void *src, u32 dx, u32 y, u8 width, u8 height);
extern void BG_SYS_FillTileMap(u32, u8, u8, u8, u8, u8);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern s32 IRC_RANKING_GetEntryCount(struct IrcRankSave *rank);
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern u8 IRC_RANKING_GetLastSlot(struct IrcRankSave *rank);
extern struct IrcRankEntry *IRC_RANKING_GetEntry(struct IrcRankSave *rank, u32 index);
extern void STRBUF_SetString(struct Strbuf *o, const struct IrcRankEntry *src);
extern u8 IRC_RANKING_GetEntryScore(struct IrcRankSave *rank, u32 index);
extern u16 IRC_RANKING_GetEntryMeetCount(struct IrcRankSave *rank, u32 index);
extern u32 IRC_RANKING_GetEntryGender(struct IrcRankSave *rank, u32 index);
extern void IRC_RANKING_GetEntryProfile(struct IrcRankSave *rank, u32, u16 *, u8 *, u8 *, u8 *);
extern u32 TOUCHPANEL_GetPointTrg(int *outX, int *outY);
extern u32 TOUCHPANEL_GetPointCont(int *outX, int *outY);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void VEC_Subtract(const Vec3 *, const Vec3 *, Vec3 *);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern float _ffltu(u32);
extern u8 BMP_WIN_GetWidth(struct BmpWin *win);
extern u8 BMP_WIN_GetHeight(struct BmpWin *win);
extern u32 GF_FONT_CountLines(struct Strbuf *, struct GfFont *);
extern void WORDSET_SetSlotMyStatus(struct WordSet *, u32, void *);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern struct BmpOam *BMP_OAM_Create(struct BmpOamSys *sys, const BmpOamParam *param);
extern void BMP_OAM_Delete(struct BmpOam *oam);
extern void PRINTSYS_PrintQueColor(struct PrintQue *printQue, struct Bmp *bmp, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQue *printQue, struct Bmp *bmp);
extern void BMP_OAM_UploadChars(struct BmpOam *oam);

int IRC_RANKING_ProcInit(struct ProcSys *procSys, u32 unused, void **args);
int IRC_RANKING_ProcExit(struct ProcSys *procSys, int unused, int *exitMode, IrcRankingWork *work);
int IRC_RANKING_ProcMain(int a, int b, int c, IrcRankingWork *work);
void IRC_RANKING_SeqInit(IrcSeq *seq, IrcRankingWork *work, void (*func)(IrcSeq *, int *, IrcRankingWork *));
void IRC_RANKING_SeqClear(IrcSeq *seq);
void IRC_RANKING_SeqRun(IrcSeq *seq);
u32 IRC_RANKING_SeqIsDone(IrcSeq *seq);
void IRC_RANKING_SeqSetFunc(IrcSeq *seq, void (*func)(IrcSeq *, int *, IrcRankingWork *));
void IRC_RANKING_SeqFinish(IrcSeq *seq);
void IRC_RANKING_SeqFadeIn(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqFadeOut(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqBrowse(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_SeqScrollToLatest(IrcSeq *seq, int *step, IrcRankingWork *work);
void IRC_RANKING_GfxInit(IrcRankingGfx *gfx, struct GameData *gameData, u32 heapId);
void IRC_RANKING_GfxExit(IrcRankingGfx *gfx);
void IRC_RANKING_DisplayBgVBlank(IrcRankingDisplay *display);
u32 IRC_RANKING_GfxGetCharRegion(IrcRankingGfx *gfx, u32 isMain);
void IRC_RANKING_ClactInit(IrcRankingClact *clact, const struct DispVramConfig *vramConfig, int heapId);
void IRC_RANKING_ClactExit(IrcRankingClact *clact);
void IRC_RANKING_ClactDraw(IrcRankingClact *clact);
void IRC_RANKING_ClactVBlank(IrcRankingClact *clact);
struct ClactUnit *IRC_RANKING_ClactGetUnit(IrcRankingClact *clact);
void IRC_RANKING_DisplayInit(IrcRankingDisplay *display, struct GameData *gameData, u32 heapId);
void IRC_RANKING_DisplayExit(IrcRankingDisplay *display);
void IRC_RANKING_Draw(IrcRankingWork *work);
IrcRankingDisplay *IRC_RANKING_GetDisplay(IrcRankingWork *work);
struct ClactUnit *IRC_RANKING_GetClactUnit(IrcRankingWork *work);
void IRC_RANKING_DisplayVBlankTask(void *task, void *taskWork);
void IRC_RANKING_ListInit(IrcRankingList *list, u32 rowBgMain, u8 textBgMain, u8 rowBgSub, u8 textBgSub, IrcRankingDisplay *display, struct ClactUnit *unit, struct MsgBank *msgBank, IrcRankingData *data, u16 heapId);
void IRC_RANKING_ListExit(IrcRankingList *list);
void IRC_RANKING_ListUpdate(IrcRankingList *list);
void IRC_RANKING_ListScrollBy(IrcRankingList *list, s16 delta);
s16 IRC_RANKING_ListGetScrollPos(IrcRankingList *list);
int IRC_RANKING_ListFindLatestScrollPos(IrcRankingList *list);
s16 IRC_RANKING_ListGetScrollMax(IrcRankingList *list);
void IRC_RANKING_ListDrawRows(IrcRankingList *list);
void IRC_RANKING_ListTransferWindows(IrcRankingList *list);
void IRC_RANKING_ListScrollTask(void *task, void *taskWork);
void IRC_RANKING_RowInit(IrcRankingRow *row, const IrcRankingItem *item, struct ClactUnit *unit, u32 palResMain, u32 palResSub, struct MsgBank *msgBank, struct GfFont *font, struct WordSet *wordSet, u16 *screenData, s16 mainY, s16 subY, u16 heapId);
void IRC_RANKING_RowExit(IrcRankingRow *row);
void IRC_RANKING_RowDraw(IrcRankingRow *row, struct BmpWin *win, u32 bgId, u16 y);
void IRC_RANKING_RowSetScroll(IrcRankingRow *row, int scroll);
void IRC_RANKING_LoadRowScreens(u16 *screens, IrcRankingGfx *gfx, u16 heapId);
void IRC_RANKING_ClearRowScreens(u16 *screens);
void IRC_RANKING_WriteRowScreen(u16 *screens, u32 bgId, int y, u8 style);
IrcRankingData *IRC_RANKING_DataCreate(struct GameData *gameData, u16 heapId);
void IRC_RANKING_DataDelete(IrcRankingData *data);
u32 IRC_RANKING_DataGetCount(IrcRankingData *data);
void IRC_RANKING_InputInit(IrcRankingInput *input, u32 heapId);
void IRC_RANKING_InputExit(IrcRankingInput *input);
void IRC_RANKING_InputUpdate(IrcRankingInput *input);
int IRC_RANKING_InputGetDrag(IrcRankingInput *input, Pair *start, Pair *current, Pair *delta);
int IRC_RANKING_InputGetFlick(IrcRankingInput *input, Pair *start, Pair *end, Vec3 *delta, int *holdFrames);
unsigned int IRC_RANKING_InputGetKeys(IrcRankingInput *input, u32 *keyHoldFrames);
void IRC_RANKING_InertiaInit(IrcRankingInertia *inertia);
void IRC_RANKING_InertiaExit(IrcRankingInertia *inertia);
void IRC_RANKING_InertiaUpdate(IrcRankingInertia *inertia);
void IRC_RANKING_InertiaStart(IrcRankingInertia *inertia, int speed, int duration);
void IRC_RANKING_InertiaStop(IrcRankingInertia *inertia);
short IRC_RANKING_InertiaStep(IrcRankingInertia *inertia);
int IRC_RANKING_InertiaIsActive(IrcRankingInertia *inertia);
void IRC_RANKING_PrintCentered(struct BmpWin *win, struct Strbuf *text, void *myStatus, struct GfFont *font);
void IRC_RANKING_CopyBmpTiles(struct Bmp *dst, struct Bmp *src, int dstX, int dstY, u16 srcX, u16 srcY, u16 width, u16 height);
IrcRankingLabel *IRC_RANKING_LabelCreate(const IrcRankingLabelPos *pos, u8 widthTiles, u8 heightTiles, int palette, u8 space, int engine, struct BmpOamSys *oamSys, struct PrintQue *printQue, u16 heapId);
void IRC_RANKING_LabelDelete(IrcRankingLabel *label);
void IRC_RANKING_LabelSetText(IrcRankingLabel *label, struct MsgBank *msgBank, u32 msgId, struct GfFont *font);
void IRC_RANKING_LabelSetColor(IrcRankingLabel *label, u16 printColor);
void IRC_RANKING_LabelSetAlign(IrcRankingLabel *label, u32 offsetX, u32 offsetY, u32 alignMode);
int IRC_RANKING_LabelUpdate(IrcRankingLabel *label);
void IRC_RANKING_LabelCalcTextPos(IrcRankingLabel *label, struct GfFont *font, Pair *out);

extern const IrcRankingLabelDef gIrcRankingLabelDefs[];
extern const Vec3 gIrcRankingFlickAxis;
extern struct DispConfig gIrcRankingDispConfig;
extern BgEntry gIrcRankingBgEntries[];
extern const struct ClactSysInit gIrcRankingClactSysInit;
extern const struct DispVramConfig gIrcRankingVramConfig;
extern const char gIrcRankingFileName[];

/* Proc init: allocates the work, builds the ranking data, display, list, input, app bar and the four header labels. */
int IRC_RANKING_ProcInit(struct ProcSys *procSys, u32 unused, void **args) {
    IrcRankingWork *work;
    IrcRankingDisplay *display;
    void *arc;
    IrcRankingLabelPos pos;
    int i;
    GFL_HEAP_CreateChildHeap(1, IRC_RANKING_HEAP_ID, 6 << 16);
    work = PROCSYS_AllocProcWork(procSys, sizeof(IrcRankingWork), IRC_RANKING_HEAP_ID);
    MI_CpuFill8(work, 0, sizeof(IrcRankingWork));
    if (*args) work->gameData = GAMESYSTEM_GetGameData(*args);
    else work->gameData = GAME_DATA_Create(1);
    work->printQue = PRINTSYS_QUE_Create(IRC_RANKING_HEAP_ID);
    work->font = GF_FONT_Create(23, 0, 0, 0, IRC_RANKING_HEAP_ID);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 50, IRC_RANKING_HEAP_ID);
    work->rankData = IRC_RANKING_DataCreate(work->gameData, IRC_RANKING_HEAP_ID);
    IRC_RANKING_DisplayInit(&work->display, work->gameData, IRC_RANKING_HEAP_ID);
    work->bmpOamSys = BMP_OAM_CreateSys(IRC_RANKING_HEAP_ID, IRC_RANKING_GetClactUnit(work));
    IRC_RANKING_SeqInit(&work->seq, work, IRC_RANKING_SeqFadeIn);
    IRC_RANKING_InputInit(&work->input, IRC_RANKING_HEAP_ID);
    IRC_RANKING_InertiaInit(&work->inertia);
    display = IRC_RANKING_GetDisplay(work);
    IRC_RANKING_ListInit(&work->list, 1, 2, 5, 6, display, IRC_RANKING_GetClactUnit(work), work->msgBank, work->rankData, IRC_RANKING_HEAP_ID);
    work->appBar = IRC_APPBAR_Create(2, IRC_RANKING_GetClactUnit(work), 4, 13, 0, 2, work->font, work->printQue, IRC_RANKING_HEAP_ID);
    arc = ARC_TOOL_CreateHandle(23, IRC_RANKING_HEAP_ID);
    work->labelPalette = CLACT_RegisterPaletteCompressed(arc, 5, 0, 448, IRC_RANKING_HEAP_ID);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&pos, 0, sizeof(IrcRankingLabelPos));
    pos.x = 8; pos.y = 41; pos.drawPriority = 0; pos.bgPriority = 0;
    for (i = 0; i < 4; i++) {
        pos.x = gIrcRankingLabelDefs[i].x; pos.y = gIrcRankingLabelDefs[i].y;
        work->labels[i] = IRC_RANKING_LabelCreate(&pos, gIrcRankingLabelDefs[i].widthTiles, gIrcRankingLabelDefs[i].heightTiles, work->labelPalette, 3, 0, work->bmpOamSys, work->printQue, IRC_RANKING_HEAP_ID);
        IRC_RANKING_LabelSetColor(work->labels[i], 1088);
        IRC_RANKING_LabelSetAlign(work->labels[i], 0, 0, 1);
        IRC_RANKING_LabelSetText(work->labels[i], work->msgBank, i + 1, work->font);
    }
    return 1;
}

/* Proc exit: tears everything down in reverse order and frees the work; the game data is deleted only when exitMode is 0. */
int IRC_RANKING_ProcExit(struct ProcSys *procSys, int unused, int *exitMode, IrcRankingWork *work)
{
    int i;
    for (i = 0; i < 4; i++) IRC_RANKING_LabelDelete(work->labels[i]);
    CLACT_ReleasePalette(work->labelPalette);
    IRC_APPBAR_Delete(work->appBar);
    IRC_RANKING_ListExit(&work->list);
    IRC_RANKING_InertiaExit(&work->inertia); IRC_RANKING_InputExit(&work->input); IRC_RANKING_SeqClear(&work->seq);
    BMP_OAM_DeleteSys(work->bmpOamSys); IRC_RANKING_DisplayExit(&work->display); IRC_RANKING_DataDelete(work->rankData);
    MSGDATA_Delete(work->msgBank); GF_FONT_Delete(work->font); PRINTSYS_QUE_Delete(work->printQue);
    if (*exitMode == 0) GAME_DATA_Delete(work->gameData);
    PROCSYS_FreeProcWork(procSys); GFL_HEAP_DeleteChecked(IRC_RANKING_HEAP_ID); return 1;
}

/* Proc main: runs the current sequence step, draws, and flushes the print queue and the labels; returns 1 once the sequence is done. */
int IRC_RANKING_ProcMain(int a, int b, int c, IrcRankingWork *work)
{
    int i;
    IRC_RANKING_SeqRun(&work->seq);
    IRC_RANKING_Draw(work);
    PRINTSYS_QUE_Main(work->printQue);
    for (i = 0; i < 4; i++) IRC_RANKING_LabelUpdate(work->labels[i]);
    if (IRC_RANKING_SeqIsDone(&work->seq)) return 1;
    return 0;
}

/* Clears the sequence and starts it at func. */
void IRC_RANKING_SeqInit(IrcSeq *seq, IrcRankingWork *work, void (*func)(IrcSeq *, int *, IrcRankingWork *))
{
    MI_CpuFill8(seq, 0, sizeof(IrcSeq));
    seq->work = work;
    IRC_RANKING_SeqSetFunc(seq, func);
}

void IRC_RANKING_SeqClear(IrcSeq *seq)
{
    MI_CpuFill8(seq, 0, sizeof(IrcSeq));
}

/* Calls the current step function once unless the sequence is done. */
void IRC_RANKING_SeqRun(IrcSeq *seq)
{
    if (seq->done == 0) seq->func(seq, &seq->step, seq->work);
}

u32 IRC_RANKING_SeqIsDone(IrcSeq *seq)
{
    return seq->done;
}

void IRC_RANKING_SeqSetFunc(IrcSeq *seq, void (*func)(IrcSeq *, int *, IrcRankingWork *))
{
    seq->func = func;
    seq->step = 0;
}

void IRC_RANKING_SeqFinish(IrcSeq *seq)
{
    seq->done = 1;
}

/* Sequence step: fade in, then go to the scroll-to-latest step when the list has a latest entry, else to browsing. */
void IRC_RANKING_SeqFadeIn(IrcSeq *seq, int *step, IrcRankingWork *work)
{
    switch (*step) {
    case 0: FADE_Start(3, 16, 0, 0); *step = 1; break;
    case 1: if (!FADE_IsActive()) *step = 2; break;
    case 2:
        if (IRC_RANKING_ListFindLatestScrollPos(&work->list) != 65535) IRC_RANKING_SeqSetFunc(&work->seq, IRC_RANKING_SeqScrollToLatest);
        else IRC_RANKING_SeqSetFunc(seq, IRC_RANKING_SeqBrowse);
        break;
    }
}

/* Sequence step: fade out, then finish the sequence. */
void IRC_RANKING_SeqFadeOut(IrcSeq *seq, int *step, IrcRankingWork *work)
{
    switch (*step) {
    case 0: FADE_Start(3, 0, 16, 0); *step = 1; break;
    case 1: if (!FADE_IsActive()) *step = 2; break;
    case 2: IRC_RANKING_SeqFinish(seq); break;
    }
}

#define ROUND_NONZERO(a) ((int)((a)!=0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
#define ROUND_POSITIVE(a) ((int)((a)>0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
#define KEY_SCROLL_SPEED(a, round) ((int)(((long long)FX_Div(round(a)-81920,163840)*245760+2048)>>12))

/*
 * note: Unsigned conversion and ROUND use runtime-proven add C95C/sub CB8C. 8FA8 stores word +28 then tail-calls 3630C; 8E90 reads five inputs, writes Pair/Vec3/word outputs.
 */
void IRC_RANKING_SeqBrowse(IrcSeq *seq, int *step, IrcRankingWork *work) {
    u32 keyHoldFrames;
    Pair drag;
    Vec3 flick;
    int flickFrames;
    if (!IRC_APPBAR_IsBusy(work->appBar)) {
        if (IRC_RANKING_InputGetKeys(&work->input, &keyHoldFrames) & 128) {
            if (ROUND_NONZERO(keyHoldFrames) > 81920) IRC_RANKING_InertiaStart(&work->inertia, KEY_SCROLL_SPEED(keyHoldFrames, ROUND_NONZERO), 12);
            else IRC_RANKING_InertiaStart(&work->inertia, 8192, 12);
        } else if (IRC_RANKING_InputGetKeys(&work->input, &keyHoldFrames) & 64) {
            if (ROUND_NONZERO(keyHoldFrames) > 81920) IRC_RANKING_InertiaStart(&work->inertia, -KEY_SCROLL_SPEED(keyHoldFrames, ROUND_NONZERO), 12);
            else IRC_RANKING_InertiaStart(&work->inertia, -8192, 12);
        } else if (IRC_RANKING_InputGetDrag(&work->input, (Pair *)0, (Pair *)0, &drag)) {
            IRC_RANKING_ListScrollBy(&work->list, -drag.y);
            IRC_RANKING_InertiaStop(&work->inertia);
        } else if (IRC_RANKING_InputGetFlick(&work->input, (Pair *)0, (Pair *)0, &flick, &flickFrames))
            IRC_RANKING_InertiaStart(&work->inertia, VEC_DotProduct(&gIrcRankingFlickAxis, &flick), flickFrames);
    }
    if (IRC_RANKING_InertiaIsActive(&work->inertia)) IRC_RANKING_ListScrollBy(&work->list, IRC_RANKING_InertiaStep(&work->inertia));
    if (IRC_APPBAR_GetResult(work->appBar) == 1) IRC_RANKING_SeqSetFunc(seq, IRC_RANKING_SeqFadeOut);
    IRC_RANKING_ListUpdate(&work->list);
    IRC_RANKING_InputUpdate(&work->input);
    IRC_RANKING_InertiaUpdate(&work->inertia);
    IRC_APPBAR_Update(work->appBar);
}

/*
 * note: The signed-halfword result of 021B913C is already sign-extended by its body. ROUND follows the runtime-confirmed add/subtract mapping.
 */
void IRC_RANKING_SeqScrollToLatest(IrcSeq *seq, int *step, IrcRankingWork *work) {
    int target, current, last;
    target = (s16)(IRC_RANKING_ListFindLatestScrollPos(&work->list) - 192);
    if (target < 0) target = 0;
    current = IRC_RANKING_ListGetScrollPos(&work->list);
    last = IRC_RANKING_ListGetScrollMax(&work->list);
    if ((s16)target > current && current != last) {
        int n = ++work->accelStep;
        if (ROUND_POSITIVE(n) > 81920)
            IRC_RANKING_InertiaStart(&work->inertia, KEY_SCROLL_SPEED(n, ROUND_POSITIVE), 12);
        else IRC_RANKING_InertiaStart(&work->inertia, 8192, 12);
    } else {
        IRC_RANKING_InertiaStop(&work->inertia);
        IRC_RANKING_SeqSetFunc(&work->seq, IRC_RANKING_SeqBrowse);
    }
    if (IRC_RANKING_InertiaIsActive(&work->inertia)) IRC_RANKING_ListScrollBy(&work->list, IRC_RANKING_InertiaStep(&work->inertia));
    if (IRC_APPBAR_GetResult(work->appBar) == 1) IRC_RANKING_SeqSetFunc(seq, IRC_RANKING_SeqFadeOut);
    IRC_RANKING_ListUpdate(&work->list);
    IRC_RANKING_InertiaUpdate(&work->inertia);
    IRC_APPBAR_Update(work->appBar);
}

/* Sets up the backgrounds, tile and screen data and the title window on both screens. */
void IRC_RANKING_GfxInit(IrcRankingGfx *gfx, struct GameData *gameData, u32 heapId) {
    int i; int paletteBlock; u32 bg; struct MsgBank *msg; struct GfFont *font; struct Strbuf *str;
    MI_CpuFill8(gfx, 0, sizeof(IrcRankingGfx));
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(&gIrcRankingDispConfig);
    for (i = 0; i < BG_COUNT; i++) {
        bg = gIrcRankingBgEntries[i].bg;
        BG_SYS_InitBgLayer((u8)bg, &gIrcRankingBgEntries[i].bgTemplate, (u8)gIrcRankingBgEntries[i].type);
        BG_SYS_FreeSlot(bg);
        BG_SYS_SetPlaneVisible(bg, 1);
    }
    gfx->arcHandle = ARC_TOOL_CreateHandle(0x4d, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(gfx->arcHandle, 0, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(gfx->arcHandle, 1, 3, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(gfx->arcHandle, 3, 0, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(gfx->arcHandle, 4, 3, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(gfx->arcHandle, 6, 0, 0, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(gfx->arcHandle, 0, 4, 0, 0, heapId);
    paletteBlock = 7;
    ARC_UTIL_UploadBgCharFromHandle(gfx->arcHandle, 3, 7, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(gfx->arcHandle, 7, 7, 0, 0, 0, heapId);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_Init(5, 0, 1, 0);
    gfx->charRegionMain = ARC_UTIL_RegisterObjCharFromHandle(gfx->arcHandle, 2, 1, 0, 0, heapId);
    gfx->charRegionSub = ARC_UTIL_RegisterObjCharFromHandle(gfx->arcHandle, 2, 5, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, paletteBlock << 6, 0x20, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, paletteBlock << 6, 0x20, heapId);
    ARC_TOOL_DeleteHandle(gfx->arcHandle);
    msg = MSGDATA_CreateFromArchive(0, 2, 0x32, heapId);
    font = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    gfx->titleWin = BMP_WIN_Create(0, 3, 1, 0x1a, 2, 0xe, 1);
    BMP_Clear(BMP_WIN_GetBmp(gfx->titleWin), 0xf);
    str = MSGDATA_AllocString(msg, 0);
    IRC_RANKING_PrintCentered(gfx->titleWin, str, GAME_DATA_GetMyStatus(gameData), font);
    STRBUF_Delete(str);
    GF_FONT_Delete(font);
    MSGDATA_Delete(msg);
    BMP_WIN_TransferChars(gfx->titleWin);
    BMP_WIN_MakeScreen(gfx->titleWin);
    BG_SYS_PushTile(0);
}

void IRC_RANKING_GfxExit(IrcRankingGfx *gfx) {
    int i;
    BMP_WIN_Delete(gfx->titleWin);
    BG_SYS_FreeTileRun(1, (u16)gfx->charRegionMain, (u16)(gfx->charRegionMain >> 16));
    BG_SYS_FreeTileRun(5, (u16)gfx->charRegionSub, (u16)(gfx->charRegionSub >> 16));
    BG_SYS_FreeTiles(5, 1, 0);
    BG_SYS_FreeTiles(1, 1, 0);
    for (i = 0; i < BG_COUNT; i++) BG_SYS_FreeLayerBuf((u8)gIrcRankingBgEntries[i].bg);
    BMP_WIN_Exit(); BG_SYS_Delete();
    MI_CpuFill8(gfx, 0, sizeof(IrcRankingGfx));
}

void IRC_RANKING_DisplayBgVBlank(IrcRankingDisplay *display)
{
    BG_SYS_Update();
}

u32 IRC_RANKING_GfxGetCharRegion(IrcRankingGfx *gfx, u32 isMain)
{
    return isMain ? gfx->charRegionMain : gfx->charRegionSub;
}

void IRC_RANKING_ClactInit(IrcRankingClact *clact, const struct DispVramConfig *vramConfig, int heapId) {
    MI_CpuFill8(clact, 0, sizeof(IrcRankingClact));
    CLACT_InitSystem(&gIrcRankingClactSysInit, vramConfig, heapId);
    clact->unit = CLACT_CreateUnit(128, 0, heapId);
    CLACT_SetUnitDefaultRenderer(clact->unit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

void IRC_RANKING_ClactExit(IrcRankingClact *clact)
{
    CLACT_DeleteUnit(clact->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(clact, 0, sizeof(IrcRankingClact));
}

/*
 * Tail-call thunk to the ARM function at 0x0204A600.
 */
void IRC_RANKING_ClactDraw(IrcRankingClact *clact)
{
    CLACT_DrawSystem();
}

void IRC_RANKING_ClactVBlank(IrcRankingClact *clact)
{
    CLACT_VBlankSystem();
}

/*
 * First-word accessor.
 */
struct ClactUnit *IRC_RANKING_ClactGetUnit(IrcRankingClact *clact)
{
    return clact->unit;
}

void IRC_RANKING_DisplayInit(IrcRankingDisplay *display, struct GameData *gameData, u32 heapId) {
    MI_CpuFill8(display, 0, sizeof(IrcRankingDisplay));
    REG_BLDCNT = 0;
    REG_BLDCNT_SUB = 0;
    REG_DISPCNT &= ~0xe000;
    REG_DISPCNT_SUB &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&gIrcRankingVramConfig);
    BMP_SetDisplaySwap(1);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    GF_FONT_InitTextColor();
    IRC_RANKING_GfxInit(&display->gfx, gameData, heapId);
    IRC_RANKING_ClactInit(&display->clact, &gIrcRankingVramConfig, heapId);
    display->vblankTask = GFL_USE_AddMainTask(IRC_RANKING_DisplayVBlankTask, display, 0);
}

void IRC_RANKING_DisplayExit(IrcRankingDisplay *display)
{
    TCB_DeleteTask(display->vblankTask);
    IRC_RANKING_ClactExit(&display->clact);
    IRC_RANKING_GfxExit(&display->gfx);
    MI_CpuFill8(display, 0, sizeof(IrcRankingDisplay));
}

void IRC_RANKING_Draw(IrcRankingWork *work)
{
    IRC_RANKING_ClactDraw(&work->display.clact);
}

IrcRankingDisplay *IRC_RANKING_GetDisplay(IrcRankingWork *work)
{
    return &work->display;
}

struct ClactUnit *IRC_RANKING_GetClactUnit(IrcRankingWork *work)
{
    return IRC_RANKING_ClactGetUnit(&work->display.clact);
}

void IRC_RANKING_DisplayVBlankTask(void *task, void *taskWork)
{
    IrcRankingDisplay *display = taskWork;
    IRC_RANKING_DisplayBgVBlank(display);
    IRC_RANKING_ClactVBlank(&display->clact);
}

/*
 * note 2026-10-05 (final push G8L9): closed. The two zero stores at +0x556/+0x558 are written with
 *   literal 0 and `m = 0;` comes after them, just before the clamp. With `m = 0;` before the calls the
 *   zero joins the clamp's phi web, so -40 was derived from the held 1 (`subs r7,#0x29`) and 1 won the
 *   block-constant register over 0x20. With the literal zero stores the zero stays a plain constant
 *   and -40 is built fresh (`movs r1,#0; subs r1,#0x28`) while 0x20 keeps r7.
 */
void IRC_RANKING_ListInit(IrcRankingList *list, u32 rowBgMain, u8 textBgMain, u8 rowBgSub, u8 textBgSub, IrcRankingDisplay *display, struct ClactUnit *unit, struct MsgBank *msgBank, IrcRankingData *data, u16 heapId) {
    void *arc;
    int i;
    int m;
    i = 0;
    MI_CpuFill8(list, 0, sizeof(IrcRankingList));
    list->display = display;
    list->rowBgMain = rowBgMain;
    list->textBgMain = textBgMain;
    list->rowBgSub = rowBgSub;
    list->textBgSub = textBgSub;
    list->data = data;
    list->rowCount = IRC_RANKING_DataGetCount(data);
    list->font = GF_FONT_Create(23, 0, 0, 1, heapId);
    list->msgBank = msgBank;
    list->wordSet = WORDSET_CreateDefault(heapId);
    IRC_RANKING_LoadRowScreens(list->rowScreenMain, &display->gfx, heapId);
    arc = ARC_TOOL_CreateHandle(7, heapId);
    list->iconPaletteMain = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 0, 0x20, heapId);
    list->iconPaletteSub = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0x20, heapId);
    ARC_TOOL_DeleteHandle(arc);
    for (i = 0; i < IRC_RANKING_DataGetCount(data); i++) {
        IRC_RANKING_RowInit(&list->rows[i], &data->items[i], unit, list->iconPaletteMain, list->iconPaletteSub, list->msgBank, list->font, list->wordSet, list->rowScreenMain, i * ROW_HEIGHT + 0x52, i * ROW_HEIGHT - 0x70, heapId);
    }
    list->textWin[0] = BMP_WIN_Create(textBgMain, 0, 0, 0x20, 0x20, 14, 1);
    list->textWin[1] = BMP_WIN_Create(textBgSub, 0, 0, 0x20, 0x20, 14, 1);
    list->bgScrollMain = -40;
    list->bgScrollSub = 24;
    BG_SYS_ChangeScrollImmediate(list->rowBgMain, 3, list->bgScrollMain);
    BG_SYS_ChangeScrollImmediate(list->textBgMain, 3, list->bgScrollMain);
    BG_SYS_ChangeScrollImmediate(list->rowBgSub, 3, list->bgScrollSub);
    BG_SYS_ChangeScrollImmediate(list->textBgSub, 3, list->bgScrollSub);
    list->scrollPos = 0;
    list->scrollMin = 0;
    m = 0;
    list->scrollMax = list->rowCount * ROW_HEIGHT - 0x120;
    if (list->scrollMax > 0) m = list->scrollMax;
    list->scrollMax = m;
    IRC_RANKING_ListDrawRows(list);
    IRC_RANKING_ListTransferWindows(list);
    list->scrollTask = GFL_USE_AddMainTask(IRC_RANKING_ListScrollTask, list, 0);
}

void IRC_RANKING_ListExit(IrcRankingList *list) {
    int i;
    TCB_DeleteTask(list->scrollTask);
    for (i = 0; i < 2; i++) BMP_WIN_Delete(list->textWin[i]);
    for (i = 0; i < IRC_RANKING_DataGetCount(list->data); i++) IRC_RANKING_RowExit(&list->rows[i]);
    CLACT_ReleasePalette(list->iconPaletteMain);
    CLACT_ReleasePalette(list->iconPaletteSub);
    IRC_RANKING_ClearRowScreens(list->rowScreenMain);
    WORDSET_Delete(list->wordSet);
    GF_FONT_Delete(list->font);
    MI_CpuFill8(list, 0, sizeof(IrcRankingList));
}

/* After a scroll, snaps to a row boundary: redraws the rows and plays a sound when the top row changed, else asks for a scroll fix-up. */
void IRC_RANKING_ListUpdate(IrcRankingList *list) {
    int value;
    if (list->needSnap == 0) return;
    list->needSnap = 0;
    value = list->scrollPos;
    if (value % ROW_HEIGHT == 0) {
        if (list->topRow != value / ROW_HEIGHT) GFL_USE_PlaySeDefaultVolume(1605);
        list->topRow = list->scrollPos / ROW_HEIGHT;
        list->bgScrollMain = -40;
        list->bgScrollSub = 24;
        IRC_RANKING_ListDrawRows(list);
        list->needTransfer = 1;
    } else list->needScrollApply = 1;
}

/* Scrolls the list by delta pixels, clamped to the scroll limits and snapped to a row boundary when one is crossed, and moves the icon sprites. */
void IRC_RANKING_ListScrollBy(IrcRankingList *list, s16 delta) {
    int old, next;
    int i;
    old = list->scrollPos;
    next = old + delta;
    if (list->scrollMin > next) {
        list->scrollPos = list->scrollMin;
        list->lastDelta = 0;
    } else if (list->scrollMax < next) {
        list->scrollPos = list->scrollMax;
        list->lastDelta = 0;
    } else {
        if (old / ROW_HEIGHT != next / ROW_HEIGHT && old % ROW_HEIGHT != 0) {
            if (delta >= 0) delta = delta - next % ROW_HEIGHT;
            else delta = delta + (ROW_HEIGHT - next % ROW_HEIGHT);
        }
        list->scrollPos += delta;
        list->lastDelta = delta;
    }
    for (i = 0; i < list->rowCount; i++) IRC_RANKING_RowSetScroll(&list->rows[i], list->scrollPos);
    list->needSnap = 1;
}

s16 IRC_RANKING_ListGetScrollPos(IrcRankingList *list)
{
    return list->scrollPos;
}

/*
 * volatile: count halfword re-read at 0x021B84D6 and 0x021B84F4.
 */
int IRC_RANKING_ListFindLatestScrollPos(IrcRankingList *list) {
    int i;
    int found;
    found = 0;
    i = 0;
    for (; i < *(volatile u16 *)&list->rowCount; i++) {
        if (list->rows[i].item->isLatest != 0) { found = 1; break; }
    }
    if (found) return (s16)(ROW_HEIGHT * i);
    return -1;
}

s16 IRC_RANKING_ListGetScrollMax(IrcRankingList *list)
{
    return list->scrollMax;
}

/* Redraws the visible rows of both screens into their text windows and row backgrounds. */
void IRC_RANKING_ListDrawRows(IrcRankingList *list) {
    int i, y;
    BG_SYS_SetTileEntry(list->rowBgMain, 0, 0, 0, 32, 24, 0);
    BG_SYS_SetTileEntry(list->rowBgSub, 0, 0, 0, 32, 24, 0);
    BMP_Clear(BMP_WIN_GetBmp(list->textWin[0]), 0);
    BMP_Clear(BMP_WIN_GetBmp(list->textWin[1]), 0);
    for (i = list->topRow - 1; i < list->topRow + 10; i++) {
        if (i >= 0 && i < list->rowCount) {
            y = (i - list->topRow) * 3 + 4;
            if (y >= 0 && y <= 24)
                IRC_RANKING_RowDraw(&list->rows[i], list->textWin[0], list->rowBgMain, y);
        }
    }
    for (i = list->topRow + 4; i < list->topRow + 17; i++) {
        if (i >= 0 && i < list->rowCount) {
            y = (i - (list->topRow + 4)) * 3;
            if (y >= 0 && y <= 24)
                IRC_RANKING_RowDraw(&list->rows[i], list->textWin[1], list->rowBgSub, y);
        }
    }
}

void IRC_RANKING_ListTransferWindows(IrcRankingList *list) {
    int i;
    for (i = 0; i < 2; i++) {
        BMP_WIN_TransferChars(list->textWin[i]);
        BMP_WIN_MakeScreen(list->textWin[i]);
    }
    BG_SYS_PushTile(list->rowBgMain);
    BG_SYS_PushTile(list->rowBgSub);
    BG_SYS_PushTile(list->textBgMain);
    BG_SYS_PushTile(list->textBgSub);
}

/*
 * Evidence: original signed halfword loads and stores fix scroll widths.
 * ARM9 BG_SYS_ChangeScrollImmediate's legacy fourth input is forwarded only to
 * BG_SYS_SetScrollField, whose complete three-input body does not read it;
 * this caller supplies only three inputs, so the unused fourth is omitted.
 */
void IRC_RANKING_ListScrollTask(void *task, void *taskWork)
{
    IrcRankingList *list = taskWork;
    s16 rem, x, y;
    if (list->needTransfer) {
        IRC_RANKING_ListTransferWindows(list);
        list->needTransfer = 0;
        list->needScrollApply = 1;
    }
    if (list->needScrollApply) {
        rem = list->scrollPos % ROW_HEIGHT;
        if (rem == 0) {
            x = list->bgScrollMain + rem;
            y = list->bgScrollSub + rem;
            list->scrollDir = list->lastDelta;
            list->dirChanged = 1;
        } else {
            if ((list->lastDelta >= 0 && list->scrollDir >= 0) ||
                (list->lastDelta < 0 && list->scrollDir < 0) || list->dirChanged != 0) {
                list->dirChanged = 0;
                if (list->lastDelta >= 0) {
                    x = list->bgScrollMain + rem;
                    y = list->bgScrollSub + rem;
                    list->scrollDir = 1;
                } else {
                    x = list->bgScrollMain - (23 - rem);
                    y = list->bgScrollSub - (23 - rem);
                    list->scrollDir = -1;
                }
            } else {
                if (list->scrollDir >= 0) {
                    x = list->bgScrollMain + rem;
                    y = list->bgScrollSub + rem;
                    list->scrollDir = 1;
                } else {
                    x = list->bgScrollMain - (23 - rem);
                    y = list->bgScrollSub - (23 - rem);
                    list->scrollDir = -1;
                }
            }
        }
        BG_SYS_ChangeScrollImmediate(list->rowBgMain, 3, x);
        BG_SYS_ChangeScrollImmediate(list->textBgMain, 3, x);
        BG_SYS_ChangeScrollImmediate(list->rowBgSub, 3, y);
        BG_SYS_ChangeScrollImmediate(list->textBgSub, 3, y);
        list->needScrollApply = 0;
    }
}

/*
 * lever: the r3 and first-stack token parameters and the loop's token local
 *   are full words (u32); as u16 the prologue spill of r3 and the in-arm token
 *   reload scheduled differently (43 bytes).  CLACT_CreateActor takes the word in
 *   its u32 third slot, so no narrowing is visible anywhere.
 */
void IRC_RANKING_RowInit(IrcRankingRow *row, const IrcRankingItem *item, struct ClactUnit *unit, u32 palResMain, u32 palResSub, struct MsgBank *msgBank, struct GfFont *font, struct WordSet *wordSet, u16 *screenData, s16 mainY, s16 subY, u16 heapId) {
    ActorInitParam param; u32 graphicIndex, cellAnim, cellBank; void *arc; struct Strbuf *rankFormat, *scoreFormat, *meetFormat, *text; int i, width; u32 palRes;
    i = 0;
    MI_CpuFill8(row, 0, sizeof(IrcRankingRow));
    row->item = item; row->screenData = screenData;
    row->textBmp = BMP_Create(32, 3, 32, heapId);
    rankFormat = STRBUF_Create(32, heapId); scoreFormat = STRBUF_Create(32, heapId);
    meetFormat = STRBUF_Create(32, heapId); text = STRBUF_Create(32, heapId);
    MSGDATA_ReadString(msgBank, MSG_ID_RANK_FORMAT, rankFormat); MSGDATA_ReadString(msgBank, MSG_ID_SCORE_FORMAT, scoreFormat); MSGDATA_ReadString(msgBank, MSG_ID_MEET_COUNT_FORMAT, meetFormat);
    WORDSET_SetSlotNumber(wordSet, 0, item->rank, 2, 0, 1);
    WORDSET_SetSlotNumber(wordSet, 2, item->score, 3, 0, 1);
    WORDSET_SetSlotNumber(wordSet, 3, item->meetCount, 3, 0, 1);
    WORDSET_CopyTaggedText(wordSet, text, rankFormat);
    width = GF_FONT_MeasureWidestLine(text, font, 0) >> 1;
    PRINTSYS_Print(row->textBmp, 38 - width, 5, text, font);
    PRINTSYS_Print(row->textBmp, 52, 5, item->name, font);
    WORDSET_CopyTaggedText(wordSet, text, scoreFormat);
    width = GF_FONT_MeasureWidestLine(text, font, 0) >> 1;
    PRINTSYS_Print(row->textBmp, 142 - width, 5, text, font);
    WORDSET_CopyTaggedText(wordSet, text, meetFormat);
    width = GF_FONT_MeasureWidestLine(text, font, 0) >> 1;
    PRINTSYS_Print(row->textBmp, 194 - width, 5, text, font);
    STRBUF_Delete(text); STRBUF_Delete(meetFormat); STRBUF_Delete(scoreFormat); STRBUF_Delete(rankFormat);
    graphicIndex = POKE_TOOL_CalcGraphicIndex(item->species, item->form, item->gender, item->isEgg);
    cellAnim = POKE_TOOL_GetIconCellArcId(); cellBank = POKE_TOOL_GetIconCellEntryId();
    arc = ARC_TOOL_CreateHandle(7, heapId);
    row->iconCharRes = CLACT_RegisterCharacter(arc, graphicIndex, 0, 2, heapId);
    row->iconCellRes = CLACT_RegisterCellAnim(arc, cellAnim, cellBank, heapId);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&param, 0, sizeof(ActorInitParam)); param.animIndex = 1; param.bgPriority = 1;
    for (; i < 2; i++) {
        param.x = 232;
        if (i == 0) { param.y = mainY; palRes = palResMain; } else { param.y = subY; palRes = palResSub; }
        row->iconY[i] = param.y;
        row->iconActors[i] = CLACT_CreateActor(unit, row->iconCharRes, palRes, row->iconCellRes, &param, i, heapId);
        CLACT_SetActorPaletteOffset(row->iconActors[i], POKE_TOOL_CalcIconPalette(item->species, item->form, item->gender, item->isEgg), 0);
        if (param.y > -16 && param.y < 208) CLACT_SetActorDrawEnable(row->iconActors[i], 1);
        else CLACT_SetActorDrawEnable(row->iconActors[i], 0);
    }
}

void IRC_RANKING_RowExit(IrcRankingRow *row)
{
    int i;
    for (i = 0; i < 2; i++) CLACT_DeleteActor(row->iconActors[i]);
    CLACT_ReleaseCharacter(row->iconCharRes);
    CLACT_ReleaseCellAnim(row->iconCellRes);
    BMP_Delete(row->textBmp);
    MI_CpuFill8(row, 0, sizeof(IrcRankingRow));
}

/*
 * extent: two zero padding bytes follow the return, before 0x021B8A6C.
 */
void IRC_RANKING_RowDraw(IrcRankingRow *row, struct BmpWin *win, u32 bgId, u16 y) {
    IRC_RANKING_CopyBmpTiles(row->textBmp, BMP_WIN_GetBmp(win), 0, 0, 0, y, 32, 3);
    IRC_RANKING_WriteRowScreen(row->screenData, bgId, y, row->item->rowStyle);
}

/* Positions the row's icon sprites for the current scroll position and hides those outside the screen. */
void IRC_RANKING_RowSetScroll(IrcRankingRow *row, int scroll) {
    OamPos pos;
    int offsets[2];
    int i;
    offsets[0] = -scroll;
    offsets[1] = -scroll;
    for (i = 0; i < 2; i++) {
        CLACT_GetActorSurfacePos(row->iconActors[i], &pos, i);
        pos.y = offsets[i] + row->iconY[i];
        CLACT_AddActorSurfacePos(row->iconActors[i], &pos, i);
        if (pos.y > -16 && pos.y < 208) CLACT_SetActorDrawEnable(row->iconActors[i], 1);
        else CLACT_SetActorDrawEnable(row->iconActors[i], 0);
    }
}

/* Loads the row background screen data (3 rows of 32 entries) and offsets its tile numbers by the char region of each screen. */
void IRC_RANKING_LoadRowScreens(u16 *screens, IrcRankingGfx *gfx, u16 heapId) {
    void *screenFile;
    void *allocation;
    const u16 *table;
    u16 charRegionMain, charRegionSub;
    int i, j;
    MI_CpuFill8(screens, 0, ROW_SCREEN_BYTES);
    charRegionMain = IRC_RANKING_GfxGetCharRegion(gfx, 1);
    charRegionSub = IRC_RANKING_GfxGetCharRegion(gfx, 0);
    allocation = ARC_UTIL_LoadPaletteDataFromArchive(77, 5, 0, &screenFile, heapId);
    table = (const u16 *)((u8 *)screenFile + 12);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 32; j++) {
            screens[i * 32 + j] = table[i * 32 + j] + charRegionMain;
            screens[i * 32 + j + 96] = table[i * 32 + j] + charRegionSub;
        }
    }
    GFL_HEAP_Free(allocation);
}

void IRC_RANKING_ClearRowScreens(u16 *screens)
{
    MI_CpuFill8(screens, 0, ROW_SCREEN_BYTES);
}

/* Writes one 3-row background strip to a bg and colours it with the row style. */
void IRC_RANKING_WriteRowScreen(u16 *screens, u32 bgId, int y, u8 style) {
    u8 *p = (u8 *)screens;
    if (bgId >= 4) p += 192;
    BG_SYS_DrawTile(bgId, p, 0, (u8)y, 32, 3);
    BG_SYS_FillTileMap(bgId, 0, y, 32, 3, style);
}

/* Builds the ranking data from the save: entries in saved order with rank (ties share a rank), row style from rank, gender and latest flag, and the Pokemon icon fields. */
IrcRankingData *IRC_RANKING_DataCreate(struct GameData *gameData, u16 heapId) {
    struct IrcRankSave *save; u16 count; IrcRankingData *out; IrcRankingItem *item; u32 i; u8 prevScore, rank, latest;
    save = IRC_RANKING_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    count = IRC_RANKING_GetEntryCount(save);
    out = GFL_HEAP_Alloc(heapId, count * sizeof(IrcRankingItem) + sizeof(IrcRankingData), 0, gIrcRankingFileName, 2724);
    MI_CpuFill8(out, 0, count * sizeof(IrcRankingItem) + sizeof(IrcRankingData));
    out->count = count;
    if (count) {
        prevScore = 128; rank = 0; latest = IRC_RANKING_GetLastSlot(save);
        for (i = 0; i < out->count; i++) {
            item = &out->items[i];
            item->name = STRBUF_Create(8, heapId);
            STRBUF_SetString(item->name, IRC_RANKING_GetEntry(save, i));
            item->score = IRC_RANKING_GetEntryScore(save, i);
            item->meetCount = IRC_RANKING_GetEntryMeetCount(save, i);
            if (item->score < prevScore) item->rank = i + 1;
            else if (item->score == prevScore) item->rank = rank;
            {
                u8 gender; int v;
                gender = IRC_RANKING_GetEntryGender(save, i);
                if (latest == i) {
                    v = gender == 0;
                    item->rowStyle = 5 * (v + 1);
                    item->isLatest = 1;
                } else if (item->rank == 1) {
                    v = 0; if (gender == 0) v = 5; item->rowStyle = v + 2;
                } else if (item->rank == 2) {
                    v = 0; if (gender == 0) v = 5; item->rowStyle = v + 3;
                } else if (item->rank == 3) {
                    v = 0; if (gender == 0) v = 5; item->rowStyle = v + 4;
                } else {
                    v = 0; if (gender == 0) v = 5; item->rowStyle = v + 1;
                }
            }
            IRC_RANKING_GetEntryProfile(save, i, &item->species, &item->form, &item->gender, &item->isEgg);
            prevScore = item->score; rank = item->rank;
        }
    }
    return out;
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void IRC_RANKING_DataDelete(IrcRankingData *data)
{
    u32 i;
    if (data->count != 0) {
        for (i = 0; i < data->count; i++) {
            struct Strbuf *name;
            name = data->items[i].name;
            if (name) STRBUF_Delete(name);
        }
    }
    GFL_HEAP_Free(data);
}

u32 IRC_RANKING_DataGetCount(IrcRankingData *data)
{
    return data->count;
}

void IRC_RANKING_InputInit(IrcRankingInput *input, u32 heapId)
{
    MI_CpuFill8(input, 0, sizeof(IrcRankingInput));
}

void IRC_RANKING_InputExit(IrcRankingInput *input)
{
    MI_CpuFill8(input, 0, sizeof(IrcRankingInput));
}


/*
 * extent: two zero padding bytes follow the return, before 0x021B8E50.
 */
void IRC_RANKING_InputUpdate(IrcRankingInput *input) {
    int x, y;
    int d;
    if (TOUCHPANEL_GetPointTrg(&x, &y)) {
        input->start.x = x; input->start.y = y;
        input->current.x = x; input->current.y = y;
        input->prev.x = x; input->prev.y = y;
        input->delta.x = 0; input->delta.y = 0;
        input->holdFrames = 0;
    } else if (TOUCHPANEL_GetPointCont(&x, &y)) {
        d = y - input->start.y;
        if (d < 0) d = -d;
        if (d >= 1) {
            input->delta.x = x - input->prev.x; input->delta.y = y - input->prev.y;
            input->prev.x = x; input->prev.y = y;
        }
        input->current.x = x; input->current.y = y; input->holdFrames++; input->idleFrames = 0;
    } else input->idleFrames++;
    if (KEY_GetTrg() & 192) { input->keyHoldFrames = 0; return; }
    if (KEY_GetCont() & 192) input->keyHoldFrames++;
}

/*
 * extent: two bytes of alignment padding after the return.
 */
int IRC_RANKING_InputGetDrag(IrcRankingInput *input, Pair *start, Pair *current, Pair *delta) {
    if (TOUCHPANEL_GetCont()) {
        if (start) *start = input->start;
        if (current) *current = input->current;
        if (delta) *delta = input->delta;
        return 1;
    }
    return 0;
}

static inline int ToFixedRounded(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}

/* Reports the finished touch once (start, end, direction vector, hold time) when no key is held. */
int IRC_RANKING_InputGetFlick(IrcRankingInput *input, Pair *start, Pair *end, Vec3 *delta, int *holdFrames)
{
    Vec3 a, b;
    int y;
    if (!KEY_GetCont()) {
        if (input->idleFrames < 1) {
            input->idleFrames = 1;
            if (start)
                *start = input->start;
            if (end)
                *end = input->current;
            if (delta) {
                y = ToFixedRounded(input->start.y);
                a.x = ToFixedRounded(input->start.x);
                a.y = y;
                a.z = 0;
                y = ToFixedRounded(input->current.y);
                b.x = ToFixedRounded(input->current.x);
                b.z = 0;
                b.y = y;
                VEC_Subtract(&a, &b, delta);
            }
            if (holdFrames)
                *holdFrames = input->holdFrames;
            return 1;
        }
    }
    return 0;
}

unsigned int IRC_RANKING_InputGetKeys(IrcRankingInput *input, u32 *keyHoldFrames)
{
    if (keyHoldFrames) *keyHoldFrames = input->keyHoldFrames;
    return KEY_GetCont();
}

void IRC_RANKING_InertiaInit(IrcRankingInertia *inertia)
{
    MI_CpuFill8(inertia, 0, sizeof(IrcRankingInertia));
}

void IRC_RANKING_InertiaExit(IrcRankingInertia *inertia)
{
    MI_CpuFill8(inertia, 0, sizeof(IrcRankingInertia));
}

/*
 * trailing: two-byte alignment padding, no follower.
 */
void IRC_RANKING_InertiaUpdate(IrcRankingInertia *inertia)
{
    if (inertia->dirty) {
        inertia->dirty = 0;
        inertia->velocity = inertia->baseSpeed + inertia->damping / 2;
        inertia->velocity = (int)(((long long)inertia->velocity * 163840 + 2048) >> 12);
    }
}

static inline int Abs32(int v) { return v < 0 ? (int)(0u - (u32)v) : v; }

static inline int ToFixedRoundedUnsigned(int v) {
    if (v != 0) return _ffix(_fadd(0.5f, _ffltu((u32)v << 12)));
    return _ffix(_fsub(_ffltu((u32)v << 12), 0.5f));
}

/*
 * note: Compiled code ends 021B9132; handed tail 021B9132..021B9134 is two zero alignment bytes. Unsigned magnitude subtraction and duration shift preserve 32-bit wrap; runtime helpers retain all repeated calls.
 */
void IRC_RANKING_InertiaStart(IrcRankingInertia *inertia, int speed, int duration) {
    int value;
    if (Abs32(speed) <= 4096) return;
    inertia->direction = speed / Abs32(speed);
    speed = Abs32(speed);
    if (speed > 245760) speed = 245760;
    else if (speed < 4096) speed = 4096;
    if (ToFixedRoundedUnsigned(duration) >= 53248) return;
    if (ToFixedRoundedUnsigned(duration) > 53248) value = 53248;
    else if (ToFixedRoundedUnsigned(duration) < 0) value = 0;
    else value = ToFixedRoundedUnsigned(duration);
    inertia->baseSpeed = FX_Div(speed - 4096, 241664);
    inertia->damping = 4096 - FX_Div(value, 53248);
    inertia->dirty = 1;
}

void IRC_RANKING_InertiaStop(IrcRankingInertia *inertia)
{
    inertia->velocity = 0;
}

/* One step of scroll momentum: returns the pixel delta and decays the velocity. */
short IRC_RANKING_InertiaStep(IrcRankingInertia *inertia) {
    int v = inertia->velocity * inertia->direction;
    if (v > 32768) v = 32768; else if (v < -32768) v = -32768;
    inertia->velocity -= (int)(((long long)inertia->velocity * 205 + 2048) >> 12);
    if (inertia->velocity > -4096 && inertia->velocity < 4096) inertia->velocity = 0;
    return (short)(v >> 12);
}

int IRC_RANKING_InertiaIsActive(IrcRankingInertia *inertia)
{
    if (inertia->velocity) return 1;
    else return 0;
}

/* Prints text centred in a window; with myStatus the text is first expanded with the player's name. */
void IRC_RANKING_PrintCentered(struct BmpWin *win, struct Strbuf *text, void *myStatus, struct GfFont *font) {
    u16 x, y; struct WordSet *wordSet; struct Strbuf *expanded;
    if (!myStatus) {
        x = BMP_WIN_GetWidth(win) * 4;
        y = BMP_WIN_GetHeight(win) * 4;
        x -= (u16)(GF_FONT_MeasureWidestLine(text, font, 0) >> 1);
        y -= (u16)(GF_FONT_CountLines(text, font) >> 1);
        PRINTSYS_Print(BMP_WIN_GetBmp(win), (s16)x, (s16)y, text, font);
    } else {
        wordSet = WORDSET_CreateDefault(0x8043);
        expanded = STRBUF_Create(128, 0x8043);
        WORDSET_SetSlotMyStatus(wordSet, 0, myStatus);
        WORDSET_CopyTaggedText(wordSet, expanded, text);
        x = BMP_WIN_GetWidth(win) * 4;
        y = BMP_WIN_GetHeight(win) * 4;
        x -= (u16)(GF_FONT_MeasureWidestLine(expanded, font, 0) >> 1);
        y -= (u16)(GF_FONT_CountLines(expanded, font) >> 1);
        PRINTSYS_Print(BMP_WIN_GetBmp(win), (s16)x, (s16)y, expanded, font);
        STRBUF_Delete(expanded);
        WORDSET_Delete(wordSet);
    }
}

/* Copies a width x height block of 4bpp tiles between two bitmaps (positions in tiles). */
void IRC_RANKING_CopyBmpTiles(struct Bmp *srcBmp, struct Bmp *dstBmp, int srcX, int srcY, u16 dstX, u16 dstY, u16 width, u16 height) {
    u8 *src = BMP_GetPixels(srcBmp);
    u8 *dst = BMP_GetPixels(dstBmp);
    MIi_CpuCopy32(src + (srcX + width * srcY) * 32, dst + (dstX + width * dstY) * 32, width * height * 32);
}

/* Creates a header label: a bitmap shown as a bitmap OAM. */
IrcRankingLabel *IRC_RANKING_LabelCreate(const IrcRankingLabelPos *pos, u8 widthTiles, u8 heightTiles, int animResId, u8 palette, int screen, struct BmpOamSys *oamSys, struct PrintQue *printQue, u16 heapId) {
    IrcRankingLabel *label; BmpOamParam param;
    label = GFL_HEAP_Alloc(heapId, sizeof(IrcRankingLabel), 0, gIrcRankingFileName, 3402);
    MI_CpuFill8(label, 0, sizeof(IrcRankingLabel));
    label->printQue = printQue;
    label->text = STRBUF_Create(128, heapId);
    label->bmp = BMP_Create(widthTiles, heightTiles, 32, heapId);
    MI_CpuFill8(&param, 0, sizeof(BmpOamParam));
    param.bmp = label->bmp; param.x = pos->x; param.y = pos->y;
    param.animResId = animResId; param.drawPriority = pos->drawPriority; param.space = screen; param.engine = screen; param.bgPriority = pos->bgPriority; param.palette = palette;
    label->oam = BMP_OAM_Create(oamSys, &param);
    return label;
}

void IRC_RANKING_LabelDelete(IrcRankingLabel *label)
{
    BMP_OAM_Delete(label->oam);
    BMP_Delete(label->bmp);
    STRBUF_Delete(label->text);
    GFL_HEAP_Free(label);
}

/*
 * extent: two bytes of alignment padding after the return.
 */
void IRC_RANKING_LabelSetText(IrcRankingLabel *label, struct MsgBank *msgBank, u32 msgId, struct GfFont *font) {
    Pair pos;
    BMP_Clear(label->bmp, label->printColor & 31);
    MSGDATA_ReadString(msgBank, msgId, label->text);
    IRC_RANKING_LabelCalcTextPos(label, font, &pos);
    PRINTSYS_PrintQueColor(label->printQue, label->bmp, (short)pos.x, (short)pos.y, label->text, font, label->printColor);
    label->pending = 1;
}

void IRC_RANKING_LabelSetColor(IrcRankingLabel *label, u16 printColor)
{
    label->printColor = printColor;
}

void IRC_RANKING_LabelSetAlign(IrcRankingLabel *label, u32 offsetX, u32 offsetY, u32 alignMode)
{
    label->offset.x = offsetX;
    label->offset.y = offsetY;
    label->alignMode = alignMode;
}

int IRC_RANKING_LabelUpdate(IrcRankingLabel *label)
{
    if (label->pending && !PRINTSYS_QUE_IsExistTarget(label->printQue, label->bmp)) {
        BMP_OAM_UploadChars(label->oam);
        label->pending = 0;
    }
    if (!label->pending) return 1;
    return 0;
}

/*
 * Computes the print position of a label's text into out: the plain offset
 * (alignMode 0), centred on both axes (1), or centred vertically only (2),
 * relative to the label offset.
 * The mode 0 copy is an 8-byte struct assignment, which is why the image
 * loads both words before either store.
 */
void IRC_RANKING_LabelCalcTextPos(IrcRankingLabel *label, struct GfFont *font, Pair *out)
{
    switch (label->alignMode) {
    case 0: {
        *out = label->offset;
        return;
    }
    case 1: {
        u32 x = (u32)BMP_GetWidth(label->bmp) >> 1;
        u32 y = (u32)BMP_GetHeight(label->bmp) >> 1;
        x -= GF_FONT_MeasureWidestLine(label->text, font, 0) >> 1;
        y -= GF_FONT_CountLines(label->text, font) >> 1;
        out->x = x + label->offset.x;
        out->y = y + label->offset.y;
        return;
    }
    case 2: {
        u32 y = (u32)BMP_GetHeight(label->bmp) >> 1;
        u32 ny = y - (GF_FONT_CountLines(label->text, font) >> 1);
        out->x = label->offset.x;
        out->y = ny + label->offset.y;
        return;
    }
    }
}
