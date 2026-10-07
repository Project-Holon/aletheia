/*
 * file:     intrude_subdisp_p01.c
 * unit:     yes
 * function: func_0217C758, func_0217C820, func_0217C914, func_0217CA1C, func_0217CA40
 * address:  0x0217C758
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   d_02183AF0     0x02183AF0  data  a4
 *   g_02183AF0     0x02183AF0  data  a4
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F37B8  0x021F37B8  thumb  ov060
 *   func_020061E4  0x020061E4  thumb
 *   func_021F37D8  0x021F37D8  thumb  ov060
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_02173A2C  0x02173A2C  thumb  ov011
 *   func_02175514  0x02175514  thumb  ov011
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_0217BED4 0x0217BED4 thumb ov018
 *   func_02185588 0x02185588 thumb ov020
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175710  0x02175710  thumb  ov011
 */
#include "../../matched/include/G_Tmpl.h"

struct BigObj;
struct Ctx;
struct Obj00020;
struct VecFx32;
struct T;
struct V3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad04[8];
    u16 fC;
} Tmpl;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct { int x, y, z; } V12;

extern void func_02082BCC(void *, int, int);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_02188C9C(unsigned char *);
extern u16 func_0216D598(void *);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u32 func_0216D8AC(void *p);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void *func_0216CE60(int, Tmpl *, int);
extern void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void func_0216DAC8(unsigned int *, unsigned int);
extern void func_0216D410(void *, u16);
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern void func_021F37B8(int, Vec *);
extern void func_020061E4(u32 a);
extern int func_021F37D8(void *);
extern int func_0216D454(int);
extern int func_0216D480(char *p);
extern void func_0216CF2C(int);
extern void func_0217F3C4(u8 *, int);
extern int func_02173A2C(unsigned char *p, int b, struct T *c, int d);
extern int func_02175514(u8 *);
extern int func_0217F40C(u8 *);
extern u32 func_020362DC(void);
extern int func_02173B9C(int a, int b);
extern void func_021753B8(u8 *);
extern int func_0217F420(void);
extern int func_02173AE0(int a, int b, int c, int d);
extern int func_0217BED4(int, V12 *);
extern void *func_02185588(void *owner, u16 id, const struct V3 *pos);
extern unsigned int func_02012138(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02012B8C(struct BigObj *p, unsigned int v);
extern int func_02158344(int a0);
extern void func_02175710(u8 *o, u32 v);
void func_0217C758(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind, u8 flag, u16 idx, int place);
int func_0217C820(Rec *r);
int func_0217C914(u8 *v, u8 *w, u8 *state);
void *func_0217CA1C(void *p);
void *func_0217CA40(int a0);
extern struct Tmpl d_02183AF0;
extern struct Tmpl g_02183AF0;


/*
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 */
void func_0217C758(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    int sys;
    void *obj;
    int zone;
    int x;
    int y;

    func_02082BCC(r, 0, 0x18);
    r->f0 = a1;
    r->f4 = a2;
    r->fC = id;
    r->fE = kind;
    r->fF = flag;
    r->fA = 15;
    r->f8 = r->fA;
    r->f13 = idx;
    if (place != 0) {
        sys = func_02012964(func_020120F4(a1));
        obj = func_021A3074(func_02188CB4(a2));
        zone = func_02188C9C(a2);
        d_02183AF0.f2 = func_0216D598(obj);
        d_02183AF0.fC = idx;
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216E618(((Tmpl *)&g_02183AF0), x, y, func_0216D8AC(obj));
        r->f14 = func_0216CE60(sys, ((Tmpl *)&g_02183AF0), zone);
        func_0217BCDC(a3, r->f0, r->fC, r->fE, r->fF);
        func_0216DAC8(obj, 1);
        func_0216DAC8(r->f14, 0);
    }
}


/*
 * Per-frame step of the 0x18-byte record (same layout as func_0217C688's).
 */
int func_0217C820(Rec *r)
{
    void *fld;
    void *obj;
    u16 anim;
    Vec v;

    fld = func_02188CB4(r->f4);
    obj = func_021A3074((void *)fld);
    switch (r->f10) {
    case 0:
        anim = r->f13 == 3 ? 7 : 6;
        func_0216D410(obj, anim);
        if (r->f14 != 0)
            func_0216D410(r->f14, anim);
        func_021A3038(fld, (struct VecFx32 *)&v);
        if (r->f13 == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        func_021F37B8((int)r->f4, &v);
        func_020061E4(0x774);
        r->f10++;
        break;
    case 1:
        r->fA--;
        if (r->fA <= 0) {
            if (r->f14 != 0) {
                func_0216DAC8(obj, 0);
                func_0216DAC8(r->f14, 1);
            }
            r->f10++;
        }
        break;
    case 2:
        if (func_021F37D8(r->f4) == 0 && func_0216D454((int)obj) == 1) {
            func_0216D480(obj);
            if (r->f14 != 0)
                func_0216D480(r->f14);
            r->f10++;
        }
        break;
    case 3:
        if (r->f14 != 0) {
            func_0216CF2C((int)r->f14);
            r->f14 = 0;
        }
        return 1;
    }
    return 0;
}


int func_0217C914(u8 *v, u8 *w, u8 *state)
{
    switch (*state) {
    case 0:
        func_0217F3C4(w + 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (func_02173A2C(v, v[0x154], (struct T *)(w + 0x44), w[0x41]) == 1)
            (*state)++;
        break;
    case 2:
        switch (func_02175514(v)) {
        case 1:
            *state = 6;
            break;
        case 2:
        case 3:
            *state = 3;
            break;
        default:
            if (func_0217F40C(w + 0x10) == 1) {
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (func_0217F40C(w + 0x10) == 1) {
            func_0217F3C4(w + 0x10, 2);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(w + 0x10) == 1)
            (*state)++;
        break;
    case 5:
        if (func_0217F420() == 1)
            *state = 8;
        break;
    case 6:
        if (func_02173AE0((int)v, v[0x154], 1, v[0x158]) == 1)
            *state = 7;
        break;
    case 7:
        if (func_0217F40C(w + 0x10) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}

void *func_0217CA1C(void *p)
{
    V12 v;
    func_0217BED4(0x117, &v);
    return func_02185588(p, 0x117, (const struct V3 *)(&v));
}


void *func_0217CA40(int a0)
{
    int h;
    void *c;
    int p;

    h = func_02012138((const struct Ctx *)a0);
    c = func_020120F4((const struct Ctx *)a0);
    p = func_02158344(h);
    if (p != 0) {
        func_02175710((u8 *)p, func_02012B58(c));
    } else {
        func_02012B8C(c, func_02012B58(c));
    }
    return func_0217CA1C((void *)a0);
}
