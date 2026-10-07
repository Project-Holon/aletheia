/*
 * file:     trcard_sys_p02.c
 * unit:     yes
 * function: func_0216E5B0, func_0216E5FC, func_0216E618, func_0216E62C, func_0216E680, func_0216E68C, func_0216E7C8, func_0216E818, func_0216E8CC
 * address:  0x0216E5B0
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
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_0201313C  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF5D8  0x021CF5D8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_0202E79C  0x0202E79C  thumb
 *   func_02012A44  0x02012A44  thumb
 *   func_0216EFA8  0x0216EFA8  thumb  ov010
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0202E818  0x0202E818  thumb
 *   func_02181D8C  0x02181D8C  thumb
 *   func_0216EB98  0x0216EB98  thumb  ov010
 *   func_0216EE40  0x0216EE40  thumb  ov010
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAABC  0x021AAABC  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA5CC  0x021AA5CC  thumb  ov021
 *   func_0216EE20  0x0216EE20  thumb  ov010
 *   func_02013144  0x02013144  thumb
 *   func_021CF748  0x021CF748  thumb  ov021
 */
struct Blk37;
struct BigObj;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
struct Work;
struct Sub02008C20Obj;
typedef short s16;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
    int z;
} Pos;

typedef struct {
    u8 pad00[0x18];
    int f18;
    Pos pos;
} Obj;

typedef struct Battle {
    u32 f00;
    u32 f04;            /* 0x04 */
} Battle;

typedef struct Holder {
    u8 pad00[0x18];
    u8 f18[4];          /* 0x18 */
} Holder;

typedef struct Task {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Task;

typedef struct Work {
    void *sys;          /* 0x00 */
    Battle *bs;         /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
} Work;

typedef u32 (*TaskFn)(void *task, u32 *state, Task *work);

extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern int func_0216E51C(void *hit);
extern void *func_0200CA1C(void *a);
extern unsigned int func_02017E1C(void *a, unsigned int b, unsigned int c);
extern u32 func_02017988(void *p, u32 a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0216F02C(void **p, void *a, void *b);
extern void *func_0201313C(void *p, int i);
extern void *func_0201AB28(void *party, u32 i);
extern void *func_0201210C(const struct Ctx *p);
extern void func_021CF5D8(u32 species, u32 a, u32 b, void *c, u32 *d, void *e);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02012F20(int p0);
extern void func_0202E79C(u8 *p);
extern u32 func_02012A44(const struct BigObj *p);
extern int func_0216EFA8(int a, int b);
extern void *func_0215F6E8(void *sys);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_0202E818(int *p);
extern void *func_02181D8C(void *sys, u32 v);
extern int func_0216EB98(void *evt, u32 *state, struct Work *w);
extern void func_0216EE40(void *p, int which);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02188CE8(u8 *p);
extern void func_021AAABC(int s);
extern void *func_02013090(u32 heap);
extern void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
extern void func_0216EE20(u16 id, int col);
extern void func_02013144(char *p, int v);
extern void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
int func_0216E5B0(void *map, const VecFx32 *pos);
int func_0216E5FC(u16 id);
void func_0216E618(Obj *o, u16 x, u16 y, int z);
void func_0216E62C(int a, int p, int id);
int func_0216E680(int a0);
int func_0216E68C(void *evt, u32 *state, Work *w);
int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
int func_0216E8CC(int a0, int a1, int a2);
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];


/*
 * Whether the map cell under pos (x, z in whole tiles of 16 units) holds a
 * hit whose check returns 1.
 */
int func_0216E5B0(void *map, const VecFx32 *pos)
{
    void *hit = func_0216DDDC((u32)map, (s16)((pos->x >> 4) / 4096), (s16)((pos->z >> 4) / 4096), pos->y, 0x20000, (int)0);

    if (hit != 0 && func_0216E51C(hit) == 1)
        return 1;
    return 0;
}


/*
 * True for kind 0x6D and 0x2003..0x2005. The range test must be written
 * as `(u16)(id + 0xDFFD) <= 2`: `id >= 0x2003 && id <= 0x2005` keeps two
 * compares, `(u16)(id - 0x2003)` pools 0x2003 and subtracts.
 */
int func_0216E5FC(u16 id)
{
    if (id == 0x6D || (u16)(id + 0xDFFD) <= 2)
        return 1;
    return 0;
}


/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C758): clears the word
 * at +0x18 and fills the {u16, u16, int} record at +0x1C.
 */
