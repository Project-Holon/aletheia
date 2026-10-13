/*
 * function: FLDEFF_GYOE_RotateByCamera
 * address:  0x021BB7B4
 * packet:   pkt_ov021_021BB7B4
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
 */

void G3D_CAMERA_GetEye(int a, int *out);
void G3D_CAMERA_GetTarget(int a, int *out);
void G3D_CAMERA_GetUp(int a, int *out);
void func_0207BCA0(int *a, int *b, int *c, int *d);
void func_02082B60(int *a, int *b);
void func_0207B0A4(int *a, int *b);
void func_0207B51C(int a, int *b, int c);

void FLDEFF_GYOE_RotateByCamera(int a, int b, int c)
{
    int v6c[3];
    int v60[3];
    int v54[3];
    int m24[12];
    int m0[9];

    G3D_CAMERA_GetEye(a, v6c);
    G3D_CAMERA_GetTarget(a, v60);
    G3D_CAMERA_GetUp(a, v54);
    func_0207BCA0(v6c, v60, v54, m24);
    func_02082B60(m24, m0);
    func_0207B0A4(m0, m0);
    func_0207B51C(b, m0, c);
}
