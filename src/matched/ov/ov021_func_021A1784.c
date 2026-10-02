/*
 * function: func_021A1784
 * address:  0x021A1784
 * packet:   pkt_ov021_021A1784
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Notes: `in` is const (lets in->f4 and out->f4 loads rise above the out->f0
 * store); the 3-way max is four arms each calling FX_Div(.., 0x4000) into
 * out->fC (tail-merged). The fx32 range stores use two locals, both computed
 * before any store, with y declared before x: that keeps (fC<<12)+(w0<<12)
 * unfolded and gives the late f10 store from r2.
 *
 * symbols:
 *   FX_Div            0x0207C768  arm
 *   MTX_Identity33_   0x0207ADC4  arm
 *   MTX_RotZ33_       0x0207AF38  thumb
 *   MTX_Scale33_      0x0207AE24  thumb
 *   MTX_Concat33      0x0207B388  arm
 *   FX_SinCosTable_   0x020A1B38  data
 * Addresses are Black-image addresses.
 */

typedef signed short   s16;
typedef unsigned short u16;
typedef int            fx32;
typedef s16            fx16;

typedef struct {
    fx32 m[3][3];
} MtxFx33;

typedef struct {
    u16 w0;
    u16 w2;
    fx32 f4;
    fx32 f8;
    fx32 fC;
    fx32 f10;
    fx32 f14;
    fx32 f18;
    u16 rot;
} In021A1784;

typedef struct {
    fx32 f0;
    fx32 f4;
    fx32 f8;
    fx32 fC;
    fx32 f10;
    fx32 f14;
    fx32 f18;
    fx32 f1C;
    MtxFx33 mtx;
} Out021A1784;

typedef struct {
    fx32 f0;
    fx32 pad[4];
    fx32 f14;
} Q021A1784;

extern const s16 FX_SinCosTable_[];

fx32 FX_Div(fx32 numer, fx32 denom);
void MTX_Identity33_(MtxFx33 *pDst);
void MTX_RotZ33_(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal);
void MTX_Scale33_(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);

static inline fx16 FX_SinIdx(int idx) { return FX_SinCosTable_[idx * 2]; }
static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[idx * 2 + 1]; }




void func_021A1784(Out021A1784 *out, const In021A1784 *in, int unused, const Q021A1784 *q)
{
    MtxFx33 tmp;
    fx32 y;
    fx32 x;

    out->f4 = FX_Div(in->f4, q->f14);
    out->f0 = FX_Div(in->f4, q->f0);
    out->f8 = in->f4;
    if (out->f4 > out->f0) {
        if (out->f4 > out->f8) {
            out->fC = FX_Div(out->f4, 0x4000);
        } else {
            out->fC = FX_Div(out->f8, 0x4000);
        }
    } else if (out->f0 > out->f8) {
        out->fC = FX_Div(out->f0, 0x4000);
    } else {
        out->fC = FX_Div(out->f8, 0x4000);
    }
    out->f0 = FX_Div(out->f0, out->fC);
    out->f4 = FX_Div(out->f4, out->fC);
    out->f8 = FX_Div(out->f8, out->fC);
    x = in->fC << 12;
    y = in->f10 << 12;
    out->f10 = x;
    out->f14 = x + (in->w0 << 12);
    out->f18 = y;
    out->f1C = y + (in->w2 << 12);
    MTX_Identity33_(&out->mtx);
    MTX_RotZ33_(&out->mtx, FX_SinIdx(in->rot >> 4), FX_CosIdx(in->rot >> 4));
    MTX_Scale33_(&tmp, in->f14, in->f18, 0x1000);
    MTX_Concat33(&out->mtx, &tmp, &out->mtx);
}
