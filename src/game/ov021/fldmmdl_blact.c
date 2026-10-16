/*
 * file:     fldmmdl_blact.c
 * unit:     yes
 * function: FLDMMDL_BLACT_AddVramSlot, FLDMMDL_BLACT_DeleteVramSlot, FLDMMDL_BLACT_Init, FLDMMDL_BLACT_Exit, FLDMMDL_BLACT_Update, FLDMMDL_BLACT_RegisterLoadedRes, FLDMMDL_BLACT_IsReservePending, FLDMMDL_BLACT_GetEntryHookFlag, FLDMMDL_BLACT_AddResByCode, FLDMMDL_BLACT_AddCachedRes, FLDMMDL_BLACT_AddActorPos, FLDMMDL_BLACT_AddActorMmdl, FLDMMDL_BLACT_AddActorPosPalette, FLDMMDL_BLACT_AddActorMmdlPalette, FLDMMDL_BLACT_AddActorMmdlByCode, FLDMMDL_BLACT_AddActorMmdlOrReserve, FLDMMDL_BLACT_DeleteActorRes, FLDMMDL_BLACT_DeleteActorMmdl, FLDMMDL_BLACT_AddActorPosOrReserve, FLDMMDL_BLACT_DeleteActorPos, FLDMMDL_BLACT_EntryHook, FLDMMDL_BLACT_GetBbActSys, FLDMMDL_BLACT_GetActorSize, FLDMMDL_BLACT_InitResTable, FLDMMDL_BLACT_FreeResTable, FLDMMDL_BLACT_AddResIndex, FLDMMDL_BLACT_RemoveResIndex, FLDMMDL_BLACT_FindResIndex, FLDMMDL_BLACT_CreateResTable, FLDMMDL_BLACT_DeleteAllRes, FLDMMDL_BLACT_AddRes, FLDMMDL_BLACT_AddResObjCodeParam, FLDMMDL_BLACT_DeleteRes, FLDMMDL_BLACT_FindRes, FLDMMDL_BLACT_CreateReserve, FLDMMDL_BLACT_DeleteReserve, FLDMMDL_BLACT_CheckReserveLeft, FLDMMDL_BLACT_ReserveRes, FLDMMDL_BLACT_LoadReservedRes, FLDMMDL_BLACT_LoadAddRes, FLDMMDL_BLACT_RegisterAddRes, FLDMMDL_BLACT_FindReservedRes, FLDMMDL_BLACT_CancelReservedRes, FLDMMDL_BLACT_ReserveActor, FLDMMDL_BLACT_AddReservedActor, FLDMMDL_BLACT_AddReservedActors, FLDMMDL_BLACT_IsActorReservedByOther, FLDMMDL_BLACT_CancelReservedActor, FLDMMDL_BLACT_ClearActorReserve, FLDMMDL_BLACT_ChangeObjCode, FLDMMDL_BLACT_CreateCodeChange, FLDMMDL_BLACT_DeleteCodeChange, FLDMMDL_BLACT_UpdateCodeChange, FLDMMDL_BLACT_UpdateCodeChanges, FLDMMDL_BLACT_IsCodeChangePending, FLDMMDL_BLACT_GetAnimeTable, FLDMMDL_BLACT_AddResSlot
 * address:  0x0219C4AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_blact.c at 0x0219D448 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   BILLBOARD_AddImageFromVramKeys  0x0204F044  arm
 *   BILLBOARD_ACT_AddSlot  0x02050238  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   sBlactCellSize     0x021D75C4  data  a4
 *   sBlactTexFmt     0x021D8064  data  a4
 *   BILLBOARD_ACT_GetSlotBoardId  0x02050330  arm
 *   BILLBOARD_ACT_DeleteSlot  0x02050304  arm
 *   BILLBOARD_ReleaseImageVram  0x0204F214  arm
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   FLDMMDL_SysSetBlActCont  0x0216D51C  thumb  ov010
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BILLBOARD_SetPolyIdBase  0x0204EDB0  arm
 *   sBlactFileName     0x021DDD70  data  a1
 *   sBlactBoardScale     0x021D8058  data  a4
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_LoadObjCodeParam  0x0216E2E8  thumb  ov010
 *   FLDMMDL_GetCachedObjCodeCount  0x0216E2E0  thumb  ov010
 *   FLDMMDL_GetCachedObjCodeParam  0x0216E2AC  thumb  ov010
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   sBlactDrawSize     0x021D75D0  data  a4
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   BILLBOARD_ACT_SetEntryPaletteFromSlot  0x02050894  arm
 *   BILLBOARD_ACT_GetEntrySlotIndex  0x020508D8  arm
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   FLDMMDL_CheckSameObjCodeOther  0x0216DFC4  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FLDMMDL_GetObjCodeParamBlActRes  0x0216E3C8  thumb  ov010
 *   FLDMMDL_SysGetResArcHandle  0x0216D518  thumb  ov010
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_ChangeObjCode  0x0216E204  thumb  ov010
 *   FLDMMDL_CheckStatusBitUse  0x0216DA30  thumb  ov010
 *   sBlactAnimeTable  0x021D7F68  data  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 */
#include "fldmmdl_blact_types.h"

