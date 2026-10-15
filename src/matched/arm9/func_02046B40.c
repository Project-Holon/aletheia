/*
 * function: G3D_SYSTEM_SetLookAt
 * address:  0x02046B40
 * packet:   pkt_02046B40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MTX_LookAt    0x0207BCA0  arm
 *   _G3dSystem       0x02146A5C  data
 *   g_renderState       0x02148B4C  data
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_CameraPositionOut       0x02148D8C  data
 *   SCREENTEX_CameraTargetOut       0x02148D98  data
 *   SCREENTEX_CameraUpOut       0x02148DA4  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 w[3];
} Blk;

extern u32 *_G3dSystem;
extern Blk SCREENTEX_CameraPositionOut;
extern Blk SCREENTEX_CameraTargetOut;
extern Blk SCREENTEX_CameraUpOut;
extern Blk g_renderStateDrawParams;
extern u32 g_renderState[];

extern void MTX_LookAt(void *a0, void *a1, void *a2, void *a3);

void G3D_SYSTEM_SetLookAt(u8 *a0)
{
    u8 *o = (u8 *)_G3dSystem;

    *(Blk *)(o + 0x5C) = *(Blk *)a0;
    *(Blk *)(o + 0x68) = *(Blk *)(a0 + 0xC);
    *(Blk *)(o + 0x74) = *(Blk *)(a0 + 0x18);
    SCREENTEX_CameraPositionOut = *(Blk *)(o + 0x5C);
    SCREENTEX_CameraTargetOut = *(Blk *)(o + 0x68);
    SCREENTEX_CameraUpOut = *(Blk *)(o + 0x74);
    MTX_LookAt(o + 0x5C, o + 0x68, o + 0x74, &g_renderStateDrawParams);
    g_renderState[0x3F] &= ~0xE8u;
}
