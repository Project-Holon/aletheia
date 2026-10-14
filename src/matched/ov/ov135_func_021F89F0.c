/*
 * function: WORLDTRADE_ENTER_CallStateHandler
 * address: 0x021F89F0
 * packet: pkt_ov135_021F89F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02203C1C 0x02203C1C data a4
 */
#include "../include/Obj08184.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int (*const d_02203C1C[])(void *);
int WORLDTRADE_ENTER_CallStateHandler(u8 *p) { int state,r;state=((struct Obj08184 *)p)->f28;r=d_02203C1C[state](p);if(state!=((struct Obj08184 *)p)->f28){((struct Obj08184 *)p)->fF88=0;((struct Obj08184 *)p)->fF8A=0;}return r; }
