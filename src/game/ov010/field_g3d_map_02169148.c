/*
 * file:     field_g3d_map_02169148.c
 * unit:     yes
 * function: func_02169148, func_0216928C, func_02169308, func_0216932C, func_02169354, func_0216937C, func_021693A0, func_021693B4, func_021693BC, func_021693C4, func_021693CC, func_021693D4, func_0216940C, func_02169444, func_02169470, func_021694D4, func_021694F8, func_021694FC, func_02169500, func_02169510, func_02169520, func_02169528, func_02169530, func_02169538, func_02169540, func_02169550, func_02169560, func_02169568, func_02169578, func_02169580, func_02169598, func_0216959C, func_021695BC, func_02169620, func_0216968C, func_02169710, func_021697E0, func_02169800, func_02169848, func_02169880, func_0216990C, func_02169928, func_02169998, func_021699A0, func_02169A14, func_02169A68, func_02169A88
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
 *   func_020307B0  0x020307B0  arm
 *   sub_02030734   0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   d_02172A40     0x02172A40  data
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049238  0x02049238  arm
 *   func_0204944C  0x0204944C  arm
 *   func_02046C9C 0x02046C9C arm
 *   func_020493D4  0x020493D4  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   NNS_G3dGlbBaseTrans  0x0206A9DC  arm
 *   func_02082B60  0x02082B60  arm
 *   NNS_G3dGlbBaseScale  0x0206AA0C  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   G3D_SYSTEM_DrawRenderObj  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   d_02148B98     0x02148B98  data   a4
 *   func_02047788  0x02047788  arm
 *   func_0204755C  0x0204755C  arm
 *   VEC_Add        0x0207C9D0  arm
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   func_0207CA00  0x0207CA00  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_0206E964  0x0206E964  arm
 *   func_0206A2CC  0x0206A2CC  arm
 *   func_0206A4AC  0x0206A4AC  arm
 *   func_02069D14  0x02069D14  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_0204932C 0x0204932C arm
 */
