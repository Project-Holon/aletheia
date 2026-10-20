/*
 * file:     field_buildmodel.c
 * unit:     yes
 * function: FIELD_BUILDMODEL_Create, FIELD_BUILDMODEL_Delete, FIELD_BUILDMODEL_UpdateSeason, FIELD_BUILDMODEL_DrawNodes, FIELD_BUILDMODEL_LoadArea, FIELD_BUILDMODEL_GetPlacementByTableId, FIELD_BUILDMODEL_GetModelDef, FIELD_BUILDMODEL_GetPlacementPosition, FIELD_BUILDMODEL_RegisterObjects, FIELD_BUILDMODEL_UnregisterObject, FIELD_BUILDMODEL_RegisterObject, FIELD_BUILDMODEL_RemoveNode, FIELD_BUILDMODEL_AddNode, FIELD_BUILDMODEL_GetNodeByHandle, FIELD_BUILDMODEL_GetNodeHandle, FIELD_BUILDMODEL_GetHandleTable, FIELD_BUILDMODEL_LoadModelArchive, FIELD_BUILDMODEL_FreeModelArchive, FIELD_BUILDMODEL_BuildTableIndex, FIELD_BUILDMODEL_GetModelIndex, FIELD_BUILDMODEL_GetOffsetTarget, FIELD_BUILDMODEL_GetModelResourceData, FIELD_BUILDMODEL_GetAnimResourceData, FIELD_BUILDMODEL_GetArchiveMemberIndex, FIELD_BUILDMODEL_CreateG3dResources, FIELD_BUILDMODEL_DeleteG3dResources, FIELD_BUILDMODEL_CountAnimResources, FIELD_BUILDMODEL_GetModelAnimDefs, FIELD_BUILDMODEL_GetModelAnimKind, FIELD_BUILDMODEL_InitSeason, FIELD_BUILDMODEL_UpdateSeasonState, FIELD_BUILDMODEL_GetSeasonChanged, FIELD_BUILDMODEL_GetSeasonAnimSlot, FIELD_BUILDMODEL_CreateModels, FIELD_BUILDMODEL_DeleteModels, FIELD_BUILDMODEL_CreateAnimSets, FIELD_BUILDMODEL_DeleteAnimSets, FIELD_BUILDMODEL_LoadModel, FIELD_BUILDMODEL_FreeModel, FIELD_BUILDMODEL_InitAnimSet, FIELD_BUILDMODEL_InitAnimSetNone, FIELD_BUILDMODEL_InitAnimSetAll, FIELD_BUILDMODEL_InitAnimSetSeason, FIELD_BUILDMODEL_FreeAnimSet, FIELD_BUILDMODEL_UpdateAnimSet, FIELD_BUILDMODEL_AnimSetKindDummy, FIELD_BUILDMODEL_UpdateAnimSetSeason, FIELD_BUILDMODEL_AdvanceAllSlots, FIELD_BUILDMODEL_UpdateAnimSetSlots, FIELD_BUILDMODEL_StartGroupOpening, FIELD_BUILDMODEL_StartGroupLoop, FIELD_BUILDMODEL_StartGroupClosing, FIELD_BUILDMODEL_StopGroup, FIELD_BUILDMODEL_ResetAnimSet, FIELD_BUILDMODEL_PlayAnimSet, FIELD_BUILDMODEL_PlayGroup, FIELD_BUILDMODEL_AnimSetKindPlayDummy, FIELD_BUILDMODEL_IsSlotIdle, FIELD_BUILDMODEL_GetSlotFrame, FIELD_BUILDMODEL_ClearEntry, FIELD_BUILDMODEL_AddEntry, FIELD_BUILDMODEL_RemoveEntriesByObject, FIELD_BUILDMODEL_FreeEntry, FIELD_BUILDMODEL_GetEntryModelId, FIELD_BUILDMODEL_SwapEntryModelId, FIELD_BUILDMODEL_GetModelIndexOut, FIELD_BUILDMODEL_CollectEntriesInRect, FIELD_BUILDMODEL_GetFirstEntryInRect, FIELD_BUILDMODEL_GetFirstEntryNearPos, FIELD_BUILDMODEL_GetEntryAnimKind, FIELD_BUILDMODEL_PlayEntryAnim, FIELD_BUILDMODEL_GetEntryWorldPos, FIELD_BUILDMODEL_GetEntrySlotFrame, FIELD_BUILDMODEL_CreateNodeFromEntry, FIELD_BUILDMODEL_CreateNodeNearPos, FIELD_BUILDMODEL_CreateNodeFromBlock, FIELD_BUILDMODEL_DeleteNode, FIELD_BUILDMODEL_PlayNodeSlot, FIELD_BUILDMODEL_PlayNodeCurrentSlot, FIELD_BUILDMODEL_TryOpenNodeSlot, FIELD_BUILDMODEL_TryOpenNodeCurrentSlot, FIELD_BUILDMODEL_IsNodeSlotIdle, FIELD_BUILDMODEL_IsNodeCurrentSlotIdle, FIELD_BUILDMODEL_GetNodeModelKind, FIELD_BUILDMODEL_DrawNode, FIELD_BUILDMODEL_GetNodeKindTableEntry, FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry, FIELD_BUILDMODEL_IsNodeSeBusy, FIELD_BUILDMODEL_MakeSearchRect
 * address:  0x0218B754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218B754: field_buildmodel.c __FILE__ anchor in its allocation call.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gBuildModelFileName     0x021DD9CC  data  ov021  a4
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_TransVramTextureAndCut  0x020470A8  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   gBuildModelAnimKindTable     0x021D3DC4  data  a4
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 *   gBuildModelSeasonAnimSlot     0x021D3D50  data  a4
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   gBuildModelAnimInitTable     0x021D3D58  data   a4
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   gBuildModelAnimOpsTable     0x021D3D5C  data  a4
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_GetAnimeObj  0x02047674  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   FIELD_G3D_MAP_SetPlacement  0x021693D4  thumb  ov010
 *   FIELD_G3D_MAP_GetPlacement  0x02169444  thumb  ov010
 *   FIELD_G3D_MAP_ClearPlacement  0x0216940C  thumb
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb
 *   VEC_Add  0x0207C9D0  arm
 *   MTX_RotY33_  0x0207AF1C  thumb
 *   FX_SinCosTable_     0x020A1B38  data   a2
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   gBuildModelKindTable     0x021D3D88  data   a2
 *   d_021D3D8A     0x021D3D8A  data   a2
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FIELD_G3D_MAPPER_TintTexture  0x0218D0D8  thumb  ov021
 *   FIELD_G3D_MAPPER_GetOriginOffset  0x0218DC5C  thumb  ov021
 */
#include "../sdk_fx.h"
#include "../types.h"

struct Sub020140BCObj;
struct ArcFile;
struct Tagged;
struct S02046CE0;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct AnmCtl;
struct Owner;
struct Arg;

#define BUILDMODEL_NODE_COUNT    7
#define BUILDMODEL_ENTRY_COUNT   0x120
#define BUILDMODEL_ANIM_SLOTS    4
#define BUILDMODEL_TABLE_ID_MAX  0x190

/* Per-slot states of a model animation set. */
enum {
    BUILDMODEL_SLOT_NONE = 0,
    BUILDMODEL_SLOT_LOOP = 1,
    BUILDMODEL_SLOT_HOLD = 2,
    BUILDMODEL_SLOT_OPENING = 3,
    BUILDMODEL_SLOT_CLOSING = 4
};

