/*
 * function: WORLDTRADE_ENTER_Init
 * address: 0x021F89B4
 * packet: pkt_ov135_021F89B4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 * symbols:
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ENTER_EmptyInitHook 0x021F8A3C thumb ov135
 */
#include "../include/Obj05413.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void WORLDTRADE_ExitPlanes(u8 *);
extern void WORLDTRADE_ENTER_EmptyInitHook(void *);
int WORLDTRADE_ENTER_Init(u8 *p) {WORLDTRADE_ExitPlanes(p);WORLDTRADE_ENTER_EmptyInitHook(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(((struct Obj05413 *)p)->f20){case 19:case 21:((struct Obj05413 *)p)->f28=2;break;case 20:((struct Obj05413 *)p)->f28=4;break;}return 1;}
