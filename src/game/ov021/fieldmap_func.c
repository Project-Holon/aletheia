/*
 * file:     fieldmap_func.c
 * unit:     yes
 * function: FLDEFF_GYOE_StartHeld, FLDEFF_GYOE_IsFinished, FLDEFF_GYOE_InitHeldTask, FLDEFF_GYOE_DeleteTask, FLDEFF_GYOE_UpdateHeldTask, FLDEFF_GYOE_UpdateTask, FLDEFF_GYOE_DrawTask, FLDEFF_GYOE_PlaySe, FLDEFF_GYOE_RotateByCamera, FLDEFF_GYOE_StepAnimation, FIELD_SUBPROC_MGR_Create, FIELD_SUBPROC_MGR_Delete, FIELD_SUBPROC_MGR_RunUpdate, FIELD_SUBPROC_MGR_RunDraw, FIELD_SUBPROC_UpdateTcb, FIELD_SUBPROC_DrawTcb, FIELD_SUBPROC_Start, FIELD_SUBPROC_End, FIELD_SUBPROC_GetWork, UNION_CHAT_LOG_Add, UNION_CHAT_LOG_TakeSlot, UNION_CHAT_LOG_GetLine, UNION_CHAT_LOG_IsNew
 * address:  0x021BB578
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
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gGyoeHeldTaskHeader     0x021D9A90  data  a4
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb  ov021
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   gGyoeDrawTransformInit       0x021D9AA4  data  a4
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   NNS_G3dGlbFlush    0x0206A854  arm
 *   NNS_G3dGeFlushBuffer    0x0206DB80  arm
 *   MTX_Identity33_    0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos    0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling    0x02047AC8  arm
 *   g_DefaultProjectionMtx       0x02148B54  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   MTX_LookAt  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   MTX_MultVec33  0x0207B51C  arm
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   VEC_Add  0x0207C9D0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 *   func_020307B0  0x020307B0  arm
 *   TCB_Main  0x02030D28  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02034714  0x02034714  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008550  0x02008550  thumb
 *   WORDSET_CopyString  0x0201F41C  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   UNION_CHARA_IsWifiFriendBeacon  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   gUnionChatEmptyMac     0x021D9AE0  data  a4
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 */
#include "../ov010/fldmmdl_types.h"

typedef int fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

#include "../ov012/union_comm_types.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

/*
 * This file holds the end of fldeff_gyoe.c (021BB578..021BB808), the field
 * sub-program manager (021BB890..021BBA6C), the union chat log
 * (021BBA70..021BBC58) and the start of fldeff_footmark.c (021BBCBC..).
 */
typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct { fx32 m[3][3]; } MtxFx33;

struct FieldSubproc;

/* ---- fldeff_gyoe.c (exclamation mark effect) ---- */

/* Position, scale and rotation of a drawn G3D object (0x48 bytes). */
typedef struct G3dObjectTransform {
    VecFx32 pos;
    VecFx32 scale;
    MtxFx33 rotation;
} G3dObjectTransform;

/* Same layout as FldeffGyoe in fldeff_gyoe.c. */
typedef struct FldeffGyoe {
    void *fieldEffectCtrl;   /* 0x00 */
    void *resource[4];       /* 0x04 */
    void *renderObj[4];      /* 0x14 */
    void *object[4];         /* 0x24 */
    u16 resourceCount;       /* 0x34 */
} FldeffGyoe;

/* Same layout as FldeffGyoeTaskParam in fldeff_gyoe.c. */
typedef struct FldeffGyoeTaskParam {
    u32 type;                  /* 0x00 which mark */
    u32 sePlay;                /* 0x04 */
    FldeffGyoe *gyoe;          /* 0x08 */
    Mmdl *mmdl;                /* 0x0C */
    MmdlCheckInfo mmdlInfo;    /* 0x10 */
    void *fieldMap;            /* 0x18 */
} FldeffGyoeTaskParam;

/* Work of one mark task (0x30 bytes). */
typedef struct FldeffGyoeTaskWork {
    FldeffGyoeTaskParam param; /* 0x00 */
    int state;                 /* 0x1C 0 hop, 1 wait, 2 shown */
    int timer;                 /* 0x20 frames spent waiting */
    int finished;              /* 0x24 set to 1 when the mark is done */
    fx32 yOffset;              /* 0x28 height above the model's head */
    fx32 yVelocity;            /* 0x2C */
} FldeffGyoeTaskWork;

