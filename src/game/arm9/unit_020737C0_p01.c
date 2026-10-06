/*
 * file:     unit_020737C0_p01.c
 * unit:     yes
 * function: func_02073838, func_02073898
 * address:  0x02073838
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08946.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern int func_0207292C(int mask);
int func_02073838(u8 *o, int n, u8 *src) {

    u32 m = 0;
    int i;
    for (i = 0; i < n; i++) {
        o[0x54 + i] = src[i];
        m |= 1u << src[i];
    }
    if (func_0207292C(m) == 0) return 0;
    ((struct Obj08946 *)o)->f50 = n;
    ((struct Obj08946 *)o)->f4C = m;
    return 1;
}

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct X { u8 pad00[0x4c]; u32 f4c; u32 f50; };

extern void func_02072974(u32);


/*
 * Releases the registered slot when one is held: the mask to drop is the value
 *  * in +0x4c itself, and the same zero then clears +0x4c and +0x50 out of one
 *  * `mov r0, #0`.
 */
void func_02073898(struct X *x)
{
    if (x->f4c == 0) return;
    func_02072974(x->f4c);
    x->f4c = 0;
    x->f50 = 0;
}