extern int G3D_SYSTEM_TransVramTexture(void *res);
extern struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys);
extern u32 func_02047388(void *res);
extern u32 func_020473B8(void *res);
extern int BILLBOARD_AddImageFromVramKeys(struct BbBoard *board, int texKey, int plttKey, int a3, u32 texFmt, u8 cellWidth, u8 cellHeight);
extern u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 imageId, u32 c);
extern void G3D_SYSTEM_DeleteResource(void *res);
extern u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex);
extern int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, int slotIndex);
extern void BILLBOARD_ReleaseImageVram(struct BbBoard *board, int imageId);
extern u32 FLDMMDL_SysGetHeapId(MmdlSys *sys);
extern void FLDMMDL_SysSetBlActCont(MmdlSys *sys, BlactSys *cont);
extern void BILLBOARD_SetScale(struct BbBoard *board, VecFx32 *scale);
extern void BILLBOARD_SetPolyIdBase(struct BbBoard *board, u8 *polyIdBase);
extern BlactSys *FLDMMDL_SysGetBlActCont(MmdlSys *sys);
extern u32 GFL_HEAP_Free(void *p);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern void FLDMMDL_LoadObjCodeParam(MmdlSys *sys, u32 code, MmdlObjCodeParam *out);
extern u16 FLDMMDL_GetCachedObjCodeCount(MmdlSys *sys);
extern void FLDMMDL_GetCachedObjCodeParam(MmdlSys *sys, int index, MmdlObjCodeParam *out);
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 base, const struct BbActDesc *desc, u32 count, u32 mode);
extern void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, void *cmdLists, u16 listCount);
extern void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex);
extern void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled);
extern MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl);
extern void FLDMMDL_ACMD_GetDrawPos(Mmdl *mmdl, VecFx32 *out);
extern int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int slotIndex);
extern u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex);
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);
extern int FLDMMDL_CheckSameObjCodeOther(Mmdl *mmdl, u32 code);
extern u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count);
extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern u16 *FLDMMDL_GetObjCodeParamBlActRes(const MmdlObjCodeParam *param);
extern void *FLDMMDL_SysGetResArcHandle(MmdlSys *sys);
extern void *G3D_SYSTEM_CreateResourceArcHandle(void *arcHandle, u32 dataId);
extern u16 FLDMMDL_SysGetMmdlMax(MmdlSys *sys);
extern void FLDMMDL_CallDrawProc(Mmdl *mmdl);
extern void MI_CpuFill8(void *p, u32 value, u32 size);
extern int FLDMMDL_CallDrawGetProc(Mmdl *mmdl, unsigned int kind);
extern void FLDMMDL_ChangeObjCode(Mmdl *mmdl, u32 code);
extern int FLDMMDL_CheckStatusBitUse(Mmdl *mmdl, BlactCodeChange *change);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);

int FLDMMDL_BLACT_AddVramSlot(struct BbActSys *sys, void *res, u32 mdlSize, u32 texSize);
void FLDMMDL_BLACT_DeleteVramSlot(struct BbActSys *sys, u32 slotIndex);
void FLDMMDL_BLACT_Init(MmdlSys *mmdlSys, struct BbActSys *bbdActSys, u32 resMax);
void FLDMMDL_BLACT_Exit(MmdlSys *mmdlSys);
void FLDMMDL_BLACT_Update(MmdlSys *mmdlSys);
void FLDMMDL_BLACT_RegisterLoadedRes(MmdlSys *mmdlSys);
int FLDMMDL_BLACT_IsReservePending(MmdlSys *mmdlSys);
int FLDMMDL_BLACT_GetEntryHookFlag(Mmdl *mmdl);
void FLDMMDL_BLACT_AddResByCode(MmdlSys *mmdlSys, u32 code);
void FLDMMDL_BLACT_AddCachedRes(MmdlSys *mmdlSys);
u32 FLDMMDL_BLACT_AddActorPos(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex);
u32 FLDMMDL_BLACT_AddActorMmdl(Mmdl *mmdl, u16 slotIndex);
u32 FLDMMDL_BLACT_AddActorPosPalette(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex, u16 paletteSlot);
u32 FLDMMDL_BLACT_AddActorMmdlPalette(Mmdl *mmdl, u16 slotIndex, u16 paletteSlot);
u32 FLDMMDL_BLACT_AddActorMmdlByCode(Mmdl *mmdl, u32 code);
int FLDMMDL_BLACT_AddActorMmdlOrReserve(Mmdl *mmdl, u16 *outBlactId);
void FLDMMDL_BLACT_DeleteActorRes(BlactSys *cont, Mmdl *mmdl, u32 blactId, u16 code);
void FLDMMDL_BLACT_DeleteActorMmdl(Mmdl *mmdl, u32 blactId);
int FLDMMDL_BLACT_AddActorPosOrReserve(MmdlSys *mmdlSys, const MmdlObjCodeParam *param, u16 *actor, VecFx32 *pos, BlactAddActorHook hook, u32 hookArg);
void FLDMMDL_BLACT_DeleteActorPos(MmdlSys *mmdlSys, u16 *actor);
void FLDMMDL_BLACT_EntryHook(struct BbActSys *sys, int entryIndex, u32 arg);
struct BbActSys *FLDMMDL_BLACT_GetBbActSys(BlactSys *cont);
void FLDMMDL_BLACT_GetActorSize(Mmdl *mmdl, u16 *width, u16 *height);
void FLDMMDL_BLACT_InitResTable(BlactResTable *table, u32 count, u32 heapId);
void FLDMMDL_BLACT_FreeResTable(BlactResTable *table);
void FLDMMDL_BLACT_AddResIndex(BlactResTable *table, u16 code, u16 slotIndex, u16 flags);
void FLDMMDL_BLACT_RemoveResIndex(BlactResTable *table, u16 code);
int FLDMMDL_BLACT_FindResIndex(BlactResTable *table, u32 code, u16 *slotIndex, u16 *flags);
void FLDMMDL_BLACT_CreateResTable(BlactSys *cont, u32 count);
void FLDMMDL_BLACT_DeleteAllRes(BlactSys *cont);
void FLDMMDL_BLACT_AddRes(BlactSys *cont, void *resHandle, u16 code, u32 mdlSize, u8 texSize, u32 flags);
void FLDMMDL_BLACT_AddResObjCodeParam(BlactSys *cont, const MmdlObjCodeParam *param, u32 flags);
void FLDMMDL_BLACT_DeleteRes(BlactSys *cont, u16 code);
int FLDMMDL_BLACT_FindRes(BlactSys *cont, u32 code, u16 *slotIndex, u16 *flags);
void FLDMMDL_BLACT_CreateReserve(BlactSys *cont);
void FLDMMDL_BLACT_DeleteReserve(BlactSys *cont);
int FLDMMDL_BLACT_CheckReserveLeft(BlactSys *cont);
void FLDMMDL_BLACT_ReserveRes(BlactSys *cont, u16 code, u8 mdlSize, u8 texSize, u16 resId, u32 flags);
void FLDMMDL_BLACT_LoadReservedRes(BlactSys *cont);
int FLDMMDL_BLACT_LoadAddRes(BlactSys *cont, u32 code, u32 mdlSize, u32 texSize, u16 resId, u32 flags);
void FLDMMDL_BLACT_RegisterAddRes(BlactSys *cont);
int FLDMMDL_BLACT_FindReservedRes(BlactSys *cont, unsigned int code, unsigned short *outFlags);
int FLDMMDL_BLACT_CancelReservedRes(BlactSys *cont, unsigned int code);
void FLDMMDL_BLACT_ReserveActor(BlactSys *cont, Mmdl *mmdl, const MmdlObjCodeParam *param, u16 *outBlactId, BlactAddActorHook hook, u32 hookArg, VecFx32 *pos);
void FLDMMDL_BLACT_AddReservedActor(BlactSys *cont, BlactEntry *entry);
void FLDMMDL_BLACT_AddReservedActors(BlactSys *cont);
int FLDMMDL_BLACT_IsActorReservedByOther(BlactSys *cont, unsigned int code, Mmdl *mmdl);
void FLDMMDL_BLACT_CancelReservedActor(BlactSys *cont, Mmdl *mmdl);
void FLDMMDL_BLACT_ClearActorReserve(BlactEntry *entry);
void FLDMMDL_BLACT_ChangeObjCode(Mmdl *mmdl, unsigned int code);
void FLDMMDL_BLACT_CreateCodeChange(BlactSys *cont);
void FLDMMDL_BLACT_DeleteCodeChange(BlactSys *cont);
void FLDMMDL_BLACT_UpdateCodeChange(BlactSys *cont, BlactCodeChange *change);
void FLDMMDL_BLACT_UpdateCodeChanges(BlactSys *cont);
int FLDMMDL_BLACT_IsCodeChangePending(BlactSys *cont, Mmdl *mmdl, u16 blactId);
BlactAnimeTable *FLDMMDL_BLACT_GetAnimeTable(int animId);
unsigned short FLDMMDL_BLACT_AddResSlot(BlactSys *cont, int code, int mdlSize, int texSize, void *resHandle, int kind);

