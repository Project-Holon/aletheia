/*
 * function: func_021A7F38
 * address:  0x021A7F38
 * packet:   pkt_ov021_021A7F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback installed by func_021A7E3C: steps through the Work step
 * table like func_021A7CE8, returning 0x21 to run again in the same frame
 * when w->f38 is set, 1 when the last step finishes, 0 otherwise.
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021BDCC8  0x021BDCC8  thumb  ov021
 *   func_021BDD20  0x021BDD20  thumb  ov021
 *   func_021A8278  0x021A8278  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BDD40  0x021BDD40  thumb  ov021
 *   func_021BDD48  0x021BDD48  thumb  ov021
 *   func_021A8244  0x021A8244  thumb  ov021
 *   func_021A7B10  0x021A7B10  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_021A834C  0x021A834C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A8324  0x021A8324  thumb  ov021
 *   func_021BDD34  0x021BDD34  thumb  ov021
 *   func_021BDCB8  0x021BDCB8  thumb  ov021
 *   func_021A8234  0x021A8234  thumb  ov021
 *   func_021A81EC  0x021A81EC  thumb  ov021
 *   func_021A8200  0x021A8200  thumb  ov021
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
    u8 pad18[0x20 - 0x18];
    u16 f20;
    u8 pad22[0x45 - 0x22];
    u8 f45;
    u8 pad46[0x48 - 0x46];
    int f48;
} Args;

typedef struct Work {
    Args *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
    u8 pad1A[0x38 - 0x1A];
    int f38;
} Work;

extern unsigned int func_02188D38(u8 *p);
extern void func_021BDCC8(char *a, int *b);
extern void func_021BDD20(void *p);
extern void func_021A8278(Work *w);
extern int func_021C6E48(void *p);
extern int func_021BDD40(void *p);
typedef unsigned int   u32;
struct Evt;
struct Obj;
extern int func_021BDD48(struct Obj *o);
extern int func_021A8244(u32 a);
extern int func_021A7B10(void *a);
extern void *func_021618E0(void *a, void *o);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern int func_021A834C(Work *w);
extern void func_020061E4(u32 a);
extern void func_021A8324(void *task, Work *w);
extern void func_021BDD34(u8 *p);
extern void func_021BDCB8(u8 *p);
extern void func_021A8234(Work *w);
extern u8 func_021A81EC(Work *w);
extern void func_021A8200(Work *w);

int func_021A7F38(void *task, int *state, Work *w)
{
    Args *a;
    void *a04;
    void *a08;
    void *obj;
    void *w04;
    void *d;

    a = w->f00;
    a04 = a->f04;
    a08 = a->f08;
    obj = a->f0C;
    w04 = w->f04;
    d = (void *)func_02188D38(obj);

    switch (*state) {
    case 0:
        func_021BDCC8(w->f08, (int *)w->f0C);
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 1:
        func_021BDD20(w->f08);
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 3:
        func_021A8278(w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 2:
        if (func_021C6E48(d) == 0) {
            break;
        }
        if (func_021BDD40(w->f08) != 0 && func_021BDD48(w->f08) != 0) {
            *state = 9;
        } else {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 4:
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC(w);
            func_021A8200(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 9:
        if (w->f18++ > 15) {
            *state = func_021A81EC(w);
            func_021A8200(w);
            if (w->f38 != 0) {
                return 0x21;
            }
        }
        break;
    case 5:
        func_021A7B10(obj);
        func_02012374(task, func_021618E0(a04, obj));
        *state = func_021A81EC(w);
        func_021A8200(w);
        if (w->f38 != 0) {
            return 0x21;
        }
        break;
    case 6:
        func_02029D44((u32)w04, (u32)a08, a->f20, a->f45);
        a->f48 = 1;
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 7:
        if (func_021A834C(w) != 0) {
            func_020061E4(0x559);
        }
        func_021A8324(task, w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 8:
        func_021BDD34(w->f08);
        func_021BDCB8(w->f08);
        func_021A8234(w);
        return 1;
    }
    return 0;
}
