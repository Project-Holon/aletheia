/*
 * file:     worldtrade.c
 * unit:     yes
 * function: WORLDTRADE_ProcInit, WORLDTRADE_ProcMain, WORLDTRADE_ProcExit, WORLDTRADE_VBlankTask, WORLDTRADE_SetupVramBanks, WORLDTRADE_CallStateHandler, WORLDTRADE_Nop, WORLDTRADE_SetupWindowPlanes, WORLDTRADE_InitClactSystem, WORLDTRADE_SetPlaneVisibleAll, WORLDTRADE_OpenTaskMenuYesNoDefault, WORLDTRADE_OpenTaskMenuYesNo, WORLDTRADE_CloseTaskMenu, WORLDTRADE_UpdateTaskMenuYesNo, WORLDTRADE_OpenTaskMenuList, WORLDTRADE_UpdateTaskMenuList, WORLDTRADE_CloseTaskMenuList, WORLDTRADE_SetNextState, WORLDTRADE_SetActorSurfacePos, WORLDTRADE_GetWifiLinkLevel, WORLDTRADE_SetStateAndReturn, WORLDTRADE_AdvanceScreenId, WORLDTRADE_GetMessageWait, WORLDTRADE_SetupGraphics, WORLDTRADE_ReleaseGraphics, WORLDTRADE_DecrementTimer, WORLDTRADE_ClearSelectedSpecies, WORLDTRADE_CreateTimeIcon, WORLDTRADE_DeleteTimeIcon, WORLDTRADE_SetActorPos, WORLDTRADE_SetBrightnessIn, WORLDTRADE_SetBrightnessOut, WORLDTRADE_ClearBlendRegs, WORLDTRADE_ClearAndShowPlanes, WORLDTRADE_ExitPlanes, WORLDTRADE_CancelSave
 * address:  0x021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   WORLDTRADE_ADAPTER_InitPrinter  0x022026D8  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_UpdateConnection 0x0205D074 arm
 *   GFL_NET_WM_ICON_EasySetLevel 0x020370F4 arm
 *   DPW_TR_Main 0x021C7C1C arm ov114
 *   PROCSYS_Main 0x02031330 arm
 *   TCB_Main 0x02030D28 arm
 *   WORLDTRADE_ADAPTER_UpdatePrinter 0x02202770 thumb ov135
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WORLDTRADE_SUBLCD_CreateActors 0x021FF6A4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   CLACT_DrawSystem 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   MSGDATA_Delete 0x02045C04 arm
 *   TCB_Noop 0x02030DA4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PROCSYS_Delete 0x0203133C arm
 *   WORLDTRADE_ADAPTER_ExitPrinter 0x02202744 thumb ov135
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   str_02203B08  0x02203B08  data  a1
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt 0x0207E51C  arm
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   data_02202BC8 0x02202BC8 data a4
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   data_02202C2C 0x02202C2C data a4
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   DWC_GetLinkLevel  0x0205CCD8  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   g_02202BFC  0x02202BFC  data  ov135
 *   WORLDTRADE_SUBLCD_FreeResources  0x021FFCD4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   tbl_02202BB8  0x02202BB8  data
 *   TCB_DeleteTask  0x02030EAC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   GFL_NET_ERR_HaltWithMessage   0x0200F7C0  thumb
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   PROCSYS_Create  0x02031324  arm  arm9
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm  arm9
 *   BG_SYS_ClearSubPlanes  0x02043588  arm  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm  arm9
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_DeleteTimeIcon  0x021F4FC4  thumb  ov135
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNo  0x021F4BF8  thumb  ov135
 *   WORLDTRADE_ClearBlendRegs  0x021F5060  thumb  ov135
 *   WORLDTRADE_SetBrightnessOut  0x021F5034  thumb  ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   WORLDTRADE_ClearSelectedSpecies 0x021F4F90 thumb ov135
 *   WORLDTRADE_GetMessageWait 0x021F4ED4 thumb ov135
 *   WORLDTRADE_CreateTimeIcon  0x021F4FA4  thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   G2x_SetBlendBrightness_  0x0207D658  arm  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   TCB_GetTaskOffset  0x02030CB0  arm  arm9
 *   TCB_Init  0x02030CBC  arm  arm9
 */
#include "worldtrade_types.h"
#include "worldtrade_adapter.h"
#include "../arm9/clact.h"
#include "../arm9/gfl_use.h"

