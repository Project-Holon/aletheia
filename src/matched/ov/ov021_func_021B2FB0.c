/*
 * function: SCRCMD_SCREENEFFECTS_ShowPlaceName
 * address:  0x021B2FB0
 * packet:   pkt_ov021_021B2FB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_ForceShowForZone  0x021BC5A0  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FIELD_PLACE_NAME_ForceShowForZone(void *p, int v);

int SCRCMD_SCREENEFFECTS_ShowPlaceName(u32 a, u32 b)
{
    void *w = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    u32 x = FIELDMAP_GetPlaceName(w);

    FIELD_PLACE_NAME_ForceShowForZone((void *)x, FIELDMAP_GetZoneId(w));
    return 0;
}
