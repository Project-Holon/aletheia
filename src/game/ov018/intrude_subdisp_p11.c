/*
 * file:     intrude_subdisp_p11.c
 * unit:     yes
 * function: func_0217EC7C, func_0217EEB4, func_0217EF44, func_0217EF70, func_0217EFCC, func_0217F008, func_0217F0C4, func_0217F0FC, func_0217F118, func_0217F174, func_0217F194
 * address:  0x0217EC7C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_02012B58  0x02012B58  thumb
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0217F284  0x0217F284  thumb  ov018
 *   func_0217EC44  0x0217EC44  thumb  ov018
 *   func_0217EC5C  0x0217EC5C  thumb  ov018
 *   func_02013DD0  0x02013DD0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_020257C4  0x020257C4  thumb
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_0204989C  0x0204989C  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0217F1E8  0x0217F1E8  thumb  ov018
 *   func_0217F240  0x0217F240  thumb  ov018
 *   func_020413B0  0x020413B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02080D24  0x02080D24  arm
 *   func_0217F5A0  0x0217F5A0  thumb  ov018
 *   func_021758C8  0x021758C8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj03092.h"
#include "../../matched/include/Obj00399.h"
#include "../../matched/include/Obj12492.h"
#include "../../matched/include/Obj09396.h"

struct Actor;
struct BigObj;
struct Ctx;
struct Obj;
struct PtS;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int lo : 20;
    unsigned int id : 10;
    unsigned int hi : 2;
} Mon;

typedef struct {
    int l, t, r, b;
} Rect;

typedef struct {
    u16 id;
    u8 pad02[0x1A];
} QEnt;

typedef struct {
    u8 pad00[0xA0];
    QEnt e[3];
} Q;

typedef struct {
    int f00;
    u8 pad04[0x8C - 0x04];
    int f8C[3];
    u8 pad98[0xC4 - 0x98];
    int fC4;
    u8 padC8[0xD8 - 0xC8];
    u8 fD8;
    u8 fD9;
    u8 padDA[0x106 - 0xDA];
    u8 f106;
    u8 f107;
    u8 pad108[0x110 - 0x108];
    u16 f110;
    u8 f112;
    u8 f113;
    u8 pad114[0x168 - 0x114];
    u8 f168;
    u8 f169;
} Obj;

typedef struct { u8 a, b, c, d; int e, f; } State;

typedef struct { u16 lo : 3; u16 hi : 13; } Bf;

typedef struct { u8 pad[0x28]; u8 idx; } T;

typedef struct {
    u8 a, b, c, d;
    int e;
    int f;
    T *g;
    u8 h, i, j;
} O;

typedef struct {
    u8 pad0[0x5C];
    void *tbl[9];
    u8 pad80[0x114 - 0x80];
    u8 f114;
    u8 pad115[3];
    u16 f118;
    u8 f11A;
    u8 f11B;
} Ov018Sel;

typedef struct {
    u8 pad0[0x9C];
    void *f9C;
    u8 padA0[0x116 - 0xA0];
    u8 f116;
    u8 f117;
} Ov018Blink;

extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CCC(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021A0F94(u32 a);
extern u8 func_02012B58(const struct BigObj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern Mon *func_0217BEA8(int a0);
extern int func_0217F284(u8 *p);
extern void func_0217EC44(int x, int y, int w, int h, Rect *r);
extern int func_0217EC5C(u32 x, u32 y, Rect *r);
extern int func_02013DD0(int a0);
extern void func_020061E4(u32 a);
extern u32 func_02013D5C(u32 id);
extern int func_020257C4(const int *p);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern int func_0217F1E8(u8 *p);
extern void func_0217F240(u8 *p, int mode);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02082BCC(void *, int, int);
extern int func_02080D24(unsigned int x);
extern int func_0217F5A0(char *);
extern int func_021758C8(u8 *o);
extern u8 *func_02175B34(u8 *p);
extern int func_0217C070(u8 *p);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_0217EC7C(Q *q, Obj *p, int id);
void func_0217EEB4(int *p);
void func_0217EF44(u8 *p);
void func_0217EF70(int *p, int x);
void func_0217EFCC(char *p, char *q);
void func_0217F008(char *p, char *q);
void func_0217F0C4(u8 *p);
int func_0217F0FC(u8 *p);
void func_0217F118(Ov018Sel *p, int n);
void func_0217F174(u8 *p);
void func_0217F194(Ov018Blink *p);
extern const Ent d_02176AA0[];


/*
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           func_02013D9C's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */
void func_0217EC7C(Q *q, Obj *p, int id)
{
    Rect rect;
    u32 tx;
    u32 ty;
    s16 pt[2];
    int x;
    int sel;
    int h;
    int i;
    int w;
    int a;
    const Ent *e;
    Mon *m;

    x = func_02188CCC(func_0201210C((const struct Ctx *)p->f00));
    func_02012138((const struct Ctx *)p->f00);
    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (p->f112 != 0 || p->f106 == 1 || !func_02035D20(&tx, &ty) || func_021A0F94(x) != 0) {
        return;
    }
    sel = func_02012B58((const struct BigObj *)h);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(p->fD9 & (1 << i))) {
            continue;
        }
        w = p->f8C[i];
        if (func_0204B3F4((struct Obj *)w) != 1) {
            continue;
        }
        func_0204B454((struct Actor *)w, (struct PtS *)pt, 0);
        if (tx - 12 > pt[0] || tx + 12 < pt[0]) {
            continue;
        }
        if (ty - 12 > pt[1] || ty + 12 < pt[1]) {
            continue;
        }
        if (q == 0) {
            continue;
        }
        if (func_0217BEA8(q->e[i].id) == 0) {
            continue;
        }
        p->f169 = i;
        return;
    }
    if (func_0217F284((u8 *)p) == 1) {
        return;
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        for (i = 0; i < 8; i++) {
            e = &d_02176AA0[i];
            func_0217EC44(e->x, e->y, 0x10, 0x10, &rect);
            if (func_0217EC5C(tx, ty, &rect) != 1) {
                continue;
            }
            a = e->a;
            if (id == a || id == e->b || (func_02013DD0(id) == 1 && func_02013DD0(a) == 1)) {
                func_020061E4(0x557);
                return;
            }
            if (i == 7) {
                p->f106 = 1;
                p->f107 = 0;
            } else {
                m = func_0217BEA8(a);
                if (m == 0) {
                    continue;
                }
                p->f110 = m->id;
                p->f112 = 1;
            }
            p->f113 = i;
            return;
        }
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        func_0217EC44(0x80, 0x5C, 0x10, 0x10, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            if (func_02013D5C(id) == 1) {
                func_020061E4(0x557);
                return;
            }
            p->f110 = 0x117;
            p->f112 = 1;
            p->f113 = 8;
            return;
        }
    }
    if (p->f168 == 0 && func_020257C4((const int *)p->fC4) == 1) {
        func_0217EC44(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            p->f168 = 1;
        }
    }
}


