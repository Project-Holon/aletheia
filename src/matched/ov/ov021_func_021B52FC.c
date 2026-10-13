/*
 * function: SCRCMD_PROC_FLD_BeginFieldRegionRelease
 * address:  0x021B52FC
 * packet:   pkt_ov021_021B52FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_PushState  0x0218F818  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   SCRCMD_PROC_FLD_PollFieldRegionStart  0x021B55C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct Desc;
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRIPT_WORK_SetCheckFlag(int n);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *FIELDMAP_GetCamera(void *a);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_CAMERA_HasDelay(u8 *a);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern void FIELD_CAMERA_PushState(u8 *a);
extern void FIELD_NOGRID_MAPPER_SetActive(u32 a, u32 b);
extern int SCRCMD_PROC_FLD_PollFieldRegionStart(void *a);

int SCRCMD_PROC_FLD_BeginFieldRegionRelease(u32 a, u32 b)
{
    void *r6;
    void *r4;
    void *r5;

    r6 = SCRCMD_WORK_GetGameSystem((void *)b);
    r4 = GAMESYSTEM_GetFieldMap((void *)r6);
    r5 = FIELDMAP_GetCamera(r4);
    SCRIPT_WORK_SetCheckFlag(0);
    if (FIELD_CAMERA_HasDelay(r5) != 0) {
        FIELD_CAMERA_EndDelay(r5);
        r5 = SCRCMD_WORK_GetScriptWork((void *)b);
        SCRIPT_SYS_CallEvent(r5, func_020122C0(r6, 0, (void *)SCRCMD_PROC_FLD_PollFieldRegionStart, 0));
        if (FIELDMAP_GetMoveKind(r4) == 1) {
            FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(r4), 0);
        }
    } else {
        FIELD_CAMERA_PushState(r5);
    }
    return 1;
}
