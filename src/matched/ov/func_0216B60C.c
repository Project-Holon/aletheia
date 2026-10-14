/*
 * function: SCRCMD_RESEARCH_CmdGetMissionElapsedHours
 * address:  0x0216B60C
 * packet:   pkt_0216B60C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionElapsedHours  0x0216BB18  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int SCRCMD_RESEARCH_GetMissionElapsedHours(void *sys);

int SCRCMD_RESEARCH_CmdGetMissionElapsedHours(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216B618:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216B61E:
    t6 = GAME_DATA_GetSaveControl((struct Big *)v1);
loc_0216B622:
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0216B62C:
    a0 = SCRCMD_RESEARCH_GetMissionElapsedHours(t6);
loc_0216B634:
*q = a0;
a0 = 0;
    return a0;}
