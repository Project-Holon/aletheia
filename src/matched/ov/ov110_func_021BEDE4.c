/*
 * function: PMS_WORDLIST_GetTopRow
 * address: 0x021BEDE4
 * packet: pkt_ov110_021BEDE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: unlabelled blocker leaf for PMS_INPUT_GetTopRow; ends at filed EDE8.
 */
#include "../include/Obj22382.h"
typedef unsigned char u8;
typedef unsigned short u16;
u16 PMS_WORDLIST_GetTopRow(u8 *p) { return ((struct Obj22382 *)p)->f0; }
