#ifndef GAME_ARM9_PROCSYS_H
#define GAME_ARM9_PROCSYS_H

#include "../types.h"

typedef struct Proc Proc;

typedef u32 (*ProcFunc)(struct Proc *proc, u32 *subSeq, void *procWork, void *work);

typedef struct ProcData {
    ProcFunc init;
    ProcFunc main;
    ProcFunc end;
} ProcData;

/* One running process; a stack of these is linked through prev/next. */
typedef struct Proc {
    const ProcData *data;
    u32 overlayId;      /* -1: no overlay to load */
    u32 seq;            /* 0 load overlay, 1 init, 2 main, 3 end */
    u32 subSeq;
    void *procWork;     /* argument given by the caller */
    void *work;         /* buffer owned by the process (PROCSYS_AllocProcWork) */
    struct Proc *prev;  /* parent */
    struct Proc *next;  /* child */
} Proc;

/* The process manager object (0x20 bytes). */
typedef struct ProcSys {
    u16 heapId;
    u16 padding02;
    u32 unused04;       /* initialised to -1, never read here */
    Proc *current;      /* process on top of the stack */
    u32 pushPending;    /* a child process is queued */
    u32 replacePending; /* the current process is to be replaced */
    u32 nextOverlayId;  /* queued process: overlay, data, argument */
    const ProcData *nextData;
    void *nextProcWork;
} ProcSys;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of procsys.c, prototypes copied from their definitions. */

#include "../types.h"

void PROCSYS_CreateGlobal(int heapId);
int PROCSYS_MainGlobal(void);
void PROCSYS_PushGlobal(u32 overlayId, const ProcData *data, void *procWork);
void PROCSYS_ReplaceGlobal(u32 overlayId, const ProcData *data, void *procWork);
void *PROCSYS_Create(int heapId);
unsigned int PROCSYS_Main(ProcSys *sys);
void PROCSYS_Delete(ProcSys *sys);
void PROCSYS_Push(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
ProcSys *PROCSYS_CreateInternal(int heapId);
Proc *PROCSYS_PushQueued(ProcSys *sys);
u32 PROCSYS_MainInternal(ProcSys *sys);
void PROCSYS_DeleteInternal(ProcSys *sys);
void PROCSYS_QueueReplace(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
void PROCSYS_PushInternal(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
Proc *PROCSYS_NewProc(u32 overlayId, const ProcData *data, void *procWork, u32 heapId);
void PROCSYS_FreeProc(Proc *proc);
void *PROCSYS_AllocProcWork(Proc *proc, u32 size, u32 heapId);
void PROCSYS_FreeProcWork(Proc *proc);
u32 PROCSYS_StepProc(Proc *proc);
/* END mkheaders: generated region */

#endif
