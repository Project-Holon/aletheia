/*
 * function: FIELDMAP_ChangeZoneWeather
 * address:  0x02189560
 * packet:   pkt_ov021_02189560
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_StoreZoneWeatherId  0x0202C83C  thumb
 *   GAME_DATA_GetWeatherId  0x02012994  thumb
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u32 FIELDMAP_GetWeather(u8 *p);
int WEATHER_StoreZoneWeatherId(int a0, int a1);
u8 GAME_DATA_GetWeatherId(const struct BigObj *p);
void WEATHER_RequestChange(int x, int k);

void FIELDMAP_ChangeZoneWeather(int *p, int b)
{
    int r = (int)FIELDMAP_GetWeather((u8 *)p);
    unsigned short k;
    WEATHER_StoreZoneWeatherId(p[1], b);
    k = (int)GAME_DATA_GetWeatherId((const struct BigObj *)p[2]);
    if (k != 0xF)
        WEATHER_RequestChange(r, k);
}
