/*
 * file:     weather_task_p17.c
 * unit:     yes
 * function: func_021A550C, func_021A552C, func_021A5538, func_021A55A8, func_021A55DC, func_021A55FC, func_021A5610, func_021A5630, func_021A569C, func_021A56C0, func_021A56F4, func_021A5708, func_021A5728, func_021A572C, func_021A5738, func_021A575C, func_021A5764, func_021A5768, func_021A5778
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
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021A3920  0x021A3920  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   d_021D8A24  0x021D8A24  data  a2
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021A5378  0x021A5378  thumb  ov021
 *   func_021A39AC  0x021A39AC  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A3998  0x021A3998  thumb  ov021
 *   func_021A5390  0x021A5390  thumb  ov021
 */
#include "../../matched/include/Obj06014.h"
#include "../../matched/include/Obj09571.h"
#include "../../matched/include/Obj12739.h"
#include "../../matched/include/Obj18049.h"
#include "../../matched/include/Obj02083.h"
#include "../../matched/include/Obj18050.h"
#include "../../matched/include/Obj09570.h"
#include "../../matched/include/Obj18051.h"
#include "../../matched/include/Obj12088.h"
#include "../../matched/include/Obj18052.h"

struct Actor;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int BOOL;

typedef int (*Fn021A55A8)(u32 *p, int a);

typedef signed short s16;

typedef signed char s8;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

typedef struct {
    u8 pad[0x14];
    u16 saved;
    u8 flag;
} Obj021A5738;

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
int func_021AB404(int a);
int func_021AB410(int a);
int func_021A5788(u32 *p, int k, int *out);
u16 func_021AB0F0(u32 attr);
extern u16 func_021A3920(u8 *p);
extern int func_021AB11C(u32);
void func_0216D88C(const struct Actor *h, struct VecFx32 *v);
int func_02163E58(void *h, Vec021A56C0 *v, int *lim);
extern u32 func_021A39AC(u32, u32);
extern void func_021A5378(u32 *p, int on);
extern int func_021A3998(u8 *a);
extern void func_021A53A4(u32 *p, int on);
int func_021A5390(u32 a);
void func_021A550C(u32 *p);
u32 func_021A552C(u32 *p);
int func_021A5538(u8 *a);
int func_021A55A8(u32 *p, u32 a, int b);
int func_021A55DC(int a);
int func_021A55FC(int a);
int func_021A5610(u32 *p);
u32 func_021A5630(u32 a);
int func_021A569C(u8 *a, void *b, int c, int *d);
u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3);
int func_021A56F4(u32 a);
int func_021A5708(u32 a);
u32 func_021A5728(u8 *p);
void *func_021A572C(u8 *p);
void func_021A5738(Obj021A5738 *p, int a);
void func_021A575C(u32 *p);
u32 func_021A5764(u8 *p);
int func_021A5768(u32 a, u32 b);
int func_021A5778(u32 a);
extern Fn021A55A8 const data_021D89EC[];
extern const u16 d_021D8A24[4];





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





int func_021A55DC(int a)
{
    if (func_021AB404(a) == 1 || func_021AB410(a) == 1)
        return 1;
    return 0;
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A55FC(int a)
{
if (func_021AB404(a) == 1) {
    return 1;
}
return 0;
}





int func_021A5610(u32 *p)
{
    int x;

    func_021A5788(p, 9, &x);
    if (func_021A55FC(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}




u32 func_021A5630(u32 a)
{
    u32 v;
    u16 t[4];
    u16 i;
    u32 x;
    u16 *p = t;
    t[0] = d_021D8A24[0];
    t[1] = d_021D8A24[1];
    t[2] = d_021D8A24[2];
    t[3] = d_021D8A24[3];
    x = func_021A3920((u8 *)(*(u32 *)&((struct Obj09571 *)a)->fC));
    i = 0;
    do {
        if (func_021A5788((u32 *)a, x, (int *)&v) == 1) {
            if (func_021A55DC(func_021AB0F0(v)) == 0) {
                if (func_021AB11C(v) == 0) {
                    return x;
                }
            }
        }
        i = i + 1;
        x = p[x];
    } while (i < 4);
    return 9;
}




int func_021A569C(u8 *a, void *b, int c, int *d)
{
    int r = func_021A5264(a, b, c, d);

    if (func_021A55DC(func_021AB0F0(*d)) == 1)
        r |= 0x100;
    return r;
}




u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj12739 *)p)->fC);
    Vec021A56C0 v;
    int lim;

    func_0216D88C(h, (struct VecFx32 *)&v);
    func_02163E58(h, &v, &lim);
    if (v.y <= lim)
        return 1;
    return 0;
}




int func_021A56F4(u32 a)
{
func_021A5378((u32 *)a, 1);
return func_021A39AC(((struct Obj18049 *)((u8 *)(a)))->fC, 7);
}



int func_021A5708(u32 a)
{
((struct Obj02083 *)((u8 *)(a)))->f14 = 0;
((struct Obj02083 *)((u8 *)(a)))->f16 = 0;
func_021A53A4((u32 *)a, 0);
func_021A5378((u32 *)a, 0);
return func_021A3998((u8 *)(((struct Obj02083 *)((u8 *)(a)))->fC));
}



/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A5728(u8 *p)
{
    return ((struct Obj18050 *)p)->fC;
}



/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void *func_021A572C(u8 *p)
{
    return func_021A3960(((struct Obj09570 *)p)->fC);
}



void func_021A5738(Obj021A5738 *p, int a)
{
    u16 s;

    if (func_021A5390((u32)p) == 1) {
        s = p->saved;
        func_021A5708((u32)p);
        if (a == 1) {
            p->saved = s;
            p->flag = 1;
        }
    }
}



/*
 * Tail-call thunk: forwards to func_021A550C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A575C(u32 *p)
{
    func_021A550C(p);
}



/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_021A5764(u8 *p)
{
    return ((struct Obj18051 *)p)->f1C;
}



int func_021A5768(u32 a, u32 b)
{
if (b == 1) {
    ((struct Obj12088 *)((u8 *)(a)))->f1C = 1;
    return a;
}
((struct Obj12088 *)((u8 *)(a)))->f1C = 0;
return a;
}



int func_021A5778(u32 a)
{
if (((struct Obj18052 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}
