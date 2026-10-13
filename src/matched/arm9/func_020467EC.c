/*
 * unit:     no
 * function: G3D_SYSTEM_GetProjection
 * address:  0x020467EC
 * packet:   pkt_020463E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj01315.h"

void G3D_SYSTEM_GetProjection(int p0){ *(int *)&((struct Obj01315 *)p0)->f0 = (int)*(int *)((*(int *)(0x2146A5C) + 28)); *(int *)&((struct Obj01315 *)p0)->f4 = (int)*(int *)((*(int *)(0x2146A5C) + 32)); *(int *)&((struct Obj01315 *)p0)->f8 = (int)*(int *)((*(int *)(0x2146A5C) + 36)); *(int *)&((struct Obj01315 *)p0)->fC = (int)*(int *)((*(int *)(0x2146A5C) + 40)); *(int *)&((struct Obj01315 *)p0)->f10 = (int)*(int *)((*(int *)(0x2146A5C) + 44)); *(int *)&((struct Obj01315 *)p0)->f14 = (int)*(int *)((*(int *)(0x2146A5C) + 48)); *(int *)&((struct Obj01315 *)p0)->f18 = (int)*(int *)((*(int *)(0x2146A5C) + 52)); *(int *)&((struct Obj01315 *)p0)->f1C = (int)*(int *)((*(int *)(0x2146A5C) + 56)); }
