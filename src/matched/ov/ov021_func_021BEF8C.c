/*
 * function: func_021BEF8C
 * address:  0x021BEF8C
 * packet:   pkt_ov021_021BEF8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_02166B2C  0x02166B2C  thumb  ov010
 *   func_021BF564  0x021BF564  thumb  ov021
 *   func_02188DF0  0x02188DF0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021903CC  0x021903CC  thumb  ov021
 *   func_021902AC  0x021902AC  thumb  ov021
 */
#include "../include/Obj01504.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02189A58(u8 *p, u32 v);
typedef signed int     s32;
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0208068C(u32 a);
extern void func_02082AC0(u32 a, u32 b, u32 c);
extern void func_02080B98(void);
extern void func_0207FDCC(u32 a);
extern void func_02166B2C(void);
extern void func_021BF564(u32 a);
extern void func_02188DF0(u8 *a);
extern u32 func_02188C54(u8 *p);
extern int func_021903CC(u8 *p);
extern void func_021902AC(u16 *p, int v);

int func_021BEF8C(u32 p0, int *st, u8 *q)
{
    u32 m;

    switch (*st) {
    case 0:
        func_02189A58((u8 *)(((struct Obj01504 *)q)->f4), 1);
        ((struct Obj01504 *)q)->f1C = 0x10;
        func_0204047C(2, 0);
        func_0204047C(0, 1);
        func_02040588(0, 1);
        func_0207D63C(0x04000050, 4, 1, ((struct Obj01504 *)q)->f1C, 0);
        func_0204E720(((struct Obj01504 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj01504 *)q)->f1C != 0) {
            ((struct Obj01504 *)q)->f1C = ((struct Obj01504 *)q)->f1C - 1;
            *(volatile u16 *)0x04000052 = ((0x10 - ((struct Obj01504 *)q)->f1C) << 8) | ((struct Obj01504 *)q)->f1C;
            break;
        }
        func_02040588(2, 0);
        func_0208068C(8);
        func_02082AC0(0, 0x06800000, 0x20000);
        func_02080B98();
        func_0207FDCC(8);
        func_02166B2C();
        *st = *st + 1;
        break;
    case 2:
        func_021BF564(((struct Obj01504 *)q)->f4);
        *st = *st + 1;
        break;
    case 3:
        func_02188DF0((u8 *)(((struct Obj01504 *)q)->f4));
        *st = *st + 1;
        break;
    case 4:
        m = func_02188C54((u8 *)(((struct Obj01504 *)q)->f4));
        if (func_021903CC((u8 *)m) != 0) {
            func_021902AC((u16 *)m, 0);
            *st = *st + 1;
        }
        break;
    case 5:
        func_021902AC((u16 *)func_02188C54((u8 *)(((struct Obj01504 *)q)->f4)), 1);
        *st = *st + 1;
        break;
    case 6:
        func_021902AC((u16 *)func_02188C54((u8 *)(((struct Obj01504 *)q)->f4)), 2);
        *st = *st + 1;
        break;
    case 7:
        *st = *st + 1;
    case 8:
        func_02189A58((u8 *)(((struct Obj01504 *)q)->f4), 0);
        return 1;
    }
    return 0;
}
