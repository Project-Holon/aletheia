/*
 * function: ISS_SYS_DeleteCity
 * address:  0x0202B67C
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_DeleteCity.c \\
 *       --func ISS_SYS_DeleteCity --addr 0x0202B67C --thumb --cc 1.1p1
 *
 * Closed: every byte reproduces and the site that held it open is now attested.
 *
 * symbols:
 *   ISS_CITY_SYS_Delete  0x0202AB28  thumb
 *   ISS_DUNGEON_SYS_Update  0x0202B404  thumb
 *   ISS_ZONE_SYS_Update  0x0202BEBC  thumb
 *   ISS_SWITCH_SYS_Delete  0x0202C08C  thumb
 *   ISS_SWITCH_SYS_Off  0x0202C0C0  thumb
 */
#include "../include/Obj02011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_CITY_SYS_Delete(void *p);
extern void ISS_SWITCH_SYS_Delete(u8 *p);
extern void ISS_DUNGEON_SYS_Update(u8 *p);
extern void ISS_ZONE_SYS_Update(u8 *p);
extern void ISS_SWITCH_SYS_Off(u32 *a0);

void ISS_SYS_DeleteCity(u8 *p)
{
    ISS_CITY_SYS_Delete(*(u8 * *)&((struct Obj02011 *)p)->f10);
    *(u32 *)&((struct Obj02011 *)p)->f10 = 0;
}
