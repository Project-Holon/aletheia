/*
 * function: SAVE_OUTSIDE_Prepare
 * address: 0x021DFDC0
 * packet: pkt_ov228_021DFDC0
 * region: ov228
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original stores live r0 after F1FC despite its legacy void return; keep returned low halfword.
 * symbols:
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 */
#include "../include/Obj04657.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
void SAVE_OUTSIDE_Prepare(u8 *p)
{
    p[0x379]=0;
    if(((struct Obj04657 *)p)->f374==2)p[0x37A]=1;
    else p[0x37A]=0;
    ((struct Obj04657 *)p)->f0=0xA10F49AE;
    ((struct Obj04657 *)p)->f4+=1;
    ((struct Obj04657 *)p)->f8=GF_STANDARD_CalcCrc16(p+12,0x368);
}
