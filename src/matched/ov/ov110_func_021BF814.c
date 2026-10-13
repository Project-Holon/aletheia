/*
 * function: PMS_INPUT_GetInitialWord
 * address: 0x021BF814
 * packet: pkt_ov110_021BF814
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSI_SEARCH_GetResultString 0x021BB1CC thumb ov110
 */
#include "../include/Obj22401.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int PMSI_SEARCH_GetResultString(u8 *p, u8 i, int c);
void PMS_INPUT_GetInitialWord(u8 *p,u32 a,int b) { PMSI_SEARCH_GetResultString(*(u8 * *)&((struct Obj22401 *)p)->f1C,a,b); }
