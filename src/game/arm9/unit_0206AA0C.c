/*
 * file:     unit_0206AA0C.c
 * unit:     yes
 * function: NNS_G3dGlbBaseScale, NNS_G3dGlbLightVector
 * address:  0x0206AA0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_renderState       0x02148B4C  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 */
#include "unit_0206A110_types.h"

void NNS_G3dGlbBaseScale(const VecFx32 *pScale);
void NNS_G3dGlbLightVector(int lightId, int x, int y, int z);


/*
 * NNS_G3dGlbBaseScale: copies the caller's scale vector into the block at
 * 0x02148C38 and clears the 0xa4 bit pair of the flag word at 0x02148B4C + 0xFC.
 *
 * The destination is spelled as one object with the flag word (0x02148C38 is
 * g_renderState + 0xEC) because that is what decides the schedule: with the two
 * addresses as separate objects the compiler hoists the flag-word load above
 * the store and needs a second pool register (`push {r3, lr}`, 52 bytes); as
 * one object every access is ordered behind the 12-byte copy and the leaf
 * comes out at the original 48 bytes with `ldr r3/r0, [pc]` twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbBaseScale.c \
 *       --func NNS_G3dGlbBaseScale --addr 0x0206AA0C --cc 1.1p1 --arm
 */
void NNS_G3dGlbBaseScale(const VecFx32 *pScale)
{
    if (pScale == 0) {
        return;
    }
    NNS_G3dGlb.prmBaseScale = *pScale;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_BASE_DEPENDENT;
}


/*
 * NNS_G3dGlbLightVector: packs three 10-bit fields (each taken from a signed
 * value shifted right by three) plus the light index at bits 30..31 into one
 * word of the lightVec array.
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbLightVector.c \
 *       --func NNS_G3dGlbLightVector --addr 0x0206AA3C --cc 1.1p1 --arm
 */
void NNS_G3dGlbLightVector(int lightId, int x, int y, int z)
{
    NNS_G3dGlb.lightVec[lightId] = (u32)(((x >> 3) & 0x3FF) | (((y >> 3) & 0x3FF) << 10)
                                         | (((z >> 3) & 0x3FF) << 20) | (lightId << 30));
}
