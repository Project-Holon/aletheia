/*
 * file:     event_field_proclink_p15.c
 * unit:     yes
 * function: func_021605C0, func_0216060C, func_02160668, func_021606D0, func_021606DC, func_0216070C, func_0216075C, func_021607E0
 * address:  0x021605C0
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
 *   func_02040588  0x02040588  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02190344  0x02190344  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012C0C  0x02012C0C  thumb
 *   func_021C4F7C  0x021C4F7C  thumb
 *   func_021C51A0  0x021C51A0  thumb  ov021
 *   func_02190398  0x02190398  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C468  0x0200C468  thumb
 *   func_021C5334  0x021C5334  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201897C  0x0201897C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02160A28  0x02160A28  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   d_021712CC     0x021712CC  data
 *   func_02160A64  0x02160A64  thumb  ov010
 *   func_02160A4C  0x02160A4C  thumb  ov010
 *   func_02160A7C  0x02160A7C  thumb  ov010
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00020.h"

struct Ctx;
struct BigObj;
struct Big;
struct Desc;
struct Hdr;
struct Obj;
struct Flags;
struct Info;
struct Rect;
struct IcaAnime;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work {
    void *f00;
    void *f04;
} Work;

typedef struct Owner_0216075C {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;            /* 0x0C */
    u8 pad10[4];
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Owner_0216075C;

typedef struct Task_0216075C {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner_0216075C *owner;       /* 0x18 */
    u8 pad1C[4];
    u8 rect[0x14];      /* 0x20 */
    u8 flags[0x18];     /* 0x34 */
    u8 info[0x14];      /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
    u8 pad6C[8];
} Task_0216075C;

typedef struct Owner_021607E0 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[8];
    void *f10;          /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
} Owner_021607E0;

typedef struct Callbacks {
    void *fn[3];
    u32 arg;
    void *ctx;
} Callbacks;

typedef struct Task_021607E0 {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 proc;           /* 0x04 */
    u32 prev;           /* 0x08 */
    u32 next;           /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner_021607E0 *owner;       /* 0x18 */
    void *work;         /* 0x1C */
    Callbacks cb;       /* 0x20 */
} Task_021607E0;

typedef struct Proc {
    void *f00;                                      /* 0x00 */
    void *f04;                                      /* 0x04 */
    void *(*init)(Task_021607E0 *t, void *arg, u32 prev, void *work); /* 0x08 */
    u32 (*finish)(Task_021607E0 *t, void *work);             /* 0x0C */
    void (*start)(Task_021607E0 *t, void *arg);              /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} Proc;

extern int func_02040588();
extern int func_02188C54();
extern int func_02190344();
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012C0C(struct BigObj *p);
extern char *func_021C4F7C(void *a0, int mode, const unsigned short *a2, unsigned short a3, unsigned short heap);
extern int func_021C51A0();
extern int func_02190398();
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C404(void *sys);
extern u16 func_0200C468(const u8 *a);
extern int func_021C5334(u32 a);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *pp, u32 id, u32 v);
extern u32 func_0201897C(struct Hdr *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02160A28(struct Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
extern void func_02164480(struct Flags *f, void *a, void *b);
extern void func_0215E840(void *field, struct Info *out);
extern int func_02160A64(Callbacks *c);
extern int func_02160A4C(Callbacks *c);
extern int func_02160A7C(Callbacks *c);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02188DA0(void);
extern void func_02188DB0(u8 *a);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern u32 func_020307B0(void *p);
void func_021605C0(int a0, int a1);
int func_0216060C(int a0, int a1);
int func_02160668(int *a0, int *a1);
void func_021606D0(int a, int b);
void *func_021606DC(void *p, u32 a);
int func_0216070C(Work *w);
void *func_0216075C(Owner_0216075C *o, u16 id);
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t);
extern Proc d_021712CC[];


void func_021605C0(int a0, int a1)
{
    int a2;
    int a3;
    unsigned char fr[4];
    int t4;
    int t5;
    void *t6;
    u8 *name;
    char *res;
    int o4;
t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t4)->fC;
    if (a0 != 0) goto loc_02160608;
loc_021605CE:
a0 = ((struct Obj00020 *)t4)->f18;
    if (a0 != 0) goto loc_02160608;
loc_021605D4:
a0 = 1;
a1 = 0;
    a0 = func_02040588(a0, a1);
loc_021605DC:
a0 = *(int *)&((struct Obj00020 *)t4)->f8;
    a0 = func_02188C54(a0);
loc_021605E2:
    if (a0 == 0) goto loc_021605EA;
loc_021605E6:
    a0 = func_02190344(a0);
loc_021605EA:
a0 = *(int *)&((struct Obj00020 *)t4)->f4;
    t6 = func_020120F4((const struct Ctx *)a0);
loc_021605F0:
    name = func_02012C0C((struct BigObj *)t6);
loc_021605F6:
a0 = 0x15;
    o4 = a0;
a1 = t5 + 0;
a3 = 0x50;
    res = func_021C4F7C(t6, a1, (const unsigned short *)name, a3, o4);
loc_02160606:
*(char * *)&((struct Obj00020 *)t4)->fC = res;
loc_02160608:
    return;
}


