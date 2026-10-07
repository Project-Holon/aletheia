/*
 * file:     scrcmd_screeneffects_p17.c
 * unit:     yes
 * function: func_021B0000, func_021B0084, func_021B010C, func_021B0130, func_021B015C, func_021B01B8, func_021B01DC, func_021B024C, func_021B02C8, func_021B0344, func_021B0394, func_021B03BC, func_021B03E4, func_021B0480, func_021B04C0, func_021B04D8, func_021B0530
 * address:  0x021B0000
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184DE8  0x02184DE8  thumb  ov020
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A864  0x0215A864  thumb  ov010
 *   func_0215A990  0x0215A990  thumb  ov010
 *   func_0215A954  0x0215A954  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0215A77C  0x0215A77C  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A654  0x0215A654  thumb  ov010
 *   func_02190FA0  0x02190FA0  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02191008  0x02191008  thumb  ov021
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_021910C0  0x021910C0  thumb  ov021
 *   func_021B162C  0x021B162C  thumb  ov021
 *   func_02191084  0x02191084  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02191184  0x02191184  thumb  ov021
 */
struct Ctx;
struct Evt;
struct Stream;
struct Handle;
struct Desc;
struct Obj;
struct U16Vec;
struct P;
struct Fx;
struct Obj2;
struct MsgBank;
struct Q;
struct WordSet;
typedef unsigned short u16;

typedef short          s16_021B0000;

typedef struct { u16 f0; u16 f2; s16_021B0000 f4; u16 f6; } Q;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    u32 a0;
    u16 *flag;
    u32 h;
} Ctx_021B0084;

typedef signed short   s16_021B010C;

typedef signed char    s8;

typedef signed short   s16_021B0130;

typedef struct {
    int h;
    int flag;
} Ctx_021B015C;

typedef signed short   s16_021B01B8;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx_021B01DC;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx_021B024C;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx_021B02C8;

typedef signed short   s16_021B0394;

typedef signed short   s16_021B03BC;

typedef signed short   s16_021B04C0;

extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02011330(struct Stream *s);
extern unsigned int func_02012104(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02188C5C(u8 *p);
extern int func_021BB3E8();
extern void *func_02184DE8(void *p, void *unused, int a, const Q *q, int s, int t);
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern void *func_0215A5DC(void *a0);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void func_0215897C(void *vm, void *task);
extern void func_0215A864(int *p);
extern int func_0215A990(u8 *a);
extern int func_0215A954(u8 *a);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern void *func_02158F74(void *p);
extern u32 func_0215A77C(u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_0215A60C(u8 *p);
extern u32 func_02158F78(u8 *p);
extern u32 func_02158F7C(u8 *p);
extern void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);
extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern void func_02191164(struct P *p);
extern int func_02158F58(int a0);
extern u32 func_0215A654(u8 *p);
extern struct Obj2 *func_02190FA0(struct Fx *a, u32 b, u32 c);
extern void func_0215A660(u8 *p, u32 v);
extern void func_0215A614(u8 *p, u32 v);
extern void func_02159144(int n);
extern int func_02191008(u32 a);
extern u32 func_0215A630(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_0215A624(u8 *p, u32 v);
extern void func_02159168(int n);
extern u32 func_021910C0(u32 *p);
extern u32 func_021B162C(u32 a, u32 b, u32 c);
extern void func_02191084(struct P *p, u32 b, u16 c, u32 d);
extern void func_020113D0(char *p, int val);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02191184(struct Q *q, u32 b, int c, u32 d);
int func_021B0000(int a0, int a1);
int func_021B0084(u32 a0, int *st, Ctx_021B0084 *c);
u32 func_021B010C(u32 a, u32 x, u32 y);
int func_021B0130(u32 a, u32 b);
int func_021B015C(int a0, int *st, Ctx_021B015C *c);
u32 func_021B01B8(u32 a, u32 x, u32 y);
int func_021B01DC(Ctx_021B01DC *c, u32 b);
int func_021B024C(Ctx_021B024C *c, u32 b);
int func_021B02C8(Ctx_021B02C8 *c, u32 b);
int func_021B0344(u32 a, u32 b);
int func_021B0394(u32 a, u32 b, u32 c, u32 d);
int func_021B03BC(u32 a, u32 b, u32 c, u32 d);
void func_021B03E4(u32 a, u32 b);
void func_021B0480(u32 a);
int func_021B04C0(u32 a, u32 b, u32 c, u32 d);
int func_021B04D8(u32 a, u32 b);
int func_021B0530(u32 a, u32 b);


int func_021B0000(int a0, int a1)
{
    struct Ctx *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    w = func_02012104(h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374((struct Evt *)w, func_02184DE8(h, a, b, (const Q *)loc, f, 0));
    return 1;
}


/*
 * State 2 is a nested switch on func_02190C78's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */
int func_021B0084(u32 a0, int *st, Ctx_021B0084 *c)
{
    func_0215A5F4((void *)c->a0);
    switch (*st) {
    case 0:
        func_0215A684((int *)c->a0, 8);
        (*st)++;
    case 1:
        if (func_0215A690((char *)c->a0) == 1) {
            c->h = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C(func_0215A5DC((void *)c->a0))), 0);
            (*st)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct Handle *)c->h)) {
        case 0:
            *c->flag = 0;
            (*st)++;
            break;
        case 2:
            break;
        default:
            *c->flag = 1;
            (*st)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)c->h);
        return 1;
    }
    return 0;
}


