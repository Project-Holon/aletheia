/*
 * function: FIELD_G3D_MAP_RunBoxTest
 * address:  0x02169A14
 * packet:   pkt_ov010_02169A14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3X_GetBoxTestResult  0x0207DEA4  arm
 */

typedef unsigned int u32;

extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern void NNS_G3dGeFlushBuffer(void);
typedef signed int     s32;
extern int G3X_GetBoxTestResult(s32 *in);

u32 FIELD_G3D_MAP_RunBoxTest(u32 a)
{
    u32 x;
    u32 y;
    u32 z;

    x = 1;
    y = 0x30C1;
    NNS_G3dGeBufferOP_N(0x29, &y, 1);
    z = 0;
    NNS_G3dGeBufferOP_N(0x40, &z, 1);
    NNS_G3dGeBufferOP_N(0x41, 0, 0);
    NNS_G3dGeBufferOP_N(0x70, (void *)a, 3);
    NNS_G3dGeFlushBuffer();
    while (G3X_GetBoxTestResult((s32 *)(&x)) != 0)
        ;
    return x;
}
