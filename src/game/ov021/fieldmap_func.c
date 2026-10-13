/*
 * file:     fieldmap_func.c
 * unit:     yes
 * function: func_021BB578, func_021BB5C8, func_021BB5DC, func_021BB608, func_021BB60C, func_021BB648, func_021BB68C, func_021BB778, func_021BB7B4, func_021BB808, func_021BB890, func_021BB90C, func_021BB948, func_021BB954, func_021BB960, func_021BB978, func_021BB990, func_021BBA1C, func_021BBA6C, func_021BBA70, func_021BBBD8, func_021BBC2C, func_021BBC58, func_021BBCBC, func_021BBCF8, func_021BBD0C, func_021BBD64, func_021BBD84
 * address:  0x021BB578
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A90     0x021D9A90  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021D9AA4       0x021D9AA4  data  a4
 *   _fflt            0x0209BDBC  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   _ffix            0x0209C494  arm
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   func_0207ADC4    0x0207ADC4  arm
 *   func_021AC1B8    0x021AC1B8  thumb  ov021
 *   func_02047AC8    0x02047AC8  arm
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 *   func_020061E4  0x020061E4  thumb
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02030D28  0x02030D28  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034714  0x02034714  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0201F41C  0x0201F41C  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9AE0     0x021D9AE0  data  a4
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02188C88  0x02188C88  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   d_021D9B0C     0x021D9B0C  data  a2
 *   d_021D9AE8     0x021D9AE8  data  a4
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;

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

/* ---- externs ---- */

int func_021ABEA0(void *fieldEffectCtrl, u32 effectId);
void func_0216E1A4(Mmdl *mmdl, MmdlCheckInfo *info);
void *func_021ABE14(void *fieldEffectCtrl);
void *func_021ABFA8(void *fieldEffectCtrl, const void *taskHeader, int a2, int a3, FldeffGyoeTaskParam *param, int a5);
extern void *func_021AC1E0(void *task);
extern FldeffGyoeTaskParam *func_021AC1AC(void *task);
extern void func_021AC178(void *task);
extern int func_0216E1C4(Mmdl *mmdl, MmdlCheckInfo *info);
extern void func_0216D88C(Mmdl *mmdl, VecFx32 *out);
extern void func_021AC1CC(void *task, VecFx32 *pos);
void func_021AC154(void *task);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void func_0207ADC4(MtxFx33 *mtx);
extern void func_021AC1B8(void *task, G3dObjectTransform *transform);
extern int func_02047AC8(void *object, G3dObjectTransform *transform);
void func_020061E4(u32 seId);
void func_02048AE8(void *g3dCamera, VecFx32 *out);
void func_02048B0C(void *g3dCamera, VecFx32 *out);
void func_02048B30(void *g3dCamera, VecFx32 *out);
void func_0207BCA0(VecFx32 *eye, VecFx32 *target, VecFx32 *up, int *outMtx43);
void func_02082B60(int *mtx43, int *outMtx33);
void func_0207B0A4(int *mtx33, int *outMtx33);
void func_0207B51C(VecFx32 *src, int *mtx33, VecFx32 *dst);
void *func_02188C58(void *fieldMap);
void *func_0218EC2C(void *fieldCamera);
void func_0207C9D0(VecFx32 *a, VecFx32 *b, VecFx32 *dst);
void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *file, unsigned short line);
u32 func_02030CB0(u32 capacity);
struct TcbList *func_02030CBC(u32 capacity, struct TcbList *buf);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct TcbList *list);
int func_02034AC4(s32 overlayId);
struct Tcb *func_02030DA8(struct TcbList *list, TcbFunc fn, void *work, int priority);
void func_02030EAC(struct Tcb *tcb);
void func_02034A5C(int overlayId);
void func_02082BCC(void *p, int v, int n);
extern void func_02034714(const char *expr, u32 line, const char *file);
u32 func_020084F8(void *myStatus, u16 *dst, u32 size);
u8 func_02008550(void *myStatus);
void func_0201F41C(const u16 *src, u16 *dst, u32 n);
void func_02087C6C(u8 *outMac);
void func_02082D44(const void *src, void *dst, int n);
void *func_020120F4(void *gameSystem);
void *func_0201283C(void *gameData);
void *func_02012EBC(void *gameData);
void *func_0200ED48(void *saveControl);
int func_0217F894(void *wifiList, UnionBeacon *beacon);
int func_0200EDC4(void *list, u32 trainerId);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void *func_02188C88(void *fieldMap);
extern void *func_021ABE24(void *fieldEffectCtrl);
extern void *func_02046E24(void *g3dHeap, u32 resId);
extern void func_021AC1F0(void *fieldEffectCtrl, void *resource);
extern u16 func_020500F0(void *bbActSys, const FootmarkSlotRecord *recs, u32 n);
extern void func_02050278(void *bbActSys, u32 first, u32 count);
void func_021BB578(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay);
int func_021BB5C8(void *task);
void func_021BB5DC(void *task, FldeffGyoeTaskWork *work);
void func_021BB608(void);
void func_021BB60C(void *task, FldeffGyoeTaskWork *work);
void func_021BB648(void *task, FldeffGyoeTaskWork *work);
void func_021BB68C(void *task, FldeffGyoeTaskWork *work);
void func_021BB778(int type);
void func_021BB7B4(void *g3dCamera, VecFx32 *src, VecFx32 *dst);
void func_021BB808(FldeffGyoeTaskWork *work, VecFx32 *out);
FieldSubprocMgr *func_021BB890(void *fieldSys, int heapId, int capacity);
void func_021BB90C(FieldSubprocMgr *mgr);
void func_021BB948(FieldSubprocMgr *mgr);
void func_021BB954(FieldSubprocMgr *mgr);
void func_021BB960(struct Tcb *tcb, FieldSubproc *proc);
void func_021BB978(struct Tcb *tcb, FieldSubproc *proc);
FieldSubproc *func_021BB990(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl);
void func_021BBA1C(FieldSubproc *proc);
void *func_021BBA6C(const FieldSubproc *proc);
void func_021BBA70(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType);
UnionChatLine *func_021BBBD8(UnionChatRing *ring);
UnionChatLine *func_021BBC2C(UnionChatRing *ring, u32 index);
int func_021BBC58(UnionChatRing *ring, const void *mac, u16 chatCount);
FootmarkEffectWork *func_021BBCBC(void *fieldEffectCtrl, u32 heapId);
void func_021BBCF8(u32 unused, FootmarkEffectWork *effWork);
void func_021BBD0C(FootmarkEffectWork *effWork);
void func_021BBD64(FootmarkEffectWork *effWork);
int func_021BBD84(FootmarkEffectWork *effWork, int type, int dir, int oldDir);
extern int d_021D9A90;
extern const G3dObjectTransform d_021D9AA4;
extern MtxFx44 g_02148B54;
extern GxState g_02148BCC;
extern int d_021DE2F8;
extern char d_021D9AE0[];
extern const char d_021DE30C[];
extern u16 d_021D9B0C[];
extern FootmarkDirRow d_021D9AE8[];

