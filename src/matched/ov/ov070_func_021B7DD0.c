/*
 * function: ITEMMENU_HideQuantityWindows
 * address: 0x021B7DD0
 * packet: pkt_ov070_021B7DD0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void func_020414EC(u32 i);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void ITEMMENU_HideQuantityWindows(u8 *p) { func_020414EC(3); CLACT_SetActorDrawEnable(((struct Obj00002 *)p)->f724,0); CLACT_SetActorDrawEnable(((struct Obj00002 *)p)->f728,0); }
