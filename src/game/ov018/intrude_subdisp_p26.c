/*
 * file:     intrude_subdisp_p26.c
 * unit:     yes
 * function: func_02180FA8, func_02180FCC
 * address:  0x02180FA8
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
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_0217405C  0x0217405C  thumb
 *   func_02175CF4  0x02175CF4  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_021804F8  0x021804F8  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_021838A4     0x021838A4  data  a2
 *   d_021838AE     0x021838AE  data  a2
 */
struct Obj;
struct Ctx;
struct S0201235C;
struct WordSet;
typedef unsigned int u32;

typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

typedef unsigned char u8;

typedef unsigned short u16;

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
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Ov018Outer;

typedef signed int     s32;

extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
int func_0217405C(void *, void *);
int func_02175CF4(void *, void *);
void func_020061E4(u32 a);
void func_0217FE38(void *v, Ov018Outer *c);
void *func_021804F8(void *, int);
void func_0201235C(struct S0201235C *o, u32 *out);
void func_02180FA8(Obj *task, const void *src);
int func_02180FCC(void *a, int *state, Ov018Outer *c);
extern const u16 d_021838A4[];
extern const u16 d_021838AE[];


/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_02180FA8(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180FCC, 0xA0);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}


int func_02180FCC(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 4);
            *state = 4;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4(v, v + 0x1AC) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_021838A4[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_021838AE[c->f42]);
            func_020061E4(0x5E0);
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
        func_0217FE38(v, c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}
