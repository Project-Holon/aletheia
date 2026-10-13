/*
 * unit:     no
 * function: PROCSYS_PushQueued
 * address:  0x020313A0
 * packet:   pkt_02031354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_NewProc  0x02031538  arm
 */
#include "../include/Obj00371.h"
#include "../include/Obj03005.h"

int PROCSYS_PushQueued(int a0){ int t0; t0 = PROCSYS_NewProc((int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f14, (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f18, (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f1C, (int)((struct Obj00371 *)((char *)(a0)))->f0); *(int *)&((struct Obj03005 *)((char *)(t0)))->f18 = (int)*(int *)&((struct Obj00371 *)((char *)(a0)))->f8; *(int *)(((char *)(*(int *)&((struct Obj00371 *)((char *)(a0)))->f8) + 28)) = (int)t0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f8 = (int)t0; *(int *)&((struct Obj00371 *)((char *)(a0)))->fC = (int)0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f14 = (int)(0 - 1); *(int *)&((struct Obj00371 *)((char *)(a0)))->f18 = (int)0; *(int *)&((struct Obj00371 *)((char *)(a0)))->f1C = (int)0; return t0; }
