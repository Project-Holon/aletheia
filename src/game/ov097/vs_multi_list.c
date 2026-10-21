/*
 * file:     vs_multi_list.c
 * unit:     yes
 * function: VS_MULTI_LIST_ProcInit, VS_MULTI_LIST_ProcMain, VS_MULTI_LIST_ProcExit, VS_MULTI_LIST_StateSetup, VS_MULTI_LIST_StateTeardown, VS_MULTI_LIST_StateWaitWipe, VS_MULTI_LIST_StateWaitFrames, VS_MULTI_LIST_StateSlideIn, VS_MULTI_LIST_StartWipeIn, VS_MULTI_LIST_StartWipeOut, VS_MULTI_LIST_EnterWaitState, VS_MULTI_LIST_SetVramBanks, VS_MULTI_LIST_InitBgs, VS_MULTI_LIST_ExitBgs, VS_MULTI_LIST_LoadBgGraphics, VS_MULTI_LIST_CreateTextResources, VS_MULTI_LIST_DeleteTextResources, VS_MULTI_LIST_AddVBlankTask, VS_MULTI_LIST_DeleteVBlankTask, VS_MULTI_LIST_VBlankCallback, VS_MULTI_LIST_InitMons, VS_MULTI_LIST_CreateWindows, VS_MULTI_LIST_DeleteWindows, VS_MULTI_LIST_UpdatePrintQueue, VS_MULTI_LIST_PrintName, VS_MULTI_LIST_PrintLevel, VS_MULTI_LIST_PrintHp, VS_MULTI_LIST_DrawHpDivider, VS_MULTI_LIST_InitIcons, VS_MULTI_LIST_ExitIcons, VS_MULTI_LIST_InitClact, VS_MULTI_LIST_ExitClact, VS_MULTI_LIST_LoadIconResources, VS_MULTI_LIST_ReleaseIconResources, VS_MULTI_LIST_CreateActors, VS_MULTI_LIST_DeleteActors, VS_MULTI_LIST_MoveActorX, VS_MULTI_LIST_MoveSlotActors, VS_MULTI_LIST_CreateBgFrames, VS_MULTI_LIST_DeleteBgFrames
 * address:  0x021F6560
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vs_multi_list.c, VS_MULTI_LIST_DeleteBgFrames.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   gVsMultiListStateTable 0x021F7608 data a4
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   VS_MULTI_LIST_DeleteBgFrames 0x021F75E0 thumb ov097
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   gVsMultiListDispVram 0x021F761C data a4
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   gVsMultiListDispConfig     0x021F75F8  data  ov097  a4
 *   gVsMultiListBg0Template     0x021F7688  data  ov097  a4
 *   gVsMultiListBg1Template     0x021F7668  data  ov097  a4
 *   gVsMultiListBg2Template     0x021F76A8  data  ov097  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   BMP_FillRect 0x02043AF4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   gVsMultiListClactInit 0x021F764C data a4
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcIdSub 0x0201BC78 thumb
 *   POKE_TOOL_GetIconCellEntryIdSub 0x0201BCEC thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetGearCellFileId 0x0202775C thumb
 *   APP_ICON_GetNoneFileId 0x02027758 thumb
 *   APP_ICON_GetGearPaletteFileId 0x02027760 thumb
 *   APP_ICON_GetGearAnimFileId 0x02027764 thumb
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gVsMultiListActorDescs 0x021F76C8 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BGWINFRM_Create 0x0202C9B4 thumb
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BGWINFRM_SetFrameData 0x0202CAC4 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BG_SYS_GetBuf 0x0204162C arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   gVsMultiListSrcName 0x021F78C0 data a4
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 */
#include "../types.h"
#include "../sdk_ioreg_reg.h"
#include "../arm9/bg_sys.h"
#include "../arm9/clact.h"

struct Proc;
struct WinMgr;
struct PrintSys;
struct DispVram;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct BmpWin;
struct Bmp;
struct PokeParty;
struct PokemonParam;
struct ArcHandle;
struct VBlankTask;
struct Unit;
struct ClactActor;
struct VsMultiList;

/* Creation record of one actor (data gVsMultiListActorDescs, 24 entries). */
struct VsMultiActorDesc {
    u32 posX;
    u32 posY;
    u32 charIndex;
    u32 paletteIndex;
    u32 cellAnimIndex;
};

/* The two parties and the side the first party is shown on (proc argument). */
struct VsMultiListArgs {
    struct PokeParty *party0;
    struct PokeParty *party1;
    int swapSides;
};

/* One text window of a Pokemon slot; dirty is set while the print queue still draws into it. */
struct VsMultiListWindow {
    struct BmpWin *bmpWin;
    u8 dirty;
    u8 pad05[3];
};

/* The 24 actors: four sets of six (one actor per slot in each set). */
struct VsMultiListActors {
    struct ClactActor *icon[6];
    struct ClactActor *heldItem[6];
    struct ClactActor *markerC[6];
    struct ClactActor *markerD[6];
};

/* Work of the proc (0x120 bytes). Slots 0 to 2 are one team, 3 to 5 the other. */
struct VsMultiList {
    struct VsMultiListArgs *args;
    struct VBlankTask *vblankTask;
    struct WinMgr *bgFrames;
    struct GfFont *font;
    struct GfFont *fontSmall;
    struct MsgBank *msgBank;
    struct WordSet *wordSet;
    struct PrintSys *printQue;
    struct VsMultiListWindow windows[6];
    struct Unit *clactUnit;
    union {
        struct ClactActor *all[24];
        struct VsMultiListActors set;
    } actors;
    u32 charIds[9];
    u32 paletteIds[4];
    u32 cellAnimIds[4];
    struct PokemonParam *mons[6];
    u32 slidePhase;
    int stateAfterWait;
    int stateAfterWipe;
    int waitFrames;
};

