/*
 * function: SCRCMD_FLDMMDL_PauseMmdls
 * address:  0x021B1BB8
 * packet:   pkt_ov021_021B1BB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_GetTargetObj  0x02158F90  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   SCRCMD_FLDMMDL_PauseMmdlsReleaseActive  0x021B1B08  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetTargetObj(void *);
extern void *SCRCMD_WORK_GetOccupyInfo(void *);
extern void FLDMMDL_SysPauseMove(void *map);
extern int SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(int a, void *b);

int SCRCMD_FLDMMDL_PauseMmdls(int a, void *b)
{
    if (SCRIPT_WORK_GetTargetObj(SCRCMD_WORK_GetScriptWork(b)) == 0) {
        FLDMMDL_SysPauseMove(SCRCMD_WORK_GetOccupyInfo(b));
    } else {
        return SCRCMD_FLDMMDL_PauseMmdlsReleaseActive(a, b);
    }
    return 0;
}