void func_0216E618(Obj *o, u16 x, u16 y, int z)
{
    Pos *p;

    o->f18 = 0;
    p = &o->pos;
    p->x = x;
    p->y = y;
    p->z = z;
}


void func_0216E62C(int a, int p, int id)
{
    int h;
    int t;
    int i;

    h = (int)func_0200CA1C((void *)a);
    t = func_02017E1C((void *)p, 5, 0);
    for (i = 0; i < 25; i++) {
        if (id == d_02172554[i][0]) {
            int v = d_02172556[i][0];
            if (t == 0x19c) {
                func_02017988((void *)p, (u16)v);
                func_0200CFA0((struct Blk37 *)h, (void *)p);
            }
            return;
        }
    }
}




int func_0216E680(int a0)
{
    int t4;

t4 = a0 + 0;
    if (t4 == 0) goto loc_0216E688;
loc_0216E686:
    a0 = ((int (*)())t4)();
loc_0216E688:
a0 = ~t4;
    return a0;}


/*
 * Four-state proc that pushes the tutorial capture task (func_0216EB98)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (func_021CF5D8's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return bs->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 func_0201313C (matched file exists, no shard) and func_0202E818 (new matched/arm9 file, EXACT, this lane).
 */
int func_0216E68C(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *ctx = func_020120F4(sys);
    void *task;
    Task *t;
    u32 species;
    u32 flag;

    switch (*state) {
    case 0:
        task = func_020122C0(sys, 0, func_0216EB98, 0x28);
        t = func_020124E8(task);
        func_0216F02C((void **)t, sys, w->bs);
        flag = 1;
        t->f14 = 1;
        species = func_02017E1C(func_0201AB28(func_0201313C(w->bs, 1), 0), 5, 0);
        {
            void *proc = func_0201210C(sys);

            if (w->bs->f04 != 1)
                flag = 0;
            func_021CF5D8(species, w->f0c, flag, proc, &t->f24, t->f08->f18);
        }
        func_02012374(evt, task);
        (*state)++;
        break;
    case 1:
        if (w->f08 == 1) {
            func_0202E79C((void *)func_02012F20((int)ctx));
            return 1;
        }
        if (func_0216EFA8(func_02012A44(ctx), 0) == 1) {
            func_0202E79C((void *)func_02012F20((int)ctx));
            func_0201235C(evt, func_0215F6E8(sys));
        } else {
            func_02012374(evt, func_021BE92C(sys, func_0201210C(sys), 0, 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 2:
        if (func_0202E818((void *)func_02012F20((int)ctx)) == 1)
            func_02012374(evt, func_02181D8C(sys, 4));
        (*state)++;
        break;
    case 3:
        func_0202E79C((void *)func_02012F20((int)ctx));
        return 1;
    }
    return 0;
}


/*
 * Allocates a 0x10-byte task record (handler func_0216E68C) and fills it
 * from the arguments.
 */
int func_0216E7C8(int a0, int a1, int a2, int a3, int a4)
{
    int h;
    u32 *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216E68C, 0x10);
    t = func_020124E8((struct Obj *)h);
    t[0] = a0;
    t[1] = a2;
    t[2] = a3;
    t[3] = a4;
    func_0216EE40((void *)a2, 0);
    func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)a0)), 5);
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}


int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int h;
    int *t;
    int v;
    int w;
    int x;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    v = func_02188CE8((u8 *)a1);
    w = (int)func_02012F2C(func_020120F4((const struct Ctx *)a0));
    x = (int)func_02013090(4);
    func_021AA5CC((struct Ctx *)v, (void *)x, a2, a3, (void *)a4, a5, 4);
    func_0216EE20(a4, 0);
    func_02008DF0((struct Sub02008C20Obj *)w, 6);
    func_02008DF0((struct Sub02008C20Obj *)w, 0x56);
    func_0216F02C((void **)t, (void *)a0, (void *)x);
    t[5] = 1;
    if (a6 & 1) {
        func_02013144((char *)x, 0x100);
        t[6] = 1;
    }
    func_021CF748(a4, a1, (int *)((int)t + 0x24), (u16 *)(t[2] + 0x18));
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}


int func_0216E8CC(int a0, int a1, int a2)
{
    int h;
    int *t;

    h = (int)func_020122C0((void *)a0, 0, func_0216EB98, 0x28);
    t = func_020124E8((struct Obj *)h);
    func_0216F02C((void **)t, (void *)a0, (void *)a2);
    t[5] = 0;
    t[6] = 1;
    t[8] = 1;
    t[9] = 9;
    func_021AAABC(func_02188CE8((u8 *)a1));
    return h;
}
