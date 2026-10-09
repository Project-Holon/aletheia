/*
 * file:     ircbattlemenu_p03.c
 * unit:     yes
 * function: func_02197DF4, func_02197E10, func_02197E28
 * address:  0x02197DF4
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
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 */
#include "../../matched/include/Obj12072.h"
#include "../../matched/include/Obj09177.h"
#include "../../matched/include/Obj12073.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(int a0, u32 a1, u32 a2, u32 a3);
int func_02197DF4(u32 a);
int func_02197E10(u32 a, u32 b, u32 c, u32 d);
int func_02197E28(u32 a, u32 b, u32 c, u32 d);



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02197DF4(u32 a)
{
if (func_0216D3CC(((struct Obj12072 *)((u8 *)(a)))->fC) == 0) {
    return 0;
}
((struct Obj12072 *)((u8 *)(a)))->f0 = 2;
return 1;
}



int func_02197E10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410((void *)(((struct Obj09177 *)((u8 *)(a)))->fC), *(u16 *)((u8 *)(((struct Obj09177 *)((u8 *)(a)))->f10)));
((struct Obj09177 *)((u8 *)(a)))->f0 = 3;
return 0;
}


int func_02197E28(u32 a, u32 b, u32 c, u32 d)
{
if (func_0216D454(((struct Obj12073 *)((u8 *)(a)))->fC, b, c, d) == 0) {
    return 0;
}
((struct Obj12073 *)((u8 *)(a)))->f0 = 4;
return 1;
}
