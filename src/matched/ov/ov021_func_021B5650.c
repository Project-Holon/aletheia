/*
 * function: SCRCMD_PROC_FLD_SetOv056Slot
 * address:  0x021B5650
 * packet:   pkt_ov021_021B5650
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * FIELD_FK_DEMO_GetCameraSettingId is the ov056 slot-table lookup (src/matched/ov/ov056_func_021F36C8.c).
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_FK_DEMO_GetCameraSettingId  0x021F36C8  thumb  ov056
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *FIELDMAP_GetCamera(void *o);
extern u32 FIELD_FK_DEMO_GetCameraSettingId(u32 idx);
extern void FIELD_CAMERA_SetSetting(u32 *p, u32 v);

int SCRCMD_PROC_FLD_SetOv056Slot(void *a, void *b)
{
    void *w = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(b));
    unsigned int k = SCRIPT_WORK_ReadWorkValue(a, b);
    u32 *x = FIELDMAP_GetCamera(w);

    FIELD_CAMERA_SetSetting(x, FIELD_FK_DEMO_GetCameraSettingId((u16)(k - 1)));
    return 0;
}