/* Starts a mark that stays until its owner reads the finished flag. */
void func_021BB578(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay)
{
    FldeffGyoeTaskParam param;

    param.type = type;
    param.sePlay = sePlay;
    param.gyoe = (FldeffGyoe *)func_021ABEA0(fieldEffectCtrl, 4);
    param.mmdl = mmdl;
    func_0216E1A4(mmdl, &param.mmdlInfo);
    param.fieldMap = func_021ABE14(fieldEffectCtrl);
    if (sePlay == 1) {
        func_021BB778(type);
    }
    func_021ABFA8(fieldEffectCtrl, &d_021D9A90, 0, 0, &param, 0);
}

/* Returns 1 when the task is gone or its mark is finished. */
int func_021BB5C8(void *task)
{
    if (task != 0) {
        return ((FldeffGyoeTaskWork *)func_021AC1E0(task))->finished;
    }
    return 1;
}

void func_021BB5DC(void *task, FldeffGyoeTaskWork *work)
{
    work->param = *func_021AC1AC(task);
    work->yVelocity = 0x6000;
    func_021AC178(task);
}

void func_021BB608(void) {}

void func_021BB60C(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (func_0216E1C4(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        work->finished = 1;
        return;
    }
    func_0216D88C(work->param.mmdl, &pos);
    func_021BB808(work, &pos);
    func_021AC1CC(task, &pos);
}

void func_021BB648(void *task, FldeffGyoeTaskWork *work)
{
    VecFx32 pos;

    if (work->finished == 1 || func_0216E1C4(work->param.mmdl, &work->param.mmdlInfo) == 0) {
        func_021AC154(task);
        return;
    }
    func_0216D88C(work->param.mmdl, &pos);
    func_021BB808(work, &pos);
    func_021AC1CC(task, &pos);
}

/*
 * Twin of ov021_func_02189810 (save/modify/restore of the projection matrix
 * g_02148B54).  Here the matrix is read through a pointer local initialised
 * at its declaration, which is what loads its address before the soft-float
 * conversion; `saved = g_02148B54` loads it after (22 bytes off with the
 * pointer declared first, r4/r5 swapped with it declared last).
 */
void func_021BB68C(void *task, FldeffGyoeTaskWork *work)
{
    G3dObjectTransform transform = d_021D9AA4;
    MtxFx44 *projection = &g_02148B54;
    MtxFx44 saved;
    MtxFx44 shifted;
    fx32 zBias;

    zBias = FX_F32_TO_FX32(work->param.gyoe->resourceCount);
    saved = *projection;
    shifted = saved;
    shifted.m[3][2] += FX_MUL(shifted.m[2][2], zBias);
    MIi_CpuCopyFast(&shifted, &g_02148B54, 0x40);
    g_02148BCC.matrixDirtyFlags &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_0207ADC4(&transform.rotation);
    func_021AC1B8(task, &transform);
    func_02047AC8(work->param.gyoe->object[work->param.type], &transform);
    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.matrixDirtyFlags &= ~0x50;
    func_0206A854();
    func_0206DB80();
}

void func_021BB778(int type)
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
    func_020061E4(seId);
}

