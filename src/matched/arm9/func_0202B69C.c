/*
 * function: ISS_SYS_DeleteZone
 * address:  0x0202B69C
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_ZONE_SYS_Delete  0x0202BEA4  thumb
 */
#include "../include/Obj02011.h"

typedef unsigned char  u8;
extern void ISS_ZONE_SYS_Delete(u8 *p);
void ISS_SYS_DeleteZone(int a0)
{
    ISS_ZONE_SYS_Delete((u8 *)(((struct Obj02011 *)a0)->f1C));
    ((struct Obj02011 *)a0)->f1C = 0;
}
