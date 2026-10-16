/*
 * file:     fldeff_footmark.c
 * unit:     yes
 * function: FLDEFF_FOOTMARK_Init, FLDEFF_FOOTMARK_Delete, FLDEFF_FOOTMARK_InitResource, FLDEFF_FOOTMARK_DeleteResource, FLDEFF_FOOTMARK_GetSlotIndex, FLDEFF_FOOTMARK_SetMMdl, FLDEFF_FOOTMARK_InitTask, FLDEFF_FOOTMARK_DeleteTask, FLDEFF_FOOTMARK_UpdateTask, FLDEFF_FOOTMARK_DrawTask
 * address:  0x021BBCBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from fieldmap_func.c, fldeff_footmark.c by tools/splitfile.py.
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos    0x021AC1B8  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   gFootmarkResId     0x021D9B0C  data  a2
 *   gFootmarkSlotTable     0x021D9AE8  data  a4
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm  arm9
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetDirDispOld  0x0216D5FC  thumb  ov010
 *   FLDEFF_FOOTMARK_GetSlotIndex  0x021BBD84  thumb  ov021
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   gFootmarkTaskHeader     0x021D9AF8  data  a4
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_GetEntryElemId  0x020508C4  arm
 *   BILLBOARD_SetElemAlpha  0x0204F6B4  arm
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

/* ---- fldeff_footmark.c ---- */

/* Same layout as FootmarkEffectWork in fldeff_footmark.c. */
typedef struct FootmarkEffectWork {
    void *fieldEffectCtrl;     /* 0x00 */
    void *bbActSys;            /* 0x04 */
    u16 resIdx[26];            /* 0x08 billboard slot per footmark picture */
    int snowHeightOffset;      /* 0x3C */
} FootmarkEffectWork;

/* Billboard slot record handed to the slot allocator (0x0C bytes). */
typedef struct FootmarkSlotRecord {
    void *resource;            /* 0x00 */
    u8 kind;                   /* 0x04 */
    u8 flags;                  /* 0x05 */
    u8 width;                  /* 0x06 */
    u8 height;                 /* 0x07 */
    u32 count;                 /* 0x08 */
} FootmarkSlotRecord;

typedef struct FootmarkDirRow { u8 slot[4]; } FootmarkDirRow;

void *FIELD_EFFECT_GetFieldMap(void *fieldEffectCtrl);

void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *file, unsigned short line);

extern u32 func_020307B0(void *p);

extern void *FIELDMAP_GetEffectBbdAct(void *fieldMap);

extern void *FIELD_EFFECT_GetArcHandle(void *fieldEffectCtrl);

extern void *G3D_SYSTEM_CreateResourceArcHandle(void *g3dHeap, u32 resId);

extern void FIELD_EFFECT_ApplyPaletteTable(void *fieldEffectCtrl, void *resource);

extern u16 BILLBOARD_ACT_CreateSlots(void *bbActSys, const FootmarkSlotRecord *recs, u32 n);

extern void BILLBOARD_ACT_DeleteSlots(void *bbActSys, u32 first, u32 count);

FootmarkEffectWork *FLDEFF_FOOTMARK_Init(void *fieldEffectCtrl, u32 heapId);

void FLDEFF_FOOTMARK_Delete(u32 unused, FootmarkEffectWork *effWork);

void FLDEFF_FOOTMARK_InitResource(FootmarkEffectWork *effWork);

void FLDEFF_FOOTMARK_DeleteResource(FootmarkEffectWork *effWork);

int FLDEFF_FOOTMARK_GetSlotIndex(FootmarkEffectWork *effWork, int type, int dir, int oldDir);

extern const char d_021DE30C[];

extern u16 gFootmarkResId[];

extern FootmarkDirRow gFootmarkSlotTable[];

FootmarkEffectWork *FLDEFF_FOOTMARK_Init(void *fieldEffectCtrl, u32 heapId)
{
    FootmarkEffectWork *effWork;

    effWork = func_02030734(heapId, 0x40, 1, d_021DE30C, 0x9d);
    effWork->fieldEffectCtrl = fieldEffectCtrl;
    effWork->bbActSys = FIELDMAP_GetEffectBbdAct(FIELD_EFFECT_GetFieldMap(fieldEffectCtrl));
    FLDEFF_FOOTMARK_InitResource(effWork);
    effWork->snowHeightOffset = 0x2000;
    return effWork;
}

