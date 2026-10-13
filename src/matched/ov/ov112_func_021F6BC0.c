/*
 * function: func_021F6BC0
 * address: 0x021F6BC0
 * packet: pkt_ov112_021F6BC0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: True entry includes push {r0-r3}; handed 021F6BC2 is an interior prologue label.
 * symbols:
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 */
#include "../include/Obj22554.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
void func_021F6BC0(char *p,u32 *q,u32 flag) {BILLBOARD_SetElemVisible(((struct Obj22554 *)p)->f4,q[6],&flag);}
