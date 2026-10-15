/*
 * function: DOUBLE3DDISP_GetField04
 * address:  0x0204EA38
 * packet:   pkt_0204E8C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A80     0x02146A80  data
 *
 * The +4 word of the singleton, through its pool word.  The same global
 * DOUBLE3DDISP_Delete and DOUBLE3DDISP_SetupGraphics write.
 */

#include "../include/G_Double3Ddisp.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Double3Ddisp *g_02146A80;

u32 DOUBLE3DDISP_GetField04(void)
{
    return *(u32 *)(((u8 *)g_02146A80) + 4);
}