#define ASSERT(x) if (!(x)) GF_PANIC_Fail(str_02203B08, 0, str_02203B08)

struct ProcSystem;

struct S020314B8;

struct Proc;

struct DispVram;

struct Bank;

struct TaskMenuRes;

struct TaskMenu;


struct TaskMenuState;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } WorldtradeHandler;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} WorldtradePlttData;

#include "../arm9/app_taskmenu.h"
#include "../arm9/msgdata.h"

typedef struct { TaskMenuItem item[2]; } BoxItems2;



typedef struct { TaskMenuItem item[3]; } BoxItems3;

#include "../arm9/gf_overlay.h"

#include "../arm9/gfl_heap.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"



#include "../arm9/tcb_list.h"

#include "../arm9/gfl_heap_wrap.h"
struct TcbSystem;



#include "../arm9/wordset.h"


#include "../arm9/bg_sys.h"



#include "../arm9/net.h"

#include "../arm9/dwc_connectinet.h"

#include "../arm9/wm_icon.h"

#include "../ov114/dpw_tr.h"




#include "../arm9/wipe.h"

#include "worldtrade_sublcd.h"















#include "../arm9/gf_panic.h"

#include "../arm9/arc_tool.h"
struct DispVramCfg;
struct SysInit;







#include "../arm9/arc_util.h"

#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"
struct MyStatus;

#include "../arm9/mystatus.h"



struct PrintQueue;
struct GFont;

struct TaskMenuInitWork;
struct TaskMenuWork;

struct Strbuf;


#include "../arm9/strbuf.h"








#include "../arm9/msg_speed.h"






struct TcbList;

struct BmpWin;
struct TimeIcon;

#include "../arm9/time_icon.h"


#include "../arm9/bmp_win.h"



#include "../arm9/g2.h"








struct TcbTask;



struct GameSystem;
struct GameData;

#include "../arm9/gamesystem.h"

#include "../arm9/game_data.h"

#include "../arm9/net_err.h"



int WORLDTRADE_ProcInit(void *proc, int *seq, WorldtradeArgs *args);

int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, WorldtradeWork *p);

int WORLDTRADE_ProcExit(void *ctx, int unused1, int unused2, WorldtradeWork *p);

void WORLDTRADE_VBlankTask(struct TcbTask *unused, void *work);

void WORLDTRADE_SetupVramBanks(const struct DispVram *vram);

void WORLDTRADE_CallStateHandler(WorldtradeWork *p, WorldtradeArgs *args);

void WORLDTRADE_Nop(WorldtradeWork *p);

void WORLDTRADE_SetupWindowPlanes(void);

void WORLDTRADE_InitClactSystem(WorldtradeWork *p, u32 mode);

void WORLDTRADE_SetPlaneVisibleAll(WorldtradeWork *p);

void WORLDTRADE_OpenTaskMenuYesNoDefault(WorldtradeWork *a, u32 b, u32 c, u32 d, u8 e);

void WORLDTRADE_OpenTaskMenuYesNo(WorldtradeWork *p,int b,int unused,int a,int c,u8 flag);

void WORLDTRADE_CloseTaskMenu(WorldtradeWork *p);

int WORLDTRADE_UpdateTaskMenuYesNo(WorldtradeWork *p);

void WORLDTRADE_OpenTaskMenuList(WorldtradeWork *p, u16 a, int count, int b);

u32 WORLDTRADE_UpdateTaskMenuList(WorldtradeWork *p);

void WORLDTRADE_CloseTaskMenuList(WorldtradeWork *p);

void WORLDTRADE_SetNextState(WorldtradeWork *p, u32 a, u32 b);

void WORLDTRADE_SetActorSurfacePos(struct ClactActor *a, int b, int c);

int WORLDTRADE_GetWifiLinkLevel(void);

void WORLDTRADE_SetStateAndReturn(WorldtradeWork *p, u32 a, u32 b);

void WORLDTRADE_AdvanceScreenId(WorldtradeWork *p);

int WORLDTRADE_GetMessageWait(void);

void WORLDTRADE_SetupGraphics(WorldtradeWork *p);

void WORLDTRADE_ReleaseGraphics(WorldtradeWork *p);

void WORLDTRADE_DecrementTimer(WorldtradeWork *p);

void WORLDTRADE_ClearSelectedSpecies(WorldtradeWork *p);

