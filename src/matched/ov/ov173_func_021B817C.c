/*
 * function: POKE_SUMMARY_ACTOR_ShowTextKind1Or4
 * address: 0x021B817C
 * packet: pkt_ov173_021B817C
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: select flag into a u8 local and store it after the branch;
 *        stores written in each arm rematerialized 0x1B0 (+4 bytes).
 * symbols:
 *   POKE_SUMMARY_MAIN_CountFreeMoves 0x021B7568 thumb ov173
 *   POKE_SUMMARY_MAIN_StartTextStream 0x021B7460 thumb ov173
 */
#include "../include/Obj14320.h"
typedef unsigned char  u8;
extern u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***p);extern void POKE_SUMMARY_MAIN_StartTextStream(char *,unsigned);
int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p) {unsigned char flag;if(POKE_SUMMARY_MAIN_CountFreeMoves((void ***)p)<4) {POKE_SUMMARY_MAIN_StartTextStream(p,1);flag=0;} else {POKE_SUMMARY_MAIN_StartTextStream(p,4);flag=2;}((struct Obj14320 *)p)->f1BA=flag;*(unsigned *)(p+0x1ba-10)=3;return 2;}
