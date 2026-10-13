/*
 * file:     field_buildmodel.c
 * unit:     yes
 * function: func_0218B754, func_0218B7F8, func_0218B83C, func_0218B88C, func_0218B8AC, func_0218B910, func_0218B924, func_0218B930, func_0218B974, func_0218B9FC, func_0218BA04, func_0218BA48, func_0218BA70, func_0218BA98, func_0218BACC, func_0218BB04, func_0218BB0C, func_0218BB64, func_0218BB78, func_0218BBD0, func_0218BBF4, func_0218BC00, func_0218BC10, func_0218BC1C, func_0218BC40, func_0218BC6C, func_0218BC8C, func_0218BCAC, func_0218BCB0, func_0218BCE4, func_0218BCF4, func_0218BD20, func_0218BD24, func_0218BD28, func_0218BD94, func_0218BDD8, func_0218BE84, func_0218BEE8, func_0218BF84, func_0218BFB4, func_0218C02C, func_0218C040, func_0218C08C, func_0218C0D8, func_0218C124, func_0218C150, func_0218C154, func_0218C1A4, func_0218C1C4, func_0218C23C, func_0218C290, func_0218C2E4, func_0218C350, func_0218C388, func_0218C3B0, func_0218C3E0, func_0218C438, func_0218C43C, func_0218C47C, func_0218C490, func_0218C4A0, func_0218C4EC, func_0218C518, func_0218C530, func_0218C54C, func_0218C574, func_0218C584, func_0218C638, func_0218C654, func_0218C674, func_0218C69C, func_0218C6D0, func_0218C6F4, func_0218C724, func_0218C7D8, func_0218C7F0, func_0218C860, func_0218C88C, func_0218C89C, func_0218C8B0, func_0218C8D8, func_0218C8FC, func_0218C910, func_0218C924, func_0218C934, func_0218C944, func_0218C990, func_0218C9A4, func_0218C9C4
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
 *   func_02030734  0x02030734  arm
 *   d_021DD9CC     0x021DD9CC  data  ov021  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02013B38  0x02013B38  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204961C  0x0204961C  arm
 *   func_02049250  0x02049250  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_020470A8  0x020470A8  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D3DC4     0x021D3DC4  data  a4
 *   func_020113D8  0x020113D8  thumb
 *   d_021D3D50     0x021D3D50  data  a4
 *   func_02046C94  0x02046C94  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D3D58     0x021D3D58  data   a4
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   d_021D3D5C     0x021D3D5C  data  a4
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047674  0x02047674  arm
 *   func_020477D4  0x020477D4  arm
 *   func_02047828  0x02047828  arm
 *   func_021693D4  0x021693D4  thumb  ov010
 *   func_02169444  0x02169444  thumb  ov010
 *   func_0216940C  0x0216940C  thumb
 *   func_02169510  0x02169510  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0207AF1C  0x0207AF1C  thumb
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_02047A60  0x02047A60  arm
 *   d_021D3D88     0x021D3D88  data   a2
 *   d_021D3D8A     0x021D3D8A  data   a2
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0218D0D8  0x0218D0D8  thumb  ov021
 *   func_0218DC5C  0x0218DC5C  thumb  ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

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

/* Vector in 20.12 fixed point units. */
typedef struct BuildModelVec {
    int x;
    int y;
    int z;
} BuildModelVec;

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
    BuildModelVec pos;
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
    BuildModelVec pos;
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

/* Animation kind callbacks (d_021D3D58 view: first slot). */
typedef struct BuildModelAnimInit {
    BuildModelAnimInitFn init;
    u32 reserved[2];
} BuildModelAnimInit;

/* Animation kind callbacks (d_021D3D5C view: second and third slot). */
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
    BuildModelVec pos;
    int scaleX;
    int scaleY;
    int scaleZ;
    u32 matrix[9];
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


