/*
 * file:     scrcmd_screeneffects_p36.c
 * unit:     yes
 * function: func_021B1CB0, func_021B1CFC
 * address:  0x021B1CB0
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021A32A8  0x021A32A8  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_021A2F54  0x021A2F54  thumb  ov021
 */
#include "../../matched/include/Obj18096.h"

struct Ctx;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021A32A8(void *, u32);
extern u16 func_0216D588(void *p);
extern int func_02158F58(int a0);
extern void *func_0215A5F4(void *p);
extern int func_021A2F54(u8 *p);
int func_021B1CB0(u32 a, u32 b);
int func_021B1CFC(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
int func_021B1CB0(u32 a, u32 b)
{
    void *h;
    u16 *p;
    u16 *q;
    int r;

    h = func_02188CB4(func_0201210C(func_0215A5DC((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    q = func_02159AE8((void *)a, (void *)b);
    r = func_021A32A8(h, 0x8000);
    if (r != 0) {
        *q = 1;
        *p = func_0216D588((void *)r);
    } else {
        *q = 0;
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B1CFC(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A2F54(func_02188CB4(((struct Obj18096 *)((u8 *)(func_02158F58((int)func_0215A5F4((void *)b)))))->f4)) == 1) {
    return 1;
}
return 0;
}