/* State registers of the geometry engine (only the dirty bits are used). */
typedef struct GxState {
    u8 pad0[0x7C];
    u32 matrixDirtyFlags;      /* 0x7C */
} GxState;

/* ---- field sub-program manager ---- */
struct TcbList;

struct Tcb;

typedef void (*TcbFunc)(struct Tcb *tcb, void *work);

typedef void (*FieldSubprocFunc)(struct FieldSubproc *proc, void *fieldSys, void *work);

/* What a sub-program is made of (0x18 bytes). */
typedef struct FieldSubprocTemplate {
    int priority;              /* 0x00 of both task lists */
    u16 workSize;              /* 0x04 zero: no work block */
    u16 pad06;
    FieldSubprocFunc init;     /* 0x08 */
    FieldSubprocFunc exit;     /* 0x0C */
    FieldSubprocFunc update;   /* 0x10 */
    FieldSubprocFunc draw;     /* 0x14 */
} FieldSubprocTemplate;

typedef struct FieldSubprocMgr {
    void *fieldSys;                       /* 0x00 */
    int heapId;                           /* 0x04 */
    int capacity;                         /* 0x08 */
    struct FieldSubproc *procs;           /* 0x0C */
    struct TcbList *updateList;           /* 0x10 */
    struct TcbList *drawList;             /* 0x14 */
} FieldSubprocMgr;

/* One running sub-program (0x18 bytes); updateTcb zero means the slot is free. */
typedef struct FieldSubproc {
    FieldSubprocMgr *mgr;                 /* 0x00 */
    struct Tcb *updateTcb;                /* 0x04 */
    struct Tcb *drawTcb;                  /* 0x08 */
    const FieldSubprocTemplate *tmpl;     /* 0x0C */
    void *work;                           /* 0x10 */
    int overlayId;                        /* 0x14 -1 none */
} FieldSubproc;

/* ---- union chat log (union_comm_types.h UnionChatLog, ring part) ---- */

/* One line of the chat log (0x24 bytes), see UnionChatEntry. */
typedef struct UnionChatLine {
    u16 name[8];               /* 0x00 sender name */
    u16 chatPms[4];            /* 0x10 easy chat sentence */
    u16 chatCount;             /* 0x18 */
    u8 senderMac[6];           /* 0x1A */
    u8 sex;                    /* 0x20 */
    u8 chatType;               /* 0x21 */
    u8 relation;               /* 0x22 0 stranger, 1 wifi friend, 2 known trainer */
    u8 pad23;
} UnionChatLine;

/* UnionChatLog with the two slot counters kept in pad438. */
typedef struct UnionChatRing {
    UnionChatLine line[UNION_CHAT_LOG_MAX]; /* 0x000 */
    u8 startSlot;              /* 0x438 slot of the oldest line */
    u8 endSlot;                /* 0x439 slot the next line goes to */
    u8 pad43A[2];
    int newestIndex;           /* 0x43C absolute index of the newest line, -1 empty */
    int oldestIndex;           /* 0x440 absolute index of the oldest kept line */
} UnionChatRing;

/* ---- externs ---- */
int FIELD_EFFECT_GetResource(void *fieldEffectCtrl, u32 effectId);

void FLDMMDL_GetCheckInfo(Mmdl *mmdl, MmdlCheckInfo *info);

void *FIELD_EFFECT_GetFieldMap(void *fieldEffectCtrl);

void *FIELD_EFFECT_AddObject(void *fieldEffectCtrl, const void *taskHeader, int a2, int a3, FldeffGyoeTaskParam *param, int a5);

extern void *FIELD_EFFECT_GetObjectWork(void *task);

extern FldeffGyoeTaskParam *FIELD_EFFECT_GetObjectParam(void *task);

extern void FIELD_EFFECT_UpdateObject(void *task);

extern int FLDMMDL_CheckCheckInfo(Mmdl *mmdl, MmdlCheckInfo *info);

extern void FLDMMDL_GetPos(Mmdl *mmdl, VecFx32 *out);

extern void FIELD_EFFECT_SetObjectPos(void *task, VecFx32 *pos);

void FIELD_EFFECT_DeleteObject(void *task);

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);

extern void NNS_G3dGlbFlush(void);

extern void NNS_G3dGeFlushBuffer(void);

extern void MTX_Identity33_(MtxFx33 *mtx);

extern void FIELD_EFFECT_GetObjectPos(void *task, G3dObjectTransform *transform);

extern int G3D_SYSTEM_DrawObjectCulling(void *object, G3dObjectTransform *transform);

