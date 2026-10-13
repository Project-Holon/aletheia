/*
 * function: FIELD_SOUND_SYSTEM_GetFieldBgmForZone
 * address:  0x02029EB4
 * packet:   pkt_02029EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetPlayerObjectCode  0x02029E58  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_FindZoneBgmOverride  0x02029E74  thumb
 *   ZONEDATA_IsRingtoneEnabled  0x02013C30  thumb
 *   FIELD_SOUND_SYSTEM_GetZoneBgm  0x02029E64  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  FIELD_SOUND_SYSTEM_GetPlayerObjectCode(void *a);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32  FIELD_SOUND_SYSTEM_FindZoneBgmOverride(void *a, u32 id);
extern u32 ZONEDATA_IsRingtoneEnabled(u32 id);
extern u32  FIELD_SOUND_SYSTEM_GetZoneBgm(void *a, u32 id, u32 which);

u32 FIELD_SOUND_SYSTEM_GetFieldBgmForZone(void *a, u32 id, u32 which)
{
    int mode;

    u32 r;

    mode = FIELD_SOUND_SYSTEM_GetPlayerObjectCode(a);
    GAME_DATA_GetBgmInfo(a);
    r = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(a, id);
    if (r == (u32)-1) {
        if (mode == 2) {
            if (ZONEDATA_IsRingtoneEnabled((u16)id)) {
                return 0x3f5;
            }
        }
        if (mode == 1) {
            if (ZONEDATA_IsRingtoneEnabled((u16)id)) {
                return 0x3f4;
            }
        }
        return FIELD_SOUND_SYSTEM_GetZoneBgm(a, id, which);
    }
    return r;
}
