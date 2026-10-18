/*
 * function: SHINKA_DEMO_VIEW_Draw3d
 * address:  0x02206664
 * packet:   pkt_02206664
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208E8C 0x02208E8C data
 *   d_02148BCC 0x02148BCC data
 *   G3D_SYSTEM_GetProjection 0x020467EC arm
 *   G3D_SYSTEM_GetLookAt 0x02046AFC arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   NNS_G3dGlbBaseTrans 0x0206A9DC arm
 *   MI_Copy36B 0x02082B60 arm
 *   NNS_G3dGlbBaseScale 0x0206AA0C arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGeFlushBuffer 0x0206DB80 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 *   SHINKA_DEMO_VIEW_DrawGrid 0x02207510 thumb ov195
 *   SHINKA_DEMO_VIEW_DrawQuad 0x02208570 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef volatile u32 vu32;

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_DIF_AMB      (*(vu32 *)0x040004C0)
#define REG_SPE_EMI      (*(vu32 *)0x040004C4)

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct MtxFx33 {
    fx32 m[3][3];
} MtxFx33;

typedef struct GlbState {
    u8 pad00[0x3c];
    MtxFx33 baseRot;
    u8 pad60[0x7c - 0x60];
    u32 flag;
} GlbState;

typedef struct Work {
    u32 f00;
    void *tex;
    void *grid[2];
    void *quad;
} Work;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x56];
    Work *work;
} Owner;

extern const VecFx32 d_02208E8C;
extern GlbState d_02148BCC;
extern void G3D_SYSTEM_GetProjection(int p0);
struct Light;
extern void G3D_SYSTEM_GetLookAt(u8 *dst);
extern void MTX_Identity33_(MtxFx33 *m);
extern void NNS_G3dGlbBaseTrans(const VecFx32 *trans);
extern void MI_Copy36B(const MtxFx33 *src, MtxFx33 *dst);
extern void NNS_G3dGlbBaseScale(const VecFx32 *scale);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void NNS_G3dGeFlushBuffer(void);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);
struct Grid;
extern void SHINKA_DEMO_VIEW_DrawGrid(struct Grid *w, u16 heap);
struct Quad;
extern void SHINKA_DEMO_VIEW_DrawQuad(struct Quad *p, u16 heap);

void SHINKA_DEMO_VIEW_Draw3d(Owner *o)
{
    u8 save0[0x20];
    u8 save1[0x24];
    Work *w = o->work;
    u8 i;

    G3D_SYSTEM_GetProjection((int)save0);
    G3D_SYSTEM_GetLookAt(save1);
    {
        VecFx32 scale = d_02208E8C;
        MtxFx33 rot;
        VecFx32 trans = {0, 0, 0};

        MTX_Identity33_(&rot);
        NNS_G3dGlbBaseTrans(&trans);
        MI_Copy36B(&rot, &d_02148BCC.baseRot);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale(&scale);
    }
    G3D_CAMERA_Reset(w->tex);
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    REG_DIF_AMB = 0x7fff7fff;
    REG_SPE_EMI = 0x7fff7fff;
    for (i = 0; i < 2; i++) {
        if (w->grid[i] != 0)
            SHINKA_DEMO_VIEW_DrawGrid(w->grid[i], o->heap);
    }
    if (w->quad != 0)
        SHINKA_DEMO_VIEW_DrawQuad(w->quad, o->heap);
    G3D_SYSTEM_SetProjection((const u32 *)save0);
    G3D_SYSTEM_SetLookAt(save1);
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
}
