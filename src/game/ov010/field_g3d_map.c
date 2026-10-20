/*
 * file:     field_g3d_map.c
 * unit:     yes
 * function: FIELD_G3D_MAP_Create, FIELD_G3D_MAP_Destroy, FIELD_G3D_MAP_Update, FIELD_G3D_MAP_WaitLoad, FIELD_G3D_MAP_DrawWithModels, FIELD_G3D_MAP_OpenArchive, FIELD_G3D_MAP_CloseArchive, FIELD_G3D_MAP_SetAltTextureRes, FIELD_G3D_MAP_ClearAltTextureRes, FIELD_G3D_MAP_SetPlacedModels, FIELD_G3D_MAP_ClearPlacedModels, FIELD_G3D_MAP_SetPlacement, FIELD_G3D_MAP_ClearPlacement, FIELD_G3D_MAP_GetPlacement, FIELD_G3D_MAP_StartLoad, FIELD_G3D_MAP_Unload, FIELD_G3D_MAP_SetVisible, FIELD_G3D_MAP_IsVisible, FIELD_G3D_MAP_SetPos, FIELD_G3D_MAP_GetPos, FIELD_G3D_MAP_GetActiveRef, FIELD_G3D_MAP_GetBuffer, FIELD_G3D_MAP_GetMemberIndex, FIELD_G3D_MAP_GetTotalBytes, FIELD_G3D_MAP_SetModelRes, FIELD_G3D_MAP_ClearModelRes, FIELD_G3D_MAP_GetModelRes, FIELD_G3D_MAP_ClearTextureRes, FIELD_G3D_MAP_GetTextureRes, FIELD_G3D_MAP_BindRenderObj, FIELD_G3D_MAP_GetRenderObj, FIELD_G3D_MAP_ResetLoadState, FIELD_G3D_MAP_BeginChunkedLoad, FIELD_G3D_MAP_ReadNextChunk, FIELD_G3D_MAP_Draw, FIELD_G3D_MAP_DrawPlacedModels, FIELD_G3D_MAP_CanQueryHits, FIELD_G3D_MAP_QueryHits, FIELD_G3D_MAP_QueryPlane, FIELD_G3D_MAP_ClearPlacements, FIELD_G3D_MAP_Reset, FIELD_G3D_MAP_InitRenderObj, FIELD_G3D_MAP_ClearRenderObjModel, FIELD_G3D_MAP_TestModelBox, FIELD_G3D_MAP_RunBoxTest, FIELD_G3D_MAP_PickTextureRes, FIELD_G3D_MAP_ReadWhole
 * address:  0x02169148
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x02169148: field_g3d_map.c __FILE__ anchor at 0x02169148 (file name kept apart from field_g3d_map.c at 0x0216BF38).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   d_02172A40     0x02172A40  data
 *   NNS_GfdDefaultFuncAllocTexVram     0x020A8140  data
 *   NNS_GfdDefaultFuncAllocPlttVram     0x020A8148  data
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   G3D_SYSTEM_InitResourceByKind 0x02046C9C arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   NNS_G3dGlbBaseTrans  0x0206A9DC  arm
 *   MI_Copy36B  0x02082B60  arm
 *   NNS_G3dGlbBaseScale  0x0206AA0C  arm
 *   NNS_G3dGlbFlush  0x0206A854  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   G3D_SYSTEM_DrawRenderObj  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   gG3dBaseMtx43     0x02148B98  data   a4
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   VEC_Add        0x0207C9D0  arm
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   FX_SinCosTable_   0x020A1B38  data
 *   VEC_Subtract  0x0207CA00  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetMdlSet  0x0206E954  arm
 *   NNS_G3dGetTex  0x0206E964  arm
 *   NNS_G3dBindMdlTex  0x0206A2CC  arm
 *   NNS_G3dBindMdlPltt  0x0206A4AC  arm
 *   NNS_G3dRenderObjInit  0x02069D14  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3X_GetBoxTestResult  0x0207DEA4  arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 */
#include "field_g3d_map_types.h"

#include "../types.h"

/* Block of the model file that holds the name dictionary (count and entry table). */
typedef struct FieldG3dMapDictBlock {
    u8 pad00[9];
    u8 count;               /* 0x09 */
    u8 pad0A[4];
    u16 entryOffset;        /* 0x0E */
} FieldG3dMapDictBlock;

