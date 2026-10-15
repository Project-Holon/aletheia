/*
 * file:     field_effect.c
 * unit:     yes
 * function: FIELD_EFFECT_Create, FIELD_EFFECT_Delete, FIELD_EFFECT_Update, FIELD_EFFECT_Draw, FIELD_EFFECT_GetFieldMap, FIELD_EFFECT_GetFieldMapData, FIELD_EFFECT_GetArcHandle, FIELD_EFFECT_GetModelBaseOffset, FIELD_EFFECT_GetModelBaseOffsetAlt, FIELD_EFFECT_LoadResources, FIELD_EFFECT_FreeResource, FIELD_EFFECT_IsResourceLoaded, FIELD_EFFECT_GetResource, FIELD_EFFECT_InitResourceTable, FIELD_EFFECT_FreeResourceTable, FIELD_EFFECT_FindResourceSlot, FIELD_EFFECT_GetResourceDef, FIELD_EFFECT_InitObjectSystem, FIELD_EFFECT_AddObject, FIELD_EFFECT_ExitObjectSystem, FIELD_EFFECT_RunTasks, FIELD_EFFECT_DrawObjects, FIELD_EFFECT_CreateObjectMgr, FIELD_EFFECT_DeleteObjectMgr, FIELD_EFFECT_DrawObjectMgr, FIELD_EFFECT_AddObjectToMgr, FIELD_EFFECT_ObjectTask, FIELD_EFFECT_InitObject, FIELD_EFFECT_DeleteObject, FIELD_EFFECT_UpdateObject, FIELD_EFFECT_DrawObject, FIELD_EFFECT_GetObjectMode, FIELD_EFFECT_GetObjectParam, FIELD_EFFECT_GetObjectPos, FIELD_EFFECT_SetObjectPos, FIELD_EFFECT_GetObjectWork, FIELD_EFFECT_SetPaletteTable, FIELD_EFFECT_ApplyPaletteTable
 * address:  0x021ABD50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021ABD50: __FILE__ field_effect.c on 0x021ABD50 (create, first
 * function), 0x021ABEAC, 0x021ABF68, 0x021ABFFC.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   FIELDMAP_GetAreaData  0x02188D58  thumb  ov021
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetField25  0x0204EDBC  arm
 *   BILLBOARD_SetField10  0x0204ED70  arm
 *   BILLBOARD_SetField24  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 *   FIELDMAP_GetG3dObjCtrl  0x02188CD8  thumb  ov021
 *   gFieldEffectResourceDefs  0x021D8F60  data  a4
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   TCB_Noop  0x02030DA4  arm
 *   TCB_Main  0x02030D28  arm
 *   PALANM_ConvertGrayTable  0x02022040  thumb
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm  arm9
 *   NNS_G3dGetTex  0x0206E964  arm  arm9
 */
#include "field_effect_types.h"

typedef struct PaletteResource {
    u8 pad00[0x30];
    u16 palSize;
    u16 pad32;
    u32 pad34;
    u32 palOffset;
} PaletteResource;

extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);
extern u32 func_020307B0(void *p);
extern u32 MI_CpuFill8(void *p, int v, int n);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 ZONEDATA_GetAreaId(u32 id);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
extern u32 FIELDMAP_GetAreaData(u8 *p);
extern u8 ZONEDATA_GetAreaInnerOuter(void *p);
extern u32 FIELDMAP_GetEffectBbdAct(u8 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetField25(u8 *dst, u8 val);
extern void BILLBOARD_SetField10(u8 *dst, VecFx32 *src);
extern void BILLBOARD_SetField24(u8 *dst, u8 *src);
extern u32 FIELDMAP_GetG3dObjCtrl(u8 *p);
extern u32 func_02030CB0(u32 idx);
extern int func_02030CBC(u32 capacity, void *buffer);
extern void TCB_Noop(int a);
extern void TCB_Main(int taskSys);
extern void *func_02030DA8(u32 taskSys, void (*cb)(void), void *arg, u32 pri);
extern void func_02030EAC(void *tcb);
extern void *G3D_SYSTEM_GetResourceFile(void *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);

FieldEffectSys *FIELD_EFFECT_Create(void *fieldmap, int resourceCount, u16 heapId);
int FIELD_EFFECT_Delete(FieldEffectSys *sys, u32 unused0, u32 unused1, u32 unused2);
void FIELD_EFFECT_Update(FieldEffectSys *sys);
void FIELD_EFFECT_Draw(FieldEffectSys *sys);
u32 FIELD_EFFECT_GetFieldMap(FieldEffectSys *sys);
u32 FIELD_EFFECT_GetFieldMapData(FieldEffectSys *sys);
u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *sys);
u8 FIELD_EFFECT_GetModelBaseOffset(FieldEffectSys *sys);
u8 FIELD_EFFECT_GetModelBaseOffsetAlt(FieldEffectSys *sys);
void FIELD_EFFECT_LoadResources(FieldEffectSys *sys, int *ids, int count);
void FIELD_EFFECT_FreeResource(FieldEffectSys *sys, int id);
int FIELD_EFFECT_IsResourceLoaded(FieldEffectSys *sys, int id);
int FIELD_EFFECT_GetResource(FieldEffectSys *sys, int id);
void FIELD_EFFECT_InitResourceTable(FieldEffectSys *sys);
void FIELD_EFFECT_FreeResourceTable(FieldEffectSys *sys);
FieldEffectResource *FIELD_EFFECT_FindResourceSlot(FieldEffectSys *sys, int id);
FieldEffectResourceDef *FIELD_EFFECT_GetResourceDef(int id);
void FIELD_EFFECT_InitObjectSystem(FieldEffectSys *sys, int objectCount);
void FIELD_EFFECT_AddObject(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void FIELD_EFFECT_ExitObjectSystem(FieldEffectSys *sys);
void FIELD_EFFECT_RunTasks(FieldEffectSys *sys);
void FIELD_EFFECT_DrawObjects(FieldEffectSys *sys);
FieldEffectObjMgr *FIELD_EFFECT_CreateObjectMgr(u16 heapId, int taskSys, int objectCount);
void FIELD_EFFECT_DeleteObjectMgr(FieldEffectObjMgr *mgr);
void FIELD_EFFECT_DrawObjectMgr(FieldEffectObjMgr *mgr);
FieldEffectObj *FIELD_EFFECT_AddObjectToMgr(FieldEffectObjMgr *mgr, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void FIELD_EFFECT_ObjectTask(u32 task, FieldEffectObj *obj);
void FIELD_EFFECT_InitObject(FieldEffectObj *obj);
void FIELD_EFFECT_DeleteObject(FieldEffectObj *obj);
void FIELD_EFFECT_UpdateObject(FieldEffectObj *obj);
void FIELD_EFFECT_DrawObject(FieldEffectObj *obj);
int FIELD_EFFECT_GetObjectMode(FieldEffectObj *obj);
void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *obj);
void FIELD_EFFECT_GetObjectPos(FieldEffectObj *obj, VecFx32 *out);
void FIELD_EFFECT_SetObjectPos(FieldEffectObj *obj, const VecFx32 *pos);
void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *obj);
void FIELD_EFFECT_SetPaletteTable(FieldEffectSys *sys, u32 paletteTable);
void FIELD_EFFECT_ApplyPaletteTable(FieldEffectSys *sys, void *model);
extern char d_021DE018[];
extern VecFx32 d_021D8F04;
extern FieldEffectResourceDef gFieldEffectResourceDefs[];

FieldEffectSys *FIELD_EFFECT_Create(void *fieldmap, int resourceCount, u16 heapId)
{
    FieldEffectSys *sys;
    int billboard;
    VecFx32 vec;
    u8 zero;

    sys = func_02030734(heapId, 0x28, 1, d_021DE018, 0x7e);
    sys->resourceCount = resourceCount;
    sys->heapId = heapId;
    sys->fieldmap = fieldmap;
    sys->arcHandle = (int)func_020490F4(0x4b, heapId);
    ZONEDATA_GetAreaId(FIELDMAP_GetZoneId((u8 *)fieldmap));
    sys->modelBaseOffset = COMM_PLAYER_SUPPORT_GetInfoCode(FIELDMAP_GetGameSystem(fieldmap));
    sys->modelBaseOffsetAlt = ZONEDATA_GetAreaInnerOuter((void *)FIELDMAP_GetAreaData((u8 *)fieldmap));
    FIELD_EFFECT_InitResourceTable(sys);
    billboard = BILLBOARD_ACT_GetBoard((u32 *)FIELDMAP_GetEffectBbdAct((u8 *)sys->fieldmap));
    BILLBOARD_SetField25((u8 *)billboard, 0);
    vec = d_021D8F04;
    BILLBOARD_SetField10((u8 *)billboard, &vec);
    zero = 0;
    BILLBOARD_SetField24((u8 *)billboard, &zero);
    return sys;
}

int FIELD_EFFECT_Delete(FieldEffectSys *sys, u32 unused0, u32 unused1, u32 unused2)
{
    FIELD_EFFECT_ExitObjectSystem(sys);
    FIELD_EFFECT_FreeResourceTable(sys);
    ARC_TOOL_DeleteHandle((void *)sys->arcHandle);
    return func_020307B0(sys);
}