/* Season state, 0x10 bytes at BuildModelMan.season. */
typedef struct BuildModelSeason {
    int season;
    int prevSeason;
    int changed;
    unsigned char animSlot;
    unsigned char dateKey;
} BuildModelSeason;

/* Placement record in the model archive (map units are whole tiles). */
typedef struct BuildModelPlacement {
    int unused;
    unsigned short modelId;
    short tileX;
    short tileY;
    short tileZ;
} BuildModelPlacement;

/* Object description handed in by the map loader, 0x10 bytes. */
typedef struct BuildModelObjectDesc {
    int x;
    int y;
    int z;
    unsigned short rotation;
    unsigned char idHigh;
    unsigned char idLow;
} BuildModelObjectDesc;

/* Arguments for BuildModel entry creation. */
typedef struct BuildModelEntryArgs {
    int modelIndex;
    struct VecFx32 pos;
    unsigned short rotation;
} BuildModelEntryArgs;

/* Same arguments with the position flattened, as built by RegisterObject. */
typedef struct BuildModelEntryArgsFlat {
    int modelIndex;
    int x;
    int y;
    int z;
    unsigned short rotation;
} BuildModelEntryArgsFlat;

/* Map object data of one placed model (read from the map object record). */
typedef struct BuildModelInstance {
    unsigned int modelId;
    struct VecFx32 pos;
    unsigned short facing;
} BuildModelInstance;

/* One placed model instance, 16 bytes, table at BuildModelMan.entries. */
typedef struct BuildModelEntry {
    void *object;
    int savedWord;
    unsigned short index;
    unsigned short visible;
    BuildModelInstance *instance;
} BuildModelEntry;

typedef struct BuildModelKindTable {
    unsigned char kind[16];
} BuildModelKindTable;

/* Anim set: one G3D animation handle plus per-slot states, 0x18 bytes. */
typedef struct BuildModelAnimSet {
    void *anim;
    struct BuildModelModel *model;
    u32 slotState[BUILDMODEL_ANIM_SLOTS];
} BuildModelAnimSet;

/* Per-model resources: definition plus model and four animation blocks, 0x18 bytes. */
typedef struct BuildModelModel {
    u8 *def;
    void *resource;
    void *animResource[BUILDMODEL_ANIM_SLOTS];
} BuildModelModel;

typedef void (*BuildModelAnimInitFn)(void *man, BuildModelAnimSet *set);

/* Animation kind callbacks (gBuildModelAnimInitTable view: first slot). */
typedef struct BuildModelAnimInit {
    BuildModelAnimInitFn init;
    u32 reserved[2];
} BuildModelAnimInit;

/* Animation kind callbacks (gBuildModelAnimOpsTable view: second and third slot). */
typedef struct BuildModelAnimOps {
    void (*update)(void *man, void *set);
    void (*play)(void *set, int slot, int mode);
    void (*reserved)(void);
} BuildModelAnimOps;

typedef struct BuildModelSearchArgs {
    int reserved[3];
    int *outIndex;
} BuildModelSearchArgs;

/* Search rectangle, in 20.12 fixed point. */
typedef struct BuildModelRect {
    int zMin;
    int zMax;
    int xMin;
    int xMax;
} BuildModelRect;

typedef struct BuildModelBlock {
    u32 w[15];
} BuildModelBlock;

/* Table of live anim set handles at BuildModelMan.handleTable, 0x18 bytes. */
typedef struct BuildModelHandleTable {
    u32 (*handles)[2];
    u32 count;
    void *extra;
    u32 reserved[3];
} BuildModelHandleTable;

/* A placed model node, 0x60 bytes. */
typedef struct BuildModelNode {
    struct BuildModelMan *man;
    unsigned int slot;
    BuildModelEntry *entry;
    BuildModelAnimSet animSet;
    struct VecFx32 pos;
    int scaleX;
    int scaleY;
    int scaleZ;
    union MtxFx33 matrix;
} BuildModelNode;

/* The build model manager, 0x13F8 bytes. */
typedef struct BuildModelMan {
    unsigned short heapId;
    unsigned short pad02;
    void *fieldMap;
    BuildModelSeason season;
    u8 *archive;
    unsigned char tableToIndex[BUILDMODEL_TABLE_ID_MAX];
    unsigned short modelCount;
    u8 pad1AE[2];
    BuildModelHandleTable handleTable;
    unsigned int modelInfoCount;
    BuildModelModel *modelInfos;
    void *g3dResources;
    unsigned int animSetCount;
    BuildModelAnimSet *animSets;
    BuildModelNode *nodes[BUILDMODEL_NODE_COUNT];
    BuildModelEntry entries[BUILDMODEL_ENTRY_COUNT];
} BuildModelMan;

