/*
 * file:     worldtrade_adapter_p39.c
 * unit:     yes
 * function: func_02201DD8, func_02201DF0, func_02201E04
 * address:  0x02201DD8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 */
#include "../../matched/include/Obj12241.h"
#include "../../matched/include/Obj18613.h"
#include "../../matched/include/Obj12242.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

extern void func_021F4EC0(u8 *p, u32 a, u32 b);
int func_02201DD8(u8 *p);
int func_02201DF0(u8 *p);
int func_02201E04(u8 *p);


/*
 * Enter the 201DD8 sub-state: flag the u16 at +0x32, set the two work values and stamp the state.
 */
int func_02201DD8(u8 *p)
{
    ((struct Obj12241 *)p)->f32 = 0;
    func_021F4EC0(p, 9, 8);
    ((struct Obj12241 *)p)->f28 = 0x28;
    return 2;
}


/*
 * Set the mode pair and latch state 0x28.
 */
int func_02201DF0(u8 *p)
{
    func_021F4EC0(p, 0x9, 0x9);
    ((struct Obj18613 *)p)->f28 = 0x28;
    return 2;
}


int func_02201E04(u8 *p)
{
    ((struct Obj12242 *)p)->f32 = 0;
    func_021F4EC0(p, 9, 10);
    ((struct Obj12242 *)p)->f28 = 0x22;
    return 2;
}
