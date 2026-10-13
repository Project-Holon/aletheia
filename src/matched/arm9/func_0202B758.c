/*
 * function: ISS_SYS_EnterSwitch
 * address: 0x0202B758
 * packet: pkt_arm9_0202B758
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
 *   ISS_SWITCH_SYS_On 0x0202C0B8 thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void ISS_SWITCH_SYS_On(u8 *p);
void ISS_SYS_EnterSwitch(u8 *p);

void ISS_SYS_EnterSwitch(u8 *p)
{
    ISS_SWITCH_SYS_On((u8 *)((struct Obj02010 *)p)->f20);
}
