/*
 * function: ISS_SYS_EnterCity
 * address: 0x0202B72C
 * packet: pkt_arm9_0202B72C
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
 *   ISS_CITY_SYS_Start 0x0202AB4C thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void ISS_CITY_SYS_Start(u8 *p);
void ISS_SYS_EnterCity(u8 *p);

void ISS_SYS_EnterCity(u8 *p)
{
    ISS_CITY_SYS_Start((u8 *)((struct Obj02010 *)p)->f10);
}
