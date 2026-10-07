/*
 * file:     scrcmd_screeneffects_p26.c
 * unit:     yes
 * function: func_021B0EDC, func_021B0EE8
 * address:  0x021B0EDC
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
 *   func_021B0A88  0x021B0A88  thumb
 *   func_021B0AB0  0x021B0AB0  thumb  ov021
 */
#include "../../matched/include/Obj18091.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed int     s32;

extern void func_021B0A88();
extern void func_021B0AB0(u32 v);
u32 func_021B0EDC(void);
int func_021B0EE8(u8 *p);


/*
 * Calls func_021B0A88() and returns 0x1.
 */
u32 func_021B0EDC(void)
{
    func_021B0A88();

    return 0x1;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0EE8(u8 *p)
{
    func_021B0AB0(((struct Obj18091 *)p)->f4);
    return 1;
}
