/*
 * function: P_STA_RIBBON_Deactivate
 * address: 0x021D909C
 * packet: pkt_ov131_021D909C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj04510.h"
typedef unsigned char u8;
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void P_STA_RIBBON_Deactivate(u8 *a,u8 *p)
{
    ((struct Obj04510 *)p)->f0=0;
    if(((struct Obj04510 *)p)->f20!=0) {
        BMP_WIN_Delete(((struct Obj04510 *)p)->f20);
        ((struct Obj04510 *)p)->f20=0;
    }
    if(((struct Obj04510 *)p)->f24!=0) {
        BMP_WIN_Delete(((struct Obj04510 *)p)->f24);
        ((struct Obj04510 *)p)->f24=0;
    }
}