void WORLDTRADE_CreateTimeIcon(WorldtradeWork *p);

void WORLDTRADE_DeleteTimeIcon(WorldtradeWork *p);

void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

void WORLDTRADE_SetBrightnessIn(u32 x);

void WORLDTRADE_SetBrightnessOut(u32 x);

void WORLDTRADE_ClearBlendRegs(void);

void WORLDTRADE_ClearAndShowPlanes(WorldtradeWork *p);

void WORLDTRADE_ExitPlanes(WorldtradeWork *p);

void WORLDTRADE_CancelSave(WorldtradeWork *p);

extern u8 ov114_id[];

extern u8 ov067_id[];

extern WorldtradeWork *g_02203F80;

extern const char str_02203AF8[];

extern const WorldtradeHandler d_02203A80[];

extern const char str_02203B08[];

extern u8 d_02202BE0[];

extern const BoxItems2 data_02202BC8;

extern const BoxItems3 data_02202C2C;

extern u8 g_02202BFC[];

extern const struct DispConfig tbl_02202BB8;

int WORLDTRADE_ProcInit(void *proc, int *seq, WorldtradeArgs *args)
{
    WorldtradeWork *p;

    GF_OVERLAY_Load((uptr)ov114_id);
    GF_OVERLAY_Load((uptr)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x48, 0x30100);
    p = PROCSYS_AllocProcWork(proc, sizeof(WorldtradeWork), 0x48);
    MI_CpuFill8(p, 0, sizeof(WorldtradeWork));
    g_02203F80 = p;
    p->tradeMon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
    p->procSys = PROCSYS_Create(0x48);
    p->recMem = GFL_HEAP_Alloc(0x48, TCB_GetTaskOffset(8), 0, str_02203AF8, 0xA1);
    p->rec_p = TCB_Init(8, p->recMem);
    WORLDTRADE_ADAPTER_InitPrinter(&p->printer, (uptr)args->statusConfig);
    p->words = WORDSET_Create(0xB, 0x40, 0x48);
    p->msg[0] = MSGDATA_CreateFromArchive(0, 2, 0xD0, 0x48);
    p->msg[2] = MSGDATA_CreateFromArchive(0, 2, 0xD1, 0x48);
    p->msg[3] = MSGDATA_CreateFromArchive(0, 2, 0xE8, 0x48);
    p->msg[1] = MSGDATA_CreateFromArchive(0, 2, 0x46, 0x48);
    p->msg[4] = MSGDATA_CreateFromArchive(0, 2, 0xE7, 0x48);
    WORLDTRADE_CallStateHandler((WorldtradeWork *)p, (WorldtradeArgs *)args);
    BG_SYS_ClearGraphicsMemory(0);
    WORLDTRADE_ClearAndShowPlanes(p);
    GFL_USE_SetBgmPaused(0);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}