extern u32 func_02082BCC(void *, int, u32);
extern void *func_02030734(u16, u32, u32, const void *, u32);
extern u32 func_020307B0(void *);
extern u32 func_02013B38(u32 id);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void *func_020490F4(u32, u32);
extern u16 func_0204961C(void *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *);
void *func_02046DB8(u32 a0, u32 a1);
u32 func_020470A8(void *p);
int func_020470D0(u32 *p);
void func_02046EFC(struct Tagged *p);
u32 func_020113D8(u32 row);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern int func_0204779C(int *p);
extern int func_02047790(int *p, int i);
extern void func_0204762C(void *p);
extern int func_02047788(int *p);
extern void func_02047738(void *p);
extern void func_02047504(void *p);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_02047674(int p);
int func_020477D4(struct Owner *owner, u32 index);
u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_021693D4(u8 *base, u8 *src, u32 idx);
extern u32 *func_02169444(u8 *base, u32 idx);
extern void func_0216940C(void *o, u32 i);
extern void func_02169510(int o, BuildModelVec *v);
extern void func_0207C9D0(void *, void *, void *);
extern void func_0207AF1C(void *m, int a, int b);
void func_02047A60(void *a0, struct Arg *a1);
int func_02006148(u32 a0);
int func_02006224(u32 a0);
BuildModelMan *func_0218B754(u16 heapId, void *fieldMap, u16 dateKey);
void func_0218B7F8(BuildModelMan *man);
void func_0218B83C(BuildModelMan *man);
void func_0218B88C(BuildModelMan *man);
void func_0218B8AC(BuildModelMan *man, int areaId, int mapHeader, int extraResource);
int func_0218B910(BuildModelMan *man, u32 modelId);
u8 *func_0218B924(BuildModelMan *man, u32 index);
int func_0218B930(BuildModelMan *man, int modelId, BuildModelVec *pos, int *modelIndex);
int func_0218B974(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *descs, int count);
void func_0218B9FC(BuildModelMan *man, void *object);
void func_0218BA04(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *desc, int index);
void func_0218BA48(BuildModelMan *man, BuildModelNode *node);
void func_0218BA70(BuildModelMan *man, BuildModelNode *node);
void *func_0218BA98(BuildModelMan *man, int handle);
unsigned short func_0218BACC(BuildModelMan *man, BuildModelNode *node);
BuildModelHandleTable *func_0218BB04(BuildModelMan *man);
void func_0218BB0C(BuildModelMan *man, u16 archiveId, u32 member);
int func_0218BB64(BuildModelMan *man);
void func_0218BB78(BuildModelMan *man, int defaultId);
int func_0218BBD0(BuildModelMan *man, unsigned int tableId);
int func_0218BBF4(u32 base, u32 index);
char *func_0218BC00(char *table, int index);
u8 *func_0218BC10(u8 *table, int index);
unsigned short func_0218BC1C(int areaIndex);
void func_0218BC40(BuildModelMan *man, int resourceId, int member, int extraResource);
void func_0218BC6C(BuildModelMan *man);
int func_0218BC8C(int *animDefs);
u8 *func_0218BCAC(u8 *p);
unsigned char func_0218BCB0(unsigned short *p);
void func_0218BCE4(BuildModelSeason *season, u8 dateKey);
void func_0218BCF4(BuildModelSeason *season);
u32 func_0218BD20(BuildModelSeason *season);
u8 func_0218BD24(BuildModelSeason *season);
void func_0218BD28(BuildModelMan *man, int extraResource);
void func_0218BD94(BuildModelMan *man);
void func_0218BDD8(BuildModelMan *man, BuildModelHandleTable *out);
void func_0218BE84(BuildModelMan *man, BuildModelHandleTable *table);
void func_0218BEE8(BuildModelMan *man, BuildModelModel *out, int index, int unused);
void func_0218BF84(BuildModelModel *model);
void func_0218BFB4(BuildModelMan *man, BuildModelAnimSet *out, BuildModelModel *model);
void func_0218C02C(void *man, BuildModelAnimSet *set);
void func_0218C040(void *man, BuildModelAnimSet *set);
void func_0218C08C(BuildModelMan *man, BuildModelAnimSet *set);
void func_0218C0D8(BuildModelAnimSet *set);
void func_0218C124(void *man, BuildModelAnimSet *set);
void func_0218C150(void);
void func_0218C154(BuildModelMan *man, BuildModelAnimSet *set);
void func_0218C1A4(int unused, BuildModelAnimSet *set);
void func_0218C1C4(u32 unused, BuildModelAnimSet *set);
void func_0218C23C(BuildModelAnimSet *set, int group);
void func_0218C290(BuildModelAnimSet *set, int group);
void func_0218C2E4(BuildModelAnimSet *set, int group);
void func_0218C350(BuildModelAnimSet *set, int group);
void func_0218C388(BuildModelAnimSet *set);
void func_0218C3B0(BuildModelAnimSet *set, int slot, int mode);
void func_0218C3E0(BuildModelAnimSet *set, int group, int mode);
void func_0218C438(void);
int func_0218C43C(BuildModelAnimSet *set, int slot);
int func_0218C47C(BuildModelAnimSet *set, int id);
void func_0218C490(void *unused, BuildModelEntry *entry);
BuildModelEntry *func_0218C4A0(BuildModelMan *man, u32 mapObject, BuildModelEntryArgs *args, int index);
void func_0218C4EC(BuildModelMan *man, void *object);
void func_0218C518(BuildModelMan *man, BuildModelEntry *entry);
u8 func_0218C530(BuildModelEntry *entry);
void func_0218C54C(BuildModelEntry *entry, int restore);
void func_0218C574(BuildModelMan *man, BuildModelSearchArgs *args, int tableId);
BuildModelEntry **func_0218C584(BuildModelMan *man, BuildModelRect *rect, int kind, int *count);
BuildModelEntry *func_0218C638(BuildModelMan *man, int kind, BuildModelRect *rect);
BuildModelEntry *func_0218C654(BuildModelMan *man, int kind, int *pos);
int func_0218C674(BuildModelMan *man, BuildModelEntry *entry);
void func_0218C69C(BuildModelMan *man, BuildModelEntry *entry, int slot, int mode);
void func_0218C6D0(BuildModelEntry *entry, void *out);
int func_0218C6F4(BuildModelMan *man, BuildModelEntry *entry, int id);
BuildModelNode *func_0218C724(BuildModelMan *man, BuildModelEntry *entry);
BuildModelNode *func_0218C7D8(BuildModelMan *man, int kind, int *pos);
BuildModelNode *func_0218C7F0(BuildModelMan *man, u32 tableId, BuildModelBlock *src);
void func_0218C860(BuildModelNode *node);
void func_0218C88C(BuildModelNode *node, int slot, int mode);
void func_0218C89C(BuildModelNode *node, int mode);
int func_0218C8B0(BuildModelNode *node, int slot);
int func_0218C8D8(BuildModelNode *node);
int func_0218C8FC(BuildModelNode *node, int slot);
int func_0218C910(BuildModelNode *node);
unsigned short func_0218C924(BuildModelNode *node);
void func_0218C934(BuildModelNode *node);
int func_0218C944(BuildModelNode *node, u32 column, u16 *out);
int func_0218C990(BuildModelNode *node, int out);
int func_0218C9A4(BuildModelNode *node);
void func_0218C9C4(BuildModelRect *out, int *__restrict pos);
int func_0218D0D8(void *a, void *b);
void func_0218DC5C(void *fieldMap, BuildModelVec *offset);
extern const char d_021DD9CC[];
extern const BuildModelKindTable d_021D3DC4;
extern unsigned char d_021D3D50[];
extern BuildModelAnimInit d_021D3D58[];
extern struct BuildModelAnimOps d_021D3D5C[];
extern s16 d_020A1B38[];
extern u8 d_021D3D88[];
extern u8 d_021D3D8A[];

