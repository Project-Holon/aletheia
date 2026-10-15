/*
 * function: PSEL_IsAnimTargetReached
 * address: 0x021B9B4C
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9B4C
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * Parent cleared larger follower; push r3,r4 and bx lr establish Thumb code.
 * symbols:
 *   table 0x021BC78C data a4
 */
#include "../include/Obj10978.h"
typedef unsigned short u16;
extern u16 table[][5];
int PSEL_IsAnimTargetReached(char *p)
{
    int select=0;
    if(((struct Obj10978 *)p)->f48==0) select=1;
    if(((struct Obj10978 *)p)->f4C==table[((struct Obj10978 *)p)->f44][select]) return 1;
    return 0;
}