extern u16 sBlactCellSize[][2];       /* cell width and height per model size */
extern u16 sBlactTexFmt[];          /* texture format per texture size */
extern unsigned char sBlactFileName[]; /* allocation site name */
extern VecFx32 sBlactBoardScale;        /* board scale */
extern u16 sBlactDrawSize[][2];       /* billboard width and height per model size */
extern BlactAnimeTable sBlactAnimeTable[];

/* Adds a slot whose image stays in VRAM; the archive resource is freed. */
int FLDMMDL_BLACT_AddVramSlot(struct BbActSys *sys, void *res, u32 mdlSize, u32 texSize)
{
    int slotIndex = -1;
    if (G3D_SYSTEM_TransVramTexture(res) == 1) {
        struct BbBoard *board = BILLBOARD_ACT_GetBoard(sys);
        u16 *cellSize = sBlactCellSize[mdlSize];
        u32 texKey = func_02047388(res);
        slotIndex = BILLBOARD_ACT_AddSlot(sys, BILLBOARD_AddImageFromVramKeys(board, texKey, func_020473B8(res), 0, sBlactTexFmt[texSize], (u8)cellSize[0], (u8)cellSize[1]), 0);
        G3D_SYSTEM_DeleteResource(res);
    }
    return slotIndex;
}

void FLDMMDL_BLACT_DeleteVramSlot(struct BbActSys *sys, u32 slotIndex)
{
    u32 imageId = BILLBOARD_ACT_GetSlotBoardId(sys, slotIndex);
    struct BbBoard *board = BILLBOARD_ACT_GetBoard(sys);
    BILLBOARD_ACT_DeleteSlot(sys, slotIndex);
    BILLBOARD_ReleaseImageVram(board, imageId);
}

void FLDMMDL_BLACT_Init(MmdlSys *mmdlSys, struct BbActSys *bbdActSys, u32 resMax)
{
    BlactSys *cont = GFL_HEAP_Alloc(FLDMMDL_SysGetHeapId(mmdlSys), 0x24, 1, (const char *)sBlactFileName, 360);
    struct BbBoard *board;
    VecFx32 scale;
    u8 polyIdBase;
    cont->mmdlSys = mmdlSys;
    cont->bbdActSys = bbdActSys;
    cont->resMax = resMax;
    FLDMMDL_SysSetBlActCont(mmdlSys, cont);
    FLDMMDL_BLACT_CreateResTable(cont, resMax);
    FLDMMDL_BLACT_CreateReserve(cont);
    FLDMMDL_BLACT_CreateCodeChange(cont);
    board = BILLBOARD_ACT_GetBoard(bbdActSys);
    scale = sBlactBoardScale;
    BILLBOARD_SetScale(board, &scale);
    polyIdBase = 0;
    BILLBOARD_SetPolyIdBase(board, &polyIdBase);
}

void FLDMMDL_BLACT_Exit(MmdlSys *mmdlSys)
{
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    FLDMMDL_BLACT_DeleteCodeChange(cont);
    FLDMMDL_BLACT_DeleteReserve(cont);
    FLDMMDL_BLACT_DeleteAllRes(cont);
    GFL_HEAP_Free(cont);
    FLDMMDL_SysSetBlActCont(mmdlSys, 0);
}

void FLDMMDL_BLACT_Update(MmdlSys *mmdlSys)
{
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    if (cont != 0) {
        if (cont->reserve != 0) {
            FLDMMDL_BLACT_AddReservedActors(cont);
            FLDMMDL_BLACT_LoadReservedRes(cont);
        }
        FLDMMDL_BLACT_UpdateCodeChanges(cont);
        cont->entryHookFlag = 0;
    }
}

void FLDMMDL_BLACT_RegisterLoadedRes(MmdlSys *mmdlSys)
{
    FLDMMDL_BLACT_RegisterAddRes(FLDMMDL_SysGetBlActCont(mmdlSys));
}

int FLDMMDL_BLACT_IsReservePending(MmdlSys *mmdlSys)
{
    if (FLDMMDL_BLACT_CheckReserveLeft(FLDMMDL_SysGetBlActCont(mmdlSys)) == 1) {
        return 1;
    }
    return 0;
}

int FLDMMDL_BLACT_GetEntryHookFlag(Mmdl *mmdl)
{
    return FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl))->entryHookFlag;
}

void FLDMMDL_BLACT_AddResByCode(MmdlSys *mmdlSys, u32 code)
{
    MmdlObjCodeParam param;
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    FLDMMDL_LoadObjCodeParam(mmdlSys, code, &param);
    FLDMMDL_BLACT_AddResObjCodeParam(cont, &param, 0);
}

void FLDMMDL_BLACT_AddCachedRes(MmdlSys *mmdlSys)
{
    MmdlObjCodeParam param;
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    int count = FLDMMDL_GetCachedObjCodeCount(mmdlSys);
    int i;
    for (i = 0; i < count; i++) {
        FLDMMDL_GetCachedObjCodeParam(mmdlSys, i, &param);
        FLDMMDL_BLACT_AddResObjCodeParam(cont, &param, 0);
    }
}

