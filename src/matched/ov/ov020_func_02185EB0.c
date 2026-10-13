/*
 * function: EVENT_MAPCHANGE_UpdateEscapeLocation
 * address:  0x02185EB0
 * packet:   pkt_ov020_02185EB0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   GAME_DATA_GetStartLocation  0x0201284C  thumb
 *   ZONEDATA_IsParentZoneD6  0x02014068  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
struct Rec1C;
struct Rec1C *GAME_DATA_GetEntranceLocation(const struct BigObj *p);
struct Rec1C *GAME_DATA_GetStartLocation(const struct BigObj *p);
typedef unsigned int   u32;
u32 ZONEDATA_IsParentZoneD6(u32 id);
void GAME_DATA_SetEscapeLocation(struct BigObj *p, const struct Rec1C *src);
struct t;
void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
u32 ZONEDATA_IsWeatherEnabled(u32 id);

void EVENT_MAPCHANGE_UpdateEscapeLocation(int a, u16 *p)
{
    int r7 = (int)GAME_DATA_GetEntranceLocation((const struct BigObj *)a);
    short *r6 = (short int *)GAME_DATA_GetStartLocation((const struct BigObj *)a);
    u8 buf[0x1c];

    if (ZONEDATA_IsParentZoneD6(p[2])) {
        if (r6[2] == 0x88) {
            GAME_DATA_SetEscapeLocation((struct BigObj *)a, (void *)r7);
        } else if (!ZONEDATA_IsParentZoneD6((u16)r6[2])) {
            ZONEDATA_SetZoneStartLocation((struct t *)buf, 0xd6);
            GAME_DATA_SetEscapeLocation((struct BigObj *)a, (const struct Rec1C *)buf);
        }
    }
    if (r6[2] == 0x9e) {
        if (ZONEDATA_IsWeatherEnabled(p[2]))
            GAME_DATA_SetEscapeLocation((struct BigObj *)a, (void *)r7);
    }
}
