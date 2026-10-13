/*
 * function: ENTRANCE_CAMERA_AimAtTarget
 * address:  0x021BE158
 * packet:   pkt_021BE158
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
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_Main  0x0218E104  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_CAMERA_Main(u8 *a, u32 b);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern int FIELD_CAMERA_ResumeTargetTrace(u32 a);
extern u32 FIELD_CAMERA_SetTarget(u32, u32);

int ENTRANCE_CAMERA_AimAtTarget(u32 a, u32 b)
{
FIELD_CAMERA_StopTargetTrace((u8 *)a);
FIELD_CAMERA_SetTarget(a, b);
FIELD_CAMERA_Main((u8 *)a, 0);
return FIELD_CAMERA_ResumeTargetTrace(a);
}