u32 FLDMMDL_BLACT_AddActorPos(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex)
{
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    struct BbActDesc desc;
    u32 blactId;
    BlactAnimeTable *anime;
    u16 *size = sBlactDrawSize[mdlSize];
    struct BbActSys *sys;
    desc.slot = slotIndex;
    desc.width = sBlactDrawSize[mdlSize][0];
    desc.height = size[1];
    desc.pos = *pos;
    desc.layer = 0x1f;
    desc.flags = 1;
    desc.color = 1;
    desc.hook = FLDMMDL_BLACT_EntryHook;
    desc.hookArg = (u32)cont;
    blactId = BILLBOARD_ACT_CreateEntries(cont->bbdActSys, cont->slotBase, &desc, 1, 0);
    anime = FLDMMDL_BLACT_GetAnimeTable(animId);
    if (anime->cmdLists != 0) {
        BILLBOARD_ACT_SetEntryCommands(cont->bbdActSys, blactId, anime->cmdLists, (u16)anime->listCount);
        sys = cont->bbdActSys;
        BILLBOARD_ACT_SetEntryList(sys, blactId, 0);
        BILLBOARD_ACT_SetEntryEnabled(sys, blactId, 1);
    }
    return blactId;
}

u32 FLDMMDL_BLACT_AddActorMmdl(Mmdl *mmdl, u16 slotIndex)
{
    MmdlSys *mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    MmdlObjCodeParam *param = FLDMMDL_GetObjCodeParam(mmdl);
    VecFx32 pos;
    FLDMMDL_ACMD_GetDrawPos(mmdl, &pos);
    return FLDMMDL_BLACT_AddActorPos(mmdlSys, &pos, param->mdlSize, param->animId, slotIndex);
}

u32 FLDMMDL_BLACT_AddActorPosPalette(MmdlSys *mmdlSys, VecFx32 *pos, int mdlSize, u32 animId, u16 slotIndex, u16 paletteSlot)
{
    u32 blactId = FLDMMDL_BLACT_AddActorPos(mmdlSys, pos, mdlSize, animId, slotIndex);
    if (paletteSlot != 0xFFFF) {
        BILLBOARD_ACT_SetEntryPaletteFromSlot(FLDMMDL_SysGetBlActCont(mmdlSys)->bbdActSys, blactId, paletteSlot);
    }
    return blactId;
}

u32 FLDMMDL_BLACT_AddActorMmdlPalette(Mmdl *mmdl, u16 slotIndex, u16 paletteSlot)
{
    MmdlSys *mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    MmdlObjCodeParam *param = FLDMMDL_GetObjCodeParam(mmdl);
    VecFx32 pos;
    FLDMMDL_ACMD_GetDrawPos(mmdl, &pos);
    return FLDMMDL_BLACT_AddActorPosPalette(mmdlSys, &pos, param->mdlSize, param->animId, slotIndex, paletteSlot);
}

u32 FLDMMDL_BLACT_AddActorMmdlByCode(Mmdl *mmdl, u32 code)
{
    u16 res[2]; /* [0] flags, [1] slot index */
    FLDMMDL_BLACT_FindRes(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl)), code, &res[1], &res[0]);
    return FLDMMDL_BLACT_AddActorMmdl(mmdl, res[1]);
}

/* Adds the model's actor now, or reserves it when the resource is not ready. */
int FLDMMDL_BLACT_AddActorMmdlOrReserve(Mmdl *mmdl, u16 *outBlactId)
{
    BlactSys *cont = FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl));
    MmdlObjCodeParam *param = FLDMMDL_GetObjCodeParam(mmdl);
    u16 res[2]; /* [0] flags, [1] slot index */
    FLDMMDL_BLACT_FindRes(cont, param->code, &res[1], &res[0]);
    if (res[1] != 0xFFFF && (FLDMMDL_BLACT_RESBIT_TRANS & res[0]) == 0) {
        *outBlactId = FLDMMDL_BLACT_AddActorMmdlByCode(mmdl, param->code);
        return 1;
    }
    *outBlactId = 0xFFFF;
    FLDMMDL_BLACT_ReserveActor(cont, mmdl, param, outBlactId, 0, 0, 0);
    return 0;
}

void FLDMMDL_BLACT_DeleteActorRes(BlactSys *cont, Mmdl *mmdl, u32 blactId, u16 code)
{
    u16 res[2]; /* [0] flags, [1] slot index */
    if (FLDMMDL_BLACT_FindRes(cont, code, &res[1], &res[0]) == 1) {
        if (res[0] & FLDMMDL_BLACT_RESBIT_TRANS) {
            u32 slotIndex = BILLBOARD_ACT_GetEntrySlotIndex(cont->bbdActSys, blactId);
            BILLBOARD_ACT_DeleteSlots(cont->bbdActSys, slotIndex, 1);
        }
        if (res[0] & FLDMMDL_BLACT_RESBIT_GUEST) {
            if (FLDMMDL_CheckSameObjCodeOther(mmdl, code) == 0)
                FLDMMDL_BLACT_DeleteRes(cont, code);
        }
    }
}

void FLDMMDL_BLACT_DeleteActorMmdl(Mmdl *mmdl, u32 blactId)
{
    u16 code = FLDMMDL_GetObjCode(mmdl);
    BlactSys *cont = FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl));
    if (blactId == 0xFFFF) {
        FLDMMDL_BLACT_CancelReservedActor(cont, mmdl);
        return;
    }
    if (FLDMMDL_BLACT_IsCodeChangePending(cont, mmdl, blactId) != 1) {
        FLDMMDL_BLACT_DeleteActorRes(cont, mmdl, (u16)blactId, code);
        BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, blactId, 1);
    }
}

/* actor: [0] resource flags, [1] actor id.
 * param is const: that is what lets the mdlSize/animId loads schedule above
 * the outgoing stack-argument store of slotIndex. */
int FLDMMDL_BLACT_AddActorPosOrReserve(MmdlSys *mmdlSys, const MmdlObjCodeParam *param, u16 *actor, VecFx32 *pos, BlactAddActorHook hook, u32 hookArg)
{
    u16 slotIndex;
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    FLDMMDL_BLACT_FindRes(cont, param->code, &slotIndex, actor);
    if (!(*actor & FLDMMDL_BLACT_RESBIT_TRANS)) {
        actor[1] = FLDMMDL_BLACT_AddActorPos(mmdlSys, pos, param->mdlSize, param->animId, slotIndex);
        return 1;
    }
    actor[1] = 0xFFFF;
    FLDMMDL_BLACT_ReserveActor(cont, 0, param, &actor[1], hook, hookArg, pos);
    return 0;
}

