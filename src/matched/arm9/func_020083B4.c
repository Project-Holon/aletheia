/*
 * function: CONFIG_SetBattleScene
 * address:  0x020083B4
 * packet:   pkt_020083B4
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
 *   CONFIG_SetBattleScene  0x020083B4  thumb
 */

typedef struct {
    unsigned short a : 4;
    unsigned short b : 2;
    unsigned short c : 1;
    unsigned short d : 1;
    unsigned short e : 1;
    unsigned short f : 1;
} BF;

void CONFIG_SetBattleScene(BF *p, unsigned int v) { p->d = (unsigned short)v; }
