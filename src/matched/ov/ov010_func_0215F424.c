/*
 * function: SCRCMD_NETWORK_CmdSetNpcTripleFromTable
 * address:  0x0215F424
 * packet:   pkt_ov010_0215F424
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_GetReturnFlag  0x0215911C  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcObjCode  0x02162774  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcEventId  0x02162788  thumb  ov010
 *   EVENT_TRAINER_GetPrimaryScriptId  0x0215A480  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 f00;
    u16 f04;
    u16 f06;
} Entry;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u32 SCRIPT_WORK_GetReturnFlag(void *p);
extern void EVENTDATA_SYSTEM_SetNpcObjCode(char *p, unsigned i, u16 v);
extern void EVENTDATA_SYSTEM_SetNpcEventId(char *p, unsigned i, u16 v);
struct BigObj;
extern u16 EVENT_TRAINER_GetPrimaryScriptId(unsigned a);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);

int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(int a0, int a1)
{
    void *w = SCRCMD_WORK_GetScriptWork((void *)a1);
    int s0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int s1 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int s2 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int i0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int i1 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int i2 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int obj = GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData((void *)a1));
    Entry *t = (Entry *)SCRIPT_WORK_GetReturnFlag(w);
    EVENTDATA_SYSTEM_SetNpcObjCode((char *)obj, s0, t[i0].f04);
    EVENTDATA_SYSTEM_SetNpcObjCode((char *)obj, s1, t[i1].f04);
    EVENTDATA_SYSTEM_SetNpcObjCode((char *)obj, s2, t[i2].f04);
    EVENTDATA_SYSTEM_SetNpcEventId((char *)obj, s0, EVENT_TRAINER_GetPrimaryScriptId(t[i0].f06));
    EVENTDATA_SYSTEM_SetNpcEventId((char *)obj, s1, EVENT_TRAINER_GetPrimaryScriptId(t[i1].f06));
    EVENTDATA_SYSTEM_SetNpcEventId((char *)obj, s2, EVENT_TRAINER_GetPrimaryScriptId(t[i2].f06));
    return 0;
}
