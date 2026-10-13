/*
 * function: FLD3D_CI_StartTrack
 * address:  0x021C24A8
 * packet:   pkt_ov021_021C24A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * FLD3D_CI_FollowTargetCallback (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 * symbols:
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   FLD3D_CI_FollowTargetCallback  0x021C24BC  thumb  ov021
 */
#include "../include/Obj20162.h"

void FLD3D_CI_FollowTargetCallback(char *p);
int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);

void FLD3D_CI_StartTrack(char *p, int k)
{
    PARTICLE_StartEffectWithCallback((int *)(((struct Obj20162 *)p)->f58), k, (int)FLD3D_CI_FollowTargetCallback, 0);
}
