/*
 * function: G3D_SYSTEM_TransVramTextureAndCut
 * address:  0x020470A8
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CutTexture  0x02046FCC  arm
 *
 * "Build, then trim": run the builder at 0x02046FF8 over the tagged object
 * and, only if it reports success, shrink the buffer with 0x02046FCC.  The
 * zero return is predicated (`moveq`/`popeq`) rather than branched, which is
 * the whole body being two statements long.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020470A8.c \
 *       --func G3D_SYSTEM_TransVramTextureAndCut --addr 0x020470A8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Tagged;
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void G3D_SYSTEM_CutTexture(struct Tagged *p);

u32 G3D_SYSTEM_TransVramTextureAndCut(void *p)
{
    if (G3D_SYSTEM_TransVramTexture(p) == 0) {
        return 0;
    }
    G3D_SYSTEM_CutTexture(p);
    return 1;
}
