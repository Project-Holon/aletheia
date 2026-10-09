/*
 * file:     intrude_subdisp_p02.c
 * unit:     yes
 * function: func_0217CA84, func_0217CAFC, func_0217CDBC, func_0217CDD0, func_0217CE08, func_0217CE6C, func_0217CEE8, func_0217CF0C, func_0217CF68, func_0217CF88, func_0217CFE4, func_0217D160, func_0217D1C0
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
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D324C  0x021D324C  thumb  ov093
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0217BF84 0x0217BF84 thumb ov018
 *   func_0217BBCC  0x0217BBCC  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217BC94  0x0217BC94  thumb  ov018
 *   func_0217C194  0x0217C194  thumb  ov018
 *   func_02030734  0x02030734  arm
 *   func_0217EFCC  0x0217EFCC  thumb  ov018
 *   func_020490F4  0x020490F4  arm
 *   func_0217D624  0x0217D624  thumb  ov018
 *   func_0217D720  0x0217D720  thumb  ov018
 *   func_0217D890  0x0217D890  thumb  ov018
 *   func_0217D918  0x0217D918  thumb  ov018
 *   func_0217DA54  0x0217DA54  thumb  ov018
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0217D5AC  0x0217D5AC  thumb  ov018
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0217EBD8  0x0217EBD8  thumb  ov018
 *   func_0217E638  0x0217E638  thumb  ov018
 *   func_0217DE68  0x0217DE68  thumb  ov018
 *   func_0217E014  0x0217E014  thumb  ov018
 *   func_0217E0F4  0x0217E0F4  thumb  ov018
 *   func_0217E3D0  0x0217E3D0  thumb  ov018
 *   func_0217E4D0  0x0217E4D0  thumb  ov018
 *   func_0217E524  0x0217E524  thumb  ov018
 *   str_02183B14   0x02183B14  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_02082A48  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   func_0217DE44  0x0217DE44  thumb  ov018
 *   func_0217DA90  0x0217DA90  thumb  ov018
 *   func_0217DA18  0x0217DA18  thumb  ov018
 *   func_0217D904  0x0217D904  thumb  ov018
 *   func_0217D870  0x0217D870  thumb  ov018
 *   func_0217D6C8  0x0217D6C8  thumb  ov018
 *   func_0201283C            0x0201283C  thumb
 *   func_0201058C            0x0201058C  thumb
 *   func_0217F008            0x0217F008  thumb  ov018
 *   func_020310C4            0x020310C4  arm
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_02045334            0x02045334  arm
 *   func_020257D0            0x020257D0  thumb
 *   func_0217F0FC            0x0217F0FC  thumb  ov018
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0217EC7C            0x0217EC7C  thumb  ov018
 *   func_0215841C            0x0215841C  thumb  ov010
 *   func_0203D1C0            0x0203D1C0  arm
 *   func_021746AC            0x021746AC  thumb  ov011
 *   func_02158428            0x02158428  thumb  ov010
 *   func_02188CCC            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 */
#include "../../matched/include/Obj02674.h"
#include "../../matched/include/Obj00703.h"
#include "../../matched/include/Obj00399.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)
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
struct Obj_0217CEE8;
struct State;
struct Rec44;
struct Node;
struct Descriptor;
struct PrintSys;
struct Tcbl;
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

typedef struct { int f0, f4, f8; } Obj_0217CEE8;

