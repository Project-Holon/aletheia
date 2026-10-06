/*
 * function: func_0216E68C
 * address:  0x0216E68C
 * packet:   pkt_ov010_0216E68C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four-state proc that pushes the tutorial capture task (func_0216EB98)
 * for the opponent's first Pokemon and then the result screens.
 * Byte-correct first draft (func_021CF5D8's species is a u32 here: no
 * truncation at the call).
 * Blocker (MATCH): two arm9 Thumb callees have no func_ label and no
 * matched file: 0x0201313C (`return bs->party[side]`, 8 bytes) and
 * 0x0202E818 (16 bytes). Seeds for the arm9 lane.
 *
 * 2026-10-05: byte-identical; the two wildcards resolve once shards exist for arm9 func_0201313C (matched file exists, no shard) and func_0202E818 (new matched/arm9 file, EXACT, this lane).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_0201313C  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

struct BigObj;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct S0201235C;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0216F02C(void **p, void *a, void *b);
extern void *func_0201313C(void *p, int i);
extern void *func_0201AB28(void *party, u32 i);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
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