/* Rotates src by the inverse of the camera's orientation. */
void func_021BB7B4(void *g3dCamera, VecFx32 *src, VecFx32 *dst)
{
    VecFx32 eye;
    VecFx32 target;
    VecFx32 up;
    int lookAt[12];
    int inverse[9];

    func_02048AE8(g3dCamera, &eye);
    func_02048B0C(g3dCamera, &target);
    func_02048B30(g3dCamera, &up);
    func_0207BCA0(&eye, &target, &up, lookAt);
    func_02082B60(lookAt, inverse);
    func_0207B0A4(inverse, inverse);
    func_0207B51C(src, inverse, dst);
}

/* Steps the hop and wait animation and returns the mark position in out. */
void func_021BB808(FldeffGyoeTaskWork *work, VecFx32 *out)
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
    g3dCamera = func_0218EC2C(func_02188C58(work->param.fieldMap));
    {
        VecFx32 above = {0, 0, 0};

        above.y = work->yOffset + 0x16000;
        offset = above;
    }
    func_021BB7B4(g3dCamera, &offset, &offset);
    func_0207C9D0(&offset, out, out);
}

FieldSubprocMgr *func_021BB890(void *fieldSys, int heapId, int capacity)
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

void func_021BB90C(FieldSubprocMgr *mgr)
{
    int i;

    for (i = 0; i < mgr->capacity; i++) {
        func_021BBA1C(&mgr->procs[i]);
    }
    func_020307B0(mgr->procs);
    func_020307B0(mgr->updateList);
    func_020307B0(mgr->drawList);
    func_020307B0(mgr);
}

void func_021BB948(FieldSubprocMgr *mgr)
{
    func_02030D28(mgr->updateList);
}

void func_021BB954(FieldSubprocMgr *mgr)
{
    func_02030D28(mgr->drawList);
}

void func_021BB960(struct Tcb *tcb, FieldSubproc *proc)
{
    if (proc->tmpl->update != 0) {
        proc->tmpl->update(proc, proc->mgr->fieldSys, proc->work);
    }
}

void func_021BB978(struct Tcb *tcb, FieldSubproc *proc)
{
    if (proc->tmpl->draw != 0) {
        proc->tmpl->draw(proc, proc->mgr->fieldSys, proc->work);
    }
}

FieldSubproc *func_021BB990(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl)
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
        proc->updateTcb = func_02030DA8(mgr->updateList, (TcbFunc)func_021BB960, proc, tmpl->priority);
        proc->drawTcb = func_02030DA8(mgr->drawList, (TcbFunc)func_021BB978, proc, tmpl->priority);
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

void func_021BBA1C(FieldSubproc *proc)
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
    func_02082BCC(proc, 0, 0x18);
}

void *func_021BBA6C(const FieldSubproc *proc)
{
    return proc->work;
}

/*
 * Adds one line to the chat log: from a received beacon, or (beaconPc zero)
 * from the own player with the sentence in chatPms.
 */
