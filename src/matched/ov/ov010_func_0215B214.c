/*
 * function: SCRCMD_WORK_CmdEventDataSetA
 * address:  0x0215B214
 * packet:   pkt_ov010_0215B214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_SetBgEventGridPos  0x02162A74  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern int EVENTDATA_SYSTEM_SetBgEventGridPos(int, int, u16, u16, u16);
int SCRCMD_WORK_CmdEventDataSetA(int a0, int a1)
{
    int v = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    EVENTDATA_SYSTEM_SetBgEventGridPos(GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((void *)a1)), v, x, y, z);
    return 0;
}