/*
 * Allocates and initialises the 0x13F8-byte manager.
 */
BuildModelMan *func_0218B754(u16 heapId, void *fieldMap, u16 dateKey)
{
    BuildModelMan *man;
    int i;
    unsigned j;
    int z = 0;

    man = (BuildModelMan *)func_02030734(heapId, 0x13F8, 0, d_021DD9CC, 0x193);
    man->heapId = heapId;
    man->fieldMap = fieldMap;
    func_0218BCE4(&man->season, dateKey);
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++)
        man->nodes[i] = (BuildModelNode *)z;
    for (j = 0; j < BUILDMODEL_ENTRY_COUNT; j++)
        func_0218C490(man, &man->entries[j]);
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

void func_0218B7F8(BuildModelMan *man)
{
    int i;

    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] != 0)
            func_0218C860(man->nodes[i]);
    }
    func_0218BE84(man, &man->handleTable);
    func_0218BD94(man);
    func_0218BB64(man);
    func_0218BC6C(man);
    func_020307B0(man);
}

void func_0218B83C(BuildModelMan *man)
{
    int i;
    unsigned u;

    func_0218BCF4(&man->season);
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        BuildModelNode *node = man->nodes[i];
        if (node != 0)
            func_0218C124(man, &node->animSet);
    }
    for (u = 0; u < man->animSetCount; u++)
        func_0218C124(man, &man->animSets[u]);
}

void func_0218B88C(BuildModelMan *man)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] != 0)
            func_0218C934(man->nodes[i]);
    }
}

void func_0218B8AC(BuildModelMan *man, int areaId, int mapHeader, int extraResource)
{
    int member;
    int archiveId;
    int resourceId;
    int tileSetId;

    member = func_0218BC1C(func_02013B38(areaId));
    if (func_020140D8((struct Sub020140BCObj *)mapHeader)) {
        archiveId = 0xE5;
        resourceId = 0xB0;
        tileSetId = 0x15;
    } else {
        archiveId = 0xE6;
        resourceId = 0xB1;
        tileSetId = 0x14;
    }
    func_0218BB0C(man, archiveId, member);
    func_0218BC40(man, (u16)resourceId, member, extraResource);
    func_0218BB78(man, tileSetId);
    func_0218BD28(man, extraResource);
    func_0218BDD8(man, &man->handleTable);
}

int func_0218B910(BuildModelMan *man, u32 tableId)
{
    return func_0218BBF4((u32)man->archive, func_0218BBD0(man, tableId));
}

/*
 * Tail-call thunk: the model definition at the given index.
 */
u8 *func_0218B924(BuildModelMan *man, u32 index)
{
    return (u8 *)func_0218BBF4((u32)man->archive, index);
}

static inline void BuildModelVec_Set(BuildModelVec *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

int func_0218B930(BuildModelMan *man, int tableId, BuildModelVec *pos, int *modelIndex)
{
    BuildModelPlacement *placement = (BuildModelPlacement *)func_0218B910(man, tableId);
    if (placement->modelId == 0xFFFF)
        return 0;
    *modelIndex = func_0218BBD0(man, placement->modelId);
    BuildModelVec_Set(pos, placement->tileX << 12, placement->tileY << 12, placement->tileZ << 12);
    return 1;
}

/*
 * The const on descs is load-bearing: with a plain BuildModelObjectDesc * the
 * compiler keeps &descs[i] in a register and spills descs; const keeps descs
 * and i*16 in registers.
 */
int func_0218B974(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *descs, int count)
{
    BuildModelEntryArgs args;
    int i;
    int next = 0;
    for (i = 0; i < count; i++) {
        func_0218BA04(man, mapObject, descs + i, next);
        if (func_0218B930(man, (unsigned short)(descs[i].idLow + (descs[i].idHigh << 8)), &args.pos, &args.modelIndex) == 1) {
            next++;
            args.rotation = descs[i].rotation;
            args.pos.x += descs[i].x;
            args.pos.y += descs[i].y;
            args.pos.z -= descs[i].z;
            func_0218C4A0(man, mapObject, &args, next);
        }
        next++;
    }
    return next;
}

/*
 * Tail-call thunk: forwards to func_0218C4EC with no argument change.
 */
void func_0218B9FC(BuildModelMan *man, void *object)
{
    func_0218C4EC(man, object);
}

static inline void BuildModelEntryArgsFlat_SetPos(BuildModelEntryArgsFlat *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_0218BA04(BuildModelMan *man, int mapObject, const BuildModelObjectDesc *desc, int index)
{
    BuildModelEntryArgsFlat args;
    args.modelIndex = func_0218BBD0(man, (unsigned short)(desc->idLow + (desc->idHigh << 8)));
    BuildModelEntryArgsFlat_SetPos(&args, desc->x, desc->y, -desc->z);
    args.rotation = desc->rotation;
    func_0218C4A0(man, mapObject, (BuildModelEntryArgs *)(&args), index);
}

void func_0218BA48(BuildModelMan *man, BuildModelNode *node)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] == node) {
            man->nodes[i] = 0;
            return;
        }
    }
}

