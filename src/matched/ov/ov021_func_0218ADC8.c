/*
 * function: FIELD_EVENT_CHECK_SetEntranceFromGridConnect
 * address:  0x0218ADC8
 * packet:   pkt_ov021_0218ADC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a 0x1C byte rectangle record with ZONEDATA_SetExitLocation from the object's
 * map value, an id and three words, and hands it to GAME_DATA_SetEntranceLocation.
 *
 * symbols:
 *   ZONEDATA_SetExitLocation  0x02014110  thumb
 *   GAME_DATA_SetEntranceLocation  0x02012878  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void ZONEDATA_SetExitLocation(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
struct BigObj;
struct Rec1C;
extern void GAME_DATA_SetEntranceLocation(struct BigObj *p, const struct Rec1C *src);

void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(u8 *p, int id, u32 *pos)
{
    u8 buf[0x1C];

    ZONEDATA_SetExitLocation(buf, FIELDMAP_GetZoneId(*(u8 * *)&((struct Obj00705 *)p)->f14), id, 0, 0, pos[0], pos[1], pos[2]);
    GAME_DATA_SetEntranceLocation(((struct Obj00705 *)p)->f8, (const struct Rec1C *)buf);
}
