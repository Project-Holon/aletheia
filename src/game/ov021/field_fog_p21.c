/*
 * file:     field_fog_p21.c
 * unit:     yes
 * function: func_021A0E58, func_021A0EB0, func_021A0ED4, func_021A0EE4
 * address:  0x021A0E58
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
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   d_021D8734  0x021D8734  data  a4
 *   d_021D8738     0x021D8738  data
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02013D00  0x02013D00  thumb
 */
#include "../../matched/include/G_021D8738.h"
#include "../../matched/include/Obj17989.h"

struct Big;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef signed char    s8;

extern int func_02189A2C(int *a);
extern void *func_02188C80(void *p);
extern u16 func_02188C9C(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02009210(void);
extern u32 func_020090E0(void);
extern u32 func_02013D20(void);
extern u32 func_02013D00(u32);
void func_021A0E58(u32 *a);
int func_021A0EB0(u32 *p, u32 a);
int func_021A0ED4(u32 a);
u32 ov021_func_021A0EE4(u32 *p, u32 x);
extern u8 d_021D8734[];
extern struct G_021D8738 d_021D8738[];


/*
 * Addresses are Black-image addresses.
 */
void func_021A0E58(u32 *a)
{
    s32 r;

    switch (a[2]) {
    case 0:
        if (*(u32 *)(d_021D8734 + a[0] * 0x1c) != 0) {
            r = func_02189A2C((int *)a[5]);
            ((void (*)(u32 *, s32))*(u32 *)(d_021D8734 + a[0] * 0x1c))(a, r == 0);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
}


int func_021A0EB0(u32 *p, u32 a)
{
    if (p[2] == 0 && d_021D8738[p[0]].init != 0)
        return d_021D8738[p[0]].init(p, a);
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0ED4(u32 a)
{
if (((struct Obj17989 *)((u8 *)(a)))->f8 == 0) {
    return 1;
}
return 0;
}


u32 ov021_func_021A0EE4(u32 *p, u32 x)
{
    u32 a, b;
    if (x == 0) {
        a = (u32)func_020120F4(func_02188C80((void *)p[5]));
        b = func_02188C9C((u8 *)p[5]);
        if (func_02013D20() != 0 || func_02013D00(b) != 0)
            return 5;
        func_02012EBC((struct Big *)a);
        func_02009210();
        if (func_020090E0() == 0)
            return 5;
    }
    return x;
}
