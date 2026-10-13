/*
 * function: func_021BD014
 * address:  0x021BD014
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *
 * Asks the arm9 predicate at 0x020362DC about the block; on a non-zero answer
 * stamps 0x6E in the byte at +0x1353 and selector 0x8A.  Returns the second
 * argument.  The predicate takes only the block.
 */
#include "../include/Obj12114.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 KEY_GetTrg(void);

int func_021BD014(char *p, int v)
{
    if (KEY_GetTrg() != 0) {
        ((struct Obj12114 *)p)->f1353 = 0x6E;
        ((struct Obj12114 *)p)->f1CC = 0x8A;
    }
    return v;
}
