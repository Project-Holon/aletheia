/*
 * function: SCRCMD_NETWORK_CmdSetNpcEventFromTable
 * address:  0x0215F33C
 * packet:   pkt_ov010_0215F33C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   SCRIPT_WORK_GetReturnFlag  0x0215911C  thumb  ov010
 *   SCRCMD_NETWORK_FindNpcTableRow  0x0215F608  thumb  ov010
 *   func_0215A480  0x0215A480  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcEventId  0x02162788  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 SCRIPT_WORK_GetReturnFlag(void *p);
extern int SCRCMD_NETWORK_FindNpcTableRow();
extern u16 func_0215A480(unsigned a);
extern void EVENTDATA_SYSTEM_SetNpcEventId(char *p, unsigned i, u16 v);

int SCRCMD_NETWORK_CmdSetNpcEventFromTable(int a, int b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    int y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int w = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u8 *base;
    int h;
    int r;
    r = GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((void *)b));
    base = (u8 *)SCRIPT_WORK_GetReturnFlag(x);
    h = *(u16 *)(base + (u16)SCRCMD_NETWORK_FindNpcTableRow(base, y, w) * 8 + 6);
    EVENTDATA_SYSTEM_SetNpcEventId((char *)r, z, func_0215A480(h));
    return 0;
}
