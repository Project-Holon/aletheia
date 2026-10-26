#ifndef GAME_OV021_FIELDMAP_FUNC_H
#define GAME_OV021_FIELDMAP_FUNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldmap_func.c, prototypes copied from their definitions. */

struct FieldSubprocMgr;
struct TcbTask;
struct FieldSubproc;
struct FieldSubprocTemplate;
typedef struct FieldSubprocMgr FieldSubprocMgr;
typedef struct FieldSubproc FieldSubproc;
typedef struct FieldSubprocTemplate FieldSubprocTemplate;

FieldSubprocMgr *FIELD_SUBPROC_MGR_Create(void *fieldSys, int heapId, int capacity);
void FIELD_SUBPROC_MGR_Delete(FieldSubprocMgr *mgr);
void FIELD_SUBPROC_MGR_RunUpdate(FieldSubprocMgr *mgr);
void FIELD_SUBPROC_MGR_RunDraw(FieldSubprocMgr *mgr);
void FIELD_SUBPROC_UpdateTcb(struct TcbTask *tcb, void *arg);
void FIELD_SUBPROC_DrawTcb(struct TcbTask *tcb, void *arg);
FieldSubproc *FIELD_SUBPROC_Start(int overlayId, FieldSubprocMgr *mgr, const FieldSubprocTemplate *tmpl);
void FIELD_SUBPROC_End(FieldSubproc *proc);
void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc);
/* END mkheaders: generated region */

#endif