#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/zonedata.h"
struct AreaData;
#include "../arm9/arc_tool.h"
struct ArcHandle;
struct G3dResource;
#include "../arm9/g3d_system.h"
#include "../arm9/timezone.h"
extern void G3D_SYSTEM_InitResourceByFile(struct S02046CE0 *out, u32 *tag);
struct G3dRender;
struct G3dAnime;
struct G3dObject;
struct FieldG3dMapPlacement;
struct FieldG3dMap;
#include "../ov010/field_g3d_map.h"
struct VecFx32;
#include "../arm9/fx_vec.h"
#include "../arm9/fx_mtx33.h"
struct G3dObjectStatus;
#include "../arm9/gfl_use.h"
BuildModelMan *FIELD_BUILDMODEL_Create(u16 heapId, void *fieldMap, u16 dateKey);
void FIELD_BUILDMODEL_Delete(BuildModelMan *man);
void FIELD_BUILDMODEL_UpdateSeason(BuildModelMan *man);
void FIELD_BUILDMODEL_DrawNodes(BuildModelMan *man);
void FIELD_BUILDMODEL_LoadArea(BuildModelMan *man, int areaId, int mapHeader, int extraResource);
int FIELD_BUILDMODEL_GetPlacementByTableId(BuildModelMan *man, u32 modelId);
u8 *FIELD_BUILDMODEL_GetModelDef(BuildModelMan *man, u32 index);
int FIELD_BUILDMODEL_GetPlacementPosition(BuildModelMan *man, int modelId, struct VecFx32 *pos, int *modelIndex);
int FIELD_BUILDMODEL_RegisterObjects(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *descs, int count);
void FIELD_BUILDMODEL_UnregisterObject(BuildModelMan *man, void *object);
void FIELD_BUILDMODEL_RegisterObject(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *desc, int index);
void FIELD_BUILDMODEL_RemoveNode(BuildModelMan *man, BuildModelNode *node);
void FIELD_BUILDMODEL_AddNode(BuildModelMan *man, BuildModelNode *node);
void *FIELD_BUILDMODEL_GetNodeByHandle(BuildModelMan *man, int handle);
unsigned short FIELD_BUILDMODEL_GetNodeHandle(BuildModelMan *man, BuildModelNode *node);
BuildModelHandleTable *FIELD_BUILDMODEL_GetHandleTable(BuildModelMan *man);
void FIELD_BUILDMODEL_LoadModelArchive(BuildModelMan *man, u16 archiveId, u32 member);
int FIELD_BUILDMODEL_FreeModelArchive(BuildModelMan *man);
void FIELD_BUILDMODEL_BuildTableIndex(BuildModelMan *man, int defaultId);
int FIELD_BUILDMODEL_GetModelIndex(BuildModelMan *man, unsigned int tableId);
int FIELD_BUILDMODEL_GetOffsetTarget(u32 base, u32 index);
char *FIELD_BUILDMODEL_GetModelResourceData(char *table, int index);
u8 *FIELD_BUILDMODEL_GetAnimResourceData(u8 *table, int index);
unsigned short FIELD_BUILDMODEL_GetArchiveMemberIndex(int areaIndex);
void FIELD_BUILDMODEL_CreateG3dResources(BuildModelMan *man, int resourceId, int member, int extraResource);
void FIELD_BUILDMODEL_DeleteG3dResources(BuildModelMan *man);
int FIELD_BUILDMODEL_CountAnimResources(int *animDefs);
u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);
unsigned char FIELD_BUILDMODEL_GetModelAnimKind(unsigned short *p);
void FIELD_BUILDMODEL_InitSeason(BuildModelSeason *season, u8 dateKey);
void FIELD_BUILDMODEL_UpdateSeasonState(BuildModelSeason *season);
u32 FIELD_BUILDMODEL_GetSeasonChanged(BuildModelSeason *season);
u8 FIELD_BUILDMODEL_GetSeasonAnimSlot(BuildModelSeason *season);
void FIELD_BUILDMODEL_CreateModels(BuildModelMan *man, int extraResource);
void FIELD_BUILDMODEL_DeleteModels(BuildModelMan *man);
void FIELD_BUILDMODEL_CreateAnimSets(BuildModelMan *man, BuildModelHandleTable *out);
void FIELD_BUILDMODEL_DeleteAnimSets(BuildModelMan *man, BuildModelHandleTable *table);
void FIELD_BUILDMODEL_LoadModel(BuildModelMan *man, BuildModelModel *out, int index, int unused);
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
BuildModelEntry *FIELD_BUILDMODEL_AddEntry(BuildModelMan *man, u32 mapObject, BuildModelEntryArgs *args, int index);
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
int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(BuildModelNode *node, int out);
int FIELD_BUILDMODEL_IsNodeSeBusy(BuildModelNode *node);
void FIELD_BUILDMODEL_MakeSearchRect(BuildModelRect *out, const struct VecFx32 *__restrict pos);
#include "field_g3d_mapper.h"
extern const char gBuildModelFileName[];
extern const BuildModelKindTable gBuildModelAnimKindTable;
extern unsigned char gBuildModelSeasonAnimSlot[];
extern BuildModelAnimInit gBuildModelAnimInitTable[];
extern struct BuildModelAnimOps gBuildModelAnimOpsTable[];
extern s16 FX_SinCosTable_[];
extern u8 gBuildModelKindTable[];
extern u8 d_021D3D8A[];

/*
 * Allocates and initialises the 0x13F8-byte manager.
 */
BuildModelMan *FIELD_BUILDMODEL_Create(u16 heapId, void *fieldMap, u16 dateKey)
{
    BuildModelMan *man;
    int i;
    unsigned j;
    int z = 0;

    man = (BuildModelMan *)GFL_HEAP_Alloc(heapId, 0x13F8, 0, (char *)gBuildModelFileName, 0x193);
    man->heapId = heapId;
    man->fieldMap = fieldMap;
    FIELD_BUILDMODEL_InitSeason(&man->season, dateKey);
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++)
        man->nodes[i] = (BuildModelNode *)z;
    for (j = 0; j < BUILDMODEL_ENTRY_COUNT; j++)
        FIELD_BUILDMODEL_ClearEntry(man, &man->entries[j]);
    man->handleTable.handles = 0;
    man->handleTable.count = 0;
    man->handleTable.extra = 0;
    man->handleTable.reserved[0] = 0;
    man->handleTable.reserved[1] = 0;
    man->handleTable.reserved[2] = 0;
    man->modelInfoCount = 0;
    man->modelInfos = 0;
    man->animSetCount = 0;
    man->animSets = 0;
    return man;
}

void FIELD_BUILDMODEL_Delete(BuildModelMan *man)
{
    int i;

    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] != 0)
            FIELD_BUILDMODEL_DeleteNode(man->nodes[i]);
    }
    FIELD_BUILDMODEL_DeleteAnimSets(man, &man->handleTable);
    FIELD_BUILDMODEL_DeleteModels(man);
    FIELD_BUILDMODEL_FreeModelArchive(man);
    FIELD_BUILDMODEL_DeleteG3dResources(man);
    GFL_HEAP_Free(man);
}

void FIELD_BUILDMODEL_UpdateSeason(BuildModelMan *man)
{
    int i;
    unsigned u;

    FIELD_BUILDMODEL_UpdateSeasonState(&man->season);
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        BuildModelNode *node = man->nodes[i];
        if (node != 0)
            FIELD_BUILDMODEL_UpdateAnimSet(man, &node->animSet);
    }
    for (u = 0; u < man->animSetCount; u++)
        FIELD_BUILDMODEL_UpdateAnimSet(man, &man->animSets[u]);
}

void FIELD_BUILDMODEL_DrawNodes(BuildModelMan *man)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] != 0)
            FIELD_BUILDMODEL_DrawNode(man->nodes[i]);
    }
}

void FIELD_BUILDMODEL_LoadArea(BuildModelMan *man, int areaId, int mapHeader, int extraResource)
{
    int member;
    int archiveId;
    int resourceId;
    int tileSetId;

    member = FIELD_BUILDMODEL_GetArchiveMemberIndex(ZONEDATA_GetAreaId(areaId));
    if (ZONEDATA_GetAreaInnerOuter((struct AreaData *)mapHeader)) {
        archiveId = 0xE5;
        resourceId = 0xB0;
        tileSetId = 0x15;
    } else {
        archiveId = 0xE6;
        resourceId = 0xB1;
        tileSetId = 0x14;
    }
    FIELD_BUILDMODEL_LoadModelArchive(man, archiveId, member);
    FIELD_BUILDMODEL_CreateG3dResources(man, (u16)resourceId, member, extraResource);
    FIELD_BUILDMODEL_BuildTableIndex(man, tileSetId);
    FIELD_BUILDMODEL_CreateModels(man, extraResource);
    FIELD_BUILDMODEL_CreateAnimSets(man, &man->handleTable);
}

int FIELD_BUILDMODEL_GetPlacementByTableId(BuildModelMan *man, u32 tableId)
{
    return FIELD_BUILDMODEL_GetOffsetTarget((u32)man->archive, FIELD_BUILDMODEL_GetModelIndex(man, tableId));
}

/*
 * Tail-call thunk: the model definition at the given index.
 */
u8 *FIELD_BUILDMODEL_GetModelDef(BuildModelMan *man, u32 index)
{
    return (u8 *)FIELD_BUILDMODEL_GetOffsetTarget((u32)man->archive, index);
}

