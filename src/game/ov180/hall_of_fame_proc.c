/*
 * file:     hall_of_fame_proc.c
 * unit:     yes
 * function: HALL_OF_FAME_ProcInit, HALL_OF_FAME_ProcMain, HALL_OF_FAME_ProcExit, HALL_OF_FAME_AddVBlankTaskMon, HALL_OF_FAME_AddVBlankTaskTrainer, HALL_OF_FAME_RemoveVBlankTask, HALL_OF_FAME_VBlankMon, HALL_OF_FAME_VBlankTrainer, HALL_OF_FAME_SetVramBanks, HALL_OF_FAME_GetVramBanksAddr, HALL_OF_FAME_InitGraphicsSystem, HALL_OF_FAME_ExitGraphicsSystem, HALL_OF_FAME_SetupDisplay
 * address:  0x021B6100
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   HALL_OF_FAME_RunState  0x021B6A10  thumb  ov180
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data a4
 *   gHallOfFameVramBanksMain 0x021B8060 data a4
 *   gHallOfFameVramBanksSub 0x021B8090 data a4
 *   gHallOfFameDisplayConfig 0x021B80D8 data a4
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   DOUBLE3DDISP_Delete  0x0204EA64  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 */
#include "hall_of_fame.h"

struct DispVram;

/* Display control block handed to the display setup call (16 bytes). */
#include "../arm9/bg_sys.h"

#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/clact.h"
#include "../arm9/double3Ddisp.h"
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern const struct DispVram gHallOfFameVramBanksMain;
extern const struct DispVram gHallOfFameVramBanksSub;
extern const struct DispConfig gHallOfFameDisplayConfig;

int HALL_OF_FAME_ProcInit(struct Proc *proc, void *unused, u32 args)
{
    HallOfFameWork *work;
    GFL_HEAP_CreateChildHeap(1, HOF_HEAP_ID, 0x60000);
    work = PROCSYS_AllocProcWork(proc, sizeof(HallOfFameWork), HOF_HEAP_ID);
    MI_CpuFill8(work, 0, sizeof(HallOfFameWork));
    work->args = (HallOfFameArgs *)args;
    return 1;
}

int HALL_OF_FAME_ProcMain(int proc, int unused, int unused2, HallOfFameWork *work)
{
    if (HALL_OF_FAME_RunState(work))
        return 0;
    return 1;
}

int HALL_OF_FAME_ProcExit(struct Proc *proc)
{
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(HOF_HEAP_ID);
    return 1;
}

void HALL_OF_FAME_AddVBlankTaskMon(HallOfFameWork *work)
{
    work->vblankTask = (void *)GFL_USE_AddMainTask((void *)HALL_OF_FAME_VBlankMon, work, 0);
}

void HALL_OF_FAME_AddVBlankTaskTrainer(HallOfFameWork *work)
{
    work->vblankTask = (void *)GFL_USE_AddMainTask((void *)HALL_OF_FAME_VBlankTrainer, work, 0);
}

void HALL_OF_FAME_RemoveVBlankTask(HallOfFameWork *work)
{
    TCB_DeleteTask(work->vblankTask);
}

/*
 * volatile: SDK IRQ check buffer read/write at 021B61A4/021B61A8.
 */
void HALL_OF_FAME_VBlankMon(void)
{
    CLACT_VBlankSystem();
    DOUBLE3DDISP_Delete();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

/*
 * volatile: SDK IRQ check buffer read/write at 021B61C4/021B61C8.
 */
void HALL_OF_FAME_VBlankTrainer(void)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

void HALL_OF_FAME_SetVramBanks(int subScreen)
{
    BG_SYS_ClearGraphicsMemory(0);
    if (subScreen == 0)
        BG_SYS_SetVramBanks(&gHallOfFameVramBanksMain);
    else
        BG_SYS_SetVramBanks(&gHallOfFameVramBanksSub);
}

int HALL_OF_FAME_GetVramBanksAddr(int subScreen)
{
    if (subScreen == 0)
        return 0x021B8060;
    return 0x021B8090;
}

void HALL_OF_FAME_InitGraphicsSystem(void)
{
    BG_SYS_Create(HOF_HEAP_ID);
}

void HALL_OF_FAME_ExitGraphicsSystem(void)
{
    BG_SYS_Delete();
}

void HALL_OF_FAME_SetupDisplay(void)
{
    struct DispConfig cfg;
    cfg = gHallOfFameDisplayConfig;
    BG_SYS_SetGraphicsMode(&cfg);
    BG_SYS_LoadPlttEntry(0, 0);
    BG_SYS_LoadPlttEntry(4, 0);
}
