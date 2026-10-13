/*
 * function: G3D_SYSTEM_BoxTest
 * address:  0x02047C04
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *
 * Four registrations through NNS_G3dGeBufferOP_N (same three-argument shape as
 * src/matched/NNS_G3dGlbFlushP.c: command, buffer, count), then NNS_G3dGeFlushBuffer
 * and a spin on func_0207DEA4 over the first slot until it reports zero.
 * The value returned is that slot, still holding the 1 it was seeded with.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef signed int     s32;
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
extern int func_0207DEA4(s32 *in);

int G3D_SYSTEM_BoxTest(void *obj)
{
    int done;
    int arg;
    int zero;

    done = 1;
    arg  = 0x30C1;
    NNS_G3dGeBufferOP_N(0x29, &arg, 1);
    zero = 0;
    NNS_G3dGeBufferOP_N(0x40, &zero, 1);
    NNS_G3dGeBufferOP_N(0x41, 0, 0);
    NNS_G3dGeBufferOP_N(0x70, obj, 3);
    NNS_G3dGeFlushBuffer();
    while (func_0207DEA4(&done) != 0) {
        ;
    }
    return done;
}
