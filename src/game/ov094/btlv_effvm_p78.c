/*
 * file:     btlv_effvm_p78.c
 * unit:     yes
 * function: func_022012CC, func_02201304, func_02201408, func_02201700
 * address:  0x022012CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02015EE8 0x02015EE8 thumb
 *   func_02015F40 0x02015F40 thumb
 *   func_02201810 0x02201810 thumb ov094
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   d_0220AE78 0x0220AE78 data a4
 *   func_021F86C4 0x021F86C4 thumb ov094
 *   func_021F9824 0x021F9824 thumb ov094
 *   func_02016028 0x02016028 thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_02201718 0x02201718 thumb ov094
 *   d_0220A0C8     0x0220A0C8  data
 *   d_0220A0B0     0x0220A0B0  data
 *   d_0220A0E0     0x0220A0E0  data
 *   d_020A1B38     0x020A1B38  data  a2
 *   _ll_mul        0x0209C054  arm
 *   func_021F86A4  0x021F86A4  thumb  ov094
 *   func_021F6AA8  0x021F6AA8  thumb  ov094
 *   func_0200616C  0x0200616C  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_022089BC  0x022089BC  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
#include "../../matched/include/Obj21725.h"
#include "../../matched/include/Obj21726.h"
#include "../../matched/include/Obj21727.h"
#include "../../matched/include/Obj21729.h"

#define MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))
struct S02030EE8;
struct Node;
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x530 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x530 */
    char pad534[0x5a4 - 0x534];
    u8 tag[1];              /* 0x5a4 */
} Work_022012CC;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work_022012CC *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef unsigned short u16;

typedef short s16;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    int v[2][3];
} Tab6;

typedef struct {
    int v[2][2][3];
} Tab12;

typedef struct {
    char pad00[0x30];
    int busy;           /* 0x30 */
    char pad34[0x1c];
    int target;         /* 0x50 */
    char pad54[0x08];
} Slot;

typedef struct {
    char *p;            /* 0x00 */
    u32 state : 31;     /* 0x04 */
    u32 sound : 1;
    int idx;            /* 0x08 */
    int dir;            /* 0x0c */
    int ang[3];         /* 0x10 */
    int cnt;            /* 0x1c */
    int step;           /* 0x20 */
} Work_02201408;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F935C(int x);
extern int func_021F8694(void);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_02015EE8(void *);
extern void func_02015F40(char *p, unsigned flags, void *callback);
extern int func_02201810(u32 flags, int a, int *out, int key);
extern u32 func_0203F0A8(void);
extern int func_021F86C4(void);
extern int func_021F9824(void *);
extern void func_02016028(void *, u32);
extern void func_02015F2C(void *, u32, void (*)(int), int);
extern void func_02201718(int);
extern int func_021F86A4(void);
extern void func_021F6AA8(int p, int i, int j, int a, int b);
extern void func_0200616C(void *arg, int i);
extern void func_020061F8(int a);
extern int func_021FFD9C(char *p, int key);
extern void func_021FF4C0(char *p, int key, int b, Vec *v, int d, int e, int f);
extern void func_022018A8(char *p, Vec *out, int key);
extern int func_022019F4(char *p, int key);
extern int func_021F86B4(void);
extern void func_022089BC(char *p, int i);
extern void func_021F89BC(void *task);
void func_022012CC(void *h);
void func_02201304(void *task, int *q);
void func_02201408(void *task, Work_02201408 *w);
void func_02201700(void *h);
extern const u8 d_0220AE78[];
extern const Tab6 d_0220A0C8;
extern const Tab6 d_0220A0B0;
extern const Tab12 d_0220A0E0;
extern const s16 d_020A1B38[];


void func_022012CC(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}

/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015F40 belongs to Ilias.
 * Verified C: one, Thumb dsi/1.1p1 -O4,p EXACT 16 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/f40-proof.log
 * symbols for blocker: func_02064D70 0x02064D70 arm
 *   extern void func_02064D70(void *, void *, unsigned);
 *   void func_02015F40(char *p, unsigned flags, void *callback)
 *   { func_02064D70(p + 0x68, callback, flags); }
 * lever: Offset local precedes the entry pointer, and is initialized first.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces; both
 * 02015F40 witnesses are inside this callback. No overlay leaves filed.
 */
