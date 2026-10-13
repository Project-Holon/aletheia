/*
 * function: FLD_WIPE_3DOBJ_Draw
 * address:  0x021C8078
 * packet:   pkt_ov021_021C8078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetLookAt  0x02046AFC  arm
 *   func_0207CA00  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   _ll_mul        0x0209C054  arm
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   func_02082B60  0x02082B60  arm
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_GetRenderObj  0x0204755C  arm
 *   NNS_G3dMdlSetMdlLightEnableFlag  0x0206E394  arm
 *   NNS_G3dMdlSetMdlPolygonID  0x0206E4FC  arm
 *   NNS_G3dMdlSetMdlCullMode  0x0206E484  arm
 *   NNS_G3dMdlSetMdlAlpha  0x0206E574  arm
 *   NNS_G3dMdlSetMdlPolygonMode  0x0206E40C  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 * Addresses are Black-image addresses.
 */

typedef struct { int x, y, z; } V;
typedef struct { int m[9]; } M;
typedef struct { int m[12]; } M43;
typedef struct { V pos, tgt, up; } Cam;
typedef struct { V t; V s; M r; } SRT;
typedef struct { int f0; void *f4; } Q;
typedef struct { int f0; void *f4; } Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Arg;
extern void G3D_SYSTEM_GetLookAt(u8 *dst);
extern void func_0207CA00(V *, V *, V *);
extern void VEC_Normalize(V *, V *);
extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern void func_02082B60(M43 *, M *);
extern int G3D_SYSTEM_GetObjectRender(int *p);
extern Q *G3D_SYSTEM_GetRenderObj(void *);
extern void NNS_G3dMdlSetMdlLightEnableFlag(void *, int, int);
extern void NNS_G3dMdlSetMdlPolygonID(void *, int, int);
extern void NNS_G3dMdlSetMdlCullMode(void *, int, int);
extern void NNS_G3dMdlSetMdlAlpha(void *, int, int);
extern void NNS_G3dMdlSetMdlPolygonMode(void *, int, int);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

void FLD_WIPE_3DOBJ_Draw(Obj *p, int b, int c)
{
    SRT srt;
    Cam cam;
    V v;
    int y;
    void *q;

    if (b == 0) {
        return;
    }
    G3D_SYSTEM_GetLookAt((u8 *)(&cam));
    srt.t = cam.pos;
    func_0207CA00(&cam.up, &cam.pos, &v);
    VEC_Normalize(&v, &v);
    y = v.y;
    if (y <= 0) {
        y = -y;
    }
    srt.s.x = b;
    srt.s.y = (int)(((long long)b * y + 0x800) >> 12);
    srt.s.z = 0x4000;
    func_02082B60((M43 *)NNS_G3dGlbGetInvCameraMtx(), &srt.r);
    q = G3D_SYSTEM_GetRenderObj((void *)G3D_SYSTEM_GetObjectRender(p->f4))->f4;
    NNS_G3dMdlSetMdlLightEnableFlag(q, 0, 0);
    NNS_G3dMdlSetMdlPolygonID(q, 0, 0);
    NNS_G3dMdlSetMdlCullMode(q, 0, 2);
    NNS_G3dMdlSetMdlAlpha(q, 0, c);
    NNS_G3dMdlSetMdlPolygonMode(q, 0, 0);
    G3D_SYSTEM_DrawObject(p->f4, (struct Arg *)(&srt));
}
