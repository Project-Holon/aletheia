/*
 * function: GIMMICK43_SnapElevatorToTop
 * address:  0x021F42A8
 * packet:   pkt_021F42A8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb
 */
#include "../include/Obj20511.h"
#include "../include/Obj20512.h"

typedef unsigned char u8;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetExpObj(void *a);
extern void *FIELDMAP_GetCommonWork(void *a, int b);
extern void *FIELDMAP_GetCamera(void *a);
extern int   FIELD_CAMERA_GetTraceTarget(void *a);
extern void  FIELD_CAMERA_StopTargetTrace(void *a);
extern void *FLD_EXP_OBJ_GetModelStatus(void *a, int b, int c);
extern void *FIELDMAP_GetFieldPlayer(void *a);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void  FIELD_PLAYER_SetPos(void *a, void *b);

void GIMMICK43_SnapElevatorToTop(void *p)
{
    void *a, *b, *c, *d, *e, *f;
    int tmp[3];

    a = GAMESYSTEM_GetFieldMap(p);
    b = FIELDMAP_GetExpObj(a);
    c = FIELDMAP_GetCommonWork(a, 1);
    d = FIELDMAP_GetCamera(a);
    ((struct Obj20511 *)c)->f10 = FIELD_CAMERA_GetTraceTarget(d);
    FIELD_CAMERA_StopTargetTrace(d);
    e = FLD_EXP_OBJ_GetModelStatus(b, 0, 7);
    ((struct Obj20512 *)e)->f4 = 0x370000;
    f = FIELDMAP_GetFieldPlayer(a);
    FIELD_PLAYER_GetPos(f, (struct VecFx32 *)tmp);
    tmp[1] = 0x370000;
    FIELD_PLAYER_SetPos(f, tmp);
}
