/*
 * function: FLD3D_CI_FindTexture
 * address:  0x021C2EDC
 * packet:   pkt_ov021_021C2EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a request block and dispatches FLD3D_CI_GetTexDataOffset on success (EXACT*: pad).
 *
 * symbols:
 *   FLD3D_CI_CopyName  0x021C2F50  thumb  ov021
 *   FLD3D_CI_GetTexDataOffset  0x021C2EBC  thumb  ov021
 *   NNS_G3dGetResDataByName  0x0206E62C  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

extern void FLD3D_CI_CopyName(char *dst, const char *src);
extern int NNS_G3dGetResDataByName(void *a, T *t);
extern int FLD3D_CI_GetTexDataOffset(u32 a, u32 b);

int FLD3D_CI_FindTexture(u8 *p, const char *name)
{
    T t;
    int r;

    FLD3D_CI_CopyName((char *)&t, name);
    if (p != 0)
        r = NNS_G3dGetResDataByName(p + 0x3C, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return FLD3D_CI_GetTexDataOffset((u32)p, r);
}
