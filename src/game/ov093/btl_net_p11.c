/*
 * file:     btl_net_p11.c
 * unit:     yes
 * function: func_021D4B98, func_021D4BD4
 * address:  0x021D4B98
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
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4330 0x021D4330 thumb ov093
 *   func_021D4394   0x021D4394  thumb ov093
 *   func_021F3B88   0x021F3B88  data
 */
#include "../../matched/include/Obj18402.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D4330(int);
u8 func_021D4394(u32 a);
int func_021D4B98(void);
u16 func_021D4BD4(int a, u8 **q);
extern u8 *d_021F3B88;
extern u8 *func_021F3B88;

int func_021D4B98(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && *(u16 *)(d_021F3B88 + i * 0xbbc + 0x17ae) != 0)
            return 0;
    }
    return 1;
}


/*
 * Index a 0xBBC-stride table hanging off the pointer global at 0x021F3B88
 * plus 0xBF4, return the element's +0xBB8 halfword through *q.  The image
 * reaches 0xBBC and 0xBB8 by subtracting 0x38 and 0x3c from the 0xBF4 it
 * already has in r2 (mwcc's constant reuse), which the same expression here
 * reproduces.
 */
u16 func_021D4BD4(int a, u8 **q)
{
    u8 *p = func_021F3B88 + 0xbf4 + func_021D4394(a) * 0xbbc;
    *q = p;
    return ((struct Obj18402 *)p)->fBB8;
}
