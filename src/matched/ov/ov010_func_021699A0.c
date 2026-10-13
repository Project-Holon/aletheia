/*
 * function: FIELD_G3D_MAP_TestModelBox
 * address:  0x021699A0
 * packet:   pkt_ov010_021699A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   FIELD_G3D_MAP_RunBoxTest  0x02169A14  thumb  ov010
 */
#include "../include/Obj04164.h"

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern u32 FIELD_G3D_MAP_RunBoxTest(u32 a);

int FIELD_G3D_MAP_TestModelBox(void *p)
{
    s16 v[6];
    u32 w[3];
    u32 one;
    char *q;
    int r;

    r = 1;
    q = p ? (char *)p + 0x14 : 0;
    v[0] = ((struct Obj04164 *)q)->f18;
    v[1] = ((struct Obj04164 *)q)->f1A;
    v[2] = ((struct Obj04164 *)q)->f1C;
    v[3] = ((struct Obj04164 *)q)->f1E;
    v[4] = ((struct Obj04164 *)q)->f20;
    v[5] = ((struct Obj04164 *)q)->f22;
    NNS_G3dGeBufferOP_N(0x11, 0, 0);
    w[0] = ((struct Obj04164 *)q)->f24;
    w[1] = w[0];
    w[2] = w[0];
    NNS_G3dGeBufferOP_N(0x1b, w, 3);
    if (FIELD_G3D_MAP_RunBoxTest((u32)v) == 0)
        r = 0;
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
    return r;
}
