/*
 * function: NNSi_SndSeqPlayerResetState
 * address:  0x02073500
 * packet:   pkt_020733E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndFaderSet  0x02075BAC  arm
 */
#include "../include/Obj00513.h"

int NNSi_SndSeqPlayerResetState(int a0){ int t0, t1; ((struct Obj00513 *)((char *)(a0)))->f2E = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2D = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2F = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f34 = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f3E = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f40 = (unsigned char)0x7f; ((struct Obj00513 *)((char *)(a0)))->f41 = (unsigned char)0x7f; t0 = func_02075B94((int)(a0 + 0x1c), (int)0x7f); t1 = NNSi_SndFaderSet((int)(a0 + 0x1c), (int)0x7f00, (int)1); return t1; }
