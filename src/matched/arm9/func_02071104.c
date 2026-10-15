/*
 * function: NNSi_G3dTexMtxScaleTrans
 * address:  0x02071104
 * packet:   pkt_02071104
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d, the texture-SRT matrix builder for a material with scale
 * and translation but no rotation: fills the scale diagonal and the two
 * translation terms of a 4x4 fx32 matrix from a material animation result.
 * Same family as NNSi_G3dTexMtxTrans / NNSi_G3dTexMtxScaleRot4x4 / NNSi_G3dTexMtxRot4x4 /
 * NNSi_G3dTexMtxIdentity, which carry the same ../2.0/sp2 pin (docs/FRONTEND-PINS.md).
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 6.  The lever is the _31
 * term's aspect factor written as two subtractions of the same field,
 * `-scaleT - scaleT + 0x1000 * 2`, rather than `-(scaleT << 1)` or a
 * multiply by 2; with it scaleT lands in r4 and transT in ip as in the
 * image.  Every spelling in docs/notes/pkt_02071104.c.txt used a shift or a
 * multiply and tied at 6.
 *
 * Pin evidence: under the default dsi/1.1p1 this exact source is 116 bytes
 * against the image's 124 (SIZE, 103 concrete out); ../2.0/sp2, sp2p2 and
 * sp1 are all 124 bytes, 0 out; ../1.2/sp2 is 128 bytes.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dTexMtxScaleTrans.c \
 *       --func NNSi_G3dTexMtxScaleTrans --addr 0x02071104 --arm --cc ../2.0/sp2
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          fx16;
typedef int            fx32;
typedef long long      fx64;

struct MatAnm {
    u32  flag;
    u32  matColor0;
    u32  matColor1;
    u32  polygonAttr;
    u32  texImage;
    u32  texPltt;
    fx32 scaleS;
    fx32 scaleT;
    fx16 sinR;
    fx16 cosR;
    fx32 transS;
    fx32 transT;
    u16  origWidth;
    u16  origHeight;
    fx32 magW;
    fx32 magH;
};

struct Mtx44 {
    fx32 _00, _01, _02, _03;
    fx32 _10, _11, _12, _13;
    fx32 _20, _21, _22, _23;
    fx32 _30, _31, _32, _33;
};

void NNSi_G3dTexMtxScaleTrans(struct Mtx44 *m, const struct MatAnm *anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = -(fx32)((fx64)anm->scaleS * anm->transS >> 8) * anm->origWidth;
    m->_31 = ((-anm->scaleT - anm->scaleT + 0x1000 * 2) * anm->origHeight << 3) +
             (fx32)((fx64)anm->scaleT * anm->transT >> 8) * anm->origHeight;

    m->_10 = 0;
}