static inline void VEC_Set_(struct VecFx32 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int FIELD_BUILDMODEL_GetPlacementPosition(BuildModelMan *man, int tableId, struct VecFx32 *pos, int *modelIndex)
{
    BuildModelPlacement *placement = (BuildModelPlacement *)FIELD_BUILDMODEL_GetPlacementByTableId(man, tableId);
    if (placement->modelId == 0xFFFF)
        return 0;
    *modelIndex = FIELD_BUILDMODEL_GetModelIndex(man, placement->modelId);
    VEC_Set_(pos, placement->tileX << 12, placement->tileY << 12, placement->tileZ << 12);
    return 1;
}

/*
 * The const on descs is load-bearing: with a plain BuildModelObjectDesc * the
 * compiler keeps &descs[i] in a register and spills descs; const keeps descs
 * and i*16 in registers.
 */
int FIELD_BUILDMODEL_RegisterObjects(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *descs, int count)
{
    BuildModelEntryArgs args;
    int i;
    int next = 0;
    for (i = 0; i < count; i++) {
        FIELD_BUILDMODEL_RegisterObject(man, mapObject, descs + i, next);
        if (FIELD_BUILDMODEL_GetPlacementPosition(man, (unsigned short)(descs[i].idLow + (descs[i].idHigh << 8)), &args.pos, &args.modelIndex) == 1) {
            next++;
            args.rotation = descs[i].rotation;
            args.pos.x += descs[i].x;
            args.pos.y += descs[i].y;
            args.pos.z -= descs[i].z;
            FIELD_BUILDMODEL_AddEntry(man, mapObject, &args, next);
        }
        next++;
    }
    return next;
}

/*
 * Tail-call thunk: forwards to FIELD_BUILDMODEL_RemoveEntriesByObject with no argument change.
 */
void FIELD_BUILDMODEL_UnregisterObject(BuildModelMan *man, void *object)
{
    FIELD_BUILDMODEL_RemoveEntriesByObject(man, object);
}

static inline void BuildModelEntryArgsFlat_SetPos(BuildModelEntryArgsFlat *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void FIELD_BUILDMODEL_RegisterObject(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *desc, int index)
{
    BuildModelEntryArgsFlat args;
    args.modelIndex = FIELD_BUILDMODEL_GetModelIndex(man, (unsigned short)(desc->idLow + (desc->idHigh << 8)));
    BuildModelEntryArgsFlat_SetPos(&args, desc->x, desc->y, -desc->z);
    args.rotation = desc->rotation;
    FIELD_BUILDMODEL_AddEntry(man, mapObject, (BuildModelEntryArgs *)(&args), index);
}

void FIELD_BUILDMODEL_RemoveNode(BuildModelMan *man, BuildModelNode *node)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] == node) {
            man->nodes[i] = 0;
            return;
        }
    }
}

void FIELD_BUILDMODEL_AddNode(BuildModelMan *man, BuildModelNode *node)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] == 0) {
            man->nodes[i] = node;
            return;
        }
    }
}

void *FIELD_BUILDMODEL_GetNodeByHandle(BuildModelMan *man, int handle)
{
    unsigned short idx = handle & ~0xFFF0;
    if ((unsigned short)(handle & 0xFFF0) != 0xFFF0)
        return 0;
    if (idx >= BUILDMODEL_NODE_COUNT)
        return 0;
    return man->nodes[idx];
}

unsigned short FIELD_BUILDMODEL_GetNodeHandle(BuildModelMan *man, BuildModelNode *node)
{
    int i;
    if (node == 0)
        return 0;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] == node)
            return 0xFFF0 | i;
    }
    return 0;
}

BuildModelHandleTable *FIELD_BUILDMODEL_GetHandleTable(BuildModelMan *man)
{
    return &man->handleTable;
}

void FIELD_BUILDMODEL_LoadModelArchive(BuildModelMan *man, u16 archiveId, u32 member)
{
    void *arc;
    u8 *data;

    arc = ARC_TOOL_CreateHandle(archiveId, (u16)((man->heapId & 0x7fff) | 0x8000));
    if (ARC_TOOL_GetHandleFileCount(arc) <= member)
        member = 0;
    data = ARC_TOOL_LoadHandleMember(arc, member, man->heapId);
    man->archive = data;
    man->modelCount = (u32)data[2] >> 1;
    if (man->modelCount > BUILDMODEL_TABLE_ID_MAX)
        man->modelCount = 0x80;
    ARC_TOOL_DeleteHandle(arc);
}

int FIELD_BUILDMODEL_FreeModelArchive(BuildModelMan *man)
{
    GFL_HEAP_Free(man->archive);
    man->modelCount = 0;
    return 107 << 2;
}

void FIELD_BUILDMODEL_BuildTableIndex(BuildModelMan *man, int defaultId)
{
    u8 i;
    u8 fill;
    int j;

    MI_CpuFill8(man->tableToIndex, 0x80, BUILDMODEL_TABLE_ID_MAX);
    for (i = 0; i < man->modelCount; i++)
        man->tableToIndex[*((u16 *)FIELD_BUILDMODEL_GetModelDef(man, i))] = i;
    fill = man->tableToIndex[defaultId];
    for (j = 0; j < BUILDMODEL_TABLE_ID_MAX; j++) {
        if (man->tableToIndex[j] == 0x80)
            man->tableToIndex[j] = fill;
    }
}

int FIELD_BUILDMODEL_GetModelIndex(BuildModelMan *man, unsigned int tableId)
{
    unsigned char index;
    if (tableId >= BUILDMODEL_TABLE_ID_MAX)
        tableId = 0;
    index = man->tableToIndex[tableId];
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return index;
}

int FIELD_BUILDMODEL_GetOffsetTarget(u32 base, u32 index)
{
    return (base + *(u32 *)((u8 *)((base + (index << 2))) + 4));
}

/*
 * Leaf: offset-table walk.  table[2] is a byte count; the offsets start at
 * table+4, each entry a 32-bit relative offset.  Returns
 * table + entry[index + (table[2]>>1)].
 */
char *FIELD_BUILDMODEL_GetModelResourceData(char *table, int index)
{
    unsigned n = (unsigned char)table[2];
    return table + *(int *)(table + 4 + ((n >> 1) + index) * 4);
}

u8 *FIELD_BUILDMODEL_GetAnimResourceData(u8 *table, int index)
{
    return (table + *(u32 *)((u8 *)((table + (index << 2))) + 4));
}

/*
 * Maps an area id to an archive member: x >= 0xd2 maps to x-0xd2, x in
 * [2,0xd2) maps to (x-2)/4, x < 2 maps to 0.  The unsigned range tests force
 * `blo` while the division stays signed.  EXACT* (follower 0x0218BC40).
 */
unsigned short FIELD_BUILDMODEL_GetArchiveMemberIndex(int areaIndex)
{
    if ((unsigned)areaIndex >= 0xd2)
        return (unsigned short)(areaIndex - 0xd2);
    if ((unsigned)areaIndex >= 2)
        return (unsigned short)((areaIndex - 2) / 4);
    return 0;
}

/* The trailing guard is the function exit: only its cmp survives. */
void FIELD_BUILDMODEL_CreateG3dResources(BuildModelMan *man, int resourceId, int member, int extraResource)
{
    man->g3dResources = G3D_SYSTEM_CreateResourceArc(resourceId, member);
    if (extraResource != 0)
        FIELD_G3D_MAPPER_TintTexture(man->g3dResources, (void *)extraResource);
    if (G3D_SYSTEM_TransVramTextureAndCut(man->g3dResources) == 0)
        return;
}

