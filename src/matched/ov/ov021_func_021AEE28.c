/*
 * function: SCRCMD_FadeOutPlayBgmWithFade
 * address:  0x021AEE28
 * packet:   pkt_ov021_021AEE28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask  0x02029A04  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PauseSlots  0x02028BA0  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(void *a, u32 b, u16 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *a);
extern void FIELD_SOUND_SYSTEM_PauseSlots(u8 *o, u32 v);
extern void SCRIPT_WORK_SetCheckFlag(int n);

int SCRCMD_FadeOutPlayBgmWithFade(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 z;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    y = SCRCMD_WORK_GetScriptWork((void *)b);
    z = (u32)FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(x, VM_GetU16((struct Stream *)a), VM_GetU16((struct Stream *)a));
    SCRIPT_SYS_CallEvent(y, (void *)z);
    FIELD_SOUND_SYSTEM_PauseSlots((u8 *)GAME_DATA_GetBgmInfo((const struct BigObj *)GAMESYSTEM_GetGameData(x)), 2);
    SCRIPT_WORK_SetCheckFlag(13);
    return 1;
}
