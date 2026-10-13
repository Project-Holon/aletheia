/*
 * function: PMS_INPUT_ResetSearch
 * address: 0x021BF7E0
 * packet: pkt_ov110_021BF7E0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSI_SEARCH_ClearInput 0x021BAFE4 thumb ov110
 */
#include "../include/Obj22396.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void PMSI_SEARCH_ClearInput(u32 p);
void PMS_INPUT_ResetSearch(u8 *p) { PMSI_SEARCH_ClearInput((u32)(*(u8 * *)&((struct Obj22396 *)p)->f1C)); }
