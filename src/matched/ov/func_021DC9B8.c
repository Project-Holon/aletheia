/*
 * function: BOX2_MAIN_RestartSeq
 * address:  0x021DC9B8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_InitSeq  0x021DC9A0  thumb  ov170
 *
 * Re-run the reset helper with the stored word.
 */
#include "../include/Obj05868.h"

extern void BOX2_MAIN_InitSeq(char *, int);

void BOX2_MAIN_RestartSeq(char *p)
{
    BOX2_MAIN_InitSeq(p, ((struct Obj05868 *)p)->f5C);
}

