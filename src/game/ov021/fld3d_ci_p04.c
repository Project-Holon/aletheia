/*
 * file:     fld3d_ci_p04.c
 * unit:     yes
 * function: func_021C1AEC, func_021C1AF4, func_021C1C04, func_021C1C24, func_021C1C4C, func_021C1CB0, func_021C1D18, func_021C1D68, func_021C1DCC, func_021C1E7C
 * address:  0x021C1AEC
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
 *   func_02050BE8  0x02050BE8  arm
 *   func_02030734  0x02030734  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02048A24  0x02048A24  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   d_021DA6E8     0x021DA6E8  data  a4
 *   d_021DA6D0     0x021DA6D0  data  a4
 *   d_021DA6F4     0x021DA6F4  data  a4
 *   d_021DA6DC     0x021DA6DC  data  a4
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   func_02047E88  0x02047E88  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0203038C  0x0203038C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C313C  0x021C313C  thumb  ov021
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 *   func_021C27F4  0x021C27F4  thumb  ov021
 *   func_021C2854  0x021C2854  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   abs_id_4A      0x0000004A  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_021C2D68  0x021C2D68  thumb  ov021
 *   func_021C2CF4  0x021C2CF4  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021C27A4  0x021C27A4  thumb  ov021
 *   func_021C27C0  0x021C27C0  thumb  ov021
 *   func_021C2BD4  0x021C2BD4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C2B1C  0x021C2B1C  thumb  ov021
 *   func_021C2B98  0x021C2B98  thumb  ov021
 *   func_021C2B5C  0x021C2B5C  thumb  ov021
 *   func_021C3198  0x021C3198  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_021C2764  0x021C2764  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_021C2320  0x021C2320  thumb  ov021
 *   func_02030830  0x02030830  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_021C30D4  0x021C30D4  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_021C21B4  0x021C21B4  thumb  ov021
 *   func_021C223C  0x021C223C  thumb  ov021
 *   func_021C22AC  0x021C22AC  thumb  ov021
 *   func_021C3158  0x021C3158  thumb  ov021
 *   func_021C2484  0x021C2484  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0207DD24  0x0207DD24  arm
 *   func_02188C60  0x02188C60  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_02193068  0x02193068  thumb  ov021
 *   func_021BC5D4  0x021BC5D4  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   func_021C27CC  0x021C27CC  thumb  ov021
 *   func_021C27E8  0x021C27E8  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   d_021DA710     0x021DA710  data  ov021  a4
 */
#include "../../matched/include/Obj04272.h"
#include "../../matched/include/Obj03528.h"
#include "../../matched/include/Obj03141.h"
#include "../../matched/include/Obj01213.h"
#include "../../matched/include/Obj04273.h"
#include "../../matched/include/Obj07558.h"
#include "../../matched/include/Obj00576.h"
#include "../../matched/include/Obj06072.h"

struct Rec;
struct Arg;
struct Light;
struct Desc;
struct Obj;
struct Ctx;
struct BigObj;
struct Evt;
struct DispConfig;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef signed char    s8;

typedef volatile unsigned short vu16;

typedef struct { int a, b, c, d; } BgMode;

typedef int (*StepFn)(int a, u8 *p);