/* Global state block of the geometry engine: only the flag word is used here. */
typedef struct FieldG3dMapGlbState {
    u8 pad00[0x7c];
    u32 flag;               /* 0x7C */
} FieldG3dMapGlbState;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/g3d_system.h"
#include "../arm9/arc_tool.h"
struct ArcHandle;
struct G3dResource;
struct ArcHandleRaw;
struct VecFx32;
#include "../arm9/nns_g3d_glb.h"
#include "../arm9/mi_memory.h"
struct NNSG3dRenderObj;
#include "../arm9/nns_g3d_ge.h"
struct G3dObject;
struct G3dRender;
#include "../arm9/fx_vec.h"
extern void MTX_RotY33_(void *m, short sinv, short cosv);
#include "../arm9/nns_g3d_res.h"
struct NNSG3dResTex;
struct NNSG3dResMdl;
typedef int GXFogBlend;
typedef int GXFogSlope;
#include "../arm9/g3x.h"
#include "../arm9/nns_g3d_tex.h"
FieldG3dMap *FIELD_G3D_MAP_Create(const FieldG3dMapConfig *cfg, u32 heapId);
void FIELD_G3D_MAP_Destroy(FieldG3dMap *map);
void FIELD_G3D_MAP_Update(FieldG3dMap *map);
int FIELD_G3D_MAP_WaitLoad(FieldG3dMap *map);
int FIELD_G3D_MAP_DrawWithModels(FieldG3dMap *map, int arg);
void FIELD_G3D_MAP_OpenArchive(FieldG3dMap *map, int archiveId, int heapId);
void FIELD_G3D_MAP_CloseArchive(FieldG3dMap *map);
void FIELD_G3D_MAP_SetAltTextureRes(FieldG3dMap *map, void *textureRes);
void FIELD_G3D_MAP_ClearAltTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPlacedModels(FieldG3dMap *map, FieldG3dMapModelSet *placedModels);
void FIELD_G3D_MAP_ClearPlacedModels(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPlacement(FieldG3dMap *map, FieldG3dMapPlacement *src, u32 index);
void FIELD_G3D_MAP_ClearPlacement(FieldG3dMap *map, u32 index);
FieldG3dMapPlacement *FIELD_G3D_MAP_GetPlacement(FieldG3dMap *map, u32 index);
void FIELD_G3D_MAP_StartLoad(FieldG3dMap *map, u32 memberIndex);
void FIELD_G3D_MAP_Unload(FieldG3dMap *map);
void FIELD_G3D_MAP_SetVisible(FieldG3dMap *map, u16 visible);
u16 FIELD_G3D_MAP_IsVisible(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPos(FieldG3dMap *map, const VecFx32 *pos);
void FIELD_G3D_MAP_GetPos(FieldG3dMap *map, VecFx32 *dst);
u16 *FIELD_G3D_MAP_GetActiveRef(FieldG3dMap *map, u16 **out);
void FIELD_G3D_MAP_GetBuffer(FieldG3dMap *map, u8 **out);
void FIELD_G3D_MAP_GetMemberIndex(FieldG3dMap *map, u32 *out);
void FIELD_G3D_MAP_GetTotalBytes(FieldG3dMap *map, u32 *out);
void FIELD_G3D_MAP_SetModelRes(FieldG3dMap *map, u8 *value);
void FIELD_G3D_MAP_ClearModelRes(FieldG3dMap *map);
void *FIELD_G3D_MAP_GetModelRes(FieldG3dMap *map);
void FIELD_G3D_MAP_ClearTextureRes(FieldG3dMap *map);
void *FIELD_G3D_MAP_GetTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_BindRenderObj(FieldG3dMap *map);
FieldG3dMapRenderObj *FIELD_G3D_MAP_GetRenderObj(FieldG3dMap *map);
void FIELD_G3D_MAP_ResetLoadState(FieldG3dMap *map);
void FIELD_G3D_MAP_BeginChunkedLoad(FieldG3dMap *map, u32 member);
int FIELD_G3D_MAP_ReadNextChunk(FieldG3dMap *map);
int FIELD_G3D_MAP_Draw(FieldG3dMap *map);
void FIELD_G3D_MAP_DrawPlacedModels(FieldG3dMap *map, int unused);
int FIELD_G3D_MAP_CanQueryHits(FieldG3dMap *map);
void FIELD_G3D_MAP_QueryHits(FieldG3dMapHitList *out, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);
void FIELD_G3D_MAP_QueryPlane(u32 *plane, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);
void FIELD_G3D_MAP_ClearPlacements(FieldG3dMap *map);
void FIELD_G3D_MAP_Reset(FieldG3dMap *map);
void FIELD_G3D_MAP_InitRenderObj(FieldG3dMapRenderObj *renderObj, void *modelRes, void *textureRes);
FieldG3dMapRenderObj *FIELD_G3D_MAP_ClearRenderObjModel(FieldG3dMapRenderObj *renderObj);
int FIELD_G3D_MAP_TestModelBox(FieldG3dMapModel *model);
u32 FIELD_G3D_MAP_RunBoxTest(const short *box);
void *FIELD_G3D_MAP_PickTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_ReadWhole(FieldG3dMap *map, u32 member);

extern const char d_02172A40[];
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern FieldG3dMapGlbState d_02148BCC;
extern u8 d_02172160[];
extern u8 gG3dBaseMtx43[];
extern short FX_SinCosTable_[];
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, u32 is4x4, u32 opt);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, u32 is4pltt, u32 opt);
extern void (*d_020A814C)(u32);
extern void (*d_020A8144)(u32);

