/*
 * file:     symbol_map_p02.c
 * unit:     yes
 * function: func_02166B0C, func_02166B2C, func_02166B58, func_02166C4C, func_02166C7C, func_02166CD0, func_02166D30, func_02166E50, func_02166F1C, func_02166F9C, func_02167044, func_02167080, func_021670F8, func_0216711C, func_02167154, func_02167168, func_02167178, func_021671CC, func_021671DC, func_021671EC, func_021671FC, func_021672B4, func_021672D0, func_021672E4, func_021672F8, func_0216730C
 * address:  0x02166B0C
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
 *   func_02005654  0x02005654  thumb
 *   func_02166A6C  0x02166A6C  thumb  ov010
 *   d_02172BA4     0x02172BA4  data  ov010  a4
 *   func_0207AD40 0x0207AD40 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216559C  0x0216559C  thumb  ov010
 *   ov215_id       0x000000D7  data   a1
 *   d_021F7118     0x021F7118  data   ov215  a4
 *   func_02013E40  0x02013E40  thumb
 *   func_02012894  0x02012894  thumb
 *   d_02171F2C  0x02171F2C  data  ov010  a4
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
 *   ov_id_D9  0x000000D9  data
 *   d_021C3FE0  0x021C3FE0  data  ov217
 *   func_020307B0  0x020307B0  arm
 *   func_02030734 0x02030734 arm
 *   d_02172A00 0x02172A00 data a1
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C54 0x02188C54 thumb ov021
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190728  0x02190728  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F31C  0x0201F31C  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_02190788  0x02190788  thumb
 *   func_02012EC0  0x02012EC0  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 */
#include "../../matched/include/Obj05899.h"
#include "../../matched/include/Obj00565.h"
#include "../../matched/include/Obj17729.h"
#include "../../matched/include/Obj17730.h"
#include "../../matched/include/Obj17731.h"

struct IcaAnime;
struct Evt;
struct Ctx;
struct Desc;
struct Obj;
struct Big;
struct BigObj;
struct Sub02009470Obj;
struct Rec0200E6FC;
struct Rec0200E714;
struct MsgBank;
struct WordSet;
struct O_02166B0C;
struct Fx;
struct Descriptor;
struct U16Vec;
struct Blk34;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct E {
    u32 val;
    u32 key;
};

struct P {
    u16 pad[2];
    u16 f4;
};

typedef signed int     s32;

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

struct O_02166B0C {
    u16 pad0[8];
    int f10;
    int f14;
    int f18;
};

struct O_021671FC {
    u16 id;
    u16 pad2[3];
    int f8;
    int pad0c[2];
    int f14;
    int f18;
    int f1c;
};

extern int func_02005654(int a, int b);
extern void func_02166A6C(void);
extern void func_0207AD40(void *);
extern void func_0207D59C(void *, void *, int, int, int, int);
extern void func_0200566C(void);
extern u32   func_02017E1C(void *obj, u32 key, u32 off);
extern int func_020144DC(int a0, int a1);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *func_020145CC(void *a0);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void  func_0216559C(u16 x);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02013E40(u32 a);
extern struct P *func_02012894(void *a);
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
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_0215897C(void *vm, void *task);
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
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
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_0219077C(u8 *p);
extern u32 func_020362DC(void);
extern void func_02082BCC(void *, int, int);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02045C04();
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int func_02190728();
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_0201ED04();
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F31C(struct WordSet *p);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021907C0(u8 *p);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_02190788();
extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern u8 func_0200C224(struct Blk34 *p);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u32 func_0200C1C4(struct Blk34 *p);
void func_02166B0C(void);
void func_02166B2C(void);
u32 func_02166B58(void *obj, u32 *mode, u32 *args);
void *func_02166C4C(void *a, void *b, void *c);
u32 func_02166C7C(void *a, u32 b);
int func_02166CD0(void *a, u32 msg);
int func_02166D30(void *c, void *vm);
u32 func_02166E50(void *obj, u32 *mode);
int func_02166F1C(void *a, void *b);
int func_02166F9C(void *a, int *st, int *p);
void *func_02167044(void *a, void *b);
int func_02167080(void *a, int *st, struct O_02166B0C *o, int a3);
void *func_021670F8(void *p);
void func_0216711C(u8 *p, void *sys);
struct MsgBank *func_02167154(int a0, int a1, int a2, int a3);
int func_02167168(int a0);
void func_02167178(struct O_02166B0C *o);
int func_021671CC(int a0);
struct WordSet *func_021671DC(int a0);
int func_021671EC(int a0);
void func_021671FC(struct O_021671FC *o);
void func_021672B4(int a0);
int func_021672D0(int a0);
int func_021672E4(int a0);
int func_021672F8(int a0);
int func_0216730C(unsigned int n);
extern u32 d_02172BA4[2];
extern char ov215_id[];
extern char d_021F7118[];
extern struct E d_02171F2C[2];
extern char ov110_id[];
extern char d_021C39B8[];
extern char ov_id_D9[];
extern char d_021C3FE0[];
extern const char d_02172A00[];







