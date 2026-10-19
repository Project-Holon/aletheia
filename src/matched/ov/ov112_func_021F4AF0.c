/*
 * function: MUSICAL_MCSS_IsElemModeSupportedA
 * address: 0x021F4AF0
 * packet: pkt_ov112_021F4AF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_IsModeSupportedA 0x021F4F74 thumb ov112
 */
#include "../include/Obj22518.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int MUSICAL_MCSS_IsModeSupportedA(u16 *, int);
int MUSICAL_MCSS_IsElemModeSupportedA(u8 *p, int index)
{
    return MUSICAL_MCSS_IsModeSupportedA(*(u16 * *)&((struct Obj22518 *)p)->f20, index);
}
