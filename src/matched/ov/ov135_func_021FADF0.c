/*
 * function: func_021FADF0
 * address: 0x021FADF0
 * packet: pkt_ov135_021FADF0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 */
#include "../include/Obj05415.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021FA9C8(u8 *,int,int);
struct Obj;
struct WinMgr;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32,u32,u32);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021FADF0(u8 *p) {func_021FA9C8(p,4,32);func_0204B878(((struct Obj05415 *)p)->f8,18);func_021F4FF4(*(u32 *)&((struct Obj05415 *)p)->f8,144,40);BGWINFRM_StartMove(((struct Obj05415 *)p)->f18,0,-4,0,4);((struct Obj05415 *)p)->f48=1;((struct Obj05415 *)p)->f4C=7;((struct Obj05415 *)p)->f38=-1;}
