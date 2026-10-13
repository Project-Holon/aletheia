/*
 * function: FLD3D_CI_UpdateStartDelays
 * address:  0x021C21B4
 * packet:   pkt_ov021_021C21B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLD3D_CI_StartTrack  0x021C24A8  thumb  ov021
 *   FLD_PARTICLE_IsEffectFinished  0x021C1AB4  thumb  ov021
 */
#include "../include/Obj01864.h"

typedef unsigned short u16;

void FLD3D_CI_StartTrack(char *p, int k);
typedef unsigned int   u32;
int FLD_PARTICLE_IsEffectFinished(u32 *p);

int FLD3D_CI_UpdateStartDelays(char *p)
{
    if (((struct Obj01864 *)p)->f64 == 0) {
        if (((struct Obj01864 *)p)->f78 == 0) {
            if (((struct Obj01864 *)p)->f5C != 0) {
                (((struct Obj01864 *)p)->f5C)--;
            } else {
                FLD3D_CI_StartTrack(p, 0);
                ((struct Obj01864 *)p)->f78 = 1;
            }
        }
        if (((struct Obj01864 *)p)->f7C == 0) {
            if (((struct Obj01864 *)p)->f5E != 0) {
                (((struct Obj01864 *)p)->f5E)--;
            } else {
                FLD3D_CI_StartTrack(p, 1);
                ((struct Obj01864 *)p)->f7C = 1;
            }
        }
        if (((struct Obj01864 *)p)->f78 != 0 && ((struct Obj01864 *)p)->f7C != 0)
            ((struct Obj01864 *)p)->f64 = 1;
    } else if (FLD_PARTICLE_IsEffectFinished((u32 *)(((struct Obj01864 *)p)->f0)) != 0) {
        return 1;
    }
    return 0;
}
