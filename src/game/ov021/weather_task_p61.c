/*
 * file:     weather_task_p61.c
 * unit:     yes
 * function: func_021A550C, func_021A552C, func_021A5538, func_021A55A8
 * address:  0x021A550C
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
 *   func_021A5340  0x021A5340  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A5334  0x021A5334  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A5328  0x021A5328  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021A5458  0x021A5458  thumb  ov021
 *   data_021D89EC  0x021D89EC  data  a4
 */
#include "../../matched/include/Obj06014.h"

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef int BOOL;

typedef int (*Fn021A55A8)(u32 *p, int a);

int func_021A5340(u32 *p);
void *func_021A3960(unsigned char *p);
u32 *func_0216D550(u32 *p, u32 v);
void func_021A5334(u32 a);
extern u16 func_0216D608(void *p);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern void func_021A5354(u32 a);
extern void func_021A3964(u8 *p, u32 v);
extern void func_021A5328(u32 a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a0, int a1);
extern u32 *func_0216D548(u32 *p, u32 v); /* its third parameter is a scratch it never reads */
int func_021A5458(u32 *p);
void func_021A550C(u32 *p);
u32 func_021A552C(u32 *p);
int func_021A5538(u8 *a);
int func_021A55A8(u32 *p, u32 a, int b);
extern Fn021A55A8 const data_021D89EC[];


void func_021A550C(u32 *p)
{
    if (func_021A5340(p) == 1) {
        func_0216D550(func_021A3960(*(unsigned char * *)&((struct Obj06014 *)p)->fC), 0x18);
        func_021A5334((u32)p);
    }
}


/*
 * Calls func_021A550C() and returns 0x0.
 */
u32 func_021A552C(u32 *p)
{
    func_021A550C(p);

    return 0x0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021A5538(u8 *a)
{
    int v;
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj06014 *)a)->fC);
    u32 y = func_0216D608(x);
    if (func_021A5264(a, x, y, &v) != 0) {
        func_021A550C((u32 *)a);
        func_021A5354((u32)a);
        func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 0);
        return 0;
    }
    func_021A5328((u32)a);
    func_0216D410(x, func_02197E7C(y, 0x10));
    func_0216D548(x, 0x18);
    ((struct Obj06014 *)a)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 1);
    return 1;
}


int func_021A55A8(u32 *p, u32 a, int b)
{
    if (b == 0) {
        if (data_021D89EC[func_021A5458(p)](p, a) == 1)
            return 1;
    }
    func_021A5334((u32)p);
    return 0;
}