void FLDMMDL_BLACT_DeleteActorPos(MmdlSys *mmdlSys, u16 *actor)
{
    BlactSys *cont = FLDMMDL_SysGetBlActCont(mmdlSys);
    if (actor[1] != 0xFFFF) {
        if (actor[0] & FLDMMDL_BLACT_RESBIT_TRANS) {
            u32 slotIndex = BILLBOARD_ACT_GetEntrySlotIndex(cont->bbdActSys, actor[1]);
            BILLBOARD_ACT_DeleteSlots(cont->bbdActSys, slotIndex, 1);
        }
        BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, actor[1], 1);
    }
    actor[0] = 0;
    actor[1] = 0xFFFF;
}

/* Entry hook of every actor (BbActDesc.hook); arg is the container. */
void FLDMMDL_BLACT_EntryHook(struct BbActSys *sys, int entryIndex, u32 arg)
{
    ((BlactSys *)arg)->entryHookFlag |= 1;
}

struct BbActSys *FLDMMDL_BLACT_GetBbActSys(BlactSys *cont)
{
    return cont->bbdActSys;
}

void FLDMMDL_BLACT_GetActorSize(Mmdl *mmdl, u16 *width, u16 *height)
{
    MmdlObjCodeParam *param = FLDMMDL_GetObjCodeParam(mmdl);
    u16 *size = sBlactDrawSize[param->mdlSize];
    *width = size[0];
    *height = size[1];
}

void FLDMMDL_BLACT_InitResTable(BlactResTable *table, u32 count, u32 heapId)
{
    BlactResIndex *entry = GFL_HEAP_Alloc(heapId, count * sizeof(BlactResIndex), 1, (const char *)sBlactFileName, 0x484);
    table->count = count;
    table->entries = entry;
    do {
        entry->code = 0xFFFF;
        entry->slotIndex = 0xFFFF;
        entry++;
    } while (--count);
}

void FLDMMDL_BLACT_FreeResTable(BlactResTable *table)
{
    GFL_HEAP_Free(table->entries);
}

void FLDMMDL_BLACT_AddResIndex(BlactResTable *table, u16 code, u16 slotIndex, u16 flags)
{
    int i;
    BlactResIndex *entry = table->entries;
    i = 0;
    do {
        if (entry->code == 0xFFFF) {
            entry->code = code;
            entry->slotIndex = slotIndex;
            entry->flags = flags;
            return;
        }
        i++;
        entry++;
    } while (i < table->count);
}

void FLDMMDL_BLACT_RemoveResIndex(BlactResTable *table, u16 code)
{
    int i;
    BlactResIndex *entry = table->entries;
    i = 0;
    do {
        if (entry->code == code) {
            entry->code = 0xFFFF;
            entry->slotIndex = 0xFFFF;
            entry->flags = 0;
            return;
        }
        i++;
        entry++;
    } while (i < table->count);
}

int FLDMMDL_BLACT_FindResIndex(BlactResTable *table, u32 code, u16 *slotIndex, u16 *flags)
{
    int i = 0;
    BlactResIndex *entry = table->entries;
    if (slotIndex) *slotIndex = 0xFFFF;
    do {
        if (entry->code == code) {
            if (slotIndex) *slotIndex = entry->slotIndex;
            if (flags) *flags = entry->flags;
            return 1;
        }
        i++;
        entry++;
    } while (i < table->count);
    return 0;
}

void FLDMMDL_BLACT_CreateResTable(BlactSys *cont, u32 count)
{
    FLDMMDL_BLACT_InitResTable(&cont->resTable, count, FLDMMDL_SysGetHeapId(cont->mmdlSys));
}

void FLDMMDL_BLACT_DeleteAllRes(BlactSys *cont)
{
    int i;
    BlactResIndex *entry = cont->resTable.entries;
    i = 0;
    do {
        if (entry->code != 0xFFFF) {
            FLDMMDL_BLACT_DeleteRes(cont, entry->code);
        }
        i++;
        entry++;
    } while (i < cont->resTable.count);
    FLDMMDL_BLACT_FreeResTable(&cont->resTable);
}

void FLDMMDL_BLACT_AddRes(BlactSys *cont, void *resHandle, u16 code, u32 mdlSize, u8 texSize, u32 flags)
{
    int kind = FLDMMDL_BLACT_SLOT_VRAM;
    u16 slotIndex;
    if (flags & FLDMMDL_BLACT_RESBIT_TRANS) kind = 2;
    slotIndex = FLDMMDL_BLACT_AddResSlot(cont, code, mdlSize, texSize, resHandle, kind);
    FLDMMDL_BLACT_AddResIndex(&cont->resTable, code, slotIndex, (u16)flags);
}

void FLDMMDL_BLACT_AddResObjCodeParam(BlactSys *cont, const MmdlObjCodeParam *param, u32 flags)
{
    u16 *resId = FLDMMDL_GetObjCodeParamBlActRes(param);
    FLDMMDL_BLACT_AddRes(cont, G3D_SYSTEM_CreateResourceArcHandle(FLDMMDL_SysGetResArcHandle(cont->mmdlSys), *resId), param->code, param->mdlSize, param->texSize, flags);
}

void FLDMMDL_BLACT_DeleteRes(BlactSys *cont, u16 code)
{
    u16 res[2]; /* [0] slot index, [1] flags */
    FLDMMDL_BLACT_FindResIndex(&cont->resTable, code, &res[0], &res[1]);
    if (res[1] & FLDMMDL_BLACT_RESBIT_TRANS) {
        BILLBOARD_ACT_DeleteSlots(cont->bbdActSys, res[0], 1);
    } else {
        FLDMMDL_BLACT_DeleteVramSlot(cont->bbdActSys, res[0]);
    }
    FLDMMDL_BLACT_RemoveResIndex(&cont->resTable, code);
}

int FLDMMDL_BLACT_FindRes(BlactSys *cont, u32 code, u16 *slotIndex, u16 *flags)
{
    return FLDMMDL_BLACT_FindResIndex(&cont->resTable, code, slotIndex, flags);
}

