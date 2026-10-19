/*
 * function: SCRCMD_PROC_FLD_StartCameraMoveToSaved
 * address:  0x021B5498
 * packet:   pkt_ov021_021B5498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_StartMoveToSaved  0x0218F9C4  thumb  ov021
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void FIELD_CAMERA_StartMoveToSaved(void *, u32 *, u32);

int SCRCMD_PROC_FLD_StartCameraMoveToSaved(u32 a, u32 b)
{
    u32 v[6];
    void *x = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
    u32 k = VM_GetU16((struct Stream *)a);

    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 1;
    v[5] = 1;
    FIELD_CAMERA_StartMoveToSaved(x, v, k);
    return 0;
}
