/*
 * function: FIELD_EVENT_CHECK_StopSoundAfterEvent
 * address:  0x0218A6E8
 * packet:   pkt_ov021_0218A6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELD_SUBSCREEN_GetCGear  0x021A1358  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StopRingtone  0x02028A70  thumb
 *   C_GEAR_IsLastCommandWifi  0x021F2AB8  thumb  ov029
 *   C_GEAR_StopRingtone  0x021F2AD4  thumb  ov029
 */

extern unsigned int FIELDMAP_GetSubscreen(unsigned char *p);
typedef unsigned int   u32;
struct BigObj;
extern u32 FIELD_SUBSCREEN_GetCGear(u32 *p);
typedef unsigned char  u8;
struct Ctx;
struct SoundSys;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_StopRingtone(struct SoundSys *sys);
extern int C_GEAR_IsLastCommandWifi(char *p);
extern void C_GEAR_StopRingtone(u8 *p);

void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *sys, void *q)
{
    void *r;

    r = (void *)FIELD_SUBSCREEN_GetCGear((u32 *)FIELDMAP_GetSubscreen(q));
    if (r == 0) {
        FIELD_SOUND_SYSTEM_StopRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(sys)));
        return;
    }
    if (C_GEAR_IsLastCommandWifi(r) == 0) {
        FIELD_SOUND_SYSTEM_StopRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(sys)));
        C_GEAR_StopRingtone(r);
    }
}
