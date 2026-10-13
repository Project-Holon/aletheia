/*
 * function: FIELD_CAMERA_ANIME_ReadParam
 * address:  0x021900C4
 * packet:   pkt_ov021_021900C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_GetEye  0x0218F19C  thumb  ov021
 *   FIELD_CAMERA_GetTarget  0x0218F18C  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   FIELD_CAMERA_GetVectorAngles  0x0218ED5C  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_CAMERA_GetEye(u32 a, void *b);
extern void FIELD_CAMERA_GetTarget(u32 a, void *b);
extern void func_0207CA00(void *a, void *b, void *c);
extern int FIELD_CAMERA_GetVectorAngles(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_CAMERA_GetTargetShift(u32 a, void *b);

void FIELD_CAMERA_ANIME_ReadParam(u32 a, u8 *b)
{
    u8 v1[12];
    u8 v0[12];
    u8 v2[12];

    FIELD_CAMERA_GetEye(a, v0);
    FIELD_CAMERA_GetTarget(a, v1);
    func_0207CA00(v0, v1, v2);
    FIELD_CAMERA_GetVectorAngles((u32)v2, (u32)b, (u32)(b + 2), (u32)(b + 4));
    FIELD_CAMERA_GetTarget(a, b + 8);
    FIELD_CAMERA_GetTargetShift(a, b + 0x14);
}
