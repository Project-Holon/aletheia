/*
 * function: NNS_G3dGlbGetInvVPMtx
 * address:  0x0206AE2C
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pin evidence (2.0): the image re-materialises the address of the flags
 * object 0x02148B4C from its pool word at +0044, *after* the two calls at
 * +0020 and +0040; 1.1p1 keeps that address live across both calls in a
 * callee-saved register and grows the frame (push {r3,r4,r5,lr}), which is
 * the documented 2.0 tell in docs/FRONTEND-PINS.md ("kept constants": the
 * image rematerialises a constant from the pool where the build keeps it
 * live in a callee-saved register).  Same family as src/pending/
 * NNS_G3dDraw.c, pinned for the identical tell.
 *
 * PARKED AT MATCH.  Under the pin every concrete byte of the 88-byte body
 * reproduces; the single open site is the call to NNS_G3dGlbGetInvCameraMtx at +0010,
 * which is the only branch to that address anywhere in the image.  It
 * unsticks when 0x0206AAD4 is itself an EXACT manifest entry (`matched`) or
 * a second caller turns up in an overlay.
 *
 * symbols:
 *   g_renderState   0x02148B4C  data
 *   g_02148D4C   0x02148D4C  data
 *   NNS_G3dGlbGetInvCameraMtx  0x0206AAD4  arm
 *   NNS_G3dGlbGetInvProjectionMtx  0x0206AD20  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_G3dGlbGetInvVPMtx.c \
 *       --func NNS_G3dGlbGetInvVPMtx --addr 0x0206AE2C --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

extern u32  g_renderState[];
extern char g_02148D4C[];

extern u32 *NNS_G3dGlbGetInvCameraMtx(void);
extern u32 *NNS_G3dGlbGetInvProjectionMtx(void);
extern void  MTX_Copy43To44_(void *a, void *buf);
extern void  func_0207BE14(void *a, void *buf, void *c);

void *NNS_G3dGlbGetInvVPMtx(void)
{
    char buf[0x40];
    void *a;
    void *b;

    if ((g_renderState[0x3f] & 0x40) == 0) {
        a = NNS_G3dGlbGetInvCameraMtx();
        b = NNS_G3dGlbGetInvProjectionMtx();
        MTX_Copy43To44_(a, buf);
        func_0207BE14(b, buf, g_02148D4C);
        g_renderState[0x3f] |= 0x40;
    }
    return g_02148D4C;
}