/*
 * Create the 0xDC-byte map object from its config: two placement tables,
 * the data buffer, two resource records, and the texture and palette VRAM
 * keys through the allocator hooks. Levers: the buffer size from cfg (not the
 * just-stored copy), and the render object model cleared through renderObjRef.
 */
FieldG3dMap *FIELD_G3D_MAP_Create(const FieldG3dMapConfig *cfg, u32 heapId)
{
    FieldG3dMap *map;
    u32 recordSize;

    map = GFL_HEAP_Alloc(heapId, sizeof(FieldG3dMap), 1, d_02172A40, 0x6E);
    recordSize = G3D_SYSTEM_GetResourceSize();
    map->placementCountA = cfg->placementCountA;
    map->placementCountB = cfg->placementCountB;
    map->extraParam0 = cfg->extraParam0;
    map->extraParam1 = cfg->extraParam1;
    if (map->placementCountA != 0)
        map->placementsA = GFL_HEAP_Alloc(heapId, cfg->placementCountA * 20, 1, d_02172A40, 0x77);
    if (map->placementCountB != 0)
        map->placementsB = GFL_HEAP_Alloc(heapId, cfg->placementCountB * 20, 1, d_02172A40, 0x7A);
    FIELD_G3D_MAP_Reset(map);
    map->typeTable = cfg->typeTable;
    map->bufferSize = cfg->bufferSize;
    map->buffer = GFL_HEAP_Alloc(heapId, cfg->bufferSize, 1, d_02172A40, 0x86);
    if (cfg->chunkSize == 0)
        map->chunkSize = 0x800;
    else
        map->chunkSize = cfg->chunkSize;
    map->userParam = cfg->userParam;
    map->renderObjRef = &map->renderObj;
    map->renderObjRef->model = 0;
    map->archive = 0;
    map->modelRes = GFL_HEAP_Alloc(heapId, recordSize, 1, d_02172A40, 0x97);
    map->textureRes = GFL_HEAP_Alloc(heapId, recordSize, 1, d_02172A40, 0x9A);
    map->altTextureRes = 0;
    if (cfg->texVramSize != 0) {
        map->texVramSize = cfg->texVramSize;
        map->texKey = NNS_GfdDefaultFuncAllocTexVram(cfg->texVramSize, 0, 0);
        map->plttKey = NNS_GfdDefaultFuncAllocPlttVram(0x200, 0, 0);
    } else {
        map->texVramSize = 0;
        map->texKey = 0;
        map->plttKey = 0;
    }
    return map;
}

/* Destroy the map object: close the archive, free the VRAM keys and every buffer. */
void FIELD_G3D_MAP_Destroy(FieldG3dMap *map)
{
    FIELD_G3D_MAP_CloseArchive(map);
    if (map->texVramSize != 0) {
        d_020A814C(map->plttKey);
        d_020A8144(map->texKey);
    }
    GFL_HEAP_Free(map->textureRes);
    GFL_HEAP_Free(map->modelRes);
    GFL_HEAP_Free(map->buffer);
    if (map->placementCountA != 0)
        GFL_HEAP_Free(map->placementsA);
    if (map->placementCountB != 0)
        GFL_HEAP_Free(map->placementsB);
    GFL_HEAP_Free(map);
}

/*
 * Update step: call the update callback of the block type while the object is
 * active. Address arithmetic: the unsigned 32-bit index scaling and base
 * addition keep the original lsls/adds wraparound without an invented bound.
 */
