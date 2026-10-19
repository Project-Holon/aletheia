/*
 * function: SCRCMD_PROC_FLD_PollCameraIdle
 * address:  0x021B55F0
 * packet:   pkt_ov021_021B55F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_IsMoving  0x0218FE50  thumb  ov021
 */

typedef unsigned char u8;
typedef enum { B_FALSE, B_TRUE } Bool;

struct Ctx;

struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *o);
extern int FIELD_CAMERA_IsMoving(u8 *a);

int SCRCMD_PROC_FLD_PollCameraIdle(void *a)
{
    int x = FIELD_CAMERA_IsMoving(FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a))));

    return x != 0 ? B_FALSE : B_TRUE;
}