void func_0217EEB4(int *p)
{
    int n;

    n = 0;
    if (*((u8 *)p + 0x11f) == 0) {
        if (*((u8 *)p + 0xda) > 1) {
            func_0204989C(0x24, 7, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 1;
            n++;
        }
    } else {
        if (*((u8 *)p + 0xda) <= 1) {
            func_0204989C(0x24, 6, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 0;
            n++;
        }
    }
    if (n != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
        func_02041B6C(6);
        if (func_0217F1E8((u8 *)p) == 1) {
            func_0217F240((u8 *)p, 1);
        }
    }
}

/*
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
void func_0217EF44(u8 *p)
{
    func_020120F4(((struct Obj03092 *)p)->f0);
    func_02012138(((struct Obj03092 *)p)->f0);
    if (p[0xd8] != p[0x105]) func_0217EF70((int *)p, p[0xd8]);
}


void func_0217EF70(int *p, int x)
{
    func_020413B0(7, 0, 2, 0x20, 0x10, (u8)(x + 5));
    func_020413B0(6, 0, 2, 0x20, 0x10, (u8)(x + 1));
    if (p[0x44 / 4] != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
    }
    func_02041B6C(7);
    func_02041B6C(6);
    *((u8 *)p + 0x105) = x;
}

/*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 */
void func_0217EFCC(char *p, char *q)
{
    State *s;
    void *h;
    s = (State *)(p + 0xd8);
    h = func_020120F4(((struct Obj00399 *)p)->f0);
    if (q == 0) {
        s->a = func_02012B58(h);
        s->b = 1 << s->a;
        s->c = 1;
        s->d = 0;
        s->e = 0;
        s->f = 0;
    } else {
        func_0217F008(p, q);
    }
}


void func_0217F008(char *p, char *q)
{
    O *o;
    int h;
    int n;
    int i;

    o = (O *)(p + 0xd8);
    h = (int)func_020120F4((const struct Ctx *)(*(int *)&((struct Obj00399 *)p)->f0));
    if (q == 0) {
        func_02082BCC(p + 0xd8, 0, 0x14);
        *(p + 0x11e) = 1;
        return;
    }
    n = func_02012B58((const struct BigObj *)h);
    o->a = ((Bf *)(q + 0x86))->lo;
    o->b = ((struct Obj12492 *)q)->f8FB;
    o->c = func_02080D24(o->b);
    o->d = ((struct Obj12492 *)q)->f910;
    o->e = func_0217F5A0(q + 0x1ac);
    o->f = func_021758C8((u8 *)(q + 0x1ac));
    o->g = (T *)func_02175B34((u8 *)(q + 0x1ac));
    if (o->g != 0) {
        o->h = ((Bf *)(q + o->g->idx * 0x1c + 0xa2))->lo;
    }
    o->i = func_0217C070((u8 *)q);
    o->j = 0;
    for (i = 0; i < 3; i++) {
        if (i != n && o->a == ((Bf *)(q + i * 0x1c + 0xa2))->lo) {
            o->j = 1;
            return;
        }
    }
}

void func_0217F0C4(u8 *p)
{
    int i;
    p[0x115] = 0;
    p[0x114] = 1;
    for (i = 0; i < 7; i++) func_0204B6F4(((void **)p)[23 + i], 6, 1);
    func_0204B6F4(((void **)p)[31], 6, 1);
}

int func_0217F0FC(u8 *p)
{
    if (p[0x114] == 1 && p[0x115] < 10) return 1;
    return 0;
}


void func_0217F118(Ov018Sel *p, int n)
{
    u8 c;

    c = p->f11B;
    if (c != n && p->f114 != 1) {
        if (c < 8) {
            func_0204B6F4(p->tbl[c], 6, 1);
        } else if (c == 8) {
            func_0204B6F4(p->tbl[8], 6, 1);
        }
        if (n < 8) {
            func_0204B6F4(p->tbl[n], 8, 1);
        } else if (n == 8) {
            func_0204B6F4(p->tbl[8], 8, 1);
        }
        p->f11B = n;
        p->f118 = 0;
        p->f11A = 0;
    }
}

void func_0217F174(u8 *p)
{
    p[0x117] = 0;
    p[0x116] = 1;
    func_0204B6F4(((struct Obj09396 *)p)->f9C, 6, 1);
}


void func_0217F194(Ov018Blink *p)
{
    int t;

    if (p->f116 != 0) {
        t = p->f117;
        if (t % 2 == 0) {
            func_0204B6F4(p->f9C, (u8)(((unsigned)t >> 1) & 1 ? 6 : 7), (int)1);
        }
        if (p->f117 < 10) {
            p->f117++;
        }
    }
}
