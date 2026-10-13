/*
 * function: FIELD_PLAYER_CORE_PostZoneBgmChange
 * address:  0x021A4114
 * packet:   pkt_ov021_021A4114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade  0x02029D8C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
void *FIELDMAP_GetGameSystem(void *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
u32 GAME_DATA_GetBgmInfo(const struct BigObj *x);
typedef unsigned char  u8;
u16 FIELDMAP_GetZoneId(u8 *p);
void FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade(u32 a0, u32 a1, u32 a2);

void FIELD_PLAYER_CORE_PostZoneBgmChange(u32 *p)
{
    int a = (int)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[2]));
    int b = GAME_DATA_GetBgmInfo((const struct BigObj *)a);

    FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade(b, a, (u16)(int)FIELDMAP_GetZoneId((u8 *)p[2]));
}
