/*
 * file:     intrude_subdisp_p13.c
 * unit:     yes
 * function: func_021821B0, func_02182214, func_0218236C, func_021823A8, func_021825F8, func_0218261C
 * address:  0x021821B0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020084F8  0x020084F8  thumb
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_021745F8  0x021745F8  thumb  ov011
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0217F5F0  0x0217F5F0  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183998     0x02183998  data  a2
 *   func_0201232C 0x0201232C thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021756D0 0x021756D0 thumb ov011
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_02175514  0x02175514  thumb  ov011
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_0217FE38  0x0217FE38  thumb  ov018
 *   d_021839E0     0x021839E0  data  a2
 *   func_02012F08  0x02012F08  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_0217F4C4  0x0217F4C4  thumb  ov018
 *   func_0217F4D8  0x0217F4D8  thumb  ov018
 *   func_0217F508  0x0217F508  thumb  ov018
 *   d_021839A4     0x021839A4  data  a2
 */
struct Ctx;
struct Desc;
struct Obj;
struct S0201235C;
struct WordSet;
struct BigObj;
struct Outer_021821B0;
struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[0x30];
    u8 f30[8];
    u8 pad38[8];
    u16 f40;
    u8 f42;
    u8 pad43;
    u16 f44;
} Task;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 f16;
    u8 pad18[0x28 - 0x18];
    u8 f28;
} Src;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    Ov018Obj obj;       /* 0x00 */
    u8 f30[0x40 - 0x30]; /* 0x30 */
    u16 f40;            /* 0x40 */
    u8 pad42[2];
    u16 f44;            /* 0x44 */
    u8 pad46[2];
    int f48;            /* 0x48 */
    int f4C;            /* 0x4C */
    int f50;            /* 0x50 */
} Ov018Work;

typedef struct Outer_021821B0 {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
    int  f9C;
    int  fA0;
} Outer_021821B0;

typedef struct Outer_021825F8 {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
} Outer_021825F8;

extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern void func_0217F2B4(Task *, void *);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
int func_02158344(int a0);
int func_0217405C(char *a, char *b);
int func_02175CF4(char *p, u8 *q);
int func_021745F8(u32 a, u32 b);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EF40(struct WordSet *p, u32 i, u32 v);
u8 func_02012B58(const struct BigObj *p);
int func_0217F5F0(void *, u8);
void func_0217F318(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, u16 a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void *func_021804F8(void *, int);
void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_0201232C(char *p, int a1, int a2);
extern void func_02082D44(void *, void *, int);
extern int func_021756D0(u32 x);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32   func_020362DC(void);
extern int func_02173B9C(int a, int b);
extern void  func_021753B8(u8 *);
extern int   func_02175514(u8 *);
extern int func_0217CA84(void *a, int b);
extern void  func_0217FE38(u8 *, Outer_021821B0 *);
extern void *func_02012F08(int *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_020127B8(void *);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_02173AE0(int a, int b, int c, int d);
extern void func_021763D8(u8 *p, u32 key);
extern void  func_0217F4C4(u8 *);
extern void func_0217F4D8(void **p, int a);
extern int func_0217F508(void **p);
void *func_021821B0(void *a, Src *b);
int func_02182214(void *a, int *state, Ov018Work *c);
void func_0218236C(void *a, void *b);
int func_021823A8(void *a, int *state, Outer_021821B0 *c);
void func_021825F8(void *a, void *b);
int func_0218261C(void *a, int *state, Outer_021825F8 *c);
extern const u16 d_02183998[];
extern const u16 d_021839E0[5][5];
extern const u16 d_021839A4[6][5];




void *func_021821B0(void *a, Src *b)
{
    void *s;
    void *t;
    Task *p;
    u16 *q;
    void *t0;

    t0 = func_020120F4(a);
    q = &b->f14;
    s = func_02012944(t0);
    t = func_020122C0(a, 0, func_02182214, 0x54);
    p = func_020124E8(t);
    func_020084F8(s, (u32)p->f30, 8);
    p->f40 = q[1];
    p->f42 = q[0];
    p->f44 = b->f28;
    func_0217F2B4(p, a);
    return t;
}




int func_02182214(void *a, int *state, Ov018Work *c)
{
    void *sub;
    void *x;
    u8 *v;
    int idx;

    sub = func_020124E4(a);
    v = (u8 *)func_02012138(sub);
    x = func_020120F4(sub);
    func_0201210C(sub);
    v = (u8 *)func_02158344((int)v);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 6);
            *state = 4;
            c->f48 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if ((c->f50 = func_02175CF4((char *)v, v + 0x1AC)) != 0) {
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, func_02012944(x));
        func_0201EF40(c->obj.f00, 1, c->f40);
        if (c->f50 == 1) {
            idx = d_02183998[func_0217F5F0(v, (int)func_02012B58(x))];
            c->f4C = 1;
        } else {
            idx = 5;
        }
        func_0217F3C4(&c->obj, idx);
        (*state)++;
        break;
    case 3:
        if (c->f4C == 1) {
            if (func_021745F8((u8)c->f44, (u32)c->f30) == 1) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *state = 6;
        }
        break;
    case 6:
        func_0217F318(&c->obj);
        func_0201235C(a, func_021804F8(sub, c->f4C));
        return 0;
    }
    return 0;
}



