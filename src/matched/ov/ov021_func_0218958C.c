/*
 * function: FIELDMAP_ChangeZoneFog
 * address:  0x0218958C
 * packet:   pkt_ov021_0218958C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetZoneFog  0x02188C68  thumb  ov021
 *   FIELD_ZONEFOG_Clear  0x021A0358  thumb  ov021
 *   ZONEDATA_GetFogId  0x02013EEC  thumb
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   FIELD_ZONEFOG_SetUp  0x021A0338  thumb  ov021
 */
#include "../include/Obj19498.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 FIELDMAP_GetZoneFog(u8 *p);
void FIELD_ZONEFOG_Clear(int a);
u32 ZONEDATA_GetFogId(u32 id);
int ZONEDATA_GetLightId(unsigned short id);
void FIELD_ZONEFOG_SetUp(u8 *p, u32 id, u32 c, u8 d);

void FIELDMAP_ChangeZoneFog(unsigned char *p, int id)
{
    int a;
    FIELD_ZONEFOG_Clear(FIELDMAP_GetZoneFog(p));
    a = (int)ZONEDATA_GetFogId((unsigned short)id);
    FIELD_ZONEFOG_SetUp((u8 *)(((struct Obj19498 *)p)->f1C), a, ZONEDATA_GetLightId(id), 1);
}