void func_0218BA70(BuildModelMan *man, BuildModelNode *node)
{
    int i;
    for (i = 0; i < BUILDMODEL_NODE_COUNT; i++) {
        if (man->nodes[i] == 0) {
            man->nodes[i] = node;
            return;
        }
    }
}

void *func_0218BA98(BuildModelMan *man, int handle)
{
    unsigned short idx = handle & ~0xFFF0;
    if ((unsigned short)(handle & 0xFFF0) != 0xFFF0)
        return 0;
    if (idx >= BUILDMODEL_NODE_COUNT)
        return 0;
    return man->nodes[idx];
}

unsigned short func_0218BACC(BuildModelMan *man, BuildModelNode *node)
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

BuildModelHandleTable *func_0218BB04(BuildModelMan *man)
{
    return &man->handleTable;
}

void func_0218BB0C(BuildModelMan *man, u16 archiveId, u32 member)
{
    void *arc;
    u8 *data;

    arc = func_020490F4(archiveId, (u16)((man->heapId & 0x7fff) | 0x8000));
    if (func_0204961C(arc) <= member)
        member = 0;
    data = func_02049250(arc, member, man->heapId);
    man->archive = data;
    man->modelCount = (u32)data[2] >> 1;
    if (man->modelCount > BUILDMODEL_TABLE_ID_MAX)
        man->modelCount = 0x80;
    func_02049238(arc);
}

int func_0218BB64(BuildModelMan *man)
{
    func_020307B0(man->archive);
    man->modelCount = 0;
    return 107 << 2;
}

void func_0218BB78(BuildModelMan *man, int defaultId)
{
    u8 i;
    u8 fill;
    int j;

    func_02082BCC(man->tableToIndex, 0x80, BUILDMODEL_TABLE_ID_MAX);
    for (i = 0; i < man->modelCount; i++)
        man->tableToIndex[*((u16 *)func_0218B924(man, i))] = i;
    fill = man->tableToIndex[defaultId];
    for (j = 0; j < BUILDMODEL_TABLE_ID_MAX; j++) {
        if (man->tableToIndex[j] == 0x80)
            man->tableToIndex[j] = fill;
    }
}

int func_0218BBD0(BuildModelMan *man, unsigned int tableId)
{
    unsigned char index;
    if (tableId >= BUILDMODEL_TABLE_ID_MAX)
        tableId = 0;
    index = man->tableToIndex[tableId];
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return index;
}

int func_0218BBF4(u32 base, u32 index)
{
    return (base + *(u32 *)((u8 *)((base + (index << 2))) + 4));
}

/*
 * Leaf: offset-table walk.  table[2] is a byte count; the offsets start at
 * table+4, each entry a 32-bit relative offset.  Returns
 * table + entry[index + (table[2]>>1)].
 */
char *func_0218BC00(char *table, int index)
{
    unsigned n = (unsigned char)table[2];
    return table + *(int *)(table + 4 + ((n >> 1) + index) * 4);
}

u8 *func_0218BC10(u8 *table, int index)
{
    return (table + *(u32 *)((u8 *)((table + (index << 2))) + 4));
}

/*
 * Maps an area id to an archive member: x >= 0xd2 maps to x-0xd2, x in
 * [2,0xd2) maps to (x-2)/4, x < 2 maps to 0.  The unsigned range tests force
 * `blo` while the division stays signed.  EXACT* (follower 0x0218BC40).
 */
unsigned short func_0218BC1C(int areaIndex)
{
    if ((unsigned)areaIndex >= 0xd2)
        return (unsigned short)(areaIndex - 0xd2);
    if ((unsigned)areaIndex >= 2)
        return (unsigned short)((areaIndex - 2) / 4);
    return 0;
}

/* The trailing guard is the function exit: only its cmp survives. */
void func_0218BC40(BuildModelMan *man, int resourceId, int member, int extraResource)
{
    man->g3dResources = func_02046DB8(resourceId, member);
    if (extraResource != 0)
        func_0218D0D8(man->g3dResources, (void *)extraResource);
    if (func_020470A8(man->g3dResources) == 0)
        return;
}

void func_0218BC6C(BuildModelMan *man)
{
    if (man->g3dResources != 0) {
        func_020470D0(man->g3dResources);
        func_02046EFC(man->g3dResources);
        man->g3dResources = 0;
    }
}

/* Counts the animation resource slots of a model definition that are in use. */
int func_0218BC8C(int *animDefs)
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
u8 *func_0218BCAC(u8 *def)
{
    return def + 0x10;
}

