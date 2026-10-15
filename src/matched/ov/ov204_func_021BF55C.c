/*
 * function: INTRO_MSG_GetWordSet
 * address: 0x021BF55C
 * packet: pkt_ov204_021BF55C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj25389.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int INTRO_MSG_GetWordSet(u8 *p)
{
    return ((struct Obj25389 *)p)->f8;
}
