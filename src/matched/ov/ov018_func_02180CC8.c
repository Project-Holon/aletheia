/*
 * function: func_02180CC8
 * address:  0x02180CC8
 * packet:   pkt_ov018_02180CC8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of func_02182AA4: a 7-state sequence driving
 * the Ov018Obj at +0x10; state 2 pushes an ov083 child task.
 *
 * symbols:
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
 *   func_0217F318  0x0217F318  thumb
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_021F5260  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   d_02183852     0x02183852  data   a2
 *   d_0218385C     0x0218385C  data   a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
    u8 f78[0xA0 - 0x78]; /* 0x78 */
    int fA0;            /* 0xA0 */
} Outer;

typedef struct {
    u32 a;
    u32 zero;
} Args;

extern u8 ov083_id[];
extern u16 d_02183852[];
extern u16 d_0218385C[];

typedef signed int     s32;
struct Ctx;
struct Evt;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217F318(Ov018Obj *p);
void func_0217F2B4(Ov018Obj *p, void *sub);
void *func_020124AC(void *h, u32 n, u32 (*fn)(void *, u32), Args *a);
void func_02012374(struct Evt *evt, struct Evt **out);
void func_0217FE38(int v, Outer *c);
u32 func_021F5260(void *, u32);

int func_02180CC8(void *a, int *state, Outer *c)
{
    void *sub;
    int v;
    Args args;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        c->fA0 = c->f42;
        func_0217F3C4(&c->obj, d_02183852[c->fA0]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        func_02012374(a, func_020124AC(sub, (u32)ov083_id, func_021F5260, &args));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217F2B4(&c->obj, sub);
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218385C[c->fA0]);
        (*state)++;
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_0217F420() == 1) {
            (*state)++;
        }
        break;
    case 6:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}