unsigned char func_0218BCB0(unsigned short *def)
{
    BuildModelKindTable t = d_021D3DC4;
    if (def[1] >= 16)
        return 0;
    return t.kind[def[1]];
}

/*
 * Stores the date key and a start season, then updates through func_0218BCF4.
 */
void func_0218BCE4(BuildModelSeason *season, u8 dateKey)
{
    season->season = 5;
    season->dateKey = dateKey;
    func_0218BCF4(season);
}

void func_0218BCF4(BuildModelSeason *season)
{
    season->prevSeason = season->season;
    season->season = func_020113D8(season->dateKey);
    season->changed = season->season != season->prevSeason;
    season->animSlot = d_021D3D50[season->season];
}

/*
 * Returns the season changed flag.
 */
u32 func_0218BD20(BuildModelSeason *season)
{
    return season->changed;
}

/*
 * Returns the animation slot chosen for the season.
 */
u8 func_0218BD24(BuildModelSeason *season)
{
    return season->animSlot;
}

void func_0218BD28(BuildModelMan *man, int extraResource)
{
    unsigned short n = man->modelCount;
    unsigned char i;
    if (n != 0) {
        man->modelInfoCount = n;
        man->modelInfos = func_02030734(man->heapId, n * 0x18, 1, d_021DD9CC, 0x45F);
        for (i = 0; i < man->modelInfoCount; i++)
            func_0218BEE8(man, &man->modelInfos[i], i, extraResource);
    }
}

void func_0218BD94(BuildModelMan *man)
{
    u32 i;
    if (man->modelInfos != 0) {
        for (i = 0; i < man->modelInfoCount; i++)
            func_0218BF84(&man->modelInfos[i]);
        func_020307B0(man->modelInfos);
        man->modelInfoCount = 0;
        man->modelInfos = 0;
    }
}

void func_0218BDD8(BuildModelMan *man, BuildModelHandleTable *out)
{
    u32 n;
    u32 i;
    n = man->modelCount;
    if (n != 0) {
        out->count = n;
        out->handles = func_02030734(man->heapId, n << 3, 1, d_021DD9CC, 0x490);
        man->animSetCount = n;
        man->animSets = func_02030734(man->heapId, n * 0x18, 1, d_021DD9CC, 0x494);
        for (i = 0; i < man->animSetCount; i++) {
            BuildModelAnimSet *sets = man->animSets;
            BuildModelModel *models = man->modelInfos;
            func_0218BFB4(man, &sets[i], &models[i]);
            out->handles[i][0] = (u32)sets[i].anim;
            out->handles[i][1] = 0;
        }
    }
}

void func_0218BE84(BuildModelMan *man, BuildModelHandleTable *table)
{
    u32 i;
    if (table->handles != 0) {
        func_020307B0(table->handles);
        table->handles = 0;
    }
    if (table->extra != 0) {
        func_020307B0(table->extra);
        table->extra = 0;
    }
    if (man->animSets != 0) {
        for (i = 0; i < man->animSetCount; i++)
            func_0218C0D8(&man->animSets[i]);
        func_020307B0(man->animSets);
        man->animSetCount = 0;
        man->animSets = 0;
    }
}

void func_0218BEE8(BuildModelMan *man, BuildModelModel *out, int index, int unused)
{
    u8 *anims;
    int count;
    int i;
    out->def = func_0218B924(man, index);
    out->resource = func_02030734(man->heapId, func_02046C94(), 1, d_021DD9CC, 0x4d0);
    func_02046CE0(out->resource, (u32 *)func_0218BC00((char *)man->archive, index));
    anims = func_0218BCAC(out->def);
    count = func_0218BC8C((int *)anims);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (i < count) {
            out->animResource[i] = func_02030734(man->heapId, func_02046C94(), 1, d_021DD9CC, 0x4db);
            func_02046CE0(out->animResource[i], (u32 *)func_0218BC10(anims, i));
        } else {
            out->animResource[i] = 0;
        }
    }
}

void func_0218BF84(BuildModelModel *model)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (model->animResource[i] != 0) {
            func_020307B0(model->animResource[i]);
            model->animResource[i] = 0;
        }
    }
    if (model->resource != 0) {
        func_020307B0(model->resource);
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
void func_0218BFB4(BuildModelMan *man, BuildModelAnimSet *out, BuildModelModel *model)
{
    u32 buf[BUILDMODEL_ANIM_SLOTS];
    u8 *anims;
    u32 owner;
    int i;
    u8 k;
    anims = func_0218BCAC(model->def);
    owner = (u32)func_02047400(model->resource, 0, man->g3dResources);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (model->animResource[i] != 0)
            buf[i] = (u32)func_02047564((struct G3dOwner *)owner, (const struct G3dOwner *)model->animResource[i], 0);
        else
            buf[i] = 0;
    }
    out->anim = func_0204767C(owner, buf, 4);
    out->model = model;
    k = anims[0];
    k = (u8)k;
    d_021D3D58[k].init(man, out);
}

/*
 * Init callback of the d_021D3D58 dispatch table (pool word 0x0218C02D at +0x0
 * and +0x18), called by func_0218BFB4 as init(man, set): clears all slot states.
 */
void func_0218C02C(void *man, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        set->slotState[i] = 0;
    }
}

