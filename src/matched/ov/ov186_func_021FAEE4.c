/*
 * function: BR_BTN_GetPos
 * address: 0x021FAEE4
 * packet: pkt_ov186_021FAEE4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_GetObjectPos 0x021FB548 thumb ov186
 */
#include "../include/Obj24819.h"
extern void BR_BTN_GetObjectPos(char *p, short *x, short *y);
void BR_BTN_GetPos(char *p,int *out) { short x,y;BR_BTN_GetObjectPos(((struct Obj24819 *)p)->f8,&x,&y);out[0]=x;out[1]=y; }