/* State numbers returned by the state functions. */
#define VS_MULTI_LIST_STATE_SETUP 0
#define VS_MULTI_LIST_STATE_TEARDOWN 1
#define VS_MULTI_LIST_STATE_WAIT_WIPE 2
#define VS_MULTI_LIST_STATE_WAIT_FRAMES 3
#define VS_MULTI_LIST_STATE_SLIDE 4
#define VS_MULTI_LIST_STATE_END 5


/* Values read with POKE_TOOL_GetPartyValue (ids of enum PokeToolParam in poke_tool.c). */
#define POKE_TOOL_PARAM_HELD_ITEM 6
#define POKE_TOOL_PARAM_IS_EGG 0x4C
#define POKE_TOOL_PARAM_LEVEL 0x9E
#define POKE_TOOL_PARAM_HP 0xA0
#define POKE_TOOL_PARAM_MAX_HP 0xA1
#define POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN 0xAD

enum { NUMBER_DISP_LEFT };

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct BgWinFrmWork;
#include "../arm9/bgwinfrm.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/net.h"
#include "../arm9/wipe.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/gfl_use.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
#include "../arm9/wordset.h"
struct TcbTask;
struct TcbTask;
#include "../arm9/tcb_list.h"
struct Party;
#include "../arm9/pokeparty.h"
#include "../arm9/bmp_win.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/strbuf.h"
#include "../arm9/poke_tool.h"
struct DispVramCfg;
struct SysInit;
struct BoxPokemon;
#include "../arm9/poke_tool_ext.h"
#include "../arm9/app_icon.h"
struct ClactActor;
#include "../arm9/file_util.h"

