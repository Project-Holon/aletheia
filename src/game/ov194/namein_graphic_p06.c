/*
 * file:     namein_graphic_p06.c
 * unit:     yes
 * function: func_021F2614, func_021F265C
 * address:  0x021F2614
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4DA4 0x021F4DA4 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F4450 0x021F4450 thumb ov194
 */
#include "../../matched/include/Obj10808.h"
#include "../../matched/include/Obj14499.h"

typedef struct {int x,y;} Pair;

extern unsigned func_021F4DA4(unsigned char *,unsigned short,unsigned short);
extern int func_021F2818(const char *,int *,int *);
extern int func_021F4450(int *,int *);
unsigned func_021F2614(char *p,int *input,unsigned short *out);
int func_021F265C(const char *p,int *point,Pair *out);

unsigned func_021F2614(char *p,int *input,unsigned short *out) {
 int xy[2]; unsigned result;
 result=((unsigned (*)(int *,int *))*(void **)(p+0x1C))(input,xy);
 if(result==1 || result==10 || result==11) {
  if(out) *out=func_021F4DA4(*(unsigned char * *)&((struct Obj10808 *)p)->f0,xy[0],xy[1]);
 } else if(result==9) {if(out) *out=32;}
 return result;
}

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
