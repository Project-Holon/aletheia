/*
 * file:     field_player_grid_event_p06.c
 * unit:     yes
 * function: func_021BF860, func_021BF874, func_021BF898
 * address:  0x021BF860
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
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C72AC  0x021C72AC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_021BF8DC 0x021BF8DC thumb ov021
 */
#include "../../matched/include/Obj12121.h"
#include "../../matched/include/Obj01860.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0218FE98(u32);
extern void func_0218FF20(u8 *a);
extern u32 func_02188D38(u8 *p);
extern u32 func_021C6DE0(u32, u32, u32);
extern void *func_021C72AC(u32 a, u16 b, int c, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5);
extern void func_021BF8DC(u8 *);
int func_021BF860(void **a);
int func_021BF874(void **a);
void *func_021BF898(int *q);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BF860(void **a)
{
func_0218FF20((u8 *)(((struct Obj12121 *)((u8 *)(a)))->f58));
return func_0218FE98(((struct Obj12121 *)((u8 *)(a)))->f58);
}


int func_021BF874(void **a)
{
return func_021C6DE0(func_02188D38((u8 *)(((struct Obj01860 *)((u8 *)(a)))->f4)), (u32)func_021C72AC(((struct Obj01860 *)((u8 *)(a)))->f4, 60, 8, 1), 0);
}


void *func_021BF898(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return func_021BE9A0((void *)a, b, (u8)q[24], (u8)q[25], (int)func_021BF8DC, (int)q);
    }
    return (void *)func_021BE92C((void *)a, b, 1, 1, 1, 0, 0);
}
