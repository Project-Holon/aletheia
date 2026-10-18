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
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   MTX_LookAt  0x0207BCA0  arm
 *   MI_Copy36B  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   MTX_MultVec33  0x0207B51C  arm
 */

void G3D_CAMERA_GetEye(int a, int *out);
void G3D_CAMERA_GetCamUp(int a, int *out);
void G3D_CAMERA_GetCamTarget(int a, int *out);
void MTX_LookAt(int *a, int *b, int *c, int *d);
void MI_Copy36B(int *a, int *b);
void func_0207B0A4(int *a, int *b);
void MTX_MultVec33(int a, int *b, int c);

void FLDEFF_GYOE_RotateByCamera(int a, int b, int c)
{
    int v6c[3];
    int v60[3];
    int v54[3];
    int m24[12];
    int m0[9];

    G3D_CAMERA_GetEye(a, v6c);
    G3D_CAMERA_GetCamUp(a, v60);
    G3D_CAMERA_GetCamTarget(a, v54);
    MTX_LookAt(v6c, v60, v54, m24);
    MI_Copy36B(m24, m0);
    func_0207B0A4(m0, m0);
    MTX_MultVec33(b, m0, c);
}