int WORLDTRADE_ProcMain(void *unused0, int *state, void *unused2, WorldtradeWork *p)
{
    if (GFL_NET_GetRunState() != 0) {
        DWC_UpdateConnection();
        GFL_NET_WM_ICON_EasySetLevel(WORLDTRADE_GetWifiLinkLevel());
    }
    DPW_TR_Main();
    p->busy_u = PROCSYS_Main(p->procSys);
    TCB_Main(p->rec_p);
    WORLDTRADE_ADAPTER_UpdatePrinter(&p->printer);
    switch (*state) {
    case 0:
        *state = d_02203A80[p->screenId].init((u8 *)p, *state);
        WORLDTRADE_SetupWindowPlanes();
        break;
    case 1:
        if (WIPE_SYS_EndCheck() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[p->screenId].update((u8 *)p, *state);
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            *state = d_02203A80[p->screenId].finish((u8 *)p, *state);
            if (p->subLcdRefresh != 0) {
                WORLDTRADE_SUBLCD_CreateActors(p);
                WORLDTRADE_SUBLCD_UpdateSlotPalettes(p, (*(int *)&p->d0), 0);
                p->subLcdRefresh = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    WORLDTRADE_DecrementTimer(p);
    if (*(u32 *)&p->res != 0) CLACT_DrawSystem();
    if (p->countdownFrames > 0) p->countdownFrames -= 1;
    return 0;
}

int WORLDTRADE_ProcExit(void *ctx, int unused1, int unused2, WorldtradeWork *p)
{
    GFL_USE_CancelChangeAndStopBgm();
    WORLDTRADE_ExitPlanes(p);
    WORLDTRADE_Nop(p);
    MSGDATA_Delete(p->names);
    MSGDATA_Delete(p->msg[3]);
    MSGDATA_Delete(p->msg[2]);
    MSGDATA_Delete(p->bank);
    MSGDATA_Delete(p->msg_p);
    WORDSET_Delete(p->words);
    TCB_Noop(p->rec_p);
    GFL_HEAP_Free(p->recMem);
    PROCSYS_Delete(p->procSys);
    GFL_HEAP_Free(p->tradeMon);
    WORLDTRADE_ADAPTER_ExitPrinter(&p->printer);
    PROCSYS_FreeProcWork(ctx);
    GFL_HEAP_DeleteChecked(0x48);
    GF_OVERLAY_Unload((uptr)ov067_id);
    GF_OVERLAY_Unload((uptr)ov114_id);
    return 1;
}

void WORLDTRADE_VBlankTask(struct TcbTask *unused, void *work)
{
    WorldtradeWork *p = work;
    BG_SYS_Update();
    CLACT_VBlankSystem();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}

void WORLDTRADE_SetupVramBanks(const struct DispVram *vram)
{
    BG_SYS_SetVramBanks(vram);
}

void WORLDTRADE_CallStateHandler(WorldtradeWork *p, WorldtradeArgs *args)
{
    ASSERT(args->saveData);
    ASSERT(args->sys);
    ASSERT(args->handle04);
    ASSERT(args->party);
    ASSERT(args->save);
    ASSERT(args->wifiList);
    ASSERT(args->wifiHistory);
    ASSERT(args->myStatus);
    ASSERT(args->statusConfig);
    ASSERT(args->record);
    p->args = args;
    p->screenId = 0;
    WORLDTRADE_SetStateAndReturn(p, 0, 0x13);
    p->sel = 0;
    p->sel_h = 0;
    p->recMode = 3;
    p->recKey = 0;
    p->recVal = 0;
    p->rec2Name = 0;
    p->active = 0;
    p->box = 0xFF;
    p->species = 0;
    p->speciesCleared = 0;
    p->historyFlag = 0;
    p->timeIcon = 0;
    p->countryFilter = 0;
}

/*
 * Empty stub: a bare `bx lr`, the overlay's no-op placeholder body.
 */
void WORLDTRADE_Nop(WorldtradeWork *p)
{
}

static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x04000048 & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x04000048 = (u16)tmp;
}

static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x0400004A & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x0400004A = (u16)tmp;
}

void WORLDTRADE_SetupWindowPlanes(void)
{
    *(vu32 *)0x04001000 &= ~0xE000;
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & ~0xE000) | 0x2000;
    SetWnd0InsidePlane(0x1F, 0);
    SetWndOutsidePlane(0x1F, 1);
    *(vu16 *)0x04000040 = 0xF0FF;
    *(vu16 *)0x04000044 = 0x10;
}

/*
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when MYSTATUS_GetSex reports 1, else 0xE/4/0xC/0xD).
 */
