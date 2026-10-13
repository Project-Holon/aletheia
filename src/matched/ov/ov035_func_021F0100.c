/*
 * function: C_GEAR_POWER_ONOFF_ExitBgs
 * address:  0x021F0100
 * packet:   pkt_ov035_021F0100
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_ExitBgs 0x021F0100 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj20480.h"

typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);

void C_GEAR_POWER_ONOFF_ExitBgs(char *p)
{
    unsigned int v = ((struct Obj20480 *)p)->f10;
    func_0203FB44(6, (unsigned short)v, (unsigned short)(v >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}
