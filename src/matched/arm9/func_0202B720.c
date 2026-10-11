/*
 * function: func_0202B720
 * address: 0x0202B720
 * packet: pkt_arm9_0202B720
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/iss_3ds_sys.c and filed here.
 *
 * symbols:
 *   func_0202B1FC 0x0202B1FC thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void func_0202B1FC(u8 *p);
void func_0202B720(u8 *p);

void func_0202B720(u8 *p)
{
    func_0202B1FC((u8 *)((struct Obj02010 *)p)->f14);
}
