/*
 * function: FIELDMAP_GetZoneWeatherId
 * address:  0x02188C70
 * packet:   pkt_ov021_02188C70
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf (no lr saved): forwards p[1] and the second argument.
 *
 * symbols:
 *   WEATHER_GetZoneWeatherId  0x0202C794  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 WEATHER_GetZoneWeatherId(void *a0, u32 a1);

int FIELDMAP_GetZoneWeatherId(int *p, int b)
{
    return WEATHER_GetZoneWeatherId((void *)p[1], b);
}
