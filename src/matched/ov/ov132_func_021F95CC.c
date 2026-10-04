/*
 * function: func_021F95CC
 * address:  0x021F95CC
 * packet:   pkt_021F95CC
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The original stores p+0xEC = 1 unconditionally after the if/else, so the
 * store is a shared tail reached by both arms (b .end out of the `c == 1`
 * arm); writing it inside the else made the compiler emit two epilogues.
 * See docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 */
#include "../include/Obj10532.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021F95CC(char *p, u8 v, int c)
{
    if (c == 1) {
        ((struct Obj10532 *)p)->fF0 = v;
    } else {
        ((struct Obj10532 *)p)->fF0 = 4;
    }
    ((struct Obj10532 *)p)->fEC = 1;
}
