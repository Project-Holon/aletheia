/*
 * function: SCRCMD_PROC_FLD_PollFieldRegionStart
 * address:  0x021B55C8
 * packet:   pkt_ov021_021B55C8
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
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;

struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *o);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void FIELD_CAMERA_PushState(u8 *a);

int SCRCMD_PROC_FLD_PollFieldRegionStart(void *a)
{
    u8 *x = FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a)));

    if (FIELD_CAMERA_IsDelayEnabled(x) == 0) {
        FIELD_CAMERA_PushState(x);
        return 1;
    }
    return 0;
}
