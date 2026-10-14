/*
 * function: WORLDTRADE_INPUT_StateGenderListClose
 * address: 0x021FBE54
 * packet: pkt_ov135_021FBE54
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_INPUT_MenuFinish 0x021F9660 thumb ov135
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
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
extern u32 BMP_MENUWORK_Delete(void *p);
int WORLDTRADE_INPUT_StateGenderListClose(u8 *p) { if(CLACT_IsActorAnimActive(((struct Obj00098 *)p)->f8))return -1;CLACT_SetActorDrawEnable(((struct Obj00098 *)p)->f8,0);WORLDTRADE_INPUT_MenuFinish(p,2);BMP_MENUWORK_Delete(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f41; }