typedef struct {
    int f0;
    int f4;
    int f8;
} Obj_0217CF0C;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

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
extern u32 *func_0217BEA8(u16);
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
extern u32 func_02188E30(u8 *p);
extern void func_021D324C();
extern void func_021A0F40(u32 *p, u32 v);
extern void *func_0215A5DC(void *);
extern void func_0217BF84(int a);
extern void func_0217BBCC(int a, int b, char *p);
extern void func_0217BBD8(u8 *a, int b, u8 *c);
extern void func_0217BC94(int a, int n);
extern void func_0217C194();
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_0217EFCC(char *p, char *q);
void *func_020490F4(u32 id, u32 heap);
void func_0217D624(struct State *o);
void func_0217D720(u8 *w, void *bg);
void func_0217D890(u8 *w);
void func_0217D918(u8 *w, void *bg);
void func_0217DA54(void *p, void *bg);
void func_02049238(void *bg);
void func_0203D34C(u32 a, u32 b);
void func_02037174(void);
void *func_020056A0(void (*cb)(void), void *arg, int pri);
void func_0217D5AC(int a0, u8 *p);
u8 *func_020120F8(const struct Ctx *p);
u16 func_02012AC8(const struct Rec44 *p);
void *func_0217EBD8(u8 *p);
void func_0217E638(u8 *w, int);
void func_0217DE68(u8 *w, int);
void func_0217E014(u8 *w, int);
void func_0217E0F4(u8 *w, u8 *, int);
void func_0217E3D0(u8 *w, int, int);
void func_0217E4D0(int *p, int a1);
void func_0217E524(u8 *w, int);
extern void func_02030EAC(struct Node *n);
extern void func_02082A48();
extern u32 func_020307B0(void *p);
extern void func_02037190();
extern void func_0217DE44(void **p);
extern void func_0217DA90(void **p);
extern void func_0217DA18(u32 *p);
extern void func_0217D904(char *p);
extern void func_0217D870();
extern void func_0217D6C8(int *p);
u32 func_0201283C(const struct BigObj *p);
u32 func_0201058C(void *key);
void func_0217F008(char *p, char *q);
void func_020310C4(struct Tcbl *p);
u32 func_0201C4E4(struct PrintSys *ps);
void *func_02045770(struct Descriptor *p);
u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_02045334(struct Descriptor *d);
void func_020257D0(struct Obj *o);
int func_0217F0FC(u8 *w);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
void func_0217EC7C(u8 *p, u8 *w, int q);
u8 func_0215841C(void *p);
u32 func_0203D1C0(u32 index);
int func_021746AC(char *a, int b);
u8 func_02158428(u8 *p);
u32 func_02188CCC(u8 *p);
void func_02034714(const char *expr, u32 line, const char *file);
int func_0217CA84(void *a, int b);
int func_0217CAFC(void *a, int *seq, Ov018Work_0217CAFC *work);
void *func_0217CDBC(void *p);
int func_0217CDD0(void *p, int *state);
void *func_0217CE08(void *a0, void *a1, int a2, int a3);
void *func_0217CE6C(void *a0, void *a1, int a2);
void *func_0217CEE8(void *p, int a, int b);
int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o);
int func_0217CF68(void *unused, void *p);
int func_0217CF88(int a0, int a1);
u8 *func_0217CFE4(void *a);
void func_0217D160(int a0);
void func_0217D1C0(u8 *w, int b);
extern char str_02183B14[];
extern char str_02183B28[];




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




void *func_0217CE6C(void *a0, void *a1, int a2)
{
    u8 *p;
    u32 *q;
    V12 v;
    u16 s;

    p = (u8 *)func_02158344(func_02012138(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = func_0217BEA8(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = (*q << 2) >> 22;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return func_02184D38(a0, (int)a1, s, (const int *)(&v), 0, 0);
}



void *func_0217CEE8(void *p, int a, int b)
{
    void *task;
    int *work;
    task = func_020122C0(p, 0, func_0217CF0C, 12);
    work = func_020124E8(task);
    work[0] = a;
    work[1] = b;
    return task;
}




int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o)
{
    switch (*state) {
    case 0:
        o->f8 += 1;
        if (o->f8 > 15) {
            func_021D324C(func_02188E30((u8 *)o->f0), -16);
            *state += 1;
        }
        break;
    case 1:
        func_021A0F40((u32 *)o->f4, 0);
        *state += 1;
        break;
    case 2:
        func_021D324C(func_02188E30((u8 *)o->f0), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}



int func_0217CF68(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = func_0215A5DC(p);
    obj = func_0201210C(sys);
    func_02012138(sys);
    func_0217BF84((int)obj);
    return 0;
}




int func_0217CF88(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = func_0215A5DC((void *)a1);
    func_020120F4((const struct Ctx *)w);
    c = func_0201210C((void *)w);
    h = func_02012138(w);
    v = 0;
    if (func_02026454((void *)h) == 2)
        v = func_02026474((void *)h);
    if (v != 0) {
        func_0217BBCC((int)c, (int)w, (char *)v);
        func_0217BBD8((u8 *)c, (int)w, (u8 *)v);
    } else {
        func_0217BC94((int)c, 1);
    }
    func_0217C194(c);
    return 0;
}



u8 *func_0217CFE4(void *a)
{
    void *s;
    u8 *w;
    u8 *p;
    void *bg;
    int i;
    int q;
    int k;
    u32 tmp;

    s = (void *)func_02012138(a);
    w = func_02030734(0x70, 0x170, 1, str_02183B14, 0x240);
    ((struct Obj02674 *)w)->f0 = a;
    w[0x105] = 0xFF;
    w[0x11B] = 0xFF;
    w[0x169] = 4;
    w[0x16A] = 4;
    ((struct Obj02674 *)w)->f10A = -1;
    for (i = 0; i < 3; i++) {
        *(u16 *)(w + 0xF0 + i * 8) = 0x1AB;
    }
    p = 0;
    if (func_02026454(s) == 2) {
        p = (u8 *)func_02026474(s);
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        p = 0;
    }
    func_0217EFCC((char *)w, (char *)p);
    w[0x11E] = w[0xDA];
    bg = func_020490F4(0x24, 0x15);
    func_0217D624((struct State *)w);
    func_0217D720(w, bg);
    func_0217D890(w);
    func_0217D918(w, bg);
    func_0217DA54(w, bg);
    func_02049238(bg);
    func_0203D34C(0, 0x15);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    ((struct Obj02674 *)w)->f34 = func_020056A0((void (*)(void))func_0217D5AC, w, 10);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj02674 *)w)->f0));
    k = (int)func_0217EBD8(w);
    func_0217E638(w, q);
    func_0217DE68(w, k);
    func_0217E014(w, k);
    func_0217E0F4(w, (u8 *)func_02158344((int)s), k);
    func_0217E3D0(w, k, q);
    func_0217E4D0((int *)w, k);
    func_0217E524(w, k);
    return w;
}



