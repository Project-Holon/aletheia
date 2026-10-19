/*
 * function: ITEMMENU_UpdatePocketSortIcon
 * address: 0x021B81F4
 * packet: pkt_ov070_021B81F4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_GetPocketSortFlag 0x021B81B0 thumb ov070
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj04328.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern int ITEMMENU_GetPocketSortFlag(int x);
extern int GAME_DATA_ContainsRecentId(int p, int a);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void ITEMMENU_UpdatePocketSortIcon(u8 *p) { if (((struct Obj04328 *)p)->f81C!=1) CLACT_SetActorAnimSeq(((struct Obj04328 *)p)->f718,(unsigned int)GAME_DATA_ContainsRecentId(*(int *)&((struct Obj04328 *)p)->f0,ITEMMENU_GetPocketSortFlag(((struct Obj04328 *)p)->f80C))+6u); }
