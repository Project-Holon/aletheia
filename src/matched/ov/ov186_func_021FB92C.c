/*
 * function: func_021FB92C
 * address: 0x021FB92C
 * packet: pkt_ov186_021FB92C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10788.h"
struct Rec {void *a,*b;unsigned char pad[12];void *handle;};
extern void func_021FC1F8(int *,int),func_0201ED04(void *),func_02045C04(struct Rec *),func_0201D83C(void *),func_020307B0(void *);
void func_021FB92C(char *p) {func_021FC1F8((int *)p,0);func_021FC1F8((int *)p,1);func_0201ED04(((struct Obj10788 *)p)->fF0);func_02045C04(*(struct Rec * *)&((struct Obj10788 *)p)->fEC);func_0201D83C(((struct Obj10788 *)p)->fE8);func_020307B0(p);}
