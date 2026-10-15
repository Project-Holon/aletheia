/*
 * function: SHINKA_DEMO_GRAPHIC_Update3d
 * address:  0x02205C58
 * packet:   pkt_02205C58
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 */
#include "../include/Obj24957.h"

extern void G3D_SYSTEM_DrawStart(void *);
extern int G3D_CAMERA_Reset(int);
extern void G3D_SYSTEM_ApplyLookAt(int);

void SHINKA_DEMO_GRAPHIC_Update3d(char *a)
{
    G3D_SYSTEM_DrawStart(a);
    G3D_SYSTEM_ApplyLookAt(G3D_CAMERA_Reset(((struct Obj24957 *)a)->f0));
}