#include "field_g3d_map_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern u32 func_020307B0(void *p);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern int func_02046C94(void);
extern ArcFile *func_020490F4(unsigned int id, unsigned int heapId);
extern void func_02049238(ArcFile *archive);
extern void func_0204944C(ArcFile *archive, u32 member, u32 offset, u32 size, void *dst);
extern void func_02046C9C(void *record, u32 mode, u32 value);
extern u32 func_020493D4(ArcFile *archive, u32 member);
extern void ARC_TOOL_ReadHandle(ArcFile *archive, u32 size, void *dst);
extern void NNS_G3dGlbBaseTrans(void *p);
extern void func_02082B60(void *a, void *b);
extern void NNS_G3dGlbBaseScale(void *p);
extern void func_0206A854(void);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void G3D_SYSTEM_DrawRenderObj(FieldG3dMapRenderObj *renderObj);
extern void *func_02047788(void *res);
extern FieldG3dMapRenderObj *func_0204755C(void *res);
extern void VEC_Add(const FieldG3dMapVec *a, const FieldG3dMapVec *b, FieldG3dMapVec *dst);
extern void MTX_RotY33_(void *m, short sinv, short cosv);
extern void func_0207CA00(const FieldG3dMapVec *pos, const FieldG3dMapVec *origin, FieldG3dMapVec *out);
extern void *func_02046F48(void *handle);
extern int func_0206E954(int p0);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0206A2CC(void *a, void *b);
extern void func_0206A4AC(void *a, void *b);
extern void func_02069D14(void *a, void *b);
extern void func_0206DB80(void);
extern int func_0207DEA4(int *result);
extern void func_0204932C(ArcFile *archive, u32 member, void *dst);
FieldG3dMap *func_02169148(const FieldG3dMapConfig *cfg, u32 heapId);
void func_0216928C(FieldG3dMap *map);
void func_02169308(FieldG3dMap *map);
int func_0216932C(FieldG3dMap *map);
int func_02169354(FieldG3dMap *map, int arg);
void func_0216937C(FieldG3dMap *map, int archiveId, int heapId);
void func_021693A0(FieldG3dMap *map);
void func_021693B4(FieldG3dMap *map, void *textureRes);
void func_021693BC(FieldG3dMap *map);
void func_021693C4(FieldG3dMap *map, FieldG3dMapModelSet *placedModels);
void func_021693CC(FieldG3dMap *map);
void func_021693D4(FieldG3dMap *map, FieldG3dMapPlacement *src, u32 index);
void func_0216940C(FieldG3dMap *map, u32 index);
FieldG3dMapPlacement *func_02169444(FieldG3dMap *map, u32 index);
void func_02169470(FieldG3dMap *map, u32 memberIndex);
void func_021694D4(FieldG3dMap *map, int unused);
void func_021694F8(FieldG3dMap *map, u16 visible);
u16 func_021694FC(FieldG3dMap *map);
void func_02169500(FieldG3dMap *map, const FieldG3dMapVec *pos);
void func_02169510(FieldG3dMap *map, FieldG3dMapVec *dst);
u16 *func_02169520(FieldG3dMap *map, u16 **out);
void func_02169528(FieldG3dMap *map, u8 **out);
void func_02169530(FieldG3dMap *map, u32 *out);
void func_02169538(FieldG3dMap *map, u32 *out);
void func_02169540(FieldG3dMap *map, u32 value);
void func_02169550(FieldG3dMap *map);
void *func_02169560(FieldG3dMap *map);
void func_02169568(FieldG3dMap *map);
void *func_02169578(FieldG3dMap *map);
void func_02169580(FieldG3dMap *map);
FieldG3dMapRenderObj *func_02169598(FieldG3dMap *map);
void func_0216959C(FieldG3dMap *map);
void func_021695BC(FieldG3dMap *map, u32 member);
int func_02169620(FieldG3dMap *map);
int func_0216968C(FieldG3dMap *map);
void func_02169710(FieldG3dMap *map, int unused);
int func_021697E0(FieldG3dMap *map);
void func_02169800(FieldG3dMapHitList *out, FieldG3dMap *map, const FieldG3dMapVec *pos, u32 gridSize);
void func_02169848(u32 *plane, FieldG3dMap *map, const FieldG3dMapVec *pos, u32 gridSize);
void func_02169880(FieldG3dMap *map);
void func_0216990C(FieldG3dMap *map);
void func_02169928(FieldG3dMapRenderObj *renderObj, void *modelRes, void *textureRes);
FieldG3dMapRenderObj *func_02169998(FieldG3dMapRenderObj *renderObj, int unused);
int func_021699A0(FieldG3dMapModel *model);
u32 func_02169A14(const short *box);
void *func_02169A68(FieldG3dMap *map);
void func_02169A88(FieldG3dMap *map, u32 member);

extern const char d_02172A40[];
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern FieldG3dMapGlbState d_02148BCC;
extern u8 d_02172160[];
extern u8 d_02148B98[];
extern short tbl_020A1B38[];
extern u32 (*g_020A8140)(u32 size, u32 is4x4, u32 opt);
extern u32 (*g_020A8148)(u32 size, u32 is4pltt, u32 opt);
extern void (*d_020A814C)(u32);
extern void (*d_020A8144)(u32);

/*
 * Create the 0xDC-byte map object from its config: two placement tables,
 * the data buffer, two resource records, and the texture and palette VRAM
 * keys through the allocator hooks. Levers: the buffer size from cfg (not the
 * just-stored copy), and the render object model cleared through renderObjRef.
 */
