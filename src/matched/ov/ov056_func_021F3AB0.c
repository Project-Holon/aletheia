/*
 * function: FIELD_FK_DEMO_ApplyCameraAnime
 * address:  0x021F3AB0
 * packet:   pkt_ov056_021F3AB0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_SetCameraStatus  0x02011B8C  thumb
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   G3D_CAMERA_GetTarget  0x02048B0C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_SetG3dUp  0x0218ED14  thumb  ov021
 *   gFkDemoOrigin     0x021F426C  data  a4
 */

typedef unsigned int u32;
typedef signed int   s32;

extern s32 gFkDemoOrigin[];

typedef unsigned char  u8;
extern void ICA_ANIME_SetCameraStatus(void *dst, void *ctx);
extern void G3D_CAMERA_GetEye(u32, s32 *);
extern void G3D_CAMERA_GetTarget(u32, s32 *);
extern void G3D_CAMERA_GetUp(u32, s32 *);
extern void func_0207C9D0(s32 *a, s32 *b, s32 *c);
extern void FIELD_CAMERA_SetEyeRaw(u32 a, s32 *b);
extern void FIELD_CAMERA_SetTarget(u32 a, s32 *b);
extern void FIELD_CAMERA_SetG3dUp(u8 *p, u32 q);

void FIELD_FK_DEMO_ApplyCameraAnime(u32 *p)
{
    s32 v2[3];
    s32 v1[3];
    s32 v3[3];

    ICA_ANIME_SetCameraStatus((void *)p[1], (void *)p[0]);
    G3D_CAMERA_GetEye(p[1], v1);
    G3D_CAMERA_GetUp(p[1], v2);
    G3D_CAMERA_GetTarget(p[1], v3);
    func_0207C9D0(v1, gFkDemoOrigin, v1);
    func_0207C9D0(v2, gFkDemoOrigin, v2);
    FIELD_CAMERA_SetEyeRaw(p[2], v1);
    FIELD_CAMERA_SetTarget(p[2], v2);
    FIELD_CAMERA_SetG3dUp((u8 *)p[2], (u32)v3);
}