void FIELD_EFFECT_Update(FieldEffectSys *sys)
{
    FIELD_EFFECT_RunTasks(sys);
}

void FIELD_EFFECT_Draw(FieldEffectSys *sys)
{
    FIELD_EFFECT_DrawObjects(sys);
}

u32 FIELD_EFFECT_GetFieldMap(FieldEffectSys *sys)
{
    return (u32)sys->fieldmap;
}

u32 FIELD_EFFECT_GetFieldMapData(FieldEffectSys *sys)
{
    return FIELDMAP_GetG3dObjCtrl((u8 *)sys->fieldmap);
}

u32 FIELD_EFFECT_GetArcHandle(FieldEffectSys *sys)
{
    return sys->arcHandle;
}

u8 FIELD_EFFECT_GetModelBaseOffset(FieldEffectSys *sys)
{
    return sys->modelBaseOffset;
}

u8 FIELD_EFFECT_GetModelBaseOffsetAlt(FieldEffectSys *sys)
{
    return sys->modelBaseOffsetAlt;
}

void FIELD_EFFECT_LoadResources(FieldEffectSys *sys, int *ids, int count)
{
    FieldEffectResource *slot;
    FieldEffectResourceDef *def;

    for (; count != 0; count--) {
        slot = FIELD_EFFECT_FindResourceSlot(sys, 0x18);
        def = FIELD_EFFECT_GetResourceDef(*ids);
        slot->id = *ids;
        slot->handle = def->load(sys, sys->heapId);
        ids++;
    }
}

void FIELD_EFFECT_FreeResource(FieldEffectSys *sys, int id)
{
    FieldEffectResource *slot = FIELD_EFFECT_FindResourceSlot(sys, id);
    FieldEffectResourceDef *def;

    if (slot != 0) {
        def = FIELD_EFFECT_GetResourceDef(id);
        def->unload(sys, slot->handle);
        slot->id = 0x18;
        slot->handle = 0;
    }
}

int FIELD_EFFECT_IsResourceLoaded(FieldEffectSys *sys, int id)
{
    if (FIELD_EFFECT_FindResourceSlot(sys, id) != 0) {
        return 1;
    }
    return 0;
}

int FIELD_EFFECT_GetResource(FieldEffectSys *sys, int id)
{
    return FIELD_EFFECT_FindResourceSlot(sys, id)->handle;
}

void FIELD_EFFECT_InitResourceTable(FieldEffectSys *sys)
{
    FieldEffectResource *slot;
    int i;

    slot = sys->resources = func_02030734(sys->heapId, sys->resourceCount * 8, 1, d_021DE018, 0x174);
    i = 0;
    if (sys->resourceCount > 0) {
        for (; i < sys->resourceCount; i++) {
            slot->id = 0x18;
            slot++;
        }
    }
}

void FIELD_EFFECT_FreeResourceTable(FieldEffectSys *sys)
{
    int i;
    FieldEffectResource *slot;

    i = 0;
    slot = sys->resources;
    if (i < sys->resourceCount) {
        for (; i < sys->resourceCount; i++, slot++) {
            if (slot->id != 0x18) {
                FIELD_EFFECT_GetResourceDef(slot->id)->unload(sys, slot->handle);
                slot->id = 0x18;
                slot->handle = 0;
            }
        }
    }
    func_020307B0(sys->resources);
    sys->resources = 0;
}

FieldEffectResource *FIELD_EFFECT_FindResourceSlot(FieldEffectSys *sys, int id)
{
    int n = sys->resourceCount;
    FieldEffectResource *slot = sys->resources;

    while (n != 0) {
        if (slot->id == id) {
            return slot;
        }
        n--;
        slot++;
    }
    return 0;
}

FieldEffectResourceDef *FIELD_EFFECT_GetResourceDef(int id)
{
    int i;
    FieldEffectResourceDef *def = gFieldEffectResourceDefs;

    for (i = 0; i < 0x18; i++) {
        if (def->id == id) {
            return def;
        }
        def++;
    }
    return def;
}

void FIELD_EFFECT_InitObjectSystem(FieldEffectSys *sys, int objectCount)
{
    sys->objectCount = objectCount;
    sys->taskBuffer = func_02030734(sys->heapId, func_02030CB0(objectCount), 0, d_021DE018, 0x1db);
    sys->taskSys = func_02030CBC(objectCount, sys->taskBuffer);
    sys->objMgr = FIELD_EFFECT_CreateObjectMgr(sys->heapId, sys->taskSys, objectCount);
}

void FIELD_EFFECT_AddObject(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority)
{
    FIELD_EFFECT_AddObjectToMgr(sys->objMgr, funcs, pos, mode, param, priority);
}

