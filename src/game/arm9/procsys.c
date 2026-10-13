/*
 * file:     procsys.c
 * unit:     yes
 * function: func_0203129C, func_020312B4, func_020312CC, func_020312F8, func_02031324, func_02031330, func_0203133C, func_02031348, func_02031354, func_020313A0, func_020313EC, func_020314B8, func_020314DC, func_020314F4, func_02031538, func_02031590, func_0203159C, func_020315D4, func_020315F0
 * address:  0x0203129C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_ProcSys 0x02146990 data
 *   ProcSys_AllocSiteName  0x020A783C  data
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020882D0       0x020882D0  arm
 *   func_02030734       0x02030734  arm
 *   ProcNew_AllocSiteName  0x020A783C  data
 *   func_020307B0  0x020307B0  arm
 *   ProcAllocWork_AllocSiteName 0x020A783C  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 */

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

struct Proc;

typedef u32 (*ProcFunc)(struct Proc *proc, u32 *subSeq, void *procWork, void *work);

typedef struct {
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
    void *work;         /* buffer owned by the process (func_0203159C) */
    struct Proc *prev;  /* parent */
    struct Proc *next;  /* child */
} Proc;

/* The process manager object (0x20 bytes). */
typedef struct {
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020882D0(void *p);
extern void ENV_SetResourceSet(void *p);
extern u32 func_020307B0(void *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
void func_0203129C(int heapId);
int func_020312B4(void);
void func_020312CC(u32 overlayId, const ProcData *data, void *procWork);
void func_020312F8(u32 overlayId, const ProcData *data, void *procWork);
void *func_02031324(int heapId);
unsigned int func_02031330(ProcSys *sys);
void sub_0203133C(ProcSys *sys);
void func_02031348(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
ProcSys *func_02031354(int heapId);
Proc *func_020313A0(ProcSys *sys);
u32 func_020313EC(ProcSys *sys);
void sub_020314B8(ProcSys *sys);
void sub_020314DC(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
void func_020314F4(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork);
Proc *func_02031538(u32 overlayId, const ProcData *data, void *procWork, u32 heapId);
void func_02031590(Proc *proc);
void *func_0203159C(Proc *proc, u32 size, u32 heapId);
void sub_020315D4(Proc *proc);
u32 func_020315F0(Proc *proc);
extern ProcSys *g_ProcSys;
extern char ProcSys_AllocSiteName[];
extern const char ProcNew_AllocSiteName[];
extern const char ProcAllocWork_AllocSiteName[];


void func_0203129C(int heapId)
{
    g_ProcSys = func_02031354(heapId);
}


/*
 * Tail-call forwarder passing g_ProcSys to func_020313EC.
 */
int func_020312B4(void)
{
    return func_020313EC(g_ProcSys);
}


/*
 * Forwarder: passes the object held in g_ProcSys to func_020314F4 with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 */
void func_020312CC(u32 overlayId, const ProcData *data, void *procWork)
{
    func_020314F4(g_ProcSys, overlayId, data, procWork);
}


/*
 * Forwarder: passes the object held in g_ProcSys to sub_020314DC with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 */
void func_020312F8(u32 overlayId, const ProcData *data, void *procWork)
{
    sub_020314DC(g_ProcSys, overlayId, data, procWork);
}


void *func_02031324(int heapId)
{
    return func_02031354(heapId);
}


unsigned int func_02031330(ProcSys *sys)
{
    return func_020313EC(sys);
}


/*
 * A four-instruction tail call to sub_020314B8, attested by the `matched`
 * class: sub_020314B8's own EXACT entry pins its address, and this call is
 * the only branch to it found in the ROM.
 */
void sub_0203133C(ProcSys *sys)
{
    sub_020314B8(sys);
}


void func_02031348(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork)
{
    func_020314F4(sys, overlayId, data, procWork);
}


/*
 * Allocates a 0x20-byte ProcSys and sets it empty: the first halfword is the
 * caller's heap id, +4 and +0x14 hold -1 (no overlay) and every other word
 * is 0.  The linker merges the two adjacent zero stores at +4/+8 into one
 * `stmib r0, {r1, r4}`.
 *
 * The first argument handed to func_02030734 is the caller's own parameter -
 * the original never writes r0 before the call, so r0 still holds heapId.
 * A literal first argument makes the compiler materialise it and shifts the
 * whole prologue.
 *
 * The pool word 0x020A783C is a `literal` site: it appears in ten other
 * pools in the image, e.g. 0x0203158C.
 */
ProcSys *func_02031354(int heapId)
{
    ProcSys *sys = func_02030734(heapId, 0x20, 0, (const char *)((int)ProcSys_AllocSiteName), 0xc5);

    sys->heapId = heapId;
    sys->unused04 = -1;
    sys->current = 0;
    sys->pushPending = 0;
    sys->replacePending = 0;
    sys->nextOverlayId = -1;
    sys->nextData = 0;
    sys->nextProcWork = 0;
    return sys;
}


/*
 * Pushes the queued process on top of the stack as a child of the current
 * one, then clears the queue.
 */
Proc *func_020313A0(ProcSys *sys)
{
    Proc *child = func_02031538(sys->nextOverlayId, sys->nextData, sys->nextProcWork, sys->heapId);

    child->prev = sys->current;
    sys->current->next = child;
    sys->current = child;
    sys->pushPending = 0;
    sys->nextOverlayId = 0xFFFFFFFF;
    sys->nextData = 0;
    sys->nextProcWork = 0;
    return child;
}




/*
 * procsys.c: advance the process chain one frame.  A pending push
 * (pushPending) is applied first (func_020313A0); then the current process
 * runs one step (func_020315F0) and, when it finishes, is freed and replaced
 * either by a freshly built process from the queued parameters
 * (replacePending set) or by its parent.  Returns 0 when the stack is empty,
 * 2 when a process just finished, 1 otherwise.
 *
 * The earlier 12-byte residue (docs/notes/pkt_020313EC.c.txt) was the
 * `parent = sys->current->prev;` load written once above the test: written
 * as the first statement of BOTH arms, the compiler hoists the common load
 * below the compare, which is the image's order (ldr replacePending, cmp,
 * ldr current, ldr prev, beq).
 */
u32 func_020313EC(ProcSys *sys)
{
    u32 status;
    Proc *parent;

    if (sys->current == 0) {
        return 0;
    }
    if (sys->pushPending != 0) {
        func_020313A0(sys);
    }
    status = func_020315F0(sys->current);
    if (status == 1) {
        if (sys->replacePending != 0) {
            parent = sys->current->prev;
            func_02031590(sys->current);
            sys->current = func_02031538(sys->nextOverlayId, sys->nextData, sys->nextProcWork, sys->heapId);
            if (parent != 0) {
                parent->next = sys->current;
            }
            sys->current->prev = parent;
            sys->replacePending = 0;
            sys->nextOverlayId = 0xFFFFFFFF;
            sys->nextData = 0;
            sys->nextProcWork = 0;
        } else {
            parent = sys->current->prev;
            func_02031590(sys->current);
            sys->current = parent;
            if (parent != 0) {
                parent->next = 0;
            }
        }
    }
    if (sys->current == 0) {
        return 0;
    }
    return (status == 1) ? 2 : 1;
}





/*
 * Frees the current process if present, then frees the ProcSys itself
 * (ENV_SetResourceSet is the heap free).  The same shutdown shape as
 * sub_02031140 and sub_020315D4 in the neighbouring packets.
 */
void sub_020314B8(ProcSys *sys)
{
    if (sys->current != 0) {
        func_020882D0(sys->current);
    }
    ENV_SetResourceSet(sys);
}





/*
 * Queues a replacement of the current process: marks it pending
 * (replacePending = 1) and stores the new overlay, data and argument.
 * No relocations.
 */
void sub_020314DC(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork)
{
    sys->replacePending = 1;
    sys->nextOverlayId = overlayId;
    sys->nextData = data;
    sys->nextProcWork = procWork;
}





/*
 * procsys.c: queue a call for the process at sys, or start it now.  When
 * a current process already exists the three parameters are parked in the
 * queue fields with pushPending set; otherwise the process is built with
 * the object's own u16 head as the heap id.
 *
 * The earlier DIFF (72 against 68, docs/notes/pkt_020314F4.c.txt) was the
 * polarity, not a predication threshold: written `== 0` with the call
 * first and the stores in the else arm, the compiler predicates the else
 * arm (movne, four strne, popne) and places it ahead of the call.
 */
void func_020314F4(ProcSys *sys, u32 overlayId, const ProcData *data, void *procWork)
{
    if (sys->current == 0) {
        sys->current = func_02031538(overlayId, data, procWork, sys->heapId);
    } else {
        sys->pushPending = 1;
        sys->nextOverlayId = overlayId;
        sys->nextData = data;
        sys->nextProcWork = procWork;
    }
}




/*
 * Build a 0x20-byte Proc from the allocator and fill it.  The allocator is
 * three-parameter with the size second (see func_0203159C), plus
 * __FILE__/__LINE__; 0x162 does not fit an ARM immediate so it costs its own
 * pool word loaded early into ip.
 */
Proc *func_02031538(u32 overlayId, const ProcData *data, void *procWork, u32 heapId)
{
    Proc *proc;

    proc = (Proc *)func_02030734(heapId, 0x20, 0,
                                 ProcNew_AllocSiteName, 0x162);
    proc->overlayId = overlayId;
    proc->data = data;
    proc->seq = 0;
    proc->subSeq = 0;
    proc->procWork = procWork;
    proc->work = 0;
    proc->prev = 0;
    proc->next = 0;
    return proc;
}




void func_02031590(Proc *proc)
{
    func_020307B0(proc);
}




/*
 * Allocate the process's work buffer.  The size never reaches a register of
 * its own: it arrives in r1 and is handed straight to the allocator's r1,
 * which is the arity tell, three parameters with the size second, not two
 * with a size read from the object.
 *
 * __LINE__ is 390 and does not fit an ARM immediate, so it costs its own
 * pool word next to the __FILE__ pointer.
 */
void *func_0203159C(Proc *proc, u32 size, u32 heapId)
{
    proc->work = func_02030734(heapId, size, 0, ProcAllocWork_AllocSiteName, 390);
    return proc->work;
}




/*
 * Frees the process's work buffer (ENV_SetResourceSet is the heap free) and
 * clears the field.
 */
void sub_020315D4(Proc *proc)
{
    ENV_SetResourceSet(proc->work);
    proc->work = 0;
}




/*
 * procsys.c: run one step of a process.  seq walks 0 (load the overlay
 * unless it is -1), 1 (init callback), 2 (main callback), 3 (end callback,
 * then unload the overlay and report finished).  Each callback returns 1
 * when its phase is done; the sub-sequence counter is passed by address and
 * cleared on every phase change.
 */
u32 func_020315F0(Proc *proc)
{
    switch (proc->seq) {
    case 0:
        if (proc->overlayId != 0xFFFFFFFF) {
            func_02034AC4(proc->overlayId);
        }
        proc->seq = 1;
    case 1:
        if (proc->data->init(proc, &proc->subSeq, proc->procWork, proc->work) == 1) {
            proc->seq = 2;
            proc->subSeq = 0;
        }
        break;
    case 2:
        if (proc->data->main(proc, &proc->subSeq, proc->procWork, proc->work) == 1) {
            proc->seq = 3;
            proc->subSeq = 0;
        }
        break;
    case 3:
        if (proc->data->end(proc, &proc->subSeq, proc->procWork, proc->work) == 1) {
            if (proc->overlayId != 0xFFFFFFFF) {
                func_02034A5C(proc->overlayId);
            }
            return 1;
        }
        break;
    }
    return 0;
}
