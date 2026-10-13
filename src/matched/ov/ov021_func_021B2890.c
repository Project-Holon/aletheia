/*
 * function: SCRCMD_SCREENEFFECTS_StartFieldFadeIn
 * address:  0x021B2890
 * packet:   pkt_ov021_021B2890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * EVENT_FIELDMAP_CONTROL_StartFadeIn reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_SCREENEFFECTS_StartFieldFadeIn(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 p;
    void *q;
    u32 z;

    x = SCRCMD_WORK_GetScriptWork((void *)b);
    y = SCRCMD_WORK_GetGameSystem((void *)b);
    p = (u32)GAMESYSTEM_GetGameData(y);
    q = GAMESYSTEM_GetFieldMap((void *)y);
    z = GAME_DATA_GetSeason((const struct BigObj *)p);
    SCRIPT_SYS_CallEvent(x, (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(y, (int)q, 3, 0, 0, z, z));
    return 0;
}