void FIELD_BUILDMODEL_DeleteG3dResources(BuildModelMan *man)
{
    if (man->g3dResources != 0) {
        G3D_SYSTEM_FreeVramTexture(man->g3dResources);
        G3D_SYSTEM_DeleteResource(man->g3dResources);
        man->g3dResources = 0;
    }
}

/* Counts the animation resource slots of a model definition that are in use. */
int FIELD_BUILDMODEL_CountAnimResources(int *animDefs)
{
    unsigned int i;
    int n;
    for (i = 0, n = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (animDefs[i + 1] != -1)
            n++;
    }
    return n;
}

/*
 * Returns the animation part of a model definition (definition + 0x10).
 */
u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *def)
{
    return def + 0x10;
}

unsigned char FIELD_BUILDMODEL_GetModelAnimKind(unsigned short *def)
{
    BuildModelKindTable t = gBuildModelAnimKindTable;
    if (def[1] >= 16)
        return 0;
    return t.kind[def[1]];
}

/*
 * Stores the date key and a start season, then updates through FIELD_BUILDMODEL_UpdateSeasonState.
 */
void FIELD_BUILDMODEL_InitSeason(BuildModelSeason *season, u8 dateKey)
{
    season->season = 5;
    season->dateKey = dateKey;
    FIELD_BUILDMODEL_UpdateSeasonState(season);
}

void FIELD_BUILDMODEL_UpdateSeasonState(BuildModelSeason *season)
{
    season->prevSeason = season->season;
    season->season = TIMEZONE_GetNowTimeZone(season->dateKey);
    season->changed = season->season != season->prevSeason;
    season->animSlot = gBuildModelSeasonAnimSlot[season->season];
}

/*
 * Returns the season changed flag.
 */
u32 FIELD_BUILDMODEL_GetSeasonChanged(BuildModelSeason *season)
{
    return season->changed;
}

/*
 * Returns the animation slot chosen for the season.
 */
u8 FIELD_BUILDMODEL_GetSeasonAnimSlot(BuildModelSeason *season)
{
    return season->animSlot;
}

void FIELD_BUILDMODEL_CreateModels(BuildModelMan *man, int extraResource)
{
    unsigned short n = man->modelCount;
    unsigned char i;
    if (n != 0) {
        man->modelInfoCount = n;
        man->modelInfos = GFL_HEAP_Alloc(man->heapId, n * 0x18, 1, (char *)gBuildModelFileName, 0x45F);
        for (i = 0; i < man->modelInfoCount; i++)
            FIELD_BUILDMODEL_LoadModel(man, &man->modelInfos[i], i, extraResource);
    }
}

void FIELD_BUILDMODEL_DeleteModels(BuildModelMan *man)
{
    u32 i;
    if (man->modelInfos != 0) {
        for (i = 0; i < man->modelInfoCount; i++)
            FIELD_BUILDMODEL_FreeModel(&man->modelInfos[i]);
        GFL_HEAP_Free(man->modelInfos);
        man->modelInfoCount = 0;
        man->modelInfos = 0;
    }
}

void FIELD_BUILDMODEL_CreateAnimSets(BuildModelMan *man, BuildModelHandleTable *out)
{
    u32 n;
    u32 i;
    n = man->modelCount;
    if (n != 0) {
        out->count = n;
        out->handles = GFL_HEAP_Alloc(man->heapId, n << 3, 1, (char *)gBuildModelFileName, 0x490);
        man->animSetCount = n;
        man->animSets = GFL_HEAP_Alloc(man->heapId, n * 0x18, 1, (char *)gBuildModelFileName, 0x494);
        for (i = 0; i < man->animSetCount; i++) {
            BuildModelAnimSet *sets = man->animSets;
            BuildModelModel *models = man->modelInfos;
            FIELD_BUILDMODEL_InitAnimSet(man, &sets[i], &models[i]);
            out->handles[i][0] = (u32)sets[i].anim;
            out->handles[i][1] = 0;
        }
    }
}

void FIELD_BUILDMODEL_DeleteAnimSets(BuildModelMan *man, BuildModelHandleTable *table)
{
    u32 i;
    if (table->handles != 0) {
        GFL_HEAP_Free(table->handles);
        table->handles = 0;
    }
    if (table->extra != 0) {
        GFL_HEAP_Free(table->extra);
        table->extra = 0;
    }
    if (man->animSets != 0) {
        for (i = 0; i < man->animSetCount; i++)
            FIELD_BUILDMODEL_FreeAnimSet(&man->animSets[i]);
        GFL_HEAP_Free(man->animSets);
        man->animSetCount = 0;
        man->animSets = 0;
    }
}

void FIELD_BUILDMODEL_LoadModel(BuildModelMan *man, BuildModelModel *out, int index, int unused)
{
    u8 *anims;
    int count;
    int i;
    out->def = FIELD_BUILDMODEL_GetModelDef(man, index);
    out->resource = GFL_HEAP_Alloc(man->heapId, G3D_SYSTEM_GetResourceSize(), 1, (char *)gBuildModelFileName, 0x4d0);
    G3D_SYSTEM_InitResourceByFile(out->resource, (u32 *)FIELD_BUILDMODEL_GetModelResourceData((char *)man->archive, index));
    anims = FIELD_BUILDMODEL_GetModelAnimDefs(out->def);
    count = FIELD_BUILDMODEL_CountAnimResources((int *)anims);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (i < count) {
            out->animResource[i] = GFL_HEAP_Alloc(man->heapId, G3D_SYSTEM_GetResourceSize(), 1, (char *)gBuildModelFileName, 0x4db);
            G3D_SYSTEM_InitResourceByFile(out->animResource[i], (u32 *)FIELD_BUILDMODEL_GetAnimResourceData(anims, i));
        } else {
            out->animResource[i] = 0;
        }
    }
}

void FIELD_BUILDMODEL_FreeModel(BuildModelModel *model)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (model->animResource[i] != 0) {
            GFL_HEAP_Free(model->animResource[i]);
            model->animResource[i] = 0;
        }
    }
    if (model->resource != 0) {
        GFL_HEAP_Free(model->resource);
        model->resource = 0;
    }
}

/*
 * The table index is narrowed in its own statement (`k = (u8)k;`): the
 * second definition makes k a two-definition web that is coloured after
 * the multiply product, so the ldrb lands in r4, the product in r3 and
 * the t reload in r0 (docs/idioms/a-self-narrowing-cast-statement-
 * recolours-a-table-index.md). A cast inside the subscript is inert.
 */
void FIELD_BUILDMODEL_InitAnimSet(BuildModelMan *man, BuildModelAnimSet *out, BuildModelModel *model)
{
    u32 buf[BUILDMODEL_ANIM_SLOTS];
    u8 *anims;
    u32 owner;
    int i;
    u8 k;
    anims = FIELD_BUILDMODEL_GetModelAnimDefs(model->def);
    owner = (u32)G3D_SYSTEM_CreateRender(model->resource, 0, man->g3dResources);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (model->animResource[i] != 0)
            buf[i] = (u32)G3D_SYSTEM_CreateAnime((struct G3dRender *)owner, (struct G3dResource *)model->animResource[i], 0);
        else
            buf[i] = 0;
    }
    out->anim = G3D_SYSTEM_CreateObject((struct G3dRender *)owner, (struct G3dAnime **)buf, 4);
    out->model = model;
    k = anims[0];
    k = (u8)k;
    gBuildModelAnimInitTable[k].init(man, out);
}

