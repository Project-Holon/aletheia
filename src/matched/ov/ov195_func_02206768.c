/*
 * function: SHINKA_DEMO_VIEW_SetModelsPos
 * address:  0x02206768
 * packet:   pkt_02206768
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_VIEW_SetModelOffset 0x022067B0 thumb ov195
 *   SHINKA_DEMO_VIEW_SetQuadOffset 0x022086BC thumb ov195
 */
#include "../include/Obj00300.h"
#include "../include/Obj14534.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void SHINKA_DEMO_VIEW_SetModelOffset(char *a, int b, int c, int d, int e);
extern void SHINKA_DEMO_VIEW_SetQuadOffset(char *a, int b, int c, int d, int e);

void SHINKA_DEMO_VIEW_SetModelsPos(char *a, u32 x, u32 y, u32 z)
{
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(void **)(t + i * 4 + 8) != 0)
            SHINKA_DEMO_VIEW_SetModelOffset(*(void **)(t + i * 4 + 8), ((struct Obj00300 *)a)->f0, x, y, z);
    }
    if (((struct Obj14534 *)t)->f10 != 0)
        SHINKA_DEMO_VIEW_SetQuadOffset(((struct Obj14534 *)t)->f10, ((struct Obj00300 *)a)->f0, x, y, z);
}