int VS_MULTI_LIST_ProcInit(struct Proc *proc, int seq, struct VsMultiListArgs *args);
int VS_MULTI_LIST_ProcMain(struct Proc *proc, int *seq, int unused, struct VsMultiList *work);
int VS_MULTI_LIST_ProcExit(struct Proc *proc);
int VS_MULTI_LIST_StateSetup(struct VsMultiList *work);
int VS_MULTI_LIST_StateTeardown(struct VsMultiList *work);
int VS_MULTI_LIST_StateWaitWipe(struct VsMultiList *work);
int VS_MULTI_LIST_StateWaitFrames(struct VsMultiList *work);
int VS_MULTI_LIST_StateSlideIn(struct VsMultiList *work);
int VS_MULTI_LIST_StartWipeIn(struct VsMultiList *work, int nextState);
int VS_MULTI_LIST_StartWipeOut(struct VsMultiList *work, int nextState);
int VS_MULTI_LIST_EnterWaitState(struct VsMultiList *work, int count, int result);
void VS_MULTI_LIST_SetVramBanks(void);
void VS_MULTI_LIST_InitBgs(void);
void VS_MULTI_LIST_ExitBgs(void);
void VS_MULTI_LIST_LoadBgGraphics(struct VsMultiList *work);
void VS_MULTI_LIST_CreateTextResources(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteTextResources(struct VsMultiList *work);
void VS_MULTI_LIST_AddVBlankTask(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteVBlankTask(struct VsMultiList *work);
void VS_MULTI_LIST_VBlankCallback(struct TcbTask *tcb, void *work);
void VS_MULTI_LIST_InitMons(struct VsMultiList *work);
void VS_MULTI_LIST_CreateWindows(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteWindows(struct VsMultiList *work);
void VS_MULTI_LIST_UpdatePrintQueue(struct VsMultiList *work);
void VS_MULTI_LIST_PrintName(struct VsMultiList *work, int slot);
void VS_MULTI_LIST_PrintLevel(struct VsMultiList *work, u32 slot);
void VS_MULTI_LIST_PrintHp(struct VsMultiList *work, int slot);
void VS_MULTI_LIST_DrawHpDivider(struct VsMultiList *work, unsigned slot);
void VS_MULTI_LIST_InitIcons(struct VsMultiList *work);
void VS_MULTI_LIST_ExitIcons(struct VsMultiList *work);
void VS_MULTI_LIST_InitClact(void);
void VS_MULTI_LIST_ExitClact(void);
void VS_MULTI_LIST_LoadIconResources(struct VsMultiList *work);
void VS_MULTI_LIST_ReleaseIconResources(struct VsMultiList *work);
void VS_MULTI_LIST_CreateActors(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteActors(struct VsMultiList *work);
void VS_MULTI_LIST_MoveActorX(struct VsMultiList *work, unsigned actor, int dx);
void VS_MULTI_LIST_MoveSlotActors(struct VsMultiList *work, unsigned firstSlot, int dx);
void VS_MULTI_LIST_CreateBgFrames(struct VsMultiList *work);
void VS_MULTI_LIST_DeleteBgFrames(struct VsMultiList *work);

extern const struct DispVram gVsMultiListDispVram;
extern const struct DispConfig gVsMultiListDispConfig;
extern const struct BgTemplate gVsMultiListBg0Template;
extern const struct BgTemplate gVsMultiListBg1Template;
extern const struct BgTemplate gVsMultiListBg2Template;
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern const struct ClactSysInit gVsMultiListClactInit;
extern const struct VsMultiActorDesc gVsMultiListActorDescs[];
extern const char gVsMultiListSrcName[];
extern int (*gVsMultiListStateTable[])(struct VsMultiList *);

int VS_MULTI_LIST_ProcInit(struct Proc *proc, int seq, struct VsMultiListArgs *args)
{
    struct VsMultiList *work;
    GFL_HEAP_CreateChildHeap(1, 0x71, 0x18000);
    work = PROCSYS_AllocProcWork(proc, 0x120, 0x71);
    MI_CpuFill8(work, 0, 0x120);
    work->args = args;
    return 1;
}

int VS_MULTI_LIST_ProcMain(struct Proc *proc, int *seq, int unused, struct VsMultiList *work)
{
    *seq = gVsMultiListStateTable[*seq](work);
    if (*seq == VS_MULTI_LIST_STATE_END) return 1;
    BGWINFRM_UpdateMoves((struct BgWinFrmWork *)work->bgFrames);
    VS_MULTI_LIST_UpdatePrintQueue(work);
    CLACT_DrawSystem();
    return 0;
}

int VS_MULTI_LIST_ProcExit(struct Proc *proc) { PROCSYS_FreeProcWork(proc); GFL_HEAP_DeleteChecked(0x71); return 1; }

/* State 0: builds the screen and starts the wipe in. */
int VS_MULTI_LIST_StateSetup(struct VsMultiList *work)
{
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    REG_BLDCNT = 0;
    REG_DB_BLDCNT = 0;
    BG_SYS_SetLcdSwap(1);
    VS_MULTI_LIST_InitMons(work);
    VS_MULTI_LIST_SetVramBanks();
    VS_MULTI_LIST_InitBgs();
    VS_MULTI_LIST_LoadBgGraphics(work);
    VS_MULTI_LIST_CreateTextResources(work);
    VS_MULTI_LIST_CreateWindows(work);
    VS_MULTI_LIST_InitIcons(work);
    VS_MULTI_LIST_CreateBgFrames(work);
    GFL_NET_RefreshWmIconAtTopRight(1, 0x71);
    BG_SYS_SetMainPlaneVisible(0x17, 1);
    VS_MULTI_LIST_AddVBlankTask(work);
    return VS_MULTI_LIST_StartWipeIn(work, VS_MULTI_LIST_EnterWaitState(work, 0x80, VS_MULTI_LIST_STATE_SLIDE));
}

/* State 1: tears the screen down. */
int VS_MULTI_LIST_StateTeardown(struct VsMultiList *work)
{
    VS_MULTI_LIST_DeleteVBlankTask(work);
    BG_SYS_SetMainPlaneVisible(0x17, 0);
    VS_MULTI_LIST_DeleteBgFrames(work);
    VS_MULTI_LIST_ExitIcons(work);
    VS_MULTI_LIST_DeleteWindows(work);
    VS_MULTI_LIST_DeleteTextResources(work);
    VS_MULTI_LIST_ExitBgs();
    return VS_MULTI_LIST_STATE_END;
}

/* State 2: waits for the wipe. */
int VS_MULTI_LIST_StateWaitWipe(struct VsMultiList *work)
{
    if (WIPE_SYS_EndCheck()== 1) return work->stateAfterWipe;
    return VS_MULTI_LIST_STATE_WAIT_WIPE;
}

/* State 3: waits the frame count. */
int VS_MULTI_LIST_StateWaitFrames(struct VsMultiList *work)
{
    if (work->waitFrames == 0) return work->stateAfterWait;
    (work->waitFrames)--;
    return VS_MULTI_LIST_STATE_WAIT_FRAMES;
}

/*
 * State 4: waits for the text to be drawn, then slides the two team columns in.
 * lever: byte-pointer object base keeps field addresses inline instead
 * of the integer-base spelling's extra loop-invariant address register.
 */
int VS_MULTI_LIST_StateSlideIn(struct VsMultiList *work)
{
    u32 i;
    switch (work->slidePhase) {
    case 0:
        if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printQue) == 0) break;
        if (work->args->swapSides == 0) {
            for (i = 0; i < 3; i++) {
                BGWINFRM_StartMove((struct BgWinFrmWork *)work->bgFrames, i + 3, -1, 0, 16);
                BGWINFRM_StartMove((struct BgWinFrmWork *)work->bgFrames, i + 9, -1, 0, 16);
            }
        } else {
            for (i = 0; i < 3; i++) {
                BGWINFRM_StartMove((struct BgWinFrmWork *)work->bgFrames, i, 1, 0, 16);
                BGWINFRM_StartMove((struct BgWinFrmWork *)work->bgFrames, i + 6, 1, 0, 16);
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x642);
        (work->slidePhase)++;
    case 1:
        if (work->args->swapSides == 0) {
            if (BGWINFRM_IsMoving((struct BgWinFrmWork *)work->bgFrames, 3) == 0) {
                (work->slidePhase)++;
                GFL_USE_PlaySeDefaultVolume(0x57a);
                return VS_MULTI_LIST_EnterWaitState(work, 0x80, 4);
            }
            VS_MULTI_LIST_MoveSlotActors(work, 3, -8);
        } else {
            if (BGWINFRM_IsMoving((struct BgWinFrmWork *)work->bgFrames, 0) == 0) {
                (work->slidePhase)++;
                GFL_USE_PlaySeDefaultVolume(0x57a);
                return VS_MULTI_LIST_EnterWaitState(work, 0x80, 4);
            }
            VS_MULTI_LIST_MoveSlotActors(work, 0, 8);
        }
        break;
    case 2:
        return VS_MULTI_LIST_StartWipeOut(work, 1);
    }
    return VS_MULTI_LIST_STATE_SLIDE;
}

/* Starts the wipe in; nextState runs when it ends. */
int VS_MULTI_LIST_StartWipeIn(struct VsMultiList *work, int nextState)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x71);
    work->stateAfterWipe = nextState;
    return VS_MULTI_LIST_STATE_WAIT_WIPE;
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
int VS_MULTI_LIST_StartWipeOut(struct VsMultiList *work, int nextState)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x71);
    work->stateAfterWipe = nextState;
    return VS_MULTI_LIST_STATE_WAIT_WIPE;
}