/*
 * Init callback of the gBuildModelAnimInitTable dispatch table (pool word 0x0218C02D at +0x0
 * and +0x18), called by FIELD_BUILDMODEL_InitAnimSet as init(man, set): clears all slot states.
 */
void FIELD_BUILDMODEL_InitAnimSetNone(void *man, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        set->slotState[i] = 0;
    }
}

/* Init callback: starts every animation the model has and marks it looping. */
void FIELD_BUILDMODEL_InitAnimSetAll(void *man, BuildModelAnimSet *set)
{
    u8 *anims;
    u32 n;
    int i;
    anims = FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    n = anims[2];
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS && i < n; i++) {
        G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)i);
        G3D_SYSTEM_ResetObjectAnimeFrame(set->anim, i);
        set->slotState[i] = 1;
    }
    for (; i < BUILDMODEL_ANIM_SLOTS; i++)
        set->slotState[i] = 0;
}

/* Init callback: starts only the animation chosen for the current season. */
void FIELD_BUILDMODEL_InitAnimSetSeason(BuildModelMan *man, BuildModelAnimSet *set)
{
    int i;
    u32 slot;
    FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    slot = FIELD_BUILDMODEL_GetSeasonAnimSlot(&man->season);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (i != slot) {
            set->slotState[i] = 0;
        } else {
            G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)i);
            G3D_SYSTEM_ResetObjectAnimeFrame(set->anim, i);
            set->slotState[i] = 1;
        }
    }
}

void FIELD_BUILDMODEL_FreeAnimSet(BuildModelAnimSet *set)
{
    int n;
    int i;
    void *rest;
    if (set->anim != 0) {
        n = G3D_SYSTEM_GetObjectAnimeCount(set->anim);
        for (i = 0; i < n; i++) {
            void *o = (void *)G3D_SYSTEM_GetObjectAnime(set->anim, (u16)i);
            if (o != 0)
                G3D_SYSTEM_DeleteAnime(o);
        }
        rest = (void *)G3D_SYSTEM_GetObjectRender(set->anim);
        G3D_SYSTEM_DeleteObject(set->anim);
        set->anim = 0;
        set->model = 0;
        G3D_SYSTEM_DeleteRender(rest);
    }
}

void FIELD_BUILDMODEL_UpdateAnimSet(void *man, BuildModelAnimSet *set)
{
    unsigned char kind = *FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    if (set->anim != 0)
        gBuildModelAnimOpsTable[kind].update(man, set);
}

void FIELD_BUILDMODEL_AnimSetKindDummy(void)
{
}

/*
 * Season update for a four-slot set: restarts the season slot when the season
 * changed, otherwise advances it.
 */
void FIELD_BUILDMODEL_UpdateAnimSetSeason(BuildModelMan *man, BuildModelAnimSet *set)
{
    int slot = FIELD_BUILDMODEL_GetSeasonAnimSlot(&man->season);
    if (FIELD_BUILDMODEL_GetSeasonChanged(&man->season) != 0) {
        FIELD_BUILDMODEL_ResetAnimSet(set);
        G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)slot);
        G3D_SYSTEM_ResetObjectAnimeFrame(set->anim, slot);
        set->slotState[slot] = 1;
    } else {
        G3D_SYSTEM_LoopObjectAnimeFrame(set->anim, (u16)slot, 0x1000);
    }
}

void FIELD_BUILDMODEL_AdvanceAllSlots(int unused, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++)
        G3D_SYSTEM_LoopObjectAnimeFrame(set->anim, (unsigned short)i, 0x1000);
}

/*
 * Per-slot state machine step over four slots.
 */
void FIELD_BUILDMODEL_UpdateAnimSetSlots(u32 unused, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        switch (set->slotState[i]) {
        case BUILDMODEL_SLOT_NONE:
        case BUILDMODEL_SLOT_HOLD:
            break;
        case BUILDMODEL_SLOT_OPENING:
            if (G3D_SYSTEM_IncObjectAnimeFrame(set->anim, (u16)i, 0x1000) == 0)
                set->slotState[i] = BUILDMODEL_SLOT_HOLD;
            break;
        case BUILDMODEL_SLOT_CLOSING:
            if (G3D_SYSTEM_IncObjectAnimeFrame(set->anim, (u16)i, -0x1000) == 0) {
                G3D_SYSTEM_SetObjectAnimeFrame(set->anim, (u16)i, 0);
                set->slotState[i] = BUILDMODEL_SLOT_HOLD;
            }
            break;
        case BUILDMODEL_SLOT_LOOP:
            G3D_SYSTEM_LoopObjectAnimeFrame(set->anim, (u16)i, 0x1000);
            break;
        }
    }
}

/*
 * Starts a group of slots and marks them opening.
 */
void FIELD_BUILDMODEL_StartGroupOpening(BuildModelAnimSet *set, int group)
{
    u8 *anims = FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)(base + i));
        G3D_SYSTEM_ResetObjectAnimeFrame(set->anim, base + i);
        set->slotState[base + i] = BUILDMODEL_SLOT_OPENING;
    }
}

/*
 * Starts a group of slots and marks them looping.
 */
void FIELD_BUILDMODEL_StartGroupLoop(BuildModelAnimSet *set, int group)
{
    u8 *anims = FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)(base + i));
        G3D_SYSTEM_ResetObjectAnimeFrame(set->anim, base + i);
        set->slotState[base + i] = BUILDMODEL_SLOT_LOOP;
    }
}

/*
 * Starts a group of slots, sets the start frame, marks them closing.
 */
void FIELD_BUILDMODEL_StartGroupClosing(BuildModelAnimSet *set, int group)
{
    u8 *anims = FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    int base = anims[2] * group;
    int i;
    int frame;
    for (i = 0; i < anims[2]; i++) {
        G3D_SYSTEM_EnableObjectAnime(set->anim, (u16)(base + i));
        frame = *(u16 *)(*(u8 **)((u8 *)G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(set->anim, (u16)(base + i))) + 8) + 4) << 12;
        G3D_SYSTEM_SetObjectAnimeFrame(set->anim, base + i, &frame);
        set->slotState[base + i] = BUILDMODEL_SLOT_CLOSING;
    }
}

/* Stops a group of slots that are running. */
void FIELD_BUILDMODEL_StopGroup(BuildModelAnimSet *set, int group)
{
    u8 *anims = FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        if (set->slotState[base + i] != 0)
            set->slotState[base + i] = BUILDMODEL_SLOT_HOLD;
    }
}

void FIELD_BUILDMODEL_ResetAnimSet(BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (set->slotState[i] != 0) {
            G3D_SYSTEM_DisableObjectAnime(set->anim, (unsigned short)i);
            set->slotState[i] = 0;
        }
    }
}

void FIELD_BUILDMODEL_PlayAnimSet(BuildModelAnimSet *set, int slot, int mode)
{
    unsigned char kind = *FIELD_BUILDMODEL_GetModelAnimDefs(set->model->def);
    unsigned char idx = slot;
    if (idx >= BUILDMODEL_ANIM_SLOTS)
        idx = 0;
    gBuildModelAnimOpsTable[kind].play(set, idx, mode);
}

/*
 * Dispatches a slot-group operation by mode 0..4.
 */
