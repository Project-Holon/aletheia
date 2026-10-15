/*
 * function: POKE_SUMMARY_MAIN_ShowTextKind3
 * address: 0x021B7590
 * packet: pkt_ov173_021B7590
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_SUMMARY_MAIN_StartTextStream 0x021B7460 thumb ov173
 *   POKE_SUMMARY_MAIN_CountFreeMoves 0x021B7568 thumb ov173
 */
#include "../include/Obj24177.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *,u32);
extern u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***);
int POKE_SUMMARY_MAIN_ShowTextKind3(u8 *p) {POKE_SUMMARY_MAIN_StartTextStream((char *)p,3);(*(u8 **)p)[27]=POKE_SUMMARY_MAIN_CountFreeMoves((void ***)p);((struct Obj24177 *)p)->f1B0=5;return 2;}
