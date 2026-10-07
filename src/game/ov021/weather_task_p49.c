/*
 * file:     weather_task_p49.c
 * unit:     yes
 * function: func_021A4768, func_021A47B4
 * address:  0x021A4768
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_021A482C  0x021A482C  thumb  ov021
 *   func_021A4768  0x021A4768  thumb  ov021
 *   func_021A569C  0x021A569C  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021A53A4  0x021A53A4  thumb  ov021
 */
#include "../../matched/include/Obj09566.h"
#include "../../matched/include/Obj12736.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 func_0216D5F8(void *p);
extern int func_0216D3CC(int a0);
extern int func_021A47B4(u32, u32, u32);
extern int func_021A482C(u32, u32, u32);
extern int func_021A4768(u32, u32, u32);
extern int func_021A569C(u8 *a, void *b, int c, int *d);
extern int func_021AB11C(u32 attr);
extern void func_021A53A4(u32 *p, int on);
int ov021_func_021A4768(u32 a, u32 b, u8 *c);
int ov021_func_021A47B4(u32 a, u32 b, u8 *c);


int ov021_func_021A4768(u32 a, u32 b, u8 *c)
{
    if (func_0216D3CC(b) == 1) {
        if (((struct Obj09566 *)c)->f8 != 9) {
            u32 r = func_0216D5F8((void *)b);
            if (((struct Obj09566 *)c)->f8 != r && ((struct Obj09566 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A47B4(a, b, (u32)c);
        }
        return func_021A482C(a, b, (u32)c);
    }
    return 0;
}


int ov021_func_021A47B4(u32 a, u32 b, u8 *c)
{
    int sp;
    u32 r;
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (((struct Obj12736 *)c)->f8 == 9) {
        return func_021A4768(a, b, (u32)c);
    }
    r = func_021A569C((u8 *)a, (void *)b, ((struct Obj12736 *)c)->f8, &sp);
    if (sp != -1) {
        if (r & 0x100) {
            if (!(r & 0xFFFFFEFF)) {
                return 2;
            }
        } else if (func_021AB11C(sp) == 0) {
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    }
    return 4;
}
