/*
 * function: SCRCMD_PushBgmAndPlayWait
 * address:  0x021AF0BC
 * packet:   pkt_ov021_021AF0BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask  0x02029AF4  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(void *a, u32 b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PushBgmAndPlayWait(u32 a, u32 b)
{
    void *y = SCRCMD_WORK_GetGameSystem((void *)b);
    void *x;

    GAMESYSTEM_GetGameData(y);
    GAMESYSTEM_GetFieldMap((void *)y);
    x = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_SYS_CallEvent(x, FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(y, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    return 1;
}
