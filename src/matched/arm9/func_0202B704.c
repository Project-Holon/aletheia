/*
 * function: ISS_SYS_UpdateSwitch
 * address:  0x0202B704
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The callee is an unlabelled Thumb thunk, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202C0C0 on the ISA mismatch.
 *
 * symbols:
 *   ISS_SWITCH_SYS_Main  0x0202C09C  thumb
 *   ISS_CITY_SYS_Delete  0x0202AB28  thumb
 *   ISS_DUNGEON_SYS_Update  0x0202B404  thumb
 *   ISS_ZONE_SYS_Update  0x0202BEBC  thumb
 *   ISS_SWITCH_SYS_Delete  0x0202C08C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SYS_UpdateSwitch.c \\
 *       --func ISS_SYS_UpdateSwitch --addr 0x0202B704 --thumb --cc 1.1p1

 * Closed by the `matched` class: the pool word names 0x0202C09C, an existing EXACT entry (pkt_0202BE00).
 */
#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_CITY_SYS_Delete(void *p);
extern void ISS_SWITCH_SYS_Delete(u8 *p);
extern void ISS_DUNGEON_SYS_Update(u8 *p);
extern void ISS_ZONE_SYS_Update(u8 *p);
extern void ISS_SWITCH_SYS_Main(u8 *p);

void ISS_SYS_UpdateSwitch(u8 *p)
{
    ISS_SWITCH_SYS_Main(*(u8 * *)&((struct Obj02010 *)p)->f20);
}
