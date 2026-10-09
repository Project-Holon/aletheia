/*
 * file:     field_fog_p04.c
 * unit:     yes
 * function: func_021A0F7C, func_021A0F90, func_021A0F94, func_021A0FA0, func_021A0FA8, func_021A0FB4, func_021A0FE8, func_021A1050, func_021A10C0
 * address:  0x021A0F7C
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
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021902A4  0x021902A4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F279C  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 *   func_021F27D8  0x021F27D8  thumb  ov029
 *   func_021F2984  0x021F2984  thumb  ov029
 *   func_02034A5C  0x02034A5C  arm
 */
#include "../../matched/include/Obj07215.h"
#include "../../matched/include/Obj17990.h"
#include "../../matched/include/Obj17991.h"

struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021A0EE4(u32, u32, u32, u32);
extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32, u32, u32, u32, u32, u32);
extern void func_02193060(u32);
extern void func_020414EC(u32 i);
extern void func_021902A4(u32, u32);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02009210();
extern u8 func_02009208(const struct Sub020090B0Obj *obj);
extern void func_02009200(u32, u32);
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_02012204(const struct Ctx *p);
extern void func_02012210(struct Ctx *p);
extern int func_02034AC4(int);
extern void *func_021F279C(int a, int b, int c, int d);
extern char *func_021F27D8(int a0, int a1, int a2, void (*cb)(int), int arg, int flag);
extern void func_021F2984(char *p);
extern void func_02034A5C(int);
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
u32 func_021A0F90(u8 *p);
int func_021A0F94(u32 a);
void func_021A0FA0(int *p, int v);
void func_021A0FA8(int *p);
void func_021A0FB4(u32 *p, u32 a);
void ov021_func_021A0FE8(u32 *p);
void ov021_func_021A1050(u32 *p);
void func_021A10C0(u32 *p);
extern unsigned char abs_id_1d[];





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0F7C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07215 *)((u8 *)(a)))->f18 = c;
((struct Obj07215 *)((u8 *)(a)))->f1C = d;
((struct Obj07215 *)((u8 *)(a)))->f4 = func_021A0EE4(a, b, c, d);
((struct Obj07215 *)((u8 *)(a)))->f8 = 1;
return 1;
}





/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A0F90(u8 *p)
{
    return ((struct Obj17990 *)p)->f0;
}





int func_021A0F94(u32 a)
{
if (a != 0) {
    return ((struct Obj17991 *)((u8 *)(a)))->f10;
}
return 0;
}





/*
 * Guarded store of the second argument at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA0(int *p, int v)
{
    if (p == 0)
        return;
    p[4] = v;
}





/*
 * Tail call with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA8(int *p)
{
    func_021A0FA0(p, 0);
}





/*
 * Addresses are Black-image addresses.
 */
void func_021A0FB4(u32 *p, u32 a)
{
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, 0);
    func_02193060(0);
    func_020414EC(1);
    func_021902A4(1, a);
}




void ov021_func_021A0FE8(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02009210(func_02012EBC(func_020120F4((const struct Ctx *)a)));
    func_02034AC4((int)abs_id_1d);
    c = func_02009208((const struct Sub020090B0Obj *)b);
    d = func_0201214C((const struct Ctx *)a);
    p[8] = (u32)func_021F279C(b, (int)p, a, d == 1 && c == 0);
    func_02009200(b, d);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
}




void ov021_func_021A1050(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)func_02188C80((void *)p[5]);
    b = (u32)func_02012EBC(func_020120F4((const struct Ctx *)a));
    func_02034AC4((int)abs_id_1d);
    c = func_0201214C((const struct Ctx *)a);
    d = (u32)func_02009210((void *)b);
    p[8] = (u32)func_021F27D8(d, (int)p, (int)func_02188C80((void *)p[5]), (void (*)(int))p[6], p[7], c);
    func_02009200(d, c);
    if (func_02012204((const struct Ctx *)a) != 0)
        func_02012210((struct Ctx *)a);
    p[0] = 0;
    p[1] = 0;
}


void func_021A10C0(u32 *p)
{
    func_021F2984((char *)p[8]);
    func_02034A5C((int)abs_id_1d);
}
