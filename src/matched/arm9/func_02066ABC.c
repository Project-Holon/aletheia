/*
 * unit:     no
 * function: NNSi_G2dRequestCellTransferState
 * address:  0x02066ABC
 * packet:   pkt_02066ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dGetCellTransferState  0x02066878  arm
 */
#include "../include/Obj08903.h"

extern unsigned char *NNSi_G2dGetCellTransferState(unsigned int i);
int NNSi_G2dRequestCellTransferState(int a0, int a1, int a2){ int t0; t0 = (int)NNSi_G2dGetCellTransferState(a0); ((struct Obj08903 *)((char *)(t0)))->f24 = (int)~0; ((struct Obj08903 *)((char *)(t0)))->f28 = (int)a1; ((struct Obj08903 *)((char *)(t0)))->f2C = (int)a2; return t0; }
