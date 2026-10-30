/*
 * file:     cg_help.c
 * unit:     yes
 * function: CG_HELP_Setup, CG_HELP_Teardown, CG_HELP_Main, CG_HELP_VBlank, CG_HELP_InitDisplay, CG_HELP_ExitDisplay, CG_HELP_SetupBgLayer, CG_HELP_LoadActorResources, CG_HELP_FreeActorResources, CG_HELP_InitWindows, CG_HELP_FreeWindows, CG_HELP_HandleTouchInput, CG_HELP_DrawPageText, CG_HELP_UpdatePageGraphics, CG_HELP_ProcInit, CG_HELP_ProcExit, CG_HELP_ProcMain
 * address:  0x021D4240
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 * symbols:
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   KEY_GetTrg 0x020362DC arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   gCgHelpVramBanks 0x021D4CC4 data a4
 *   gCgHelpDispConfig 0x021D4BF4 data a4
 *   gCgHelpBgTemplateLayer4 0x021D4C44 data a4
 *   gCgHelpBgTemplateLayer5 0x021D4C64 data a4
 *   gCgHelpBgTemplateLayer6 0x021D4C84 data a4
 *   gCgHelpBgTemplateLayer7 0x021D4C24 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   gCgHelpTouchRects 0x021D4BE4 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   gCgHelpPageAnimSeq 0x021D4CF4 data a4
 *   gCgHelpPageCharOffset 0x021D4CA4 data a4
 *   gCgHelpFileName 0x021D4D4C data a1
 *   gCgHelpPageTileBase 0x021D4C04 data a4
 *   gCgHelpActorOffset 0x021D4BE0 data a2
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   KEY_GetCont 0x0203630C arm
 *   MYSTATUS_SetSex 0x0200854C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb  arm9
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   APP_TASKMENU_WIN_TransChar  0x02028454  thumb  arm9
 *   MYSTATUS_Create  0x0200846C  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb  arm9
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb  arm9
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   MYSTATUS_GetSex  0x02008550  thumb  arm9
 */

struct Node;
struct Descriptor;
struct ClactActor;
struct PrintSys;
struct Cfg;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Bank;
struct Sub0200852CObj;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct Rec;
struct TaskMenuState;
struct Ctx;
struct Vec2;
struct Proc;
struct Proc;
#include "../types.h"
#include "../sdk_ioreg.h"

typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } CgHelpClactConfig;

typedef struct { u16 x, y, z; u8 a, b; } CgHelpActorHeader;

typedef struct { void *text; u16 color; u16 pad; u32 flag; } CgHelpMenuItem;

typedef struct { u8 bytes[16]; } CgHelpTouchRects;

typedef struct { s16 x, y; } CgHelpVec;

typedef struct CgHelpArgs {
    void *myStatus;
    const struct Ctx *inputCtx;
} CgHelpArgs;

typedef struct CgHelpCharData {
    u8 pad0[12];
    u8 *rawData;
} CgHelpCharData;

enum {
    CG_HELP_PHASE_FADE_IN_START = 0,
    CG_HELP_PHASE_FADE_IN_WAIT = 1,
    CG_HELP_PHASE_CLOSE_BUTTON = 2,
    CG_HELP_PHASE_FADE_OUT_WAIT = 3,
    CG_HELP_PHASE_INTERACTIVE = 4
};

#define CG_HELP_LAST_PAGE 11

typedef struct CgHelpWork {
    u16 heapId;
    u8 pad2[2];
    CgHelpArgs *args;
    int closeRequested;
    unsigned int firstDrawPending;
    unsigned int phase;
    void *vblankTask;
    u8 pageIndex;
    u8 pad19[3];
    unsigned int textDirty;
    void *bodyWin;
    void *titleWin;
    void *font;
    void *msgData;
    void *printQue;
    void *menuRes;
    void *prevButton;
    void *nextButton;
    void *closeButton;
    void *charFile;
    CgHelpCharData *charData;
    void *actorUnit;
    int paletteId;
    unsigned int charId;
    unsigned int cellAnimId;
    void *pageActor;
} CgHelpWork;

