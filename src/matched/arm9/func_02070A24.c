/*
 * function: NNSi_G3dAnmSetTexParam
 * address:  0x02070A24
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGetResDataByName  0x0206E62C  arm
 *   func_0207C768  0x0207C768  arm
 *
 * NitroSystem g3d, the texture-parameter setter of the texture-pattern
 * animation: look the texture up by index in the texture block's dictionary
 * (NNS_G3dGetResDataByName, at +0x3c of the texture resource), rebase its TEXIMAGE_PARAM
 * on the VRAM address of the plain or the 4x4-compressed texture slot (format
 * field == 5, 0x14000000), store the original width/height (two 11-bit fields
 * of the extra parameter) and derive the magnification factors with FX_Div
 * (func_0207C768), FX32_ONE when unchanged.
 *
 * The earlier DIFF 60 (a mask/value register swap throughout) came from
 * three misreadings, all fixed here: the second parameter is the dictionary
 * INDEX forwarded untouched to NNS_G3dGetResDataByName (the caller NNSi_G3dAnmCalcNsBtp passes
 * a dictionary lookup's result there); the `lsl #16 / lsr #16 / bic
 * #0xe0000000` triple is NNS_GfdGetTexKeyAddr(vramKey) >> 3, i.e.
 * ((key & 0xffff) << 3) >> 3, not a 16-bit bitfield; and the prmTexImage
 * update is `&=` then `|=`.  1.1p1 is 28 bytes out on this source.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmSetTexParam.c \
 *       --func NNSi_G3dAnmSetTexParam --addr 0x02070A24 --arm --cc ../2.0/sp2
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef s32            fx32;
typedef struct { u32 vramKey; u16 sizeTex; u16 ofsDict; u16 flag; u16 pad; u32 ofsTex; } TexInfo;
typedef struct { u32 vramKey; u16 sizeTex; u16 ofsDict; u16 flag; u16 pad; u32 ofsTex; u32 ofsTexPlttIdx; } Tex4x4Info;
typedef struct { u32 vramKey; u16 sizePltt; u16 flag; u16 ofsDict; u16 pad; u32 ofsPlttData; } PlttInfo;
typedef struct { u8 dummy[4]; } ResDict;
typedef struct {
    u32        header[2];
    TexInfo    texInfo;      /* 0x08 */
    Tex4x4Info tex4x4Info;   /* 0x18 */
    PlttInfo   plttInfo;     /* 0x2c */
    ResDict    dict;         /* 0x3c */
} ResTex;
typedef struct { u32 texImageParam; u32 extraParam; } DictTexData;
typedef struct {
    u32  flag;
    u32  prmMatColor0;
    u32  prmMatColor1;
    u32  prmPolygonAttr;
    u32  prmTexImage;        /* 0x10 */
    u32  prmTexPltt;
    fx32 scaleS, scaleT;
    short sinR, cosR;
    fx32 transS, transT;
    u16  origWidth, origHeight;  /* 0x2c */
    fx32 magW, magH;         /* 0x30 */
} MatAnmResult;
extern void *NNS_G3dGetResDataByName(const ResDict *dict, u32 idx);
extern u32 func_0207C768(u32 a, u32 b);
#define GetTexKeyAddr(key) ((u32)(((key) & 0x0000FFFF) << 3))
void NNSi_G3dAnmSetTexParam(const ResTex *pTex, u32 idx, MatAnmResult *pResult)
{
    const DictTexData *pData = (const DictTexData *)(pTex ? NNS_G3dGetResDataByName(&pTex->dict, idx) : 0);
    u32 offset;
    if ((pData->texImageParam & 0x1c000000) != 0x14000000)
        offset = GetTexKeyAddr(pTex->texInfo.vramKey) >> 3;
    else
        offset = GetTexKeyAddr(pTex->tex4x4Info.vramKey) >> 3;
    pResult->prmTexImage &= 0xc00f0000;
    pResult->prmTexImage |= pData->texImageParam + offset;
    pResult->origWidth  = (u16)((pData->extraParam & 0x7ff) >> 0);
    pResult->origHeight = (u16)((pData->extraParam & (0x7ff << 11)) >> 11);
    {
        u32 w = (pData->extraParam & 0x7ff) >> 0;
        u32 h = (pData->extraParam & (0x7ff << 11)) >> 11;
        pResult->magW = (w != pResult->origWidth) ? func_0207C768((fx32)(w << 12), (fx32)(pResult->origWidth << 12)) : 0x1000;
        pResult->magH = (h != pResult->origHeight) ? func_0207C768((fx32)(h << 12), (fx32)(pResult->origHeight << 12)) : 0x1000;
    }
}
