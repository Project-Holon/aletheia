/*
 * file:     pdc.c
 * unit:     yes
 * function: PDC_CreateArgs, PDC_GetGameData, PDC_GetMon, PDC_GetScene, PDC_GetMyStatus, PDC_GetMyItem, PDC_GetConfig, PDC_GetPokedexSave, PDC_GetResult, PDC_ProcInit, PDC_ProcMain, PDC_ProcExit
 * address:  0x021B6100
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdc.c, ov098_func_021B6CDC.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gPdcSrcName 0x021B6E60 data a1
 *   ov094_id       0x0000005E  data
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   PDC_MAIN_Create 0x021B61E8 thumb ov098
 *   PDC_MAIN_Update 0x021B6308 thumb ov098
 *   PDC_MAIN_Delete 0x021B632C thumb ov098
 */
#include "pdc_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02034AC4(int overlayId);
extern void GFL_HEAP_CreateChildHeap(u32 parentHeapId, u32 heapId, u32 size);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);
extern void MIi_CpuClearFast(int value, void *dst, u32 size);
extern void func_020315D4(struct Proc *proc);
extern void GFL_HEAP_DeleteChecked(unsigned int heapId);
extern void func_02034A5C(int overlayId);

extern struct PdcSys *PDC_MAIN_Create(struct PdcArgs *args, u16 heapId);
extern int PDC_MAIN_Update(struct PdcSys *sys);
extern void PDC_MAIN_Delete(struct PdcSys *sys);

extern const char gPdcSrcName[];
extern char ov094_id[];

/* Builds the argument block of the screen. */
struct PdcArgs *PDC_CreateArgs(struct GameData *gameData, struct PokemonParam *mon, void *scene, struct MyStatus *myStatus,
                              struct MyItem *myItem, struct Config *config, struct PokedexSave *pokedexSave, u16 heapId)
{
    struct PdcArgs *args;

    args = func_02030734(heapId, 0x20, 0, gPdcSrcName, 0x50);
    args->gameData = gameData;
    args->mon = mon;
    args->scene = scene;
    args->myStatus = myStatus;
    args->myItem = myItem;
    args->config = config;
    args->pokedexSave = pokedexSave;
    args->result = 0;
    return args;
}

/* Getters of the argument block, one per field. */
struct GameData *PDC_GetGameData(struct PdcArgs *args)
{
    return args->gameData;
}

struct PokemonParam *PDC_GetMon(struct PdcArgs *args)
{
    return args->mon;
}

void *PDC_GetScene(struct PdcArgs *args)
{
    return args->scene;
}

struct MyStatus *PDC_GetMyStatus(struct PdcArgs *args) { return args->myStatus; }

struct MyItem *PDC_GetMyItem(struct PdcArgs *args)
{
    return args->myItem;
}

struct Config *PDC_GetConfig(struct PdcArgs *args) { return args->config; }

struct PokedexSave *PDC_GetPokedexSave(struct PdcArgs *args)
{
    return args->pokedexSave;
}

int PDC_GetResult(struct PdcArgs *args)
{
    return args->result;
}

/* Proc init: loads overlay 94, creates the heap and the screen. */
int PDC_ProcInit(struct Proc *proc, int seq, struct PdcArgs *args)
{
    struct PdcProc *work;

    func_02034AC4((int)ov094_id);
    GFL_HEAP_CreateChildHeap(1, 0x85, 0xc0000);
    work = PROCSYS_AllocProcWork(proc, 0xc, 0x85);
    MIi_CpuClearFast(0, work, 0xc);
    work->heapId = 0x85;
    work->sys = PDC_MAIN_Create(args, work->heapId);
    work->args = args;
    return 1;
}

/* Proc main: runs the screen, stores its result in the argument block. */
int PDC_ProcMain(struct Proc *proc, int seq, int unused, struct PdcProc *work)
{
    work->args->result = PDC_MAIN_Update(work->sys);
    if (work->args->result != 0) return 1;
    return 0;
}

/* Proc exit: deletes the screen, the heap and the overlay. */
int PDC_ProcExit(struct Proc *proc, int seq, int unused, struct PdcProc *work)
{
    PDC_MAIN_Delete(work->sys);
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(0x85);
    func_02034A5C((int)ov094_id);
    return 1;
}