/*
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum, then
 * tail-calls func_02005654(func_02166A6C, 0).
 */
void func_02166B0C(void)
{
    d_02172BA4[0] = 0x3F800000;
    d_02172BA4[1] = 0;
    func_02005654((int)func_02166A6C, 0);
}






void func_02166B2C(void) {
    int m[4];
    func_0207AD40(m);
    func_0207D59C((void *)0x04000020, m, 128, 92, 0, 0);
    func_0200566C();
}







/*
 * Stage machine on *mode, same family as ov002 func_021542C0.  The second
 * argument to func_020120B4 is pooled 0xD7 (215), a linker overlay id for
 * ov215; the third, 0x021F7118, lies in its window.
 */
u32 func_02166B58(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];
    u32 a1 = args[1];
    u32 a2 = args[2];

    switch (*mode) {
    case 0:
        if (func_02017E1C((void *)args[3], 0x4C, 0) == 0 || func_02017E1C((void *)args[3], 3, 0) == 1) {
            *mode = 7;
        } else {
            *mode = 1;
        }
        break;
    case 1:
        args[4] = a1;
        args[5] = args[3];
        *mode = 2;
        break;
    case 2:
        func_02012374(obj, (struct Evt **)func_021BE8D4((void *)a0, a2, 0, 0));
        *mode = 3;
        break;
    case 3:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, a2));
        *mode = 4;
        break;
    case 4:
        func_020120B4((struct IcaAnime *)a0, (u32)ov215_id, d_021F7118, &args[4]);
        *mode = 5;
        break;
    case 5:
        func_02012374(obj, func_020145CC((void *)a0));
        *mode = 6;
        break;
    case 6:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)a0, a2, 0, 0, 1, 0, 0));
        func_0216559C(func_02017E1C((void *)args[3], 5, 0));
        *mode = 7;
        break;
    case 7:
        return 1;
    }
    return 0;
}






void *func_02166C4C(void *a, void *b, void *c) {
    void *task;
    void **w;
    task = func_020122C0(a, 0, func_02166B58, 24);
    w = func_020124E8(task);
    w[0] = a;
    w[2] = b;
    w[1] = func_020120F4(a);
    w[3] = c;
    return task;
}







u32 func_02166C7C(void *a, u32 b)
{
    u32 v = func_02013E40(b);
    u32 r;
    int i;
    if (v == 0x1A6)
        return func_02013E40(func_02012894(a)->f4);
    for (i = 0; i < 2; i++) {
        if (d_02171F2C[i].key == v) {
            r = (u16)*(u32 *)((char *)d_02171F2C + i * 8);
            goto done;
        }
    }
    r = 0xFFFF;
done:
    if (r != 0xFFFF)
        v = (u16)r;
    return v;
}






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






int func_02167080(void *a, int *st, struct O_02166B0C *o, int a3)
{
    switch (*st) {
    case 0:
        func_02167154((int)o, (int)st, (int)o, a3);
        func_02167178(o);
        func_021671DC((int)o);
        func_021671FC((struct O_021671FC *)o);
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




void *func_021670F8(void *p) {
    void *task;
    task = func_020122C0(p, 0, func_02167080, 32);
    func_0216711C(func_020124E8(task), p);
    return task;
}




/*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 */
void func_0216711C(u8 *p, void *sys) {
    void *field;
    field = func_0201210C(sys);
    func_02082BCC(p, 0, 32);
    ((struct Obj05899 *)p)->f0 = func_02188C84(field);
    ((struct Obj05899 *)p)->f4 = sys;
    ((struct Obj05899 *)p)->f8 = func_020120F4(sys);
    ((struct Obj05899 *)p)->fC = field;
    ((struct Obj05899 *)p)->f10 = func_02188C54(field);
}





struct MsgBank *func_02167154(int a0, int a1, int a2, int a3)
{
    int t4;
    struct MsgBank *bank;

t4 = a0 + 0;
a3 = ((struct Obj00565 *)((char *)t4))->f0;
a0 = 0;
a1 = 3;
a2 = 0x2f;
    bank = func_02045B38(a0, a1, a2, a3);
loc_02167164:
*(struct MsgBank * *)&((struct Obj00565 *)t4)->f18 = bank;
    return bank;}





int func_02167168(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00565 *)t4)->f18;
    a0 = func_02045C04(a0);
loc_02167172:
a0 = 0;
*(int *)&((struct Obj00565 *)t4)->f18 = a0;
    return a0;}