u32 func_021B010C(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021B0084, 0xc);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}


int func_021B0130(u32 a, u32 b)
{
    u16 *r = func_02159AE8((void *)a, (void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, (void *)func_021B010C((u32)func_0215A5DC((void *)b), b, (u32)r));
    return 1;
}


int func_021B015C(int a0, int *st, Ctx_021B015C *c)
{
    int r;

    switch (*st) {
    case 0:
        func_0215A684((int *)c->h, 8);
        (*st)++;
    case 1:
        if (func_0215A690((char *)c->h) == 1) {
            func_0215A864((int *)c->h);
            (*st)++;
        }
        break;
    case 2:
        if (c->flag != 0)
            r = func_0215A990((u8 *)c->h);
        else
            r = func_0215A954((u8 *)c->h);
        if (r == 1)
            return 1;
        break;
    }
    return 0;
}


u32 func_021B01B8(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021B015C, 8);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}


int func_021B01DC(Ctx_021B01DC *c, u32 b)
{
    u8 *q;
    u32 v0, v1, v2, v3, r;
    void *t0;
    void *t1;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 0, r, (u32)func_02158F74(t0), 0);
    return 1;
}


int func_021B024C(Ctx_021B024C *c, u32 b)
{
    u8 *q;
    u32 v2, r;
    void *t0;
    void *t1;
    u8 v0, v1, v3;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 0, r, (u32)func_02158F74(t0), func_0215A60C((u8 *)b));
    return 1;
}


int func_021B02C8(Ctx_021B02C8 *c, u32 b)
{
    u8 *q;
    u32 v2, r;
    void *t0;
    void *t1;
    u8 v0, v1, v3;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 1, r, (u32)func_02158F74(t0), func_0215A60C((u8 *)b));
    return 1;
}


int func_021B0344(u32 a, u32 b)
{
    u32 x, y, z;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02011330((struct Stream *)a);
    y = func_02011330((struct Stream *)a);
    z = func_02159B10((void *)a, (void *)b);
    func_0215A7F0((short unsigned int *)b, x, y, z, (struct U16Vec *)func_02158F78(t), (void *)func_02158F7C(t));
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0394(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), (void *)func_021B01B8((u32)func_0215A5DC((void *)b), b, 0));
return 1;
}


int func_021B03BC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), (void *)func_021B01B8((u32)func_0215A5DC((void *)b), b, 0));
return 1;
}


void func_021B03E4(u32 a, u32 b)
{
    u32 x, r4, r5;
    u32 *p;

    r5 = 1;
    if (func_02159190(1)) {
        func_02191164((void *)func_0215A61C(a));
        return;
    }
    p = (u32 *)func_02158F58((int)func_0215A5F4((void *)a));
    x = func_0215A60C((u8 *)a);
    r4 = b;
    if (b == 1) {
    } else if (b == 2) {
        r5 = 0x13;
    } else if (b == 0) {
        switch (func_0215A654((u8 *)a)) {
        case 1:
        case 3:
        case 5:
            r4 = r5;
            break;
        case 2:
        case 4:
        case 6:
            r5 = 0x13;
            r4 = 2;
            break;
        case 7:
            r5 = 0x13;
            r4 = 2;
            break;
        default:
            r5 = 0x13;
            r4 = 2;
            break;
        }
    } else {
        r5 = 0x13;
        r4 = 2;
    }
    r5 = (u32)func_02190FA0((struct Fx *)(*p), x, r5);
    func_0215A660((u8 *)a, r4);
    func_0215A614((u8 *)a, r5);
    func_02159144(1);
}


void func_021B0480(u32 a)
{
    u32 t;

    if (func_02159190(1)) {
        func_02191008(func_0215A61C(a));
        t = func_0215A630((u8 *)a);
        if (t) {
            func_0202F038((void *)t);
            func_0215A624((u8 *)a, 0);
        }
        func_0215A614((u8 *)a, 0);
        func_02159168(1);
    }
}


int func_021B04C0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021910C0((u32 *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}


int func_021B04D8(u32 a, u32 b)
{
    u32 x, y;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_021B162C(b, (u32)t, x);
    func_02191084((struct P *)func_0215A61C(b), 0, 0, y);
    func_020113D0((char *)a, (u32)func_021B04C0);
    return 1;
}


int func_021B0530(u32 a, u32 b)
{
    u32 s, x, y, z, w;
    void *t;

    t = func_0215A5F4((void *)b);
    s = func_02158F78(t);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_0215A60C((u8 *)b);
    z = (u32)func_02158F74(t);
    w = func_02158F7C(t);
    func_02045CAC((struct MsgBank *)y, x, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)s, (void *)w);
    y = func_0215A61C(b);
    func_02191164((void *)y);
    func_02191184((struct Q *)y, 0, 0, s);
    return 0;
}
