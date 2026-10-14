/*
 * function: DRAW_SYSTEM_FlushStrokes
 * address: 0x021B6C4C
 * packet: pkt_ov172_021B6C4C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DRAW_SYSTEM_GetStroke 0x021B6EC4 thumb ov172
 *   DRAW_SYSTEM_DrawStroke 0x021B6C78 thumb ov172
 *   DRAW_SYSTEM_AdvanceIndex 0x021B6ECC thumb ov172
 */
#include "../include/Obj04549.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *DRAW_SYSTEM_GetStroke(void *, int);
typedef struct Stroke Stroke;
extern void DRAW_SYSTEM_DrawStroke(u16 *o, const Stroke *e);
extern void DRAW_SYSTEM_AdvanceIndex(void *, u16 *);

void DRAW_SYSTEM_FlushStrokes(char *p)
{
    if (((struct Obj04549 *)p)->f6 != ((struct Obj04549 *)p)->f4) do {
        DRAW_SYSTEM_DrawStroke((u16 *)p, (const Stroke *)DRAW_SYSTEM_GetStroke(p, ((struct Obj04549 *)p)->f6));
        DRAW_SYSTEM_AdvanceIndex(p, (u16 *)(p + 6));
    } while (((struct Obj04549 *)p)->f6 != ((struct Obj04549 *)p)->f4);
}
