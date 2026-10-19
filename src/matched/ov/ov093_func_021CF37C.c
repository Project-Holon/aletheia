/*
 * function: BTL_CLIENT_SetSlotLinkWord
 * address: 0x021CF37C
 * packet: pkt_ov093_021CF37C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_MAIN_RemoveItemFromBag 0x021B9090 thumb ov093
 */
#include "../include/Obj06234.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern void BTL_MAIN_RemoveItemFromBag(u8 *p, u32 k, u32 x);
void BTL_CLIENT_SetSlotLinkWord(u8 *p,u32 i,u32 v) { if(p[0x1aa]==0) { if(p[0x1a6]==BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj06234 *)p)->f0)) { *(u16 *)(p+0x1a0+i*2)=v; BTL_MAIN_RemoveItemFromBag(*(u8 * *)&((struct Obj06234 *)p)->f0,p[0x1a6],v); } } }
