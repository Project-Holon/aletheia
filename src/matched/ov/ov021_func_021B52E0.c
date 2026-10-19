/*
 * function: SCRCMD_PROC_FLD_RestoreCameraTask
 * address:  0x021B52E0
 * packet:   pkt_ov021_021B52E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   SCRCMD_PROC_FLD_RestoreCamera  0x021B52A4  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *p);
extern int SCRCMD_PROC_FLD_RestoreCamera(void *a, u32 b);

int SCRCMD_PROC_FLD_RestoreCameraTask(void **p)
{
    void *w = GAMESYSTEM_GetFieldMap(p[0]);

    SCRCMD_PROC_FLD_RestoreCamera(w, (u32)FIELDMAP_GetCamera(w));
    return 1;
}
