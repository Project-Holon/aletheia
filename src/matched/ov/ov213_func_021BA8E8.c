/*
 * function: COMM_BTL_DEMO_MAIN_StartEffect
 * address: 0x021BA8E8
 * packet: pkt_ov213_021BA8E8
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_StartEffect 0x020515B4 arm
 */
#include "../include/Obj25709.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int PARTICLE_StartEffect(void *,int,int);
int COMM_BTL_DEMO_MAIN_StartEffect(char *p,int b,int c) { return PARTICLE_StartEffect(((struct Obj25709 *)p)->f10,b,c); }
