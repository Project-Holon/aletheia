/*
 * function: SCRCMD_RestoreBgmVolume
 * address:  0x021AEF60
 * packet:   pkt_ov021_021AEF60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
struct BigObj;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
typedef unsigned short u16;
struct SoundSys;
extern void FIELD_SOUND_SYSTEM_FadeVolume(struct SoundSys *sys, u8 level, u16 frames);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_RestoreBgmVolume(u32 a, u32 b)
{
    u32 y;
    void *x;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    y = (u32)GAMESYSTEM_GetGameData(x);
    GAMESYSTEM_GetFieldMap((void *)x);
    y = GAME_DATA_GetBgmInfo((const struct BigObj *)y);
    FIELD_SOUND_SYSTEM_FadeVolume((struct SoundSys *)y, 0x7f, (u8)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    SCRIPT_WORK_ResetCheckFlag(12);
    return 0;
}
