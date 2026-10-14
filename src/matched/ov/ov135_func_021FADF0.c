/*
 * function: WORLDTRADE_INPUT_StateStartCategoryScreen
 * address: 0x021FADF0
 * packet: pkt_ov135_021FADF0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_DrawFrame 0x021FA9C8 thumb ov135
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WORLDTRADE_SetActorPos 0x021F4FF4 thumb ov135
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */
#include "../include/Obj05415.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WORLDTRADE_INPUT_DrawFrame(u8 *,int,int);
struct Obj;
struct WinMgr;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void WORLDTRADE_SetActorPos(u32,u32,u32);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void WORLDTRADE_INPUT_StateStartCategoryScreen(u8 *p) {WORLDTRADE_INPUT_DrawFrame(p,4,32);CLACT_SetActorAnimSeq(((struct Obj05415 *)p)->f8,18);WORLDTRADE_SetActorPos(*(u32 *)&((struct Obj05415 *)p)->f8,144,40);BGWINFRM_StartMove(((struct Obj05415 *)p)->f18,0,-4,0,4);((struct Obj05415 *)p)->f48=1;((struct Obj05415 *)p)->f4C=7;((struct Obj05415 *)p)->f38=-1;}
