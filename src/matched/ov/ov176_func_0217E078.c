/*
 * function: func_0217E078
 * address: 0x0217E078
 * packet: pkt_ov176_0217E078
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 */
#include "../include/Obj10705.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern int DELIVERY_IRC_Delete(void *a0);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
int func_0217E078(u8 *p) {if(func_0200FB24()!=0) {if(((struct Obj10705 *)p)->f1018!=0) {DELIVERY_IRC_Delete((void *)(((struct Obj10705 *)p)->f1018));((struct Obj10705 *)p)->f1018=0;}func_0200FBB0();GFL_NET_ERR_ShowSimpleScreen();return 1;}return 0;}
