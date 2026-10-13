/*
 * function: FIELDMAP_Draw3dEncEff
 * address:  0x021899C4
 * packet:   pkt_ov021_021899C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3X_SetClearColor  0x0207DD24  arm
 *   ENCEFF_RunUpdate  0x021CF520  thumb  ov021
 */
#include "../include/Obj19500.h"

typedef unsigned short u16;
void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
void ENCEFF_RunUpdate(int h);

void FIELDMAP_Draw3dEncEff(unsigned char *p)
{
    G3X_SetClearColor(0x4210, 0x1F, 0x7FFF, 0, 0);
    ENCEFF_RunUpdate(((struct Obj19500 *)p)->f13C);
}
