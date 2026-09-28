/*
 * function: func_0207BCA0
 * address:  0x0207BCA0
 * packet:   pkt_0207BCA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_LookAt (libfx.TWL.HYB.a fx_mtx43.o)
 *
 * symbols:
 *   VEC_Normalize      0x0207CCA4  arm
 *   VEC_CrossProduct   0x0207CAE8  arm
 *   VEC_DotProduct     0x0207CA68  arm
 */

typedef long fx32;
typedef long long fx64;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;


extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);

void func_0207BCA0(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx)
{
    VecFx32 vLook, vRight, vUp;

    vLook.x = camPos->x - target->x;
    vLook.y = camPos->y - target->y;
    vLook.z = camPos->z - target->z;
    VEC_Normalize(&vLook, &vLook);
    VEC_CrossProduct(camUp, &vLook, &vRight);
    VEC_Normalize(&vRight, &vRight);
    VEC_CrossProduct(&vLook, &vRight, &vUp);

    mtx->_00 = vRight.x;
    mtx->_01 = vUp.x;
    mtx->_02 = vLook.x;
    mtx->_10 = vRight.y;
    mtx->_11 = vUp.y;
    mtx->_12 = vLook.y;
    mtx->_20 = vRight.z;
    mtx->_21 = vUp.z;
    mtx->_22 = vLook.z;
    mtx->_30 = -VEC_DotProduct(camPos, &vRight);
    mtx->_31 = -VEC_DotProduct(camPos, &vUp);
    mtx->_32 = -VEC_DotProduct(camPos, &vLook);
}
