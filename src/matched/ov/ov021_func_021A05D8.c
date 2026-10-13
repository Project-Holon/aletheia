/*
 * function: FIELD_LIGHT_ReloadZoneTable
 * address:  0x021A05D8
 * packet:   pkt_ov021_021A05D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_Dummy  0x021A07B0  thumb  ov021
 *   FIELD_LIGHT_LoadZoneTable  0x021A0734  thumb  ov021
 *   FIELD_LIGHT_FindKeyframe  0x021A07B4  thumb  ov021
 *   FIELD_LIGHT_BeginBlendDefault  0x021A0974  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09537.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_Dummy(void);
extern void FIELD_LIGHT_LoadZoneTable(u8 *a, u32 b);
extern u32 FIELD_LIGHT_FindKeyframe(u8 *p, int t);
extern void FIELD_LIGHT_BeginBlendDefault(u32 a1, u32 a2, u32 a3);

void FIELD_LIGHT_ReloadZoneTable(u8 *a)
{
    u32 r;

    FIELD_LIGHT_Dummy();
    FIELD_LIGHT_LoadZoneTable(a, ((struct Obj09537 *)a)->f354);
    r = FIELD_LIGHT_FindKeyframe(a, ((struct Obj09537 *)a)->f48C);
    ((struct Obj09537 *)a)->f350 = r;
    FIELD_LIGHT_BeginBlendDefault((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + r * 0x34));
}
