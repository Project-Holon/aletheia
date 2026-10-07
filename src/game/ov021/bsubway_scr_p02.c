/*
 * file:     bsubway_scr_p02.c
 * unit:     yes
 * function: func_021C8868, func_021C88AC, func_021C88EC, func_021C8960
 * address:  0x021C8868
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021C8738  0x021C8738  thumb  ov021
 *   func_021C86E8  0x021C86E8  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C87D4  0x021C87D4  thumb  ov021
 *   func_021C8810  0x021C8810  thumb  ov021
 */
#include "../../matched/include/Obj18340.h"
#include "../../matched/include/Obj18341.h"

struct Ctx;
struct Big;
struct Stream;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012ED0(struct Big *p);
extern u16 func_02011330(struct Stream *s);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_021C8738(char *p, int k);
extern u32 func_021C86E8(u32, u32, u32);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_021C87D4(char *p, int i, int v);
extern u32 func_021C8810(u32);
int func_021C8868(int a, int b);
int func_021C88AC(u32 a, u32 b, u32 c, u32 d);
int func_021C88EC(int a, int b);
int func_021C8960(u32 a, u32 b, u32 c, u32 d);


int func_021C8868(int a, int b)
{
    int *r4;
    int r7;
    unsigned short *r5;

    func_0215A5F4((void *)b);
    r4 = (int *)func_02012ED0(func_020120F4((void *)func_02188C80(func_0201210C(func_0215A5DC((void *)b)))));
    r7 = func_02011330((struct Stream *)a);
    r5 = func_02159AE8((void *)a, (void *)b);
    *r5 = func_021C8738((char *)(*r4), r7);
    return 0;
}


int func_021C88AC(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021C86E8(((struct Obj18340 *)((u8 *)(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))))))->f0, func_02011330((struct Stream *)a), func_02011330((struct Stream *)a));
return 0;
}


int func_021C88EC(int a, int b)
{
    int *r7;
    int sp;
    int r5;
    int v;

    func_0215A5F4((void *)b);
    r7 = (int *)func_02012ED0(func_020120F4(func_0215A5DC((void *)b)));
    sp = (int)func_02159B10((void *)a, (void *)b);
    r5 = func_02011330((struct Stream *)a);
    func_02011330((struct Stream *)a);
    v = (int)func_02159B10((void *)a, (void *)b);
    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        func_021C87D4((char *)(*r7), sp, v == 1);
        break;
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C8960(u32 a, u32 b, u32 c, u32 d)
{
func_021C8810(((struct Obj18341 *)((u8 *)(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC((void *)b))))))))->f0);
return 0;
}