void FIELD_EFFECT_ExitObjectSystem(FieldEffectSys *sys)
{
    if (sys->objMgr != 0) {
        FIELD_EFFECT_DeleteObjectMgr(sys->objMgr);
        TCB_Noop(sys->taskSys);
        func_020307B0(sys->taskBuffer);
    }
}

void FIELD_EFFECT_RunTasks(FieldEffectSys *sys)
{
    if (sys->taskSys != 0) {
        TCB_Main(sys->taskSys);
    }
}

void FIELD_EFFECT_DrawObjects(FieldEffectSys *sys)
{
    if (sys->objMgr != 0) {
        FIELD_EFFECT_DrawObjectMgr(sys->objMgr);
    }
}

FieldEffectObjMgr *FIELD_EFFECT_CreateObjectMgr(u16 heapId, int taskSys, int objectCount)
{
    FieldEffectObjMgr *mgr;

    mgr = func_02030734(heapId, 0x10, 1, d_021DE018, 0x23a);
    mgr->count = objectCount;
    mgr->heapId = heapId;
    mgr->objs = func_02030734(heapId, objectCount * 0xd4, 1, d_021DE018, 0x23e);
    mgr->taskSys = taskSys;
    return mgr;
}

void FIELD_EFFECT_DeleteObjectMgr(FieldEffectObjMgr *mgr)
{
    u32 i;

    for (i = 0; i < mgr->count; i++) {
        if (mgr->objs[i].active != 0) {
            FIELD_EFFECT_DeleteObject(&mgr->objs[i]);
        }
    }
    func_020307B0(mgr->objs);
    func_020307B0(mgr);
}

void FIELD_EFFECT_DrawObjectMgr(FieldEffectObjMgr *mgr)
{
    u32 i;

    for (i = 0; i < mgr->count; i++) {
        if (mgr->objs[i].active != 0)
            FIELD_EFFECT_DrawObject(&mgr->objs[i]);
    }
}

FieldEffectObj *FIELD_EFFECT_AddObjectToMgr(FieldEffectObjMgr *mgr, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority)
{
    u32 i = 0;
    FieldEffectObj *obj = mgr->objs;

    do {
        if (obj->active == 0) {
            MI_CpuFill8(obj, 0, sizeof(FieldEffectObj));
            obj->active = 1;
            obj->funcs = *funcs;
            obj->mode = mode;
            obj->param = param;
            if (pos != 0)
                obj->pos = *pos;
            obj->mgr = mgr;
            obj->task = func_02030DA8(mgr->taskSys, (void (*)(void))FIELD_EFFECT_ObjectTask, obj, priority);
            break;
        }
        i++;
        obj++;
    } while (i < mgr->count);
    if (i < mgr->count) {
        FIELD_EFFECT_InitObject(obj);
        return obj;
    }
    return 0;
}

void FIELD_EFFECT_ObjectTask(u32 task, FieldEffectObj *obj)
{
    FIELD_EFFECT_UpdateObject(obj);
}

void FIELD_EFFECT_InitObject(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.init(obj, obj->work);
}

void FIELD_EFFECT_DeleteObject(FieldEffectObj *obj)
{
    if (obj != 0) {
        obj->funcs.exit(obj, obj->work);
        func_02030EAC(obj->task);
        obj->active = 0;
    }
}

void FIELD_EFFECT_UpdateObject(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.update(obj, obj->work);
}

void FIELD_EFFECT_DrawObject(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.draw(obj, obj->work);
}

int FIELD_EFFECT_GetObjectMode(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->mode;
    }
    return 0;
}

void *FIELD_EFFECT_GetObjectParam(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->param;
    }
    return 0;
}

void FIELD_EFFECT_GetObjectPos(FieldEffectObj *obj, VecFx32 *out)
{
    if (obj != 0)
        *out = obj->pos;
}

void FIELD_EFFECT_SetObjectPos(FieldEffectObj *obj, const VecFx32 *pos)
{
    if (obj != 0)
        obj->pos = *pos;
}

void *FIELD_EFFECT_GetObjectWork(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->work;
    }
    return 0;
}

void FIELD_EFFECT_SetPaletteTable(FieldEffectSys *sys, u32 paletteTable)
{
    sys->paletteTable = paletteTable;
}

void FIELD_EFFECT_ApplyPaletteTable(FieldEffectSys *sys, void *model)
{
    PaletteResource *res;

    if (sys->paletteTable != 0) {
        res = (PaletteResource *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(model));
        PALANM_ConvertGrayTable((u16 *)((u8 *)res + res->palOffset), res->palSize * 8u / 2, (const u8 *)sys->paletteTable);
    }
}
