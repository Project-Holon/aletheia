/*
 * file:     unit_021BA874.c
 * unit:     yes
 * function: func_021BA874, func_021BA87C, func_021BA884
 * address:  0x021BA874
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj22574.h"
#include "../../matched/include/Obj22575.h"
#include "../../matched/include/Obj22576.h"

typedef unsigned char u8;

typedef unsigned int u32;

void func_021BA874(u8 *p, int v);
void func_021BA87C(u8 *p, int v);
u32 func_021BA884(u8 *p);

void func_021BA874(u8 *p, int v)
{
    ((struct Obj22574 *)p)->f14 = v;
}

/*
 * Word setter at +0x10.
 */
void func_021BA87C(u8 *p, int v)
{
    ((struct Obj22575 *)p)->f10 = v;
}

/*
 * Word getter at +0x10.
 */
u32 func_021BA884(u8 *p)
{
    return ((struct Obj22576 *)p)->f10;
}
