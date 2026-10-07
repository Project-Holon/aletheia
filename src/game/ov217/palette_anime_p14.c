/*
 * file:     palette_anime_p14.c
 * unit:     yes
 * function: func_021C2888, func_021C288C, func_021C2894, func_021C28A4, func_021C28BC
 * address:  0x021C2888
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj26023.h"
#include "../../matched/include/Obj03957.h"
#include "../../matched/include/Obj26024.h"
#include "../../matched/include/Obj26025.h"
#include "../../matched/include/Obj26026.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int _s32_div_f(int, int);
void func_021C2888(void *p, u8 v);
void func_021C288C(void *p, u32 a, u32 b);
u8 func_021C2894(char *p);
u8 func_021C28A4(char *p);
u8 func_021C28BC(char *p);


/*
 * Field setter, u8 at +2.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2888(void *p, u8 v)
{
    ((struct Obj26023 *)p)->f2 = v;
}


/*
 * Store two u32 arguments at +4 and +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C288C(void *p, u32 a, u32 b)
{
    ((struct Obj03957 *)p)->f4 = a;
    ((struct Obj03957 *)p)->f8 = b;
}


/*
 * Addresses are Black-image addresses.
 */
u8 func_021C2894(char *p)
{
    return (u8)(((struct Obj26024 *)p)->f2 % 10);
}


u8 func_021C28A4(char *p)
{
    int t = ((struct Obj26025 *)p)->f2 % 100;
    return (u8)(t / 10);
}


u8 func_021C28BC(char *p)
{
    return (u8)(((struct Obj26026 *)p)->f2 / 100);
}
