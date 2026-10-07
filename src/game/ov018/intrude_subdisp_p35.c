/*
 * file:     intrude_subdisp_p35.c
 * unit:     yes
 * function: func_021820A4, func_02182124, func_02182150
 * address:  0x021820A4
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
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_0217FE38  0x0217FE38  thumb  ov018
 *   d_0218398E     0x0218398E  data   a2
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021821B0  0x021821B0  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */
struct Obj;
struct WordSet;
struct Ctx;
struct Desc;
struct Evt;
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
    u8 pad43[0x78 - 0x43];
    u8 f78[0x98 - 0x78]; /* 0x78 */
} Outer;

typedef unsigned int   u32;

typedef struct { u32 words[13]; } Rec;

void *func_020124E4(struct Obj *p);
unsigned int func_02012138(const struct Ctx *);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217FE38(u8 *v, Outer *c);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern Rec *func_020124E8(void *);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *);
extern void *func_021821B0(void *, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02188BE8(void *a);
extern u32 *func_0216D9E4(void *c);
int func_021820A4(void *a, int *state, Outer *c);
void *func_02182124(void *a, void *unused, Rec *b);
int func_02182150(void *a, int *state, int c);
extern u16 d_0218398E[];


/*
 * Task callback in the shape of func_021809A4: a 4-state sequence driving
 * the Ov018Obj at +0x10.
 */
int func_021820A4(void *a, int *state, Outer *c)
{
    u8 *v;

    v = (u8 *)func_02158344((int)((void *)func_02012138(func_020124E4(a))));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218398E[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}

void *func_02182124(void *a, void *unused, Rec *b) { void *r; r = func_020122C0(a,0,(void *)func_02182150,0x34); *func_020124E8(r) = *b; return r; }


int func_02182150(void *a, int *state, int c)
{
    void *h;
    u8 *r;

    h = func_020124E4(a);
    r = func_0201210C(h);
    switch (*state) {
    case 0:
        func_0216D9A0((void *)func_02188C7C(r));
        func_02012374(a, func_021821B0(h, c));
        (*state)++;
        break;
    case 1:
        if (r != 0 && func_02188BE8(r) == 1) {
            func_0216D9E4((void *)func_02188C7C(r));
            return 1;
        }
        break;
    }
    return 0;
}