void WORLDTRADE_InitClactSystem(WorldtradeWork *p, u32 mode)
{
    void *arc;
    void *buf;
    WorldtradePlttData *pd;
    int i;
    u16 *d;
    u32 anm;
    u32 cell;
    u32 pal;
    u32 chr;

    arc = ARC_TOOL_CreateHandle(0x60, 0x48);
    CLACT_InitSystem((const struct ClactSysInit *)d_02202BE0, (const struct DispVramCfg *)mode, 0x48);
    p->res_res.unit = (uptr)CLACT_CreateUnit(0x60, 0, 0x48);
    p->res_res.mainChar = CLACT_RegisterCharacter(arc, 0x11, 1, 0, 0x48);
    p->res_res.mainPlt = CLACT_RegisterPalette(arc, 8, 0, 0, 0x48);
    p->res_res.mainCell = CLACT_RegisterCellAnim(arc, 0x12, 0x13, 0x48);
    p->res_res.mainIconChar = CLACT_RegisterCharacter(arc, 0x27, 1, 0, 0x48);
    p->res_res.mainIconCell = CLACT_RegisterCellAnim(arc, 0x28, 0x29, 0x48);
    p->res_res.slotChar = CLACT_RegisterCharacter(arc, 0x24, 1, 1, 0x48);
    p->res_res.slotPlt = CLACT_RegisterPalette(arc, 7, 1, 0, 0x48);
    p->res_res.slotCell = CLACT_RegisterCellAnim(arc, 0x25, 0x26, 0x48);
    ARC_TOOL_DeleteHandle(arc);

    buf = ARC_UTIL_LoadPaletteBlockFromArchive(7, 0, (&pd), 0x48);
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0xA0, 0x60);
    d = pd->data;
    for (i = 0; i < 0x30; i++) {
        u16 c = d[i];
        d[i] = ((((c >> 10) & 0x1f) / 2) << 10) | ((((c >> 5) & 0x1f) / 2) << 5) | ((c & 0x1f) / 2);
    }
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0x100, 0x60);
    GFL_HEAP_Free(buf);

    if ((u8)(u32)MYSTATUS_GetSex(p->ctx->myStatus) == 1) {
        chr = 0x11;
        anm = 0x10;
        cell = 0xF;
        pal = 6;
    } else {
        chr = 0xE;
        anm = 0xD;
        cell = 0xC;
        pal = 4;
    }
    arc = ARC_TOOL_CreateHandle(0x1f, 0x48);
    p->res_res.primaryChar = CLACT_RegisterCharacter(arc, chr, 0, 1, 0x48);
    p->res_res.primaryPlt = CLACT_RegisterPaletteEx(arc, pal, 1, 0, 0, 1, 0x48);
    p->res_res.primaryCell = CLACT_RegisterCellAnim(arc, cell, anm, 0x48);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Release the 0x10 channel on both hardware blocks.
 */
