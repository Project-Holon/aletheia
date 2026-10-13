/*
 * function: EVENT_MAPCHANGE_RunSituationWarpArrivalEvent
 * address:  0x02185694
 * packet:   pkt_ov020_02185694
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocked (evidence class: none, unresolved callee sites) by two unlabelled arm9
 * leaves inside labelled arm9 functions (the integrator's), each verified EXACT in a
 * scratch file with `one --region arm9 --thumb`:
 *   0x0202B578: int ISS_SYS_GetSwitchSys(int *p) { return p[8]; }
 *   0x02029DF4: void FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void) { FIELD_SOUND_SYSTEM_GetFieldBgmForZone(); }   (thumb tail-call
 *               stub, .word 0x02029EB5)
 *
 * symbols:
 *   EVENT_MAPCHANGE_InitFieldFromSituationWarp  0x0218562C  thumb  ov020
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   ISS_SWITCH_SYS_ResetSwitch  0x0202C110  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   FIELD_SOUND_SYSTEM_StartChangeTask  0x020298A0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldOpenNoNotifyEvent  0x020145FC  thumb
 */

void EVENT_MAPCHANGE_InitFieldFromSituationWarp(int a);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Evt;
struct Rec44;
struct SaveBlock;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
void GAME_DATA_SetPlayerObjectCode(struct Rec44 *p, u32 v);
u32 GAMESYSTEM_GetIssSystem(u32 *p);
u32 ISS_SYS_GetSwitchSys(u32 *p);
void ISS_SWITCH_SYS_ResetSwitch(void *p);
u8 GAME_DATA_GetSeason(const struct BigObj *p);
unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void *a, unsigned int id, unsigned int which);
void *FIELD_SOUND_SYSTEM_StartChangeTask(void *a, u32 b, u32 c, u32 d);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
int FIELD_STATUS_CreateFieldOpenNoNotifyEvent(int a);

int EVENT_MAPCHANGE_RunSituationWarpArrivalEvent(int a0, int *st, int *p)
{
    int r;

    switch (st[0]) {
    case 0:
        EVENT_MAPCHANGE_InitFieldFromSituationWarp(p[0]);
        st[0]++;
        break;
    case 1:
        GAME_DATA_SetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData((const struct Ctx *)p[0])), 0);
        ISS_SWITCH_SYS_ResetSwitch((void *)ISS_SYS_GetSwitchSys((u32 *)GAMESYSTEM_GetIssSystem((u32 *)p[0])));
        r = FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx((void *)p[1], ((short *)p)[6], GAME_DATA_GetSeason((const struct BigObj *)p[1]));
        r = (int)FIELD_SOUND_SYSTEM_StartChangeTask((void *)p[0], r, 0, 0x3c);
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 2:
        r = FIELD_STATUS_CreateFieldOpenNoNotifyEvent(p[0]);
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
