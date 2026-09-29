/*
 * function: func_02181FD8
 * address:  0x02181FD8
 * packet:   pkt_ov018_02181FD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of func_021809A4: a 4-state sequence with an exit that retasks the callback driving
 * the Ov018Obj at +0x10.
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
 *   func_020061E4  0x020061E4  thumb
 *   func_0217CA1C  0x0217CA1C  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 *   d_0218397A     0x0218397A  data   a2
 */

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

extern u16 d_0218397A[];

void *func_020124E4(void *);
void *func_02012138(void *);
u8 *func_02158344(void *);
void func_0201F02C(void *, int, void *);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217FE38(u8 *v, Outer *c);
void func_020061E4(int);
void *func_0217CA1C(void *);
void func_0201235C(void *, void *);

int func_02181FD8(void *a, int *state, Outer *c)
{
    void *h;
    u8 *v;

    h = func_020124E4(a);
    v = func_02158344(func_02012138(h));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218397A[c->f42]);
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
        if (v != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(h));
            return 0;
        }
        return 1;
    }
    return 0;
}
