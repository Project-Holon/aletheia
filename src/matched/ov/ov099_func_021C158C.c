/*
 * unit: yes
 * function: WIFICLUB_StateBeginIdleAfterNet, WIFICLUB_StateGotoWaitKey
 * address: 0x021C158C
 * packet: pkt_ov099_021C158C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414AC 0x020414AC arm
 *   WIFICLUB_BeginIdle 0x021BE4F0 thumb ov099
 */
#include "../include/Obj13703.h"
#include "../include/Obj22057.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020414AC(int);
extern int WIFICLUB_BeginIdle(char *,int);
int WIFICLUB_StateBeginIdleAfterNet(char *p,int ret){func_020414AC(3);((struct Obj13703 *)p)->f1358=0;((struct Obj13703 *)p)->f1CC=WIFICLUB_BeginIdle(p,0);return ret;}
int WIFICLUB_StateGotoWaitKey(char *p,int ret){((struct Obj22057 *)p)->f1CC=47;return ret;}
