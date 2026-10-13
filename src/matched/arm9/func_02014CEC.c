/*
 * function: MCSS_SetTaskSystem
 * address: 0x02014CEC
 * packet: pkt_02014CEC
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj15658.h"
typedef unsigned char u8;
typedef unsigned int u32;
void MCSS_SetTaskSystem(u8 *p, u32 value)
{
    ((struct Obj15658 *)p)->f8 = value;
}
