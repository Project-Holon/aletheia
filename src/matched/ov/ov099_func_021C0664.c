/*
 * function: func_021C0664
 * address: 0x021C0664
 * packet: pkt_ov099_021C0664
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BA8EC(char *);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_021C18C8(char *,int,int);
extern void func_021C2408(char *);
int func_021C0664(char *p,int ret){func_021BA8EC(p);GFL_NET_STATE_WifiDisconnect(1);func_021C18C8(p,1,2);((struct Obj00008 *)p)->f1F0=-1;func_021C2408(p);((struct Obj00008 *)p)->f1CC=11;return ret;}
