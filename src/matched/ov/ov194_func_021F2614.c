/*
 * function: func_021F2614
 * address: 0x021F2614
 * packet: pkt_ov194_021F2614
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4DA4 0x021F4DA4 thumb ov194
 */
#include "../include/Obj10808.h"
extern unsigned func_021F4DA4(unsigned char *,unsigned short,unsigned short);
unsigned func_021F2614(char *p,int *input,unsigned short *out) {
 int xy[2]; unsigned result;
 result=((unsigned (*)(int *,int *))*(void **)(p+0x1C))(input,xy);
 if(result==1 || result==10 || result==11) {
  if(out) *out=func_021F4DA4(*(unsigned char * *)&((struct Obj10808 *)p)->f0,xy[0],xy[1]);
 } else if(result==9) {if(out) *out=32;}
 return result;
}