extern void func_02050BE8();
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02047CFC(int a, int b, int heap);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 func_02048AC4(void *ptr);
extern void func_02047E54(struct Rec *p);
extern u32 func_020307B0(void *p);
extern u32 func_02047E88(u32, u32, u32, u32);
extern u32 func_0207ADC4(u32);
void func_02048AD0(struct Light *l);
u32 func_020489F4(u8 *a0, int i);
u32 func_02048A00(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
void func_02047A60(void *a0, struct Arg *a1);
u32 func_0203038C(int a);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_021C313C(u32 a, u32 *p);
int func_021C27F4(int a, int *b);
int func_021C2854(int a, char *b);
void *func_020120F4(const struct Ctx *p);
void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
int func_02034AC4(signed int id);
void func_02034A5C(int id);
int *func_021F54E0(int a);
int func_021C2D68(int a, int *b);
int func_021C2CF4(void *a, u8 *p);
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *o);
extern void func_021C27A4(u8 *p);
extern void func_021C27C0(char *p);
extern int func_021C2BD4(u16 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C2B1C(int a, int *b);
extern int func_021C2B98(void *a, u32 *p);
extern int func_021C2B5C(void *t, int *st);
extern void func_021C3198(void *p, u32 *done);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216CF2C(u32 a);
extern void func_02189A58(u8 *p, u32 v);
extern void func_021C2764(u8 *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_02188C64(u8 *p);
extern int func_021A01A4(u32 a, u32 b);
extern void func_021C2320(int a, char *p, char *q, int d);
extern void *func_02030830(u32 heapId);
extern void func_021899F8(u8 *p, u32 v);
extern void func_021C30D4(u32 a);
extern int func_02005C64(void);
extern int func_021C21B4(char *p);
extern int func_021C223C(char *p);
extern int func_021C22AC(char *p);
extern void func_021C3158(u8 *p);
extern int func_021C2484(u8 *a, u8 *b);
extern void func_0216D5E0(int a0, int a1);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern u32 func_02188C60(u8 *p);
extern void func_021A0568(u8 *p, int force);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern u32 func_02188C54(u8 *p);
extern u32 func_02188D20(u8 *p);
extern void func_02193068(char *p);
extern void func_021BC5D4(u8 *p);
extern void func_021904D0(u8 *p);
extern void func_020414AC(int);
extern void func_021C27CC(u8 *p);
extern void func_021C27E8(u8 *p);
extern u32 *func_0216D9E4(void *c);
void func_021C1AEC(void);
u32 *func_021C1AF4(u32 a, u32 b);
void func_021C1C04(u32 *p);
int func_021C1C24(u32 a, u32 b, u32 c, u32 d);
void func_021C1C4C(char *p);
int func_021C1CB0(int a, char *b, int c);
int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g);
int func_021C1D68(int a, int b, int c);
int func_021C1DCC(int a, char *b, int c, int d);
int func_021C1E7C(int a, int *st, u8 *ctx);
extern u8 d_021DE3D8;
extern const VecFx32 d_021DA6E8;
extern const VecFx32 d_021DA6D0;
extern const VecFx32 d_021DA6F4;
extern const VecFx32 d_021DA6DC;
extern const s16 d_020A1EB8[];
extern u32 d_021DA7F4[];
extern unsigned char abs_id_4A[];
extern const BgMode d_021DA710;


/*
 * Tail-call thunk: forwards to func_02050BE8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1AEC(void)
{
    func_02050BE8();
}


static inline void *mk(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    VecFx32 up = *upsrc;
    return func_02048A24(a, s, c, d, e, f, g, h, pos, &up, tgt, heap);
}


static inline void *mk_persp(VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *tgt, int heap)
{
    return mk(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, pos, upsrc, tgt, heap);
}


/*
 * note:     stack slots (high to low) pos1, tgt1, pos2, tgt2, up2, up1. The caller's block
 *           locals take the top slots in textual order; each up vector is an inline helper's
 *           local, and the first call reaching the helper one inline level deeper (through
 *           mk_persp) is what puts up1 below up2. Both calls through mk directly: up1/up2
 *           swapped (2 bytes out). The zero targets need a brace initialiser in a declaration.
 *
 * Addresses are Black-image addresses.
 */
u32 *func_021C1AF4(u32 a, u32 b)
{
    u32 *r;

    r = func_02030734(a, 0x138, 1, (const char *)&d_021DE3D8, 0x158);
    r[5] = (u32)func_02047CFC(8, 2, a);
    ((struct Obj04272 *)r)->f10 = a;
    r[0] = b;
    r[6] = -1;
    {
        VecFx32 p1 = d_021DA6E8;
        VecFx32 t1 = {0, 0, 0};
        r[1] = (u32)mk_persp(&p1, &d_021DA6D0, &t1, a);
    }
    {
        VecFx32 p2 = d_021DA6F4;
        VecFx32 t2 = {0, 0, 0};
        r[2] = (u32)mk(2, 0x30000, -0x30000, -0x40000, 0x40000, 0x1000, 0x400000, 0, &p2, &d_021DA6DC, &t2, a);
    }
    r[3] = 0;
    return r;
}


/*
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 */
void func_021C1C04(u32 *p)
{
    func_02048AC4((void *)p[1]);
    func_02048AC4((void *)p[2]);
    func_02047E54((struct Rec *)p[5]);
    func_020307B0(p);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C1C24(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj03528 *)((u8 *)(a)))->f18 = func_02047E88(((struct Obj03528 *)((u8 *)(a)))->f14, b, c, d);
((struct Obj03528 *)((u8 *)(a)))->f28 = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f2C = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f30 = (1 << 12);
func_0207ADC4((a + 52));
((struct Obj03528 *)((u8 *)(a)))->f1C = 0;
((struct Obj03528 *)((u8 *)(a)))->f20 = 0;
((struct Obj03528 *)((u8 *)(a)))->f24 = 0;
return 0;
}


