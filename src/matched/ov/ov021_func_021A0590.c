/*
 * function: FIELD_LIGHT_ChangeTable
 * address:  0x021A0590
 * packet:   pkt_ov021_021A0590
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_Dummy  0x021A07B0  thumb  ov021
 *   FIELD_LIGHT_LoadTable  0x021A0748  thumb  ov021
 *   FIELD_LIGHT_FindKeyframe  0x021A07B4  thumb  ov021
 *   FIELD_LIGHT_BeginBlend  0x021A0980  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12698.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_Dummy(void);
extern void FIELD_LIGHT_LoadTable(u8 *a, u32 b, u32 c);
extern u32 FIELD_LIGHT_FindKeyframe(u8 *p, int t);
extern void FIELD_LIGHT_BeginBlend(u8 *a, u8 *b, u8 *c, u32 d);

void FIELD_LIGHT_ChangeTable(u8 *a, u32 b, u32 c, u32 d)
{
    u32 r;

    FIELD_LIGHT_Dummy();
    FIELD_LIGHT_LoadTable(a, b, c);
    r = FIELD_LIGHT_FindKeyframe(a, ((struct Obj12698 *)a)->f48C);
    ((struct Obj12698 *)a)->f350 = r;
    FIELD_LIGHT_BeginBlend(a + 0x390, a + 0x356, a + 0x10 + r * 0x34, d);
}
