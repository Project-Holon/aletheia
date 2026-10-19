/*
 * function: SCRCMD_WORK_CmdResetEventFlagOffset
 * address:  0x0215B350
 * packet:   pkt_0215B350
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   EVENT_TRAINER_ClearDefeatedFlag  0x0215A500  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int EVENT_TRAINER_ClearDefeatedFlag();

int SCRCMD_WORK_CmdResetEventFlagOffset(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215B35C:
    a0 = GAME_DATA_GetEventWork(v0);
loc_0215B360:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215B36A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = EVENT_TRAINER_ClearDefeatedFlag(a0, a1);
loc_0215B372:
a0 = 0;
    return a0;}