void FIELD_G3D_MAP_Update(FieldG3dMap *map)
{
    FieldG3dMapUpdateFunc update;

    if (map->active) {
        update = map->typeTable[map->typeIndex].update;
        if (update)
            update(map, map->userParam);
    }
}

/* Run update steps in synchronous load mode until the object is no longer active. */
int FIELD_G3D_MAP_WaitLoad(FieldG3dMap *map)
{
    u16 *activeRef;

    map->loadSync = 1;
    do {
        FIELD_G3D_MAP_Update(map);
        FIELD_G3D_MAP_GetActiveRef(map, &activeRef);
    } while (*activeRef != 0);
    map->loadSync = 0;
    return 0;
}

/* Draw the map model and, when it was drawn and has placed models, those models too. */
int FIELD_G3D_MAP_DrawWithModels(FieldG3dMap *map, int arg)
{
    int drawn;

    drawn = 0;
    if (FIELD_G3D_MAP_Draw(map) == 1) {
        if (map->placedModels != 0)
            FIELD_G3D_MAP_DrawPlacedModels(map, arg);
        drawn = 1;
    }
    return drawn;
}

/* Reset the object, clear the render object model and open the archive. */
void FIELD_G3D_MAP_OpenArchive(FieldG3dMap *map, int archiveId, int heapId)
{
    FIELD_G3D_MAP_Reset(map);
    FIELD_G3D_MAP_CloseArchive(map);
    map->renderObjRef->model = 0;
    map->archive = ARC_TOOL_CreateHandle(archiveId, heapId);
}

/* Close the archive if one is open. */
void FIELD_G3D_MAP_CloseArchive(FieldG3dMap *map)
{
    if (map->archive != 0) {
        ARC_TOOL_DeleteHandle(map->archive);
        map->archive = 0;
    }
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_Setup.
 */
void FIELD_G3D_MAP_SetAltTextureRes(FieldG3dMap *map, void *textureRes)
{
    map->altTextureRes = textureRes;
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_ReleaseBlocks.
 */
void FIELD_G3D_MAP_ClearAltTextureRes(FieldG3dMap *map)
{
    map->altTextureRes = 0;
}

void FIELD_G3D_MAP_SetPlacedModels(FieldG3dMap *map, FieldG3dMapModelSet *placedModels)
{
    map->placedModels = placedModels;
}

void FIELD_G3D_MAP_ClearPlacedModels(FieldG3dMap *map)
{
    map->placedModels = 0;
}

/*
 * Unlabelled leaf (blocker of ov021 FIELD_BUILDMODEL_AddEntry).  Stores a 0x14-byte
 * placement (index, position, angle) into entry `index` of table A.
 */
void FIELD_G3D_MAP_SetPlacement(FieldG3dMap *map, FieldG3dMapPlacement *src, u32 index)
{
    map->placementsA[index].modelIndex = src->modelIndex;
    map->placementsA[index].pos = src->pos;
    map->placementsA[index].angle = src->angle;
}

/* Reset the 0x14-byte entry `index` of placement table A. */
void FIELD_G3D_MAP_ClearPlacement(FieldG3dMap *map, u32 index)
{
    FieldG3dMapPlacement *entry;

    if (index == 0xffffffff)
        return;
    if (index >= map->placementCountA)
        return;
    map->placementsA[index].modelIndex = 0xffffffff;
    entry = &map->placementsA[index];
    entry->pos.x = 0;
    entry->pos.y = 0;
    entry->pos.z = 0;
    map->placementsA[index].angle = 0;
}

/*
 * Unlabelled leaf (blocker of ov021 FIELD_BUILDMODEL_AddEntry).  Returns entry `index` of
 * placement table A, or 0 if the index is out of range or the entry is unused
 * (model index -1).
 */
FieldG3dMapPlacement *FIELD_G3D_MAP_GetPlacement(FieldG3dMap *map, u32 index)
{
    FieldG3dMapPlacement *entry;

    if (index >= map->placementCountA)
        return 0;
    entry = &map->placementsA[index];
    if (entry->modelIndex == -1)
        return 0;
    return entry;
}

/* Index of the type table entry whose key equals *key; the table ends with key -1. */
static inline int FIELD_G3D_MAP_FindTypeIndex(const u16 *key, const FieldG3dMapType *typeTable)
{
    unsigned i;

    i = 0;
    while (typeTable[i].key != (-1)) {
        if ((*key) == typeTable[i].key)
            break;
        i++;
    }
    return i;
}

/*
 * Start loading archive member `memberIndex`: read its 2-byte type key, find
 * the block type and mark the object active.
 * stand-in: the two table temporaries and the self-assignment stay; without
 * them the table lands in r0 and the sentinel in r1 (tried: one temporary,
 * none).
 */
void FIELD_G3D_MAP_StartLoad(FieldG3dMap *map, u32 memberIndex)
{
    u16 key;
    const FieldG3dMapType *typeTable;
    int typeIndex;
    const FieldG3dMapType *tableTmp;

    FIELD_G3D_MAP_ClearRenderObjModel(map->renderObjRef);
    FIELD_G3D_MAP_ClearModelRes(map);
    FIELD_G3D_MAP_ClearTextureRes(map);
    FIELD_G3D_MAP_ClearPlacements(map);
    map->memberIndex = memberIndex;
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)map->archive, memberIndex, 0, 2, &key);
    tableTmp = map->typeTable;
    typeTable = map->typeTable;
    typeIndex = FIELD_G3D_MAP_FindTypeIndex(&key, tableTmp);
    typeTable = typeTable;
    map->typeIndex = typeIndex;
    map->active = 1;
}