/* Init callback: starts every animation the model has and marks it looping. */
void func_0218C040(void *man, BuildModelAnimSet *set)
{
    u8 *anims;
    u32 n;
    int i;
    anims = func_0218BCAC(set->model->def);
    n = anims[2];
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS && i < n; i++) {
        func_020477A4(set->anim, (u16)i);
        func_02047804(set->anim, i);
        set->slotState[i] = 1;
    }
    for (; i < BUILDMODEL_ANIM_SLOTS; i++)
        set->slotState[i] = 0;
}

/* Init callback: starts only the animation chosen for the current season. */
void func_0218C08C(BuildModelMan *man, BuildModelAnimSet *set)
{
    int i;
    u32 slot;
    func_0218BCAC(set->model->def);
    slot = func_0218BD24(&man->season);
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (i != slot) {
            set->slotState[i] = 0;
        } else {
            func_020477A4(set->anim, (u16)i);
            func_02047804(set->anim, i);
            set->slotState[i] = 1;
        }
    }
}

void func_0218C0D8(BuildModelAnimSet *set)
{
    int n;
    int i;
    void *rest;
    if (set->anim != 0) {
        n = func_0204779C(set->anim);
        for (i = 0; i < n; i++) {
            void *o = (void *)func_02047790(set->anim, (u16)i);
            if (o != 0)
                func_0204762C(o);
        }
        rest = (void *)func_02047788(set->anim);
        func_02047738(set->anim);
        set->anim = 0;
        set->model = 0;
        func_02047504(rest);
    }
}

void func_0218C124(void *man, BuildModelAnimSet *set)
{
    unsigned char kind = *func_0218BCAC(set->model->def);
    if (set->anim != 0)
        d_021D3D5C[kind].update(man, set);
}

void func_0218C150(void)
{
}

/*
 * Season update for a four-slot set: restarts the season slot when the season
 * changed, otherwise advances it.
 */
void func_0218C154(BuildModelMan *man, BuildModelAnimSet *set)
{
    int slot = func_0218BD24(&man->season);
    if (func_0218BD20(&man->season) != 0) {
        func_0218C388(set);
        func_020477A4(set->anim, (u16)slot);
        func_02047804(set->anim, slot);
        set->slotState[slot] = 1;
    } else {
        func_02047910(set->anim, (u16)slot, 0x1000);
    }
}

void func_0218C1A4(int unused, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++)
        func_02047910(set->anim, (unsigned short)i, 0x1000);
}

/*
 * Per-slot state machine step over four slots.
 */
void func_0218C1C4(u32 unused, BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        switch (set->slotState[i]) {
        case BUILDMODEL_SLOT_NONE:
        case BUILDMODEL_SLOT_HOLD:
            break;
        case BUILDMODEL_SLOT_OPENING:
            if (func_020478B8(set->anim, (u16)i, 0x1000) == 0)
                set->slotState[i] = BUILDMODEL_SLOT_HOLD;
            break;
        case BUILDMODEL_SLOT_CLOSING:
            if (func_020478B8(set->anim, (u16)i, -0x1000) == 0) {
                func_0204784C(set->anim, (u16)i, 0);
                set->slotState[i] = BUILDMODEL_SLOT_HOLD;
            }
            break;
        case BUILDMODEL_SLOT_LOOP:
            func_02047910(set->anim, (u16)i, 0x1000);
            break;
        }
    }
}

/*
 * Starts a group of slots and marks them opening.
 */
void func_0218C23C(BuildModelAnimSet *set, int group)
{
    u8 *anims = func_0218BCAC(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        func_020477A4(set->anim, (u16)(base + i));
        func_02047804(set->anim, base + i);
        set->slotState[base + i] = BUILDMODEL_SLOT_OPENING;
    }
}

/*
 * Starts a group of slots and marks them looping.
 */
void func_0218C290(BuildModelAnimSet *set, int group)
{
    u8 *anims = func_0218BCAC(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        func_020477A4(set->anim, (u16)(base + i));
        func_02047804(set->anim, base + i);
        set->slotState[base + i] = BUILDMODEL_SLOT_LOOP;
    }
}

/*
 * Starts a group of slots, sets the start frame, marks them closing.
 */
void func_0218C2E4(BuildModelAnimSet *set, int group)
{
    u8 *anims = func_0218BCAC(set->model->def);
    int base = anims[2] * group;
    int i;
    int frame;
    for (i = 0; i < anims[2]; i++) {
        func_020477A4(set->anim, (u16)(base + i));
        frame = *(u16 *)(*(u8 **)(func_02047674((int)func_02047790(set->anim, (u16)(base + i))) + 8) + 4) << 12;
        func_0204784C(set->anim, base + i, &frame);
        set->slotState[base + i] = BUILDMODEL_SLOT_CLOSING;
    }
}

/* Stops a group of slots that are running. */
void func_0218C350(BuildModelAnimSet *set, int group)
{
    u8 *anims = func_0218BCAC(set->model->def);
    int base = anims[2] * group;
    int i;
    for (i = 0; i < anims[2]; i++) {
        if (set->slotState[base + i] != 0)
            set->slotState[base + i] = BUILDMODEL_SLOT_HOLD;
    }
}

void func_0218C388(BuildModelAnimSet *set)
{
    int i;
    for (i = 0; i < BUILDMODEL_ANIM_SLOTS; i++) {
        if (set->slotState[i] != 0) {
            func_020477D4(set->anim, (unsigned short)i);
            set->slotState[i] = 0;
        }
    }
}

