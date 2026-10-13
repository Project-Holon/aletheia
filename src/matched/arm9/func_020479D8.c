/*
 * function: G3D_SYSTEM_ApplyLookAt
 * address:  0x020479D8
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem     0x02146A5C  data
 *   NNS_G3dGlb     0x02148B4C  data
 *   MTX_LookAt     0x0207BCA0  arm
 *
 * g3d_system.c.  Re-apply the context's camera (position, up and target at
 * +0x5C/+0x68/+0x74) through NitroSystem's NNS_G3dGlbLookAt inline, then run
 * the context's +0x88 callback.
 *
 * The lever (wave 15) is the library shape: the three destination blocks
 * 0x02148D8C/0x02148D98/0x02148DA4, the camera matrix 0x02148B98 and the flag
 * word 0x02148B4C+0xFC are all fields of ONE object, NNS_G3dGlb (camPos,
 * camUp, camTarget at +0x240/+0x24C/+0x258, cameraMtx at +0x4C, flag at
 * +0xFC), and the copies plus MTX_LookAt plus the flag clear are the
 * NitroSystem inline NNS_G3dGlbLookAt(const VecFx32 *, const VecFx32 *,
 * const VecFx32 *) (glbstate_inline.h, NitroSystem-071126).  The inline's
 * three pointer parameters are what keep the three addresses in lr/ip/r5
 * for the call; every hand spelling with separate externs came out one
 * callee-saved register wider (22 to 31 bytes out,
 * docs/notes/pkt_020479D8.c.txt).  0xE8 is INVCAMERA | INVBASECAMERA |
 * INVCAMERAPROJ | BASECAMERA.  The layout below reproduces the NitroSystem
 * struct up to camTarget; the offsets are fixed by the image's pool words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_ApplyLookAt.c \
 *       --func G3D_SYSTEM_ApplyLookAt --addr 0x020479D8 --arm
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[4][3]; } MtxFx43;
typedef struct { fx32 m[4][4]; } MtxFx44;
typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct {
    u32 cmd0;
    u32 mtxmode_proj;
    MtxFx44 projMtx;
    u32 mtxmode_posvec;
    MtxFx43 cameraMtx;
    u32 cmd1;
    u32 lightVec[4];
    u32 cmd2;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmViewPort;
    u32 cmd3;
    u32 lightColor[4];
    u32 cmd4;
    MtxFx33 prmBaseRot;
    VecFx32 prmBaseTrans;
    VecFx32 prmBaseScale;
    u32 prmTexImageParam;
    u32 flag;
    MtxFx43 invCameraMtx;
    MtxFx43 srtCameraMtx;
    MtxFx43 invSrtCameraMtx;
    MtxFx43 invBaseMtx;
    MtxFx44 invProjMtx;
    MtxFx44 invCameraProjMtx;
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
} NNSG3dGlb;

extern NNSG3dGlb NNS_G3dGlb;

extern void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                       const VecFx32 *target, MtxFx43 *mtx);

static inline void NNS_G3dGlbLookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                                    const VecFx32 *target)
{
    NNS_G3dGlb.camPos = *camPos;
    NNS_G3dGlb.camUp = *camUp;
    NNS_G3dGlb.camTarget = *target;
    MTX_LookAt(camPos, camUp, target, &NNS_G3dGlb.cameraMtx);
    NNS_G3dGlb.flag &= ~(0x08 | 0x80 | 0x20 | 0x40);
}

struct G3dCtx {
    u8   pad_00[0x5C];
    VecFx32 view0;
    VecFx32 view1;
    VecFx32 view2;
    u8   pad_80[0x08];
    void (*f88)(void);
};

extern struct G3dCtx *_G3dSystem;

void G3D_SYSTEM_ApplyLookAt(void)
{
    NNS_G3dGlbLookAt(&_G3dSystem->view0, &_G3dSystem->view1, &_G3dSystem->view2);
    _G3dSystem->f88();
}
