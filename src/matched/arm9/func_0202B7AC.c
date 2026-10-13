/*
 * function: ISS_SYS_Leave3ds
 * address: 0x0202B7AC
 * packet: pkt_arm9_0202B7AC
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
 *   ISS_3DS_SYS_Leave 0x0202B904 thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
void ISS_SYS_Leave3ds(u8 *p);
void ISS_3DS_SYS_Leave(u8 *p);

void ISS_SYS_Leave3ds(u8 *p)
{
    ISS_3DS_SYS_Leave((u8 *)((struct Obj02010 *)p)->f24);
}
