/*
 * file:     field_fog_p23.c
 * unit:     yes
 * function: func_021A0F94, func_021A0FA0, func_021A0FA8, func_021A0FB4
 * address:  0x021A0F94
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
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021902A4  0x021902A4  thumb  ov021
 */
#include "../../matched/include/Obj17991.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02188E30(u8 *p);
extern void func_021D3270(u32, u32, u32, u32, u32, u32);
extern void func_02193060(u32);
extern void func_020414EC(u32 i);
extern void func_021902A4(u32, u32);
int func_021A0F94(u32 a);
void func_021A0FA0(int *p, int v);
void func_021A0FA8(int *p);
void func_021A0FB4(u32 *p, u32 a);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0F94(u32 a)
{
if (a != 0) {
    return ((struct Obj17991 *)((u8 *)(a)))->f10;
}
return 0;
}


/*
 * Guarded store of the second argument at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA0(int *p, int v)
{
    if (p == 0)
        return;
    p[4] = v;
}


/*
 * Tail call with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A0FA8(int *p)
{
    func_021A0FA0(p, 0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0FB4(u32 *p, u32 a)
{
    func_021D3270(func_02188E30((u8 *)p[5]), 1, 0, 0, 0, 0);
    func_02193060(0);
    func_020414EC(1);
    func_021902A4(1, a);
}