#include "../arm9/gfl_use.h"
#include "../arm9/net.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/wipe.h"
struct TaskMenuWin;
#include "../arm9/app_taskmenu.h"
#include "../arm9/key.h"
#ifdef __MWERKS__
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetPlaneVisible
#undef BG_SYS_FreeSlot
void BG_SYS_SetPlaneVisible(u32, unsigned char);
void BG_SYS_FreeSlot(u32);
#endif
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/clact.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u32);
#include "../arm9/g2.h"
struct DispVramCfg;
struct SysInit;
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
struct MyStatus;
#include "../arm9/mystatus.h"
struct ClactActor;
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
#include "../arm9/bmp_menuwork.h"
struct GFont;
struct TaskMenuRes;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
struct Strbuf;
struct TaskMenuItem;
#include "../arm9/strbuf.h"
#include "../arm9/touchpanel.h"
struct GameSystem;
#include "../arm9/gamesystem.h"
#include "../arm9/nns_gfd_vram_transfer.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../version.h"

#if LANGUAGE == LANGUAGE_JAPANESE
#define CG_HELP_MSG_ARCHIVE 22
#else
#define CG_HELP_MSG_ARCHIVE 21
#endif
void CG_HELP_Setup(CgHelpWork *work);
void CG_HELP_Teardown(CgHelpWork *work);
int CG_HELP_Main(CgHelpWork *work);
void CG_HELP_VBlank(struct TcbTask * unused0, void * unused1);
void CG_HELP_InitDisplay(CgHelpWork *work);
void CG_HELP_ExitDisplay(CgHelpWork *work);
void CG_HELP_SetupBgLayer(const struct BgTemplate *bgTemplate, int layer, int type);
void CG_HELP_LoadActorResources(CgHelpWork *work);
void CG_HELP_FreeActorResources(CgHelpWork *work);
void CG_HELP_InitWindows(CgHelpWork *work);
void CG_HELP_FreeWindows(CgHelpWork *work);
void CG_HELP_HandleTouchInput(CgHelpWork *work);
void CG_HELP_DrawPageText(CgHelpWork *work, int page);
void CG_HELP_UpdatePageGraphics(CgHelpWork *work, u32 page);
int CG_HELP_ProcInit(void *a,int b,CgHelpArgs *c);
int CG_HELP_ProcExit(struct Proc *task,int b,int keep,CgHelpWork *work);
extern const CgHelpClactConfig gClActorInitParam;
extern const u32 gCgHelpVramBanks[], gCgHelpDispConfig[], gCgHelpBgTemplateLayer4[], gCgHelpBgTemplateLayer5[], gCgHelpBgTemplateLayer6[], gCgHelpBgTemplateLayer7[];
extern const CgHelpTouchRects gCgHelpTouchRects;
extern const u32 gCgHelpPageAnimSeq[], gCgHelpPageCharOffset[], gCgHelpPageTileBase[];
extern const char gCgHelpFileName[];
extern const CgHelpVec gCgHelpActorOffset;

void CG_HELP_Setup(CgHelpWork *work)
{
    work->phase = 0;
    CG_HELP_InitDisplay(work);
    CG_HELP_LoadActorResources(work);
    CG_HELP_InitWindows(work);
    work->vblankTask = GFL_USE_AddMainTask(CG_HELP_VBlank,(void *)work,8);
    work->pageIndex = 0;
    work->firstDrawPending = 1;
    CG_HELP_DrawPageText(work,work->pageIndex);
    GFL_NET_RefreshWmIconAtTopRight(0,work->heapId);
}

void CG_HELP_Teardown(CgHelpWork *work)
{
    TCB_DeleteTask(work->vblankTask);
    CG_HELP_FreeWindows(work);
    CG_HELP_FreeActorResources(work);
    CG_HELP_ExitDisplay(work);
}

