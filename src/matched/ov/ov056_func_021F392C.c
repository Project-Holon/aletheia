/*
 * function: FIELD_FK_DEMO_InitCamera
 * address:  0x021F392C
 * packet:   pkt_ov056_021F392C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Camera setup; the G3D_CAMERA_Create call is spelled as in ov111_func_021C7744
 * (the pool word 0x020A1EB8 is FX_SinCosTable_ + 0x380, the load reach of
 * elements 0x1C6/0x1C7). The zeroed vector handed to FIELD_CAMERA_SetTargetShift is a
 * byte buffer viewed through a VecFx32 pointer: the image keeps its address
 * in r4 and stores through it. A declared VecFx32 (field stores, a
 * VEC_Set-style inline, a pointer local, or a {0,0,0} initialiser) folds the
 * stores to sp (a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md).
 * FIELD_CAMERA_GetG3dUp is an unlabelled ov021 leaf filed alongside this function.
 *
 * symbols:
 *   ICA_ANIME_CreateStream  0x02011510  thumb
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   FIELD_CAMERA_GetG3dUp  0x0218ED20  thumb  ov021
 *   FIELD_FK_DEMO_ApplyCameraAnime  0x021F3AB0  thumb  ov056
 *   gFkDemoCameraUp     0x021F4338  data  a4
 *   gFkDemoCameraSettingId     0x021F42B0  data  a4
 *   FX_SinCosTable_  0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct Obj {
    void *f0;
    void *cam;
    int f8;
    u16 hc;
    u16 he;
    VecFx32 f10;
    VecFx32 f1c;
    int f28;
    u32 f2c;
} Obj;

extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void G3D_CAMERA_GetUp(u32 cam, VecFx32 *out);
extern void G3D_CAMERA_GetEye(u32 cam, VecFx32 *out);
extern void *G3D_CAMERA_Create(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern u8 FIELD_CAMERA_GetAreasEnabled(u8 *p);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_GetTargetShift(int a, VecFx32 *v);
extern void FIELD_CAMERA_SetTargetShift(int a, VecFx32 *v);
extern void FIELD_CAMERA_GetG3dUp(void *p, void *out);
extern void FIELD_FK_DEMO_ApplyCameraAnime(u32 *p);

extern const VecFx32 gFkDemoCameraUp;
extern const u32 gFkDemoCameraSettingId[];
extern const s16 FX_SinCosTable_[];

void FIELD_FK_DEMO_InitCamera(Obj *o, int a1, int heap, int idx)
{
    VecFx32 tgt;
    VecFx32 pos;
    u8 zero[12];
    VecFx32 up;
    u32 cam;
    VecFx32 *pz;

    o->f28 = 0;
    o->f0 = ICA_ANIME_CreateStream(heap, 0x96, idx + 0x18, 10);
    cam = FIELD_CAMERA_GetG3dCamera((u8 *)a1);
    G3D_CAMERA_GetUp(cam, &tgt);
    G3D_CAMERA_GetEye(cam, &pos);
    up = gFkDemoCameraUp;
    o->cam = G3D_CAMERA_Create(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &pos, &up, &tgt, heap);
    o->f8 = a1;
    o->hc = FIELD_CAMERA_GetMode((u8 *)a1);
    FIELD_CAMERA_SetMode((u8 *)o->f8, 2);
    o->he = FIELD_CAMERA_GetAreasEnabled((u8 *)o->f8);
    FIELD_CAMERA_SetAreasEnabled((u8 *)o->f8, 0);
    FIELD_CAMERA_StopTargetTrace((u8 *)o->f8);
    pz = (VecFx32 *)zero;
    pz->x = 0;
    pz->y = 0;
    pz->z = 0;
    FIELD_CAMERA_GetTargetShift(o->f8, &o->f10);
    FIELD_CAMERA_SetTargetShift(o->f8, pz);
    FIELD_CAMERA_GetG3dUp((void *)o->f8, &o->f1c);
    FIELD_FK_DEMO_ApplyCameraAnime((u32 *)o);
    o->f2c = gFkDemoCameraSettingId[idx];
}
