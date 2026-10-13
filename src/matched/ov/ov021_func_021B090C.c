/*
 * function: SCRCMD_MSGWIN_RotateOffsetByCamera
 * address:  0x021B090C
 * packet:   pkt_ov021_021B090C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetTarget  0x02048B0C  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 */

typedef struct { int x, y, z; } V;
typedef struct { int m[9]; } M;
typedef struct { int m[12]; } M43;

extern void G3D_CAMERA_GetEye(int, V *);
extern void G3D_CAMERA_GetTarget(int, V *);
extern void G3D_CAMERA_GetUp(int, V *);
extern void func_0207BCA0(V *, V *, V *, M43 *);
extern void func_02082B60(M43 *, M *);
extern void func_0207B0A4(M *, M *);
extern void func_0207B51C(M *, M *, M *);

void SCRCMD_MSGWIN_RotateOffsetByCamera(M *a, int b)
{
    V v1, v2, v3;
    M43 m1;
    M m2;

    G3D_CAMERA_GetEye(b, &v1);
    G3D_CAMERA_GetTarget(b, &v2);
    G3D_CAMERA_GetUp(b, &v3);
    func_0207BCA0(&v1, &v2, &v3, &m1);
    func_02082B60(&m1, &m2);
    func_0207B0A4(&m2, &m2);
    func_0207B51C(a, &m2, a);
}
