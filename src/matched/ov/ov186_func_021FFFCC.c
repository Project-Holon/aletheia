/*
 * function: BR_POKESEARCH_DestroyGroupWindows
 * address: 0x021FFFCC
 * packet: pkt_ov186_021FFFCC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 */
#include "../include/Obj14487.h"
#include "../include/Obj24878.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BR_UTIL_Delete(u8 *p);
extern void BG_SYS_PushTile(u32 index);
extern void BR_RES_ApplyBgSet(int,unsigned);
void BR_POKESEARCH_DestroyGroupWindows(u8 *p) { int i; for(i=0;i<9;i++) { u8 *q=p+(u32)i*4; BR_UTIL_Delete(((struct Obj14487 *)q)->f40); *(u32 *)&((struct Obj14487 *)q)->f40=0; } BG_SYS_PushTile(4); BR_RES_ApplyBgSet(((struct Obj24878 *)p)->f28,20); }