/*
 * unblocked: func_021C51A0 is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 92 bytes against 90 compiled: the unlabelled follower.
 */
int func_0216060C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
    if (a0 != 0) goto loc_02160662;
loc_02160616:
a0 = *(int *)&((struct Obj00020 *)t5)->f1C;
    if (a0 == 0) goto loc_02160626;
loc_0216061C:
    if (a0 == 1) goto loc_0216064A;
loc_02160620:
    if (a0 == 2) goto loc_02160656;
loc_02160624:
    goto loc_0216065E;
loc_02160626:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    if (a0 == 0) goto loc_02160644;
loc_0216062C:
a0 = 1;
a1 = 0;
t4 = 1;
t6 = 0;
    a0 = func_02040588(a0, a1);
loc_02160638:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    a0 = func_021C51A0(a0);
loc_0216063E:
*(int *)&((struct Obj00020 *)t5)->fC = t6;
*(int *)&((struct Obj00020 *)t5)->f1C = t4;
    goto loc_0216065E;
loc_02160644:
a0 = 2;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
    goto loc_0216065E;
loc_0216064A:
a0 = *(int *)&((struct Obj00020 *)t5)->f8;
    a0 = func_02188C54(a0);
loc_02160650:
    a0 = func_02190398(a0);
loc_02160654:
    goto loc_02160644;
loc_02160656:
a0 = 0;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
a0 = 1;
    return a0;
loc_0216065E:
a0 = 0;
    return a0;
loc_02160662:
a0 = 1;
    return a0;}


int func_02160668(int *a0, int *a1)
{
    void *x;

    x = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx *)a1[1])));
    switch (a1[7]) {
    case 0:
        if (func_0200C468(x) == 0) {
            a1[6] = 1;
            a1[7] = 2;
        } else if ((u32)(a0[9] - 1) <= 2) {
            a1[7] = 2;
        } else {
            func_021605C0(1, (int)a1);
            a1[7] = 1;
        }
        break;
    case 1:
        if (func_021C5334(a1[3]) != 0) {
            a1[7] = 2;
        }
        break;
    case 2:
        a1[7] = 0;
        return 1;
    }
    return 0;
}


/*
 * Unlabelled thunk: tail-calls func_0216060C with its second argument.
 */
void func_021606D0(int a, int b)
{
    func_0216060C(b, b);
}


void *func_021606DC(void *p, u32 a)
{
    void *h;

    h = func_02158768((int)p, 0x7D6, 0, 0x15);
    func_02159058(func_021589D0((int)h), a, 0, 0, 0);
    return h;
}


/*
 * TRUE when some party member has field 0xA9 set and passes func_0201897C.
 */
