/*
 * file:     weather_task_p32.c
 * unit:     yes
 * function: func_021A3680, func_021A368C, func_021A3698, func_021A36A4, func_021A36B0, func_021A36BC, func_021A36C8
 * address:  0x021A3680
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
 *   func_021A5928  0x021A5928  thumb
 *   func_021A5964  0x021A5964  thumb  ov021
 *   func_021A59EC  0x021A59EC  thumb
 *   func_021A5A30  0x021A5A30  thumb  ov021
 *   func_021A5A00  0x021A5A00  thumb  ov021
 *   func_021A5A0C  0x021A5A0C  thumb  ov021
 *   func_021A5A18  0x021A5A18  thumb  ov021
 */
#include "../../matched/include/Obj18024.h"
#include "../../matched/include/Obj18025.h"
#include "../../matched/include/Obj18026.h"
#include "../../matched/include/Obj18027.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18028.h"
#include "../../matched/include/Obj18029.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021A5928(u8 *p, int v);
extern void func_021A5964(u32 *p);
extern u32 func_021A59EC(u32 p);
extern u32 func_021A5A30(u32 *p);
extern void func_021A5A00(u8 *p, void *r);
extern void func_021A5A0C(u8 *p, void *a1);
extern int func_021A5A18(u8 *p, u32 k, void *buf);
void func_021A3680(u8 *p, int a1);
void func_021A368C(u8 *p);
u32 func_021A3698(u8 *p);
u32 func_021A36A4(u8 *p);
void func_021A36B0(u8 *p, void *r);
void func_021A36BC(struct Obj18028 *p, void *a1);
int func_021A36C8(u8 *p, u32 k, void *buf);


/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3680(u8 *p, int a1)
{
    func_021A5928((u8 *)(((struct Obj18024 *)p)->fC), a1);
}


void func_021A368C(u8 *p)
{
    func_021A5964((u32 *)(((struct Obj18025 *)p)->fC));
}


u32 func_021A3698(u8 *p)
{
    return func_021A59EC(((struct Obj18026 *)p)->fC);
}


u32 func_021A36A4(u8 *p)
{
    return func_021A5A30((u32 *)(((struct Obj18027 *)p)->fC));
}


/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36B0(u8 *p, void *r)
{
    func_021A5A00(*(u8 * *)&((struct Obj00614 *)p)->fC, r);
}


/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36BC(struct Obj18028 *p, void *a1)
{
    func_021A5A0C((u8 *)(p->fC), a1);
}


/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A18.
 *
 * Addresses are Black-image addresses.
 */
int func_021A36C8(u8 *p, u32 k, void *buf)
{
    return func_021A5A18(*(u8 * *)&((struct Obj18029 *)p)->fC, k, buf);
}