void FLDEFF_FOOTMARK_Delete(u32 unused, FootmarkEffectWork *effWork)
{
    FLDEFF_FOOTMARK_DeleteResource(effWork);
    func_020307B0(effWork);
}

void FLDEFF_FOOTMARK_InitResource(FootmarkEffectWork *effWork)
{
    FootmarkSlotRecord record;
    int i;
    const u16 *resId = gFootmarkResId;
    void *g3dHeap = FIELD_EFFECT_GetArcHandle(effWork->fieldEffectCtrl);

    record.kind = 2;
    record.flags = 0x11;
    record.width = 0x10;
    record.height = 0x10;
    record.count = 1;
    for (i = 0; i < 0x1a; i++, resId++) {
        record.resource = G3D_SYSTEM_CreateResourceArcHandle(g3dHeap, *resId);
        FIELD_EFFECT_ApplyPaletteTable(effWork->fieldEffectCtrl, record.resource);
        effWork->resIdx[i] = BILLBOARD_ACT_CreateSlots(effWork->bbActSys, &record, 1);
    }
}

void FLDEFF_FOOTMARK_DeleteResource(FootmarkEffectWork *effWork)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        BILLBOARD_ACT_DeleteSlots(effWork->bbActSys, effWork->resIdx[i], 1);
    }
}

/* Picks the billboard slot of a footmark picture (oldDir selects the turn row). */
int FLDEFF_FOOTMARK_GetSlotIndex(FootmarkEffectWork *effWork, int type, int dir, int oldDir)
{
    int slot = 0;
    switch (type) {
    case 0: slot = dir; break;
    case 1: slot = gFootmarkSlotTable[oldDir].slot[dir]; break;
    case 2: slot = dir + 10; break;
    case 3: slot = gFootmarkSlotTable[oldDir].slot[dir] - 4; slot += 14; break;
    case 4: slot = gFootmarkSlotTable[oldDir].slot[dir] - 4; slot += 20; break;
    }
    return slot;
}

struct Actor;

struct BbActDesc;

struct BbActSys;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Add-task header copied into every footmark task. */
typedef struct FootmarkTaskHead {
    FootmarkEffectWork *effWork;
    u16 resNo;
    u16 padResNo;
} FootmarkTaskHead;

typedef struct FootmarkTaskWork {
    FootmarkTaskHead head;
    u16 actId;
    u16 seq;
    u16 padSeq;
    s16 alpha;
    int frame;
} FootmarkTaskWork;

/* Billboard actor add parameters. */
typedef struct FootmarkBbActAdd {
    u16 resIdx, scaleX, scaleY;
    s8 alpha;
    int drawEnable, lightEnable;
} FootmarkBbActAdd;

/* Field effect task draw-object setup. */
typedef struct FootmarkTaskObj {
    int reserved[3];
    int g3dObj;
    FootmarkTaskWork *work;
} FootmarkTaskObj;

int FIELD_EFFECT_GetResource(u32 fieldEffectCtrl, u32 procId);

u16 FLDMMDL_GetDirDisp(void *mmdl);

u16 FLDMMDL_GetDirDispOld(void *mmdl);

void FLDMMDL_GetPos(const struct Actor *mmdl, struct VecFx32 *out);

int FLDMMDL_GetGridOldX(void *mmdl);

int FLDMMDL_GetGridOldZ(void *mmdl);

void FLDMMDL_MOVE_GridToVectorPos(int gridX, int gridZ, int *pos);

void FIELD_EFFECT_AddObject(int fieldEffectCtrl, void *taskHeader, VecFx32 *pos, int param, FootmarkTaskHead *head, int pri);

extern int FIELD_EFFECT_GetObjectParam(u32 task);

extern void FIELD_EFFECT_GetObjectPos(int task, FootmarkTaskObj *obj);

extern void FIELD_EFFECT_DeleteObject(int task);

extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 base, const struct BbActDesc *desc, u32 count, u32 mode);

extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count);

extern u32 BILLBOARD_ACT_GetBoard(u32 *sys);

extern u32 BILLBOARD_ACT_GetEntryElemId(u32 sys, u16 actId);

extern void BILLBOARD_SetElemAlpha(u8 *board, int elem, u8 *alpha);

void FLDEFF_FOOTMARK_SetMMdl(int mmdl, int fieldEffectCtrl, int type);

void FLDEFF_FOOTMARK_InitTask(int task, FootmarkTaskWork *work);

