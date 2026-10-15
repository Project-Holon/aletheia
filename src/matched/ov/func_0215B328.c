/*
 * function: SCRCMD_WORK_CmdSetEventFlagOffset
 * address:  0x0215B328
 * packet:   pkt_0215B328
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
 *   EVENT_POKE_STATUS_SetFlag  0x0215A4EC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int EVENT_POKE_STATUS_SetFlag();

int SCRCMD_WORK_CmdSetEventFlagOffset(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215B334:
    a0 = GAME_DATA_GetEventWork(v0);
loc_0215B338:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215B342:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = EVENT_POKE_STATUS_SetFlag(a0, a1);
loc_0215B34A:
a0 = 0;
    return a0;}
