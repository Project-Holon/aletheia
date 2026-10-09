/*
 * file:     scrcmd_proc_p04.c
 * unit:     yes
 * function: func_0215C610, func_0215C63C, func_0215C69C, func_0215C6F0, func_0215C700, func_0215C72C, func_0215C7C4
 * address:  0x0215C610
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020113D0  0x020113D0  thumb
 *   d_021728F0     0x021728F0  data  a1
 *   func_02158FB8  0x02158FB8  thumb  ov010
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02158FBC  0x02158FBC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0202E474  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   d_021BB96C     0x021BB96C  data  ov070 a4
 */
#include "../../matched/include/Obj00005.h"

struct Ctx;
struct IcaAnime;
struct Pair;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct ProcHandoff {
    void *work;         /* 0x00 */
    u32 arg1;           /* 0x04 */
    u32 arg0;           /* 0x08 */
} ProcHandoff;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Outputs { u16 *first; u16 *second; } Outputs;

typedef struct Context { char pad[0x34]; u32 first; u32 second; } Context;

typedef struct Pair { Context *context; Outputs *outputs; } Pair;

typedef struct Rec {
    u32 *src;
    u16 *dst;
} Rec;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern int func_020144DC(int a0, int a1);
extern int func_0215897C();
extern void *func_02158FB4(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_020113D0(char *p, int val);
extern u32 func_02158FB8(void *p);
extern u32 func_020120F0(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern int func_02158FBC();
extern u32 func_02159B10(void *c, void *vm);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *vm);
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
int func_0215C610(int a0, int a1);
/* * Starts a child process from an overlay on behalf of a script command: * allocates the 12-byte hand-off record (work pointer and two words), * launches the process over the work with func_020120B4, parks the record in the * script's slot and waits on func_0215C69C. */ void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
int func_0215C69C(int a0, int a1);
int func_0215C6F0(int a0, int a1);
/* * lever: Stores in both if/else arms retain the zero-first full branch; * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33. */ void func_0215C700(Pair *p);
/* * Script command: reads a selector and two words, maps the selector * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built * from func_0202E474 with an 8-byte hand-off record. * * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line * (the proc table lives in ov070, the overlay this function opens) gave the * witness; ov070_id then resolved through the overlay_id walk (func_0215C63C * is a registered consumer). Source unchanged. */ int func_0215C72C(void *c, void *vm);
void func_0215C7C4(Rec *r);
extern const char d_021728F0[];
extern const u8 d_021BB96C[];
extern u8 ov070_id[];




int func_0215C610(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C61A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215C622:
    v2 = func_0201210C(v1);
loc_0215C628:
    a0 = func_020144DC((int)v1, (int)v2);
loc_0215C630:
a1 = a0 + 0;
    a0 = func_0215897C(v0, a1);
loc_0215C638:
a0 = 1;
    return a0;}





/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with func_020120B4, parks the record in the
 * script's slot and waits on func_0215C69C.
 */
void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1)
{
    void *sys;
    void **slot;
    ProcHandoff *h;

    sys = func_0215A5DC(vm);
    slot = func_02158FB4(func_0215A5F4(vm));
    h = func_02030734(4, sizeof(ProcHandoff), 1, d_021728F0, 0x8B);
    h->work = work;
    h->arg1 = arg1;
    h->arg0 = arg0;
    func_020120B4(sys, ovId, (void *)proc, work);
    *slot = h;
    func_020113D0(c, (int)func_0215C69C);
}





int func_0215C69C(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;

t4 = a1 + 0;
a0 = t4 + 0;
    t6 = func_0215A5DC((void *)a0);
loc_0215C6A6:
a0 = t4 + 0;
    a0 = (int)func_0215A5F4((void *)a0); /* int-typed on purpose: pointer local changes codegen */
loc_0215C6AE:
t4 = a0 + 0;
    a0 = func_02158FB8((void *)a0);
loc_0215C6B4:
t5 = a0 + 0;
    a0 = func_020120F0(t6);
loc_0215C6BC:
    if (a0 == 0) goto loc_0215C6C4;
loc_0215C6C0:
a0 = 0;
    return a0;
loc_0215C6C4:
a1 = *(int *)&((struct Obj00005 *)t5)->f8;
    if (a1 == 0) goto loc_0215C6D0;
loc_0215C6CA:
a0 = t5 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215C6CE:
    goto loc_0215C6E4;
loc_0215C6D0:
a0 = *(int *)&((struct Obj00005 *)((char *)t5))->f0;
    if (a0 == 0) goto loc_0215C6DA;
loc_0215C6D6:
    func_020307B0((void *)a0);
loc_0215C6DA:
a0 = *(int *)&((struct Obj00005 *)t5)->f4;
    if (a0 == 0) goto loc_0215C6E4;
loc_0215C6E0:
    func_020307B0((void *)a0);
loc_0215C6E4:
a0 = t4 + 0;
    a0 = func_02158FBC(a0);
loc_0215C6EA:
a0 = 1;
    return a0;}





int func_0215C6F0(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215C6F8:
    a0 = func_02158FBC(v0);
loc_0215C6FC:
a0 = 1;
    return a0;}



/*
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 */
void func_0215C700(Pair *p)
{
    Context *c = p->context;
    Outputs *o = p->outputs;
    if (c->first == 0)
        *o->first = B_FALSE;
    else
        *o->first = B_TRUE;
    *o->second = c->second;
    func_020307B0(p->outputs);
    func_020307B0(p->context);
}




/*
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from func_0202E474 with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (func_0215C63C
 * is a registered consumer). Source unchanged.
 */
int func_0215C72C(void *c, void *vm)
{
    u32 sel;
    u32 a;
    u32 b;
    u32 k;
    void *work;
    u32 *h;

    func_0215A5DC(vm);
    func_0215A5F4(vm);
    sel = func_02159B10(c, vm);
    a = (u32)func_02159AE8(c, vm);
    b = (u32)func_02159AE8(c, vm);
    if (sel == 0)
        k = 4;
    else if (sel == 1)
        k = 5;
    else
        k = 0;
    work = func_0202E474((const struct BigObj *)func_0215A5E4(vm), 0, k, 4);
    h = func_02030734(4, 8, 1, d_021728F0, 0x118);
    h[0] = a;
    h[1] = b;
    func_0215C63C(c, vm, (u32)ov070_id, d_021BB96C, work, (u32)func_0215C700, (u32)h);
    return 1;
}


/*
 * Unlabelled Thumb leaf (callback of func_0215C7E0): stores whether the
 * first record's word at +4 equals 1 into the halfword the second record
 * points to, then frees the first record's first word.
 */
void func_0215C7C4(Rec *r)
{
    if (r->src[1] == 1)
        *r->dst = 1;
    else
        *r->dst = 0;
    func_020307B0(r->src);
}
