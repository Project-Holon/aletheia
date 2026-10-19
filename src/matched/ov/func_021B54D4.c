/*
 * function: SCRCMD_PROC_FLD_StartCameraMoveToSetting
 * address:  0x021B54D4
 * packet:   pkt_021B54D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   VM_GetU16  0x02011330  thumb
 *   FIELD_CAMERA_StartMoveToSetting  0x0218FA40  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *FIELDMAP_GetCamera(void *p);
extern void FIELD_CAMERA_StartMoveToSetting(u8 *p, u16 v);

int SCRCMD_PROC_FLD_StartCameraMoveToSetting(u32 a, u32 b, u32 c, u32 d)
{
FIELD_CAMERA_StartMoveToSetting(FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))), VM_GetU16((struct Stream *)a));
return 0;
}

