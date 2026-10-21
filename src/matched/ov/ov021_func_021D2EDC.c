/*
 * function: SCRCMD_StartSwapNpcEvent
 * address:  0x021D2EDC
 * packet:   pkt_ov021_021D2EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SP_POKE_GIMMICK_StartSwapNpc  0x021F3CFC  thumb  ov059
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetMmdlSys(void *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void *SP_POKE_GIMMICK_StartSwapNpc(void *a, int *v, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

u32 SCRCMD_StartSwapNpcEvent(u32 a, u32 b)
{
    int v[3];
    void *r7;
    void *s0;
    u32 r6;
    u32 r5;
    void *r;

    r7 = SCRCMD_WORK_GetScriptWork((void *)b);
    s0 = SCRCMD_WORK_GetGameSystem((void *)b);
    GAMESYSTEM_GetFieldMap(s0);
    r6 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    FLDMMDL_GetPos((const struct Actor *)FLDMMDL_SysSearchObjId(SCRCMD_WORK_GetMmdlSys((void *)b), r6), (struct VecFx32 *)v);
    r = SP_POKE_GIMMICK_StartSwapNpc(s0, v, r6, r5);
    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(r7, r);
    return 1;
}
