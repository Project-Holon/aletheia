/*
 * function: ISS_SYS_LeaveDungeon
 * address: 0x0202B788
 * packet: pkt_arm9_0202B788
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/arm9/iss_3ds_sys_p01.c and filed here.
 *
 * symbols:
 *   ISS_DUNGEON_SYS_Stop  0x0202B42C  thumb
 */

#include "../include/Obj02010.h"

typedef unsigned char u8;
extern void ISS_DUNGEON_SYS_Stop(u8 *p);
void ISS_SYS_LeaveDungeon(u8 *p);

void ISS_SYS_LeaveDungeon(u8 *p)
{
    ISS_DUNGEON_SYS_Stop((u8 *)((struct Obj02010 *)p)->f18);
}
