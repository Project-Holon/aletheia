/*
 * file:     field_flash_p07.c
 * unit:     yes
 * function: func_021C77D8, func_021C7814, func_021C7844
 * address:  0x021C77D8
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_0204E720  0x0204E720  arm
 */
#include "../../matched/include/Obj07232.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u32 x, y, z; } V;

typedef struct { u16 f0; u16 f2; } X_021C77D8;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } X_021C7814;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

extern u16 func_02188C84(u8 *p);
extern Q *func_021C6C70(u32 heap, u32 size, void *fn);
extern u32 func_021C6CCC(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
Q *func_021C77D8(u32 a, u16 b);
int func_021C77FC(X_021C77D8 *x);
Q *func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e);
int func_021C7844(u32 a, u32 b, u32 c);

Q *func_021C77D8(u32 a, u16 b)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 4, func_021C77FC);
    X_021C77D8 *x = (X_021C77D8 *)func_021C6CCC((u8 *)q);
    x->f0 = 0;
    x->f2 = b;
    return q;
}


int func_021C77FC(X_021C77D8 *x)
{
    x->f0++;
    if (x->f2 <= x->f0)
        return 1;
    return 0;
}

Q *func_021C7814(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    Q *q = func_021C6C70(func_02188C84((u8 *)a), 0x14, func_021C7844);
    X_021C7814 *x = (X_021C7814 *)func_021C6CCC((u8 *)q);
    x->f0 = a;
    x->f4 = b;
    x->f8 = c;
    x->fC = d;
    x->f10 = e;
    return q;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C7844(u32 a, u32 b, u32 c)
{
func_0204E720(((struct Obj07232 *)((u8 *)(a)))->f4, ((struct Obj07232 *)((u8 *)(a)))->f8, ((struct Obj07232 *)((u8 *)(a)))->fC, ((struct Obj07232 *)((u8 *)(a)))->f10);
return 1;
}
