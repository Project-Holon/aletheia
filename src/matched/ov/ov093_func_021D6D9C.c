/*
 * function: func_021D6D9C
 * address: 0x021D6D9C
 * packet: pkt_ov093_021D6D9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bind the requested halfword, keeping the object's remaining value inline.
 */
#include "../include/Obj07801.h"
typedef unsigned char u8;
typedef unsigned short u16;
int func_021D6D9C(u8 *p, u16 *value)
{
    u16 requested;
    requested = *value;
    if (((struct Obj07801 *)p)->f1F2 <= requested) {
        *value = ((struct Obj07801 *)p)->f1F2;
        ((struct Obj07801 *)p)->f1F2 = 0;
        return 1;
    }
    ((struct Obj07801 *)p)->f1F2 -= requested;
    return 0;
}