void GFL_USE_PlaySeDefaultVolume(u32 seId);

void func_02048AE8(void *g3dCamera, VecFx32 *out);

void func_02048B0C(void *g3dCamera, VecFx32 *out);

void func_02048B30(void *g3dCamera, VecFx32 *out);

void MTX_LookAt(VecFx32 *eye, VecFx32 *target, VecFx32 *up, int *outMtx43);

void func_02082B60(int *mtx43, int *outMtx33);

void func_0207B0A4(int *mtx33, int *outMtx33);

void MTX_MultVec33(VecFx32 *src, int *mtx33, VecFx32 *dst);

void *FIELDMAP_GetCamera(void *fieldMap);

void *FIELD_CAMERA_GetG3dCamera(void *fieldCamera);

void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *dst);

void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *file, unsigned short line);

u32 func_02030CB0(u32 capacity);

struct TcbList *func_02030CBC(u32 capacity, struct TcbList *buf);

extern u32 func_020307B0(void *p);

extern void TCB_Main(struct TcbList *list);

int func_02034AC4(s32 overlayId);

struct Tcb *func_02030DA8(struct TcbList *list, TcbFunc fn, void *work, int priority);

void func_02030EAC(struct Tcb *tcb);

void func_02034A5C(int overlayId);

void MI_CpuFill8(void *p, int v, int n);

extern void func_02034714(const char *expr, u32 line, const char *file);

u32 func_020084F8(void *myStatus, u16 *dst, u32 size);

u8 func_02008550(void *myStatus);

void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

void OS_GetMacAddress(u8 *outMac);

void MI_CpuCopy8(const void *src, void *dst, int n);

void *ICA_ANIME_GetField1C(void *gameSystem);

void *GAME_DATA_GetField1A0(void *gameData);

void *GAME_DATA_GetSaveControl(void *gameData);

void *MISC_SAVEDATA_GetBlock44(void *saveControl);

int UNION_CHARA_IsWifiFriendBeacon(void *wifiList, UnionBeacon *beacon);

int func_0200EDC4(void *list, u32 trainerId);

extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

void FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay);

int FLDEFF_GYOE_IsFinished(void *task);

void FLDEFF_GYOE_InitHeldTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_DeleteTask(void);

void FLDEFF_GYOE_UpdateHeldTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_UpdateTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_DrawTask(void *task, FldeffGyoeTaskWork *work);

void FLDEFF_GYOE_PlaySe(int type);

void FLDEFF_GYOE_RotateByCamera(void *g3dCamera, VecFx32 *src, VecFx32 *dst);

void FLDEFF_GYOE_StepAnimation(FldeffGyoeTaskWork *work, VecFx32 *out);

FieldSubprocMgr *FIELD_SUBPROC_MGR_Create(void *fieldSys, int heapId, int capacity);

void FIELD_SUBPROC_MGR_Delete(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_MGR_RunUpdate(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_MGR_RunDraw(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_UpdateTcb(struct Tcb *tcb, FieldSubproc *proc);

void FIELD_SUBPROC_DrawTcb(struct Tcb *tcb, FieldSubproc *proc);

FieldSubproc *FIELD_SUBPROC_Start(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl);

void FIELD_SUBPROC_End(FieldSubproc *proc);

void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc);

void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType);

UnionChatLine *UNION_CHAT_LOG_TakeSlot(UnionChatRing *ring);

UnionChatLine *UNION_CHAT_LOG_GetLine(UnionChatRing *ring, u32 index);

int UNION_CHAT_LOG_IsNew(UnionChatRing *ring, const void *mac, u16 chatCount);

extern int gGyoeHeldTaskHeader;

extern const G3dObjectTransform gGyoeDrawTransformInit;

extern MtxFx44 g_DefaultProjectionMtx;

extern GxState SCREENTEX_CameraState;

extern int d_021DE2F8;

extern char gUnionChatEmptyMac[];

/* Starts a mark that stays until its owner reads the finished flag. */
void FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay)
{
    FldeffGyoeTaskParam param;

    param.type = type;
    param.sePlay = sePlay;
    param.gyoe = (FldeffGyoe *)FIELD_EFFECT_GetResource(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    FLDMMDL_GetCheckInfo(mmdl, &param.mmdlInfo);
    param.fieldMap = FIELD_EFFECT_GetFieldMap(fieldEffectCtrl);
    if (sePlay == 1) {
        FLDEFF_GYOE_PlaySe(type);
    }
    FIELD_EFFECT_AddObject(fieldEffectCtrl, &gGyoeHeldTaskHeader, 0, 0, &param, 0);
}

/* Returns 1 when the task is gone or its mark is finished. */
int FLDEFF_GYOE_IsFinished(void *task)
{
    if (task != 0) {
        return ((FldeffGyoeTaskWork *)FIELD_EFFECT_GetObjectWork(task))->finished;
    }
    return 1;
}

void FLDEFF_GYOE_InitHeldTask(void *task, FldeffGyoeTaskWork *work)
{
    work->param = *FIELD_EFFECT_GetObjectParam(task);
    work->yVelocity = 0x6000;
    FIELD_EFFECT_UpdateObject(task);
}

void FLDEFF_GYOE_DeleteTask(void) {}

void FLDEFF_GYOE_UpdateHeldTask(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        work->finished = 1;
        return;
    }
    FLDMMDL_GetPos(work->param.mmdl, &pos);
    FLDEFF_GYOE_StepAnimation(work, &pos);
    FIELD_EFFECT_SetObjectPos(task, &pos);
}

