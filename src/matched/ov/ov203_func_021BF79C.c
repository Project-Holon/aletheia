/*
 * function: DEMO3D_DATA_TaskDeleteCapture
 * address:  0x021BF79C
 * packet:   pkt_021BF79C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb
 */
#include "../include/Obj14599.h"

extern void DEMO3D_DATA_DeleteCapture(int);

void DEMO3D_DATA_TaskDeleteCapture(char *a)
{
    DEMO3D_DATA_DeleteCapture(((struct Obj14599 *)a)->f2C);
    ((struct Obj14599 *)a)->f2C = 0;
}
