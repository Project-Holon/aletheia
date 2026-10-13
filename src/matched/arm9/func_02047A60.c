/*
 * function: func_02047A60
 * address:  0x02047A60
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem      0x02146A5C  data
 *   g_renderState      0x02148B4C  data
 *   g_renderStateIdentityMtx      0x02148C08  data
 *   func_02047788   0x02047788  arm
 *   func_0204755C   0x0204755C  arm
 *   G3D_SYSTEM_DrawRenderObj   0x02047C8C  arm
 *   NNS_G3dGlbBaseTrans   0x0206A9DC  arm
 *   NNS_G3dGlbBaseScale   0x0206AA0C  arm
 *   MI_Copy36B      0x02082B60  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct { u32 x, y, z; } VecFx32;
typedef struct { u32 m[9]; } MtxFx33;

struct Arg {
    u8      pad_00[0x0C];
    VecFx32 v0c;
    MtxFx33 m18;
};

struct Ctx { u8 pad_00[0x88]; void (*f88)(void); };

extern struct Ctx *_G3dSystem;
extern u32 g_renderState[];
extern u32 g_renderStateIdentityMtx[];

extern int func_02047788(int *p);
extern int func_0204755C(int *p);
struct P02047C8C;
extern void G3D_SYSTEM_DrawRenderObj(struct P02047C8C *p);
extern void  NNS_G3dGlbBaseTrans(void *p);
extern void  NNS_G3dGlbBaseScale(VecFx32 *p);
extern void  MI_Copy36B(const void *src, void *dst);

void func_02047A60(void *a0, struct Arg *a1)
{
    void *r;

    r = (void *)func_0204755C((int *)func_02047788(a0));
    NNS_G3dGlbBaseTrans(a1);
    MI_Copy36B(&a1->m18, g_renderStateIdentityMtx);
    g_renderState[63] = g_renderState[63] & ~0xa4u;
    NNS_G3dGlbBaseScale(&a1->v0c);
    _G3dSystem->f88();
    G3D_SYSTEM_DrawRenderObj(r);
}