/* Enters the wait state: count frames, then result. */
int VS_MULTI_LIST_EnterWaitState(struct VsMultiList *work, int count, int result)
{
    work->waitFrames = count;
    work->stateAfterWait = result;
    return VS_MULTI_LIST_STATE_WAIT_FRAMES;
}

void VS_MULTI_LIST_SetVramBanks(void)
{
    BG_SYS_SetVramBanks(&gVsMultiListDispVram);
}

void VS_MULTI_LIST_InitBgs(void)
{
    struct DispConfig dispConfig;
    struct BgTemplate bg0;
    struct BgTemplate bg1;
    struct BgTemplate bg2;
    BG_SYS_Create(0x71);
    dispConfig = gVsMultiListDispConfig;
    BG_SYS_SetGraphicsMode(&dispConfig);
    bg0 = gVsMultiListBg0Template;
    BG_SYS_InitBgLayer(0, &bg0, 0);
    BG_SYS_ClearSlot(0);
    BG_SYS_InitRun(0, 0x20, 0, 0x71);
    bg1 = gVsMultiListBg1Template;
    BG_SYS_InitBgLayer(1, &bg1, 0);
    bg2 = gVsMultiListBg2Template;
    BG_SYS_InitBgLayer(2, &bg2, 0);
}

void VS_MULTI_LIST_ExitBgs(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}

void VS_MULTI_LIST_LoadBgGraphics(struct VsMultiList *work)
{
    struct ArcHandle *handle;
    handle = ARC_TOOL_CreateHandle(0x64, 0x8071);
    ARC_UTIL_UploadBgCharFromHandle(handle, 0x12, 2, 0, 0, 1, 0x8071);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 0, 2, 0, 0, 1, 0x8071);
    ARC_UTIL_UploadPaletteFromHandleWhole(handle, 0x13, 0, 0, 0, 0x8071);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 0x10, 1, 0, 0x800, 1, 0x8071);
    ARC_TOOL_DeleteHandle(handle);
    BG_SYS_LoadPlttEntry(4, 0);
}

void VS_MULTI_LIST_CreateTextResources(struct VsMultiList *work)
{
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x12, 0x71);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x71);
    work->fontSmall = GF_FONT_Create(0x17, 3, 0, 0, 0x71);
    work->wordSet = WORDSET_CreateDefault(0x71);
    work->printQue = (struct PrintSys *)PRINTSYS_QUE_CreateEx(0x800, 0x71);
}

void VS_MULTI_LIST_DeleteTextResources(struct VsMultiList *work)
{
    MSGDATA_Delete(work->msgBank);
    GF_FONT_Delete(work->font);
    GF_FONT_Delete(work->fontSmall);
    WORDSET_Delete(work->wordSet);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printQue);
}

void VS_MULTI_LIST_AddVBlankTask(struct VsMultiList *work)
{
    work->vblankTask = (struct VBlankTask *)GFL_USE_AddMainTask(VS_MULTI_LIST_VBlankCallback, work, 0);
}

void VS_MULTI_LIST_DeleteVBlankTask(struct VsMultiList *work)
{
    TCB_DeleteTask((struct TcbTask *)work->vblankTask);
}

static inline void OS_SetIrqCheckFlag(u32 intr) { *(volatile u32 *)((uptr)SDK_AUTOLOAD_DTCM_START + 0x3ff8) |= intr; }

/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 021F6A18/021F6A1C, HW_INTR_CHECK_BUF.
 */
void VS_MULTI_LIST_VBlankCallback(struct TcbTask *tcb, void *work)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    OS_SetIrqCheckFlag(1);
}

/* Fills the six mon slots: the first party goes to slots 0 to 2, the second to 3 to 5 (swapped when swapSides is set). */
void VS_MULTI_LIST_InitMons(struct VsMultiList *work)
{
    struct VsMultiListArgs *args;
    struct PokeParty *firstParty;
    struct PokeParty *secondParty;
    unsigned i;

    args = work->args;
    if (args->swapSides == 0) {
        firstParty = args->party0;
        secondParty = args->party1;
    } else {
        firstParty = args->party1;
        secondParty = args->party0;
    }
    for (i = 0; i < 3; i++) {
        if (POKEPARTY_GetCount((struct Party *)firstParty) > i)
            work->mons[i] = POKEPARTY_GetMember((struct Party *)firstParty, i);
        else
            work->mons[i] = 0;
        if (POKEPARTY_GetCount((struct Party *)secondParty) > i)
            work->mons[3 + i] = POKEPARTY_GetMember((struct Party *)secondParty, i);
        else
            work->mons[3 + i] = 0;
    }
}

