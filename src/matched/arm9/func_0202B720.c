/*
 * function: ISS_SYS_EnterRoad
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
 *   ISS_ROAD_SYS_Start 0x0202B1FC thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void ISS_ROAD_SYS_Start(u8 *p);
void ISS_SYS_EnterRoad(u8 *p);

void ISS_SYS_EnterRoad(u8 *p)
{
    ISS_ROAD_SYS_Start((u8 *)((struct Obj02010 *)p)->f14);
}
