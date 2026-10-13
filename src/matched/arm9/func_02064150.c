/*
 * unit:     no
 * function: NNSi_G2dSrtcResetSrtData
 * address:  0x02064150
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj08899.h"

int NNSi_G2dSrtcResetSrtData(int a0){ int t0; t0 = func_02082A48((int)0, (int)(a0 + 4), (int)0x18); ((struct Obj08899 *)((char *)(a0)))->f4 = (int)0x1000; ((struct Obj08899 *)((char *)(a0)))->f8 = (int)0x1000; return 0x1000; }
