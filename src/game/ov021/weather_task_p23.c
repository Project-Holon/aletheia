/*
 * file:     weather_task_p23.c
 * unit:     yes
 * function: func_021A2F98, func_021A2FA4, func_021A2FB0, func_021A2FD0, func_021A2FE4, func_021A3038, func_021A3044
 * address:  0x021A2F98
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
 *   func_021A3AD4  0x021A3AD4  thumb
 *   func_021A3AB8  0x021A3AB8  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A5778  0x021A5778  thumb  ov021
 *   func_021A59DC  0x021A59DC  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 *   func_021A548C  0x021A548C  thumb
 *   func_021A54A0  0x021A54A0  thumb
 *   func_021A59EC  0x021A59EC  thumb
 *   func_021A396C  0x021A396C  thumb
 *   func_021A3818  0x021A3818  thumb
 *   func_021A3898  0x021A3898  thumb
 *   func_021A38A4  0x021A38A4  thumb
 */
#include "../../matched/include/Obj18009.h"
#include "../../matched/include/Obj18010.h"
#include "../../matched/include/Obj09180.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18011.h"
#include "../../matched/include/Obj18012.h"

struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A3AD4(u8 *p);
extern u16 func_021A3AB8(u32 a, u32 v);
extern u32 func_02188CFC(u8 *p);
extern int func_021A5778(u32 a);
extern int func_021A59DC(u32 a);
extern int func_021A3CB0(u32 a, u32 b);
extern u32 func_021A3CE8(u32);
extern int func_021A548C();
extern int func_021A54A0(u32 a);
extern u32 func_021A59EC(u32 p);
extern void func_021A396C(u8 *p, u32 v);
extern void func_021A3818(u32 *p);
extern void func_021A3898(u8 *p, struct VecFx32 *out);
extern void func_021A38A4(u8 *p, void *v);
u32 func_021A2F98(u8 *p);
u16 func_021A2FA4(u8 *p, u32 a1);
u32 func_021A2FB0(u32 a);
int func_021A2FD0(void *a);
void func_021A2FE4(u32 *p);
void func_021A3038(u8 *p, struct VecFx32 *out);
void func_021A3044(u8 *p, void *v);


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A2F98(u8 *p)
{
    return func_021A3AD4((u8 *)(((struct Obj18009 *)p)->f4));
}


u16 func_021A2FA4(u8 *p, u32 a1)
{
    return func_021A3AB8(((struct Obj18010 *)p)->f4, a1);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A2FB0(u32 a)
{
if (func_02188CFC((u8 *)(((struct Obj09180 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5778(((struct Obj09180 *)((u8 *)(a)))->f8);
}
return func_021A59DC(((struct Obj09180 *)((u8 *)(a)))->fC);
}


int func_021A2FD0(void *a)
{
func_021A3CB0(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4, 1);
return func_021A3CE8(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A2FE4(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0) {
        if (func_021A548C(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
        if (func_021A54A0(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    } else {
        if (func_021A59EC(p[3]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    }
    func_021A3818((u32 *)p[1]);
}


void func_021A3038(u8 *p, struct VecFx32 *out)
{
    func_021A3898((u8 *)((struct Obj18011 *)p)->f4, out);
}


void func_021A3044(u8 *p, void *v)
{
    func_021A38A4((u8 *)((struct Obj18012 *)p)->f4, v);
}
