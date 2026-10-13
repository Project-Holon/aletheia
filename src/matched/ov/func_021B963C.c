/*
 * function: FIELD_RAIL_LINE_IsConsistent
 * address:  0x021B963C
 * packet:   pkt_021B963C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb
 *   FIELD_RAIL_POINT_GetLineKey  0x021B960C  thumb
 *   FIELD_RAIL_KEY_Opposite  0x021B93D4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02052.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);
u32 FIELD_RAIL_POINT_GetLineKey(u32 *p, u8 *v, u8 *q);
int FIELD_RAIL_KEY_Opposite(int dir);

int FIELD_RAIL_LINE_IsConsistent(u8 *a, u8 *b)
{
    u8 *row1, *row2;
    u32 r1, r2;

    if (((struct Obj02052 *)a)->f0 == 0xFFFF || ((struct Obj02052 *)a)->f4 == 0xFFFF)
        return 0;
    row1 = FIELD_RAIL_SETTING_GetPoint(b, ((struct Obj02052 *)a)->f0);
    row2 = FIELD_RAIL_SETTING_GetPoint(b, ((struct Obj02052 *)a)->f4);
    r1 = FIELD_RAIL_POINT_GetLineKey((u32 *)row1, a, b);
    if (r1 == 0)
        return 0;
    if (r1 != ((struct Obj02052 *)a)->f8)
        return 0;
    r2 = FIELD_RAIL_POINT_GetLineKey((u32 *)row2, a, b);
    if (r2 == 0)
        return 0;
    if (r2 != (u32)FIELD_RAIL_KEY_Opposite(((struct Obj02052 *)a)->f8))
        return 0;
    return 1;
}
