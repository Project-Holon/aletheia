/*
 * file:     unit_0219B508_p11.c
 * unit:     yes
 * function: func_0219C034, func_0219C04C
 * address:  0x0219C034
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
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 */
#include "../../matched/include/Obj17963.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02197EDC(u8 *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern u16 func_0216D608(void *p);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
int func_0219C034(u32 a, u32 b, u32 c, u32 d);
int func_0219C04C(u32 a, s8 *s);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C034(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    ((struct Obj17963 *)((u8 *)(b)))->f0 = 2;
    return 1;
}
return 0;
}


int func_0219C04C(u32 a, s8 *s)
{
    u32 o;
    if (s[1] == 9) {
        o = (u32)func_0216DEE0(func_0216D67C((void *)a));
        if (o != 0) {
            s[1] = func_0216D608((void *)o);
        }
    }
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    s[0] = 3;
    return 1;
}