void func_0218C3B0(BuildModelAnimSet *set, int slot, int mode)
{
    unsigned char kind = *func_0218BCAC(set->model->def);
    unsigned char idx = slot;
    if (idx >= BUILDMODEL_ANIM_SLOTS)
        idx = 0;
    d_021D3D5C[kind].play(set, idx, mode);
}

/*
 * Dispatches a slot-group operation by mode 0..4.
 */
void func_0218C3E0(BuildModelAnimSet *set, int group, int mode)
{
    switch (mode) {
    case 0:
        func_0218C388(set);
        func_0218C23C(set, group);
        break;
    case 1:
        func_0218C388(set);
        func_0218C2E4(set, group);
        break;
    case 2:
        func_0218C388(set);
        func_0218C290(set, group);
        break;
    case 3:
        func_0218C350(set, group);
        break;
    case 4:
        func_0218C388(set);
        break;
    }
}

void func_0218C438(void)
{
}

/*
 * Reports whether slot i (0 if out of range) is idle (state none or hold).
 */
int func_0218C43C(BuildModelAnimSet *set, int slot)
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

int func_0218C47C(BuildModelAnimSet *set, int id)
{
    int frame;
    func_02047828(set->anim, (unsigned short)id, &frame);
    return frame;
}

void func_0218C490(void *unused, BuildModelEntry *entry)
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
BuildModelEntry *func_0218C4A0(BuildModelMan *man, u32 mapObject, BuildModelEntryArgs *args, int index)
{
    BuildModelEntry *entry = &man->entries[0];
    u32 i;
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        entry = &man->entries[i];
        if (entry->object == 0) {
            func_021693D4((u8 *)mapObject, (u8 *)args, index);
            entry->object = (void *)mapObject;
            entry->savedWord = -1;
            entry->index = index;
            entry->visible = 1;
            entry->instance = (BuildModelInstance *)func_02169444((u8 *)mapObject, index);
            return entry;
        }
    }
    return 0;
}

void func_0218C4EC(BuildModelMan *man, void *object)
{
    BuildModelEntry *entries = man->entries;
    int i;
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        if (entries[i].object == object)
            func_0218C518(man, &entries[i]);
    }
}

/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216940C (0x0216940C) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 */
void func_0218C518(BuildModelMan *man, BuildModelEntry *entry)
{
    func_0216940C(entry->object, entry->index);
    func_0218C490(man, entry);
}

/* Returns the low byte of the instance's model id (the saved one while visible). */
u8 func_0218C530(BuildModelEntry *entry)
{
    if (entry->instance->modelId == (~0)) {
        return (((u32)entry->savedWord << 24) >> 24);
    }
    return ((entry->instance->modelId << 24) >> 24);
}

/* Swaps the instance model id with the saved word: attach hides it, restore puts it back. */
void func_0218C54C(BuildModelEntry *entry, int restore)
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

