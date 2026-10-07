/*
 * file:     fldmmdl_p04.c
 * unit:     yes
 * function: func_0216C538, func_0216C640, func_0216C680, func_0216C6E8, func_0216C7FC, func_0216C860, func_0216C888, func_0216C8B0
 * address:  0x0216C538
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216C484  0x0216C484  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200B400  0x0200B400  thumb
 *   func_021CBD08  0x021CBD08  thumb  ov021
 *   func_0216CAD4  0x0216CAD4  thumb  ov010
 *   func_0216E8CC  0x0216E8CC  thumb  ov010
 *   func_02191388  0x02191388  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   sub_02045B38   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021B09D8  0x021B09D8  thumb
 *   func_021B09EC  0x021B09EC  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_02012EFC  0x02012EFC  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj12397.h"
#include "../../matched/include/Obj12055.h"

struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct Blk37;
struct S;
struct U16Vec;
struct Actor;
struct MsgBank;
struct Rec;
struct Ent;
struct Evt;
struct RecSlot;
struct S020314B8;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct SummaryArgs {
    void *party;        /* 0x08 */
    u32 f04;
    void *p;            /* 0x10 */
    u8 f0c;             /* 0x14 */
    u8 f0d;             /* 0x15 */
    u8 count;           /* 0x16 */
    u8 pad0f;
    u8 f10;             /* 0x18 */
    u8 pad11[7];
    void *f18;          /* 0x20 */
    u8 pad1c[0xC];
} SummaryArgs;

typedef struct PartyArgs {
    void *party;        /* 0x30 */
    u8 pad04[0x10];
    void *f14;          /* 0x44 */
    u8 pad18[0x1C];
    u32 f34;            /* 0x64 */
    u32 f38;            /* 0x68 */
    u8 pad3c[0x5C];
} PartyArgs;

typedef struct PartyTaskWork {
    void *sys;          /* 0x00 */
    void *q;            /* 0x04 */
    SummaryArgs sum;    /* 0x08 */
    PartyArgs pa;       /* 0x30 */
    void *outC8;        /* 0xC8 */
    void *outCC;        /* 0xCC */
    void *outD0;        /* 0xD0 */
    u8 padD4[4];
} PartyTaskWork;

typedef struct PartyCaller {
    u8 pad00[9];
    u8 kind;            /* 0x009 */
    u8 pad0A[0x72];
    u8 f7c[6];          /* 0x07C */
    u16 f82;            /* 0x082 */
    u16 f84;            /* 0x084 */
    u8 pad86[0x7C8 - 0x86];
    void *party;        /* 0x7C8 */
} PartyCaller;

