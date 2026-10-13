/*
 * unit:     no
 * function: PMSI_PARAM_SetSentenceId
 * address:  0x02024598
 * packet:   pkt_02024584
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj05795.h"

void PMSI_PARAM_SetSentenceId(void *p0, int p1, int p2){ ((struct Obj05795 *)p0)->f0 = (unsigned short)p1; ((struct Obj05795 *)p0)->f2 = (unsigned short)p2; }
