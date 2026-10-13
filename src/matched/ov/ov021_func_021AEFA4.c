/*
 * function: SCRCMD_RestoreBgmVolumeEvent
 * address:  0x021AEFA4
 * packet:   pkt_ov021_021AEFA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Ctx;
struct SoundSys;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_FadeVolume(struct SoundSys *sys, u8 level, u16 frames);

int SCRCMD_RestoreBgmVolumeEvent(u32 *a, u32 *st)
{
    u32 r = GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData((const struct Ctx *)(*a)));

    switch (*st) {
    case 0:
        FIELD_SOUND_SYSTEM_FadeVolume((struct SoundSys *)r, 0x7f, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
