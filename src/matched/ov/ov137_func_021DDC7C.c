/*
 * function: func_021DDC7C
 * address: 0x021DDC7C
 * packet: pkt_ov137_021DDC7C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original cmp r0,#1 at 021DDC96 uses func_021DCBC4's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to GFL_NET_SetLoginOption despite its filed no-argument prototype.
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "../include/Obj10617.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(char *p);
extern int func_021DCBC4(void *,u32,const void *,u32);
extern void GFL_NET_SetLoginOption(u8 a0);
int func_021DDC7C(char *p,int state) {if(((struct Obj10617 *)p)->f4813==0) {if(func_021DCBC4(((struct Obj10617 *)p)->f10,0x2804,0,0)==1) {((struct Obj10617 *)p)->f118=27;GFL_NET_SetLoginOption(1);}}return state;}
