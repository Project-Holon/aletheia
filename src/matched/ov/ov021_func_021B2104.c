/*
 * function: SCRCMD_FLDMMDL_StartMmdlRailSlipDown
 * address:  0x021B2104
 * packet:   pkt_ov021_021B2104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   RAIL_SLIPDOWN_Start  0x021C474C  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *RAIL_SLIPDOWN_Start(void *a, u32 b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_FLDMMDL_StartMmdlRailSlipDown(u32 a, u32 b)
{
    void *t;
    u32 v;
    u32 m;
    u32 o;
    void *w;

    w = SCRCMD_WORK_GetGameSystem((void *)b);
    t = SCRCMD_WORK_GetScriptWork((void *)b);
    m = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    o = (u32)FLDMMDL_SysSearchObjId((void *)m, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
    v = (u32)RAIL_SLIPDOWN_Start(w, ((u32 *)SCRIPT_WORK_ResetFieldParam((int)t))[1], o);
    SCRIPT_SYS_CallEvent(t, (void *)v);
    return 1;
}
