/*
 * function: COMM_BTL_DEMO_MAIN_StartEffects
 * address: 0x021BA8F4
 * packet: pkt_ov213_021BA8F4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The original truncates the second call argument to u16; the extern preserves that width.
 * symbols:
 *   COMM_BTL_DEMO_MAIN_StartEffect 0x021BA8E8 thumb ov213
 */
#include "../include/Obj25710.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int COMM_BTL_DEMO_MAIN_StartEffect(char *p, int b, int c);
void COMM_BTL_DEMO_MAIN_StartEffects(char *p,int v) { int i; for(i=0;i<((struct Obj25710 *)p)->f4814;i++) COMM_BTL_DEMO_MAIN_StartEffect(p,(u16)i,v); }