int func_0216070C(Work *w)
{
    void *party;
    void *pp;
    int i;

    party = func_02012934(func_020120F4(w->f04));
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        pp = func_0201AB28(party, i);
        if (func_02017E1C(pp, 0xA9, 0) != 0 && func_0201897C(pp) != 0)
            return 1;
    }
    return 0;
}


/*
 * Creates the 0x74-byte task that runs func_021607E0 and initialises it
 * from the owner.
 */
void *func_0216075C(Owner_0216075C *o, u16 id)
{
    void *h;
    Task_0216075C *t;

    h = func_020122C0(o->f00, o->f08, func_021607E0, sizeof(Task_0216075C));
    t = func_020124E8(h);
    MI_CpuFill8(t, 0, sizeof(Task_0216075C));
    t->id = id;
    t->owner = o;
    t->state = 4;
    t->handle = h;
    t->f04 = o->f0c;
    t->f08 = o->f0c;
    t->f0c = o->f0c;
    t->f60 = 0;
    t->f62 = 0;
    t->f68 = 0;
    func_02160A28((struct Rect *)t->rect, (u32)t->owner, t->owner->f14, t->owner->f18, t->owner->f1c, t->owner->f20);
    func_02164480((struct Flags *)t->flags, t->owner->f00, t->owner->f04);
    func_0215E840(t->owner->f04, (struct Info *)t->info);
    return h;
}


/*
 * The fourteen-state task func_0216075C creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 */
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t)
{
    u32 v;
    void *work;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        v = t->state;
        if (v <= 1) {
            *state = 2;
        } else if (v == 4) {
            if (d_021712CC[t->proc].start == 0)
                *state = 6;
            else
                *state = 3;
        } else if (v == 3) {
            t->owner->result = 3;
            *state = 2;
        } else if (v == 2) {
            t->owner->result = 2;
            *state = 2;
        }
        break;
    case 2:
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        return 1;
    case 3:
        if (func_02160A64(&t->cb) == 0)
            break;
        d_021712CC[t->proc].start(t, t->owner->f10);
        *state = 4;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (t->state == 0) {
            if (func_02160A4C(&t->cb) == 0)
                break;
            *state = 1;
        } else {
            *state = 1;
        }
        break;
    case 6:
        func_02012374(evt, (struct Evt **)func_021BE8D4(t->owner->f00, (int)t->owner->f04, 0, 0));
        *state = 7;
        break;
    case 7:
        if (func_02160A64(&t->cb) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_020144DC((int)t->owner->f00, (int)t->owner->f04));
        *state = 11;
        break;
    case 8:
        func_02160A7C(&t->cb);
        func_02012374(evt, func_020145CC(t->owner->f00));
        *state = 9;
        break;
    case 9:
        work = func_0201210C(t->owner->f00);
        t->owner->f04 = work;
        func_02188DA0();
        func_02188DB0(t->owner->f04);
        *state = 10;
        break;
    case 10:
        if (func_02160A4C(&t->cb) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_021BE92C(t->owner->f00, (int)t->owner->f04, 0, 0, 0, 0, 0));
        *state = 1;
        break;
    case 11:
        work = d_021712CC[t->proc].init(t, t->owner->f10, t->prev, t->work);
        if (t->work != 0) {
            d_021712CC[t->prev].exit(t->work);
            t->work = 0;
        }
        t->work = work;
        if (d_021712CC[t->proc].f04 == 0)
            break;
        func_020120B4(t->owner->f00, (u32)d_021712CC[t->proc].f00, d_021712CC[t->proc].f04, work);
        *state = 12;
        break;
    case 12:
        if (func_020120F0(t->owner->f00) != 0)
            break;
        *state = 13;
        break;
    case 13:
        t->state = d_021712CC[t->proc].finish(t, t->work);
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        else if (v == 3)
            t->owner->result = 3;
        else if (v == 2)
            t->owner->result = 2;
        if (t->state == 4) {
            t->prev = t->proc;
            t->proc = t->next;
            *state = 11;
        } else {
            if (t->work != 0) {
                func_020307B0(t->work);
                t->work = 0;
            }
            *state = 8;
        }
        break;
    }
    return 0;
}
