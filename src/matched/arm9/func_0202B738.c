/*
 * function: func_0202B738
 * address: 0x0202B738
 * packet: pkt_arm9_0202B738
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
 *   func_0202B424 0x0202B424 thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void func_0202B424(u8 *p);
void func_0202B738(u8 *p);

void func_0202B738(u8 *p)
{
    func_0202B424((u8 *)((struct Obj02010 *)p)->f18);
}
