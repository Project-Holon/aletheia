/*
 * file:     symbol_map_p06.c
 * unit:     yes
 * function: func_02166CD0, func_02166D30, func_02166E50, func_02166F1C, func_02166F9C, func_02167044, func_02167080
 * address:  0x02166CD0
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
 *   func_0201296C  0x0201296C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009590  0x02009590  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02024044  0x02024044  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_02024108  0x02024108  thumb
 *   func_02012444  0x02012444  thumb
 *   func_0202411C  0x0202411C  thumb
 *   func_02024128  0x02024128  thumb
 *   func_02024124  0x02024124  thumb
 *   func_02024134  0x02024134  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_0200E714  0x0200E714  thumb
 *   func_020240FC  0x020240FC  thumb
 *   ov110_id       0x0000006E  data   a1
 *   d_021C39B8     0x021C39B8  data   ov110  a4
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0202C794  0x0202C794  thumb
 *   func_021A1BE4  0x021A1BE4  thumb  ov021
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   func_020129A0  0x020129A0  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   ov_id_D9  0x000000D9  data
 *   d_021C3FE0  0x021C3FE0  data  ov217
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02030734 0x02030734 arm
 *   d_02172A00 0x02172A00 data a1
 *   func_02167154  0x02167154  thumb  ov010
 *   func_02167178  0x02167178  thumb  ov010
 *   func_021671DC  0x021671DC  thumb  ov010
 *   func_021671FC  0x021671FC  thumb  ov010
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_021672B4  0x021672B4  thumb  ov010
 *   func_021671EC  0x021671EC  thumb  ov010
 *   func_021671CC  0x021671CC  thumb  ov010
 *   func_02167168  0x02167168  thumb  ov010
 */
struct Big;
struct BigObj;
struct Sub02009470Obj;
struct Ctx;
struct Desc;
struct Obj;
struct Rec0200E6FC;
struct Rec0200E714;
struct Evt;
struct IcaAnime;
struct MsgBank;
struct WordSet;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct ChoiceWork {
    u32 kind;           /* 0x00 */
    u16 *var0;          /* 0x04 */
    u16 *var1;          /* 0x08 */
    u16 *result;        /* 0x0C */
    void *win;          /* 0x10 */
    u32 msg;            /* 0x14 */
    u32 hasMsg;         /* 0x18 */
} ChoiceWork;

typedef struct Res4 {
    u16 a;
    u16 b;
} Res4;

typedef struct Res8 {
    u16 pad[2];
    u16 a;
    u16 b;
} Res8;

typedef struct Work {
    u32 kind;       /* 0x00 */
    u16 *out0;      /* 0x04 */
    u16 *out1;      /* 0x08 */
    u16 *done;      /* 0x0C */
    void *task;     /* 0x10 */
    u32 f14;        /* 0x14 */
    u32 f18;        /* 0x18 */
} Work;

struct O {
    u32 pad[5];
    int f14;
};

extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012F08(int *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 func_02009590(void *a, u32 b, u32 c);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_0216BF9C(void *a, int i, void *b);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_0215897C(void *vm, void *task);
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200E6F0(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void func_02024108(u16 *dst, const u16 *src);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern int func_0202411C(unsigned char *p);
extern void  func_02024128(void *t, Res4 *out);
extern unsigned int func_02024124(unsigned short *p);
extern void func_02024134(char *a, void *b);
extern void *func_020124E4(struct Obj *p);
extern void func_0200E714(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src);
extern void  func_020240FC(void *t);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C6C(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern u8 func_0202C794(void *a0, u32 a1);
extern void func_021A1BE4(int a, int b);
extern void func_021A1BDC(int a, int b);
extern void func_020129A0(struct BigObj *p, u8 v);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern struct MsgBank *func_02167154(int a0, int a1, int a2, int a3);
extern void func_02167178(struct O *o);
extern struct WordSet *func_021671DC(int a0);
extern void func_021671FC(struct O *o);
extern int func_0219077C(u8 *p);
extern u32 func_020362DC(void);
extern int func_021672B4(int a0);
extern int func_021671EC(int a0);
extern int func_021671CC(int a0);
extern int func_02167168(int a0);
int func_02166CD0(void *a, u32 msg);
int func_02166D30(void *c, void *vm);
u32 func_02166E50(void *obj, u32 *mode);
int func_02166F1C(void *a, void *b);
int func_02166F9C(void *a, int *st, int *p);
void *func_02167044(void *a, void *b);
int func_02167080(void *a, int *st, struct O *o, int a3);
extern char ov110_id[];
extern char d_021C39B8[];
extern char ov_id_D9[];
extern char d_021C3FE0[];
extern const char d_02172A00[];


int func_02166CD0(void *a, u32 msg)
{
    int r7 = func_0201296C(a);
    int r0 = (int)func_02012F08(a);
    int r6 = (int)func_02012944(a);
    u32 t;
    int res;
    t = (u32)func_02009470(func_02012EBC(a));
    switch (msg) {
    case 0xF000:
        return func_0216BF9C((void *)r0, 1, (void *)r6);
    case 0xF001:
        res = 0;
        if (func_02009590((void *)t, r6, 0) >= 1)
            res = 1;
        return res;
    }
    return func_020142E8((void *)r7, msg);
}


/*
 * Script command: reads a kind and three variable pointers, starts the
 * func_02166E50 task over a 0x1C-byte work, and for kinds 0..5 opens the
 * matching window (func_02024044), optionally filled with a message.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): byte-correct; the one
 * wildcard is the bl to arm9 0x02024108, a Thumb function (`ldrh r2, [r1]`
 * ...) with no witness outside this file (seed for the ARM9 session).
 */
int func_02166D30(void *c, void *vm)
{
    u8 buf[8];
    u16 *result;
    u16 *var1;
    u16 *var0;
    void *sys;
    void *heap;
    void *owner;
    ChoiceWork *w;
    void *task;
    u16 kind;
    u32 mode;

    sys = func_0215A5DC(vm);
    heap = func_0215A5E4(vm);
    owner = func_0215A5F4(vm);
    kind = func_02159B10(c, vm);
    var0 = func_02159AE8(c, vm);
    var1 = func_02159AE8(c, vm);
    result = func_02159AE8(c, vm);
    mode = 0;
    task = func_020122C0(sys, 0, func_02166E50, sizeof(ChoiceWork));
    w = func_020124E8(task);
    MI_CpuFill8(w, 0, sizeof(ChoiceWork));
    w->kind = kind;
    w->var0 = var0;
    w->var1 = var1;
    w->result = result;
    *result = 0;
    switch (kind) {
    case 0:
        w->msg = 1;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 1:
        w->msg = 2;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 2:
        w->msg = 3;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 3:
        w->msg = 4;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 4:
        w->hasMsg = 0;
        break;
    case 5:
        w->hasMsg = 0;
        mode = 1;
        break;
    default:
        w->win = 0;
        func_0215897C(owner, task);
        return 1;
    }
    w->win = func_02024044(mode, 0, 0, 0, func_02012EBC(heap), 1);
    if (w->hasMsg) {
        func_0200E6FC(func_0200E6F0((u32)func_02012EBC(func_020120F4(sys))), w->msg, (struct Rec0200E6FC *)buf);
        func_02024108(w->win, (const u16 *)buf);
    }
    func_0215897C(owner, task);
    return 1;
}


/*
 * Two-stage task: stage 0 starts an ov110 sub-task (pooled 0x6E is the
 * overlay id, 0x021C39B8 a table in its window) on the work at +0x10;
 * stage 1 reads back its result by the kind at +0x00 into the u16 outputs
 * at +0x04/+0x08 and flags +0x0C, then frees the work.
 *
 * Byte-correct (lane B5, run 1).  7 of 14 sites unresolved, no C change helps:
 *   - ov110_id 0x6E: overlay_id refuses, func_02012444 is not in
 *     OVERLAY_ID_CONSUMERS (it stores a1 in a descriptor for the state
 *     machine func_0201240C rather than passing it straight to a loader).
 *   - d_021C39B8: with the ov110 token the hint is "contested" and no
 *     overlay_id site loads ov110; without it, "no witness".  Resolves once
 *     ov110_id does.
 *   - arm9 unlabelled leaves 0x0202411C, 0x02024124, 0x02024128,
 *     0x02024134 (a .word run in asm/arm9/main.s after func_020240FC) and
 *     0x0200E714: no witness outside this range; each needs its own EXACT
 *     arm9 entry (matched class).
 * Same blocker family as ov010_func_02166908 / ov010_func_0216B004.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
u32 func_02166E50(void *obj, u32 *mode)
{
    Work *w = func_020124E8(obj);
    void *t = w->task;
    Res4 r4;
    Res8 r8;
    u16 v;
    u16 done;

    switch (*mode) {
    case 0:
        if (t == 0) {
            return 1;
        }
        func_02012444(obj, (u32)ov110_id, (u32)d_021C39B8, (u32)t);
        (*mode)++;
        break;
    case 1:
        if (func_0202411C(t) != 0) {
            done = 0;
        } else {
            if (w->kind == 5) {
                func_02024128(t, &r4);
                *w->out0 = r4.a;
                v = r4.b;
            } else if (w->kind == 4) {
                *w->out0 = func_02024124(t);
                v = 0;
            } else {
                func_02024134(t, &r8);
                if (w->f18 != 0) {
                    func_0200E714(func_0200E6F0((u32)func_02012EBC(func_020120F4(func_020124E4(obj)))), w->f14, (struct Rec0200E714 *)(&r8));
                }
                *w->out0 = r8.a;
                v = r8.b;
            }
            *w->out1 = v;
            done = 1;
        }
        *w->done = done;
        func_020240FC(w->task);
        return 1;
    }
    return 0;
}


int func_02166F1C(void *a, void *b)
{
    void *s4;
    void *s0;
    void *s8;
    int r7;
    int r4;
    int r5;
    func_0215A5F4(b);
    s4 = func_0215A5DC((void *)b);
    s0 = func_0215A5E4((void *)b);
    s8 = func_0201210C((void *)s4);
    r7 = func_02188C6C((u8 *)s8);
    r4 = func_02159B10(a, b);
    r5 = func_02159B10(a, b);
    if (r4 == 0xFFFF)
        r4 = func_0202C794(s4, func_02188C9C(s8));
    if (r5 != 0)
        func_021A1BE4(r7, r4);
    else
        func_021A1BDC(r7, r4);
    func_020129A0(s0, r4 & 0xff);
    return 0;
}


int func_02166F9C(void *a, int *st, int *p)
{
    int p0 = p[0];
    int p1 = p[1];
    switch (*st) {
    case 0:
        func_02012374(a, (struct Evt **)func_021BE8D4((void *)p0, p1, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC(p0, p1));
        *st = 2;
        break;
    case 2:
        func_020120B4((struct IcaAnime *)p0, (u32)ov_id_D9, d_021C3FE0, (void *)p[2]);
        *st = 3;
        break;
    case 3:
        func_02012374(a, (struct Evt **)((int)func_020145CC((void *)p0)));
        *st = 4;
        break;
    case 4:
        func_02012374(a, (struct Evt **)func_021BE92C((void *)p0, p1, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}

void *func_02167044(void *a, void *b) {
    void *task;
    void **w;
    void **q;
    task = func_020122C0(a, 0, func_02166F9C, 12);
    w = func_020124E8(task);
    w[0] = a;
    w[1] = b;
    q = func_02030734(4, 4, 0, d_02172A00, 117);
    w[2] = q;
    q[0] = a;
    return task;
}


int func_02167080(void *a, int *st, struct O *o, int a3)
{
    switch (*st) {
    case 0:
        func_02167154((int)o, (int)st, (int)o, a3);
        func_02167178(o);
        func_021671DC((int)o);
        func_021671FC(o);
        *st = *st + 1;
        break;
    case 1:
        if (func_0219077C((u8 *)o->f14) == 1)
            *st = *st + 1;
        break;
    case 2:
        if (func_020362DC() & 0xf3)
            *st = *st + 1;
        break;
    case 3:
        func_021672B4((int)o);
        func_021671EC((int)o);
        func_021671CC((int)o);
        func_02167168((int)o);
        return 1;
    }
    return 0;
}
