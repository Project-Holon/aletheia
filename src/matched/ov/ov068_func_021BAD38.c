/*
 * function: func_021BAD38
 * address: 0x021BAD38
 * packet: pkt_ov068_021BAD38
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: name the call result before addition (commutative operand idiom).
 * Arithmetic: unsigned word addition/subtraction wraps before signed division.
 * symbols:
 *   func_02040804 0x02040804 arm
 */
#include "../include/Obj13142.h"
#include "../include/Obj20646.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02040804(u32 layer);
int func_021BAD38(u8 *p, u8 *q)
{
    int n;
    n = func_02040804(((struct Obj13142 *)p)->f2);
    n = (int)((u32)n + ((struct Obj20646 *)q)->f4 - 16u) / 24;
    if ((u32)n >= 5) n = ((struct Obj13142 *)p)->f4;
    return n;
}
