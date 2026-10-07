/*
 * file:     intrude_subdisp_p02.c
 * unit:     yes
 * function: func_0217CA84, func_0217CAFC, func_0217CDBC, func_0217CDD0, func_0217CE08
 * address:  0x0217CA84
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
 *   func_02012138  0x02012138  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217C094  0x0217C094  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0217CA40  0x0217CA40  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_0202648C  0x0202648C  thumb
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217C658  0x0217C658  thumb  ov018
 *   func_0217C688  0x0217C688  thumb  ov018
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb  ov021
 *   func_02026484  0x02026484  thumb
 *   func_020264F4  0x020264F4  thumb
 *   func_02185214  0x02185214  thumb  ov020
 *   func_02012B70  0x02012B70  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217BED4  0x0217BED4  thumb  ov018
 *   func_02185140  0x02185140  thumb  ov020
 *   func_02185588  0x02185588  thumb  ov020
 */
struct Ctx;
struct Desc;
struct Obj;
struct Comm;
struct Rec;
struct BigObj;
struct Evt;
struct Fx;
struct Obj2;
struct Obj00020;
typedef struct {
    unsigned char pad00[0x20];
    int f20;
    int f24;
} Ov018Work_0217CA84;

typedef unsigned int   u32;

typedef unsigned short u16;

/* 0x28-byte task work, allocated by func_0217CA84 through func_020122C0 */
typedef struct {
    void *f00;
    void *f04;
    unsigned char f08[0x18];
    int f20;
    int f24;
} Ov018Work_0217CAFC;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct { int x, y, z; } V12;

