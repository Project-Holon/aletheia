/*
 * function: FIELD_CAMERA_ANIME_SetAnglesFromPos
 * address:  0x02190058
 * packet:   pkt_ov021_02190058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetEye  0x0218F19C  thumb  ov021
 *   FIELD_CAMERA_GetTarget  0x0218F18C  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   FIELD_CAMERA_GetVectorAngles  0x0218ED5C  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[3]; } B12;

extern void FIELD_CAMERA_GetEye(u8 *o, B12 *v);
extern void FIELD_CAMERA_GetTarget(u8 *o, B12 *v);
extern void VEC_Subtract(B12 *a, B12 *b, B12 *c);
extern int FIELD_CAMERA_GetVectorAngles(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_CAMERA_SetDistance(u8 *o, u32 v);
extern void FIELD_CAMERA_SetPitch(u8 *o, u16 v);
extern void FIELD_CAMERA_SetYaw(u8 *p, u32 v);

void FIELD_CAMERA_ANIME_SetAnglesFromPos(u8 *o)
{
    B12 v2, v1, v;
    u32 c;
    u16 b, a;
    FIELD_CAMERA_GetEye(o, &v1);
    FIELD_CAMERA_GetTarget(o, &v2);
    VEC_Subtract(&v1, &v2, &v);
    FIELD_CAMERA_GetVectorAngles((u32)(&v), (u32)(&b), (u32)(&a), (u32)(&c));
    FIELD_CAMERA_SetDistance(o, c);
    FIELD_CAMERA_SetPitch(o, b);
    FIELD_CAMERA_SetYaw(o, a);
}
