/*
 * file:     fldeff_iwakudaki_p06.c
 * unit:     yes
 * function: func_021AE550, func_021AE56C, func_021AE58C, func_021AE5A8, func_021AE5BC
 * address:  0x021AE550
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
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 */
#include "../../matched/include/Obj12098.h"
#include "../../matched/include/Obj07221.h"
#include "../../matched/include/Obj09182.h"
#include "../../matched/include/Obj12099.h"
#include "../../matched/include/Obj12100.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021BB528(u32, u32, u32, u32);
extern u32 func_021AC154(u32);
extern int func_021BB5C8(u32 a);
extern void func_0216D410(void *a0, u16 a1);
int func_021AE550(u32 a, u32 b, u32 c, u32 d);
int func_021AE56C(u32 a, u32 b, u32 c, u32 d);
int func_021AE58C(u32 a, u32 b, u32 c, u32 d);
int func_021AE5A8(u32 a, u32 b, u32 c, u32 d);
int func_021AE5BC(u32 a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE550(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(((struct Obj12098 *)((u8 *)(a)))->f8, b, c, d) == 0) {
    return 0;
}
((struct Obj12098 *)((u8 *)(a)))->f0 = 5;
return 1;
}


int func_021AE56C(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj07221 *)((u8 *)(a)))->f2C = func_021BB528(func_02188CD0((u8 *)(((struct Obj07221 *)((u8 *)(a)))->f30)), ((struct Obj07221 *)((u8 *)(a)))->f8, 0, 0);
((struct Obj07221 *)((u8 *)(a)))->f0 = 6;
return 0;
}


int func_021AE58C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021BB5C8(((struct Obj09182 *)((u8 *)(a)))->f2C) == 1) {
    func_021AC154(((struct Obj09182 *)((u8 *)(a)))->f2C);
    ((struct Obj09182 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}


int func_021AE5A8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410((void *)(((struct Obj12099 *)((u8 *)(a)))->f8), 101);
((struct Obj12099 *)((u8 *)(a)))->f0 = 8;
return 0;
}


int func_021AE5BC(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(((struct Obj12100 *)((u8 *)(a)))->f8, b, c, d) == 1) {
    ((struct Obj12100 *)((u8 *)(a)))->f0 = 9;
}
return 0;
}