void FLDEFF_GYOE_UpdateTask(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (work->finished == 1 || FLDMMDL_CheckCheckInfo(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        FIELD_EFFECT_DeleteObject(task);
        return;
    }
    FLDMMDL_GetPos(work->param.mmdl, &pos);
    FLDEFF_GYOE_StepAnimation(work, &pos);
    FIELD_EFFECT_SetObjectPos(task, &pos);
}

/*
 * Twin of ov021_func_02189810 (save/modify/restore of the projection matrix
 * g_DefaultProjectionMtx).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_DefaultProjectionMtx` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 */
void FLDEFF_GYOE_DrawTask(void *task, FldeffGyoeTaskWork *work)
{
    G3dObjectTransform transform = gGyoeDrawTransformInit;
    MtxFx44 *projection = &g_DefaultProjectionMtx;
    MtxFx44 saved;
    MtxFx44 shifted;
    fx32 zBias;

    zBias = FX_F32_TO_FX32(work->param.gyoe->resourceCount);
    saved = *projection;
    shifted = saved;
    shifted.m[3][2] += FX_MUL(shifted.m[2][2], zBias);
    MIi_CpuCopyFast(&shifted, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.matrixDirtyFlags &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
    MTX_Identity33_(&transform.rotation);
    FIELD_EFFECT_GetObjectPos(task, &transform);
    G3D_SYSTEM_DrawObjectCulling(work->param.gyoe->object[work->param.type], &transform);
    MIi_CpuCopyFast(&saved, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.matrixDirtyFlags &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
}

void FLDEFF_GYOE_PlaySe(int type)
{
    int seId = 0;

    switch (type) {
    case 0:
        seId = 0x678;
        break;
    case 1:
        seId = 0x730;
        break;
    case 2:
        seId = 0x731;
        break;
    case 3:
        return;
    }
    GFL_USE_PlaySeDefaultVolume(seId);
}

/* Rotates src by the inverse of the camera's orientation. */
void FLDEFF_GYOE_RotateByCamera(void *g3dCamera, VecFx32 *src, VecFx32 *dst)
{
    VecFx32 eye;
    VecFx32 target;
    VecFx32 up;
    int lookAt[12];
    int inverse[9];

    func_02048AE8(g3dCamera, &eye);
    func_02048B0C(g3dCamera, &target);
    func_02048B30(g3dCamera, &up);
    MTX_LookAt(&eye, &target, &up, lookAt);
    func_02082B60(lookAt, inverse);
    func_0207B0A4(inverse, inverse);
    MTX_MultVec33(src, inverse, dst);
}

/* Steps the hop and wait animation and returns the mark position in out. */
void FLDEFF_GYOE_StepAnimation(FldeffGyoeTaskWork *work, VecFx32 *out)
{
    void *g3dCamera;
    VecFx32 offset;

    switch (work->state) {
    case 0:
        work->yOffset += work->yVelocity;
        if (work->yOffset != 0) {
            work->yVelocity = work->yVelocity - 0x2000;
        } else {
            work->yVelocity = 0;
            work->state = work->state + 1;
        }
        break;
    case 1:
        work->timer = work->timer + 1;
        if (work->timer >= 30) {
            work->state = work->state + 1;
            work->finished = 1;
        }
        break;
    }
    g3dCamera = FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(work->param.fieldMap));
    {
        VecFx32 above = {0, 0, 0};

        above.y = work->yOffset + 0x16000;
        offset = above;
    }
    FLDEFF_GYOE_RotateByCamera(g3dCamera, &offset, &offset);
    VEC_Add(&offset, out, out);
}

FieldSubprocMgr *FIELD_SUBPROC_MGR_Create(void *fieldSys, int heapId, int capacity)
{
    FieldSubprocMgr *mgr = func_02030734(heapId, 0x18, 1, (const char *)&d_021DE2F8, 0x46);
    int listSize;

    mgr->fieldSys = fieldSys;
    mgr->heapId = heapId;
    mgr->capacity = capacity;
    mgr->procs = func_02030734(heapId, 0x18 * capacity, 1, (const char *)&d_021DE2F8, 0x4a);
    listSize = func_02030CB0(capacity);
    mgr->drawList = func_02030734(heapId, listSize, 1, (const char *)&d_021DE2F8, 0x56);
    mgr->drawList = func_02030CBC(capacity, mgr->drawList);
    mgr->updateList = func_02030734(heapId, listSize, 1, (const char *)&d_021DE2F8, 0x59);
    mgr->updateList = func_02030CBC(capacity, mgr->updateList);
    return mgr;
}

void FIELD_SUBPROC_MGR_Delete(FieldSubprocMgr *mgr)
{
    int i;

    for (i = 0; i < mgr->capacity; i++) {
        FIELD_SUBPROC_End(&mgr->procs[i]);
    }
    func_020307B0(mgr->procs);
    func_020307B0(mgr->updateList);
    func_020307B0(mgr->drawList);
    func_020307B0(mgr);
}

void FIELD_SUBPROC_MGR_RunUpdate(FieldSubprocMgr *mgr)
{
    TCB_Main(mgr->updateList);
}

void FIELD_SUBPROC_MGR_RunDraw(FieldSubprocMgr *mgr)
{
    TCB_Main(mgr->drawList);
}

void FIELD_SUBPROC_UpdateTcb(struct Tcb *tcb, FieldSubproc *proc)
{
    if (proc->tmpl->update != 0) {
        proc->tmpl->update(proc, proc->mgr->fieldSys, proc->work);
    }
}

void FIELD_SUBPROC_DrawTcb(struct Tcb *tcb, FieldSubproc *proc)
{
    if (proc->tmpl->draw != 0) {
        proc->tmpl->draw(proc, proc->mgr->fieldSys, proc->work);
    }
}

FieldSubproc *FIELD_SUBPROC_Start(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl)
{
    FieldSubproc *proc = mgr->procs;
    int i;

    for (i = 0; i < mgr->capacity; i++, proc++) {
        if (proc->updateTcb != 0) {
            continue;
        }
        if (overlayId != -1) {
            func_02034AC4(overlayId);
        }
        proc->overlayId = overlayId;
        proc->updateTcb = func_02030DA8(mgr->updateList, (TcbFunc)FIELD_SUBPROC_UpdateTcb, proc, tmpl->priority);
        proc->drawTcb = func_02030DA8(mgr->drawList, (TcbFunc)FIELD_SUBPROC_DrawTcb, proc, tmpl->priority);
        proc->mgr = mgr;
        proc->tmpl = tmpl;
        if (tmpl->workSize != 0) {
            proc->work = func_02030734((u16)mgr->heapId, tmpl->workSize, 1, (const char *)&d_021DE2F8, 0xc3);
        }
        if (tmpl->init != 0) {
            tmpl->init(proc, mgr->fieldSys, proc->work);
        }
        return proc;
    }
    return 0;
}

void FIELD_SUBPROC_End(FieldSubproc *proc)
{
    const FieldSubprocTemplate *tmpl;

    if (proc->updateTcb == 0) {
        return;
    }
    tmpl = proc->tmpl;
    if (tmpl->exit != 0) {
        tmpl->exit(proc, proc->mgr->fieldSys, proc->work);
    }
    if (proc->tmpl->workSize != 0) {
        func_020307B0(proc->work);
    }
    func_02030EAC(proc->updateTcb);
    func_02030EAC(proc->drawTcb);
    if (proc->overlayId != -1) {
        func_02034A5C(proc->overlayId);
    }
    MI_CpuFill8(proc, 0, 0x18);
}

void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc)
{
    return proc->work;
}

/*
 * Adds one line to the chat log: from a received beacon, or (beaconPc zero)
 * from the own player with the sentence in chatPms.
 */
void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType)
{
    UnionChatRing *ring = (UnionChatRing *)&work->chatLog;
    UnionChatLine *line;
    void *myStatus;
    void *wifiList;
    void *saveControl;
    int relation;

    if (beaconPc == 0 && chatPms == 0) {
        func_02034714((const char *)0x021DE308, 0, (const char *)0x021DE308);
    }
    if (beaconPc != 0 && UNION_CHAT_LOG_IsNew(ring, beaconPc->mac, beaconPc->beacon.chatCount) == 0) {
        return;
    }
    line = UNION_CHAT_LOG_TakeSlot(ring);
    if (beaconPc == 0) {
        myStatus = work->parent->myStatus;
        func_020084F8(myStatus, line->name, 8);
        /* the re-test of chatPms inside the chatPms == 0 arm is the dead second bne */
        if (chatPms == 0) {
            if (chatPms != 0 || chatType == 0) {
                func_02034714((const char *)0x021DE308, 0, (const char *)0x021DE308);
            }
        }
        line->chatPms[0] = chatPms[0];
        line->chatPms[1] = chatPms[1];
        line->chatPms[2] = chatPms[2];
        line->chatPms[3] = chatPms[3];
        line->chatType = chatType;
        line->chatCount = 0;
        OS_GetMacAddress(line->senderMac);
        line->sex = func_02008550(myStatus);
        line->relation = 0;
    } else {
        WORDSET_CopyString(beaconPc->beacon.name, line->name, 8);
        line->chatPms[0] = beaconPc->beacon.chatPms.word[0];
        line->chatPms[1] = beaconPc->beacon.chatPms.word[1];
        line->chatPms[2] = beaconPc->beacon.chatPms.word[2];
        line->chatPms[3] = beaconPc->beacon.chatPms.word[3];
        line->chatType = beaconPc->beacon.chatType;
        line->chatCount = beaconPc->beacon.chatCount;
        MI_CpuCopy8(beaconPc->mac, line->senderMac, 6);
        line->sex = beaconPc->beacon.sex;
        saveControl = ICA_ANIME_GetField1C(work->parent->gameSystem);
        wifiList = GAME_DATA_GetField1A0(saveControl);
        saveControl = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(saveControl));
        if (UNION_CHARA_IsWifiFriendBeacon(wifiList, &beaconPc->beacon) == 1) {
            relation = 1;
        } else if (func_0200EDC4(saveControl, beaconPc->beacon.trainerId) == 1) {
            relation = 2;
        } else {
            relation = 0;
        }
        line->relation = relation;
    }
    if (ring->newestIndex == ring->oldestIndex) {
        ring->oldestIndex++;
    }
    ring->newestIndex++;
    if (ring->newestIndex - ring->oldestIndex >= 30) {
        ring->oldestIndex = ring->newestIndex - 29;
    }
}

