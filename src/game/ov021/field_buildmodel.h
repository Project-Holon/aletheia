#ifndef GAME_OV021_FIELD_BUILDMODEL_H
#define GAME_OV021_FIELD_BUILDMODEL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_buildmodel.c, prototypes copied from their definitions. */

struct BuildModelMan;
struct AreaData;
struct BuildModelPlacement;
struct VecFx32;
struct FieldG3dMap;
struct BuildModelObjectDesc;
struct BuildModelNode;
struct BuildModelHandleTable;
struct BuildModelSeason;
struct BuildModelModel;
struct BuildModelAnimSet;
struct BuildModelEntry;
struct BuildModelEntryArgs;
struct BuildModelSearchArgs;
struct BuildModelRect;
struct BuildModelBlock;
typedef struct BuildModelMan BuildModelMan;
typedef struct BuildModelPlacement BuildModelPlacement;
typedef struct BuildModelObjectDesc BuildModelObjectDesc;
typedef struct BuildModelNode BuildModelNode;
typedef struct BuildModelHandleTable BuildModelHandleTable;
typedef struct BuildModelSeason BuildModelSeason;
typedef struct BuildModelModel BuildModelModel;
typedef struct BuildModelAnimSet BuildModelAnimSet;
typedef struct BuildModelEntry BuildModelEntry;
typedef struct BuildModelEntryArgs BuildModelEntryArgs;
typedef struct BuildModelSearchArgs BuildModelSearchArgs;
typedef struct BuildModelRect BuildModelRect;
typedef struct BuildModelBlock BuildModelBlock;

#include "../types.h"

