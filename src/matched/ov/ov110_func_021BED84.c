/*
 * function: PMS_INPUT_InitWordList
 * address: 0x021BED84
 * packet: pkt_ov110_021BED84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetListItemCount 0x021BF734 thumb ov110
 */
#include "../include/Obj02165.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PMS_INPUT_GetListItemCount(u8 *p);
void PMS_INPUT_InitWordList(u8 *p, void *q) {
    ((struct Obj02165 *)p)->f0=0; p[6]=0; p[7]=0;
    ((struct Obj02165 *)p)->f4=PMS_INPUT_GetListItemCount(q);
    ((struct Obj02165 *)p)->f8=0;
    ((struct Obj02165 *)p)->fC=0; ((struct Obj02165 *)p)->fE=65535;
    if (((struct Obj02165 *)p)->f4>14) ((struct Obj02165 *)p)->f2=(((struct Obj02165 *)p)->f4-14)/2+(((struct Obj02165 *)p)->f4&1);
    else ((struct Obj02165 *)p)->f2=0;
}
