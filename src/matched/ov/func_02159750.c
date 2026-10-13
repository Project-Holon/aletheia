/*
 * function: SCRIPT_WORK_CmdResetEventFlag
 * address:  0x02159750
 * packet:   pkt_02159750
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
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int ZONEDATA_ResetEventFlag();

int SCRIPT_WORK_CmdResetEventFlag(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215975C:
    a0 = GAME_DATA_GetEventWork(v0);
loc_02159760:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215976A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = ZONEDATA_ResetEventFlag(a0, a1);
loc_02159772:
a0 = 0;
    return a0;}