BuildModelMan *FIELD_BUILDMODEL_Create(u16 heapId, void *fieldMap, u16 dateKey);
void FIELD_BUILDMODEL_Delete(BuildModelMan *man);
void FIELD_BUILDMODEL_UpdateSeason(BuildModelMan *man);
void FIELD_BUILDMODEL_DrawNodes(BuildModelMan *man);
void FIELD_BUILDMODEL_LoadArea(BuildModelMan *man, int areaId, struct AreaData *mapHeader, void *extraResource);
BuildModelPlacement *FIELD_BUILDMODEL_GetPlacementByTableId(BuildModelMan *man, u32 tableId);
u8 *FIELD_BUILDMODEL_GetModelDef(BuildModelMan *man, u32 index);
int FIELD_BUILDMODEL_GetPlacementPosition(BuildModelMan *man, int tableId, struct VecFx32 *pos, int *modelIndex);
int FIELD_BUILDMODEL_RegisterObjects(BuildModelMan *man, struct FieldG3dMap *mapObject, const BuildModelObjectDesc *descs, int count);
void FIELD_BUILDMODEL_UnregisterObject(BuildModelMan *man, void *object);
void FIELD_BUILDMODEL_RegisterObject(BuildModelMan *man, struct FieldG3dMap *mapObject, const BuildModelObjectDesc *desc, int index);
void FIELD_BUILDMODEL_RemoveNode(BuildModelMan *man, BuildModelNode *node);
void FIELD_BUILDMODEL_AddNode(BuildModelMan *man, BuildModelNode *node);
void *FIELD_BUILDMODEL_GetNodeByHandle(BuildModelMan *man, int handle);
unsigned short FIELD_BUILDMODEL_GetNodeHandle(BuildModelMan *man, BuildModelNode *node);
BuildModelHandleTable *FIELD_BUILDMODEL_GetHandleTable(BuildModelMan *man);
void FIELD_BUILDMODEL_LoadModelArchive(BuildModelMan *man, u16 archiveId, u32 member);
int FIELD_BUILDMODEL_FreeModelArchive(BuildModelMan *man);
void FIELD_BUILDMODEL_BuildTableIndex(BuildModelMan *man, int defaultId);
int FIELD_BUILDMODEL_GetModelIndex(BuildModelMan *man, unsigned int tableId);
u8 *FIELD_BUILDMODEL_GetOffsetTarget(u8 *base, u32 index);
char *FIELD_BUILDMODEL_GetModelResourceData(char *table, int index);
u8 *FIELD_BUILDMODEL_GetAnimResourceData(u8 *table, int index);
unsigned short FIELD_BUILDMODEL_GetArchiveMemberIndex(int areaIndex);
void FIELD_BUILDMODEL_CreateG3dResources(BuildModelMan *man, int resourceId, int member, void *extraResource);
void FIELD_BUILDMODEL_DeleteG3dResources(BuildModelMan *man);
int FIELD_BUILDMODEL_CountAnimResources(int *animDefs);
u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *def);
unsigned char FIELD_BUILDMODEL_GetModelAnimKind(unsigned short *def);
void FIELD_BUILDMODEL_InitSeason(BuildModelSeason *season, u8 dateKey);
void FIELD_BUILDMODEL_UpdateSeasonState(BuildModelSeason *season);
u32 FIELD_BUILDMODEL_GetSeasonChanged(BuildModelSeason *season);
u8 FIELD_BUILDMODEL_GetSeasonAnimSlot(BuildModelSeason *season);
void FIELD_BUILDMODEL_CreateModels(BuildModelMan *man, void *extraResource);
void FIELD_BUILDMODEL_DeleteModels(BuildModelMan *man);
void FIELD_BUILDMODEL_CreateAnimSets(BuildModelMan *man, BuildModelHandleTable *out);
void FIELD_BUILDMODEL_DeleteAnimSets(BuildModelMan *man, BuildModelHandleTable *table);
void FIELD_BUILDMODEL_LoadModel(BuildModelMan *man, BuildModelModel *out, int index, void *unused);
void FIELD_BUILDMODEL_FreeModel(BuildModelModel *model);
void FIELD_BUILDMODEL_InitAnimSet(BuildModelMan *man, BuildModelAnimSet *out, BuildModelModel *model);
void FIELD_BUILDMODEL_InitAnimSetNone(void *man, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_InitAnimSetAll(void *man, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_InitAnimSetSeason(BuildModelMan *man, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_FreeAnimSet(BuildModelAnimSet *set);
void FIELD_BUILDMODEL_UpdateAnimSet(void *man, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_AnimSetKindDummy(void);
void FIELD_BUILDMODEL_UpdateAnimSetSeason(BuildModelMan *man, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_AdvanceAllSlots(int unused, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_UpdateAnimSetSlots(u32 unused, BuildModelAnimSet *set);
void FIELD_BUILDMODEL_StartGroupOpening(BuildModelAnimSet *set, int group);
void FIELD_BUILDMODEL_StartGroupLoop(BuildModelAnimSet *set, int group);
void FIELD_BUILDMODEL_StartGroupClosing(BuildModelAnimSet *set, int group);
void FIELD_BUILDMODEL_StopGroup(BuildModelAnimSet *set, int group);
void FIELD_BUILDMODEL_ResetAnimSet(BuildModelAnimSet *set);
void FIELD_BUILDMODEL_PlayAnimSet(BuildModelAnimSet *set, int slot, int mode);
void FIELD_BUILDMODEL_PlayGroup(BuildModelAnimSet *set, int group, int mode);
void FIELD_BUILDMODEL_AnimSetKindPlayDummy(void);
int FIELD_BUILDMODEL_IsSlotIdle(BuildModelAnimSet *set, int slot);
int FIELD_BUILDMODEL_GetSlotFrame(BuildModelAnimSet *set, int id);
void FIELD_BUILDMODEL_ClearEntry(void *unused, BuildModelEntry *entry);
BuildModelEntry *FIELD_BUILDMODEL_AddEntry(BuildModelMan *man, struct FieldG3dMap *mapObject, BuildModelEntryArgs *args, int index);
void FIELD_BUILDMODEL_RemoveEntriesByObject(BuildModelMan *man, void *object);
void FIELD_BUILDMODEL_FreeEntry(BuildModelMan *man, BuildModelEntry *entry);
u8 FIELD_BUILDMODEL_GetEntryModelId(BuildModelEntry *entry);
void FIELD_BUILDMODEL_SwapEntryModelId(BuildModelEntry *entry, int restore);
void FIELD_BUILDMODEL_GetModelIndexOut(BuildModelMan *man, BuildModelSearchArgs *args, int tableId);
BuildModelEntry **FIELD_BUILDMODEL_CollectEntriesInRect(BuildModelMan *man, BuildModelRect *rect, int kind, int *count);
BuildModelEntry *FIELD_BUILDMODEL_GetFirstEntryInRect(BuildModelMan *man, int kind, BuildModelRect *rect);
BuildModelEntry *FIELD_BUILDMODEL_GetFirstEntryNearPos(BuildModelMan *man, int kind, const struct VecFx32 *pos);
int FIELD_BUILDMODEL_GetEntryAnimKind(BuildModelMan *man, BuildModelEntry *entry);
void FIELD_BUILDMODEL_PlayEntryAnim(BuildModelMan *man, BuildModelEntry *entry, int slot, int mode);
void FIELD_BUILDMODEL_GetEntryWorldPos(BuildModelEntry *entry, void *out);
int FIELD_BUILDMODEL_GetEntrySlotFrame(BuildModelMan *man, BuildModelEntry *entry, int id);
BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromEntry(BuildModelMan *man, BuildModelEntry *entry);
BuildModelNode *FIELD_BUILDMODEL_CreateNodeNearPos(BuildModelMan *man, int kind, const struct VecFx32 *pos);
BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromBlock(BuildModelMan *man, u32 tableId, BuildModelBlock *src);
void FIELD_BUILDMODEL_DeleteNode(BuildModelNode *node);
void FIELD_BUILDMODEL_PlayNodeSlot(BuildModelNode *node, int slot, int mode);
void FIELD_BUILDMODEL_PlayNodeCurrentSlot(BuildModelNode *node, int mode);
int FIELD_BUILDMODEL_TryOpenNodeSlot(BuildModelNode *node, int slot);
int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(BuildModelNode *node);
int FIELD_BUILDMODEL_IsNodeSlotIdle(BuildModelNode *node, int slot);
int FIELD_BUILDMODEL_IsNodeCurrentSlotIdle(BuildModelNode *node);
unsigned short FIELD_BUILDMODEL_GetNodeModelKind(BuildModelNode *node);
void FIELD_BUILDMODEL_DrawNode(BuildModelNode *node);
int FIELD_BUILDMODEL_GetNodeKindTableEntry(BuildModelNode *node, u32 column, u16 *out);
int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(BuildModelNode *node, u16 *out);
int FIELD_BUILDMODEL_IsNodeSeBusy(BuildModelNode *node);
/* END mkheaders: generated region */

#endif
