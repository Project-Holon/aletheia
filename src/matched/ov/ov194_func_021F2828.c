/*
 * function: NAMEIN_GRAPHIC_FindCellByValue
 * address: 0x021F2828
 * packet: pkt_ov194_021F2828
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj14501.h"
typedef struct {int x,y;} Pair;
int NAMEIN_GRAPHIC_FindCellByValue(const char *p,int target,Pair *out) {
 Pair xy;
 for(xy.y=0;xy.y<=*(const unsigned short *)&((struct Obj14501 *)p)->f22;xy.y++)
 for(xy.x=0;xy.x<=*(const unsigned short *)&((struct Obj14501 *)p)->f20;xy.x++)
 if(((int (*)(int *,int *))*(void *const *)(p+0x1C))(&xy.x,0)==target) {*out=xy;return 1;}
 return 0;
}
