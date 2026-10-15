/*
 * unit:     no
 * function: rewind
 * address:  0x02092120
 * packet:   pkt_02092120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   fseek  0x02092004  arm
 */
#include "../include/Obj11692.h"

int rewind(void *a0){ int t0; ((struct Obj11692 *)((char *)(a0)))->fD = (unsigned char)0; t0 = fseek((int)a0, (int)0, (int)0); ((struct Obj11692 *)((char *)(a0)))->fD = (unsigned char)0; return t0; }
