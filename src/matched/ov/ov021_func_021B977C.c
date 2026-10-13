/*
 * function: FIELD_RAIL_WORK_DebugCheck
 * address:  0x021B977C
 * packet:   pkt_ov021_021B977C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_POINT_DebugPrint  0x021B976C  thumb  ov021
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb  ov021
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04250.h"
#include "../include/Obj20089.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021DE2B0[];
extern u8 d_021DE2B4[];
extern u8 d_021DE2BC[];

void FIELD_RAIL_POINT_DebugPrint(void *a, void *b, void *c);
u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);

void FIELD_RAIL_WORK_DebugCheck(u8 *p)
{
    void *x;
    void *y;

    if (((struct Obj04250 *)p)->f0 == 0) {
        FIELD_RAIL_POINT_DebugPrint(0, ((struct Obj04250 *)p)->f4, d_021DE2B0);
    } else if (((struct Obj04250 *)p)->f0 == 1) {
        x = FIELD_RAIL_SETTING_GetPoint(((struct Obj04250 *)p)->f24, **(u32 * *)&((struct Obj04250 *)p)->f4);
        y = FIELD_RAIL_SETTING_GetPoint(((struct Obj04250 *)p)->f24, ((struct Obj20089 *)(*(u8 * *)&((struct Obj04250 *)p)->f4))->f4);
        FIELD_RAIL_POINT_DebugPrint(d_021DE2B4, x, 0);
        FIELD_RAIL_POINT_DebugPrint(d_021DE2BC, y, d_021DE2B0);
    }
}
