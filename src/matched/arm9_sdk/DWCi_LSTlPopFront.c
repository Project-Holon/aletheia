/*
 * function: G3D_SYSTEM_GetResourceTex
 * address:  0x02047250
 * packet:   pkt_02047250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGetTex 0x0206E964 arm
 */

struct DwcList { unsigned int f0; unsigned char *f4; };
extern unsigned char *NNS_G3dGetTex(unsigned char *p);

unsigned char *G3D_SYSTEM_GetResourceTex(struct DwcList *list)
{
    return NNS_G3dGetTex(list->f4);
}