void FLDMMDL_BLACT_CreateReserve(BlactSys *cont)
{
    u32 heapId = FLDMMDL_SysGetHeapId(cont->mmdlSys);
    BlactReserve *reserve = GFL_HEAP_Alloc(heapId, sizeof(BlactReserve), 1, (const char *)sBlactFileName, 1491);
    BlactResReserve *res;
    int i;
    reserve->resReserveMax = cont->resMax;
    reserve->actReserveMax = FLDMMDL_SysGetMmdlMax(cont->mmdlSys);
    reserve->addResMax = 1;
    res = GFL_HEAP_Alloc(heapId, sizeof(BlactResReserve) * reserve->resReserveMax, 1, (const char *)sBlactFileName, 1498);
    reserve->resReserve = res;
    i = 0;
    if (i < reserve->resReserveMax) {
        for (; i < reserve->resReserveMax; i++, res++)
            res->code = 0xFFFF;
    }
    reserve->addRes = GFL_HEAP_Alloc(heapId, sizeof(BlactAddRes) * reserve->addResMax, 1, (const char *)sBlactFileName, 1511);
    reserve->actReserve = GFL_HEAP_Alloc(heapId, sizeof(BlactEntry) * reserve->actReserveMax, 1, (const char *)sBlactFileName, 1513);
    reserve->isActive = 1;
    cont->reserve = reserve;
}

void FLDMMDL_BLACT_DeleteReserve(BlactSys *cont)
{
    BlactReserve *reserve = cont->reserve;
    u32 i;
    BlactAddRes *addRes;
    BlactEntry *entry;
    if (reserve == 0) return;
    i = 0;
    reserve->isActive = i;
    GFL_HEAP_Free(reserve->resReserve);
    addRes = reserve->addRes;
    if (i < reserve->addResMax) {
        for (; i < reserve->addResMax; i++, addRes++) {
            if (addRes->resHandle != 0)
                G3D_SYSTEM_DeleteResource(addRes->resHandle);
        }
    }
    GFL_HEAP_Free(reserve->addRes);
    i = 0;
    entry = reserve->actReserve;
    if (i < reserve->actReserveMax) {
        for (; i < reserve->actReserveMax; i++, entry++) {
            if (entry->outBlactId != 0 && entry->resHandle != 0)
                G3D_SYSTEM_DeleteResource(entry->resHandle);
        }
    }
    GFL_HEAP_Free(reserve->actReserve);
    GFL_HEAP_Free(reserve);
    cont->reserve = 0;
}

/*
 * The reserve pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps the record pointer in r0 instead of hoisting the count into
 * a register.
 */
int FLDMMDL_BLACT_CheckReserveLeft(BlactSys *cont)
{
    const BlactReserve *reserve = cont->reserve;
    u32 i;
    const BlactResReserve *res;
    const BlactAddRes *addRes;
    const BlactEntry *entry;
    res = reserve->resReserve;
    for (i = 0; i < reserve->resReserveMax; i++, res++) {
        if (res->code != 0xFFFF) {
            return 1;
        }
    }
    addRes = reserve->addRes;
    for (i = 0; i < reserve->addResMax; i++, addRes++) {
        if (addRes->resHandle != 0) {
            return 1;
        }
    }
    entry = reserve->actReserve;
    for (i = 0; i < reserve->actReserveMax; i++, entry++) {
        if (entry->outBlactId != 0 && entry->resHandle != 0) {
            return 1;
        }
    }
    return 0;
}

void FLDMMDL_BLACT_ReserveRes(BlactSys *cont, u16 code, u8 mdlSize, u8 texSize, u16 resId, u32 flags)
{
    BlactReserve *reserve = cont->reserve;
    u32 i;
    u32 count = reserve->resReserveMax;
    /* stand-in: the record cursor reuses the variable of the first parameter
     * (the image keeps it in that parameter's register, copied to r4); a
     * separate cursor variable is allocated to other registers. */
    cont = (BlactSys *)reserve->resReserve;
    for (i = 0; i < count; i++, cont = (BlactSys *)((BlactResReserve *)cont + 1)) {
        BlactResReserve *res = (BlactResReserve *)cont;
        if (res->code == 0xFFFF) {
            res->code = code;
            res->mdlSize = mdlSize;
            res->texSize = texSize;
            res->resId = resId;
            res->flags = flags;
            return;
        }
    }
}

