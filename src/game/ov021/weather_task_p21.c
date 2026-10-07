/*
 * file:     weather_task_p21.c
 * unit:     yes
 * function: func_021A2D30, func_021A2D88, func_021A2DE4, func_021A2DF0, func_021A2E34, func_021A2E44, func_021A2E50, func_021A2E90
 * address:  0x021A2D30
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
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   d_021DDE90     0x021DDE90  data  a4
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A35BC  0x021A35BC  thumb
 *   func_021A35F0  0x021A35F0  thumb
 *   func_021A36E4  0x021A36E4  thumb  ov021
 *   d_021DDEA8     0x021DDEA8  data  a4
 *   func_021A41A8  0x021A41A8  thumb  ov021
 *   func_021A5920  0x021A5920  thumb  ov021
 *   func_021A3810  0x021A3810  thumb  ov021
 */
#include "../../matched/include/Obj12722.h"
#include "../../matched/include/Obj19760.h"
#include "../../matched/include/Obj19761.h"
#include "../../matched/include/Obj05861.h"

struct Obj00020;
typedef struct {
    int f0;
    int pad4[4];
    int f14;
} Obj;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

u32 func_0207C768(u32 a, u32 b);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
u16 func_02188C84(u8 *p);
void *func_02188CB4(struct Obj00020 *p);
void *func_021A3074(unsigned char *p);
void func_0216D5E0(int a0, int a1);
void func_021A35E0(u32 *p, u32 heap);
void *func_0216D888(void *a);
void func_02188D40(u8 *p, u32 v);
void func_02188CAC(u8 *p, u32 v);
extern u32 func_020307B0(void *p);
extern u32 func_02188CA4(u8 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_021A35BC(int a);
extern int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
u32 func_021A36E4(int a, u32 b, int c, int d, u16 heap);
extern void func_021A3810(u32 a0);
extern void func_021A41A8(void);
extern void func_021A5920(void);
void func_021A2D30(Obj *o, int v, int *out2, int *out1);
void func_021A2D88(int obj, int unused, int y);
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d);
void func_021A2DF0(u32 a);
int func_021A2E34(u32 a, u32 b, u32 c, u32 d);
void func_021A2E44(int a, u32 v);
u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap);
int func_021A2E90(void *a);
extern int d_021DDE90;
extern int d_021DDEA8;


void func_021A2D30(Obj *o, int v, int *out2, int *out1)
{
    *out1 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f14) * 0x2000 + 0x800) >> 12);
    *out2 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f0) * 0x2000 + 0x800) >> 12);
}


void func_021A2D88(int obj, int unused, int y)
{
    int h;
    void *a;
    void *b;
    char *p;

    h = func_02188C84((u8 *)obj);
    p = (char *)func_02030734(h, 0x10, 1, (const char *)&d_021DDE90, 0x68);
    ((struct Obj12722 *)p)->f0 = h;
    ((struct Obj12722 *)p)->f4 = obj;
    a = func_02188CB4((void *)obj);
    b = func_021A3074((void *)a);
    func_0216D5E0((int)b, y);
    func_021A35E0(a, h);
    func_02188D40((u8 *)obj, (u32)func_0216D888(b));
    func_02188CAC((u8 *)obj, (u32)p);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)func_02188CA4((u8 *)a));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A2DF0(u32 a)
{
    u8 *p = (u8 *)func_02188CA4((u8 *)a);
    void *q = func_02188CB4((void *)a);

    if (((struct Obj19760 *)p)->fC == 0) {
        u32 x = func_020362DC();
        u32 y = func_0203630C();
        u32 f = 0;

        if (func_021A35BC((int)q) == 1)
            f |= 1;
        func_021A35F0((u32)q, x, y, f);
    }
}


int func_021A2E34(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}


void func_021A2E44(int a, u32 v)
{
    ((struct Obj19761 *)((char *)func_02188CA4((u8 *)a)))->fC = v;
}


u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap)
{
    u32 *o = (u32 *)func_02030734(heap, 0x10, 1, (const char *)&d_021DDEA8, 0x4C);

    o[0] = b;
    o[1] = func_021A36E4(a, b, c, d, heap);
    return o;
}


int func_021A2E90(void *a)
{
if (((struct Obj05861 *)((u8 *)(a)))->f8 != 0) {
    func_021A41A8();
}
if (((struct Obj05861 *)((u8 *)(a)))->fC != 0) {
    func_021A5920();
}
func_021A3810(((struct Obj05861 *)((u8 *)(a)))->f4);
return func_020307B0(a);
}
