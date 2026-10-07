/*
 * file:     fldeff_ripple_p03.c
 * unit:     yes
 * function: func_021C3A7C, func_021C3A90, func_021C3AAC, func_021C3ADC
 * address:  0x021C3A7C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 *   func_021C4504  0x021C4504  thumb  ov021
 */
#include "../../matched/include/Obj18302.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02082BCC(u32, u32, u32, u32);
extern int func_021C3BB0(u32 a);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u16 func_021C4504(u16 sp);
extern u32 func_02005728(u32 v);
int func_021C3A7C(u32 a, u32 b, u32 c, u32 d);
void func_021C3A90(void *a, u32 *out);
void func_021C3AAC(void *a, u32 *out);
void func_021C3ADC(void *a, u32 *out);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C3A7C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 140, d);
((struct Obj18302 *)((u8 *)(a)))->f8 = 1;
return 1;
}


/*
 * Stores the base form of the parent species.
 */
void func_021C3A90(void *a, u32 *out)
{
    *out = func_021C4504(func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0));
}


/*
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 */
void func_021C3AAC(void *a, u32 *out)
{
    u32 sp = func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0);

    if (sp == 0x1D || sp - 0x20 <= 2) {
        if (func_02005728(2) == 0)
            *out = 0x1D;
        else
            *out = 0x20;
    }
}


/*
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 */
void func_021C3ADC(void *a, u32 *out)
{
    u32 sp = func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0);

    if (sp == 0x139 || sp == 0x13A) {
        if (func_02005728(2) == 0)
            *out = 0x139;
        else
            *out = 0x13A;
    }
}
