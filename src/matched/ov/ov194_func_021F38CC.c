/*
 * function: NAMEIN_GRAPHIC_KanaTouch
 * address: 0x021F38CC
 * packet: pkt_ov194_021F38CC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   NAMEIN_GRAPHIC_FindCellAtPoint 0x021F265C thumb ov194
 *   func_020355D8 0x020355D8 arm
 */
#include "../include/Obj14503.h"
extern unsigned TOUCHPANEL_GetPointTrg(unsigned *,unsigned *);
extern int NAMEIN_GRAPHIC_FindCellAtPoint(char *,int *,int *);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
int NAMEIN_GRAPHIC_KanaTouch(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(TOUCHPANEL_GetPointTrg(&x,&y)) {
 point[0]=x;point[1]=y;
 if(NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(int *)(p+0xD8))) {
 u=((struct Obj14503 *)p)->fD8;out[3]=((struct Obj14503 *)p)->fDC;out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}
