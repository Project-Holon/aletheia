/*
 * docs/families/procsys.h -- shared declarations for the procsys.c family
 * (0x02031354..0x020316C8 in the ARM9 image, ARM code, dsi/1.1p1 -O4,p).
 * Anchor: __FILE__ at 0x020A783C, passed by func_02031538 and func_0203159C.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Every field below
 * is evidenced by an EXACT file in src/matched, named beside it.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

/* A process: callbacks, overlay, state machine (func_020315F0). */
typedef u32 (*ProcFunc)(void *proc, u32 *subseq, u32 pwork, u32 work);

typedef struct {
    ProcFunc init;      /* +0x0  state 1 */
    ProcFunc main;      /* +0x4  state 2 */
    ProcFunc end;       /* +0x8  state 3 */
} ProcData;

typedef struct Proc Proc;
struct Proc {           /* 0x20 bytes, built by func_02031538 */
    const ProcData *data;  /* +0x00 (func_02031538 stores a1 here) */
    u32 ovl;            /* +0x04 overlay id, 0xFFFFFFFF = none */
    u32 seq;            /* +0x08 0 load, 1 init, 2 main, 3 end */
    u32 subseq;         /* +0x0C passed by address to each callback */
    u32 pwork;          /* +0x10 */
    u32 work;           /* +0x14 (func_0203159C allocates it) */
    Proc *parent;       /* +0x18 (func_020313EC: prev) */
    Proc *child;        /* +0x1C */
};

/* The process system object (func_020313A0, func_020313EC, func_020314F4). */
typedef struct {
    u16 heap;           /* +0x00 heap id for func_02031538 */
    u16 pad02;
    u32 f04;
    Proc *proc;         /* +0x08 current process */
    u32 call_pending;   /* +0x0C a sub-process call is queued */
    u32 next_pending;   /* +0x10 a replacement process is queued */
    u32 next_data;      /* +0x14 parked arguments, reset to 0xFFFFFFFF */
    u32 next_ovl;       /* +0x18 */
    u32 next_pwork;     /* +0x1C */
} ProcSys;

Proc *func_02031538(u32 data, u32 ovl, u32 pwork, u32 heap);   /* build */
void  func_02031590(Proc *p);                                  /* free */
void  func_0203159C(Proc *p, u32 size, u32 heap);              /* work alloc */
u32   func_020315F0(Proc *p);           /* one step; 1 when finished */
u32   func_020313EC(ProcSys *s);        /* 0 none left, 1 running, 2 switched */
void  func_020314F4(ProcSys *s, u32 a1, u32 a2, u32 a3);       /* call or start */

/* Overlay load/unload used by func_020315F0 (gf_overlay.c, ARM). */
void func_02034AC4(u32 ovl);
void func_02034A5C(u32 ovl);

/*
 * Levers that closed this family (wave 15):
 *  - func_020314F4: `if (x == 0) { call } else { stores }` predicates the
 *    else arm and places it first; `!= 0` with the stores first does not.
 *  - func_020313EC: a load common to both arms, written as the first
 *    statement of each arm, is hoisted below the compare.
 */
