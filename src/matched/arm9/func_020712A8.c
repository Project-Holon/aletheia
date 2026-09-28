/*
 * function: func_020712A8
 * address:  0x020712A8
 * packet:   pkt_02070B64
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_DivAsync      0x0207C930  arm
 *   FX_GetDivResult  0x0207C86C  arm
 *
 * NitroSystem g3d texture-SRT matrix, the rotation-only member: build a
 * texture MtxFx44 from a material animation result (NNSG3dMatAnmResult:
 * sinR/cosR fx16 at +0x20/+0x22, origWidth/origHeight u16 at +0x2c/+0x2e),
 * with the aspect correction from two hardware divides h/w and w/h.
 *
 * docs/notes/pkt_02071104.c.txt held this at 4 bytes (an r1/r2 swap on the
 * _30 term).  Two changes close it: the real structure types (MtxFx44 and
 * the MatAnmResult layout) under ../2.0/sp2, and the _30 factor's negation
 * done in u32, `(fx32)-(u32)(sinR + cosR) + 0x1000`.  A signed negation folds
 * with the + 0x1000 into one rsb (180 bytes); the three-statement spelling
 * keeps the size but swaps the registers.  The permuter's anneal found the
 * unsigned negation (`temp(tmp=-t) ; cast(u32)`); this is its readable form.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020712A8.c \
 *       --func func_020712A8 --addr 0x020712A8 --arm --cc ../2.0/sp2
 */
typedef unsigned short u16; typedef unsigned int u32; typedef int s32; typedef short fx16; typedef s32 fx32;
typedef struct {
    u32  flag; u32 prmMatColor0; u32 prmMatColor1; u32 prmPolygonAttr; u32 prmTexImage; u32 prmTexPltt;
    fx32 scaleS, scaleT; fx16 sinR, cosR; fx32 transS, transT; u16 origWidth, origHeight; fx32 magW, magH;
} MatAnmResult;
typedef struct { fx32 _00,_01,_02,_03,_10,_11,_12,_13,_20,_21,_22,_23,_30,_31,_32,_33; } MtxFx44;
extern void FX_DivAsync(fx32 numer, fx32 denom);
extern fx32 FX_GetDivResult(void);
void func_020712A8(MtxFx44 *m, const MatAnmResult *anm)
{
    fx32 w = anm->origWidth << 12;
    fx32 h = anm->origHeight << 12;
    FX_DivAsync(h, w);
    m->_00 = anm->cosR;
    m->_11 = anm->cosR;
    m->_01 = (-anm->sinR * FX_GetDivResult()) >> 12;
    FX_DivAsync(w, h);
    m->_30 = (anm->origWidth * ((fx32)-(u32)(anm->sinR + anm->cosR) + 0x1000)) << 3;
    m->_31 = (anm->origHeight * (anm->sinR - anm->cosR + 0x1000)) << 3;
    m->_10 = (anm->sinR * FX_GetDivResult()) >> 12;
}
