/*
 * file:     fieldmap_func.c
 * unit:     yes
 * function: FIELD_SUBPROC_MGR_Create, FIELD_SUBPROC_MGR_Delete, FIELD_SUBPROC_MGR_RunUpdate, FIELD_SUBPROC_MGR_RunDraw, FIELD_SUBPROC_UpdateTcb, FIELD_SUBPROC_DrawTcb, FIELD_SUBPROC_Start, FIELD_SUBPROC_End, FIELD_SUBPROC_GetWork
 * address:  0x021BB890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): the FIELD_SUBPROC_ sub process manager 021BB890..021BBA6F. __FILE__ anchor fieldmap_func.c at FIELD_SUBPROC_MGR_Create 021BB908 and FIELD_SUBPROC_Start 021BBA18 (string d_021DE2F8, which sits between the fldeff_gyoe.c string 0x021DE2E8 and the fldeff_footmark.c data). The FLDEFF_GYOE_ functions that used to open this file are in fldeff_gyoe.c; the UNION_CHAT_LOG_ code after it is union_chat_log.c.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 *   TCB_Main  0x02030D28  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
typedef int fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

#include "../ov012/union_comm_types.h"

struct FieldSubproc;

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

void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *file, unsigned short line);

u32 TCB_GetTaskOffset(u32 capacity);

struct TcbList *TCB_Init(u32 capacity, struct TcbList *buf);

extern u32 GFL_HEAP_Free(void *p);

extern void TCB_Main(struct TcbList *list);

int GF_OVERLAY_Load(s32 overlayId);

struct Tcb *TCB_AddTask(struct TcbList *list, TcbFunc fn, void *work, int priority);

void TCB_DeleteTask(struct Tcb *tcb);

void GF_OVERLAY_Unload(int overlayId);

void MI_CpuFill8(void *p, int v, int n);

FieldSubprocMgr *FIELD_SUBPROC_MGR_Create(void *fieldSys, int heapId, int capacity);

void FIELD_SUBPROC_MGR_Delete(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_MGR_RunUpdate(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_MGR_RunDraw(FieldSubprocMgr *mgr);

void FIELD_SUBPROC_UpdateTcb(struct Tcb *tcb, FieldSubproc *proc);

void FIELD_SUBPROC_DrawTcb(struct Tcb *tcb, FieldSubproc *proc);

FieldSubproc *FIELD_SUBPROC_Start(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl);

void FIELD_SUBPROC_End(FieldSubproc *proc);

void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc);

extern int d_021DE2F8;

FieldSubprocMgr *FIELD_SUBPROC_MGR_Create(void *fieldSys, int heapId, int capacity)
{
    FieldSubprocMgr *mgr = GFL_HEAP_Alloc(heapId, 0x18, 1, (const char *)&d_021DE2F8, 0x46);
    int listSize;

    mgr->fieldSys = fieldSys;
    mgr->heapId = heapId;
    mgr->capacity = capacity;
    mgr->procs = GFL_HEAP_Alloc(heapId, 0x18 * capacity, 1, (const char *)&d_021DE2F8, 0x4a);
    listSize = TCB_GetTaskOffset(capacity);
    mgr->drawList = GFL_HEAP_Alloc(heapId, listSize, 1, (const char *)&d_021DE2F8, 0x56);
    mgr->drawList = TCB_Init(capacity, mgr->drawList);
    mgr->updateList = GFL_HEAP_Alloc(heapId, listSize, 1, (const char *)&d_021DE2F8, 0x59);
    mgr->updateList = TCB_Init(capacity, mgr->updateList);
    return mgr;
}

void FIELD_SUBPROC_MGR_Delete(FieldSubprocMgr *mgr)
{
    int i;

    for (i = 0; i < mgr->capacity; i++) {
        FIELD_SUBPROC_End(&mgr->procs[i]);
    }
    GFL_HEAP_Free(mgr->procs);
    GFL_HEAP_Free(mgr->updateList);
    GFL_HEAP_Free(mgr->drawList);
    GFL_HEAP_Free(mgr);
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
            GF_OVERLAY_Load(overlayId);
        }
        proc->overlayId = overlayId;
        proc->updateTcb = TCB_AddTask(mgr->updateList, (TcbFunc)FIELD_SUBPROC_UpdateTcb, proc, tmpl->priority);
        proc->drawTcb = TCB_AddTask(mgr->drawList, (TcbFunc)FIELD_SUBPROC_DrawTcb, proc, tmpl->priority);
        proc->mgr = mgr;
        proc->tmpl = tmpl;
        if (tmpl->workSize != 0) {
            proc->work = GFL_HEAP_Alloc((u16)mgr->heapId, tmpl->workSize, 1, (const char *)&d_021DE2F8, 0xc3);
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
        GFL_HEAP_Free(proc->work);
    }
    TCB_DeleteTask(proc->updateTcb);
    TCB_DeleteTask(proc->drawTcb);
    if (proc->overlayId != -1) {
        GF_OVERLAY_Unload(proc->overlayId);
    }
    MI_CpuFill8(proc, 0, 0x18);
}

void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc)
{
    return proc->work;
}