/* Unload the current member: clear the render object, both resource records and the load state. */
void FIELD_G3D_MAP_Unload(FieldG3dMap *map)
{
    FIELD_G3D_MAP_ClearRenderObjModel(map->renderObjRef);
    FIELD_G3D_MAP_ClearModelRes(map);
    FIELD_G3D_MAP_ClearTextureRes(map);
    FIELD_G3D_MAP_ResetLoadState(map);
    FIELD_G3D_MAP_Reset(map);
}

void FIELD_G3D_MAP_SetVisible(FieldG3dMap *map, u16 visible)
{
    map->visible = visible;
}

u16 FIELD_G3D_MAP_IsVisible(FieldG3dMap *map)
{
    return map->visible;
}

void FIELD_G3D_MAP_SetPos(FieldG3dMap *map, const VecFx32 *pos)
{
    map->pos = *pos;
}

/*
 * Unlabelled leaf (blocker of ov021 FIELD_BUILDMODEL_CreateNodeFromEntry).  Copies the position to dst.
 */
void FIELD_G3D_MAP_GetPos(FieldG3dMap *map, VecFx32 *dst)
{
    *dst = map->pos;
}

/* Store the address of the active flag in *out and return it. */
u16 *FIELD_G3D_MAP_GetActiveRef(FieldG3dMap *map, u16 **out)
{
    u16 *activeRef;

    activeRef = &map->active;
    *out = activeRef;
    return activeRef;
}

/* Unlabelled leaf accessor: copies the data buffer pointer to *out. */
void FIELD_G3D_MAP_GetBuffer(FieldG3dMap *map, u8 **out)
{
    *out = map->buffer;
}

/* Unlabelled leaf accessor: copies the archive member index to *out. */
void FIELD_G3D_MAP_GetMemberIndex(FieldG3dMap *map, u32 *out)
{
    *out = map->memberIndex;
}

/* Unlabelled leaf accessor: copies the total size of the member to *out. */
void FIELD_G3D_MAP_GetTotalBytes(FieldG3dMap *map, u32 *out)
{
    *out = map->totalBytes;
}

/* Unlabelled leaf: tail call that fills the model resource record. */
void FIELD_G3D_MAP_SetModelRes(FieldG3dMap *map, u8 *value)
{
    G3D_SYSTEM_InitResourceByKind(map->modelRes, 1, (void *)value);
}

/* Empty the model resource record. */
void FIELD_G3D_MAP_ClearModelRes(FieldG3dMap *map)
{
    G3D_SYSTEM_InitResourceByKind(map->modelRes, 1, 0);
}

/* Unlabelled leaf accessor: returns the model resource record. */
void *FIELD_G3D_MAP_GetModelRes(FieldG3dMap *map)
{
    return map->modelRes;
}

/* Empty the texture resource record. */
void FIELD_G3D_MAP_ClearTextureRes(FieldG3dMap *map)
{
    G3D_SYSTEM_InitResourceByKind(map->textureRes, 2, 0);
}

/* Unlabelled leaf: forwarding tail call to the texture resource picker. */
void *FIELD_G3D_MAP_GetTextureRes(FieldG3dMap *map)
{
    return FIELD_G3D_MAP_PickTextureRes(map);
}