void func_021C1C4C(char *p)
{
    int a;
    int n;
    int i;
    u8 k;

    if (((struct Obj03141 *)p)->fC == 0)
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f4));
    else
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f8));
    if (((struct Obj03141 *)p)->f18 != -1) {
        a = (int)func_020489F4((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        n = (int)func_02048A00((u8 *)(((struct Obj03141 *)p)->f14), (u16)(((struct Obj03141 *)p)->f18));
        for (k = 0; k < n; k++) {
            i = (int)func_02048A18((u8 *)(((struct Obj03141 *)p)->f14), (u16)(a + k));
            func_02047A60((void *)i, (struct Arg *)(p + 0x1c));
        }
    }
}


int func_021C1CB0(int a, char *b, int c)
{
    int r;

    if (func_0203038C(0x15) < d_021DA7F4[c])
        return 0;
    ((struct Obj01213 *)b)->f64 = 0;
    ((struct Obj01213 *)b)->f130 = 0;
    ((struct Obj01213 *)b)->f134 = 0;
    ((struct Obj01213 *)b)->f136 = 0;
    ((struct Obj01213 *)b)->f66 = c;
    *(u32 *)&((struct Obj01213 *)b)->f128 = 0;
    *(u32 *)&((struct Obj01213 *)b)->f12C = 0;
    ((struct Obj01213 *)b)->fC = 0;
    r = (int)func_020122C0((void *)a, 0, func_021C1E7C, 0x40);
    func_021C313C((u32)b, func_020124E8((struct Obj *)r));
    return r;
}


int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g)
{
    char *q;
    int r;

    r = func_021C1CB0(a, b, 3);
    if (r == 0)
        return 0;
    ((struct Obj01213 *)b)->f128 = func_021C27F4;
    ((struct Obj01213 *)b)->f12C = func_021C2854;
    q = b + 0x9c;
    ((struct Obj04273 *)q)->f8 = e;
    ((struct Obj01213 *)b)->f9C = c;
    ((struct Obj04273 *)q)->fC = f;
    ((struct Obj04273 *)q)->f4 = d;
    ((struct Obj04273 *)q)->f10 = g;
    ((struct Obj04273 *)q)->f18 = 5;
    ((struct Obj04273 *)q)->f14 = 1;
    ((struct Obj04273 *)q)->f1A = 0x1e;
    return r;
}


int func_021C1D68(int a, int b, int c)
{
    int p;
    int x5;
    int x6f;
    int x6e;
    int xe;
    int x4c;

    p = (int)func_0201AB28(func_02012934(func_020120F4((const struct Ctx *)a)), c);
    x5 = func_02017E1C((void *)p, 5, 0);
    x6f = func_02017E1C((void *)p, 0x6f, 0);
    x6e = func_02017E1C((void *)p, 0x6e, 0);
    xe = func_02017EAC((void *)p);
    x4c = func_02017E1C((void *)p, 0x4c, 0);
    return func_021C1D18(a, (char *)b, x5, x6f, x6e, xe, x4c);
}


