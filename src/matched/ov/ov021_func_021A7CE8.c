/*
 * function: func_021A7CE8
 * address:  0x021A7CE8
 * packet:   pkt_ov021_021A7CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Step machine over the Work step table: each state either stays or loads
 * the next step (func_021A81EC) and advances the index (func_021A8200).
 * Returns 1 once the current step is 8 and the handle reports done.
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02185B88  0x02185B88  thumb  ov020
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BDCC8  0x021BDCC8  thumb  ov021
 *   func_02029D7C  0x02029D7C  thumb
 *   func_021A82D8  0x021A82D8  thumb  ov021
 *   func_021A8278  0x021A8278  thumb  ov021
 *   func_021A8244  0x021A8244  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_021BDD40  0x021BDD40  thumb  ov021
 *   func_021BDD48  0x021BDD48  thumb  ov021
 *   func_021A82A8  0x021A82A8  thumb  ov021
 *   func_021BDD20  0x021BDD20  thumb  ov021
 *   func_021A81EC  0x021A81EC  thumb  ov021
 *   func_021A8200  0x021A8200  thumb  ov021
 *   func_021A81DC  0x021A81DC  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BDD34  0x021BDD34  thumb  ov021
 *   func_0218E160  0x0218E160  thumb  ov021
 *   func_021BDCB8  0x021BDCB8  thumb  ov021
 *   func_021A8234  0x021A8234  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Args {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
} Work;

extern void *func_02188C58(void *o);
extern void *func_02188D38(void *o);
typedef unsigned int   u32;
struct Evt;
struct Obj;
extern u16 func_02188C9C(u8 *p);
extern void func_02185B88(void *p, unsigned int v);
extern int func_0218F0F8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021BDCC8(void *p, void *q);
extern void func_02029D7C(void *a, void *b);
extern void func_021A82D8(void *a, Work *w);
extern void func_021A8278(Work *w);
extern int func_021A8244(Work *w);
extern void *func_021618E0(void *a, void *o);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BDD40(void *p);
extern int func_021BDD48(struct Obj *o);
extern void func_021A82A8(Work *w);
extern void func_021BDD20(void *p);
extern u8 func_021A81EC(Work *w);
extern void func_021A8200(Work *w);
extern u8 func_021A81DC(Work *w);
extern int func_021C6E48(void *p);
extern void func_021BDD34(u8 *p);
extern void func_0218E160(void *h);
extern void func_021BDCB8(u8 *p);
extern void func_021A8234(Work *w);

int func_021A7CE8(void *task, int *state, Work *w)
{
    Args *a;
    void *a04;
    void *obj;
    void *a08;
    void *w04;
    void *h;
    void *d;

    a = w->f00;
    a04 = a->f04;
    obj = a->f0C;
    a08 = a->f08;
    w04 = w->f04;
    h = func_02188C58(obj);
    d = func_02188D38(obj);
    func_02188C9C(obj);

    switch (*state) {
    case 0:
        func_02185B88(obj, 1);
        if (func_0218F0F8(h) == 0) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        } else {
            func_0218F0A8(h);
            *state = 9;
        }
        break;
    case 9:
        if (func_0218F0E8(h) == 0) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 1:
        func_021BDCC8(w->f08, w->f0C);
        func_02029D7C(w04, a08);
        func_021A82D8(task, w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 2:
        func_021A8278(w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 3:
        if (func_021A8244(w) == 1) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 4:
        func_02185B88(obj, 0);
        func_02012374(task, func_021618E0(a04, obj));
        if (func_021BDD40(w->f08) != 0 && func_021BDD48(w->f08) != 0) {
            *state = 10;
        } else {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 6:
        func_021A82A8(w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 10:
        if (w->f18++ > 15) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 5:
        func_021BDD20(w->f08);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 7:
        if (func_021A8244(w) == 1) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 8:
        break;
    }

    if (func_021A81DC(w) == 8 && func_021C6E48(d) != 0) {
        func_021BDD34(w->f08);
        func_0218E160(h);
        func_021BDCB8(w->f08);
        func_021A8234(w);
        return 1;
    }
    return 0;
}