void FLDEFF_FOOTMARK_DeleteTask(int task, FootmarkTaskWork *work);

void FLDEFF_FOOTMARK_UpdateTask(int task, FootmarkTaskWork *work);

void FLDEFF_FOOTMARK_DrawTask(void);

extern int gFootmarkTaskHeader;

void FLDEFF_FOOTMARK_SetMMdl(int mmdl, int fieldEffectCtrl, int type)
{
    int effWork;
    int dir;
    int oldDir;
    int resNo;
    VecFx32 pos;
    FootmarkTaskHead head;

    effWork = FIELD_EFFECT_GetResource(fieldEffectCtrl, 5);
    head.effWork = (FootmarkEffectWork *)effWork;
    dir = FLDMMDL_GetDirDisp((void *)mmdl);
    oldDir = FLDMMDL_GetDirDispOld((void *)mmdl);
    resNo = (u16)FLDEFF_FOOTMARK_GetSlotIndex((FootmarkEffectWork *)effWork, type, dir, oldDir);
    FLDMMDL_GetPos((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    dir = FLDMMDL_GetGridOldX((void *)mmdl);
    FLDMMDL_MOVE_GridToVectorPos(dir, FLDMMDL_GetGridOldZ((void *)mmdl), (int *)(&pos));
    if (type == 0 && (u16)(resNo + 0xFFFE) <= 1) {
        pos.z -= 0x2000;
    } else if (type == 4 && (u16)(resNo + 0xFFFE) <= 1) {
        pos.z -= 0x2000;
    }
    if (type == 4) {
        pos.y -= ((FootmarkEffectWork *)effWork)->snowHeightOffset;
    }
    head.resNo = resNo;
    FIELD_EFFECT_AddObject(fieldEffectCtrl, &gFootmarkTaskHeader, &pos, 0, &head, 0);
}

void FLDEFF_FOOTMARK_InitTask(int task, FootmarkTaskWork *work)
{
    FootmarkTaskObj obj;
    FootmarkBbActAdd add;
    FootmarkTaskHead *head = (FootmarkTaskHead *)FIELD_EFFECT_GetObjectParam(task);

    work->head = *head;
    work->alpha = 0x1f;
    add.resIdx = work->head.effWork->resIdx[work->head.resNo];
    add.scaleX = 0x1000;
    add.scaleY = 0x1000;
    add.alpha = work->alpha;
    add.drawEnable = 1;
    add.lightEnable = 1;
    obj.g3dObj = 0;
    obj.work = work;
    FIELD_EFFECT_GetObjectPos(task, &obj);
    work->actId = BILLBOARD_ACT_CreateEntries((void *)work->head.effWork->bbActSys, 0, (const struct BbActDesc *)(&add), 1, 3);
    if (work->actId == 0xFFFF) {
        FIELD_EFFECT_DeleteObject(task);
    }
}

void FLDEFF_FOOTMARK_DeleteTask(int task, FootmarkTaskWork *work)
{
    int bbActSys = (int)work->head.effWork->bbActSys;
    u16 actId = work->actId;

    if (actId != 0xFFFF) {
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)bbActSys, actId, 1);
    }
}

/*
 * Witnesses: arm9 leaves BILLBOARD_ACT_GetBoard, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled,
 * BILLBOARD_ACT_GetEntryElemId, BILLBOARD_GetElemCell filed in src/matched/arm9 (wave A1).
 */
void FLDEFF_FOOTMARK_UpdateTask(int task, FootmarkTaskWork *work)
{
    u8 alpha;
    int bbActSys, board;
    u16 elem;

    switch (work->seq) {
    case 0:
        work->frame = work->frame + 1;
        if (work->frame >= 0x10) {
            work->seq = work->seq + 1;
        }
        break;
    case 1:
        work->alpha = work->alpha - 2;
        if (work->alpha < 0) {
            FIELD_EFFECT_DeleteObject(task);
            return;
        }
        alpha = work->alpha;
        bbActSys = (int)work->head.effWork->bbActSys;
        board = BILLBOARD_ACT_GetBoard((u32 *)bbActSys);
        elem = (int)BILLBOARD_ACT_GetEntryElemId((u32)bbActSys, (u16)work->actId);
        BILLBOARD_SetElemAlpha((u8 *)board, elem, &alpha);
        break;
    }
}

void FLDEFF_FOOTMARK_DrawTask(void) {}