/* Loads the reserved resources, then moves the free records to the end. */
void FLDMMDL_BLACT_LoadReservedRes(BlactSys *cont)
{
    BlactReserve *reserve = cont->reserve;
    u32 j = 0;
    u32 k = 0;
    BlactResReserve *res = reserve->resReserve;
    BlactResReserve *base;
    for (; j < reserve->resReserveMax; j++, res++) {
        if (res->code != 0xFFFF) {
            if (FLDMMDL_BLACT_LoadAddRes(cont, res->code, res->mdlSize, res->texSize, res->resId, res->flags) == 0)
                break;
            res->code = 0xFFFF;
            k++;
            if (k >= reserve->addResMax)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = reserve->resReserve;
        for (; j < (u32)reserve->resReserveMax - 1; j++) {
            BlactResReserve *free = &base[j];
            if (free->code == 0xFFFF) {
                for (k = j + 1; k < reserve->resReserveMax; k++) {
                    if (base[k].code != 0xFFFF) {
                        *free = base[k];
                        base[k].code = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}

int FLDMMDL_BLACT_LoadAddRes(BlactSys *cont, u32 code, u32 mdlSize, u32 texSize, u16 resId, u32 flags)
{
    BlactReserve *reserve = cont->reserve;
    BlactAddRes *addRes = reserve->addRes;
    u32 i;
    for (i = 0; i < reserve->addResMax; i++, addRes++) {
        if (addRes->resHandle == 0) {
            addRes->isReady = 0;
            addRes->code = code;
            addRes->mdlSize = mdlSize;
            addRes->texSize = texSize;
            addRes->flags = flags;
            addRes->resHandle = G3D_SYSTEM_CreateResourceArcHandle(FLDMMDL_SysGetResArcHandle(cont->mmdlSys), resId);
            addRes->isReady = 1;
            return 1;
        }
    }
    return 0;
}

/* Registers the loaded resources in billboard slots. */
void FLDMMDL_BLACT_RegisterAddRes(BlactSys *cont)
{
    unsigned int i;
    BlactAddRes *addRes;
    BlactReserve *reserve;
    reserve = cont->reserve;
    if (reserve != 0 && reserve->isActive == 1) {
        i = 0;
        addRes = reserve->addRes;
        if (!(i < reserve->addResMax)) {
            return;
        }
        for (; i < reserve->addResMax; i++, addRes++) {
            if (addRes->resHandle != 0 && addRes->isReady == 1) {
                addRes->isReady = 0;
                FLDMMDL_BLACT_AddRes(cont, addRes->resHandle, addRes->code, addRes->mdlSize,
                              addRes->texSize, addRes->flags);
                addRes->resHandle = 0;
            }
        }
    }
}

int FLDMMDL_BLACT_FindReservedRes(BlactSys *cont, unsigned int code, unsigned short *outFlags)
{
    unsigned int i;
    BlactResReserve *res;
    unsigned int resCount;
    unsigned int j;
    BlactAddRes *addRes;
    unsigned int addCount;
    BlactReserve *reserve = cont->reserve;
    i = 0;
    resCount = reserve->resReserveMax;
    res = reserve->resReserve;
    for (; i < resCount; i++, res++) {
        if (res->code == code) {
            *outFlags = res->flags;
            return 1;
        }
    }
    addCount = reserve->addResMax;
    j = 0;
    addRes = reserve->addRes;
    for (; j < addCount; j++, addRes++) {
        if (addRes->code == code && addRes->resHandle != 0) {
            *outFlags = addRes->flags;
            return 1;
        }
    }
    return 0;
}

int FLDMMDL_BLACT_CancelReservedRes(BlactSys *cont, unsigned int code)
{
    unsigned int i;
    BlactResReserve *res;
    unsigned int resCount;
    unsigned int j;
    BlactAddRes *addRes;
    unsigned int addCount;
    BlactReserve *reserve = cont->reserve;
    i = 0;
    resCount = reserve->resReserveMax;
    res = reserve->resReserve;
    for (; i < resCount; i++, res++) {
        if (res->code == code) {
            res->code = 0xFFFF;
            return 1;
        }
    }
    addCount = reserve->addResMax;
    j = 0;
    addRes = reserve->addRes;
    for (; j < addCount; j++, addRes++) {
        if (addRes->resHandle != 0 && addRes->code == code) {
            addRes->isReady = 0;
            G3D_SYSTEM_DeleteResource(addRes->resHandle);
            addRes->resHandle = 0;
            return 1;
        }
    }
    return 0;
}

/* Reserves an actor; its resource is reserved too when nobody has it yet. */
void FLDMMDL_BLACT_ReserveActor(BlactSys *cont, Mmdl *mmdl, const MmdlObjCodeParam *param, u16 *outBlactId, BlactAddActorHook hook, u32 hookArg, VecFx32 *pos)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short res[2]; /* [0] flags, [1] slot index */
    u16 *resId;
    i = 0;
    count = FLDMMDL_SysGetMmdlMax(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId == 0) {
            entry->isWaiting = 0;
            entry->mmdl = mmdl;
            entry->outBlactId = outBlactId;
            entry->code = param->code;
            entry->mdlSize = param->mdlSize;
            entry->texSize = param->texSize;
            entry->animId = param->animId;
            FLDMMDL_BLACT_FindRes(cont, entry->code, &res[1], &res[0]);
            if (res[1] == 0xFFFF && FLDMMDL_BLACT_FindReservedRes(cont, entry->code, &res[0]) == 0) {
                resId = FLDMMDL_GetObjCodeParamBlActRes(param);
                res[0] = FLDMMDL_BLACT_RESBIT_GUEST;
                FLDMMDL_BLACT_ReserveRes(cont, entry->code, entry->mdlSize,
                              entry->texSize, *resId, FLDMMDL_BLACT_RESBIT_GUEST);
            }
            entry->hook = hook;
            entry->hookArg = hookArg;
            if (pos != 0) {
                entry->pos = *pos;
            }
            entry->isWaiting = 1;
            return;
        }
    }
}

void FLDMMDL_BLACT_AddReservedActor(BlactSys *cont, BlactEntry *entry)
{
    unsigned short slot[3]; /* [0] palette slot, [1] flags, [2] image slot */
    u32 blactId;
    slot[0] = 0xFFFF;
    entry->isWaiting = 0;
    if (entry->resHandle != 0) {
        slot[2] = FLDMMDL_BLACT_AddResSlot(cont, entry->code, entry->mdlSize,
                                entry->texSize, entry->resHandle, 1);
        entry->resHandle = 0;
        FLDMMDL_BLACT_FindRes(cont, entry->code, &slot[0], &slot[1]);
    } else {
        FLDMMDL_BLACT_FindRes(cont, entry->code, &slot[2], &slot[1]);
    }
    if (entry->mmdl != 0) {
        blactId = FLDMMDL_BLACT_AddActorMmdlPalette(entry->mmdl, slot[2], slot[0]);
    } else {
        blactId = FLDMMDL_BLACT_AddActorPosPalette(cont->mmdlSys, &entry->pos, entry->mdlSize,
                                entry->animId, slot[2], slot[0]);
    }
    *entry->outBlactId = blactId;
    if (entry->hook != 0) {
        entry->hook(*entry->outBlactId, entry->hookArg);
    }
    if (entry->mmdl != 0) {
        FLDMMDL_CallDrawProc(entry->mmdl);
    }
}

/* Adds the reserved actors whose resource is now registered. */
void FLDMMDL_BLACT_AddReservedActors(BlactSys *cont)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short res[2]; /* [0] slot index, [1] flags */
    i = 0;
    count = FLDMMDL_SysGetMmdlMax(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    if (count == 0) {
        return;
    }
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->isWaiting == 1) {
            if (FLDMMDL_BLACT_FindRes(cont, entry->code, &res[0], &res[1]) == 1) {
                FLDMMDL_BLACT_AddReservedActor(cont, entry);
                FLDMMDL_BLACT_ClearActorReserve(entry);
            }
        }
    }
}

int FLDMMDL_BLACT_IsActorReservedByOther(BlactSys *cont, unsigned int code, Mmdl *mmdl)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    i = 0;
    count = FLDMMDL_SysGetMmdlMax(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->mmdl != 0 && entry->mmdl != mmdl && entry->code == code) {
            return 1;
        }
    }
    return 0;
}

