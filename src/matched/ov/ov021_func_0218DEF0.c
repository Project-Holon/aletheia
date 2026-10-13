/*
 * function: FIELD_G3D_MAPPER_StampFrame
 * address:  0x0218DEF0
 * packet:   pkt_0218DEF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_02FFFC3C  0x02FFFC3C  data  a4
 */
#include "../include/Obj19554.h"

typedef unsigned int u32;

void FIELD_G3D_MAPPER_StampFrame(char *p)
{
    ((struct Obj19554 *)p)->f50 = *(u32 *)0x02FFFC3C;
}
