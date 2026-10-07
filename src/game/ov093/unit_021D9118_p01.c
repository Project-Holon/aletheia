/*
 * file:     unit_021D9118_p01.c
 * unit:     yes
 * function: func_021D927C, func_021D928C
 * address:  0x021D927C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D92CC   0x021D92CC  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "../../matched/include/Obj21283.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D76BC(int key, u32 val);
/* 021D927C shifted 4-arg wrapper -> func_021D92CC(..., 0xc6) */ void func_021D927C(int a, int b, int c, int d);
void func_021D928C(int a, int b, int c, int d);


/* 021D927C  shifted 4-arg wrapper -> func_021D92CC(..., 0xc6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0xc6; bl func_021D92CC; pop {r3, pc}.
 */
void func_021D927C(int a, int b, int c, int d)
{
    func_021D92CC(b, c, d, 0xc6);
}


void func_021D928C(int a, int b, int c, int d)
{
    if (b == func_021D775C(2) && b != func_021D775C(3)) {
        if (d == 8 || d == func_021D775C(0x1f)) {
            if (func_021D775C(0x20) < 0)
                ((struct Obj21283 *)c)->f0 = func_021D76BC(0x41, 1);
        }
    }
}
