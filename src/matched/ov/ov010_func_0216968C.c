/*
 * function: FIELD_G3D_MAP_Draw
 * address:  0x0216968C
 * packet:   pkt_ov010_0216968C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_G3dGlbBaseTrans  0x0206A9DC  arm
 *   MI_Copy36B  0x02082B60  arm
 *   NNS_G3dGlbBaseScale  0x0206AA0C  arm
 *   NNS_G3dGlbFlush  0x0206A854  arm
 *   NNS_G3dGeBufferOP_N  0x0206DDA4  arm
 *   FIELD_G3D_MAP_TestModelBox  0x021699A0  thumb  ov010
 *   G3D_SYSTEM_DrawRenderObj  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   gG3dBaseMtx43     0x02148B98  data   a4
 */
#include "../include/Obj03541.h"
#include "../include/Obj19050.h"
#include "../include/Obj19051.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void NNS_G3dGlbBaseTrans(void *p);
extern void MI_Copy36B(void *a, void *b);
extern void NNS_G3dGlbBaseScale(void *p);
extern void NNS_G3dGlbFlush(void);
struct P02047C8C;
extern void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
extern int FIELD_G3D_MAP_TestModelBox(void *p);
extern void G3D_SYSTEM_DrawRenderObj(struct P02047C8C *p);
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern struct {
    u8 pad[0x7c];
    u32 f7c;
} d_02148BCC;
extern u8 d_02172160[];
extern u8 gG3dBaseMtx43[];

int FIELD_G3D_MAP_Draw(u8 *p)
{
    int r;

    r = 0;
    if (*(u16 *)&((struct Obj03541 *)p)->f0 != 0 && ((struct Obj19050 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4 != 0) {
        NNS_G3dGlbBaseTrans(d_0217216C);
        MI_Copy36B(d_02172178, d_02148C08);
        d_02148BCC.f7c &= ~0xa4;
        NNS_G3dGlbBaseScale(d_02172160);
        NNS_G3dGlbFlush();
        NNS_G3dGeBufferOP_N(0x15, 0, 0);
        NNS_G3dGeBufferOP_N(0x17, gG3dBaseMtx43, 0xc);
        NNS_G3dGeBufferOP_N(0x1c, p + 4, 3);
        if (FIELD_G3D_MAP_TestModelBox(((struct Obj19051 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4) == 1) {
            G3D_SYSTEM_DrawRenderObj(((struct Obj03541 *)p)->f2C);
            r = 1;
        }
    }
    return r;
}