int func_021C1DCC(int a, char *b, int c, int d)
{
    int *q;
    int r;
    int x;
    int *s;

    func_02034AC4((int)abs_id_4A);
    q = func_021F54E0(c);
    r = func_021C1CB0(a, b, (u8)(*q));
    if (r == 0) {
        func_02034A5C((int)abs_id_4A);
        return 0;
    }
    x = (int)func_020124E8((struct Obj *)r);
    func_021C313C((u32)b, (u32 *)x);
    *(int *)&((struct Obj07558 *)x)->f3C = d;
    if (q[4] != 0)
        ((struct Obj01213 *)b)->f128 = func_021C2D68;
    else
        ((struct Obj01213 *)b)->f128 = 0;
    ((struct Obj01213 *)b)->f12C = func_021C2CF4;
    *(int *)&((struct Obj01213 *)b)->fC = 2;
    s = (int *)(b + 0x9c);
    ((struct Obj01213 *)b)->f9C = q[3];
    s[1] = q[1];
    s[2] = q[2];
    if (q[4] == 1)
        s[3] = 1;
    else
        s[3] = 0;
    if (q[0] == 0xd && s[3] != 0)
        s[4] = 1;
    else
        s[4] = 0;
    func_02034A5C((int)abs_id_4A);
    return r;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C1E7C(int a, int *st, u8 *ctx)
{
    u8 *p;
    int h;
    void *sys;
    int r1v;
    int r2v;
    u32 s10;
    u32 s14;
    BgMode m;

    p = *(u8 * *)&((struct Obj06072 *)ctx)->f0;
    h = (int)func_020124E4((struct Obj *)a);
    sys = func_0201210C((void *)h);
    switch (*st) {
    case 0:
        if (((struct Obj06072 *)ctx)->f38)
            func_0216D9A0(func_02188C7C((void *)sys));
        func_021C27A4(p);
        func_021C27C0((char *)p);
        if (func_021C2BD4(((struct Obj00576 *)p)->f66) == 0)
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B1C, 0));
        (*st)++;
        break;
    case 1:
        (*st)++;
        if (((struct Obj00576 *)p)->f66 == 0xb || ((struct Obj00576 *)p)->f66 == 0x12) {
            func_0216DAC8(func_021A3074(func_02188CB4((void *)sys)), 1);
            break;
        }
        if (((struct Obj00576 *)p)->f66 == 0x11) {
            u32 x = (u32)func_0216DE94(func_02188C7C((void *)sys), (u16)((struct Obj00576 *)p)->f9C);
            if (x)
                func_0216CF2C(x);
            break;
        }
    case 2:
        func_02189A58(sys, 1);
        func_021C2764(p);
        (*st)++;
        break;
    case 3:
        if (((struct Obj00576 *)p)->f70 == 0)
            break;
        func_0204047C(0, 0);
        func_0204047C(2, 1);
        m = d_021DA710;
        func_0203FC28((struct DispConfig *)(&m));
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        func_0207FDCC(8);
        func_0207D63C(0x04000050, 0, 4, 0, 0);
        func_02040588(2, 1);
        func_021A01A4(func_02188C64(sys), 0);
        (*st)++;
        break;
    case 4:
        func_021C2320(a, (char *)p, (char *)(ctx + 4), (u8)((struct Obj00576 *)p)->f66);
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_02030830(((struct Obj00576 *)p)->f10);
        func_021899F8(sys, 1);
        if (((struct Obj06072 *)ctx)->f34)
            func_021C30D4(((struct Obj06072 *)ctx)->f34);
        (*st)++;
        break;
    case 5:
        if (func_021C2BD4(((struct Obj00576 *)p)->f66))
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B98, 0));
        else
            func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, (void *)a, func_021C2B5C, 0));
        (*st)++;
        break;
    case 6:
        if (func_02005C64())
            break;
        (*st)++;
    case 7:
        {
            int r7v;
            int ok;

            ((struct Obj00576 *)p)->f134 += 1;
            r7v = func_021C21B4((char *)p);
            r1v = func_021C223C((char *)p);
            r2v = func_021C22AC((char *)p);
            ((struct Obj00576 *)p)->f11C = r7v;
            ((struct Obj00576 *)p)->f120 = r1v;
            ((struct Obj00576 *)p)->f124 = r2v;
            func_021C3158(p);
            ok = 0;
            if (*(StepFn *)&((struct Obj00576 *)p)->f12C)
                ok = (*(StepFn *)(p + 0x12c))(a, p);
            else if (((struct Obj00576 *)p)->f11C && ((struct Obj00576 *)p)->f120 && ((struct Obj00576 *)p)->f124)
                ok = 1;
            if (ok == 0)
                break;
        }
        (*st)++;
        break;
    case 8:
        func_021899F8(sys, 0);
        func_021C2484(p, ctx + 4);
        if (func_021C2BD4(((struct Obj00576 *)p)->f66)) {
            void *o = func_021A3074(func_02188CB4((void *)sys));
            func_0216DAC8(o, 0);
            func_0216D5E0((int)o, 1);
            func_02189A58(sys, 0);
        } else {
            func_02040588(0, 0);
            func_0207DD24(0, 0x1f, 0x7fff, 0, 0);
        }
        func_021A01A4(func_02188C64(sys), 1);
        (*st)++;
        break;
    case 9:
        func_021A0568((u8 *)func_02188C60(sys), 1);
        ((struct Obj00576 *)p)->f74 = 0;
        func_020056A0(func_021C3198, p + 0x74, 0);
        (*st)++;
        break;
    case 10:
        if (((struct Obj00576 *)p)->f74 == 0)
            break;
        func_02030830(((struct Obj00576 *)p)->f10);
        s10 = func_02188C54(sys);
        s14 = func_02188D20(sys);
        func_02193068((char *)s10);
        func_021BC5D4((u8 *)s14);
        func_021904D0((u8 *)s10);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        func_020414AC(2);
        func_021C27CC(p);
        func_021C27E8(p);
        func_02189A58(sys, 0);
        if (((struct Obj06072 *)ctx)->f38)
            func_0216D9E4(func_02188C7C((void *)sys));
        (*st)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}
