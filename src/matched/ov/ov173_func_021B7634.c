/*
 * function: POKE_SUMMARY_ANIM_ShowTextKind5, POKE_SUMMARY_ANIM_Finish
 * address: 0x021B7634
 * packet: pkt_ov173_021B7634
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   POKE_SUMMARY_MAIN_StartTextStream 0x021B7460 thumb ov173
 */
#include "../include/Obj24178.h"
#include "../include/Obj24179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *,u32);
int POKE_SUMMARY_ANIM_ShowTextKind5(u8 *p) {POKE_SUMMARY_MAIN_StartTextStream((char *)p,5);((struct Obj24178 *)p)->f1B0=6;return 2;}
int POKE_SUMMARY_ANIM_Finish(u8 *p) {((struct Obj24179 *)p)->f1B0=10;return 0;}