/* Creates the six text windows and prints name, level and HP into the used ones. */
void VS_MULTI_LIST_CreateWindows(struct VsMultiList *work)
{
    unsigned int i;

    BMP_WIN_Init(0x71);
    for (i = 0; i < 6; i++)
        work->windows[i].bmpWin = BMP_WIN_Create(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        BMP_Clear(BMP_WIN_GetBmp(work->windows[i].bmpWin), 0);
        if (work->mons[i] != 0) {
            VS_MULTI_LIST_PrintName(work, i);
            VS_MULTI_LIST_PrintLevel(work, i);
            VS_MULTI_LIST_PrintHp(work, i);
            VS_MULTI_LIST_DrawHpDivider(work, i);
        } else {
            BMP_WIN_TransferChars(work->windows[i].bmpWin);
        }
    }
}

void VS_MULTI_LIST_DeleteWindows(struct VsMultiList *work) { u32 i; for(i=0; i<6; i++) { BMP_WIN_Delete(work->windows[i].bmpWin); } BMP_WIN_Exit(); }

/* Runs the print queue and transfers each window once its text is drawn. */
void VS_MULTI_LIST_UpdatePrintQueue(struct VsMultiList *work)
{
    unsigned i;
    struct PrintSys *printQue;

    PRINTSYS_QUE_Main((struct PrintQueue *)work->printQue);
    for (i = 0; i < 6; i++) {
        printQue = work->printQue;
        if (work->windows[i].dirty != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printQue, BMP_WIN_GetBmp(work->windows[i].bmpWin)) == 0) {
                BMP_WIN_TransferChars(work->windows[i].bmpWin);
                work->windows[i].dirty = 0;
            }
        }
    }
}

static inline void PrintLeft(struct VsMultiList *work, int slot, struct Strbuf *str, int x, int y, u16 color)
{
    struct PrintSys *printQue = work->printQue;
    PRINTSYS_PrintQueColor((struct PrintQueue *)printQue, BMP_WIN_GetBmp(work->windows[slot].bmpWin), x, y, str, work->font, color);
    work->windows[slot].dirty = 1;
}

static inline void PrintRight(struct VsMultiList *work, int slot, struct BmpWin *window, u32 msgId, u16 color)
{
    struct Strbuf *str = MSGDATA_AllocString(work->msgBank, msgId);
    struct GfFont *font = work->font;
    u32 width = BMP_WIN_GetWidth(window);
    short x = (short)(width * 8 - PRINTSYS_MeasureWidestLine(str, work->font, 0));
    struct PrintSys *printQue = work->printQue;
    PRINTSYS_PrintQueColor((struct PrintQueue *)printQue, BMP_WIN_GetBmp(work->windows[slot].bmpWin), x, 7, str, font, color);
    work->windows[slot].dirty = 1;
    STRBUF_Delete(str);
}

/*
 * Prints the nickname and, when the mon has a gender to show, the gender sign at the right edge.
 * lever: Named monster base/index and byte gender if/else retain the original scheduling; inline print helpers retain owner spills.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`windows = p;` before `windows = p + 0x20;`; `dirty = p;` before `dirty =
 * p + 0x24;`). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void VS_MULTI_LIST_PrintName(struct VsMultiList *work, int slot)
{
    struct VsMultiListWindow *windows;
    struct PokemonParam **mons;
    u32 monOffset;
    u8 gender;
    struct BmpWin *window;
    struct Strbuf *name, *format;
    windows = work->windows;
    window = windows[slot].bmpWin;
    name = STRBUF_Create(0xc, 0x8071);
    format = MSGDATA_AllocString(work->msgBank, 0);
    mons = work->mons;
    monOffset = slot;
    WORDSET_SetSlotMonNickname(work->wordSet, 0, mons[monOffset]);
    WORDSET_CopyTaggedText(work->wordSet, name, format);
    PrintLeft(work, slot, name, 0x20, 7, 0x3dc0);
    STRBUF_Delete(format);
    STRBUF_Delete(name);
    if (POKE_TOOL_GetPartyValue(mons[monOffset], POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN, 0) == 1 &&
        POKE_TOOL_GetPartyValue(mons[monOffset], POKE_TOOL_PARAM_IS_EGG, 0) == 0) {
        gender = POKE_TOOL_GetGender(mons[monOffset]);
        if (gender == 0) PrintRight(work, slot, window, 0x16, 0x2960);
        else if (gender == 1) PrintRight(work, slot, window, 0x17, 0x31a0);
    }
}

static inline void PrintLevel(struct VsMultiList *work, u32 slot, struct Strbuf *str)
{
    struct PrintSys *printQue = work->printQue;
    PRINTSYS_PrintQueColor((struct PrintQueue *)printQue,
                  BMP_WIN_GetBmp(work->windows[slot].bmpWin), 8, 0x20, str,
                  work->fontSmall, 0x3dc0);
    work->windows[slot].dirty = 1;
}

/*
 * Prints the level label.
 * lever: six window records initialized by matched 021F6A98; direct per-field windows[slot] accesses retain index scaling and recompute the dirty-byte address.
 * checks: 1 every callee copied from its own matched definition; 2 021F6A98 initializes six 8-byte records and gives the fixed bound; 3 enum zero gave84, readonly header38; 4 struct-array-per-field idiom closes38 to EXACT; 5 fresh idiom directory and matched neighbours read.
 * permuter: historical once-only types300 consumed; no repeat in wave77.
 */
