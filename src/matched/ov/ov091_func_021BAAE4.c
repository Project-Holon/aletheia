/*
 * function: PLIST_PLATE_Draw
 * address: 0x021BAAE4
 * packet: pkt_ov091_021BAAE4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_PLATE_DrawMonInfo 0x021BAB04 thumb ov091
 *   PLIST_PLATE_DrawHpBar 0x021BAE94 thumb ov091
 *   PLIST_PLATE_DrawEgg 0x021BAF28 thumb ov091
 */
#include "../include/Obj03183.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void PLIST_PLATE_DrawMonInfo(u8 *,u8 *,int);
extern void PLIST_PLATE_DrawHpBar(u8 *,u8 *);
extern void PLIST_PLATE_DrawEgg(u8 *,u8 *);
void PLIST_PLATE_Draw(u8 *a,u8 *s,int k) { if(((struct Obj03183 *)s)->fC==0) {PLIST_PLATE_DrawMonInfo(a,s,k);PLIST_PLATE_DrawHpBar(a,s);} else PLIST_PLATE_DrawEgg(a,s); }
