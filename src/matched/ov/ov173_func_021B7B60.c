/*
 * function: POKE_SUMMARY_ACTOR_StartWipe
 * address: 0x021B7B60
 * packet: pkt_ov173_021B7B60
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj24186.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
int POKE_SUMMARY_ACTOR_StartWipe(u8 *p) {WIPE_SYS_Start(0,0,0,0,6,1,79);((struct Obj24186 *)p)->f1B0=11;return 0;}
