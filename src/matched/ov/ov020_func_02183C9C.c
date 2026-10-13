/*
 * function: EVENT_MAPCHANGE_NewGameStartEvent
 * address:  0x02183C9C
 * packet:   pkt_ov020_02183C9C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct (202 bytes + 2 padding). The one unresolved site is
 * +005E THM_CALL FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx: an unlabelled arm9 Thumb thunk
 * (ldr r3,[pc,#0]; bx r3; .word 0x02029EB5), so no label and no
 * outside witness. It is the integrator's arm9 leaf, verified EXACT at
 * 0x02029DF4 (region arm9, thumb, dsi/1.1p1 -O4,p) as:
 *     extern int FIELD_SOUND_SYSTEM_GetFieldBgmForZone(u32 a, int b, u32 c);   (0x02029EB4 thumb)
 *     int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(u32 a, int b, u32 c)
 *     { return FIELD_SOUND_SYSTEM_GetFieldBgmForZone(a, b, c); }
 * Once that leaf is filed in an arm9 shard this caller resolves as
 * `matched` and goes EXACT. The same call caps the twin
 * src/matched/ov/ov012_func_021743A4.c, which `one` now reports MATCH.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRIPT_SYS_RunInitScript  0x02158A10  thumb  ov010
 *   EVENT_MAPCHANGE_UpdateFieldStateForZone  0x02185A68  thumb  ov020
 *   EVENT_MAPCHANGE_ApplyLocation  0x021857C0  thumb  ov020
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   FIELD_SOUND_SYSTEM_StartChangeTask  0x020298A0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldOpenNoNotifyEvent  0x020145FC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct Arg {
    u32 f0;
    u8  pad4[4];
    u8  f8[4];
    s16 fC;
} Arg;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void SCRIPT_SYS_RunInitScript(int a, int b);
extern void EVENT_MAPCHANGE_UpdateFieldStateForZone(void *a, int b);
extern void EVENT_MAPCHANGE_ApplyLocation(void *a, int b);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void *a, unsigned int id, unsigned int which);
extern void *FIELD_SOUND_SYSTEM_StartChangeTask(void *a, u32 b, u32 c, u32 d);
struct Ctx;
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldOpenNoNotifyEvent(int a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_ShowForZone(void *p, int v);

int EVENT_MAPCHANGE_NewGameStartEvent(void *obj, int *state, Arg *arg)
{
    u32 x = arg->f0;
    u32 t = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)x);
    void *w;

    GAME_DATA_GetEventWork((const struct BigObj *)t);
    switch (*state) {
    case 0:
        SCRIPT_SYS_RunInitScript(x, 1);
        EVENT_MAPCHANGE_UpdateFieldStateForZone((void *)x, (u16)arg->fC);
        EVENT_MAPCHANGE_ApplyLocation((void *)x, (int)arg->f8);
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(obj, FIELD_SOUND_SYSTEM_StartChangeTask((void *)x, FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx((void *)t, arg->fC, GAME_DATA_GetSeason((const struct BigObj *)t)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldOpenNoNotifyEvent(x));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(obj, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, (int)GAMESYSTEM_GetFieldMap((void *)x), 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        w = GAMESYSTEM_GetFieldMap((void *)x);
        if (FIELDMAP_GetPlaceName(w) != 0)
            FIELD_PLACE_NAME_ShowForZone((void *)FIELDMAP_GetPlaceName(w), arg->fC);
        return 1;
    }
    return 0;
}
