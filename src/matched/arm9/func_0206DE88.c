/*
 * function: NNS_G3dGeResetGX
 * address:  0x0206DE88
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGeFlushBuffer    0x0206DB80  arm
 *   G3X_GetClipMtx    0x0207DC98  arm
 *   MTX_Copy44To43_    0x0207BDE0  arm
 *   G3X_GetVectorMtx    0x0207DCC8  arm
 *
 * The 3D-engine reset path: drain the pending display list (NNS_G3dGeFlushBuffer),
 * zero GXFIFO's control words at 0x04000440/0x04000444/0x04000454, then, if a
 * matrix block was given, spin G3X_GetClipMtx on a 0x40-byte stack scratch
 * until it reports ready and hand the pair to MTX_Copy44To43_; if a second block
 * was given, spin G3X_GetVectorMtx on it; finally write 1 to 0x04000448 and 2 to
 * 0x04000440 (the store to 0x04000440 is spelled `str r0, [r1, #-8]` off the
 * 0x04000448 pool word, so the two are one base in the original too).
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, and the sibling
 * src/matched/NNS_G3dGeFlushBuffer.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGeResetGX.c \
 *       --func NNS_G3dGeResetGX --addr 0x0206DE88 --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

extern void NNS_G3dGeFlushBuffer(void);
extern u32  G3X_GetClipMtx(void *p);
extern void MTX_Copy44To43_(void *p, void *q);
extern u32  G3X_GetVectorMtx(void *p);

void NNS_G3dGeResetGX(void *a, void *b)
{
    u32 tmp[0x10];

    NNS_G3dGeFlushBuffer();
    *(u32 *)0x04000440 = 0;
    *(u32 *)0x04000444 = 0;
    *(u32 *)0x04000454 = 0;
    if (a != 0) {
        while (G3X_GetClipMtx(tmp) != 0)
            ;
        MTX_Copy44To43_(tmp, a);
    }
    if (b != 0) {
        while (G3X_GetVectorMtx(b) != 0)
            ;
    }
    *(u32 *)0x04000448 = 1;
    *(u32 *)0x04000440 = 2;
}
