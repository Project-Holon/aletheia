/*
 * function: CALENDER_GetWeatherOnDate
 * address:  0x02164844
 * packet:   pkt_ov010_02164844
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up a table entry; 0xFFFF means missing and forwards to
 * ZONEDATA_GetWeatherId, otherwise reads one byte through ARC_TOOL_ReadHandleMemberRange.
 *
 * symbols:
 *   CALENDER_FindZoneOffset  0x021648A8  thumb ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   CALENDER_GetDayOfYear  0x021648CC  thumb ov010
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18978.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 CALENDER_FindZoneOffset(u8 *p, u32 n);
extern u8   ZONEDATA_GetWeatherId(u32 b);
extern u16 CALENDER_GetDayOfYear(int n, int k);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);

u8 CALENDER_GetWeatherOnDate(u8 *a, u32 b, u8 c, u8 d)
{
    u32 t = CALENDER_FindZoneOffset(a, b);
    u8 out;
    u16 s;
    if (t == 0xffff) {
        return ZONEDATA_GetWeatherId(b);
    }
    s = t + CALENDER_GetDayOfYear(c, d);
    ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)((struct Obj18978 *)a)->f8, 0, s, 1, &out);
    return out;
}
