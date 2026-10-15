/*
 * unit: no
 * function: STAFF_ROLL_AdvanceLights
 * address: 0x021BA000
 * packet: pkt_ov181_021BA000
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj08304.h"
#include "../include/Obj14411.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
void STAFF_ROLL_AdvanceLights(u8 *p){u32 i;for(i=0;i<15;i++){u8 *q=p+i*4;((struct Obj08304 *)q)->f34=((struct Obj08304 *)q)->f38;((struct Obj08304 *)q)->f36=((struct Obj08304 *)q)->f3A;}((struct Obj14411 *)p)->f70=65535;((struct Obj14411 *)p)->f72=0;}
