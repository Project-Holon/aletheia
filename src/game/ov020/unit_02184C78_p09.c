/*
 * file:     unit_02184C78_p09.c
 * unit:     yes
 * function: func_02185C8C, func_02185D38
 * address:  0x02185C8C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_021BE9F0  0x021BE9F0  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_02158630  0x02158630  thumb  ov010
 *   func_021D2750  0x021D2750  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026484  0x02026484  thumb
 *   func_0217574C  0x0217574C  thumb  ov011
 *   func_02175710  0x02175710  thumb  ov011
 *   func_02175B4C  0x02175B4C  thumb  ov011
 *   func_02012B78  0x02012B78  thumb
 *   func_02039338  0x02039338  arm
 *   func_02012B64  0x02012B64  thumb
 *   func_02185C4C  0x02185C4C  thumb  ov020
 */
struct Desc;
struct Obj;
struct Ctx;
struct Evt;
struct Comm;
struct BigObj;
typedef struct { int f[7]; } S7;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u8 pad00[0x1c];
    int f1c;
    int f20;
    int f24;
    int f28;
    u8 b2c;
} Ctx;

void func_020061E4(u32 a);
int func_02189A08(unsigned char *p);
void func_021CF498(struct Ctx *c, u32 x, int idx);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02184CEC(void **o, void *p);
int func_02184504(int a, int *state, u8 *p);
void func_02012374(struct Evt *evt, struct Evt **out);
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4);
extern unsigned int func_02012138(const struct Ctx *a);
extern int func_02158344(int a0);
extern int func_0217C070(u8 *o);
extern int func_02158630(int h);
extern int func_021D2750(u32 a);
extern u16 func_02188C84(u8 *p);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern int func_02158590(void *p);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void func_02026484(void *obj);
extern void func_0217574C(u8 *o, u32 v);
extern void func_02175710(u8 *o, u32 v);
extern void func_02175B4C(u8 *o, u8 *p);
extern struct BigObj *func_02012B78(struct BigObj *p, u8 v);
extern int func_02039338(int a);
extern void func_02012B64(int a, int b);
extern int func_02185C4C(int a, int b, Ctx *c);
int func_02185C8C(int a0, int *st, int *p);
int func_02185D38(int a0, int *state, Ctx *c);


int func_02185C8C(int a0, int *st, int *p)
{
    int r7 = p[7];
    int r6 = p[9];
    void *h;
    int *n;

    switch (st[0]) {
    case 0:
        func_020061E4(0x773);
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)r6), a0, 0x24);
        st[0]++;
        break;
    case 1:
        h = func_020122C0((void *)r7, 0, func_02184504, 0x9c);
        n = func_020124E8(h);
        func_02184CEC((void **)n, (void *)r7);
        *(S7 *)(n + 4) = *(S7 *)p;
        n[0xb] = 0;
        n[0x10] = 0;
        func_02012374((struct Evt *)a0, h);
        st[0]++;
        break;
    case 2:
        func_02012374((struct Evt *)a0, func_021BE9F0((void *)r7, r6, 0, 0, 2));
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


int func_02185D38(int a0, int *state, Ctx *c)
{
    int r;
    int h;
    int flag;
    int id;
    u8 *obj;

    h = func_02012138((const struct Ctx *)c->f1c);
    switch (*state) {
    case 0:
        obj = (u8 *)func_02158344(h);
        flag = 0;
        r = 0;
        if (obj != 0) {
            r = func_0217C070(obj);
            if (func_02158630(h) == 3)
                flag = 1;
        }
        if (r == 0 && func_021D2750(c->f1c) != 0) {
            id = !flag ? 0x279A : 0x279B;
            func_02158780((void *)a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            if (func_02158590((void *)c->f20) == 0)
                func_02026400((struct Comm *)h);
            *state = 1;
        } else {
            id = !r ? 0x279C : 0x279D;
            func_02158780((void *)a0, id, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
        }
        break;
    case 1:
        if (func_02158590((void *)c->f20) == 0) {
            if (func_02026454((void *)h) != 0)
                break;
            func_02026484((void *)h);
        }
        if (c->f28 == 1 && func_02158630(h) != 3) {
            func_02158780((void *)a0, 0x279F, 0, 0, func_02188C84((u8 *)c->f24));
            *state = 3;
            break;
        }
        obj = (u8 *)func_02158344(h);
        if (obj != 0) {
            func_0217574C(obj, 1);
            func_02175710(obj, c->b2c);
            if (c->f28 == 1)
                func_02175B4C(obj, obj + 0x1AC);
        }
        func_02012B64(c->f20, func_02039338((int)func_02012B78((struct BigObj *)c->f20, 1)));
        func_02012374((struct Evt *)a0, (struct Evt **)func_02185C4C(c->f1c, c->f24, c));
        *state = 2;
        break;
    case 2:
        obj = (u8 *)func_02158344(h);
        if (obj != 0)
            func_0217574C(obj, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}
