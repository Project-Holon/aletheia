/*
 * function: NNS_G3dInit
 * address:  0x0206DF14
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dInit.c \
 *       --func NNS_G3dInit --addr 0x0206DF14 --cc 1.1p1 --arm
 *
 * symbols:
 *   NNS_G3dGlbInit  0x0206A700  arm
 *   G3X_Init  0x0207D988  arm
 */

typedef unsigned int u32;

extern void G3X_Init(void);
extern void NNS_G3dGlbInit(void);

void NNS_G3dInit(void)
{
    G3X_Init();
    NNS_G3dGlbInit();
    *(u32 *)0x04000600 = (*(u32 *)0x04000600 & 0x3FFFFFFFu) | 0x80000000u;
}
