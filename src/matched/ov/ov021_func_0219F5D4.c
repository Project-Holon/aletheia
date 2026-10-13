/*
 * function: FLDMMDL_DRAW_RotateByCamera
 * address:  0x0219F5D4
 * packet:   pkt_ov021_0219F5D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetTarget  0x02048B0C  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef signed int   s32;
extern void G3D_CAMERA_GetEye(u32, s32 *);
extern void G3D_CAMERA_GetTarget(u32, s32 *);
extern void G3D_CAMERA_GetUp(u32, s32 *);
extern void func_0207BCA0(s32 *, s32 *, s32 *, s32 *);
extern void func_02082B60(s32 *, s32 *);
extern void func_0207B0A4(s32 *, s32 *);
extern void func_0207B51C(s32 *, s32 *, s32 *);

void FLDMMDL_DRAW_RotateByCamera(u32 a, s32 *b, s32 *c)
{
    s32 v1[3];
    s32 v2[3];
    s32 v3[3];
    s32 m4[12];
    s32 m3[9];
    G3D_CAMERA_GetEye(a, v1);
    G3D_CAMERA_GetTarget(a, v2);
    G3D_CAMERA_GetUp(a, v3);
    func_0207BCA0(v1, v2, v3, m4);
    func_02082B60(m4, m3);
    func_0207B0A4(m3, m3);
    func_0207B51C(b, m3, c);
}
