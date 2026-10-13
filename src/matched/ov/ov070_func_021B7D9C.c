/*
 * function: ITEMMENU_ShowQuantityWindows
 * address: 0x021B7D9C
 * packet: pkt_ov070_021B7D9C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_LoadSellPalette 0x021BB1C4 thumb ov070
 *   ITEMMENU_PrintQuantityPrice 0x021BB260 thumb ov070
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
extern void ITEMMENU_LoadSellPalette(void *p);
extern void ITEMMENU_PrintQuantityPrice(u8 *p, int val);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void ITEMMENU_ShowQuantityWindows(u8 *p, int v) { ((struct Obj00002 *)p)->f7EC=v; ITEMMENU_LoadSellPalette(p); ITEMMENU_PrintQuantityPrice(p,((struct Obj00002 *)p)->f7F4); CLACT_SetActorDrawEnable(((struct Obj00002 *)p)->f724,1); CLACT_SetActorDrawEnable(((struct Obj00002 *)p)->f728,1); }
