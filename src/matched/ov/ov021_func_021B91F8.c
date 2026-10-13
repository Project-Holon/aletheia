/*
 * function: FIELD_RAIL_WORK_GetSpotPos
 * address:  0x021B91F8
 * packet:   pkt_ov021_021B91F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_RAIL_SETTING_GetLinePos  0x021B8848  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLinePosFunc  0x021B8894  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00454.h"
#include "../include/Obj20083.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { u32 a, b, c; } V3;
typedef void (*Fn)(void *, void *);

u32 *FIELD_RAIL_SETTING_GetLinePos(void *a, u32 b);
Fn FIELD_RAIL_SETTING_GetLinePosFunc(void *a, u32 b);

void FIELD_RAIL_WORK_GetSpotPos(u8 *p, V3 *out)
{
    Fn f;

    if (((struct Obj00454 *)p)->f0 == 0) {
        *out = *(V3 *)(*(u8 * *)&((struct Obj00454 *)p)->f4 + 0x30);
        return;
    }
    if (((struct Obj00454 *)p)->f0 == 1) {
        u32 *r = FIELD_RAIL_SETTING_GetLinePos(((struct Obj00454 *)p)->f24, ((struct Obj20083 *)(*(u8 * *)&((struct Obj00454 *)p)->f4))->fC);
        f = FIELD_RAIL_SETTING_GetLinePosFunc(((struct Obj00454 *)p)->f24, *r);
        if (f)
            f(p, out);
    }
}
