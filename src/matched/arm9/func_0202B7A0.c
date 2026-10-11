/*
 * function: func_0202B7A0
 * address: 0x0202B7A0
 * packet: pkt_arm9_0202B7A0
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
 *   func_0202C0C0 0x0202C0C0 thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;
extern void func_0202C0C0(u32 *a0);
void func_0202B7A0(u8 *p);

void func_0202B7A0(u8 *p)
{
    func_0202C0C0((u32 *)((u8 *)((struct Obj02010 *)p)->f20));
}
