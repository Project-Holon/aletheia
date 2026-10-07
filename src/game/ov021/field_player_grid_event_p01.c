/*
 * file:     field_player_grid_event_p01.c
 * unit:     yes
 * function: func_021BEE74, func_021BEEB4, func_021BEF08, func_021BEF8C, func_021BF0A4, func_021BF0E4
 * address:  0x021BEE74
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
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021BF564  0x021BF564  thumb  ov021
 *   func_021BF584  0x021BF584  thumb  ov021
 *   func_0208068C  0x0208068C  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_02166B0C  0x02166B0C  thumb  ov010
 *   d_021D9F50     0x021D9F50  data  ov021  a4
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02166B2C  0x02166B2C  thumb  ov010
 *   func_02188DF0  0x02188DF0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021903CC  0x021903CC  thumb  ov021
 *   func_021902AC  0x021902AC  thumb  ov021
 *   func_0218774C  0x0218774C  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_021877A8  0x021877A8  thumb  ov020
 */
#include "../../matched/include/Obj12906.h"
#include "../../matched/include/Obj06060.h"
#include "../../matched/include/Obj20152.h"
#include "../../matched/include/Obj01504.h"
#include "../../matched/include/Obj07553.h"
#include "../../matched/include/Obj05067.h"

struct DispConfig;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { u32 w[4]; } S16;

extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021BF564(u32 a);
extern void func_021BF584(u8 *a0);
extern void func_0208068C(u32 a);
extern void func_02087AE4(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02166B0C(void);
extern void func_02189A58(u8 *p, u32 v);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void func_02082AC0(u32 a, u32 b, u32 c);
extern void func_02080B98(void);
extern void func_02166B2C(void);
extern void func_02188DF0(u8 *a);
extern u32 func_02188C54(u8 *p);
extern int func_021903CC(u8 *p);
extern void func_021902AC(u16 *p, int v);
extern void *func_0218774C(int a, int b, u8 c, u8 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f);
int func_021BEE74(u32 p0, int *st, u8 *q);
int func_021BEEB4(u32 p0, int *st, u8 *q);
int func_021BEF08(u32 p0, int *st, u8 *q);
int func_021BEF8C(u32 p0, int *st, u8 *q);
int func_021BF0A4(u32 p0, int *st, u8 *q);
int func_021BF0E4(u32 p0, int *st, u8 *q);
extern S16 d_021D9F50;


int func_021BEE74(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        func_0204E720(((struct Obj12906 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj12906 *)q)->f14 == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}


int func_021BEEB4(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        if (((struct Obj06060 *)q)->f18 != 0) {
            func_021BF564(((struct Obj06060 *)q)->f4);
            func_021BF584((u8 *)(((struct Obj06060 *)q)->f4));
        }
        func_0204E720(((struct Obj06060 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj06060 *)q)->f14 == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}


int func_021BEF08(u32 p0, int *st, u8 *q)
{
    S16 loc;

    if (*st == 0) {
        func_0204E720(((struct Obj20152 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        func_0208068C(8);
        *(volatile u32 *)0x04000064 = 0x80330010;
        func_02087AE4();
        func_02087AE4();
        loc = d_021D9F50;
        func_0203FC28((struct DispConfig *)(&loc));
        *(volatile u16 *)0x0400000C = 0x4084 | (*(volatile u16 *)0x0400000C & 0x43);
        func_0207FDCC(8);
        func_0204047C(2, 0);
        func_02040588(2, 1);
        func_02166B0C();
        return 1;
    }
    return 0;
}


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


int func_021BF0A4(u32 p0, int *st, u8 *q)
{
    u32 a = ((struct Obj07553 *)q)->f0;
    u32 b = ((struct Obj07553 *)q)->f4;

    switch (*st) {
    case 0: {
        u32 r = (u32)func_0218774C(a, b, q[0x20], q[0x21]);
        func_02012374((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}


int func_021BF0E4(u32 p0, int *st, u8 *q)
{
    u32 a = ((struct Obj05067 *)q)->f0;
    u32 b = ((struct Obj05067 *)q)->f4;

    switch (*st) {
    case 0: {
        u32 r = (u32)func_021877A8(a, b, q[0x20], q[0x21], ((struct Obj05067 *)q)->f24, ((struct Obj05067 *)q)->f28);
        func_02012374((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
