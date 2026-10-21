#ifndef GAME_OV021_FIELD_EFFECT_H
#define GAME_OV021_FIELD_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_effect.c, prototypes copied from their definitions. */

struct FieldMap;
struct FieldG3dObjCtrl;
struct ArcHandle;
struct TcbSystem;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FieldEffectSys *FIELD_EFFECT_Create(void *fieldmap, int resourceCount, u16 heapId);
int FIELD_EFFECT_Delete(FieldEffectSys *sys);
void FIELD_EFFECT_Update(FieldEffectSys *sys);
void FIELD_EFFECT_Draw(FieldEffectSys *sys);
struct FieldMap *FIELD_EFFECT_GetFieldMap(FieldEffectSys *sys);
struct FieldG3dObjCtrl *FIELD_EFFECT_GetFieldMapData(FieldEffectSys *sys);
struct ArcHandle *FIELD_EFFECT_GetArcHandle(FieldEffectSys *sys);
u8 FIELD_EFFECT_GetModelBaseOffset(FieldEffectSys *sys);
u8 FIELD_EFFECT_GetModelBaseOffsetAlt(FieldEffectSys *sys);
void FIELD_EFFECT_LoadResources(FieldEffectSys *sys, int *ids, int count);
void FIELD_EFFECT_FreeResource(FieldEffectSys *sys, int id);
int FIELD_EFFECT_IsResourceLoaded(FieldEffectSys *sys, int id);
void *FIELD_EFFECT_GetResource(FieldEffectSys *sys, int id);
void FIELD_EFFECT_InitResourceTable(FieldEffectSys *sys);
void FIELD_EFFECT_FreeResourceTable(FieldEffectSys *sys);
FieldEffectResource *FIELD_EFFECT_FindResourceSlot(FieldEffectSys *sys, int id);
FieldEffectResourceDef *FIELD_EFFECT_GetResourceDef(int id);
void FIELD_EFFECT_InitObjectSystem(FieldEffectSys *sys, int objectCount);
FieldEffectObj *FIELD_EFFECT_AddObject(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void FIELD_EFFECT_ExitObjectSystem(FieldEffectSys *sys);
void FIELD_EFFECT_RunTasks(FieldEffectSys *sys);
void FIELD_EFFECT_DrawObjects(FieldEffectSys *sys);
FieldEffectObjMgr *FIELD_EFFECT_CreateObjectMgr(u16 heapId, struct TcbSystem *taskSys, int objectCount);
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
void FIELD_EFFECT_SetPaletteTable(FieldEffectSys *sys, const u8 *paletteTable);
void FIELD_EFFECT_ApplyPaletteTable(FieldEffectSys *sys, void *model);
/* END mkheaders: generated region */

#endif