/* Bind the model and the picked texture resource to the render object. */
void FIELD_G3D_MAP_BindRenderObj(FieldG3dMap *map)
{
    void *textureRes;

    textureRes = FIELD_G3D_MAP_PickTextureRes(map);
    FIELD_G3D_MAP_InitRenderObj(map->renderObjRef, map->modelRes, textureRes);
}

/* Unlabelled leaf accessor: returns the render object pointer. */
FieldG3dMapRenderObj *FIELD_G3D_MAP_GetRenderObj(FieldG3dMap *map)
{
    return map->renderObjRef;
}

/* Clear the load progress fields. */
void FIELD_G3D_MAP_ResetLoadState(FieldG3dMap *map)
{
    map->bufferOffset = 0;
    map->resetFlag = 0;
    map->readFinished = 0;
    map->buildStarted = 0;
    map->dataReady = 0;
}

/*
 * Start reading member `member`: in synchronous mode read it whole, otherwise
 * read the first chunk. lever: the archive length call takes the still-live
 * member argument.
 */
void FIELD_G3D_MAP_BeginChunkedLoad(FieldG3dMap *map, u32 member)
{
    u8 *dst;

    if (map->loadSync != 0) {
        FIELD_G3D_MAP_ReadWhole(map, member);
        return;
    }
    dst = map->buffer + map->bufferOffset;
    map->totalBytes = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)map->archive, member);
    map->loadedBytes = 0;
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)map->archive, member, 0, map->chunkSize, dst);
    map->bufferOffset = map->bufferOffset + map->chunkSize;
    map->loadedBytes = map->loadedBytes + map->chunkSize;
}

/* Read the next chunk of the member; returns 1 while more chunks remain. */
int FIELD_G3D_MAP_ReadNextChunk(FieldG3dMap *map)
{
    u8 *buffer;
    u32 offset;
    u32 loaded;
    u32 total;
    u32 remaining;

    buffer = map->buffer;
    offset = map->bufferOffset;
    loaded = map->loadedBytes;
    total = map->totalBytes;
    if (total <= loaded)
        return 0;
    remaining = total - loaded;
    if (remaining > map->chunkSize) {
        ARC_TOOL_ReadHandle((struct ArcHandleRaw *)map->archive, map->chunkSize, buffer + offset);
        map->bufferOffset = map->bufferOffset + map->chunkSize;
        map->loadedBytes = map->loadedBytes + map->chunkSize;
        return 1;
    }
    ARC_TOOL_ReadHandle((struct ArcHandleRaw *)map->archive, remaining, buffer + offset);
    map->bufferOffset = map->bufferOffset + remaining;
    return 0;
}

/* Draw the map model at its position when it is visible and its box test passes; returns 1 if drawn. */
int FIELD_G3D_MAP_Draw(FieldG3dMap *map)
{
    int drawn;

    drawn = 0;
    if (map->visible != 0 && map->renderObjRef->model != 0) {
        NNS_G3dGlbBaseTrans((struct VecFx32 *)d_0217216C);
        MI_Copy36B(d_02172178, d_02148C08);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale((struct VecFx32 *)d_02172160);
        NNS_G3dGlbFlush();
        NNS_G3dGeBufferOP_N(0x15, 0, 0);
        NNS_G3dGeBufferOP_N(0x17, gG3dBaseMtx43, 0xc);
        NNS_G3dGeBufferOP_N(0x1c, &map->pos, 3);
        if (FIELD_G3D_MAP_TestModelBox(map->renderObjRef->model) == 1) {
            G3D_SYSTEM_DrawRenderObj((struct NNSG3dRenderObj *)map->renderObjRef);
            drawn = 1;
        }
    }
    return drawn;
}

/*
 * Draws each placed model: for every 0x14-byte entry of table A (count u16 at
 * +0xA4) whose index is valid in the model set, loads the base matrix
 * (pipeline command 0x17, 4x3 load), multiplies in a Y rotation by the
 * entry's angle translated by the map position plus the entry's position
 * (command 0x19, 4x3 multiply), box-tests the model and draws it.
 */