void func_0218C574(BuildModelMan *man, BuildModelSearchArgs *args, int tableId)
{
    *args->outIndex = func_0218BBD0(man, tableId);
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
BuildModelEntry **func_0218C584(BuildModelMan *man, BuildModelRect *rect, int kind, int *count)
{
    BuildModelEntry **list;
    BuildModelEntry *entry;
    BuildModelVec pos;
    int n = 0;
    u32 i;
    list = func_02030734(man->heapId, 0x80, 1, d_021DD9CC, 0x749);
    for (i = 0; i < BUILDMODEL_ENTRY_COUNT; i++) {
        entry = &man->entries[i];
        if (entry->object == 0)
            continue;
        if (kind != 0 && kind != func_0218C674(man, entry))
            continue;
        func_02169510((int)entry->object, &pos);
        func_0207C9D0(&entry->instance->pos, &pos, &pos);
        if (BuildModelRect_Contains(rect, pos.x, pos.z) == 1) {
            list[n] = entry;
            n++;
        }
    }
    *count = n;
    return list;
}

BuildModelEntry *func_0218C638(BuildModelMan *man, int kind, BuildModelRect *rect)
{
    int count;
    BuildModelEntry **list = func_0218C584(man, rect, kind, &count);
    BuildModelEntry *first = *list;
    func_020307B0(list);
    return first;
}

BuildModelEntry *func_0218C654(BuildModelMan *man, int kind, int *pos)
{
    BuildModelRect rect;
    func_0218C9C4(&rect, (int *__restrict)pos);
    return func_0218C638(man, kind, &rect);
}

int func_0218C674(BuildModelMan *man, BuildModelEntry *entry)
{
    unsigned char index = func_0218C530(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return func_0218BCB0((short unsigned int *)func_0218B924(man, index));
}

void func_0218C69C(BuildModelMan *man, BuildModelEntry *entry, int slot, int mode)
{
    unsigned char index = func_0218C530(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    func_0218C3B0(&man->animSets[index], slot, mode);
}

void func_0218C6D0(BuildModelEntry *entry, void *out)
{
    BuildModelVec pos;
    func_02169510((int)entry->object, &pos);
    func_0207C9D0(&entry->instance->pos, &pos, out);
}

int func_0218C6F4(BuildModelMan *man, BuildModelEntry *entry, int id)
{
    unsigned char index = func_0218C530(entry);
    if (index >= 0x80 || index >= man->modelCount)
        index = 0;
    return func_0218C47C(&man->animSets[index], id);
}

/*
 * Allocates a 0x60-byte node for an entry, builds its matrices, registers it.
 */
BuildModelNode *func_0218C724(BuildModelMan *man, BuildModelEntry *entry)
{
    BuildModelInstance *instance = entry->instance;
    BuildModelNode *node;
    BuildModelVec fieldOffset;
    int facing;
    node = func_02030734(man->heapId, 0x60, 0, d_021DD9CC, 0x7E9);
    node->man = man;
    node->entry = entry;
    node->slot = 0xFFFF;
    facing = instance->facing >> 4;
    func_0207AF1C(node->matrix, d_020A1B38[facing * 2], d_020A1B38[facing * 2 + 1]);
    func_02169510((int)entry->object, &node->pos);
    func_0207C9D0(&node->pos, &instance->pos, &node->pos);
    func_0218DC5C(man->fieldMap, &fieldOffset);
    func_0207C9D0(&node->pos, &fieldOffset, &node->pos);
    node->scaleX = 0x1000;
    node->scaleY = 0x1000;
    node->scaleZ = 0x1000;
    func_0218BFB4(man, &node->animSet, &man->modelInfos[instance->modelId]);
    func_0218BA70(man, node);
    func_0218C54C(node->entry, 0);
    return node;
}

BuildModelNode *func_0218C7D8(BuildModelMan *man, int kind, int *pos)
{
    BuildModelEntry *entry = func_0218C654(man, kind, pos);
    if (entry == 0)
        return 0;
    return func_0218C724(man, entry);
}

/*
 * Allocates a 0x60-byte node, copies a 60-byte block into it, registers it.
 */
BuildModelNode *func_0218C7F0(BuildModelMan *man, u32 tableId, BuildModelBlock *src)
{
    BuildModelNode *node = func_02030734(man->heapId, 0x60, 0, d_021DD9CC, 0x825);
    node->man = man;
    node->entry = 0;
    node->slot = 0xFFFF;
    *(BuildModelBlock *)&node->pos = *src;
    func_0218BFB4(man, &node->animSet, &man->modelInfos[func_0218BBD0(man, tableId)]);
    func_0218BA70(man, node);
    return node;
}

void func_0218C860(BuildModelNode *node)
{
    if (node != 0) {
        func_0218BA48(node->man, node);
        func_0218C0D8(&node->animSet);
        if (node->entry != 0)
            func_0218C54C(node->entry, 1);
        func_020307B0(node);
    }
}

void func_0218C88C(BuildModelNode *node, int slot, int mode)
{
    if (node != 0) {
        node->slot = slot;
        func_0218C3B0(&node->animSet, slot, mode);
    }
}

void func_0218C89C(BuildModelNode *node, int mode)
{
    if (node != 0)
        func_0218C3B0(&node->animSet, node->slot, mode);
}

int func_0218C8B0(BuildModelNode *node, int slot)
{
    if (node == 0)
        return 1;
    if (func_0218C8FC(node, slot) == 1) {
        func_0218C88C(node, slot, 3);
        return 1;
    }
    return 0;
}

int func_0218C8D8(BuildModelNode *node)
{
    if (node == 0)
        return 1;
    if (func_0218C910(node) == 1) {
        func_0218C89C(node, 3);
        return 1;
    }
    return 0;
}

int func_0218C8FC(BuildModelNode *node, int slot)
{
    if (node == 0)
        return 0;
    return func_0218C43C(&node->animSet, slot);
}

int func_0218C910(BuildModelNode *node)
{
    if (node == 0)
        return 0;
    return func_0218C43C(&node->animSet, node->slot);
}

/* Returns the kind field of the node's model definition. */
unsigned short func_0218C924(BuildModelNode *node)
{
    if (node == 0)
        return 0;
    return ((unsigned short *)node->animSet.model->def)[1];
}

void func_0218C934(BuildModelNode *node)
{
    if (node != 0)
        func_02047A60(node->animSet.anim, (struct Arg *)&node->pos);
}

/*
 * Looks up a 10-byte-stride table row by model kind and reads column idx.
 */
int func_0218C944(BuildModelNode *node, u32 column, u16 *out)
{
    u32 key;
    u32 j;
    if (node == 0)
        return 0;
    key = func_0218C924(node);
    *out = 0;
    if (column >= 4)
        return 0;
    for (j = 0; j < 6; j++) {
        if (key == *(u16 *)(d_021D3D88 + j * 10)) {
            *out = *(u16 *)(d_021D3D8A + j * 10 + column * 2);
            return 1;
        }
    }
    return 0;
}

int func_0218C990(BuildModelNode *node, int out)
{
    if (node == 0)
        return 0;
    return func_0218C944(node, node->slot, (u16 *)out);
}

int func_0218C9A4(BuildModelNode *node)
{
    unsigned short v;
    if (func_0218C990(node, (int)(&v)) == 0)
        return 0;
    return func_02006224(func_02006148(v));
}

/*
 * `__restrict` on pos lets mwcc keep pos[2] in a register across the
 * out->zMin/out->zMax stores and sink the out->zMin store past the pos[0] load
 * (see docs/idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md).
 */
void func_0218C9C4(BuildModelRect *out, int *__restrict pos)
{
    out->zMin = pos[2] - 0x30000;
    out->zMax = pos[2] + 0x30000;
    out->xMin = pos[0] - 0x20000;
    out->xMax = pos[0] + 0x20000;
}
