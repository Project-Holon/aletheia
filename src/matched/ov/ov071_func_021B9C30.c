/*
 * function: MONOLITH_TOOL_UpdateScrollArrows
 * address:  0x021B9C30
 * packet:   pkt_ov071_021B9C30
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   MONOLITH_TOOL_Noop  0x021B7170  thumb  ov071
 */
#include "../include/Obj00044.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void MONOLITH_TOOL_Noop(void *a);

void MONOLITH_TOOL_UpdateScrollArrows(u8 *p)
{
    if (((struct Obj00044 *)p)->f2D8 <= 0x800)
        CLACT_SetActorDrawEnable(((struct Obj00044 *)p)->f18, 0);
    else
        CLACT_SetActorDrawEnable(((struct Obj00044 *)p)->f18, 1);
    if ((((struct Obj00044 *)p)->f2D8 >> 8) >= p[0x27c] * 32 - 200)
        CLACT_SetActorDrawEnable(((struct Obj00044 *)p)->f1C, 0);
    else
        CLACT_SetActorDrawEnable(((struct Obj00044 *)p)->f1C, 1);
    MONOLITH_TOOL_Noop(((struct Obj00044 *)p)->f18);
    MONOLITH_TOOL_Noop(((struct Obj00044 *)p)->f1C);
}