void FIELD_BUILDMODEL_PlayGroup(BuildModelAnimSet *set, int group, int mode)
{
    switch (mode) {
    case 0:
        FIELD_BUILDMODEL_ResetAnimSet(set);
        FIELD_BUILDMODEL_StartGroupOpening(set, group);
        break;
    case 1:
        FIELD_BUILDMODEL_ResetAnimSet(set);
        FIELD_BUILDMODEL_StartGroupClosing(set, group);
        break;
    case 2:
        FIELD_BUILDMODEL_ResetAnimSet(set);
        FIELD_BUILDMODEL_StartGroupLoop(set, group);
        break;
    case 3:
        FIELD_BUILDMODEL_StopGroup(set, group);
        break;
    case 4:
        FIELD_BUILDMODEL_ResetAnimSet(set);
        break;
    }
}

void FIELD_BUILDMODEL_AnimSetKindPlayDummy(void)
{
}

/*
 * Reports whether slot i (0 if out of range) is idle (state none or hold).
 */
int FIELD_BUILDMODEL_IsSlotIdle(BuildModelAnimSet *set, int slot)
{
    u8 j = slot;
    if (j >= BUILDMODEL_ANIM_SLOTS)
        j = 0;
    switch (set->slotState[j]) {
    case BUILDMODEL_SLOT_NONE:
        return 1;
    case BUILDMODEL_SLOT_LOOP:
        return 0;
    case BUILDMODEL_SLOT_HOLD:
        return 1;
    case BUILDMODEL_SLOT_OPENING:
    case BUILDMODEL_SLOT_CLOSING:
        return 0;
    }
    return 0;
}

int FIELD_BUILDMODEL_GetSlotFrame(BuildModelAnimSet *set, int id)
{
    int frame;
    G3D_SYSTEM_GetObjectAnimeFrame(set->anim, (unsigned short)id, &frame);
    return frame;
}

void FIELD_BUILDMODEL_ClearEntry(void *unused, BuildModelEntry *entry)
{
    entry->object = 0;
    entry->savedWord = -1;
    entry->index = 0;
    entry->visible = 0;
    entry->instance = 0;
}

/*
 * Claims the first free entry of the entry table.
 */
BuildModelEntry *FIELD_BUILDMODEL_AddEntry(BuildModelMan *man, u32 mapObject, BuildModelEntryArgs *args, int index)
{
    BuildModelEntry *entry = &man->entries[0];
    u32 i;
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        entry = &man->entries[i];
        if (entry->object == 0) {
            FIELD_G3D_MAP_SetPlacement((struct FieldG3dMap *)mapObject, (struct FieldG3dMapPlacement *)args, index);
            entry->object = (void *)mapObject;
            entry->savedWord = -1;
            entry->index = index;
            entry->visible = 1;
            entry->instance = (BuildModelInstance *)FIELD_G3D_MAP_GetPlacement((struct FieldG3dMap *)mapObject, index);
            return entry;
        }
    }
    return 0;
}

void FIELD_BUILDMODEL_RemoveEntriesByObject(BuildModelMan *man, void *object)
{
    BuildModelEntry *entries = man->entries;
    int i;
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        if (entries[i].object == object)
            FIELD_BUILDMODEL_FreeEntry(man, &entries[i]);
    }
}

/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * FIELD_G3D_MAP_ClearPlacement (0x0216940C) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 */
void FIELD_BUILDMODEL_FreeEntry(BuildModelMan *man, BuildModelEntry *entry)
{
    FIELD_G3D_MAP_ClearPlacement(entry->object, entry->index);
    FIELD_BUILDMODEL_ClearEntry(man, entry);
}

/* Returns the low byte of the instance's model id (the saved one while visible). */
u8 FIELD_BUILDMODEL_GetEntryModelId(BuildModelEntry *entry)
{
    if (entry->instance->modelId == (~0)) {
        return (((u32)entry->savedWord << 24) >> 24);
    }
    return ((entry->instance->modelId << 24) >> 24);
}

/* Swaps the instance model id with the saved word: attach hides it, restore puts it back. */
void FIELD_BUILDMODEL_SwapEntryModelId(BuildModelEntry *entry, int restore)
{
    if (restore) {
        entry->instance->modelId = entry->savedWord;
        entry->savedWord = -1;
        entry->visible = 1;
    } else {
        entry->savedWord = entry->instance->modelId;
        entry->instance->modelId = -1;
        entry->visible = 0;
    }
}

void FIELD_BUILDMODEL_GetModelIndexOut(BuildModelMan *man, BuildModelSearchArgs *args, int tableId)
{
    *args->outIndex = FIELD_BUILDMODEL_GetModelIndex(man, tableId);
}

static inline int BuildModelRect_Contains(BuildModelRect *r, int x, int z)
{
    if (r->xMin <= x && r->xMax >= x && r->zMin <= z && r->zMax >= z)
        return 1;
    return 0;
}

/*
 * Collects the active entries whose position lies inside a rect.
 */
BuildModelEntry **FIELD_BUILDMODEL_CollectEntriesInRect(BuildModelMan *man, BuildModelRect *rect, int kind, int *count)
{
    BuildModelEntry **list;
    BuildModelEntry *entry;
    struct VecFx32 pos;
    int n = 0;
    u32 i;
    list = GFL_HEAP_Alloc(man->heapId, 0x80, 1, (char *)gBuildModelFileName, 0x749);
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        entry = &man->entries[i];
        if (entry->object == 0)
            continue;
        if (kind != 0 && kind != FIELD_BUILDMODEL_GetEntryAnimKind(man, entry))
            continue;
        FIELD_G3D_MAP_GetPos((struct FieldG3dMap *)entry->object, &pos);
        VEC_Add(&entry->instance->pos, &pos, &pos);
        if (BuildModelRect_Contains(rect, pos.x, pos.z) == 1) {
            list[n] = entry;
            n++;
        }
    }
    *count = n;
    return list;
}

BuildModelEntry *FIELD_BUILDMODEL_GetFirstEntryInRect(BuildModelMan *man, int kind, BuildModelRect *rect)
{
    int count;
    BuildModelEntry **list = FIELD_BUILDMODEL_CollectEntriesInRect(man, rect, kind, &count);
    BuildModelEntry *first = *list;
    GFL_HEAP_Free(list);
    return first;
}

BuildModelEntry *FIELD_BUILDMODEL_GetFirstEntryNearPos(BuildModelMan *man, int kind, const struct VecFx32 *pos)
{
    BuildModelRect rect;
    FIELD_BUILDMODEL_MakeSearchRect(&rect, pos);
    return FIELD_BUILDMODEL_GetFirstEntryInRect(man, kind, &rect);
}