/*
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */
void func_0218236C(void *a, void *b) { u16 *h; func_0201232C(a,(int)((void *)func_021823A8),0xa4); a = func_020124E8(a); func_02082D44(b,a,0x98); h = (u16 *)((u8 *)a+0x58); if (func_021756D0(*h) == 0) *h = 17; }



/*
 * lever: func_021804F8 reads the live r1 as its second argument.
 * The f9C comparison value is forwarded unchanged on the taken arm.
 * Addresses are Black-image addresses.
 */
int func_021823A8(void *a, int *state, Outer_021821B0 *c)
{
    void *sub;
    u8 *v;
    u16 *h;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 4) {
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 0) {
            return 0;
        }
        if (*state < 9) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), 4);
            *state = 9;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        h = c->h58;
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            switch (func_02175514(v)) {
            case 7:
                *state = 2;
                break;
            case 3:
            case 8:
                *state = 5;
                break;
            case 9:
                *state = 6;
                break;
            case 10:
                *state = 7;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    c->fA0 = 1;
                    *state = 8;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[4][c->b42]);
        (*state)++;
        break;
    case 3:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_02175CF4((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            *state = 9;
        }
        break;
    case 5:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[1][c->b42]);
        *state = 9;
        break;
    case 6:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[2][c->b42]);
        *state = 9;
        break;
    case 7:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[3][c->b42]);
        *state = 9;
        break;
    case 8:
        *state = 11;
        break;
    case 9:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            *state = 10;
        }
        break;
    case 10:
        if (func_0217F420() == 1) {
            *state = 11;
        }
        break;
    case 11:
        func_0217FE38(v, (Outer_021821B0 *)c);
        if (c->f9C == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        if (c->fA0 == 0) {
            func_0201235C(a, (u32 *)func_0217CA84(sub, 2));
            return 0;
        }
        func_0201235C(a, (u32 *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}


void func_021825F8(void *a, void *b) { func_0201232C(a,(int)((void *)func_0218261C),0xa4); func_02082D44(b,func_020124E8(a),0x98); }



/*
 * EXACT*: the listing extent runs into two unlabelled 8-byte Thumb
 * followers at 0x021828A8 and 0x021828B0 (ldr r3,[pc,#0]; bx r3 thunks
 * to 0x0218236D and 0x021825F9).
 *
 * Addresses are Black-image addresses.
 */
int func_0218261C(void *a, int *state, Outer_021825F8 *c)
{
    void *sub;
    void *x;
    u8 *v;
    u16 *h;
    void *t;
    int flag;
    int r;

    sub = func_020124E4(a);
    x = func_020120F4(sub);
    t = (void *)func_02012138(sub);
    h = c->h58;
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 0) {
            return 0;
        }
        if (*state < 8 && *state != 2 && *state != 3) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), 4);
            *state = 8;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[1][c->b42]);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            func_0217F4D8((void **)((u8 *)c + 0x10), (int)sub);
            (*state)++;
        }
        break;
    case 3:
        r = func_0217F508((void **)((u8 *)c + 0x10));
        flag = 0;
        switch (r) {
        case 0:
            func_0217F4C4((u8 *)c + 0x10);
            if (h[1] > func_0200C274(func_02012F08(x))) {
                flag = 1;
                *state = 5;
            } else if (func_02007E3C(func_0201292C(x), h[0], 1, 0x15) == 0) {
                flag = 1;
                *state = 6;
            } else {
                *state = 4;
            }
            break;
        case 1:
            func_0217F4C4((u8 *)c + 0x10);
            flag = 1;
            *state = 7;
            break;
        }
        if (flag == 1) {
            func_021763D8(func_020127B8(x), 3);
        }
        break;
    case 4:
        if (func_02173AE0((int)v, v[0x154], 7, v[0x158]) == 1) {
            func_0200C29C(func_02012F08(x), h[1]);
            func_02007E50(func_0201292C(x), h[0], 1, 0x15);
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[5][c->b42]);
            *state = 8;
        }
        break;
    case 5:
        if (func_02173AE0((int)v, v[0x154], 9, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[3][c->b42]);
            *state = 8;
        }
        break;
    case 6:
        if (func_02173AE0((int)v, v[0x154], 10, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[4][c->b42]);
            *state = 8;
        }
        break;
    case 7:
        if (func_02173AE0((int)v, v[0x154], 8, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[2][c->b42]);
            *state = 8;
        }
        break;
    case 8:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if (func_0217F420() == 1) {
            *state = 10;
        }
        break;
    case 10:
        func_0217FE38(v, (Outer_021821B0 *)c);
        return 1;
    }
    return 0;
}
