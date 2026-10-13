/*
 * function: FIELD_RAIL_POINT_IsConsistent
 * address:  0x021B96AC
 * packet:   pkt_021B96AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_SETTING_GetLine  0x021B87FC  thumb
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb
 *   FIELD_RAIL_KEY_Opposite  0x021B93D4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09187.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *FIELD_RAIL_SETTING_GetLine(u8 *p, u32 idx);
u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);
int FIELD_RAIL_KEY_Opposite(int dir);

int FIELD_RAIL_POINT_IsConsistent(u8 *a, u8 *b)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        u32 val = *(u32 *)(a + i * 4 + 0x10);
        u32 key = *(u32 *)(a + i * 4);
        u8 *row;
        u8 *r4;
        u8 *r0;

        if ((val == 0) != (key == 0xFFFF))
            return 0;
        if (key == 0xFFFF)
            continue;
        row = FIELD_RAIL_SETTING_GetLine(b, key);
        r4 = FIELD_RAIL_SETTING_GetPoint(b, ((struct Obj09187 *)row)->f0);
        r0 = FIELD_RAIL_SETTING_GetPoint(b, ((struct Obj09187 *)row)->f4);
        if (r4 != a && r0 != a)
            return 0;
        if (*(u32 *)(a + i * 4 + 0x10) == 0)
            continue;
        for (j = i + 1; j < 4; j++) {
            if (*(u32 *)(a + i * 4 + 0x10) == (u32)FIELD_RAIL_KEY_Opposite(*(u32 *)(a + j * 4 + 0x10))) {
                if (((struct Obj09187 *)row)->f8 != *(u32 *)(FIELD_RAIL_SETTING_GetLine(b, *(u32 *)(a + j * 4)) + 8))
                    return 0;
            }
        }
    }
    return 1;
}
