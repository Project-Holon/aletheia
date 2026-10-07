/*
 * file:     wih_p15.c
 * unit:     yes
 * function: func_02179368, func_02179394
 * address:  0x02179368
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021795A4  0x021795A4  thumb  ov014
 *   func_02178E38  0x02178E38  thumb  ov014
 *   func_02178D20  0x02178D20  thumb  ov014
 *   g_021797A8 0x021797A8 data a4
 *   func_02090B18 0x02090B18 arm
 */
#include "../../matched/include/G_S.h"

typedef int BOOL;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern unsigned short func_021795A4(void);
extern u16 func_02178E38(void);
extern int func_02178D20(u32 a, u32 b, u32 c);
extern int func_02090B18(void *info, void *buffer, u16 slot);
BOOL func_02179368(int a, u16 b, int c);
int func_02179394(u16 slot);
extern struct S *g_021797A8;


/*
 * Guard wrapper: forwards to func_02178D20 when func_021795A4 is nonzero or
 * one of bits 1-7 of func_02178E38 is set, else returns 0.  The unlabelled
 * follower at 02179394 (adds the block's +0x1C64 / +0x1444 to g_021797A8,
 * tail calls a thumb function) is why the extent runs long.
 */
BOOL func_02179368(int a, u16 b, int c)
{
    if (func_021795A4() == 0 && (func_02178E38() & 0xFE) == 0)
        return 0;
    return func_02178D20(a, b, c);
}

/*
 * extent: existing matched 021793B8 follows the 36-byte leaf.
 */
int func_02179394(u16 slot)
{
    return func_02090B18(((u8 *)g_021797A8) + 0x1444, ((u8 *)g_021797A8) + 0x1C64, slot);
}