void VS_MULTI_LIST_PrintLevel(struct VsMultiList *work, u32 slot)
{
    struct Strbuf *text;
    struct Strbuf *format;
    unsigned char dispType = NUMBER_DISP_LEFT;

    text = STRBUF_Create(0x20, 0x8071);
    format = MSGDATA_AllocString(work->msgBank, 0xb);
    WORDSET_SetSlotNumber(work->wordSet, 0,
                  POKE_TOOL_GetPartyValue(work->mons[slot], POKE_TOOL_PARAM_LEVEL, 0), 3, dispType, 1);
    WORDSET_CopyTaggedText(work->wordSet, text, format);
    PrintLevel(work, slot, text);
    STRBUF_Delete(format);
    STRBUF_Delete(text);
}

static inline u8 CenterX(u32 width)
{
    return 0x5c - (width >> 1);
}

/*
 * Prints "HP", then the current and the maximum HP.
 * lever: 2026-10-05 (wD9r lane136): width is a narrow local (u8). mwcc does not schedule the reload of a
 *   spilled narrow local above the outgoing stack stores, so the block-3 x sum comes after them as in the
 *   image; a u32 width reload is hoisted (25 bytes in waves D3 to D9r). The centre shift is unsigned
 *   (lsrs), so the u8 width is widened to u32 before the shift; a plain u8 `width >> 1` gives asrs. An inline
 *   helper `CenterX(u32 width)` gives the same EXACT bytes. Diagnostic that found it: the block-2 s16 local x
 *   used as the block-3 operand gave the image order, a u32/int x did not.
 */
void VS_MULTI_LIST_PrintHp(struct VsMultiList *work, int slot)
{
    struct Strbuf *buf;
    struct Strbuf *hpLabel;
    struct Strbuf *hpFormat;
    struct Strbuf *maxHpFormat;
    u8 labelWidth;
    u8 labelX;
    uptr printQue1;
    uptr printQue2;
    short x;
    uptr printQue3;
    uptr font;

    buf = STRBUF_Create(0x20, 0x8071);
    hpLabel = MSGDATA_AllocString(work->msgBank, 0xc);
    labelWidth = PRINTSYS_MeasureWidestLine(hpLabel, work->fontSmall, 0);
    labelX = CenterX(labelWidth);
    {
        uptr bmp;
        printQue1 = (uptr)work->printQue;
        bmp = (uptr)BMP_WIN_GetBmp(work->windows[slot].bmpWin);
        PRINTSYS_PrintQueColor((struct PrintQueue *)printQue1, (struct Bmp *)bmp, (short)labelX, 0x20, hpLabel, work->fontSmall, 0x3dc0);
    }
    work->windows[slot].dirty = 1;
    STRBUF_Delete(hpLabel);

    hpFormat = MSGDATA_AllocString(work->msgBank, 0xd);
    WORDSET_SetSlotNumber(work->wordSet, 0, POKE_TOOL_GetPartyValue(work->mons[slot], POKE_TOOL_PARAM_HP, 0), 3, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, buf, hpFormat);
    {
        uptr bmp;
        font = (uptr)work->fontSmall;
        x = labelX - PRINTSYS_MeasureWidestLine(buf, (struct GfFont *)font, 0);
        printQue2 = (uptr)work->printQue;
        bmp = (uptr)BMP_WIN_GetBmp(work->windows[slot].bmpWin);
        PRINTSYS_PrintQueColor((struct PrintQueue *)printQue2, (struct Bmp *)bmp, x, 0x20, buf, (struct GfFont *)font, 0x3dc0);
    }
    work->windows[slot].dirty = 1;
    STRBUF_Delete(hpFormat);

    maxHpFormat = MSGDATA_AllocString(work->msgBank, 0xd);
    WORDSET_SetSlotNumber(work->wordSet, 0, POKE_TOOL_GetPartyValue(work->mons[slot], POKE_TOOL_PARAM_MAX_HP, 0), 3, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, buf, maxHpFormat);
    {
        uptr bmp;
        printQue3 = (uptr)work->printQue;
        bmp = (uptr)BMP_WIN_GetBmp(work->windows[slot].bmpWin);
        PRINTSYS_PrintQueColor((struct PrintQueue *)printQue3, (struct Bmp *)bmp, (short)(labelX + labelWidth), 0x20, buf, work->fontSmall, 0x3dc0);
    }
    work->windows[slot].dirty = 1;
    STRBUF_Delete(maxHpFormat);
    STRBUF_Delete(buf);
}

/* Draws the two-pixel divider line between the HP numbers. */
void VS_MULTI_LIST_DrawHpDivider(struct VsMultiList *work, unsigned slot)
{
    struct VsMultiListWindow *windows = work->windows;
    BMP_FillRect(BMP_WIN_GetBmp(windows[slot].bmpWin), 0x40, 0x1b, 0x30, 1, 1);
    BMP_FillRect(BMP_WIN_GetBmp(windows[slot].bmpWin), 0x40, 0x1c, 0x30, 1, 2);
}

void VS_MULTI_LIST_InitIcons(struct VsMultiList *work)
{
    VS_MULTI_LIST_InitClact();
    VS_MULTI_LIST_LoadIconResources(work);
    VS_MULTI_LIST_CreateActors(work);
}

void VS_MULTI_LIST_ExitIcons(struct VsMultiList *work)
{
    VS_MULTI_LIST_DeleteActors(work);
    VS_MULTI_LIST_ReleaseIconResources(work);
    VS_MULTI_LIST_ExitClact();
}

void VS_MULTI_LIST_InitClact(void)
{
    struct ClactSysInit init = gVsMultiListClactInit;
    CLACT_InitSystem(&init, (const struct DispVramCfg *)&gVsMultiListDispVram, 0x71);
}

void VS_MULTI_LIST_ExitClact(void)
{
    CLACT_ExitSystem();
}

