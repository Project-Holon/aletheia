/*
 * function: BTL_MAIN_UpdateFriendshipIfPlayer
 * address: 0x021B92B0
 * packet: pkt_ov093_021B92B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_MAIN_UpdateFriendship 0x021B92D4 thumb ov093
 */
#include "../include/Obj07746.h"
#include "../include/Obj13276.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_MAIN_UpdateFriendship(char *,void *,int);
void BTL_MAIN_UpdateFriendshipIfPlayer(char *p,void *m,int k) { u8 *q; q=*(u8 * *)&((struct Obj07746 *)p)->f0; if(((struct Obj13276 *)q)->f0<=1 && q[0x23]==0) BTL_MAIN_UpdateFriendship(p,m,k?5:4); }
