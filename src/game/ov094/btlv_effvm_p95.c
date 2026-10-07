/*
 * file:     btlv_effvm_p95.c
 * unit:     yes
 * function: func_022044A0, func_022044C0, func_0220453C, func_02204588, func_022045A8, func_0220461C, func_02204678, func_02204698, func_022047CC, func_022047F8, func_02204838, func_022048A4, func_02204940, func_02204960, func_022049C8, func_02204A3C
 * address:  0x022044A0
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
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_02040618  0x02040618  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 *   d_0220A46C     0x0220A46C  data  ov094  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 *   func_02030EE8  0x02030EE8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_02040588  0x02040588  arm
 *   func_022023D0  0x022023D0  thumb  ov094
 *   func_02021ED8  0x02021ED8  thumb
 */
#include "../../matched/include/Obj21770.h"

struct S02030EE8;
struct Ctx;
struct Actor;
struct Bank;
struct Vec2;
struct Obj;
struct PtS;
typedef struct Bits_022044A0 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_022044A0;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Main_022044C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022044C0;

typedef struct Obj_022044C0 {
    Main_022044C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Obj_022044C0;

typedef struct Ctx_0220453C {
    char *main;
    int state;
    int a8;
    int ac;
    int d10;
    int cnt;
} Ctx_0220453C;

typedef struct Bits_02204588 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204588;

typedef struct Main_022045A8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022045A8;

typedef struct Obj_022045A8 {
    Main_022045A8 *main;
    int idx;
    int set;
    int cnt;
} Obj_022045A8;

typedef struct Ent {
    int v0;
    int v1;
} Ent;

typedef struct Ctx_0220461C {
    char *main;
    int idx;
    int set;
    int cnt;
} Ctx_0220461C;

typedef struct Bits_02204678 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204678;

typedef struct Bits_02204698 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204698;

typedef struct Obj_02204698 {
    void *h0;
    char pad04[0x68 - 4];
    Bits_02204698 f68;
    char pad6c[0x104 - 0x6c];
    int h104;
    int h108;
    int h10c;
    char pad110[0x240 - 0x110];
    u16 heap;
} Obj_02204698;

typedef struct Quad { u16 v[4]; } Quad;

typedef struct Pos { short x; short y; } Pos;

typedef struct Row { Pos pos[6]; int val[2]; } Row;

typedef struct Res { Obj_02204698 *owner; void *h; void *e[6]; } Res;

typedef unsigned char  u8;

typedef struct Main_022047F8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_022047F8;

typedef struct Ctx_022047F8 {
    Main_022047F8 *main;
    int h4;
    void *ent[6];
} Ctx_022047F8;

typedef struct Main_02204838 {
    void *f0;
    unsigned char pad04[0x68 - 4];
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02204838;

typedef struct Obj_02204838 {
    Main_02204838 *main;
    int f4;
} Obj_02204838;

typedef short s16;

typedef struct Main_022048A4 {
    unsigned char pad00[0x68];
    u32 f68;
} Main_022048A4;

typedef struct Ctx_022048A4 {
    Main_022048A4 *main;
    int f4;
} Ctx_022048A4;

typedef struct Bits_02204940 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204940;

typedef struct Main_02204960 {
    unsigned char pad00[0x240];
    u16 h240;
} Main_02204960;

typedef struct Obj_02204960 {
    Main_02204960 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Obj_02204960;

typedef struct Ctx_022049C8 {
    void *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Ctx_022049C8;

typedef struct Bits_02204A3C { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A3C;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
extern void func_0220684C(char *p, int a, int b);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0220687C(char *p, void *q);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj_02204698 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B404(struct Obj_02204698 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B92C(struct Obj_02204698 *p, u32 v);
extern void func_0204B878(struct Obj_02204698 *p, u16 value);
extern void *func_02030DA8(void *, void (*)(void *, Res *), void *, u32);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_02021ED8(const char *ptr);
extern int func_0204E804(void);
extern void func_022023D0(char *p);
void func_022044A0(void *h);
void func_022044C0(Main_022044C0 *m, int a1, int a2, int a3, int a4);
void func_0220453C(int a0, Ctx_0220453C *c);
void func_02204588(void *h);
void func_022045A8(Main_022045A8 *m, int a1, int a2);
void func_0220461C(int a0, Ctx_0220461C *c);
void func_02204678(void *h);
void func_02204698(Obj_02204698 *p, int a, int b);
void func_022047CC(void *a, void **s);
void func_022047F8(void *h);
void func_02204838(Main_02204838 *m, int a1);
void func_022048A4(int a0, Ctx_022048A4 *c);
void func_02204940(void *h);
void func_02204960(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void func_022049C8(int a0, Ctx_022049C8 *c);
void func_02204A3C(void *a, char **s);
extern const char d_0220AEB0[];
extern const Ent d_0220A46C[][2];
extern const Quad d_0220A53C;
extern Row d_0220A85C[];
extern const int d_0220A3B4[][2];


void func_022044A0(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_022044A0 *)(p + 0x68))->n--;
}


void func_022044C0(Main_022044C0 *m, int a1, int a2, int a3, int a4)
{
    Obj_022044C0 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x18, 0, d_0220AEB0, 0xbd5);
    o->main = m;
    o->f4 = 0;
    o->f8 = a1;
    o->fc = a2;
    o->f10 = a3;
    o->f14 = a4;
    func_0220684C((char *)m, (int)func_020056A0((void *)func_0220453C, o, 0), (int)func_02204588);
    m->st = m->st + 1;
}


void func_0220453C(int a0, Ctx_0220453C *c)
{
    if (c->state == 0) {
        func_02040618(4, 0, c->a8);
        func_02040618(4, 3, c->ac);
        c->state = c->state + 1;
        return;
    }
    c->ac = c->ac + c->d10;
    func_02040618(4, 3, c->ac);
    c->cnt = c->cnt - 1;
    if (c->cnt == 0)
        func_0220687C(c->main, (void *)a0);
}


void func_02204588(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_02204588 *)(p + 0x68))->n--;
}


void func_022045A8(Main_022045A8 *m, int a1, int a2)
{
    Obj_022045A8 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0xc10);
    o->main = m;
    o->idx = 0;
    o->set = a2;
    o->cnt = 2;
    func_0220684C((char *)m, (int)func_020056A0((void *)func_0220461C, o, 0), (int)func_02204678);
    m->st = m->st + 1;
}


/*
 * lever:    the table extern is `const` (non-const put the cnt store before the address add)
 */
void func_0220461C(int a0, Ctx_0220461C *c)
{
    int i;

    c->cnt = c->cnt - 1;
    if (c->cnt == 0) {
        c->cnt = 2;
        func_02040618(5, 0, d_0220A46C[c->set][c->idx].v0);
        i = c->idx;
        c->idx = i + 1;
        func_02040618(5, 3, d_0220A46C[c->set][i].v1);
        if (c->idx >= 2)
            func_0220687C(c->main, (void *)a0);
    }
}


void func_02204678(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_02204678 *)(p + 0x68))->n--;
}