void func_02201304(void *task, int *q)
{
    char *p = (char *)func_021F8694();
    int i = q[1];
    int off;
    char *e;
    if (i == -1) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    off = i * 0x5c;
    e = p + 8;
    if (*(void **)(e + off) == 0) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    switch (q[0]) {
    case 0:
        ((struct Obj21726 *)((char *)func_02015EE8(*(void **)(e + off))))->fC = 0;
        func_02015F40(*(void **)(e + off), i | 0x80000000, func_02201810);
        q[0]++;
        q[2] = d_0220AE78[(u32)(((u64)func_0203F0A8() * 3) >> 32)];
        return;
    case 1:
        q[2]--;
        if (q[2] != 0 && ((struct Obj21725 *)p)->f51C == 0 && func_021F9824((void *)func_021F86C4()) != 0) break;
        func_02016028(*(void **)(e + off), 0);
        ((struct Obj21727 *)((char *)func_02015EE8(*(void **)(e + off))))->fC = 1;
        func_02015F40(*(void **)(e + off), i, func_02201810);
        q[0]++;
        return;
    case 2:
        func_02015F2C(*(void **)(e + off), i, func_02201718, 1);
        func_020307B0(q);
        func_02030EAC(task);
        *(int *)(p + off + 0x30) = 0;
        break;
    }
}


/*
 * lever: the slot test written as char-pointer arithmetic (p + k * 0x5c + 0x30)
 * swaps the row and base registers in the case-0 loop; indexing a 0x5c-byte
 * Slot struct array evaluates the row first, as the original does.
 */
void func_02201408(void *task, Work_02201408 *w)
{
    Tab6 keys = d_0220A0C8;
    Tab6 angs = d_0220A0B0;
    Tab12 tgt = d_0220A0E0;
    Vec v;
    Vec pos;
    int idx[3];
    int i;
    int step;

    switch (w->state) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (((Slot *)w->p)[keys.v[w->idx][i]].busy != 0)
                break;
        }
        if (i != 3)
            return;
        for (i = 0; i < 3; i++)
            w->ang[i] = angs.v[w->idx][i];
        step = (w->dir == 0) ? 0x1000 : -0x1000;
        func_021F6AA8(func_021F86A4(), w->idx, 0, step, 0x3c);
        w->step = (w->dir == 0) ? 0x16c : -0x16c;
        w->cnt = 0x3c;
        if (w->sound)
            func_0200616C((void *)0x6ca, 2);
        w->state++;
        return;
    case 1:
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                v.x = MUL(d_020A1B38[((u16)w->ang[i] >> 4) * 2], 0x5000);
                v.y = 0x666;
                v.z = (w->idx == 0) ? 0xc000 : -0xd000;
                v.z += MUL(d_020A1B38[((u16)w->ang[i] >> 4) * 2 + 1], 0x5000);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, &v, 0, 0, 0);
            }
            w->ang[i] += w->step;
        }
        if (--w->cnt != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                func_022018A8(w->p, &pos, tgt.v[w->dir][w->idx][i]);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, &pos, 0, 0, 0);
            }
        }
        w->state++;
        return;
    case 2:
        if (*(int *)(w->p + 0x514) != 0)
            return;
        for (i = 0; i < 3; i++) {
            idx[i] = func_022019F4(w->p, keys.v[w->idx][i]);
            func_022089BC((char *)func_021F86B4(), keys.v[w->idx][i]);
        }
        for (i = 0; i < 3; i++) {
            if (idx[i] != -1)
                ((Slot *)w->p)[idx[i]].target = tgt.v[w->dir][w->idx][i];
        }
        if (w->sound) {
            func_020061F8(2);
            func_0200616C((void *)0x57a, 1);
        }
        func_021F89BC(task);
        return;
    }
}


void func_02201700(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((struct Obj21729 *)p)->f510 &= ~4;
}
