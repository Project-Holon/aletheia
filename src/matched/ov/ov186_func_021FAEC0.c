/*
 * function: BR_BTN_PlaceIndexed
 * address: 0x021FAEC0
 * packet: pkt_ov186_021FAEC0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_BTN_SetObjectPos 0x021FB514 thumb ov186
 */
#include "../include/Obj14454.h"
extern int BR_BTN_DATA_GetRowField(void *p, int i);
extern void BR_BTN_SetObjectPos(char *p, short x, int y);
void BR_BTN_PlaceIndexed(char *p,unsigned index) { short x=(short)BR_BTN_DATA_GetRowField((void *)(((struct Obj14454 *)p)->fC),0);BR_BTN_SetObjectPos(((struct Obj14454 *)p)->f8,x,(short)(169-(index<<4))); }
