/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent
 * address: 0x02187098
 * packet: pkt_ov020_02187098
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent 0x021870C4 thumb ov020
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 */
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(void *a, void *b);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
int FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent(void *unused, void *p)
{
    void *vm;
    void *obj;
    vm = SCRCMD_WORK_GetScriptWork(p);
    obj = SCRCMD_WORK_GetGameSystem(p);
    SCRIPT_SYS_CallEvent(vm, FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(obj, GAMESYSTEM_GetFieldMap(obj)));
    return 1;
}
