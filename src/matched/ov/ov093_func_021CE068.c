/*
 * function: BTL_CLIENT_StartTimeLimit
 * address: 0x021CE068
 * packet: pkt_ov093_021CE068
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8504 0x021F8504 thumb ov094
 */
#include "../include/Obj01892.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F8504(u32,u32,u32);
void BTL_CLIENT_StartTimeLimit(u8 *p) { if(((struct Obj01892 *)p)->fE4) { func_021F8504(1,1,1); p[0x1ad]=0; } }
