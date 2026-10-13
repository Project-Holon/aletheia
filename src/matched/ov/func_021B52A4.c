/*
 * function: SCRCMD_PROC_FLD_ReleaseFieldRegion
 * address:  0x021B52A4
 * packet:   pkt_021B52A4
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
 *   FIELD_CAMERA_PopState  0x0218F878  thumb  ov021
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRIPT_WORK_ResetCheckFlag(u32);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);
extern int FIELD_CAMERA_HasDelay(u8 *a);
extern void FIELD_CAMERA_PopState(u8 *a);
extern u32 FIELD_NOGRID_MAPPER_SetActive(u32, u32);

int SCRCMD_PROC_FLD_ReleaseFieldRegion(void *a, u32 b)
{
FIELD_CAMERA_PopState((u8 *)b);
if (FIELD_CAMERA_HasDelay((u8 *)b) != 0) {
    FIELD_CAMERA_RestartDelay((unsigned char *)b);
}
if (FIELDMAP_GetMoveKind((u8 *)a) == 1) {
    FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper((u8 *)a), 1);
}
return SCRIPT_WORK_ResetCheckFlag(0);
}

