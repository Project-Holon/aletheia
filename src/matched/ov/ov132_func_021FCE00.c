/*
 * function: func_021FCE00
 * address: 0x021FCE00
 * packet: pkt_ov132_021FCE00
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
#include "../include/Obj23272.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
int func_021FCE00(char *p,int id) {if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),id,0x11)==1)return 1;if(((struct Obj23272 *)p)->f4==1)return 1;return 0;}
