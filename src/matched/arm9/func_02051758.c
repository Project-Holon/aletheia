/*
 * unit:     no
 * function: PARTICLE_ReleaseCamera
 * address:  0x02051758
 * packet:   pkt_02051648
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 */
#include "../include/Obj01197.h"

int PARTICLE_ReleaseCamera(int a0){ int t0; t0 = G3D_CAMERA_Delete((int)*(int *)&((struct Obj01197 *)((char *)(a0)))->f20); *(int *)&((struct Obj01197 *)((char *)(a0)))->f20 = (int)0; return 0; }
