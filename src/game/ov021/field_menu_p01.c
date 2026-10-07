/*
 * file:     field_menu_p01.c
 * unit:     yes
 * function: func_021A7CE8, func_021A7E3C, func_021A7EB4
 * address:  0x021A7CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_021A80FC  0x021A80FC  thumb  ov021
 *   func_021BDC94  0x021BDC94  thumb  ov021
 *   func_021A811C  0x021A811C  thumb  ov021
 *   func_021A8214  0x021A8214  thumb  ov021
 *   func_02162370  0x02162370  thumb  ov010
 *   func_021A7F38  0x021A7F38  thumb  ov021
 *   func_021A8268  0x021A8268  thumb  ov021
 */
struct Evt;
struct Obj;
struct Src;
struct Desc;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Args_021A7CE8 {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
} Args_021A7CE8;

typedef struct Work_021A7CE8 {
    Args_021A7CE8 *f00;
    void *f04;
    void *f08;
    u8 f0C[0x18 - 0x0C];
    u16 f18;
} Work_021A7CE8;

typedef unsigned int   u32;

typedef struct Work_021A7E3C {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    int f10;
    int f14;
    u16 f18;
    u8 f1A;
    u8 pad1B[0x28 - 0x1B];
    int f28;
    u8 pad2C[0x36 - 0x2C];
    u8 f36;
    u8 pad37;
    int f38;
} Work_021A7E3C;

typedef struct Args_021A7E3C {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
} Args_021A7E3C;

extern void *func_02188C58(void *o);
extern unsigned int func_02188D38(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern void func_02185B88(void *p, unsigned int v);
extern int func_0218F0F8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021BDCC8(char *a, int *b);
extern void func_02029D7C(void *a, void *b);
extern void func_021A82D8(void *a, struct Src **pp);
extern void func_021A8278(Work_021A7CE8 *w);
extern int func_021A8244(u32 a);
extern void *func_021618E0(void *a, void *o);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021BDD40(void *p);
extern int func_021BDD48(struct Obj *o);
extern void func_021A82A8(Work_021A7CE8 *w);
extern void func_021BDD20(void *p);
extern u8 func_021A81EC(Work_021A7CE8 *w);
extern void func_021A8200(Work_021A7CE8 *w);
extern u8 func_021A81DC(u32 a);
extern int func_021C6E48(void *p);
extern void func_021BDD34(u8 *p);
extern int func_0218E160(u32 a);
extern void func_021BDCB8(u8 *p);
extern void func_021A8234(Work_021A7CE8 *w);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_021A80FC(u32 a);
extern void *func_021BDC94(void *p);
extern int func_021A811C(u32 a, u32 b);
extern void func_021A8214(Work_021A7E3C *w);
extern int func_02162370(int a);
extern int func_021A7F38(void *task, int *state, struct Work_021A7E3C *w);
extern int func_021A8268(u32 a);
int func_021A7CE8(void *task, int *state, Work_021A7CE8 *w);
void *func_021A7E3C(Args_021A7E3C *a);
void func_021A7EB4(u8 *p);


/*
 * Step machine over the Work step table: each state either stays or loads
 * the next step (func_021A81EC) and advances the index (func_021A8200).
 * Returns 1 once the current step is 8 and the handle reports done.
 */
int func_021A7CE8(void *task, int *state, Work_021A7CE8 *w)
{
    Args_021A7CE8 *a;
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
    d = (void *)func_02188D38(obj);
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
        func_021BDCC8(w->f08, (int *)w->f0C);
        func_02029D7C(w04, a08);
        func_021A82D8(task, (struct Src **)w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 2:
        func_021A8278(w);
        *state = func_021A81EC(w);
        func_021A8200(w);
        break;
    case 3:
        if (func_021A8244((u32)w) == 1) {
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
        if (func_021A8244((u32)w) == 1) {
            *state = func_021A81EC(w);
            func_021A8200(w);
        }
        break;
    case 8:
        break;
    }

    if (func_021A81DC((u32)w) == 8 && func_021C6E48(d) != 0) {
        func_021BDD34(w->f08);
        func_0218E160((u32)h);
        func_021BDCB8(w->f08);
        func_021A8234(w);
        return 1;
    }
    return 0;
}


void *func_021A7E3C(Args_021A7E3C *a)
{
    void *task;
    Work_021A7E3C *w;

    task = func_020122C0(a->f04, 0, func_021A7F38, 0x3C);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = (void *)func_02012A30(a->f08);
    w->f28 = 0;
    w->f18 = 0;
    w->f1A = func_021A80FC((u32)a->f0C);
    w->f36 = 0;
    w->f08 = func_021BDC94(a->f0C);
    w->f0C = a->f10;
    w->f10 = 0;
    w->f14 = 1;
    func_021A811C((u32)a->f0C, (u32)((u8 *)w + 0x1C));
    func_021A8214(w);
    func_021A7EB4((u8 *)w);
    if (func_02162370((int)a->f10) != 0) {
        w->f38 = 1;
    } else {
        w->f38 = 0;
    }
    return task;
}


void func_021A7EB4(u8 *p)
{
    if (func_021A8268((u32)p) != 0) {
        p[0x2C] = 0;
        p[0x2D] = 3;
        p[0x2E] = 1;
        p[0x2F] = 2;
        p[0x30] = 5;
        p[0x31] = 6;
        p[0x32] = 7;
        p[0x33] = 8;
    } else {
        p[0x2C] = 0;
        p[0x2D] = 1;
        p[0x2E] = 2;
        p[0x2F] = 5;
        p[0x30] = 6;
        p[0x31] = 7;
        p[0x32] = 8;
    }
}
