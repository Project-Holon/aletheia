/*
 * function: func_02206664
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
 *   func_02046AFC 0x02046AFC arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   NNS_G3dGlbBaseTrans 0x0206A9DC arm
 *   func_02082B60 0x02082B60 arm
 *   NNS_G3dGlbBaseScale 0x0206AA0C arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0206DB80 0x0206DB80 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 *   func_02207510 0x02207510 thumb ov195
 *   func_02208570 0x02208570 thumb ov195
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
extern void func_02046AFC(u8 *dst);
extern void func_0207ADC4(MtxFx33 *m);
extern void NNS_G3dGlbBaseTrans(const VecFx32 *trans);
extern void func_02082B60(const MtxFx33 *src, MtxFx33 *dst);
extern void NNS_G3dGlbBaseScale(const VecFx32 *scale);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_0206DB80(void);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);
struct Grid;
extern void func_02207510(struct Grid *w, u16 heap);
struct Quad;
extern void func_02208570(struct Quad *p, u16 heap);

void func_02206664(Owner *o)
{
    u8 save0[0x20];
    u8 save1[0x24];
    Work *w = o->work;
    u8 i;

    G3D_SYSTEM_GetProjection((int)save0);
    func_02046AFC(save1);
    {
        VecFx32 scale = d_02208E8C;
        MtxFx33 rot;
        VecFx32 trans = {0, 0, 0};

        func_0207ADC4(&rot);
        NNS_G3dGlbBaseTrans(&trans);
        func_02082B60(&rot, &d_02148BCC.baseRot);
        d_02148BCC.flag &= ~0xa4;
        NNS_G3dGlbBaseScale(&scale);
    }
    func_02048AD0(w->tex);
    func_020479D8();
    func_0206DB80();
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    REG_DIF_AMB = 0x7fff7fff;
    REG_SPE_EMI = 0x7fff7fff;
    for (i = 0; i < 2; i++) {
        if (w->grid[i] != 0)
            func_02207510(w->grid[i], o->heap);
    }
    if (w->quad != 0)
        func_02208570(w->quad, o->heap);
    G3D_SYSTEM_SetProjection((const u32 *)save0);
    G3D_SYSTEM_SetLookAt(save1);
    func_020479D8();
    func_0206DB80();
}
