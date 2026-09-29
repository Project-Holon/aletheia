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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef volatile unsigned short vu16;

typedef struct { int a, b, c, d; } BgMode;

extern int func_020124E4(int a);
extern int func_0201210C(int a);
extern u32 func_02188C7C(u32 a);
extern void func_0216D9A0(u32 o);
extern void func_021C27A4(u8 *p);
extern void func_021C27C0(u8 *p);
extern int func_021C2BD4(u16 a);
extern u32 func_020122C0(u32 a, u32 b, void *c, u32 d);
extern void func_02012374(u32, u32);
extern int func_021C2B1C(int a, int *b);
extern int func_021C2B98(int a, int *b);
extern int func_021C2B5C(int a, int *b);
extern void func_021C3198(void);
extern u32 func_02188CB4(u32 a);
extern u32 func_021A3074(u32 a);
extern void func_0216DAC8(u32 o, int v);
extern u32 func_0216DE94(u32 a, u32 b);
extern void func_0216CF2C(u32 a);
extern void func_02189A58(u32 o, u32 v);
extern void func_021C2764(u8 *p);
extern void func_0204047C(int, int);
extern void func_0203FC28(BgMode *m);
extern void func_0207FDCC(u32 a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(int, int);
extern u32 func_02188C64(u32 a);
extern void func_021A01A4(u32 a, int b);
extern void func_021C2320(int a, u8 *p, u8 *q, int d);
extern void func_02030830(u16 heap);
extern void func_021899F8(u32 a, int b);
extern void func_021C30D4(u32 a);
extern int func_02005C64(void);
extern int func_021C21B4(u8 *p);
extern int func_021C223C(u8 *p);
extern int func_021C22AC(u8 *p);
extern void func_021C3158(u8 *p);
extern void func_021C2484(u8 *p, u8 *q);
extern void func_0216D5E0(u32 o, u32 b);
extern void func_0207DD24(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02188C60(u32 a);
extern void func_021A0568(u32 a, int b);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern u32 func_02188C54(u32 a);
extern u32 func_02188D20(u32 a);
extern void func_02193068(u32 a);
extern void func_021BC5D4(u32 a);
extern void func_021904D0(u32 a);
extern void func_020414AC(int);
extern void func_021C27CC(u8 *p);
extern void func_021C27E8(u8 *p);
extern void func_0216D9E4(u32 o);
extern const BgMode d_021DA710;

typedef int (*StepFn)(int a, u8 *p);

int func_021C1E7C(int a, int *st, u8 *ctx)
{
    u8 *p;
    int h;
    u32 sys;
    int r1v;
    int r2v;
    u32 s10;
    u32 s14;
    BgMode m;

    p = *(u8 **)ctx;
    h = func_020124E4(a);
    sys = func_0201210C(h);
    switch (*st) {
    case 0:
        if (*(u32 *)(ctx + 0x38))
            func_0216D9A0(func_02188C7C(sys));
        func_021C27A4(p);
        func_021C27C0(p);
        if (func_021C2BD4(*(u16 *)(p + 0x66)) == 0)
            func_02012374(a, func_020122C0(h, a, func_021C2B1C, 0));
        (*st)++;
        break;
    case 1:
        (*st)++;
        if (*(u16 *)(p + 0x66) == 0xb || *(u16 *)(p + 0x66) == 0x12) {
            func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
            break;
        }
        if (*(u16 *)(p + 0x66) == 0x11) {
            u32 x = func_0216DE94(func_02188C7C(sys), (u16)*(u32 *)(p + 0x9c));
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
        if (*(u32 *)(p + 0x70) == 0)
            break;
        func_0204047C(0, 0);
        func_0204047C(2, 1);
        m = d_021DA710;
        func_0203FC28(&m);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        func_0207FDCC(8);
        func_0207D63C(0x04000050, 0, 4, 0, 0);
        func_02040588(2, 1);
        func_021A01A4(func_02188C64(sys), 0);
        (*st)++;
        break;
    case 4:
        func_021C2320(a, p, ctx + 4, (u8)*(u16 *)(p + 0x66));
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_02030830(*(u16 *)(p + 0x10));
        func_021899F8(sys, 1);
        if (*(u32 *)(ctx + 0x34))
            func_021C30D4(*(u32 *)(ctx + 0x34));
        (*st)++;
        break;
    case 5:
        if (func_021C2BD4(*(u16 *)(p + 0x66)))
            func_02012374(a, func_020122C0(h, a, func_021C2B98, 0));
        else
            func_02012374(a, func_020122C0(h, a, func_021C2B5C, 0));
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

            *(u16 *)(p + 0x134) += 1;
            r7v = func_021C21B4(p);
            r1v = func_021C223C(p);
            r2v = func_021C22AC(p);
            *(int *)(p + 0x11c) = r7v;
            *(int *)(p + 0x120) = r1v;
            *(int *)(p + 0x124) = r2v;
            func_021C3158(p);
            ok = 0;
            if (*(StepFn *)(p + 0x12c))
                ok = (*(StepFn *)(p + 0x12c))(a, p);
            else if (*(int *)(p + 0x11c) && *(int *)(p + 0x120) && *(int *)(p + 0x124))
                ok = 1;
            if (ok == 0)
                break;
        }
        (*st)++;
        break;
    case 8:
        func_021899F8(sys, 0);
        func_021C2484(p, ctx + 4);
        if (func_021C2BD4(*(u16 *)(p + 0x66))) {
            u32 o = func_021A3074(func_02188CB4(sys));
            func_0216DAC8(o, 0);
            func_0216D5E0(o, 1);
            func_02189A58(sys, 0);
        } else {
            func_02040588(0, 0);
            func_0207DD24(0, 0x1f, 0x7fff, 0, 0);
        }
        func_021A01A4(func_02188C64(sys), 1);
        (*st)++;
        break;
    case 9:
        func_021A0568(func_02188C60(sys), 1);
        *(u32 *)(p + 0x74) = 0;
        func_020056A0(func_021C3198, p + 0x74, 0);
        (*st)++;
        break;
    case 10:
        if (*(u32 *)(p + 0x74) == 0)
            break;
        func_02030830(*(u16 *)(p + 0x10));
        s10 = func_02188C54(sys);
        s14 = func_02188D20(sys);
        func_02193068(s10);
        func_021BC5D4(s14);
        func_021904D0(s10);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        func_020414AC(2);
        func_021C27CC(p);
        func_021C27E8(p);
        func_02189A58(sys, 0);
        if (*(u32 *)(ctx + 0x38))
            func_0216D9E4(func_02188C7C(sys));
        (*st)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}
