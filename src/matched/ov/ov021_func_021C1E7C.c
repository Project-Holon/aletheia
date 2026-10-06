/*
 * function: func_021C1E7C
 * address:  0x021C1E7C
 * packet:   pkt_ov021_021C1E7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021C27A4  0x021C27A4  thumb  ov021
 *   func_021C27C0  0x021C27C0  thumb  ov021
 *   func_021C2BD4  0x021C2BD4  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
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
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00576.h"
#include "../include/Obj06072.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef volatile unsigned short vu16;

typedef struct { int a, b, c, d; } BgMode;

struct Desc;
struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
struct Ctx;
struct DispConfig;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *o);
extern void func_021C27A4(u8 *p);
extern void func_021C27C0(char *p);
extern int func_021C2BD4(u16 a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C2B1C(int a, int *b);
extern int func_021C2B98(void *a, u32 *p);
extern int func_021C2B5C(void *t, int *st);
extern void func_021C3198(void *p, u32 *done);
extern void *func_02188CB4(unsigned char *p);
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
extern void func_02040588(u32 which, u32 enable);
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
extern void func_021C2484(u8 *p, u8 *q);
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
extern void func_0216D9E4(void *o);
extern const BgMode d_021DA710;

typedef int (*StepFn)(int a, u8 *p);

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