int FIELD_BUILDMODEL_GetEntryAnimKind(BuildModelMan *man, BuildModelEntry *entry)
{
    unsigned char index = FIELD_BUILDMODEL_GetEntryModelId(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return FIELD_BUILDMODEL_GetModelAnimKind((short unsigned int *)FIELD_BUILDMODEL_GetModelDef(man, index));
}

void FIELD_BUILDMODEL_PlayEntryAnim(BuildModelMan *man, BuildModelEntry *entry, int slot, int mode)
{
    unsigned char index = FIELD_BUILDMODEL_GetEntryModelId(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    FIELD_BUILDMODEL_PlayAnimSet(&man->animSets[index], slot, mode);
}

void FIELD_BUILDMODEL_GetEntryWorldPos(BuildModelEntry *entry, void *out)
{
    struct VecFx32 pos;
    FIELD_G3D_MAP_GetPos((struct FieldG3dMap *)entry->object, &pos);
    VEC_Add(&entry->instance->pos, &pos, out);
}

int FIELD_BUILDMODEL_GetEntrySlotFrame(BuildModelMan *man, BuildModelEntry *entry, int id)
{
    unsigned char index = FIELD_BUILDMODEL_GetEntryModelId(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return FIELD_BUILDMODEL_GetSlotFrame(&man->animSets[index], id);
}

/*
 * Allocates a 0x60-byte node for an entry, builds its matrices, registers it.
 */
BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromEntry(BuildModelMan *man, BuildModelEntry *entry)
{
    BuildModelInstance *instance = entry->instance;
    BuildModelNode *node;
    struct VecFx32 fieldOffset;
    int facing;
    node = GFL_HEAP_Alloc(man->heapId, 0x60, 0, (char *)gBuildModelFileName, 0x7E9);
    node->man = man;
    node->entry = entry;
    node->slot = 0xFFFF;
    facing = instance->facing >> 4;
    MTX_RotY33_(&node->matrix, FX_SinCosTable_[facing * 2], FX_SinCosTable_[facing * 2 + 1]);
    FIELD_G3D_MAP_GetPos((struct FieldG3dMap *)entry->object, &node->pos);
    VEC_Add(&node->pos, &instance->pos, &node->pos);
    FIELD_G3D_MAPPER_GetOriginOffset(man->fieldMap, &fieldOffset);
    VEC_Add(&node->pos, &fieldOffset, &node->pos);
    node->scaleX = 0x1000;
    node->scaleY = 0x1000;
    node->scaleZ = 0x1000;
    FIELD_BUILDMODEL_InitAnimSet(man, &node->animSet, &man->modelInfos[instance->modelId]);
    FIELD_BUILDMODEL_AddNode(man, node);
    FIELD_BUILDMODEL_SwapEntryModelId(node->entry, 0);
    return node;
}

BuildModelNode *FIELD_BUILDMODEL_CreateNodeNearPos(BuildModelMan *man, int kind, const struct VecFx32 *pos)
{
    BuildModelEntry *entry = FIELD_BUILDMODEL_GetFirstEntryNearPos(man, kind, pos);
    if (entry == 0)
        return 0;
    return FIELD_BUILDMODEL_CreateNodeFromEntry(man, entry);
}

/*
 * Allocates a 0x60-byte node, copies a 60-byte block into it, registers it.
 */
BuildModelNode *FIELD_BUILDMODEL_CreateNodeFromBlock(BuildModelMan *man, u32 tableId, BuildModelBlock *src)
{
    BuildModelNode *node = GFL_HEAP_Alloc(man->heapId, 0x60, 0, (char *)gBuildModelFileName, 0x825);
    node->man = man;
    node->entry = 0;
    node->slot = 0xFFFF;
    *(BuildModelBlock *)&node->pos = *src;
    FIELD_BUILDMODEL_InitAnimSet(man, &node->animSet, &man->modelInfos[FIELD_BUILDMODEL_GetModelIndex(man, tableId)]);
    FIELD_BUILDMODEL_AddNode(man, node);
    return node;
}

void FIELD_BUILDMODEL_DeleteNode(BuildModelNode *node)
{
    if (node != 0) {
        FIELD_BUILDMODEL_RemoveNode(node->man, node);
        FIELD_BUILDMODEL_FreeAnimSet(&node->animSet);
        if (node->entry != 0)
            FIELD_BUILDMODEL_SwapEntryModelId(node->entry, 1);
        GFL_HEAP_Free(node);
    }
}

void FIELD_BUILDMODEL_PlayNodeSlot(BuildModelNode *node, int slot, int mode)
{
    if (node != 0) {
        node->slot = slot;
        FIELD_BUILDMODEL_PlayAnimSet(&node->animSet, slot, mode);
    }
}

void FIELD_BUILDMODEL_PlayNodeCurrentSlot(BuildModelNode *node, int mode)
{
    if (node != 0)
        FIELD_BUILDMODEL_PlayAnimSet(&node->animSet, node->slot, mode);
}

int FIELD_BUILDMODEL_TryOpenNodeSlot(BuildModelNode *node, int slot)
{
    if (node == 0)
        return 1;
    if (FIELD_BUILDMODEL_IsNodeSlotIdle(node, slot) == 1) {
        FIELD_BUILDMODEL_PlayNodeSlot(node, slot, 3);
        return 1;
    }
    return 0;
}

int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(BuildModelNode *node)
{
    if (node == 0)
        return 1;
    if (FIELD_BUILDMODEL_IsNodeCurrentSlotIdle(node) == 1) {
        FIELD_BUILDMODEL_PlayNodeCurrentSlot(node, 3);
        return 1;
    }
    return 0;
}

int FIELD_BUILDMODEL_IsNodeSlotIdle(BuildModelNode *node, int slot)
{
    if (node == 0)
        return 0;
    return FIELD_BUILDMODEL_IsSlotIdle(&node->animSet, slot);
}

int FIELD_BUILDMODEL_IsNodeCurrentSlotIdle(BuildModelNode *node)
{
    if (node == 0)
        return 0;
    return FIELD_BUILDMODEL_IsSlotIdle(&node->animSet, node->slot);
}

/* Returns the kind field of the node's model definition. */
unsigned short FIELD_BUILDMODEL_GetNodeModelKind(BuildModelNode *node)
{
    if (node == 0)
        return 0;
    return ((unsigned short *)node->animSet.model->def)[1];
}

void FIELD_BUILDMODEL_DrawNode(BuildModelNode *node)
{
    if (node != 0)
        G3D_SYSTEM_DrawObject(node->animSet.anim, (struct G3dObjectStatus *)&node->pos);
}

/*
 * Looks up a 10-byte-stride table row by model kind and reads column idx.
 */
int FIELD_BUILDMODEL_GetNodeKindTableEntry(BuildModelNode *node, u32 column, u16 *out)
{
    u32 key;
    u32 j;
    if (node == 0)
        return 0;
    key = FIELD_BUILDMODEL_GetNodeModelKind(node);
    *out = 0;
    if (column >= 4)
        return 0;
    for (j = 0; j < 6; j++) {
        if (key == *(u16 *)(gBuildModelKindTable + j * 10)) {
            *out = *(u16 *)(d_021D3D8A + j * 10 + column * 2);
            return 1;
        }
    }
    return 0;
}

int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(BuildModelNode *node, int out)
{
    if (node == 0)
        return 0;
    return FIELD_BUILDMODEL_GetNodeKindTableEntry(node, node->slot, (u16 *)out);
}

int FIELD_BUILDMODEL_IsNodeSeBusy(BuildModelNode *node)
{
    unsigned short v;
    if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(node, (int)(&v)) == 0)
        return 0;
    return GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(v));
}

/*
 * `__restrict` on pos lets mwcc keep pos[2] in a register across the
 * out->zMin/out->zMax stores and sink the out->zMin store past the pos[0] load
 * (see docs/idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md).
 */
void FIELD_BUILDMODEL_MakeSearchRect(BuildModelRect *out, const struct VecFx32 *__restrict pos)
{
    out->zMin = pos->z - 0x30000;
    out->zMax = pos->z + 0x30000;
    out->xMin = pos->x - 0x20000;
    out->xMax = pos->x + 0x20000;
}
