/*
 * function: func_021B93A4
 * address: 0x021B93A4
 * packet: pkt_ov067_021B93A4
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller ov209 021BCE98 reads the signed sum. ov067 is loaded by
 * ov209 021BCC94 and unloaded by 021BCD48. Following code starts at 021B93B0.
 */
#include "../include/Obj13135.h"
int func_021B93A4(char *p)
{
    return ((struct Obj13135 *)p)->f5C + ((struct Obj13135 *)p)->f62;
}
