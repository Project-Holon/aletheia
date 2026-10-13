/*
 * function: FIELDMAP_Draw3dNormal
 * address:  0x02189810
 * packet:   pkt_ov021_02189810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DrawTalkSys    0x0219047C  thumb  ov021
 *   FIELD_G3D_MAPPER_Draw    0x0218CC64  thumb  ov021
 *   FIELDSKILL_MAPEFF_Apply    0x021C7FB4  thumb  ov021
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   FIELD_EFFECT_Draw    0x021ABE0C  thumb  ov021
 *   FIELD_G3DOBJ_DrawAll    0x021C64E0  thumb  ov021
 *   func_02050790    0x02050790  arm
 *   UNION_EFF_Draw    0x0217F928  thumb  ov019
 *   FIELD_SUBPROC_MGR_RunDraw    0x021BB954  thumb  ov021
 *   WEATHER_Draw    0x021A1B38  thumb  ov021
 *   FLD_EXP_OBJ_Draw    0x021BE4F8  thumb  ov021
 *   FLD_PARTICLE_Exit    0x021C1AEC  thumb  ov021
 *   FLD3D_CI_DrawEffect    0x021C1C4C  thumb  ov021
 *   g_DefaultProjectionMtx       0x02148B54  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00704.h"
#include "../include/G_Glb.h"

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

extern MtxFx44 g_DefaultProjectionMtx;
typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

extern struct Glb SCREENTEX_CameraState;

extern void FIELD_MSGBG_DrawTalkSys(u8 *p);
extern void FIELD_G3D_MAPPER_Draw(char *p, int a, int m);
extern void FIELDSKILL_MAPEFF_Apply(u32 a);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void FIELD_EFFECT_Draw(u32 a);
extern void FIELD_G3DOBJ_DrawAll(u32 a);
struct tagLISTCB;
extern void func_02050790(struct tagLISTCB *list, int b, int c);
extern void UNION_EFF_Draw(char *p);
extern void FIELD_SUBPROC_MGR_RunDraw(u8 *p);
extern void WEATHER_Draw(u32 *p);
extern void FLD_EXP_OBJ_Draw(char *p);
extern void FLD_PARTICLE_Exit(void);
extern void FLD3D_CI_DrawEffect(char *p);

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

void FIELDMAP_Draw3dNormal(u8 *p)
{
    MtxFx44 saved;
    MtxFx44 m;

    if (((struct Obj00704 *)p)->f28 != 0)
        FIELD_MSGBG_DrawTalkSys((u8 *)(((struct Obj00704 *)p)->f28));
    FIELD_G3D_MAPPER_Draw((char *)(((struct Obj00704 *)p)->f48), ((struct Obj00704 *)p)->fA4, 1);
    FIELDSKILL_MAPEFF_Apply(((struct Obj00704 *)p)->fA0);
    saved = g_DefaultProjectionMtx;

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104);
    MIi_CpuCopyFast(&m, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    FIELD_EFFECT_Draw(((struct Obj00704 *)p)->f94);
    FIELD_G3DOBJ_DrawAll(((struct Obj00704 *)p)->f130);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB0), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB8), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    if (((struct Obj00704 *)p)->f98 != 0)
        UNION_EFF_Draw((char *)(((struct Obj00704 *)p)->f98));

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104 / 2);
    MIi_CpuCopyFast(&m, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB4), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);

    MIi_CpuCopyFast(&saved, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    func_0206A854();

    FIELD_SUBPROC_MGR_RunDraw((u8 *)(((struct Obj00704 *)p)->fBC));
    WEATHER_Draw((u32 *)(((struct Obj00704 *)p)->f20));
    FLD_EXP_OBJ_Draw((char *)(((struct Obj00704 *)p)->f34));
    FLD_PARTICLE_Exit();
    FLD3D_CI_DrawEffect((char *)(((struct Obj00704 *)p)->f124));
}
