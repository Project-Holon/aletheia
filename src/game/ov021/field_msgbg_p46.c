/*
 * file:     field_msgbg_p46.c
 * unit:     yes
 * function: func_0218FE50, func_0218FE70, func_0218FE78, func_0218FE80, func_0218FE98, func_0218FEA0, func_0218FEA4
 * address:  0x0218FE50
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
 *   func_021900C4  0x021900C4  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_0218FF30  0x0218FF30  thumb
 *   func_0218FF50  0x0218FF50  thumb
 *   func_0218FF48  0x0218FF48  thumb  ov021
 *   func_0218FFE8  0x0218FFE8  thumb  ov021
 *   func_02190058  0x02190058  thumb  ov021
 *   func_021900A8  0x021900A8  thumb  ov021
 *   func_0218FF78  0x0218FF78  thumb  ov021
 */
#include "../../matched/include/Obj19576.h"
#include "../../matched/include/Obj17917.h"
#include "../../matched/include/Obj02372.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
    u32 unk9c;
} Sub;

extern void func_021900C4();
extern u16 func_02188C84(u8 *p);
extern void *func_0218FF30(u32 heap);
extern void func_0218FF50(u32 *o, void *a);
extern void func_0218FF48(void *a0);
extern u32 func_0218FF78(u32 *p);
extern void func_0218FFE8(u8 *a, u32 a1, u32 a2, u32 a3);
extern void func_02190058(u8 *o);
extern void func_021900A8(void *a);
int func_0218FE50(u8 *a);
u8 *func_0218FE70(u8 *p);
void func_0218FE78(void);
void *func_0218FE80(void *a);
void func_0218FE98(void *a0);
void func_0218FEA0(u8 *p, u32 v);
int func_0218FEA4(u32 a, u32 b, u32 c, u32 d);


int func_0218FE50(u8 *a)
{
    Sub *s = (Sub *)(a + 0xf0);
    if (((struct Obj19576 *)a)->f1AC != 0 && s->unk9c != 0)
        return 1;
    return 0;
}


/*
 * Returns the object pointer advanced by 340 bytes.
 */
u8 *func_0218FE70(u8 *p)
{
    return p + 340;
}


/*
 * Tail-call thunk: forwards to func_021900C4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FE78(void)
{
    func_021900C4();
}


void *func_0218FE80(void *a)
{
    void *o = func_0218FF30(func_02188C84(a));
    func_0218FF50(o, a);
    return o;
}


/*
 * Tail-call thunk: forwards to func_0218FF48 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FE98(void *a0)
{
    func_0218FF48(a0);
}


/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FEA0(u8 *p, u32 v)
{
    ((struct Obj17917 *)p)->f8 = v;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218FEA4(u32 a, u32 b, u32 c, u32 d)
{
func_0218FFE8((u8 *)a, b, c, d);
func_02190058((u8 *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
func_021900A8((void *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
return func_0218FF78((u32 *)a);
}
