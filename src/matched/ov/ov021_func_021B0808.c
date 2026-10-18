/*
 * function: SCRCMD_MSGWIN_CalcBalloonOffset
 * address:  0x021B0808
 * packet:   pkt_ov021_021B0808
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The quotient is written back into z (the address-taken output local)
 * rather than a fresh q: with a separate local the divisor 12 and the
 * table stride 12 pool into r6 across the _u32_div_f call.
 *
 * symbols:
 *   SCRCMD_MSGWIN_CalcBalloonOffset  0x021B0808  thumb
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   sBalloonUpVec     0x021D9390  data
 *   sBalloonOffsetTable     0x021D939C  data
 */

typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 x, y, z; } VecFx32;

struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_CAMERA_GetCamTarget(void *cam, VecFx32 *out);
extern void G3D_CAMERA_GetEye(void *cam, VecFx32 *out);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *out);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void NNS_G3dWorldPosToScrPos(VecFx32 *pos, u32 *x, u32 *z);

extern const VecFx32 sBalloonUpVec;
extern const VecFx32 sBalloonOffsetTable[2][4];

void SCRCMD_MSGWIN_CalcBalloonOffset(const VecFx32 *src, VecFx32 *out, void *cam)
{
    VecFx32 pos;
    VecFx32 c;
    VecFx32 d;
    VecFx32 e;
    VecFx32 f;
    VecFx32 b;
    VecFx32 a;
    u32 x;
    u32 z;
    u32 t;
    u32 r;

    pos = *src;
    G3D_CAMERA_Reset(cam);
    G3D_CAMERA_GetCamTarget(cam, &a);
    G3D_CAMERA_GetEye(cam, &b);
    VEC_Subtract(&a, &b, &c);
    d = c;
    d.y = r = 0;
    VEC_Normalize(&d, &d);
    VEC_CrossProduct(&d, &sBalloonUpVec, &e);
    VEC_CrossProduct(&c, &e, &f);
    VEC_Normalize(&f, &f);
    pos.x += f.x;
    pos.y += f.y;
    pos.z += f.z;
    NNS_G3dWorldPosToScrPos(&pos, &x, &z);
    t = x >> 3;
    if (t < 10) {
        r = 0;
    } else if (t >= 10 && t <= 15) {
        r = 1;
    } else if (t >= 16 && t < 22) {
        r = 2;
    } else {
        r = 3;
    }
    z = (z >> 3) / 12;
    if (r < 4 && z < 2) {
        *out = sBalloonOffsetTable[z][r];
    } else {
        VecFx32 zero = {0, 0, 0};
        *out = zero;
    }
}
