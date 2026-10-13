/*
 * function: NNS_G3dGlbFlushP
 * address:  0x0206A884
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B50       0x02148B50  data
 *   g_renderStateDrawParams       0x02148B98  data
 *   g_02148BC8       0x02148BC8  data
 *   g_renderState       0x02148B4C  data
 *   NNS_G3dGeBufferOP_N    0x0206DDA4  arm
 *
 * Four registrations against the shared table at 0x02148B50/0x02148B98/
 * 0x02148BC8, the third of them with a one-word out-parameter whose address
 * is taken (hence the 8-byte frame), then the two low bits of the flags word
 * at 0x02148B4C + 0xFC are cleared and bit 1 set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbFlushP.c \
 *       --func NNS_G3dGlbFlushP --addr 0x0206A884 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int  g_02148B50[];
extern int  g_renderStateDrawParams[];
extern int  g_02148BC8[];
extern u32  g_renderState[];
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);

void NNS_G3dGlbFlushP(void)
{
    NNS_G3dGeBufferOP_N(0x1610, g_02148B50, 0x11);
    NNS_G3dGeBufferOP_N(0x19, g_renderStateDrawParams, 0xC);
    {
        int v = 2;
        NNS_G3dGeBufferOP_N(0x10, &v, 1);
    }
    NNS_G3dGeBufferOP_N(0x15, g_02148BC8, 0x20);
    g_renderState[63] = (g_renderState[63] & ~1u) | 2;
}