/* Mon slot i of a work given as an integer base (the integer-base spelling is what the compiled code needs). */
#ifdef __MWERKS__
#define MON_AT(base, i) (*(struct PokemonParam **)((base) + (i) * 4 + 0xf8))
#else
#define MON_AT(base, i) (((struct VsMultiList *)(base))->mons[i])
#endif

static inline u32 CharIdsAddress(sptr base)
{
    return (uptr)&((struct VsMultiList *)base)->charIds[0];
}

/*
 * Registers the icon, ball and marker graphics.
 * lever: the icon array address comes from a static
 * inline accessor of the char id array (the inlined parameter and the result share
 * one spill slot: str p; adds #0xb4; str); merged icon is u16.
 * note 2026-10-05: replaced the stand-in `icons = p; icons = p + 0xb4;`
 * with the accessor. EXACT in --lang c99 and --lang c. An
 * accessor returning u32 * with icons[i] stores gives DIFF; one that copies
 * into a local and adds (r = obj; r += 0xb4) gives DIFF.
 */
void VS_MULTI_LIST_LoadIconResources(struct VsMultiList *work)
{
    sptr base = (sptr)work;
    u32 cellArc, cellAnim;
    struct ArcHandle *iconArc;
    struct ArcHandle *uiArc;
    u16 i, icon;
    uptr charIds;
    iconArc = ARC_TOOL_CreateHandle(7, 0x8071);
    charIds = CharIdsAddress(base);
    for (i = 0; i < 6; i++) {
        if (MON_AT(base, i) != 0)
            icon = POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(MON_AT(base, i)));
        else
            icon = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
        *(int *)(charIds + i * 4) = CLACT_RegisterCharacter(iconArc, icon, 0, 0, 0x71);
    }
    work->paletteIds[0] = CLACT_RegisterPaletteCompressed(iconArc, POKE_TOOL_GetIconPaletteArcId(), 0, 0, 0x71);
    cellArc = POKE_TOOL_GetIconCellArcIdSub();
    cellAnim = POKE_TOOL_GetIconCellEntryIdSub();
    work->cellAnimIds[0] = CLACT_RegisterCellAnim(iconArc, cellArc, cellAnim, 0x71);
    ARC_TOOL_DeleteHandle(iconArc);
    uiArc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x8071);
    work->charIds[7] = CLACT_RegisterCharacter(uiArc, 0xc, 0, 0, 0x71);
    work->paletteIds[2] = CLACT_RegisterPalette(uiArc, 0xb, 0, 0x60, 0x71);
    work->cellAnimIds[2] = CLACT_RegisterCellAnim(uiArc, 0xf, 0x12, 0x71);
    work->charIds[6] = CLACT_RegisterCharacter(uiArc, 0x41, 0, 0, 0x71);
    work->paletteIds[1] = CLACT_RegisterPalette(uiArc, 0x42, 0, 0x80, 0x71);
    work->cellAnimIds[1] = CLACT_RegisterCellAnim(uiArc, 0x45, 0x48, 0x71);
    work->charIds[8] = CLACT_RegisterCharacter(uiArc, APP_ICON_GetGearCellFileId(2), 0, 0, 0x71);
    work->paletteIds[3] = CLACT_RegisterPalette(uiArc, APP_ICON_GetNoneFileId(), 0, 0xa0, 0x71);
    cellArc = APP_ICON_GetGearPaletteFileId(2);
    cellAnim = APP_ICON_GetGearAnimFileId(2);
    work->cellAnimIds[3] = CLACT_RegisterCellAnim(uiArc, cellArc, cellAnim, 0x71);
    ARC_TOOL_DeleteHandle(uiArc);
}

void VS_MULTI_LIST_ReleaseIconResources(struct VsMultiList *work)
{
    unsigned i;

    for (i = 0; i < 9; i++)
        CLACT_ReleaseCharacter(work->charIds[i]);
    for (i = 0; i < 4; i++)
        CLACT_ReleasePalette(work->paletteIds[i]);
    for (i = 0; i < 4; i++)
        CLACT_ReleaseCellAnim(work->cellAnimIds[i]);
}

/*
 * Creates the 24 actors, hides the unused ones and moves each team off screen.
 * prototype: 0204B294 result stored at 021F719C despite owner void; 020185F4 preserves and returns live r0; 0204B8C4 visible r1=0 retained.
 */
