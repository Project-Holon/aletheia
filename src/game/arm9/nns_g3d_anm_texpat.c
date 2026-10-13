/*
 * file:     nns_g3d_anm_texpat.c
 * unit:     yes
 * function: NNSi_G3dGetTexPatAnmTexNameByIdx, NNSi_G3dGetTexPatAnmPlttNameByIdx, NNSi_G3dTexPatAnmGetFrameValue, NNSi_G3dTexPatAnmGetTrackByIdx
 * address:  0x0206EA00
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d binres/res_struct_accessor_anm.c and the texture pattern
 * animation sampler, all under ../2.0/sp2:
 *   0x0206EA00  NNSi_G3dGetTexPatAnmTexNameByIdx
 *   0x0206EA2C  NNSi_G3dGetTexPatAnmPlttNameByIdx
 *   0x0206EA58  frame value lookup
 *   0x0206EAD8  track lookup
 * The name arrays are 16-byte NNSG3dResName records.  The accessor bodies are
 * the library bodies verbatim (asserts compiled out).
 *
 * Compiler pin of the two name accessors, the "kept branches" tell
 * (docs/FRONTEND-PINS.md): the image branches both failed tests to one shared
 * `mov r0, #0; bx lr` tail and keeps the three-instruction success arm
 * unpredicated, 44 bytes; dsi/1.1p1 predicates the success arm for 40 bytes
 * whatever the spelling (two ifs, &&, ||, nested, result local and goto were
 * measured).
 */
#include "nns_g3d_anm_calc_types.h"

/* One data track of a texture pattern animation: frame value count, frame ratio, offset of its records. */
typedef struct NNSG3dResTexPatAnmTrack {
    u16 numFrameValue;
    u16 reserved02;
    s16 ratioDataFrame;
    u16 ofsFrameValue;
} NNSG3dResTexPatAnmTrack;

const NNSG3dResName *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);
const NNSG3dResName *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
const NNSG3dResTexPatAnmFV *NNSi_G3dTexPatAnmGetFrameValue(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx, u32 frame);
const NNSG3dResTexPatAnmTrack *NNSi_G3dTexPatAnmGetTrackByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx);

/* Name of texture texIdx, or 0 when the animation has fewer textures. */
const NNSG3dResName *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx)
{
    if (pPatAnm && texIdx < pPatAnm->numTex) {
        const NNSG3dResName *pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsTexName);

        return &pNameArray[texIdx];
    }

    return 0;
}

/* Name of palette plttIdx, or 0 when the animation has fewer palettes. */
const NNSG3dResName *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx)
{
    if (pPatAnm && plttIdx < pPatAnm->numPltt) {
        const NNSG3dResName *pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsPlttName);

        return &pNameArray[plttIdx];
    }

    return 0;
}

/*
 * Bucket search in the frame values of a track: the scaled frame is a
 * fixed-point index; step it down over entries at or after frame, then up over
 * entries at or before frame, and return the entry.
 */
const NNSG3dResTexPatAnmFV *NNSi_G3dTexPatAnmGetFrameValue(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx, u32 frame)
{
    const NNSG3dResTexPatAnmTrack *pTrack = NNSi_G3dTexPatAnmGetTrackByIdx(pPatAnm, dataIdx);
    const NNSG3dResTexPatAnmFV *pFV = (const NNSG3dResTexPatAnmFV *)((const u8 *)pPatAnm + pTrack->ofsFrameValue);
    u32 idx = (u32)(pTrack->ratioDataFrame * frame) >> 12;

    while (idx != 0 && pFV[idx].idxFrame >= frame)
        idx--;
    while (idx + 1 < pTrack->numFrameValue && pFV[idx + 1].idxFrame <= frame)
        idx++;
    return &pFV[idx];
}

/*
 * The track record for dataIdx in the animation's dictionary, or 0 when the
 * animation is null or the index is out of range.  The null test is on the
 * computed dictionary address (`adds r3, r0, #12`), while the count and the
 * entry offset are read relative to the animation itself and only the unit
 * size goes through the computed base; that mix of spellings is what
 * reproduces the register use.
 */
const NNSG3dResTexPatAnmTrack *NNSi_G3dTexPatAnmGetTrackByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 dataIdx)
{
    const NNSG3dResDict *pDict = &pPatAnm->dict;

    if (pDict != 0 && dataIdx < pPatAnm->dict.numEntry) {
        u16 ofsEntry = pPatAnm->dict.ofsEntry;
        u16 sizeUnit = *(const u16 *)((const u8 *)pDict + ofsEntry);

        return (const NNSG3dResTexPatAnmTrack *)((const u8 *)pDict + ofsEntry + 4 + sizeUnit * dataIdx);
    }
    return 0;
}
