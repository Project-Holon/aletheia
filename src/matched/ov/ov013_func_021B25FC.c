/*
 * function: VCT_SESSION_FillAnnounceFields
 * address: 0x021B25FC
 * packet: pkt_ov013_021B25FC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctGroup 0x021B4BD0 data a4
 */
#include "../include/Obj00947.h"
#include "../include/G_Stats.h"
typedef unsigned char u8;
extern struct Stats gVctGroup;
void VCT_SESSION_FillAnnounceFields(u8 *a,u8 *b)
{
    if(b[10] == 1) {
        b[11]=a[4];
        ((struct Obj00947 *)b)->fC=((int *)&gVctGroup)[1];
    }
}
