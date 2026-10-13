/*
 * function: SCRIPT_WORK_CmdPushEventFlag
 * address:  0x021594B0
 * packet:   pkt_021594B0
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
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   VM_PushStack  0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef signed int     s32;
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int VM_PushStack();

int SCRIPT_WORK_CmdPushEventFlag(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_021594BC:
    a0 = GAME_DATA_GetEventWork(v0);
loc_021594C0:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_021594CA:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = ZONEDATA_CheckEventFlag((void *)a0, a1);
loc_021594D2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = VM_PushStack(a0, a1);
loc_021594DA:
a0 = 0;
    return a0;}
