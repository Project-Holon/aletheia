/*
 * function: SCRCMD_PlayTrainerEncounterBgm
 * address:  0x021AEC40
 * packet:   pkt_ov021_021AEC40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   FIELD_SOUND_SYSTEM_GetTrainerClassBgm  0x02029E20  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask  0x02029AF4  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
extern unsigned short FIELD_SOUND_SYSTEM_GetTrainerClassBgm(u32 k);
extern void *FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(void *a, u32 b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PlayTrainerEncounterBgm(u32 a, u32 b)
{
    void *x;
    void *y;

    x = SCRCMD_WORK_GetGameSystem((void *)b);
    SCRCMD_WORK_GetGameData((void *)b);
    y = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_SYS_CallEvent(y, FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(x, FIELD_SOUND_SYSTEM_GetTrainerClassBgm(TPOKE_DATA_GetRecordField((void *)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b), 1))));
    return 1;
}