/* Takes the slot for the next line, dropping the oldest line when full. */
UnionChatLine *UNION_CHAT_LOG_TakeSlot(UnionChatRing *ring)
{
    int slot;
    UnionChatLine *line;
    if (ring->newestIndex > 0) {
        slot = ring->endSlot;
        if (slot == ring->startSlot) {
            ring->startSlot += 1;
            if (ring->startSlot >= 30) ring->startSlot = 0;
        }
    }
    line = &ring->line[ring->endSlot];
    ring->endSlot += 1;
    if (ring->endSlot >= 30) ring->endSlot = 0;
    return line;
}

/* Returns the line with the given absolute index, or zero when it is empty. */
UnionChatLine *UNION_CHAT_LOG_GetLine(UnionChatRing *ring, u32 index)
{
    UnionChatLine *line = &ring->line[index % 30];

    if (GF_STANDARD_CompareBytes(line->senderMac, (const u8 *)gUnionChatEmptyMac, 6) == 0) {
        line = 0;
    }
    return line;
}

/*
 * Returns 0 when a kept line from this sender has this chat count already.
 * A u16 chatCount (not int/u32) is what stores its spill before mac's.
 */
int UNION_CHAT_LOG_IsNew(UnionChatRing *ring, const void *mac, u16 chatCount)
{
    int i;
    UnionChatLine *line;

    for (i = ring->newestIndex; i > ring->newestIndex - 30; i--) {
        if (i < 0) return 1;
        line = UNION_CHAT_LOG_GetLine(ring, i);
        if (line != 0 && GF_STANDARD_CompareBytes(line->senderMac, mac, 6) == 0) {
            if (line->chatCount != chatCount) return 1;
            return 0;
        }
    }
    return 1;
}
