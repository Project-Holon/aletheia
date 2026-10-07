/*
 * file:     weather_task_p50.c
 * unit:     yes
 * function: func_021A482C, func_021A4890, func_021A48A4
 * address:  0x021A482C
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
 *   func_021A5390  0x021A5390  thumb  ov021
 *   func_021A56F4  0x021A56F4  thumb  ov021
 *   func_0219F7CC  0x0219F7CC  thumb  ov021
 *   func_021A5708  0x021A5708  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A56C0  0x021A56C0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb  ov021
 */
#include "../../matched/include/Obj02083.h"
#include "../../matched/include/Obj19788.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021A5390(u32 a);
extern int func_021A56F4(u32 a);
extern int func_0219F7CC(u32, u32);
extern int func_021A5708(u32 a);
extern void func_021A53A4(u32 *p, int on);
extern int func_021A47B4(u8 *, u32, u8 *);
extern int func_0216D3CC(int a0);
extern void func_021A54B4(u8 *p);
extern u32 func_021A56C0(u32 *p, u32 a1, u32 a2, u32 a3);
int ov021_func_021A482C(u8 *a, u32 b, u8 *c);
int func_021A4890(u8 *a, u32 b, u32 c);
int func_021A48A4(u32 a, u32 b, u32 c, u32 d);


int ov021_func_021A482C(u8 *a, u32 b, u8 *c)
{
    if (((struct Obj19788 *)c)->f8 == 9) {
        if (func_021A5390((u32)a) == 0) {
            func_021A56F4((u32)a);
        }
        if (((struct Obj02083 *)a)->f16 == 1) {
            if (func_0219F7CC(b, ((struct Obj02083 *)a)->f14) != 0) {
                ((struct Obj02083 *)a)->f16 = 0;
            }
        }
        ((struct Obj02083 *)a)->f14 = ((struct Obj02083 *)a)->f14 + 1;
        if (((struct Obj02083 *)a)->f14 == 60) {
            func_021A5708((u32)a);
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    } else {
        func_021A5708((u32)a);
        return func_021A47B4(a, b, c);
    }
    return 6;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4890(u8 *a, u32 b, u32 c)
{
if (func_0216D3CC(b) == 1) {
    return 9;
}
return 8;
}


int func_021A48A4(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A56C0((u32 *)a, b, c, d) == 1) {
    func_021A54B4((u8 *)a);
    func_021A53A4((u32 *)a, 0);
    return 1;
}
return 9;
}