/*
 * extent: existing follower 021D43F0 remains in its separately verified file.
 */
int CG_HELP_Main(CgHelpWork *work)
{
    switch(work->phase) {
    case 0:
        WIPE_SYS_Start((void *)4,1,1,0,6,1,work->heapId);
        work->phase=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) work->phase=4;
        break;
    case 2:
        if(APP_TASKMENU_WIN_IsFinish(work->closeButton)==1) {
            WIPE_SYS_Start((void *)4,0,0,0,6,1,work->heapId);
            work->phase=3;
        }
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        if(!work->textDirty) CG_HELP_HandleTouchInput(work);
        if(KEY_GetTrg()&4) BG_SYS_MarkTileDirty(4);
        break;
    }
    PRINTSYS_QUE_Main(work->printQue);
    CLACT_DrawSystem();
    if(work->nextButton) APP_TASKMENU_WIN_Update(work->nextButton);
    if(work->prevButton) APP_TASKMENU_WIN_Update(work->prevButton);
    APP_TASKMENU_WIN_Update(work->closeButton);
    if(work->textDirty==1 && PRINTSYS_QUE_IsFinished(work->printQue)==1 &&
       (APP_TASKMENU_WIN_IsFinish(work->nextButton)==1 || APP_TASKMENU_WIN_IsFinish(work->prevButton)==1 || work->firstDrawPending==1)) {
        BMP_WIN_TransferChars(work->bodyWin);
        BMP_WIN_TransferChars(work->titleWin);
        work->textDirty=0;
        work->firstDrawPending=0;
        CG_HELP_UpdatePageGraphics(work,work->pageIndex);
        if(work->pageIndex==11) {
            APP_TASKMENU_WIN_ResetDecide(work->nextButton);
            APP_TASKMENU_WIN_ClearScreen(work->nextButton);
        } else {
            APP_TASKMENU_WIN_TransChar(work->nextButton);
            APP_TASKMENU_WIN_ResetDecide(work->nextButton);
        }
        if(work->pageIndex==0) {
            APP_TASKMENU_WIN_ResetDecide(work->prevButton);
            APP_TASKMENU_WIN_ClearScreen(work->prevButton);
        } else {
            APP_TASKMENU_WIN_TransChar(work->prevButton);
            APP_TASKMENU_WIN_ResetDecide(work->prevButton);
        }
    }
    BG_SYS_ChangeScrollImmediate(7,5,1);
    return 0;
}

/*
 * extent: 8-byte tail stub; labelled function 021D43F8 follows.
 */
void CG_HELP_VBlank(struct TcbTask * unused0, void * unused1)
{
    CLACT_VBlankSystem();
}

static inline void visible(int plane)
{
    *(volatile u32 *)REG_DISPCNT_ADDR = (*(volatile u32 *)REG_DISPCNT_ADDR & ~0x1f00) | (plane << 8);
}

static inline void subvisible(int plane)
{
    *(volatile u32 *)REG_DB_DISPCNT_ADDR = (*(volatile u32 *)REG_DB_DISPCNT_ADDR & ~0x1f00) | (plane << 8);
}

/*
 * volatile: display read-modify-writes 021D440E/021D4416, 021D4418/021D441C; POWCNT1 021D443E/021D4444.
 */
