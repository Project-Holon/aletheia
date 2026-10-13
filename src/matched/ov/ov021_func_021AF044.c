/*
 * function: SCRCMD_ResumeZoneBgmWithFade
 * address:  0x021AF044
 * packet:   pkt_ov021_021AF044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx (arm9, unlabelled thumb veneer: ldr r3,[pc]; bx r3;
 * .word 0x02029EB5) has no witness outside the range (evidence class: none;
 * arm9 leaf belongs to the integrator, not filed here).
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   FIELD_SOUND_SYSTEM_StartChangeTask  0x020298A0  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   FIELD_SOUND_SYSTEM_ResumeSlots  0x02028BDC  thumb
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
struct Stream;
extern unsigned short VM_GetU16(struct Stream *s);
struct Ctx;
struct S;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *a);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void *a, unsigned int id, unsigned int which);
extern void *FIELD_SOUND_SYSTEM_StartChangeTask(void *a, u32 b, u32 c, u32 d);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void FIELD_SOUND_SYSTEM_ResumeSlots(struct S *s, u32 mask);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_ResumeZoneBgmWithFade(struct Stream *a, u32 b)
{
    u32 y, m, n, q, s;
    void *x;
    void *l;
    void *p;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    y = (u32)GAMESYSTEM_GetGameData(x);
    l = GAMESYSTEM_GetFieldMap((void *)x);
    m = GAME_DATA_GetBgmInfo((const struct BigObj *)y);
    p = SCRCMD_WORK_GetScriptWork((void *)b);
    n = VM_GetU16(a);
    q = GAME_DATA_GetSeason((const struct BigObj *)y);
    s = FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx((void *)y, FIELDMAP_GetZoneId(l), q);
    SCRIPT_SYS_CallEvent(p, (void *)FIELD_SOUND_SYSTEM_StartChangeTask(x, s, n, 0x3c));
    FIELD_SOUND_SYSTEM_ResumeSlots((struct S *)m, 2);
    SCRIPT_WORK_ResetCheckFlag(13);
    return 1;
}