void WORLDTRADE_SetPlaneVisibleAll(WorldtradeWork *p)
{
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void WORLDTRADE_OpenTaskMenuYesNoDefault(WorldtradeWork *work, u32 y, u32 unused, u32 plttIdx, u8 flag)
{
    WORLDTRADE_OpenTaskMenuYesNo((WorldtradeWork *)work, y, unused, plttIdx, 0, flag);
}

void WORLDTRADE_OpenTaskMenuYesNo(WorldtradeWork *p,int y,int unused,int plttIdx,int bgLayer,u8 flag)
{
    BoxItems2 items;
    TaskMenuInitWork menu;
    int on;
    if (p->taskMenuRes) GF_PANIC_Fail(str_02203B08,0,str_02203B08);
    if (p->taskMenu) GF_PANIC_Fail(str_02203B08,0,str_02203B08);
    p->taskMenuRes=APP_TASKMENU_RES_Create((u8)bgLayer,(u8)plttIdx,(struct GFont *)p->uiResA,(struct PrintQueue *)p->uiResB,0x48);
    items=data_02202BC8;
    on=0;
    MI_CpuFill8(&menu,0,20);
    items.item[0].str=MSGDATA_AllocString(p->bank,63);
    items.item[1].str=MSGDATA_AllocString(p->bank,64);
    menu.heapId=0x48;
    menu.itemNum=2;
    menu.itemWork=items.item;
    menu.posType=1;
    menu.charPosX=0x20;
    menu.charPosY=y;
    menu.width=8;
    menu.height=3;
    p->taskMenu=APP_TASKMENU_OpenMenu(&menu,p->taskMenuRes);
    STRBUF_Delete(items.item[0].str);
    STRBUF_Delete(items.item[1].str);
    if (flag) {
        if(bgLayer<=3) on=1;
        WORLDTRADE_SetBrightnessIn(on);
    }
}

void WORLDTRADE_CloseTaskMenu(WorldtradeWork *p) { if(p->taskMenu) { APP_TASKMENU_CloseMenu(p->taskMenu); p->taskMenu=0; } if(p->taskMenuRes) { APP_TASKMENU_RES_Delete(p->taskMenuRes); p->taskMenuRes=0; } }

int WORLDTRADE_UpdateTaskMenuYesNo(WorldtradeWork *p) { int result; result=0; if(p->taskMenu) { APP_TASKMENU_UpdateMenu(p->taskMenu); if(APP_TASKMENU_IsFinish(p->taskMenu)) { result=APP_TASKMENU_GetCursorPos(p->taskMenu); if(result==0) result=1; else if(result==1) result=2; WORLDTRADE_ClearBlendRegs(); } } return result; }

void WORLDTRADE_OpenTaskMenuList(WorldtradeWork *p, u16 bgLayer, int count, int y)
{
    BoxItems3 items;
    TaskMenuInitWork menu;
    int i;
    if (p->taskMenuRes) GF_PANIC_Fail(str_02203B08,0,str_02203B08);
    if (p->taskMenu) GF_PANIC_Fail(str_02203B08,0,str_02203B08);
    p->taskMenuRes=APP_TASKMENU_RES_Create(bgLayer,10,(struct GFont *)p->uiResA,(struct PrintQueue *)p->uiResB,0x48);
    items=data_02202C2C;
    MI_CpuFill8(&menu,0,20);
    if ((u32)count>3) GF_PANIC_Fail(str_02203B08,0,str_02203B08);
    for(i=0;i<count;i++) items.item[i].str=(struct Strbuf *)*(u32 *)((uptr)p->de8+i*8);
    menu.heapId=0x48;
    menu.itemNum=count;
    menu.itemWork=items.item;
    menu.posType=1;
    menu.charPosX=0x20;
    menu.charPosY=y;
    menu.width=13;
    menu.height=3;
    p->taskMenu=APP_TASKMENU_OpenMenu(&menu,p->taskMenuRes);
    WORLDTRADE_SetBrightnessIn(1);
}

u32 WORLDTRADE_UpdateTaskMenuList(WorldtradeWork *p)
{
    u32 r = (u32)-1;

    if (p->taskMenu != 0) {
        APP_TASKMENU_UpdateMenu(p->taskMenu);
        if (APP_TASKMENU_IsFinish(p->taskMenu) != 0) {
            r = APP_TASKMENU_GetCursorPos(p->taskMenu) + 1;
            WORLDTRADE_ClearBlendRegs();
        }
    }
    return r;
}

void WORLDTRADE_CloseTaskMenuList(WorldtradeWork *p)
{
    if (p->taskMenu != 0) {
        APP_TASKMENU_CloseMenu(p->taskMenu);
        p->taskMenu = 0;
    }
    if (p->taskMenuRes != 0) {
        APP_TASKMENU_RES_Delete(p->taskMenuRes);
        p->taskMenuRes = 0;
    }
    WORLDTRADE_ClearBlendRegs();
}

void WORLDTRADE_SetNextState(WorldtradeWork *p, u32 state, u32 returnState)
{
    p->state = state;
    p->returnState = returnState;
}

/*
 * Send a one-entry u16 table {b, c}
/*
 * Send a one-entry u16 table {b, c} to CLACT_AddActorSurfacePos.
 */
void WORLDTRADE_SetActorSurfacePos(struct ClactActor *obj, int x, int y)
{
    u16 t[2];

    t[0] = x;
    t[1] = y;
    CLACT_AddActorSurfacePos(obj, (const struct ClactVec2 *)t, 1);
}

int WORLDTRADE_GetWifiLinkLevel(void)
{
    return 3 - DWC_GetLinkLevel();
}

/*
 * Store two words into the object at +0x14 and +0x20.
 */
void WORLDTRADE_SetStateAndReturn(WorldtradeWork *p, u32 nextScreenId, u32 kind)
{
    p->nextScreenId = nextScreenId;
    *(u32 *)&p->kind = kind;
}

/*
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */
void WORLDTRADE_AdvanceScreenId(WorldtradeWork *p)
{
    p->prevScreenId = p->screenId;
    p->screenId = p->nextScreenId;
}

int WORLDTRADE_GetMessageWait(void)
{
    return MSG_SPEED_GetWait();
}

/*
 * Wire the shared table into the two initialisers and release the channel.
 */
void WORLDTRADE_SetupGraphics(WorldtradeWork *p)
{
    WORLDTRADE_SetupVramBanks((const struct DispVram *)g_02202BFC);
    WORLDTRADE_InitClactSystem((WorldtradeWork *)p, (uptr)g_02202BFC);
    WORLDTRADE_SetPlaneVisibleAll(p);
}

void WORLDTRADE_ReleaseGraphics(WorldtradeWork *p)
{
    WORLDTRADE_SUBLCD_FreeResources(p);
    CLACT_ReleasePalette(p->res_res.primaryPlt);
    CLACT_ReleaseCharacter(p->res_res.primaryChar);
    CLACT_ReleaseCellAnim(p->res_res.primaryCell);
    CLACT_ReleasePalette(p->res_res.slotPlt);
    CLACT_ReleaseCharacter(p->res_res.slotChar);
    CLACT_ReleaseCellAnim(p->res_res.slotCell);
    CLACT_ReleasePalette(p->sub.mainPlt);
    CLACT_ReleaseCharacter(p->sub.mainChar);
    CLACT_ReleaseCellAnim(p->sub.mainCell);
    CLACT_ReleaseCharacter(p->sub.mainIconChar);
    CLACT_ReleaseCellAnim(p->sub.mainIconCell);
    CLACT_DeleteUnit((struct Unit *)(p->sub.unit));
    p->sub.unit = 0;
    CLACT_ExitSystem();
}

/*
 * Decrement the u16 counter at +0x36 when it is non-zero.
 */
void WORLDTRADE_DecrementTimer(WorldtradeWork *p)
{
    u16 v = p->cooldownFrames;

    if (v != 0) {
        p->cooldownFrames = v - 1;
    }
}

/*
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */
void WORLDTRADE_ClearSelectedSpecies(WorldtradeWork *p)
{
    p->speciesCleared = 1;
    p->species = 0;
}

/*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * GFL_USE_GetMainTaskList.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WORLDTRADE_CreateTimeIcon.c --func WORLDTRADE_CreateTimeIcon  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */
void WORLDTRADE_CreateTimeIcon(WorldtradeWork *p)
{
    p->timeIcon = (uptr)TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(), (void *)(p->frame),
                                        0xf, 0x10, 0x48);
}