void func_021BBA70(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType)
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
    if (beaconPc != 0 && func_021BBC58(ring, beaconPc->mac, beaconPc->beacon.chatCount) == 0) {
        return;
    }
    line = func_021BBBD8(ring);
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
        func_02087C6C(line->senderMac);
        line->sex = func_02008550(myStatus);
        line->relation = 0;
    } else {
        func_0201F41C(beaconPc->beacon.name, line->name, 8);
        line->chatPms[0] = beaconPc->beacon.chatPms.word[0];
        line->chatPms[1] = beaconPc->beacon.chatPms.word[1];
        line->chatPms[2] = beaconPc->beacon.chatPms.word[2];
        line->chatPms[3] = beaconPc->beacon.chatPms.word[3];
        line->chatType = beaconPc->beacon.chatType;
        line->chatCount = beaconPc->beacon.chatCount;
        func_02082D44(beaconPc->mac, line->senderMac, 6);
        line->sex = beaconPc->beacon.sex;
        saveControl = func_020120F4(work->parent->gameSystem);
        wifiList = func_0201283C(saveControl);
        saveControl = func_0200ED48(func_02012EBC(saveControl));
        if (func_0217F894(wifiList, &beaconPc->beacon) == 1) {
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
UnionChatLine *func_021BBBD8(UnionChatRing *ring)
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
UnionChatLine *func_021BBC2C(UnionChatRing *ring, u32 index)
{
    UnionChatLine *line = &ring->line[index % 30];

    if (func_0203EFC8(line->senderMac, (const u8 *)d_021D9AE0, 6) == 0) {
        line = 0;
    }
    return line;
}

/*
 * Returns 0 when a kept line from this sender has this chat count already.
 * A u16 chatCount (not int/u32) is what stores its spill before mac's.
 */
int func_021BBC58(UnionChatRing *ring, const void *mac, u16 chatCount)
{
    int i;
    UnionChatLine *line;

    for (i = ring->newestIndex; i > ring->newestIndex - 30; i--) {
        if (i < 0) return 1;
        line = func_021BBC2C(ring, i);
        if (line != 0 && func_0203EFC8(line->senderMac, mac, 6) == 0) {
            if (line->chatCount != chatCount) return 1;
            return 0;
        }
    }
    return 1;
}

FootmarkEffectWork *func_021BBCBC(void *fieldEffectCtrl, u32 heapId)
{
    FootmarkEffectWork *effWork;

    effWork = func_02030734(heapId, 0x40, 1, d_021DE30C, 0x9d);
    effWork->fieldEffectCtrl = fieldEffectCtrl;
    effWork->bbActSys = func_02188C88(func_021ABE14(fieldEffectCtrl));
    func_021BBD0C(effWork);
    effWork->snowHeightOffset = 0x2000;
    return effWork;
}

void func_021BBCF8(u32 unused, FootmarkEffectWork *effWork)
{
    func_021BBD64(effWork);
    func_020307B0(effWork);
}

void func_021BBD0C(FootmarkEffectWork *effWork)
{
    FootmarkSlotRecord record;
    int i;
    const u16 *resId = d_021D9B0C;
    void *g3dHeap = func_021ABE24(effWork->fieldEffectCtrl);

    record.kind = 2;
    record.flags = 0x11;
    record.width = 0x10;
    record.height = 0x10;
    record.count = 1;
    for (i = 0; i < 0x1a; i++, resId++) {
        record.resource = func_02046E24(g3dHeap, *resId);
        func_021AC1F0(effWork->fieldEffectCtrl, record.resource);
        effWork->resIdx[i] = func_020500F0(effWork->bbActSys, &record, 1);
    }
}

void func_021BBD64(FootmarkEffectWork *effWork)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        func_02050278(effWork->bbActSys, effWork->resIdx[i], 1);
    }
}

/* Picks the billboard slot of a footmark picture (oldDir selects the turn row). */
int func_021BBD84(FootmarkEffectWork *effWork, int type, int dir, int oldDir)
{
    int slot = 0;
    switch (type) {
    case 0: slot = dir; break;
    case 1: slot = d_021D9AE8[oldDir].slot[dir]; break;
    case 2: slot = dir + 10; break;
    case 3: slot = d_021D9AE8[oldDir].slot[dir] - 4; slot += 14; break;
    case 4: slot = d_021D9AE8[oldDir].slot[dir] - 4; slot += 20; break;
    }
    return slot;
}
