/*
 * function: WORLDTRADE_INPUT_StateSubCategorySelected
 * address: 0x021FB1E4
 * packet: pkt_ov135_021FB1E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: 2-byte zero alignment padding.
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_INPUT_MenuFinish 0x021F9660 thumb ov135
 */
#include "../include/Obj00098.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void WORLDTRADE_INPUT_MenuFinish(void *,u32);
int WORLDTRADE_INPUT_StateSubCategorySelected(u8 *p) { if(CLACT_IsActorAnimActive(((struct Obj00098 *)p)->f8))return -1;CLACT_SetActorDrawEnable(((struct Obj00098 *)p)->f8,0);WORLDTRADE_INPUT_MenuFinish(p,5);if(((struct Obj00098 *)p)->f3A>=0)*(u32 *)&((struct Obj00098 *)p)->f48=14;else *(u32 *)&((struct Obj00098 *)p)->f48=9;return -1; }
