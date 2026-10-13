/*
 * function: FIELDMAP_Draw3dParticle
 * address:  0x02189998
 * packet:   pkt_ov021_02189998
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3X_SetClearColor  0x0207DD24  arm
 *   FLD_PARTICLE_Exit  0x021C1AEC  thumb  ov021
 *   FLD3D_CI_DrawEffect  0x021C1C4C  thumb  ov021
 */
#include "../include/Obj19499.h"

typedef unsigned short u16;
void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
void FLD_PARTICLE_Exit(void);
void FLD3D_CI_DrawEffect(char *p);

void FIELDMAP_Draw3dParticle(unsigned char *p)
{
    G3X_SetClearColor(0, 0, 0x7FFF, 0, 0);
    FLD_PARTICLE_Exit();
    FLD3D_CI_DrawEffect((char *)(((struct Obj19499 *)p)->f124));
}
