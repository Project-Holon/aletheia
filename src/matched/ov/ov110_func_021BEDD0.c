/*
 * function: PMS_WORDLIST_GetSelectedIndex
 * address: 0x021BEDD0
 * packet: pkt_ov110_021BEDD0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_WORDLIST_GetCellOffset 0x021BEDC4 thumb ov110
 */
#include "../include/Obj10283.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned PMS_WORDLIST_GetCellOffset(u8 *);
unsigned PMS_WORDLIST_GetSelectedIndex(u8 *p) { return ((struct Obj10283 *)p)->f0*2+PMS_WORDLIST_GetCellOffset(p); }
