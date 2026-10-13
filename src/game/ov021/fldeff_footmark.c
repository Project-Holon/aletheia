/*
 * file:     fldeff_footmark.c
 * unit:     yes
 * function: FLDEFF_FOOTMARK_SetMMdl, FLDEFF_FOOTMARK_InitTask, FLDEFF_FOOTMARK_DeleteTask, FLDEFF_FOOTMARK_UpdateTask, FLDEFF_FOOTMARK_DrawTask
 * address:  0x021BBDD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BBF78 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetDirDispOld  0x0216D5FC  thumb  ov010
 *   FLDEFF_FOOTMARK_GetSlotIndex  0x021BBD84  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gFootmarkTaskHeader     0x021D9AF8  data  a4
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_GetEntryElemId  0x020508C4  arm
 *   BILLBOARD_SetElemAlpha  0x0204F6B4  arm
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm  arm9
 */
struct Actor;
struct BbActDesc;
struct BbActSys;

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Footmark effect work (FLDEFF_CTRL effect slot 5). */
typedef struct FootmarkEffectWork {
    int fieldEffectCtrl;
    int bbActSys;
    u16 resIdx[26];
    int snowHeightOffset;
} FootmarkEffectWork;

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
int FLDEFF_FOOTMARK_GetSlotIndex(int effWork, int type, int dir, int oldDir);
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
    resNo = (u16)FLDEFF_FOOTMARK_GetSlotIndex(effWork, type, dir, oldDir);
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
    int bbActSys = work->head.effWork->bbActSys;
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
        bbActSys = work->head.effWork->bbActSys;
        board = BILLBOARD_ACT_GetBoard((u32 *)bbActSys);
        elem = (int)BILLBOARD_ACT_GetEntryElemId((u32)bbActSys, (u16)work->actId);
        BILLBOARD_SetElemAlpha((u8 *)board, elem, &alpha);
        break;
    }
}

void FLDEFF_FOOTMARK_DrawTask(void) {}
