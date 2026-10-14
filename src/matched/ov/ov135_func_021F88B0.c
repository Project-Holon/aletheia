/*
 * function: WORLDTRADE_ENTER_ClearFlags
 * address: 0x021F88B0
 * packet: pkt_ov135_021F88B0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_022030E8 0x022030E8 data a2
 */
#include "../include/Obj02204.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u16 d_022030E8[];
void WORLDTRADE_ENTER_ClearFlags(u8 *p,u32 n) { if(n==0){((struct Obj02204 *)p)->fF84=0;return;}n--;if(n<130)((struct Obj02204 *)p)->fF84=d_022030E8[n]; }
