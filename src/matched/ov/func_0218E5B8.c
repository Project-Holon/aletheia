/*
 * function: FIELD_CAMERA_UpdateEyeMode
 * address:  0x0218E5B8
 * packet:   pkt_0218E5B8
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
 *   FIELD_CAMERA_PullEyeFromTrace  0x0218E298  thumb  ov021
 *   FIELD_CAMERA_SolveEyeMode  0x0218E404  thumb  ov021
 *   FIELD_CAMERA_ApplyToG3d  0x0218E540  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_CAMERA_PullEyeFromTrace(u8 *a);
extern void FIELD_CAMERA_SolveEyeMode(u8 *a);
extern u32 FIELD_CAMERA_ApplyToG3d(u32);

int FIELD_CAMERA_UpdateEyeMode(u32 a, u32 b, u32 c, u32 d)
{
FIELD_CAMERA_PullEyeFromTrace((u8 *)a);
FIELD_CAMERA_SolveEyeMode((u8 *)a);
return FIELD_CAMERA_ApplyToG3d(a);
}