void WORLDTRADE_DeleteTimeIcon(WorldtradeWork *p)
{
    if (p->timeIcon != 0) {
        TIME_ICON_Delete((struct TimeIcon *)(p->timeIcon));
        p->timeIcon = 0;
        BMP_WIN_MakeScreen((struct BmpWin *)(p->frame));
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)(p->frame)));
    }
}

void WORLDTRADE_SetActorPos(u32 obj, u32 x, u32 y)
{
    u16 t[2];

    t[0] = x;
    t[1] = y;
    CLACT_AddActorSurfacePos((struct ClactActor *)obj, (const struct ClactVec2 *)t, 0);
}

/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1e/-7 pair.
 */
void WORLDTRADE_SetBrightnessIn(u32 isMain)
{
    if (isMain != 0) {
        G2x_SetBlendBrightness_(0x04000050, 0x1e, -7);
    } else {
        G2x_SetBlendBrightness_(0x04001050, 0x1e, -7);
    }
}

/*
 * Pick the 0x04000050 or 0x04001050 hardware register from the flag and write the 0x1b/-7 pair.
 */
void WORLDTRADE_SetBrightnessOut(u32 isMain)
{
    if (isMain != 0) {
        G2x_SetBlendBrightness_(0x04000050, 0x1b, -7);
    } else {
        G2x_SetBlendBrightness_(0x04001050, 0x1b, -7);
    }
}

/*
 * Clear the two display control registers.
 */
void WORLDTRADE_ClearBlendRegs(void)
{
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
}

void WORLDTRADE_ClearAndShowPlanes(WorldtradeWork *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    WORLDTRADE_SetupGraphics(p);
    BG_SYS_Create(0x48);
    BMP_WIN_Init(0x48);
    {
        struct DispConfig c = tbl_02202BB8;

        BG_SYS_SetGraphicsMode(&c);
    }
    WORLDTRADE_SetupWindowPlanes();
    *(vu16 *)0x04000050 = 0;
    *(vu16 *)0x04001050 = 0;
    if (p->vblank_p == 0) {
        p->vblank_p = GFL_USE_AddMainTask(WORLDTRADE_VBlankTask, p, 0);
    }
}

void WORLDTRADE_ExitPlanes(WorldtradeWork *p)
{
    if (p->vblank_p != 0) {
        TCB_DeleteTask(p->vblank_p);
        p->vblank_p = 0;
    }
    *(vu16 *)0x04000050 = 0;
    *(vu16 *)0x04001050 = 0;
    WORLDTRADE_ReleaseGraphics(p);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    *(vu32 *)0x04000000 &= 0xFFFF1FFF;
    *(vu32 *)0x04001000 &= 0xFFFF1FFF;
}

void WORLDTRADE_CancelSave(WorldtradeWork *p)
{
    GAME_DATA_SaveCancel(GAMESYSTEM_GetGameData((struct GameSystem *)p->ctx->gameData));
    GFL_NET_ERR_HaltWithMessage(0x29);
}
