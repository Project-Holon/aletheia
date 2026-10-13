/*
 * function: SCRCMD_TRIALHOUSE_GetClearFlags
 * address:  0x0216A774
 * packet:   pkt_0216A774
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   TRIAL_HOUSE_GetRecordSlotsState  0x021D1028  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int TRIAL_HOUSE_GetRecordSlotsState();

int SCRCMD_TRIALHOUSE_GetClearFlags(int a0, int a1)
{
    int t4;
    int t5;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216A780:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A786:
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0216A790:
    a0 = TRIAL_HOUSE_GetRecordSlotsState(v1);
loc_0216A798:
*q = a0;
a0 = 0;
    return a0;}
