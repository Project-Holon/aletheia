/*
 * file:     nns_g3d_glb_5.c
 * unit:     yes
 * function: NNS_G3dGlbLightColor, NNS_G3dGlbMaterialColorDiffAmb, NNS_G3dGlbMaterialColorSpecEmi
 * address:  0x0206AA78
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
 *   g_02148BF4       0x02148BF4  data
 *   g_renderState       0x02148B4C  data
 */
#include "nns_g3d_tex_4_types.h"

void NNS_G3dGlbLightColor(int lightId, u32 lightColor);
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 isSetVtxColor);
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 isShininess);



/*
 * NNS_G3dGlbLightColor: store the color of one light with the light index in
 * bits 30..31.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbLightColor.c \
 *       --func NNS_G3dGlbLightColor --addr 0x0206AA78 --cc 1.1p1 --arm
 */
void NNS_G3dGlbLightColor(int lightId, u32 lightColor)
{
    NNS_G3dGlb.lightColor[lightId] = lightColor | (u32)(lightId << 30);
}



/*
 * Unlabelled leaf: no prologue, so disasm.py never traced it and it sits in
 * the 76-byte gap between NNS_G3dGlbLightColor and func_0206AAD4, between two of the
 * flags object's literal pools.  NNS_G3dGlbMaterialColorDiffAmb: packs the
 * diffuse color, the set-vertex-color bit at bit 15 and the ambient color
 * into prmMatColor0 (0x02148B4C + 0x94).
 *
 * Extent note: the follower at 0x0206AAB0 is unlabelled too, so the listing's
 * inferred extent for this address runs to the next label at 0x0206AAD4 and
 * the verdict is EXACT*.  Both addresses are reported for
 * layout/function_starts.txt rather than edited in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbMaterialColorDiffAmb.c \
 *       --func NNS_G3dGlbMaterialColorDiffAmb --addr 0x0206AA8C --cc 1.1p1 --arm
 */
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 isSetVtxColor)
{
    NNS_G3dGlb.prmMatColor0 = diffuse | (ambient << 16) | ((u32)(isSetVtxColor != 0) << 15);
}


/*
 * NNS_G3dGlbMaterialColorSpecEmi: the +0x98 twin of NNS_G3dGlbMaterialColorDiffAmb, packing
 * the specular color, the shininess-table bit at bit 15 and the emission
 * color into prmMatColor1.
 *
 * Extent note: the listing's inferred extent for this address runs to the
 * next label at 0x0206AAD4, so the verdict is EXACT*; 0x0206AAB0 joins
 * 0x0206AA8C in the unlabelled-follower report.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbMaterialColorSpecEmi.c \
 *       --func NNS_G3dGlbMaterialColorSpecEmi --addr 0x0206AAB0 --cc 1.1p1 --arm
 */
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 isShininess)
{
    NNS_G3dGlb.prmMatColor1 = specular | (emission << 16) | ((u32)(isShininess != 0) << 15);
}