/*
 * note: the row offset goes into the row pointer first and the table base is added
 *   to it (base + offset); that order gives the original r0/r1 colouring at +0056.
 */
void func_02204698(Obj_02204698 *p, int a, int b)
{
    Res *r;
    u16 v;
    int i;
    Row *row;
    Quad quad;

    r = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    r->owner = p;
    r->h = func_0204B100(6, 0, p->heap);
    row = (Row *)(a << 5);
    row = (Row *)((u32)d_0220A85C + (u32)row);
    v = row->val[b];
    for (i = 0; i < 6; i++) {
        if (row->pos[i].x == -1) {
            r->e[i] = 0;
        } else {
            r->e[i] = func_0204B294(r->h, p->h104, p->h108, p->h10c, &quad, 1, p->heap);
            func_0204B404(r->e[i], (const struct Vec2 *)(&row->pos[i]), 1);
            func_0204B570(r->e[i], 2);
            func_0204B92C(r->e[i], 1);
            func_0204B878(r->e[i], v);
        }
    }
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, (void (*)(void *, Res *))func_022047CC, r, 0), (int)func_022047F8);
    p->f68.n++;
}


void func_022047CC(void *a, void **s)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (s[i + 2] != 0 && func_0204B98C(s[i + 2]) != 0)
            return;
    }
    func_0220687C(s[0], a);
}


void func_022047F8(void *h)
{
    Ctx_022047F8 *c = (Ctx_022047F8 *)func_02030EE8(h);
    int i;

    for (i = 0; i < 6; i++) {
        if (c->ent[i] != 0)
            func_0204B3B4(c->ent[i]);
    }
    func_0204B1CC((struct Bank *)c->h4);
    c->main->st = c->main->st - 1;
}


void func_02204838(Main_02204838 *m, int a1)
{
    Obj_02204838 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0xcc9);
    o->main = m;
    o->f4 = a1;
    func_0220684C((char *)m, (int)func_02030DA8(m->f0, (void *)func_022048A4, o, 0), (int)func_02204940);
    m->st = m->st + 1;
}


void func_022048A4(int a0, Ctx_022048A4 *c)
{
    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    s16 v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][c->f4];
        if (k == 0) {
            p = (char *)c->main + 0x47 * 4;
        } else {
            if (((c->main->f68 << 17) >> 31) == 0) {
                break;
            }
            p = (char *)c->main + 0x53 * 4;
        }
        for (j = 0; j < 6; j++) {
            func_0204B454(*(void **)(p + j * 8), (struct PtS *)v, 1);
            if (v[1] > target) {
                v[1] = v[1] - 4;
                changed = 1;
            } else if (v[1] < target) {
                v[1] = v[1] + 4;
                changed = 1;
            }
            func_0204B404(*(void **)(p + j * 8), (const struct Vec2 *)v, 1);
        }
    }
    if (changed == 0) {
        func_0220687C((char *)c->main, (void *)a0);
    }
}


void func_02204940(void *h)
{
    char *p = *((char **)func_02030EE8(h));
    ((Bits_02204940 *)(p + 0x68))->n--;
}


void func_02204960(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Obj_02204960 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xd1d);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    o->f14 = a5;
    o->f18 = a6;
    o->f1c = a7;
    func_0220684C((char *)m, (int)func_020056A0((void *)func_022049C8, o, 0), 0);
}


void func_022049C8(int a0, Ctx_022049C8 *c)
{
    if (c->f4 != -1) {
        func_02040618((u8)c->f4, (int)0, (int)c->f8);
        func_02040618((u8)c->f4, (int)3, (int)c->fc);
    }
    if (c->f10 != 2) {
        func_02040588((int)4, (u8)c->f10);
    }
    if (c->f14 != 2) {
        func_02040588((int)5, (u8)c->f14);
    }
    if (c->f18 != 2) {
        func_02040588((int)6, (u8)c->f18);
    }
    if (c->f1c != 2) {
        func_02040588((int)7, (u8)c->f1c);
    }
    func_0220687C(c->main, (void *)a0);
}


void func_02204A3C(void *a, char **s)
{
    if (func_02021ED8(((struct Obj21770 *)(*s))->f64) != 0)
        return;
    if (func_0204E804() != 0)
        return;
    if (((Bits_02204A3C *)(*s + 0x68))->mode == 1)
        func_022023D0(*s);
    func_0220687C(*s, a);
}
