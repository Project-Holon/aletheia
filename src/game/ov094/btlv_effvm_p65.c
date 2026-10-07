/*
 * file:     btlv_effvm_p65.c
 * unit:     yes
 * function: func_021FF7B0, func_021FF870, func_021FF924, func_021FFA18
 * address:  0x021FF7B0
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
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_022089BC  0x022089BC  thumb  ov094
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021FF260  0x021FF260  thumb  ov094
 *   func_02200CD0  0x02200CD0  thumb  ov094
 *   func_02200D30  0x02200D30  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 *   func_02015FAC 0x02015FAC thumb
 *   func_0220074C 0x0220074C thumb ov094
 *   func_02200D68 0x02200D68 thumb ov094
 *   func_02200DE4 0x02200DE4 thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02200E1C 0x02200E1C thumb ov094
 *   func_02201098 0x02201098 thumb ov094
 */
#include "../../matched/include/Obj06309.h"

#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))
typedef struct {
    int x, y, z;
} Vec3;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x44];
    int key;                /* 0x48 */
    unsigned int pad4c : 6; /* 0x4c */
    unsigned int f6 : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work_021FF7B0;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x520 - 4];
    int mask[4];            /* 0x520 */
    char pad530[0x540 - 0x530];
    u16 heap;               /* 0x540 */
    char pad542[0x588 - 0x542];
    u8 cnt[4][14];          /* 0x588 */
} Work_021FF870;

typedef struct {
    Work_021FF870 *w;                /* 0x00 */
    int i;                  /* 0x04 */
    char pad08[0x0c];
    int kind;               /* 0x14 */
    char pad18[0x2c];
    int f44;                /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
} Obj_021FF870;

typedef struct { int x, y, z; } Vec;

typedef struct {
    void *owner;
    char pad04[0x514 - 4];
    int mask;
    char pad518[0x540 - 0x518];
    u16 heap;
    u8 cnt[14];
} Work_021FFA18;

typedef struct {
    Work_021FFA18 *w;
    int key, kind, direction, f10, f14, f18, f1c, f20, f24;
    int f28, f2c, f30, f34, f38;
} Obj_021FFA18;

extern int func_022019F4(char *p, int key);
extern int func_021FFD9C(char *p, int key);
extern void func_022018A8(Work_021FF7B0 *w, Vec3 *out, int key);
extern void func_021FF4C0(Work_021FF7B0 *w, int key, int a, Vec3 *v, int b, int c, int d);
extern int func_021F86B4(void);
extern void func_022089BC(char *p, int i);
extern void func_021FF374(Work_021FF7B0 *w, int key, int kind);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern int func_021F935C(int x);
extern void func_021FF260(Work_021FF870 *w, int key, int flag);
extern void func_02200CD0(void);
extern void func_02200D30(void *p);
extern u8 func_02015FAC(void *p);
extern void func_0220074C(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern void func_02200D68(void *o, char *q);
extern void func_02200DE4(void *p);
extern void func_02200E1C(void *task, char *q);
extern void func_02201098(void *p);
void func_021FF7B0(Work_021FF7B0 *w, int a, int b);
void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b);
void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);
void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s);
extern const char d_0220AE7C[];


void func_021FF7B0(Work_021FF7B0 *w, int a, int b)
{
    int keys[2];
    int idx[2];
    Vec3 v;
    int i;

    keys[0] = a;
    keys[1] = b;
    for (i = 0; i < 2; i++) {
        idx[i] = func_022019F4((char *)w, keys[i]);
        if (func_021FFD9C((char *)w, keys[i])) {
            func_022018A8(w, &v, keys[i ^ 1]);
            func_021FF4C0(w, keys[i], 0, &v, 0, 0, 0);
            func_022089BC((char *)func_021F86B4(), keys[i]);
            if (w->e[idx[i]].f6) {
                w->e[idx[i]].f6 = 0;
                func_021FF374(w, keys[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            w->e[idx[i]].key = keys[i ^ 1];
    }
}


void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b)
{
    Obj_021FF870 *o;

    switch (kind) {
    case 3:
        func_021FF260(w, key, 1);
        return;
    case 4:
        func_021FF260(w, key, 0);
        return;
    case 2:
        o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0x5e5);
        o->w = w;
        o->i = key;
        o->kind = kind;
        o->f44 = 0;
        o->f48 = a;
        o->f4c = b * 2;
        w->cnt[0][key]++;
        o->f50 = w->cnt[0][key];
        func_021F896C(func_02030DA8(w->owner, (void *)func_02200CD0, o, 0), func_02200D30, 2);
        w->mask[2] |= func_021F935C(key);
        return;
    }
}

/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02015FAC_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int value : 8; } Data;
 * u8 func_02015FAC(Data *p) { return p->value; }
 */
void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(func_02015FAC(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x596 + key))++;
    func_0220074C(w, key, kind, &start, &end, a, b, c, (void *)func_02200D68, func_02200DE4, 0, *(u8 *)(w + 0x596 + key));
    ((struct Obj06309 *)w)->f52C |= func_021F935C(key);
}

/*
 * lever: the 4/5 kind test is an unsigned range check; individual equality tests cost two bytes.
 */
void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s)
{
    Obj_021FFA18 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x3c, 0, d_0220AE7C, 0x627);
    o->w = w;
    o->key = s->key;
    o->kind = s->kind;
    o->direction = s->direction;
    o->f10 = s->f10;
    o->f14 = s->f14;
    o->f18 = s->f18;
    o->f1c = s->f1c;
    o->f20 = s->f20;
    o->f24 = s->f24;
    o->f30 = 0;
    o->f34 = 0;
    if (o->key & 1) {
        if ((o->kind != 0 && o->kind != 1 && (unsigned)(o->kind - 4) > 1)
            || (s->direction != 2 && s->direction != 3))
            o->direction ^= 1;
    }
    o->f28 = (o->kind & 1) ? 0x10000 : 0;
    o->f2c = 0x10000 / s->f18;
    w->cnt[o->key]++;
    o->f38 = w->cnt[o->key];
    func_021F896C(func_02030DA8(w->owner, (void *)func_02200E1C, o, 0), func_02201098, 2);
    w->mask |= func_021F935C(o->key);
}
