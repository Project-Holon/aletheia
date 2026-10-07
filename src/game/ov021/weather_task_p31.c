/*
 * file:     weather_task_p31.c
 * unit:     yes
 * function: func_021A3504, func_021A3524, func_021A3550, func_021A356C, func_021A3584, func_021A35A0, func_021A35BC, func_021A35E0, func_021A35F0, func_021A35FC, func_021A3624, func_021A3644, func_021A3664, func_021A3674
 * address:  0x021A3504
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
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A5738  0x021A5738  thumb  ov021
 *   func_021A575C  0x021A575C  thumb  ov021
 *   func_021A5764  0x021A5764  thumb  ov021
 *   func_021A5768  0x021A5768  thumb  ov021
 *   func_021A30BC  0x021A30BC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021A4140  0x021A4140  thumb  ov021
 *   func_021A41B0  0x021A41B0  thumb  ov021
 *   func_021A3960  0x021A3960  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A54A0  0x021A54A0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb
 *   func_021A5880  0x021A5880  thumb  ov021
 *   func_021A596C  0x021A596C  thumb
 */
#include "../../matched/include/Obj12087.h"
#include "../../matched/include/Obj18022.h"
#include "../../matched/include/Obj06010.h"
#include "../../matched/include/Obj18023.h"

struct BigObj;
struct Ctx;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

u32 func_021A3098(u8 *p);
int func_021AB5AC(unsigned long a, unsigned long b);
int func_021AB11C(u32 attr);
u16 func_021AB0F0(u32 attr);
int func_021AB310(u16 id);
u32 func_02188CFC(u8 *p);
void func_021A5738(u32 x, int a);
void func_021A575C(u32 *x);
extern u32 func_021A5764(u8 *p);
int func_021A5768(u32 a, u32 b);
int func_021A30BC(u8 *p);
void *func_020120F4(const struct Ctx *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_020142E8(void *bitmap, s32 id);
u32 *func_021A4140(u32 a, u32 b);
extern u32 func_021A41B0(u32, u32, u32, u32);
void *func_021A3960(unsigned char *p);
int func_0216D83C(void *p);
int func_0216D854(void *p);
int func_0216D86C(void *p);
extern int func_021A54A0(u32 a);
extern void func_021A54B4(u8 *p);
u8 *func_021A5880(u8 *obj, int heap);
extern void func_021A596C(u8 *p, u32 b, u32 c);
int func_021A3504(u8 *a, int b, int c);
int func_021A3524(u8 *a, int b, int c);
void func_021A3550(u32 *p, int a);
void func_021A356C(void **p);
int func_021A3584(void *a);
void func_021A35A0(u32 *p, int a);
int func_021A35BC(int a);
void func_021A35E0(u32 *p, u32 heap);
int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
int func_021A3624(void *a);
void func_021A3644(void **p);
void func_021A3664(u32 *p, u32 heap);
void func_021A3674(u8 *p, u32 b, u32 c);


int func_021A3504(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (r == 2 || r == 3)
        return 0;
    return func_021AB5AC(b, c);
}


int func_021A3524(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (func_021AB11C(b) != 0 || r != 2)
        return 0;
    return func_021AB310(func_021AB0F0(c));
}


void func_021A3550(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5738(p[2], a);
}


void func_021A356C(void **p)
{
    if (func_02188CFC(p[0]) == 0)
        func_021A575C(p[2]);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3584(void *a)
{
if (func_02188CFC((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5764((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f8));
}
return 0;
}


void func_021A35A0(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5768(p[2], a);
}


int func_021A35BC(int a)
{
    if (func_020142E8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_021A30BC((u8 *)a))), 0x963) != 0)
        return 1;
    return 0;
}


void func_021A35E0(u32 *p, u32 heap)
{
    p[2] = (u32)func_021A4140(p[1], heap);
}


int func_021A35F0(u32 a, u32 b, u32 c, u32 d)
{
return func_021A41B0(((struct Obj18022 *)((u8 *)(a)))->f8, b, c, d);
}


void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c)
{
    void *h = func_021A3960(p[1]);

    *a = func_0216D83C(h);
    *b = func_0216D854(h);
    *c = func_0216D86C(h);
}


int func_021A3624(void *a)
{
if (func_02188CFC((u8 *)(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f0)) == 0) {
    if (func_021A54A0(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f8) == 1) {
        return 1;
    }
}
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A3644(void **p)
{
    if (func_02188CFC(p[0]) == 0 && func_021A54A0((u32)p[2]) == 1)
        func_021A54B4(p[2]);
}


void func_021A3664(u32 *p, u32 heap)
{
    p[3] = (u32)func_021A5880((u8 *)p[1], heap);
}


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3674(u8 *p, u32 b, u32 c)
{
    func_021A596C((u8 *)(((struct Obj18023 *)p)->fC), b, c);
}
