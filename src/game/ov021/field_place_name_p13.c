/*
 * file:     field_place_name_p13.c
 * unit:     yes
 * function: func_021BD0FC, func_021BD118, func_021BD120, func_021BD134, func_021BD138, func_021BD140, func_021BD148, func_021BD184, func_021BD19C, func_021BD1CC, func_021BD1D4, func_021BD1DC, func_021BD1E4
 * address:  0x021BD0FC
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 *   func_021BD214  0x021BD214  thumb  ov021
 *   func_021BD234  0x021BD234  thumb  ov021
 *   func_021BD2BC  0x021BD2BC  thumb  ov021
 *   func_021BD250  0x021BD250  thumb  ov021
 *   func_021BD278  0x021BD278  thumb  ov021
 *   func_021BD5F8  0x021BD5F8  thumb  ov021
 *   func_021BD2A4  0x021BD2A4  thumb  ov021
 *   func_021BD264  0x021BD264  thumb  ov021
 *   func_021BD22C  0x021BD22C  thumb  ov021
 *   func_021BD2C4  0x021BD2C4  thumb  ov021
 *   func_021BD2D0  0x021BD2D0  thumb  ov021
 *   func_021BD30C  0x021BD30C  thumb  ov021
 *   func_021BD57C  0x021BD57C  thumb  ov021
 *   func_021BD588  0x021BD588  thumb  ov021
 *   func_021BD554  0x021BD554  thumb  ov021
 *   func_021BD3BC  0x021BD3BC  thumb
 *   func_021BD474  0x021BD474  thumb
 *   func_021BD308  0x021BD308  thumb
 */
#include "../../matched/include/Obj00575.h"
#include "../../matched/include/Obj18211.h"
#include "../../matched/include/Obj18214.h"
#include "../../matched/include/Obj18215.h"
#include "../../matched/include/Obj12115.h"

struct Big;
struct Ctx;
struct Sub02008828Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj;

extern struct Sub02008828Obj *func_02008854(void *sys);
extern u32 func_020089A0(u32, u32);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02013E6C(u32 id);
extern void *func_021BD214(int a);
extern void func_021BD234(void *p);
extern void func_021BD2BC(u8 *p, int v);
extern void func_021BD250(void *p);
extern void func_021BD278(void *p, int a, int b, int c);
extern void func_021BD5F8(void *p, unsigned int a);
extern u32 func_021BD22C(void *a0);
extern void func_021BD264(u8 *p);
extern u32 func_021BD2A4(u32, u32, u32, u32);
extern void func_021BD2C4(u8 *p, u32 v);
extern void func_021BD2D0(u8 *p, u16 v);
extern void func_021BD30C(char *p);
extern u32 func_021BD554(u32, u32);
extern void func_021BD57C(u8 *p);
extern void func_021BD588(u32 *p);
extern void func_021BD3BC(void *p);
extern void func_021BD474();
extern int func_021BD308(u8 *p);
int func_021BD0FC(u32 a);
u16 func_021BD118(u8 *p);
void func_021BD120(Obj *p, u16 v);
u32 func_021BD134(u8 *p);
u8 func_021BD138(u8 *p);
void func_021BD140(void *a, int b, int c);
void *func_021BD148(int a0, int a1, int a2, int a3);
int func_021BD184(void *a, u32 b, u32 c, u32 d);
int func_021BD19C(u32 a, u32 b);
void func_021BD1CC(void *a);
void func_021BD1D4(void *a);
int func_021BD1DC(u8 *a0);
void func_021BD1E4(void *p, unsigned int a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD0FC(u32 a)
{
return func_020089A0((u32)func_02008854(func_02012EBC(func_020120F4((const struct Ctx *)(((struct Obj00575 *)((u8 *)(a)))->f0)))), *(u16 *)((u8 *)((a + 70))));
}


u16 func_021BD118(u8 *p)
{
    return ((struct Obj18211 *)p)->f46;
}


void func_021BD120(Obj *p, u16 v)
{
    p->h44 = p->h46;
    p->h46 = v;
}


u32 func_021BD134(u8 *p)
{
    return ((struct Obj18214 *)p)->f1C;
}


/*
 * Loads the byte at byte +0x20 of the object.
 */
u8 func_021BD138(u8 *p)
{
    return ((struct Obj18215 *)p)->f20;
}


void func_021BD140(void *a, int b, int c)
{
    func_02013E6C((u32)a);
}


void *func_021BD148(int a0, int a1, int a2, int a3)
{
    void *p = func_021BD214(a0);
    func_021BD234(p);
    func_021BD2BC(p, a0);
    func_021BD250(p);
    func_021BD278(p, a1, a2, a3);
    func_021BD5F8(p, 0);
    return p;
}


int func_021BD184(void *a, u32 b, u32 c, u32 d)
{
func_021BD2A4((u32)a, b, c, d);
func_021BD264((u8 *)a);
return func_021BD22C(a);
}


int func_021BD19C(u32 a, u32 b)
{
func_021BD2C4((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f20);
func_021BD2D0((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f24);
func_021BD30C((char *)a);
func_021BD57C((u8 *)a);
func_021BD588((u32 *)a);
return func_021BD554(a, b);
}


/*
 * Tail-call thunk: forwards to func_021BD3BC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1CC(void *a)
{
    func_021BD3BC(a);
}


void func_021BD1D4(void *a)
{
    func_021BD474();
}


/*
 * Tail-call thunk: forwards to func_021BD308 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021BD1DC(u8 *a0)
{
    return func_021BD308(a0);
}


/*
 * Tail-call thunk: forwards to func_021BD5F8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD1E4(void *p, unsigned int a)
{
func_021BD5F8(p, a);
}
