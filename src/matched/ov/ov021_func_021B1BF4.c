/*
 * function: SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer
 * address:  0x021B1BF4
 * packet:   pkt_ov021_021B1BF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   SCRCMD_FLDMMDL_GetPlayerMmdl  0x021B1E74  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned short u16;
extern int SCRCMD_FLDMMDL_GetPlayerMmdl(u32 a);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);
extern void *SCRIPT_WORK_GetTargetObj(void *p);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);

int SCRCMD_FLDMMDL_TurnTargetMmdlToPlayer(u32 a, u32 b)
{
    void *s = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 v = FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirDisp((void *)SCRCMD_FLDMMDL_GetPlayerMmdl(b)));
    u32 o = (u32)SCRIPT_WORK_GetTargetObj(s);

    if (o != 0) {
        FLDMMDL_SetDirDispCheckPause(o, v);
        FLDMMDL_SetDrawStatus((void *)o, 0);
    }
    return 0;
}