void func_0217D160(int a0)
{
    func_02030EAC((struct Node *)(((struct Obj00703 *)a0)->f34));
    func_02082A48(0, 0x05000400, 2);
    func_0217DE44((void **)a0);
    func_0217DA90((void **)a0);
    func_0217DA18((u32 *)a0);
    func_0217D904((char *)a0);
    func_0217D870(a0);
    func_0217D6C8((int *)a0);
    func_020307B0((void *)a0);
    func_02037190();
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u16 *)0x04001050 = 0;
}



void func_0217D1C0(u8 *w, int b)
{
    void *s1;
    void *s2;
    u8 *p;
    int q;
    int i;
    int v;
    void *h;

    s1 = (void *)func_02012138(((struct Obj00399 *)w)->f0);
    s2 = func_020120F4(((struct Obj00399 *)w)->f0);
    p = (u8 *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj00399 *)w)->f0));
    func_0201058C((void *)func_0201283C(s2));
    func_02037174();
    if (p == 0 || (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 0)) {
        func_0217F008((char *)w, (char *)p);
    }
    if (w[0x11E] < w[0xDA]) {
        if (func_02012B70(s2) == 1) {
            func_020061E4(0x699);
        }
        w[0x11E] = w[0xDA];
    }
    func_020310C4(((struct Obj00399 *)w)->f20);
    func_0201C4E4(((struct Obj00399 *)w)->f28);
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x48] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f44)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f44);
            w[0x48] = 0;
        }
    }
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x50] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f4C)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f4C);
            w[0x50] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(((struct Obj00399 *)w)->f28, *(void **)(w + 0xB4 + i * 4)) == 0) {
            func_020257D0(*(void **)(w + 0xC0 + i * 4));
        }
    }
    if (b == 0) {
        if (func_0217F0FC(w) == 1 || w[0x116] == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (b == 1) {
        func_0217EC7C(p, w, q);
    }
    if (p != 0 && w[0x106] == 1) {
        v = func_0215841C(s2);
        if ((int)func_0203D1C0((u8)v) == 0) {
            w[0x106] = 0;
            return;
        }
        switch (w[0x107]) {
        case 0:
            if (func_021746AC((char *)p, (u8)v) == 1) {
                w[0x107]++;
            }
            break;
        case 1:
            if (func_02158428(p) == 1) {
                func_02188CCC(func_0201210C(((struct Obj00399 *)w)->f0));
                ((struct Obj00399 *)w)->f110 = 0x126;
                w[0x112] = 1;
                w[0x106] = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
            break;
        }
    }
}
