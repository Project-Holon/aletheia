/*
 * function: NNS_G2dInitAnimCtrl
 * address:  0x02062F38
 * packet:   pkt_02062F38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dResetCellAnimationState  0x02062F78  arm
 */
#include "../include/Obj03468.h"

int NNS_G2dInitAnimCtrl(int a0){ int t0; t0 = NNSi_G2dResetCellAnimationState((int)(a0 + 0x20)); ((struct Obj03468 *)((char *)(a0)))->f0 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f4 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f8 = (int)0; ((struct Obj03468 *)((char *)(a0)))->fC = (int)1; ((struct Obj03468 *)((char *)(a0)))->f10 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f14 = (int)0x1000; ((struct Obj03468 *)((char *)(a0)))->f18 = (int)0; ((struct Obj03468 *)((char *)(a0)))->f1C = (int)0; return 0x1000; }