FieldG3dMap *func_02169148(const FieldG3dMapConfig *cfg, u32 heapId)
{
    FieldG3dMap *map;
    u32 recordSize;

    map = sub_02030734(heapId, sizeof(FieldG3dMap), 1, d_02172A40, 0x6E);
    recordSize = func_02046C94();
    map->placementCountA = cfg->placementCountA;
    map->placementCountB = cfg->placementCountB;
    map->extraParam0 = cfg->extraParam0;
    map->extraParam1 = cfg->extraParam1;
    if (map->placementCountA != 0)
        map->placementsA = sub_02030734(heapId, cfg->placementCountA * 20, 1, d_02172A40, 0x77);
    if (map->placementCountB != 0)
        map->placementsB = sub_02030734(heapId, cfg->placementCountB * 20, 1, d_02172A40, 0x7A);
    func_0216990C(map);
    map->typeTable = cfg->typeTable;
    map->bufferSize = cfg->bufferSize;
    map->buffer = sub_02030734(heapId, cfg->bufferSize, 1, d_02172A40, 0x86);
    if (cfg->chunkSize == 0)
        map->chunkSize = 0x800;
    else
        map->chunkSize = cfg->chunkSize;
    map->userParam = cfg->userParam;
    map->renderObjRef = &map->renderObj;
    map->renderObjRef->model = 0;
    map->archive = 0;
    map->modelRes = sub_02030734(heapId, recordSize, 1, d_02172A40, 0x97);
    map->textureRes = sub_02030734(heapId, recordSize, 1, d_02172A40, 0x9A);
    map->altTextureRes = 0;
    if (cfg->texVramSize != 0) {
        map->texVramSize = cfg->texVramSize;
        map->texKey = g_020A8140(cfg->texVramSize, 0, 0);
        map->plttKey = g_020A8148(0x200, 0, 0);
    } else {
        map->texVramSize = 0;
        map->texKey = 0;
        map->plttKey = 0;
    }
    return map;
}

/* Destroy the map object: close the archive, free the VRAM keys and every buffer. */
void func_0216928C(FieldG3dMap *map)
{
    func_021693A0(map);
    if (map->texVramSize != 0) {
        d_020A814C(map->plttKey);
        d_020A8144(map->texKey);
    }
    func_020307B0(map->textureRes);
    func_020307B0(map->modelRes);
    func_020307B0(map->buffer);
    if (map->placementCountA != 0)
        func_020307B0(map->placementsA);
    if (map->placementCountB != 0)
        func_020307B0(map->placementsB);
    func_020307B0(map);
}

/*
 * Update step: call the update callback of the block type while the object is
 * active. Address arithmetic: the unsigned 32-bit index scaling and base
 * addition keep the original lsls/adds wraparound without an invented bound.
 */
void func_02169308(FieldG3dMap *map)
{
    FieldG3dMapUpdateFunc update;

    if (map->active) {
        update = map->typeTable[map->typeIndex].update;
        if (update)
            update(map, map->userParam);
    }
}

/* Run update steps in synchronous load mode until the object is no longer active. */
int func_0216932C(FieldG3dMap *map)
{
    u16 *activeRef;

    map->loadSync = 1;
    do {
        func_02169308(map);
        func_02169520(map, &activeRef);
    } while (*activeRef != 0);
    map->loadSync = 0;
    return 0;
}

/* Draw the map model and, when it was drawn and has placed models, those models too. */
int func_02169354(FieldG3dMap *map, int arg)
{
    int drawn;

    drawn = 0;
    if (func_0216968C(map) == 1) {
        if (map->placedModels != 0)
            func_02169710(map, arg);
        drawn = 1;
    }
    return drawn;
}

/* Reset the object, clear the render object model and open the archive. */
void func_0216937C(FieldG3dMap *map, int archiveId, int heapId)
{
    func_0216990C(map);
    func_021693A0(map);
    map->renderObjRef->model = 0;
    map->archive = func_020490F4(archiveId, heapId);
}

