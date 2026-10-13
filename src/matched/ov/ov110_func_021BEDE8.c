/*
 * function: PMS_WORDLIST_GetMaxTopRow
 * address: 0x021BEDE8
 * packet: pkt_ov110_021BEDE8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj22383.h"
typedef unsigned char u8;
typedef unsigned short u16;
u16 PMS_WORDLIST_GetMaxTopRow(u8 *p) { return ((struct Obj22383 *)p)->f2; }