typedef struct S { char p0[9]; unsigned char k; char p1[0x7CC - 10]; int f; } S;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32 pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_0216C484(int a, int *st, int *o);
extern void *func_02012934(const struct BigObj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_0201A354(int a, int b);
extern void *func_0200CA1C(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_0200B400(u32 heap);
extern u32 func_021CBD08(u8 *p, int a);
extern void func_0216CAD4(void *a0, void *a1, void *a2);
extern int func_0216E8CC(int, int, int);
extern u32 func_02191388(u32 *a);
extern void func_021914CC(struct S *s);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern int func_021912D8(u32 a);
extern int func_021912F8(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02188C54(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *p, u32 id);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void *func_02188C58(void *proc);
extern u32 func_0218EC2C(u8 *p);
extern void func_021B09D8(VecFx32 *pos, VecFx32 *ofs, u32 a, void *m, u8 dir);
extern void func_021B09EC(u8 dir, u32 *a, u32 *b);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void *func_02012EFC(void **p);
extern int func_0200DF40(struct RecSlot *p);
extern u8 func_0200DF4C(struct RecSlot *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
extern int func_0203159C();
extern void *func_02031324(int a0);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn);
void func_0216C640(S *a, int b, int c);
int func_0216C680(int a, int *st, int *o, u32 a3);
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir);
int func_0216C7FC(int a, int *st, int *o);
void *func_0216C860(void *a);
int func_0216C888(int a0, int a1, int a2);
int func_0216C8B0(void *a, int b, int c, void **d);
extern char d_021BA650[];
extern char id_00000045[];


/*
 * Starts the func_0216C484 task over a 0xD8-byte work: points it at the
 * caller's result fields, picks the party (the player's, or the one at
 * +0x7C8 when `useOwn` is set), and fills the party-screen and summary
 * argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * caller's kind at +9.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order q, task, p
 * for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 */
void *func_0216C538(PartyCaller *c, void *sys, u8 useOwn)
{
    void *q;
    void *task;
    void *p;
    PartyTaskWork *w;
    void *party;
    PartyArgs *pa;
    SummaryArgs *sum;
    void *h;
    u32 mode;
    u32 sel;

    p = func_020120F4(sys);
    q = func_0201210C(sys);
    task = func_020122C0(sys, 0, func_0216C484, sizeof(PartyTaskWork));
    w = func_020124E8(task);
    w->sys = sys;
    w->q = q;
    w->outD0 = c->f7c;
    w->outCC = &c->f82;
    w->outC8 = &c->f84;
    if (useOwn == 0)
        party = func_02012934(p);
    else
        party = c->party;
    mode = 0x14;
    sel = 0;
    pa = &w->pa;
    MI_CpuFill8(pa, 0, sizeof(PartyArgs));
    pa->party = party;
    switch (c->kind) {
    case 1:
    case 6:
        mode = 0x15;
        sel = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        mode = 0x16;
        sel = 2;
        break;
    }
    pa->f14 = func_0201A354(mode, 4);
    pa->f34 = 0x16;
    pa->f38 = sel;
    sum = &w->sum;
    h = func_0200CA1C(p);
    MI_CpuFill8(sum, 0, sizeof(SummaryArgs));
    sum->party = party;
    sum->f0c = 1;
    sum->count = func_0201AA18(party);
    sum->f0d = 0;
    sum->f10 = 0;
    sum->p = p;
    sum->f18 = (void *)func_0200CA38(h);
    return task;
}


/*
 * lever: The result of func_021CBD08 remains live in r2 and is the third argument of func_0216E8CC.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
void func_0216C640(S *a, int b, int c)
{
    int t;
    func_0200B400(4);
    t = func_021CBD08((u8 *)a, b);
    a->f = t;
    if (a->k == 3 || a->k == 8) {
        func_0216CAD4(a, (void *)b, (void *)c);
        return;
    }
    func_0216E8CC(b, c, t);
}


int func_0216C680(int a, int *st, int *o, u32 a3)
{
    switch (*st) {
    case 0:
        if (!func_02191388((u32 *)o[5]))
            break;
        (*st)++;
    case 1:
        func_021914CC((struct S *)o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(o[5]);
        (*st)++;
        break;
    case 2:
        if (func_021912F8(o[5], (u32)st, (u32)o, a3) == 1) {
            func_02045808((struct U16Vec *)o[6]);
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 */
void *func_0216C6E8(u8 *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32 ofs;
    u32 a;
    u32 b;
    void *task;
    void *ctx;
    void *x;
    void *proc;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    x = (void *)func_02188C54(proc);
    task = func_020122C0(sys, 0, func_0216C680, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (*(u16 *)((u32)d + 0xA0 + idx * 0x120) == 0xFFFF) {
        t->name = func_020457B0(0x300, 4);
        bank = sub_02045B38(0, 2, 0xB8, 4);
        n = *(u16 *)((u32)d + 0xA2 + idx * 0x120);
        if (n >= 0x3AE)
            n = 0;
        func_02045CAC(bank, n, t->name);
        func_02045C04(bank);
    } else {
        t->name = func_0202435C((u16 *)((u32)d + 0xA0 + idx * 0x120), 4);
    }
    func_0216D88C(func_0216DE94((void *)func_02012964(ctx), t->id), &t->pos);
    m = func_02188C58(proc);
    func_021B09D8(&t->pos, &ofs, func_0218EC2C(m), m, dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    func_021B09EC(dir, &a, &b);
    t->obj = func_0219129C(x, a, (u32)(&t->pos), (u32)t->name, 0, b);
    return task;
}


/*
 * blockers: func_02012EFC (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216C7FC(int a, int *st, int *o)
{
    int t;
    switch (*st) {
    case 0:
        o[2] = (int)func_020120F4((const struct Ctx *)o[1]);
        t = (int)func_02012EFC((void **)o[2]);
        o[3] = func_0200DF40((struct RecSlot *)t);
        o[4] = func_0200DF4C((struct RecSlot *)t);
        func_02012374((struct Evt *)a, func_020146F8((char *)o[1], o[0], (int)id_00000045, (int)d_021BA650, (int)(&o[2])));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

void *func_0216C860(void *a) {
    void *v; void *t; void **p;
    v=func_0201210C(a); t=func_020122C0(a,0,(void *)func_0216C7FC,0x14); p=func_020124E8(t);
    p[1]=a; ((struct Obj12397 *)p)->f0=v; return t;
}


int func_0216C888(int a0, int a1, int a2)
{
    int t4;

a2 = 1;
t4 = a0 + 0;
a0 = 1;
a1 = 0x76;
a2 = a2 << 0xe;
    func_0203064C(a0, a1, a2);
loc_0216C898:
a0 = t4 + 0;
a1 = 4;
a2 = 0x76;
    a0 = func_0203159C(a0, a1, a2);
loc_0216C8A2:
t4 = a0 + 0;
a0 = 0x76;
    a0 = (int)func_02031324(a0);
loc_0216C8AA:
((struct Obj12055 *)((char *)t4))->f0 = a0;
a0 = 1;
    return a0;}

/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int func_0216C8B0(void *a, int b, int c, void **d) {
    func_0203133C(*d); func_020315D4(a); func_020306F0(0x76); return 1;
}