unsigned int func_02012138(const struct Ctx *);
struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
void *func_020124E8(struct Obj *p);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
u32 func_0202647C(void *obj);
u32 func_02012204(const struct Ctx *p);
void func_020061E4(u32 a);
void func_0217C094(unsigned char *);
void *func_020124E4(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
void *func_0217CA40(int a0);
void func_02012374(struct Evt *evt, struct Evt **out);
u32 func_0200FB24(void);
u32 func_02026460(void *obj);
void func_02026400(struct Comm *p);
u32 func_02012114(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
int func_02188BE8(void *);
u32 func_02188C54(u8 *p);
int func_021904B0(u32 a, u32 b);
struct Obj2 *func_02190F64(struct Fx *a, u32 b);
u32 func_0202648C(void *obj);
void func_02190E74(u32 *p, u32 b, u32 c, u32 d);
void *func_02029830(void *a, u32 b);
int func_02005F38(void);
void *func_02029620(void *a, u32 b, u32 c);
u32 func_02190EF0(u32 *p);
u32 func_020362DC(void);
int func_02190E40(u32 a);
u32 func_02045C04(struct Rec *rec);
void *func_02188CB4(struct Obj00020 *p);
int func_021A3238(u8 *p);
void func_0217C658(void *, void *, void *, int, int, int);
int func_0217C688(void *, int);
u32 func_0201296C(const struct BigObj *p);
u32 func_020142E8(void *bitmap, s32 id);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
u8 func_02012B58(const struct BigObj *p);
u8 func_0201212C(const struct Ctx *p);
int func_021C06CC(void *, void *);
void func_02026484(void *);
void func_020264F4(u8 *p);
void *func_02185214(void *a);
extern int func_02012B70(const struct BigObj *p);
extern int func_02158344(int a0);
extern int func_0217BED4();
extern void *func_02185140();
extern void *func_02185588();
int func_0217CA84(void *a, int b);
int func_0217CAFC(void *a, int *seq, Ov018Work_0217CAFC *work);
void *func_0217CDBC(void *p);
int func_0217CDD0(void *p, int *state);
void *func_0217CE08(void *a0, void *a1, int a2, int a3);


int func_0217CA84(void *a, int b)
{
    void *sys;
    int ret;
    Ov018Work_0217CA84 *work;
    unsigned char *x;

    sys = (void *)func_02012138(a);
    ret = (int)func_020122C0(a, 0, func_0217CAFC, 0x28);
    work = func_020124E8((struct Obj *)ret);
    work->f20 = b;
    if (func_02026454(sys) == 2) {
        x = (unsigned char *)func_02026474(sys);
        if (x != 0) {
            func_0217C094((unsigned char *)func_02026474(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (func_02012204(a) == 1) {
        if (func_0202647C(sys) == 1) {
            work->f24 = 1;
        }
    }
    func_020061E4(0x737);
    return ret;
}


int func_0217CAFC(void *a, int *seq, Ov018Work_0217CAFC *work)
{
    void *x;
    void *s2;
    void *s1;
    void *y;
    void *z;
    void *t;
    int flag;
    int msg;
    int v;
    int r;

    x = func_020124E4(a);
    s2 = func_020120F4(x);
    s1 = (void *)func_02012138(x);
    switch (*seq) {
    case 0:
        func_02012374(a, (struct Evt **)func_0217CA40((int)x));
        (*seq)++;
        break;
    case 1:
        if (func_0200FB24() == 0 && (int)func_02026460(s1) != 0) {
            break;
        }
        if (func_0200FB24() == 0 && ((int)func_02026454(s1) == 2 || (int)func_02026454(s1) == 1)) {
            func_02026400(s1);
        }
        (*seq)++;
        break;
    case 2:
        if (func_0200FB24() == 0 && (int)func_02026454(s1) != 0) {
            break;
        }
        if (work->f24 == 1) {
            *seq = 7;
        } else {
            (*seq)++;
        }
        break;
    case 3:
        if (func_02012114(x) != 1) {
            break;
        }
        flag = 0;
        y = func_0201210C(x);
        if (func_02188BE8(y) != 1) {
            break;
        }
        z = (void *)func_02188C54(y);
        work->f00 = t = (void *)func_021904B0((u32)z, 0x2D);
        work->f04 = func_02190F64(z, (u32)t);
        switch (work->f20) {
        case 1:
        case 2:
            msg = 0x5C;
            goto set;
        default:
            msg = 0x59;
        set:
            flag = 1;
            break;
        case 0:
            switch ((int)func_0202648C(s1)) {
            case 1:
                msg = 0x5A;
                break;
            case 2:
                msg = 0x56;
                break;
            case 3:
                msg = 0x57;
                flag = 1;
                break;
            case 4:
                msg = 0x58;
                flag = 1;
                break;
            case 0:
            case 5:
            default:
                msg = 0x59;
                break;
            }
            break;
        }
        func_02190E74(work->f04, (int)0, (int)0, (int)msg);
        if (flag == 1) {
            func_02012374(a, func_02029830(x, 0x52D));
            *seq = 4;
        } else {
            *seq = 5;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(x, 0, 6));
            *seq = 5;
        }
        break;
    case 5:
        if ((int)func_02190EF0(work->f04) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_02190E40((u32)work->f04);
            func_02045C04(work->f00);
            (*seq)++;
        }
        break;
    case 7:
        y = func_0201210C(x);
        if (func_02188BE8(y) == 1) {
            if (func_021A3238(func_02188CB4(y)) == 0) {
                func_0217C658(work->f08, x, y, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 10;
            }
        }
        break;
    case 8:
        if (func_0217C688(work->f08, 0) == 1) {
            if (work->f24 == 1) {
                *seq = 10;
            } else {
                (*seq)++;
            }
        }
        break;
    case 9:
        if ((int)func_020142E8((void *)func_0201296C(s2), 0x980) == 0) {
            r = (int)func_0202648C(s1);
            v = 0;
            switch (r) {
            case 0:
            case 1:
                break;
            case 2:
                v = 0xC;
                break;
            case 3:
            case 4:
                v = 0xD;
                break;
            case 5:
                break;
            }
            func_02158780(a, (u16)v, 0, 0, (int)0x8015);
        }
        *seq = 10;
        break;
    case 10:
        if ((func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) && func_0201212C(x) == 1) {
            func_02012374(a, (struct Evt **)func_021C06CC(x, func_0201210C(x)));
        }
        (*seq)++;
        break;
    case 11:
        func_02026484(s1);
        func_020264F4(s1);
        if (func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) {
            func_02012374(a, func_02185214(x));
        }
        (*seq)++;
        break;
    case 12:
        return 1;
    }
    return 0;
}

void *func_0217CDBC(void *p)
{
    return func_020122C0(p, 0, func_0217CDD0, 0);
}

int func_0217CDD0(void *p, int *state)
{
    switch (*state) {
    case 0:
        func_02158780(p, 0x279e, 0, 0, 0x15);
        ++*state;
        break;
    case 1:
        return 1;
    }
    return 0;
}


void *func_0217CE08(void *a0, void *a1, int a2, int a3)
{
    int h;
    void *c;
    V12 v;

    h = func_02012138(a0);
    c = func_020120F4(a0);
    func_02158344(h);
    if (func_0217BED4(a2, &v) == 0)
        return 0;
    if (func_02012B70(c) == 0 && a2 == 0x117)
        return func_02185140(a0, a2, &v, a3);
    return func_02185588(a0, a2, &v);
}
