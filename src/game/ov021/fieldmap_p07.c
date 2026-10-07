/*
 * file:     fieldmap_p07.c
 * unit:     yes
 * function: func_02188D24, func_02188D2C, func_02188D30, func_02188D38, func_02188D40, func_02188D48, func_02188D4C
 * address:  0x02188D24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj17876.h"
#include "../../matched/include/Obj17877.h"
#include "../../matched/include/Obj17878.h"
#include "../../matched/include/Obj17879.h"
#include "../../matched/include/Obj17880.h"
#include "../../matched/include/Obj17881.h"
#include "../../matched/include/Obj17882.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u32 func_02188D24(u8 *p);
int func_02188D2C(int *p);
u32 func_02188D30(u8 *p);
u32 func_02188D38(u8 *p);
void func_02188D40(u8 *p, u32 v);
u32 func_02188D48(u8 *p);
void func_02188D4C(u8 *p, u32 v);


/*
 * Loads the 32-bit word at byte +0xbc of the object.
 */
u32 func_02188D24(u8 *p)
{
    return ((struct Obj17876 *)p)->fBC;
}


/*
 * Unlabelled ov021 leaf accessor: returns the word at +0x34 of its argument.
 * Matched to supply the `matched` witness for the ten pending callers that
 * reference it.
 */
int func_02188D2C(int *p)
{
    return ((struct Obj17877 *)p)->f34;
}


/*
 * Loads the 32-bit word at byte +0x110 of the object.
 */
u32 func_02188D30(u8 *p)
{
    return ((struct Obj17878 *)p)->f110;
}


/*
 * Loads the 32-bit word at byte +0x134 of the object.
 */
u32 func_02188D38(u8 *p)
{
    return ((struct Obj17879 *)p)->f134;
}


/*
 * Field setter at +0xf0 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_02188D40(u8 *p, u32 v)
{
    ((struct Obj17880 *)p)->fF0 = v;
}


u32 func_02188D48(u8 *p)
{
    return ((struct Obj17881 *)p)->f2C;
}


/*
 * Field setter at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_02188D4C(u8 *p, u32 v)
{
    ((struct Obj17882 *)p)->f2C = v;
}