/* Close the archive if one is open. */
void func_021693A0(FieldG3dMap *map)
{
    if (map->archive != 0) {
        func_02049238(map->archive);
        map->archive = 0;
    }
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218CEE4.
 */
void func_021693B4(FieldG3dMap *map, void *textureRes)
{
    map->altTextureRes = textureRes;
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218D05C.
 */
void func_021693BC(FieldG3dMap *map)
{
    map->altTextureRes = 0;
}

void func_021693C4(FieldG3dMap *map, FieldG3dMapModelSet *placedModels)
{
    map->placedModels = placedModels;
}

void func_021693CC(FieldG3dMap *map)
{
    map->placedModels = 0;
}

/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Stores a 0x14-byte
 * placement (index, position, angle) into entry `index` of table A.
 */
void func_021693D4(FieldG3dMap *map, FieldG3dMapPlacement *src, u32 index)
{
    map->placementsA[index].modelIndex = src->modelIndex;
    map->placementsA[index].pos = src->pos;
    map->placementsA[index].angle = src->angle;
}

/* Reset the 0x14-byte entry `index` of placement table A. */
void func_0216940C(FieldG3dMap *map, u32 index)
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
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Returns entry `index` of
 * placement table A, or 0 if the index is out of range or the entry is unused
 * (model index -1).
 */
FieldG3dMapPlacement *func_02169444(FieldG3dMap *map, u32 index)
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
void func_02169470(FieldG3dMap *map, u32 memberIndex)
{
    u16 key;
    const FieldG3dMapType *typeTable;
    int typeIndex;
    const FieldG3dMapType *tableTmp;

    func_02169998(map->renderObjRef, memberIndex);
    func_02169550(map);
    func_02169568(map);
    func_02169880(map);
    map->memberIndex = memberIndex;
    func_0204944C(map->archive, memberIndex, 0, 2, &key);
    tableTmp = map->typeTable;
    typeTable = map->typeTable;
    typeIndex = FIELD_G3D_MAP_FindTypeIndex(&key, tableTmp);
    typeTable = typeTable;
    map->typeIndex = typeIndex;
    map->active = 1;
}

/* Unload the current member: clear the render object, both resource records and the load state. */
void func_021694D4(FieldG3dMap *map, int unused)
{
    func_02169998(map->renderObjRef, unused);
    func_02169550(map);
    func_02169568(map);
    func_0216959C(map);
    func_0216990C(map);
}

void func_021694F8(FieldG3dMap *map, u16 visible)
{
    map->visible = visible;
}

u16 func_021694FC(FieldG3dMap *map)
{
    return map->visible;
}

void func_02169500(FieldG3dMap *map, const FieldG3dMapVec *pos)
{
    map->pos = *pos;
}

/*
 * Unlabelled leaf (blocker of ov021 func_0218C724).  Copies the position to dst.
 */
void func_02169510(FieldG3dMap *map, FieldG3dMapVec *dst)
{
    *dst = map->pos;
}

/* Store the address of the active flag in *out and return it. */
u16 *func_02169520(FieldG3dMap *map, u16 **out)
{
    u16 *activeRef;

    activeRef = &map->active;
    *out = activeRef;
    return activeRef;
}

/* Unlabelled leaf accessor: copies the data buffer pointer to *out. */
void func_02169528(FieldG3dMap *map, u8 **out)
{
    *out = map->buffer;
}

/* Unlabelled leaf accessor: copies the archive member index to *out. */
void func_02169530(FieldG3dMap *map, u32 *out)
{
    *out = map->memberIndex;
}

/* Unlabelled leaf accessor: copies the total size of the member to *out. */
void func_02169538(FieldG3dMap *map, u32 *out)
{
    *out = map->totalBytes;
}

/* Unlabelled leaf: tail call that fills the model resource record. */
void func_02169540(FieldG3dMap *map, u32 value)
{
    func_02046C9C(map->modelRes, 1, value);
}

/* Empty the model resource record. */
void func_02169550(FieldG3dMap *map)
{
    func_02046C9C(map->modelRes, 1, 0);
}

/* Unlabelled leaf accessor: returns the model resource record. */
void *func_02169560(FieldG3dMap *map)
{
    return map->modelRes;
}

/* Empty the texture resource record. */
void func_02169568(FieldG3dMap *map)
{
    func_02046C9C(map->textureRes, 2, 0);
}

/* Unlabelled leaf: forwarding tail call to the texture resource picker. */
void *func_02169578(FieldG3dMap *map)
{
    return func_02169A68(map);
}

/* Bind the model and the picked texture resource to the render object. */
void func_02169580(FieldG3dMap *map)
{
    void *textureRes;

    textureRes = func_02169A68(map);
    func_02169928(map->renderObjRef, map->modelRes, textureRes);
}

/* Unlabelled leaf accessor: returns the render object pointer. */
FieldG3dMapRenderObj *func_02169598(FieldG3dMap *map)
{
    return map->renderObjRef;
}

/* Clear the load progress fields. */
void func_0216959C(FieldG3dMap *map)
{
    map->bufferOffset = 0;
    map->loadStageA = 0;
    map->loadStageC = 0;
    map->loadStageD = 0;
    map->dataReady = 0;
}

/*
 * Start reading member `member`: in synchronous mode read it whole, otherwise
 * read the first chunk. lever: the archive length call takes the still-live
 * member argument.
 */
void func_021695BC(FieldG3dMap *map, u32 member)
{
    u8 *dst;

    if (map->loadSync != 0) {
        func_02169A88(map, member);
        return;
    }
    dst = map->buffer + map->bufferOffset;
    map->totalBytes = func_020493D4(map->archive, member);
    map->loadedBytes = 0;
    func_0204944C(map->archive, member, 0, map->chunkSize, dst);
    map->bufferOffset = map->bufferOffset + map->chunkSize;
    map->loadedBytes = map->loadedBytes + map->chunkSize;
}

/* Read the next chunk of the member; returns 1 while more chunks remain. */
int func_02169620(FieldG3dMap *map)
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
        ARC_TOOL_ReadHandle(map->archive, map->chunkSize, buffer + offset);
        map->bufferOffset = map->bufferOffset + map->chunkSize;
        map->loadedBytes = map->loadedBytes + map->chunkSize;
        return 1;
    }
    ARC_TOOL_ReadHandle(map->archive, remaining, buffer + offset);
    map->bufferOffset = map->bufferOffset + remaining;
    return 0;
}

