/*
 * function: SCRCMD_PROC_FLD_RestoreCameraCmd
 * address:  0x021B536C
 * packet:   pkt_ov021_021B536C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   SCRCMD_PROC_FLD_RestoreCamera  0x021B52A4  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *p);
extern int SCRCMD_PROC_FLD_RestoreCamera(void *a, u32 b);

int SCRCMD_PROC_FLD_RestoreCameraCmd(u32 a, u32 b)
{
    void *w = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));

    SCRCMD_PROC_FLD_RestoreCamera(w, (u32)FIELDMAP_GetCamera(w));
    return 0;
}
