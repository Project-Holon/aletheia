/*
 * function: func_021F265C
 * address: 0x021F265C
 * packet: pkt_ov194_021F265C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F4450 0x021F4450 thumb ov194
 */
#include "../include/Obj14499.h"
typedef struct {int x,y;} Pair;
extern int func_021F2818(const char *,int *,int *);
extern int func_021F4450(int *,int *);
int func_021F265C(const char *p,int *point,Pair *out) {
 Pair xy; int rect[4];
 for(xy.y=0;xy.y<*(const unsigned short *)&((struct Obj14499 *)p)->f22;xy.y++) {
 for(xy.x=0;xy.x<*(const unsigned short *)&((struct Obj14499 *)p)->f20;xy.x++) {
 if(func_021F2818(p,&xy.x,rect)) {
 rect[0]*=8;rect[1]*=8;rect[2]*=8;rect[3]*=8;
 if(func_021F4450(rect,point)) {*out=xy;return 1;}
 }
 }} return 0;
}