/* Draw the map model at its position when it is visible and its box test passes; returns 1 if drawn. */
int func_0216968C(FieldG3dMap *map)
{
    int drawn;

    drawn = 0;
    if (map->visible != 0 && map->renderObjRef->model != 0) {
        NNS_G3dGlbBaseTrans(d_0217216C);
        func_02082B60(d_02172178, d_02148C08);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale(d_02172160);
        func_0206A854();
        func_0206DDA4(0x15, 0, 0);
        func_0206DDA4(0x17, d_02148B98, 0xc);
        func_0206DDA4(0x1c, &map->pos, 3);
        if (func_021699A0(map->renderObjRef->model) == 1) {
            G3D_SYSTEM_DrawRenderObj(map->renderObjRef);
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
void func_02169710(FieldG3dMap *map, int unused)
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
        renderObj = func_0204755C(func_02047788(modelRes[modelIndex].modelData));
        model = renderObj->model;
        if (model == 0) {
            continue;
        }
        angleIndex = map->placementsA[i].angle >> 4;
        sinAngle = tbl_020A1B38[angleIndex * 2];
        cosAngle = tbl_020A1B38[angleIndex * 2 + 1];
        func_0206DDA4(0x17, d_02148B98, 12);
        VEC_Add(&map->pos, &map->placementsA[i].pos, &mtx.trans);
        MTX_RotY33_(&mtx, sinAngle, cosAngle);
        func_0206DDA4(0x19, &mtx, 12);
        if (func_021699A0(model) == 1) {
            G3D_SYSTEM_DrawRenderObj(renderObj);
        }
    }
}

/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218DBD4.  Returns 1 if data is ready and the block
 * type has a hit query callback.
 */
int func_021697E0(FieldG3dMap *map)
{
    if (map->dataReady == 0
        || map->typeTable[map->typeIndex].queryHits == 0)
        return 0;
    return 1;
}

/* Query the hits of the block type at `pos` (relative to the map position). */
void func_02169800(FieldG3dMapHitList *out, FieldG3dMap *map, const FieldG3dMapVec *pos, u32 gridSize)
{
    FieldG3dMapVec localPos;
    u32 height;
    FieldG3dMapQueryFunc query;

    out->count = 0;
    if (map->dataReady != 0) {
        height = map->pos.y;
        func_0207CA00(pos, &map->pos, &localPos);
        query = map->typeTable[map->typeIndex].queryHits;
        if (query != 0)
            query(out, map->buffer, &localPos, gridSize, height);
    }
}

/*
 * Query the plane of the block type at `pos` into `plane` (0x41 words).
 * extent: trailing two-byte alignment padding.
 * output proof: func_0207CA00 stores localPos at 0207CA20/0207CA28; the
 * callback receives that initialized three-word vector, with original arity.
 */
void func_02169848(u32 *plane, FieldG3dMap *map, const FieldG3dMapVec *pos, u32 gridSize)
{
    FieldG3dMapVec localPos;
    FieldG3dMapQueryFunc query;

    func_0207CA00(pos, &map->pos, &localPos);
    query = map->typeTable[map->typeIndex].queryPlane;
    query(plane, map->buffer, &localPos, gridSize, map->pos.y);
}

/*
 * Reset both placement tables (model index -1, zero position and angle).
 * The second loop's final store goes through table A, as the bytes show.
 */
void func_02169880(FieldG3dMap *map)
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
void func_0216990C(FieldG3dMap *map)
{
    map->visible = 0;
    map->pos.x = 0;
    map->pos.y = 0;
    map->pos.z = 0;
    map->active = 0;
    map->memberIndex = 0;
    func_02169880(map);
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
void func_02169928(FieldG3dMapRenderObj *renderObj, void *modelRes, void *textureRes)
{
    u8 *modelFile;
    u32 *entry;
    u8 *model;
    void *texture;
    void *textureFile;

    model = func_02046F48(modelRes);
    textureFile = func_02046F48(textureRes);
    texture = 0;
    modelFile = (u8 *)func_0206E954((int)model);
    if (modelFile != 0 && (entry = FIELD_G3D_MAP_GetDictData((FieldG3dMapDictBlock *)modelFile, 0)) != 0)
        model = modelFile + *entry;
    else
        model = 0;
    if (textureFile != 0)
        texture = func_0206E964(textureFile);
    if (texture != 0) {
        func_0206A2CC(model, texture);
        func_0206A4AC(model, texture);
    }
    func_02069D14(renderObj, model);
}

/* Clear the model of the render object; returns the render object. */
FieldG3dMapRenderObj *func_02169998(FieldG3dMapRenderObj *renderObj, int unused)
{
    renderObj->model = 0;
    return renderObj;
}

/*
 * Box test of the model bounding box (pipeline commands 0x11 push, 0x1b
 * scale, 0x12 pop around the test); returns 0 if the box is outside.
 */
int func_021699A0(FieldG3dMapModel *model)
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
    func_0206DDA4(0x11, 0, 0);
    scale[0] = info->boxPosScale;
    scale[1] = scale[0];
    scale[2] = scale[0];
    func_0206DDA4(0x1b, scale, 3);
    if (func_02169A14(box) == 0)
        visible = 0;
    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return visible;
}

/* Run a box test of the 6 halfwords at `box` and wait for the result; returns it. */
u32 func_02169A14(const short *box)
{
    int result;
    u32 polygonAttr;
    u32 beginMode;

    result = 1;
    polygonAttr = 0x30C1;
    func_0206DDA4(0x29, &polygonAttr, 1);
    beginMode = 0;
    func_0206DDA4(0x40, &beginMode, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, box, 3);
    func_0206DB80();
    while (func_0207DEA4(&result) != 0)
        ;
    return result;
}

/*
 * Pick the texture resource record: the main one when it holds a resource,
 * else the alternate one if set, else the main one anyway.
 */
void *func_02169A68(FieldG3dMap *map)
{
    void *textureRes;

    textureRes = func_02046F48(map->textureRes);
    if (textureRes == 0) {
        textureRes = map->altTextureRes;
        if (textureRes != 0)
            return textureRes;
    }
    return map->textureRes;
}

/* Read the whole member `member` into the buffer in one step. */
void func_02169A88(FieldG3dMap *map, u32 member)
{
    void *dst;
    u32 size;

    dst = map->buffer;
    size = func_020493D4(map->archive, member);
    func_0204932C(map->archive, member, dst);
    map->totalBytes = size;
    map->bufferOffset = size;
    map->loadedBytes = size;
}