void FLDMMDL_BLACT_CancelReservedActor(BlactSys *cont, Mmdl *mmdl)
{
    unsigned int i;
    unsigned int count;
    BlactEntry *entry;
    unsigned short flags;
    i = 0;
    count = FLDMMDL_SysGetMmdlMax(cont->mmdlSys);
    entry = cont->reserve->actReserve;
    for (; i < count; i++, entry++) {
        if (entry->outBlactId != 0 && entry->mmdl == mmdl) {
            entry->isWaiting = 0;
            if (FLDMMDL_BLACT_FindReservedRes(cont, entry->code, &flags) == 1 && (flags & FLDMMDL_BLACT_RESBIT_GUEST)) {
                if (FLDMMDL_BLACT_IsActorReservedByOther(cont, entry->code, entry->mmdl) == 0) {
                    FLDMMDL_BLACT_CancelReservedRes(cont, entry->code);
                }
            }
            if (entry->resHandle != 0) {
                G3D_SYSTEM_DeleteResource(entry->resHandle);
                entry->resHandle = 0;
            }
            FLDMMDL_BLACT_ClearActorReserve(entry);
            return;
        }
    }
}

void FLDMMDL_BLACT_ClearActorReserve(BlactEntry *entry)
{
    entry->isWaiting = 0;
    MI_CpuFill8(entry, 0, sizeof(BlactEntry));
}

/*
 * Changes the object code of a model and keeps its old actor until the new
 * one is drawn. The search for a free record never advances the record
 * pointer, so only the first record is ever used (original code).
 */
void FLDMMDL_BLACT_ChangeObjCode(Mmdl *mmdl, unsigned int code)
{
    BlactSys *cont;
    int i;
    BlactCodeChange *change;
    unsigned short oldBlactId;
    unsigned short res[2]; /* [0] flags, [1] slot index */
    cont = FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl));
    change = cont->codeChanges;
    FLDMMDL_BLACT_FindRes(cont, code, &res[1], &res[0]);
    if (res[1] != 0xFFFF && !(res[0] & FLDMMDL_BLACT_RESBIT_TRANS)) {
        FLDMMDL_ChangeObjCode(mmdl, code);
        return;
    }
    i = 0;
    oldBlactId = FLDMMDL_CallDrawGetProc(mmdl, 0);
    if (oldBlactId == 0xFFFF) {
        FLDMMDL_ChangeObjCode(mmdl, code);
        return;
    }
    for (; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++) {
        if (change->mmdl == 0) {
            break;
        }
    }
    if (i >= FLDMMDL_BLACT_CODE_CHANGE_MAX) {
        FLDMMDL_ChangeObjCode(mmdl, code);
        return;
    }
    change->mmdl = mmdl;
    change->oldBlactId = oldBlactId;
    change->oldCode = FLDMMDL_GetObjCode(mmdl);
    change->newCode = code;
    FLDMMDL_ChangeObjCode(mmdl, code);
    i = 0;
    if (FLDMMDL_CallDrawGetProc(mmdl, 0) != 0xFFFF) {
        FLDMMDL_BLACT_DeleteActorRes(cont, mmdl, change->oldBlactId, change->oldCode);
        BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
    }
}

void FLDMMDL_BLACT_CreateCodeChange(BlactSys *cont)
{
    cont->codeChanges =
        GFL_HEAP_Alloc(FLDMMDL_SysGetHeapId(cont->mmdlSys), sizeof(BlactCodeChange) * FLDMMDL_BLACT_CODE_CHANGE_MAX, 1, (const char *)sBlactFileName, 0x979);
}

void FLDMMDL_BLACT_DeleteCodeChange(BlactSys *cont)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0) {
                BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, change->oldBlactId, 1);
                change->mmdl = 0;
            }
        }
        GFL_HEAP_Free(cont->codeChanges);
    }
}

/* Deletes the old actor once the model is gone or its new actor exists. */
void FLDMMDL_BLACT_UpdateCodeChange(BlactSys *cont, BlactCodeChange *change)
{
    Mmdl *mmdl;
    unsigned short oldCode;
    mmdl = change->mmdl;
    if (FLDMMDL_CheckStatusBitUse(mmdl, change) == 0) {
        FLDMMDL_BLACT_DeleteActorRes(cont, mmdl, change->oldBlactId, change->oldCode);
        BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
        return;
    }
    if ((unsigned short)FLDMMDL_CallDrawGetProc(mmdl, 0) != 0xFFFF) {
        oldCode = change->oldCode;
        if (oldCode != FLDMMDL_GetObjCode(mmdl)) {
            FLDMMDL_BLACT_DeleteActorRes(cont, mmdl, change->oldBlactId, oldCode);
        }
        BILLBOARD_ACT_DeleteEntries(cont->bbdActSys, change->oldBlactId, 1);
        change->mmdl = 0;
    }
}

void FLDMMDL_BLACT_UpdateCodeChanges(BlactSys *cont)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0) {
                FLDMMDL_BLACT_UpdateCodeChange(cont, change);
            }
        }
    }
}

int FLDMMDL_BLACT_IsCodeChangePending(BlactSys *cont, Mmdl *mmdl, u16 blactId)
{
    BlactCodeChange *change = cont->codeChanges;
    int i;
    if (change != 0) {
        for (i = 0; i < FLDMMDL_BLACT_CODE_CHANGE_MAX; i++, change++) {
            if (change->mmdl != 0 && change->mmdl == mmdl && change->oldBlactId == blactId) {
                return 1;
            }
        }
    }
    return 0;
}

BlactAnimeTable *FLDMMDL_BLACT_GetAnimeTable(int animId)
{
    return &sBlactAnimeTable[animId];
}

/* Adds an image slot for a resource: kept in VRAM (kind -1) or by request record. */
unsigned short FLDMMDL_BLACT_AddResSlot(BlactSys *cont, int code, int mdlSize, int texSize, void *resHandle, int kind)
{
    u16 *cellSize;
    struct BbActRec rec;
    if (kind == FLDMMDL_BLACT_SLOT_VRAM) {
        return (unsigned short)FLDMMDL_BLACT_AddVramSlot(cont->bbdActSys, resHandle, mdlSize, texSize);
    }
    rec.resource = (u32)resHandle;
    rec.format = 0;
    rec.sizeS = sBlactTexFmt[texSize];
    cellSize = sBlactCellSize[mdlSize];
    rec.sizeT = cellSize[0];
    rec.paletteId = cellSize[1];
    rec.kind = kind;
    return BILLBOARD_ACT_CreateSlots(cont->bbdActSys, &rec, 1);
}