void VS_MULTI_LIST_CreateActors(struct VsMultiList *work)
{
    u32 i;
    u16 heldItem;
    work->clactUnit = CLACT_CreateUnit(24, 0, 0x71);
    for (i = 0; i < 24; i++) {
        work->actors.all[i] = CLACT_CreateActor(work->clactUnit,
            work->charIds[gVsMultiListActorDescs[i].charIndex],
            work->paletteIds[gVsMultiListActorDescs[i].paletteIndex],
            work->cellAnimIds[gVsMultiListActorDescs[i].cellAnimIndex], (const struct ActorInitParam *)&gVsMultiListActorDescs[i], 0, 0x71);
    }
    for (i = 0; i < 6; i++) {
        if (work->mons[i] == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors.set.icon[i], 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors.set.heldItem[i], 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors.set.markerD[i], 0);
        } else {
            CLACT_SetActorAutoAnim((struct ClactActor *)work->actors.set.icon[i], 1);
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors.set.icon[i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(work->mons[i])), 1);
            heldItem = POKE_TOOL_GetPartyValue(work->mons[i], POKE_TOOL_PARAM_HELD_ITEM, 0);
            if (heldItem == 0) CLACT_SetActorDrawEnable((struct ClactActor *)work->actors.set.heldItem[i], 0);
            else if (FILE_UTIL_IsMailItem(heldItem) == 1) {
                CLACT_SetActorAnimFrame((struct ClactActor *)work->actors.set.heldItem[i], 0);
                CLACT_SetActorAnimSeq((struct ClactActor *)work->actors.set.heldItem[i], 1);
            } else {
                CLACT_SetActorAnimFrame((struct ClactActor *)work->actors.set.heldItem[i], 0);
                CLACT_SetActorAnimSeq((struct ClactActor *)work->actors.set.heldItem[i], 0);
            }
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors.set.markerC[i], 0);
    }
    if (work->args->swapSides == 0) {
        for (i = 0; i < 3; i++) {
            VS_MULTI_LIST_MoveActorX(work, i + 3, 128);
            VS_MULTI_LIST_MoveActorX(work, i + 9, 128);
            VS_MULTI_LIST_MoveActorX(work, i + 15, 128);
            VS_MULTI_LIST_MoveActorX(work, i + 21, 128);
        }
    } else {
        for (i = 0; i < 3; i++) {
            VS_MULTI_LIST_MoveActorX(work, i, -128);
            VS_MULTI_LIST_MoveActorX(work, i + 6, -128);
            VS_MULTI_LIST_MoveActorX(work, i + 12, -128);
            VS_MULTI_LIST_MoveActorX(work, i + 18, -128);
        }
    }
}

void VS_MULTI_LIST_DeleteActors(struct VsMultiList *work)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        CLACT_DeleteActor((struct ClactActor *)work->actors.all[i]);
    CLACT_DeleteUnit(work->clactUnit);
}

/* Moves one actor horizontally by dx. */
void VS_MULTI_LIST_MoveActorX(struct VsMultiList *work, unsigned actor, int dx)
{
    struct ClactVec2 pos;
    struct ClactActor **actors = work->actors.all;
    CLACT_GetActorSurfacePos(actors[actor], &pos, 0);
    pos.x = pos.x + dx;
    CLACT_AddActorSurfacePos(actors[actor], &pos, 0);
}

/* Moves the actors of the three slots from firstSlot on, in all four sets. */
void VS_MULTI_LIST_MoveSlotActors(struct VsMultiList *work, unsigned firstSlot, int dx)
{
    unsigned i;

    for (i = firstSlot; i < firstSlot + 3; i++) {
        VS_MULTI_LIST_MoveActorX(work, i, dx);
        VS_MULTI_LIST_MoveActorX(work, i + 6, dx);
        VS_MULTI_LIST_MoveActorX(work, i + 12, dx);
        VS_MULTI_LIST_MoveActorX(work, i + 18, dx);
    }
}

/* Creates the background frames that carry the six plates and places them. */
void VS_MULTI_LIST_CreateBgFrames(struct VsMultiList *work)
{
    u16 i;
    u8 *palette, *buf;
    work->bgFrames = (struct WinMgr *)BGWINFRM_Create(2, 12, 0x71);
    for (i = 0; i < 6; i++) {
        BGWINFRM_AddFrame((struct BgWinFrmWork *)work->bgFrames, i, 1, 16, 6);
        BGWINFRM_AddFrame((struct BgWinFrmWork *)work->bgFrames, i + 6, 0, 16, 6);
        BGWINFRM_PutBmpWin((struct BgWinFrmWork *)work->bgFrames, i + 6, work->windows[i].bmpWin);
    }
    palette = (u8 *)BG_SYS_GetBuf(1);
    buf = GFL_HEAP_Alloc(0x8071, 0xc0, 0, gVsMultiListSrcName, 0x606);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + i * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (work->mons[i]) BGWINFRM_SetFrameData((struct BgWinFrmWork *)work->bgFrames, i, buf);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + (i + 18) * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (!work->mons[i]) BGWINFRM_SetFrameData((struct BgWinFrmWork *)work->bgFrames, i, buf);
    GFL_HEAP_Free(buf);
    BG_SYS_ClearSlot(1);
    if (work->args->swapSides == 0) {
        for (i = 3; i < 6; i++) if (work->mons[i]) BGWINFRM_ChangePalette((struct BgWinFrmWork *)work->bgFrames, i, 0, 0, 16, 6, 5);
    } else {
        for (i = 0; i < 3; i++) if (work->mons[i]) BGWINFRM_ChangePalette((struct BgWinFrmWork *)work->bgFrames, i, 0, 0, 16, 6, 5);
    }
    if (work->args->swapSides == 0) {
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 0, 0, 0);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 1, 0, 6);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 2, 0, 12);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 6, 0, 0);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 7, 0, 6);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 8, 0, 12);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 3, 32, 1);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 4, 32, 7);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 5, 32, 13);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 9, 32, 1);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 10, 32, 7);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 11, 32, 13);
    } else {
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 0, -16, 0);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 1, -16, 6);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 2, -16, 12);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 6, -16, 0);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 7, -16, 6);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 8, -16, 12);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 3, 16, 1);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 4, 16, 7);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 5, 16, 13);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 9, 16, 1);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 10, 16, 7);
        BGWINFRM_PutFrame((struct BgWinFrmWork *)work->bgFrames, 11, 16, 13);
    }
}

void VS_MULTI_LIST_DeleteBgFrames(struct VsMultiList *work)
{
    BGWINFRM_Delete((struct BgWinFrmWork *)work->bgFrames);
}