void func_02167178(struct O_02166B0C *o)
{
    int a;
    int b;
    int c;
    switch (func_021672D0((int)o)) {
    case 0:
        a = 1;
        b = 0x1e;
        c = 4;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        a = 1;
        b = 0x1e;
        c = 8;
        break;
    }
    o->f14 = (int)func_02190708((struct Fx *)o->f10, o->f18, a, a, b, c);
}





int func_021671CC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)t4)->f14;
    a0 = func_02190728(a0);
loc_021671D6:
a0 = 0;
((struct Obj00565 *)t4)->f14 = a0;
    return a0;}





struct WordSet *func_021671DC(int a0)
{
    int t4;
    struct WordSet *ws;

t4 = a0 + 0;
a0 = ((struct Obj00565 *)((char *)t4))->f0;
    ws = func_0201EC64(a0);
loc_021671E6:
*(struct WordSet * *)&((struct Obj00565 *)t4)->f1C = ws;
    return ws;}



int func_021671EC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00565 *)t4)->f1C;
    a0 = func_0201ED04(a0);
loc_021671F6:
a0 = 0;
*(int *)&((struct Obj00565 *)t4)->f1C = a0;
    return a0;}



void func_021671FC(struct O_021671FC *o)
{
    void *r4;
    void *r6;
    int r7;
    int s8;
    int sc;
    r4 = func_020457B0(0x100, o->id);
    r6 = func_020457B0(0x100, o->id);
    r7 = func_021672D0((int)o);
    s8 = func_021672E4((int)o);
    sc = func_021672F8((int)o);
    r7 = func_0216730C(r7);
    func_0201F02C((struct WordSet *)o->f1c, 0, func_02012944((void *)o->f8));
    func_0201EFA4((struct WordSet *)o->f1c, 1, s8, 5, 1, 1);
    func_0201EFA4((struct WordSet *)o->f1c, 2, sc, 5, 1, 1);
    func_02045CAC((struct MsgBank *)o->f18, r7, r4);
    func_0201F250((struct WordSet *)o->f1c, r6, r4);
    func_0201F31C((struct WordSet *)o->f1c);
    func_02190758(o->f14, 8, 0, (u32)r6);
    func_020409B4(func_02045730((void *)func_021907C0((u8 *)o->f14)));
    func_02045808(r4);
    func_02045808(r6);
}




void func_021672B4(int a0)
{
    int t4;

    t4 = a0;
    func_02190788(((struct Obj00565 *)t4)->f14);
    func_020409B4(func_02045730((struct Descriptor *)func_021907C0((u8 *)((struct Obj00565 *)t4)->f14)));
}





int func_021672D0(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17729 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_021672D8:
    sys = func_0200C0E8(big);
loc_021672DC:
    a0 = func_0200C224(sys);
loc_021672E0:
    return a0;}





int func_021672E4(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17730 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_021672EC:
    sys = func_0200C0E8(big);
loc_021672F0:
    a0 = func_0200C1DC(sys);
loc_021672F4:
    return a0;}





int func_021672F8(int a0)
{
    void *big;
    void *sys;


a0 = ((struct Obj17731 *)a0)->f8;
    big = func_02012EC0((struct Big *)a0);
loc_02167300:
    sys = func_0200C0E8(big);
loc_02167304:
    a0 = func_0200C1C4(sys);
loc_02167308:
    return a0;}




int func_0216730C(unsigned int n)
{
    switch (n) {
    case 0:
        return 0x174;
    case 1:
        return 0x175;
    case 2:
        return 0x176;
    case 3:
        return 0x177;
    case 4:
        return 0x178;
    case 5:
        return 0x179;
    }
    return 0;
}