void FIELD_G3D_MAP_DrawPlacedModels(FieldG3dMap *map, int unused)
{
    FieldG3dMapModelRes *modelRes = map->placedModels->res;
    u32 count = map->placedModels->count;
    int i;

    if (count == 0 || modelRes == 0) {
        return;
    }
    for (i = 0; i < map->placementCountA; i++) {
        u32 modelIndex = map->placementsA[i].modelIndex;
        FieldG3dMapRenderObj *renderObj;
        FieldG3dMapModel *model;
        FieldG3dMapMtx43 mtx;
        short sinAngle;
        short cosAngle;
        int angleIndex;

        if (modelIndex == (u32)-1 || modelIndex >= count) {
            continue;
        }
        renderObj = (struct FieldG3dMapRenderObj *)(struct FieldG3dMapRenderObj *)G3D_SYSTEM_GetRenderObj(G3D_SYSTEM_GetObjectRender(modelRes[modelIndex].modelData));
        model = renderObj->model;
        if (model == 0) {
            continue;
        }
        angleIndex = map->placementsA[i].angle >> 4;
        sinAngle = FX_SinCosTable_[angleIndex * 2];
        cosAngle = FX_SinCosTable_[angleIndex * 2 + 1];
        NNS_G3dGeBufferOP_N(0x17, gG3dBaseMtx43, 12);
        VEC_Add((void *)(&map->pos), (void *)(&map->placementsA[i].pos), &mtx.trans);
        MTX_RotY33_(&mtx, sinAngle, cosAngle);
        NNS_G3dGeBufferOP_N(0x19, &mtx, 12);
        if (FIELD_G3D_MAP_TestModelBox(model) == 1) {
            G3D_SYSTEM_DrawRenderObj((struct NNSG3dRenderObj *)renderObj);
        }
    }
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 FIELD_G3D_MAPPER_CheckSlotReady.  Returns 1 if data is ready and the block
 * type has a hit query callback.
 */
int FIELD_G3D_MAP_CanQueryHits(FieldG3dMap *map)
{
    if (map->dataReady == 0
        || map->typeTable[map->typeIndex].queryHits == 0)
        return 0;
    return 1;
}

/* Query the hits of the block type at `pos` (relative to the map position). */
void FIELD_G3D_MAP_QueryHits(FieldG3dMapHitList *out, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize)
{
    VecFx32 localPos;
    u32 height;
    FieldG3dMapQueryFunc query;

    out->count = 0;
    if (map->dataReady != 0) {
        height = map->pos.y;
        VEC_Subtract((void *)pos, (void *)(&map->pos), &localPos);
        query = map->typeTable[map->typeIndex].queryHits;
        if (query != 0)
            query(out, map->buffer, &localPos, gridSize, height);
    }
}

/*
 * Query the plane of the block type at `pos` into `plane` (0x41 words).
 * extent: trailing two-byte alignment padding.
 * output proof: VEC_Subtract stores localPos at 0207CA20/0207CA28; the
 * callback receives that initialized three-word vector, with original arity.
 */
void FIELD_G3D_MAP_QueryPlane(u32 *plane, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize)
{
    VecFx32 localPos;
    FieldG3dMapQueryFunc query;

    VEC_Subtract((void *)pos, (void *)(&map->pos), &localPos);
    query = map->typeTable[map->typeIndex].queryPlane;
    query(plane, map->buffer, &localPos, gridSize, map->pos.y);
}

/*
 * Reset both placement tables (model index -1, zero position and angle).
 * The second loop's final store goes through table A, as the bytes show.
 */
void FIELD_G3D_MAP_ClearPlacements(FieldG3dMap *map)
{
    int i;
    FieldG3dMapPlacement *entry;

    for (i = 0; i < map->placementCountA; i++) {
        map->placementsA[i].modelIndex = -1;
        entry = &map->placementsA[i];
        entry->pos.x = 0;
        entry->pos.y = 0;
        entry->pos.z = 0;
        map->placementsA[i].angle = 0;
    }
    for (i = 0; i < map->placementCountB; i++) {
        map->placementsB[i].modelIndex = -1;
        entry = &map->placementsB[i];
        entry->pos.x = 0;
        entry->pos.y = 0;
        entry->pos.z = 0;
        map->placementsA[i].angle = 0;
    }
}

/* Reset visibility, position, member index and active flag, and clear the placement tables. */
void FIELD_G3D_MAP_Reset(FieldG3dMap *map)
{
    map->visible = 0;
    map->pos.x = 0;
    map->pos.y = 0;
    map->pos.z = 0;
    map->active = 0;
    map->memberIndex = 0;
    FIELD_G3D_MAP_ClearPlacements(map);
}

/* Data pointer of entry `index` of the dictionary in `dict`, or 0 if out of range. */
static inline u32 *FIELD_G3D_MAP_GetDictData(FieldG3dMapDictBlock *dict, u32 index)
{
    u8 *head;

    head = (u8 *)dict + 8;
    if (head != 0 && index < dict->count)
        return (u32 *)(head + dict->entryOffset + 4 + index * 4);
    return 0;
}

/* Initialize the render object from the model resource and bind the texture resource to it. */
void FIELD_G3D_MAP_InitRenderObj(FieldG3dMapRenderObj *renderObj, void *modelRes, void *textureRes)
{
    u8 *modelFile;
    u32 *entry;
    u8 *model;
    void *texture;
    void *textureFile;

    model = G3D_SYSTEM_GetResourceFile(modelRes);
    textureFile = G3D_SYSTEM_GetResourceFile(textureRes);
    texture = 0;
    modelFile = (u8 *)NNS_G3dGetMdlSet((sptr)model);
    if (modelFile != 0 && (entry = FIELD_G3D_MAP_GetDictData((FieldG3dMapDictBlock *)modelFile, 0)) != 0)
        model = modelFile + *entry;
    else
        model = 0;
    if (textureFile != 0)
        texture = NNS_G3dGetTex(textureFile);
    if (texture != 0) {
        NNS_G3dBindMdlTex((struct NNSG3dResMdl *)model, (struct NNSG3dResTex *)texture);
        NNS_G3dBindMdlPltt((struct NNSG3dResMdl *)model, (struct NNSG3dResTex *)texture);
    }
    NNS_G3dRenderObjInit((struct NNSG3dRenderObj *)renderObj, (uptr)model);
}

/* Clear the model of the render object; returns the render object. */
FieldG3dMapRenderObj *FIELD_G3D_MAP_ClearRenderObjModel(FieldG3dMapRenderObj *renderObj)
{
    renderObj->model = 0;
    return renderObj;
}

/*
 * Box test of the model bounding box (pipeline commands 0x11 push, 0x1b
 * scale, 0x12 pop around the test); returns 0 if the box is outside.
 */
int FIELD_G3D_MAP_TestModelBox(FieldG3dMapModel *model)
{
    short box[6];
    u32 scale[3];
    u32 one;
    FieldG3dMapModelInfo *info;
    int visible;

    visible = 1;
    info = model ? &model->info : 0;
    box[0] = info->boxX;
    box[1] = info->boxY;
    box[2] = info->boxZ;
    box[3] = info->boxW;
    box[4] = info->boxH;
    box[5] = info->boxD;
    NNS_G3dGeBufferOP_N(0x11, 0, 0);
    scale[0] = info->boxPosScale;
    scale[1] = scale[0];
    scale[2] = scale[0];
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    if (FIELD_G3D_MAP_RunBoxTest(box) == 0)
        visible = 0;
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    return visible;
}

/* Run a box test of the 6 halfwords at `box` and wait for the result; returns it. */
u32 FIELD_G3D_MAP_RunBoxTest(const short *box)
{
    int result;
    u32 polygonAttr;
    u32 beginMode;

    result = 1;
    polygonAttr = 0x30C1;
    NNS_G3dGeBufferOP_N(0x29, &polygonAttr, 1);
    beginMode = 0;
    NNS_G3dGeBufferOP_N(0x40, &beginMode, 1);
    NNS_G3dGeBufferOP_N(0x41, 0, 0);
    NNS_G3dGeBufferOP_N(0x70, box, 3);
    NNS_G3dGeFlushBuffer();
    while (G3X_GetBoxTestResult(&result) != 0)
        ;
    return result;
}

/*
 * Pick the texture resource record: the main one when it holds a resource,
 * else the alternate one if set, else the main one anyway.
 */
void *FIELD_G3D_MAP_PickTextureRes(FieldG3dMap *map)
{
    void *textureRes;

    textureRes = G3D_SYSTEM_GetResourceFile(map->textureRes);
    if (textureRes == 0) {
        textureRes = map->altTextureRes;
        if (textureRes != 0)
            return textureRes;
    }
    return map->textureRes;
}

/* Read the whole member `member` into the buffer in one step. */
void FIELD_G3D_MAP_ReadWhole(FieldG3dMap *map, u32 member)
{
    void *dst;
    u32 size;

    dst = map->buffer;
    size = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)map->archive, member);
    ARC_TOOL_ReadHandleMember((struct ArcHandle *)map->archive, member, dst);
    map->totalBytes = size;
    map->bufferOffset = size;
    map->loadedBytes = size;
}
