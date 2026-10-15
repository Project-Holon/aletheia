/*
 * function: NAMEIN_GRAPHIC_FindCellAtPoint
 * address: 0x021F265C
 * packet: pkt_ov194_021F265C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_IsPointInRect 0x021F4450 thumb ov194
 */
#include "../include/Obj14499.h"
typedef struct {int x,y;} Pair;
extern int NAMEIN_GRAPHIC_PickerGetBox(const char *,int *,int *);
extern int NAMEIN_GRAPHIC_IsPointInRect(int *,int *);
int NAMEIN_GRAPHIC_FindCellAtPoint(const char *p,int *point,Pair *out) {
 Pair xy; int rect[4];
 for(xy.y=0;xy.y<*(const unsigned short *)&((struct Obj14499 *)p)->f22;xy.y++) {
 for(xy.x=0;xy.x<*(const unsigned short *)&((struct Obj14499 *)p)->f20;xy.x++) {
 if(NAMEIN_GRAPHIC_PickerGetBox(p,&xy.x,rect)) {
 rect[0]*=8;rect[1]*=8;rect[2]*=8;rect[3]*=8;
 if(NAMEIN_GRAPHIC_IsPointInRect(rect,point)) {*out=xy;return 1;}
 }
 }} return 0;
}
