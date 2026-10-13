/*
 * function: BTL_POKEPARAM_SubHp
 * address: 0x021D5F90
 * packet: pkt_ov093_021D5F90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
#include "../include/Obj07797.h"
typedef unsigned char u8;
typedef unsigned short u16;
void BTL_POKEPARAM_SubHp(u8 *p, u16 n)
{
    if (((struct Obj07797 *)p)->f10 > n) {
        ((struct Obj07797 *)p)->f10 = ((struct Obj07797 *)p)->f10 - n;
        return;
    }
    ((struct Obj07797 *)p)->f10 = 0;
}
