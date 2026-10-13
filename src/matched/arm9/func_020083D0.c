/*
 * function: CONFIG_SetBattleStyle
 * address:  0x020083D0
 * packet:   pkt_020083D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter on a u16 bitfield word (witness for ov068 callers).
 *
 * symbols:
 *   CONFIG_SetBattleStyle  0x020083D0  thumb
 */

typedef struct {
    unsigned short a : 4;
    unsigned short b : 2;
    unsigned short c : 1;
    unsigned short d : 1;
    unsigned short e : 1;
    unsigned short f : 1;
} BF;

void CONFIG_SetBattleStyle(BF *p, unsigned int v) { p->c = (unsigned short)v; }
