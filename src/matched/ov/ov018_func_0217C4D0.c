/*
 * function: func_0217C4D0
 * address:  0x0217C4D0
 * packet:   pkt_ov018_0217C4D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback registered by func_0217C458 (0x88-byte work, state word
 * in the second argument).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F528  0x0217F528  thumb  ov018
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F574  0x0217F574  thumb  ov018
 *   func_02029830  0x02029830  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0217F58C  0x0217F58C  thumb  ov018
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0217C658  0x0217C658  thumb  ov018
 *   func_0217C688  0x0217C688  thumb  ov018
 *   func_02173FC0  0x02173FC0  thumb  ov011
 *   func_02175A24  0x02175A24  thumb  ov011
 *   func_0217F318  0x0217F318  thumb  ov018
 *   func_02174E14  0x02174E14  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    int f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec;

typedef struct {
    u32 lo : 4;
    u32 mid : 14;
    u32 hi : 11;
    u32 top : 3;
} Bits;

typedef struct {
    u8 mask : 3;
    u8 rest : 5;
} Mask;

typedef struct {
    int f00;
    Bits f04;
    Mask f08;
    u8 pad09;
    u16 f0A[3];
    u8 f10[8];
    u8 f18[0x1C];
} Info;

typedef struct {
    u16 f00;
    int f04;
    u8 f08[0x30];
    Info f38;
    Rec f6C;
    u8 f84;
} Work;

struct Ctx;
struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern u8 *func_02158344(void *);
extern void func_0217F528(void *, void *, int, int, int, int);
extern void func_021762D8(Info *, void *, int, u16);
extern void func_0217F574(void *, u16, int, int);
extern void *func_02029830(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02005F38(void);
extern void *func_02029620(void *a, u16 b, u16 c);
extern void func_0217F58C(void *);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B58(void *);
extern void func_0217C658(Rec *, void *, int, u16, u8, u8);
extern int func_0217C688(Rec *, void *);
extern int func_02173FC0(u8 *, u8 *);
extern int func_02175A24(u8 *);
extern void func_0217F318(void *);
extern void func_02174E14(u8 *, int);

int func_0217C4D0(void *task, int *state, Work *w)
{
    void *sys;
    u8 *peer;
    u16 hi;
    u8 t;

    sys = func_020124E4(task);
    peer = func_02158344((void *)func_02012138(sys));
    if (peer == 0 && *state == 0)
        *state = 8;

    switch (*state) {
    case 0:
        if (w->f84 == 0) {
            *state = 4;
            break;
        }
        func_0217F528(w->f08, sys, 1, 1, 0x1E, 0x10);
        func_021762D8(&w->f38, w->f38.f18, *(int *)w->f08, w->f00);
        hi = w->f38.f04.hi;
        func_0217F574(w->f08, w->f38.f04.lo, 8, 0);
        func_0217F574(w->f08, hi, 8, 0x10);
        (*state)++;
        break;
    case 1:
        func_02012374(task, func_02029830(sys, 0x52B));
        (*state)++;
        break;
    case 2:
        if (func_02005F38() == 0) {
            func_02012374(task, func_02029620(sys, 0, 6));
            (*state)++;
        }
        break;
    case 3:
        func_0217F58C(w->f08);
        (*state)++;
        break;
    case 4:
        t = func_02012B58(func_020120F4(sys));
        func_0217C658(&w->f6C, sys, w->f04, w->f38.f0A[t], w->f38.f10[t],
                      w->f38.f08.mask & (1 << t));
        (*state)++;
        break;
    case 5:
        if (func_0217C688(&w->f6C, peer) == 1)
            (*state)++;
        break;
    case 6:
        if (peer != 0) {
            if (func_02173FC0(peer, peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (peer != 0) {
            if (func_02175A24(peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        func_0217F318(w->f08);
        if (peer != 0)
            func_02174E14(peer, 0);
        return 1;
    }
    return 0;
}
