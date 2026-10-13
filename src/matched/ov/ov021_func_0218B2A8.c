/*
 * function: FIELD_EVENT_CHECK_SetEntranceFromRailConnect
 * address:  0x0218B2A8
 * packet:   pkt_ov021_0218B2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   ZONEDATA_SetExitRailLocation  0x02014134  thumb
 *   GAME_DATA_SetEntranceLocation  0x02012878  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04982.h"

typedef unsigned short u16;
typedef signed short   s16;

typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void ZONEDATA_SetExitRailLocation(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
struct BigObj;
struct Rec1C;
extern void GAME_DATA_SetEntranceLocation(struct BigObj *p, const struct Rec1C *src);

void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(char *p, int s, u16 *v)
{
    int buf[7];

    ZONEDATA_SetExitRailLocation((u8 *)buf, FIELDMAP_GetZoneId(((struct Obj04982 *)p)->f14), (s16)s, 0, 0, v[0], v[3], (s16)v[2]);
    GAME_DATA_SetEntranceLocation(((struct Obj04982 *)p)->f8, (const struct Rec1C *)buf);
}
