/*
 * function: COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded
 * address:  0x021BA9C0
 * packet:   pkt_021BA9C0
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   COMM_BTL_DEMO_MAIN_UnloadObject 0x021BA9AC thumb
 */
#include "../include/Obj02551.h"

extern void COMM_BTL_DEMO_MAIN_UnloadObject(char *p);

void COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(void *a)
{
    if (((struct Obj02551 *)a)->fF)
        COMM_BTL_DEMO_MAIN_UnloadObject(a);
}