void CG_HELP_InitDisplay(CgHelpWork *work)
{
    CgHelpClactConfig cfg;
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    visible(0);
    subvisible(0);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    *(volatile u16 *)REG_POWCNT1_ADDR |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)gCgHelpVramBanks);
    BG_SYS_Create(work->heapId);
    BMP_WIN_Init(work->heapId);
    BG_SYS_SetGraphicsMode((struct DispConfig *)gCgHelpDispConfig);
    CG_HELP_SetupBgLayer((const struct BgTemplate *)gCgHelpBgTemplateLayer4, 4, 0);
    CG_HELP_SetupBgLayer((const struct BgTemplate *)gCgHelpBgTemplateLayer5, 5, 0);
    CG_HELP_SetupBgLayer((const struct BgTemplate *)gCgHelpBgTemplateLayer6, 6, 0);
    CG_HELP_SetupBgLayer((const struct BgTemplate *)gCgHelpBgTemplateLayer7, 7, 0);
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 4, 8, 15, 4);
    cfg = gClActorInitParam;
    cfg.h = 0x40;
    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&cfg)), (const struct DispVramCfg *)gCgHelpVramBanks, work->heapId);
    work->actorUnit = CLACT_CreateUnit(0x30, 0, work->heapId);
    CLACT_SetUnitDefaultRenderer(work->actorUnit);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void CG_HELP_ExitDisplay(CgHelpWork *work)
{
    CLACT_DeleteUnit(work->actorUnit);
    CLACT_ExitSystem();
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

/* 020414AC's legacy asm prototype says void, but its body forwards entry r0. */
void CG_HELP_SetupBgLayer(const struct BgTemplate *bgTemplate, int layer, int type)
{
    BG_SYS_InitBgLayer(layer, bgTemplate, type);
    BG_SYS_SetPlaneVisible(layer, 1);
    BG_SYS_FreeSlot(layer);
    BG_SYS_PushTile(layer);
}

void CG_HELP_LoadActorResources(CgHelpWork *work)
{
    void *archive;
    CgHelpActorHeader req;
    archive = ARC_TOOL_CreateHandle(0x1d, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 1, 4, 0, 0, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 4, 6, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 10, 6, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 4, 7, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 9, 7, 0, 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    archive = ARC_TOOL_CreateHandle(0x1e, work->heapId);
    if (MYSTATUS_GetSex(work->args->myStatus) == 0)
        work->paletteId = CLACT_RegisterPaletteEx(archive, 19, 1, 0, 0, 15, work->heapId);
    else
        work->paletteId = CLACT_RegisterPaletteEx(archive, 12, 1, 0, 0, 15, work->heapId);
    work->charId = CLACT_RegisterCharacter(archive, 22, 0, 1, work->heapId);
    work->cellAnimId = CLACT_RegisterCellAnim(archive, 21, 20, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(archive, 0, 4, 0, 0, 0, work->heapId);
    work->charFile = ARC_UTIL_LoadPaletteBlockFromHandle((void *)archive, (u32)13, (&work->charData), work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    req.x = 32;
    req.y = 48;
    req.z = 0;
    req.a = 0;
    req.b = 0;
    work->pageActor = CLACT_CreateActor((struct Unit *)work->actorUnit, work->paletteId, work->charId, work->cellAnimId, (const struct ActorInitParam *)&req, 1, work->heapId);
    CLACT_SetActorDrawEnable(work->pageActor, 0);
    CLACT_SetActorAutoAnim(work->pageActor, 1);
}

void CG_HELP_FreeActorResources(CgHelpWork *work)
{
    GFL_HEAP_Free(work->charFile);
    CLACT_DeleteActor(work->pageActor);
    CLACT_ReleasePalette(work->paletteId);
    CLACT_ReleaseCharacter(work->charId);
    CLACT_ReleaseCellAnim(work->cellAnimId);
}

void CG_HELP_InitWindows(CgHelpWork *work)
{
    CgHelpMenuItem req;
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heapId);
    GF_FONT_SetTextColor(15, 2, 0);
    work->msgData = MSGDATA_CreateFromArchive(0, 2, CG_HELP_MSG_ARCHIVE, work->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 480, 32, work->heapId);
    BMP_MENUWORK_LoadCharAndPltt(5, 1, 13, 0, work->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(5, BMP_MENUWORK_GetPlttFileId(0), 4, 416, 64, work->heapId);
    GF_FONT_SetDefaultTextColor();
    work->printQue = PRINTSYS_QUE_Create(work->heapId);
    work->menuRes = APP_TASKMENU_RES_Create(4, 11, work->font, work->printQue, work->heapId);
    work->titleWin = BMP_WIN_Create(5, 2, 4, 28, 4, 15, 1);
    work->bodyWin = BMP_WIN_Create(5, 2, 9, 28, 12, 15, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->titleWin), 1);
    BMP_WIN_TransferChars(work->titleWin);
    BMP_WIN_MakeScreen(work->titleWin);
    BMP_MENUWORK_DrawWindow(work->titleWin, 1, 1, 14);
    BMP_Clear(BMP_WIN_GetBmp(work->bodyWin), 0);
    BMP_WIN_TransferChars(work->bodyWin);
    BMP_WIN_MakeScreen(work->bodyWin);
    BG_SYS_PushTile(5);
    BG_SYS_PushTile(4);
    work->textDirty = 0;
    req.text = MSGDATA_AllocString(work->msgData, 24);
    req.color = 0x39e3;
    req.flag = 0;
    work->nextButton = APP_TASKMENU_WIN_Create(work->menuRes, (struct TaskMenuItem *)(&req), 11, 21, 11, work->heapId);
    STRBUF_Delete(req.text);
    req.text = MSGDATA_AllocString(work->msgData, 26);
    work->prevButton = APP_TASKMENU_WIN_Create(work->menuRes, (struct TaskMenuItem *)(&req), 0, 21, 11, work->heapId);
    STRBUF_Delete(req.text);
    req.text = MSGDATA_AllocString(work->msgData, 25);
    req.flag = 1;
    work->closeButton = APP_TASKMENU_WIN_Create(work->menuRes, (struct TaskMenuItem *)(&req), 22, 21, 10, work->heapId);
    STRBUF_Delete(req.text);
    APP_TASKMENU_WIN_ClearScreen(work->prevButton);
    *(u16 *)0x050005e2 = 0;
}

void CG_HELP_FreeWindows(CgHelpWork *work)
{
    if (work->nextButton) APP_TASKMENU_WIN_Delete(work->nextButton);
    if (work->prevButton) APP_TASKMENU_WIN_Delete(work->prevButton);
    APP_TASKMENU_WIN_Delete(work->closeButton);
    APP_TASKMENU_RES_Delete(work->menuRes);
    PRINTSYS_QUE_Delete(work->printQue);
    BMP_WIN_Delete(work->bodyWin);
    BMP_WIN_Delete(work->titleWin);
    MSGDATA_Delete(work->msgData);
    GF_FONT_Delete(work->font);
    GF_FONT_SetDefaultTextColor();
}

void CG_HELP_HandleTouchInput(CgHelpWork *work)
{
    CgHelpTouchRects table;
    table = gCgHelpTouchRects;
    switch (TOUCHPANEL_HitTrg((const TouchHitTable *)&table)) {
    case 0:
        if (work->pageIndex != 0) {
            (work->pageIndex)--;
            CG_HELP_DrawPageText(work,work->pageIndex);
            APP_TASKMENU_WIN_SetDecide(work->prevButton,1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 1:
        if (work->pageIndex < 11) {
            (work->pageIndex)++;
            CG_HELP_DrawPageText(work,work->pageIndex);
            APP_TASKMENU_WIN_SetDecide(work->nextButton,1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 2:
        APP_TASKMENU_WIN_SetDecide(work->closeButton,1);
        work->phase = 2;
        GFL_USE_PlaySeDefaultVolume(0x551);
        break;
    }
    if (GAMESYSTEM_IsNetOffBySleep((struct GameSystem *)work->args->inputCtx) == 1) {
        APP_TASKMENU_WIN_SetDecide(work->closeButton,1);
        work->phase = 2;
    }
}

void CG_HELP_DrawPageText(CgHelpWork *work, int page)
{
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(work->titleWin),1);
    BMP_Clear(BMP_WIN_GetBmp(work->bodyWin),0);
    q = MSGDATA_AllocString(work->msgData,page);
    PRINTSYS_PrintQueColor(work->printQue,BMP_WIN_GetBmp(work->titleWin),40,8,q,work->font,0x3c40);
    STRBUF_Delete(q);
    page += 12;
    q = MSGDATA_AllocString(work->msgData,page);
    PRINTSYS_PrintQueColor(work->printQue,BMP_WIN_GetBmp(work->bodyWin),0,0,q,work->font,0x3c40);
    STRBUF_Delete(q);
    work->textDirty = 1;
}

/*
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 */
void CG_HELP_UpdatePageGraphics(CgHelpWork *work, u32 page)
{
    u16 *q;
    u8 i, j;
    CgHelpVec delta;
    CLACT_SetActorAnimSeq(work->pageActor, gCgHelpPageAnimSeq[page]);
    CLACT_SetActorDrawEnable(work->pageActor, 1);
    if (page <= 7) {
        NNS_GfdRegisterNewVramTransferTask(31, 320, (work->charData->rawData + gCgHelpPageCharOffset[page] * 32), 32);
        q = GFL_HEAP_Alloc(work->heapId, 32, 1, gCgHelpFileName, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + gCgHelpPageTileBase[page] + i * 32 + 0xa000;
            }
        }
        BG_SYS_DrawTile(4, q, 2, 4, 4, 4);
        GFL_HEAP_Free(q);
    } else {
        q = GFL_HEAP_Alloc(work->heapId, 32, 1, gCgHelpFileName, 0x2bb);
        BG_SYS_DrawTile(4, q, 2, 4, 4, 4);
        GFL_HEAP_Free(q);
    }
    BG_SYS_PushTile(4);
    delta = gCgHelpActorOffset;
    CLACT_AddActorSurfacePos((struct ClactActor *)work->pageActor, (const struct ClactVec2 *)((const struct Vec2 *)(&delta)), 1);
    if (page == 10) {
        CLACT_SetActorAutoAnim((struct ClactActor *)work->pageActor, 0);
        CLACT_SetActorAnimIndex((struct ClactActor *)(work->pageActor), 1);
    } else if (page == 11) {
        CLACT_SetActorAutoAnim((struct ClactActor *)work->pageActor, 0);
        CLACT_SetActorAnimIndex((struct ClactActor *)(work->pageActor), 0);
    } else {
        CLACT_SetActorAutoAnim(work->pageActor, 1);
    }
}

int CG_HELP_ProcInit(void *a,int b,CgHelpArgs *c)
{
    CgHelpWork *work;
    CgHelpArgs *q;
    GFL_HEAP_CreateChildHeap(1,0x8a,0x60000);
    work = PROCSYS_AllocProcWork(a,sizeof(CgHelpWork),0x8a);
    q = c;
    if (!q) {
        q = GFL_HEAP_Alloc(0x8a,sizeof(CgHelpArgs),1,gCgHelpFileName,0x2f3);
        q->myStatus = MYSTATUS_Create(0x8a);
        if (KEY_GetCont() & 0x100) MYSTATUS_SetSex(q->myStatus,1);
        else MYSTATUS_SetSex(q->myStatus,0);
    }
    work->args = q;
    work->heapId = 0x8a;
    CG_HELP_Setup(work);
    return 1;
}

int CG_HELP_ProcExit(struct Proc *task, int b, int keep, CgHelpWork *work)
{
    CG_HELP_Teardown(work);
    if (keep == 0) {
        GFL_HEAP_Free(work->args->myStatus);
        GFL_HEAP_Free(work->args);
    }
    PROCSYS_FreeProcWork(task);
    GFL_HEAP_DeleteChecked(0x8a);
    return 1;
}

#include "../arm9/net_err.h"
int CG_HELP_ProcMain(int a, int b, int c, CgHelpWork *work)
{
    int r;

    (void)a; (void)b; (void)c;
    r = CG_HELP_Main(work);
    if (GFL_NET_ERR_GetErrorLevel() != 0 && work->closeRequested == 0) {
        work->closeRequested = 1;
        work->phase = CG_HELP_PHASE_CLOSE_BUTTON;
    }
    return r == 1;
}
