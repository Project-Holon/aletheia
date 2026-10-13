/*
 * function: func_021F0728
 * address: 0x021F0728
 * packet: pkt_ov107_021F0728
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE894 0x021EE894 thumb ov107
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 */
#include "../include/Obj13761.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern int func_021EE894(u8 *);extern u32 func_0200FB24(void);extern void GFL_NET_ERR_RequestScreen(void);
int func_021F0728(int a,int b,int c,u8 *p) { if(func_021EE894(p)==1)return 1;if(func_0200FB24()!=0 && ((struct Obj13761 *)p)->f10==0){GFL_NET_ERR_RequestScreen();((struct Obj13761 *)p)->f10=1;}return 0; }
