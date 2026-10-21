/*
 * file:     shinka_demo_effect.c
 * unit:     yes
 * function: SHINKA_DEMO_EFFECT_CreateNodes, SHINKA_DEMO_EFFECT_FreeNode, SHINKA_DEMO_EFFECT_Create, SHINKA_DEMO_EFFECT_Destroy, SHINKA_DEMO_EFFECT_Main, SHINKA_DEMO_EFFECT_Draw, SHINKA_DEMO_EFFECT_Trigger, SHINKA_DEMO_EFFECT_StartIntro, SHINKA_DEMO_EFFECT_AdvanceState, SHINKA_DEMO_EFFECT_IsState4, SHINKA_DEMO_EFFECT_IsCameraReady, SHINKA_DEMO_EFFECT_CreateParticle, SHINKA_DEMO_EFFECT_DeleteParticle, SHINKA_DEMO_EFFECT_UpdateParticle, SHINKA_DEMO_EFFECT_DrawParticle, SHINKA_DEMO_EFFECT_SetParticleActive, SHINKA_DEMO_EFFECT_SetParticleTimer, SHINKA_DEMO_EFFECT_SetParticleTimerRaw, SHINKA_DEMO_EFFECT_InitUnit, SHINKA_DEMO_EFFECT_DeleteUnit, SHINKA_DEMO_EFFECT_DrawNodes, SHINKA_DEMO_EFFECT_SetupNode, SHINKA_DEMO_EFFECT_RemoveUnit, SHINKA_DEMO_EFFECT_UpdateAnime, SHINKA_DEMO_EFFECT_AnimSetState1, SHINKA_DEMO_EFFECT_AnimIsState2, SHINKA_DEMO_EFFECT_AnimSetState3, SHINKA_DEMO_EFFECT_AnimIsState0
 * address:  0x022086C8
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from shinka_demo_view.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   d_02208F7C 0x02208F7C data
 *   d_02208ED0 0x02208ED0 data
 *   SHINKA_DEMO_EFFECT_AnimIsState0 0x02208C30 thumb ov195
 *   d_02208F24 0x02208F24 data
 *   d_02208F30 0x02208F30 data
 *   d_02208E9C 0x02208E9C data
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_RESOURCE_GetType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_02208EC0 0x02208EC0 data
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetUnitObjIdx 0x020489F4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 */
#include "shinka_demo_graphic_shared_types.h"
#include "../arm9/g3d_util.h"
#include "shinka_demo_view_shared_types.h"

struct Ptc;

struct Anim;

struct ParticleSys;

struct ParticleCameraParams;

struct Util;

struct Transform;

struct Arg;

struct G3dSys;

struct AnmCtl;

struct Util;

typedef struct EffectNode EffectNode;

typedef struct EffectModel {
    u16 heap;
    u16 pad02;
    u32 mode;
    u32 state;
    u32 wait;
    void *ptc;
    void *res;
    u16 unitIdx;
    u16 mainNode;
    u16 count;
    u16 pad1e;
    EffectNode *nodes;
    u32 updateCount;
    u32 animeState;
} EffectModel;

typedef struct EmitParam {
    u32 projType;
    fx32 fovSin;
    fx32 fovCos;
    u32 aspect;
    u32 orthoExtent;
    fx32 nearZ;
    u32 farZ;
    u32 projScale;
} EmitParam;

typedef struct Ptc {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    void *cues;
    u8 work[0x4800];
    void *spl;
    u8 res;
    u8 pad4811[3];
    u32 active;
    s32 timer;
} Ptc;

typedef struct Cue {
    u16 frame;
    u8 emit;
    u8 id;
} Cue;

typedef struct Emit {
    u8 work[0x4800];
    void *spl;
    u8 res;
    u8 pad[3];
} Emit;

typedef struct EffectParticle {
    u16 frame;
    u16 cue;
    u16 ncue;
    u16 pad06;
    Cue *cues;
    Emit emit[1];
    u32 active;
    s32 timer;
} EffectParticle;

typedef struct EffectNode {u16 id;u16 pad02;fx32 tx,ty,tz,sx,sy,sz;u8 mtx[0x24];u32 visible;} EffectNode;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/fx_mtx33.h"

extern int SHINKA_DEMO_EFFECT_AnimIsState0(EffectModel *p);

#include "../arm9/particle.h"
struct ParticleSys;













struct G3dObjectStatus;
struct G3dObject;

#include "../arm9/g3d_system.h"








ShinkaDemoGraphicNode *SHINKA_DEMO_EFFECT_CreateNodes(u16 heap, u16 n);

void SHINKA_DEMO_EFFECT_FreeNode(void *p);

EffectModel *SHINKA_DEMO_EFFECT_Create(u16 heap, u32 x);

void SHINKA_DEMO_EFFECT_Destroy(char *a);

void SHINKA_DEMO_EFFECT_Main(EffectModel *p);

void SHINKA_DEMO_EFFECT_Draw(char *a);

void SHINKA_DEMO_EFFECT_Trigger(char *a);

void SHINKA_DEMO_EFFECT_StartIntro(int *p);

void SHINKA_DEMO_EFFECT_AdvanceState(int *p);

int SHINKA_DEMO_EFFECT_IsState4(int *p);

int SHINKA_DEMO_EFFECT_IsCameraReady(int *p);

Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 cueCount, void *cueTable);

void SHINKA_DEMO_EFFECT_DeleteParticle(char *a);

void SHINKA_DEMO_EFFECT_UpdateParticle(EffectParticle *p);

void SHINKA_DEMO_EFFECT_DrawParticle(int unused);

void SHINKA_DEMO_EFFECT_SetParticleActive(char *p);

void SHINKA_DEMO_EFFECT_SetParticleTimer(char *p,u32 v);

void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(EffectParticle *p, s32 timer);

void SHINKA_DEMO_EFFECT_InitUnit(char *a);

void SHINKA_DEMO_EFFECT_DeleteUnit(char *p);

void SHINKA_DEMO_EFFECT_DrawNodes(EffectModel *p);

void SHINKA_DEMO_EFFECT_SetupNode(EffectModel *p);

void SHINKA_DEMO_EFFECT_RemoveUnit(char *a);

void SHINKA_DEMO_EFFECT_UpdateAnime(char *p);

void SHINKA_DEMO_EFFECT_AnimSetState1(EffectModel *p);

int SHINKA_DEMO_EFFECT_AnimIsState2(EffectModel *p);

void SHINKA_DEMO_EFFECT_AnimSetState3(EffectModel *p);

extern const s16 FX_SinCosTable_[];

extern char d_02208F7C[];

extern char d_02208ED0[];

extern const VecFx32 d_02208F24;

extern const VecFx32 d_02208F30;

extern const u32 d_02208E9C[2];

extern char d_02208EC0[];

ShinkaDemoGraphicNode *SHINKA_DEMO_EFFECT_CreateNodes(u16 heap, u16 n)
{
    ShinkaDemoGraphicNode *p = GFL_HEAP_Alloc(heap, n * sizeof(ShinkaDemoGraphicNode), 1, d_02208F7C, 0xe8);
    u16 i;

    for (i = 0; i < n; i++) {
        p[i].tx = 0;
        p[i].ty = 0;
        p[i].tz = 0;
        p[i].sx = 0x1000;
        p[i].sy = 0x1000;
        p[i].sz = 0x1000;
        MTX_Identity33_((MtxFx33 *)p[i].mtx);
    }
    return p;
}

void SHINKA_DEMO_EFFECT_FreeNode(void *node){GFL_HEAP_Free(node);}

EffectModel *SHINKA_DEMO_EFFECT_Create(u16 heap, u32 x)
{
    EffectModel *p = GFL_HEAP_Alloc(heap, sizeof(EffectModel), 1, d_02208F7C, 0x150);

    p->heap = heap;
    p->mode = x;
    if (x == 0)
        p->state = 0;
    else
        p->state = 7;
    p->wait = 0;
    p->ptc = SHINKA_DEMO_EFFECT_CreateParticle(p->heap, 9, d_02208ED0);
    SHINKA_DEMO_EFFECT_InitUnit((char *)p);
    SHINKA_DEMO_EFFECT_SetupNode((EffectModel *)p);
    return p;
}

void SHINKA_DEMO_EFFECT_Destroy(char *model)
{
    SHINKA_DEMO_EFFECT_RemoveUnit(model);
    SHINKA_DEMO_EFFECT_DeleteUnit(model);
    SHINKA_DEMO_EFFECT_DeleteParticle((char *)(((EffectModel *)model)->ptc));
    GFL_HEAP_Free(model);
}

void SHINKA_DEMO_EFFECT_Main(EffectModel *model)
{
    switch (model->state) {
    case 0:
    case 1:
        break;
    case 2:
        SHINKA_DEMO_EFFECT_AnimSetState1((EffectModel *)model);
        model->state = 3;
        break;
    case 3:
        if (SHINKA_DEMO_EFFECT_AnimIsState2((EffectModel *)model)) {
            model->state = 4;
            model->wait = 3;
            SHINKA_DEMO_EFFECT_SetParticleTimerRaw((EffectParticle *)model->ptc, 0);
        }
        break;
    case 4:
        if (model->wait == 0) {
            SHINKA_DEMO_EFFECT_AnimSetState3((EffectModel *)model);
            model->state = 5;
        } else {
            model->wait = model->wait - 1;
        }
        break;
    case 5:
        if (SHINKA_DEMO_EFFECT_AnimIsState0((EffectModel *)model))
            model->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    SHINKA_DEMO_EFFECT_UpdateAnime((char *)model);
    SHINKA_DEMO_EFFECT_UpdateParticle((EffectParticle *)model->ptc);
}

void SHINKA_DEMO_EFFECT_Draw(char *model)
{
    SHINKA_DEMO_EFFECT_DrawNodes((EffectModel *)((struct Anim *)model));
    SHINKA_DEMO_EFFECT_DrawParticle((sptr)((EffectModel *)model)->ptc);
}

void SHINKA_DEMO_EFFECT_Trigger(char *model)
{
    SHINKA_DEMO_EFFECT_SetParticleTimer((char *)(((EffectModel *)model)->ptc), 0x1e);
    if (((EffectModel *)model)->state == 1)
        ((EffectModel *)model)->state = 2;
}

/*
 * Move the ov195 scene object to state 1 with a 0x26c timer.  Labelled leaf.
 */
void SHINKA_DEMO_EFFECT_StartIntro(int *model)
{
    void SHINKA_DEMO_EFFECT_SetParticleActive(char *model);

    SHINKA_DEMO_EFFECT_SetParticleActive((char *)model[4]);
    model[2] = 1;
    model[3] = 0x26c;
}

/*
 * Flag bump on the ov195 scene object (+8 == 1 -> 2); unlabelled leaf.
 */
void SHINKA_DEMO_EFFECT_AdvanceState(int *model)
{
    if (model[2] == 1)
        model[2] = 2;
}

/*
 * True when the ov195 scene object's +8 state is 4; unlabelled leaf.
 */
int SHINKA_DEMO_EFFECT_IsState4(int *model)
{
    if (model[2] == 4)
        return 1;
    return 0;
}

/*
 * Camera-state predicate on the ov195 scene object's +8/+0xc words:
 * state 4 with +0xc <= 1, or state 5.  Unlabelled leaf.
 */
int SHINKA_DEMO_EFFECT_IsCameraReady(int *model)
{
    if (model[2] == 4 && (unsigned)model[3] <= 1)
        return 1;
    if (model[2] == 5)
        return 1;
    return 0;
}

/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   call at +0xD8 to the unlabelled ARM leaf 0x02051B04, closed when that
 *   leaf was seeded in layout/function_starts.txt and matched
 *   (src/matched/PARTICLE_RESOURCE_GetType.c); all 13 relocations resolve.
 */
Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 cueCount, void *cueTable)
{
    VecFx32 cameraPos = d_02208F24;
    VecFx32 cameraTarget = d_02208F30;
    VecFx32 cameraUp = {0, 0, 0};
    EmitParam prm;
    Ptc *p;
    uptr res;

    prm.projType = 0;
    prm.fovSin = FX_SinCosTable_[0xe3 * 2];
    prm.fovCos = FX_SinCosTable_[0xe3 * 2 + 1];
    prm.aspect = 0x1555;
    prm.orthoExtent = 0;
    prm.nearZ = 0x1000;
    prm.farZ = 0x400000;
    prm.projScale = 0;

    p = GFL_HEAP_Alloc(heap, sizeof(Ptc), 1, d_02208F7C, 0x2e5);
    p->frame = 0;
    p->cue = 0;
    p->ncue = cueCount;
    p->cues = cueTable;
    p->active = 0;
    p->timer = -1;
    PARTICLE_InitManager(heap);
    p->spl = PARTICLE_CreateSystem((uptr)p->work, sizeof(p->work), 1, 5, 6, 0x3b, heap);
    PARTICLE_ReleaseCamera((struct ParticleSys *)p->spl);
    PARTICLE_InitCamera((struct ParticleSys *)p->spl, (struct ParticleCameraParams *)(&prm), 0x2000, (Vec3 *)((int *)(&cameraPos)), (Vec3 *)((int *)(&cameraTarget)), (Vec3 *)((int *)(&cameraUp)), heap);
    res = (uptr)PARTICLE_LoadArchiveMember((unsigned int)d_02208E9C[0], (unsigned int)d_02208E9C[1], (unsigned int)heap);
    p->res = PARTICLE_RESOURCE_GetType((void *)res);
    PARTICLE_SetupSystem(p->spl, (void *)res, 1, 0);
    return p;
}

void SHINKA_DEMO_EFFECT_DeleteParticle(char *particle)
{
    PARTICLE_ExitManager();
    GFL_HEAP_Free(particle);
}

void SHINKA_DEMO_EFFECT_UpdateParticle(EffectParticle *particle)
{
    if (particle->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; particle->cue < particle->ncue; particle->cue++) {
            if (particle->frame != particle->cues[(int)particle->cue].frame)
                break;
            c = &particle->cues[particle->cue];
            PARTICLE_StartEffect(particle->emit[c->emit].spl, c->id, (sptr)(&v));
        }
        particle->frame++;
    }
    if (particle->timer >= 0) {
        if (particle->timer == 0)
            PARTICLE_KillAllEffects(particle->emit[0].spl);
        particle->timer--;
    }
}

void SHINKA_DEMO_EFFECT_DrawParticle(int unused){PARTICLE_Main();}

void SHINKA_DEMO_EFFECT_SetParticleActive(char *particle){((EffectParticle *)particle)->active=1;}

void SHINKA_DEMO_EFFECT_SetParticleTimer(char *particle,u32 timer) { ((EffectParticle *)particle)->active=0; ((EffectParticle *)particle)->timer=timer; }

void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(EffectParticle *particle, s32 timer)
{
    particle->timer = timer;
}

void SHINKA_DEMO_EFFECT_InitUnit(char *model)
{
    *(int *)&((EffectModel *)model)->res = (sptr)G3D_UTIL_Create(4, 1, ((EffectModel *)model)->heap);
    ((EffectModel *)model)->count = 0;
}

void SHINKA_DEMO_EFFECT_DeleteUnit(char *model) { G3D_UTIL_Delete((G3dUtil *)(*(struct Util * *)&((EffectModel *)model)->res)); }

void SHINKA_DEMO_EFFECT_DrawNodes(EffectModel *model) { u16 i; EffectNode *n; for(i=0;i<model->count;i++) { n=model->nodes+i; if(n->visible) G3D_SYSTEM_DrawObject(G3D_UTIL_GetObject(model->res,n->id),(struct G3dObjectStatus *)((struct Transform *)&n->tx)); } }

/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   two calls to the unlabelled ARM leaf 0x0204784C (sites +0x8E, +0x98),
 *   closed when that leaf was seeded in layout/function_starts.txt and
 *   matched (src/matched/G3D_SYSTEM_SetObjectAnimeFrame.c); all 11 relocations resolve.
 */
void SHINKA_DEMO_EFFECT_SetupNode(EffectModel *model)
{
    u32 x;
    void *q;
    u16 i;
    EffectNode *n;
    u16 id;

    model->unitIdx = G3D_UTIL_AddUnit((G3dUtil *)model->res, (const G3dUtilSetup *)d_02208EC0);
    model->count = 1;
    model->nodes = (EffectNode *)SHINKA_DEMO_EFFECT_CreateNodes(model->heap, model->count);
    id = G3D_UTIL_GetUnitObjIdx(model->res, model->unitIdx);
    n = model->nodes;
    model->mainNode = 0;
    n->id = id;
    n->tx = 0;
    n->ty = 0;
    n->tz = 0;
    n->visible = 1;
    for (i = 0; i < model->count; i++)
        G3D_SYSTEM_EnableObjectAnime(G3D_UTIL_GetObject(model->res, model->nodes[i].id), 0);
    model->updateCount = 0;
    q = G3D_UTIL_GetObject(model->res, model->nodes[model->mainNode].id);
    x = 0;
    model->animeState = 0;
    G3D_SYSTEM_EnableObjectAnime(q, 1);
    G3D_SYSTEM_EnableObjectAnime(q, 2);
    G3D_SYSTEM_SetObjectAnimeFrame(q, 1, (s32 *)(&x));
    G3D_SYSTEM_SetObjectAnimeFrame(q, 2, (s32 *)(&x));
}

void SHINKA_DEMO_EFFECT_RemoveUnit(char *model)
{
    G3D_UTIL_RemoveUnit((G3dUtil *)((struct Util *)(*(int *)&((EffectModel *)model)->res)), ((EffectModel *)model)->unitIdx);
    SHINKA_DEMO_EFFECT_FreeNode((void *)(((EffectModel *)model)->nodes));
    ((EffectModel *)model)->count = 0;
}

/*
 * blocker resolved: 0x02047910 and 0x020478B8 were matched in arm9
 *           (src/matched/G3D_SYSTEM_LoopObjectAnimeFrame.c, src/matched/G3D_SYSTEM_IncObjectAnimeFrame.c;
 *           shards pkt_02047910 and pkt_020478B8), so their call sites now
 *           attest as `matched`.  0x02048A18 already resolved via matched;
 *           all 164 bytes are correct.
 */
void SHINKA_DEMO_EFFECT_UpdateAnime(char *model)
{
    unsigned short i;
    int j = 0;
    G3dObject *object;

    for (i = 0; i < ((EffectModel *)model)->count; i++) {
        unsigned short v = *(unsigned short *)((u8 *)((EffectModel *)model)->nodes + i * 0x44);
        G3dObject *x = G3D_UTIL_GetObject((G3dUtil *)((u8 *)(((EffectModel *)model)->res)), v);

        G3D_SYSTEM_LoopObjectAnimeFrame(x, j, 0x1000);
    }
    ((EffectModel *)model)->updateCount = ((EffectModel *)model)->updateCount + 1;
    object = G3D_UTIL_GetObject((G3dUtil *)((u8 *)(((EffectModel *)model)->res)),
                       *(unsigned short *)((u8 *)((EffectModel *)model)->nodes +
                                           ((EffectModel *)model)->mainNode * 0x44));
    if (((EffectModel *)model)->animeState == 1) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame(object, 1, 0x5000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame(object, 2, 0x5000);

        if (a == 0 && b == 0)
            ((EffectModel *)model)->animeState = 2;
    } else if (((EffectModel *)model)->animeState == 3) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame(object, 1, -0x2000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame(object, 2, -0x2000);

        if (a == 0 && b == 0)
            ((EffectModel *)model)->animeState = 0;
    }
}

void SHINKA_DEMO_EFFECT_AnimSetState1(EffectModel *model)
{
    model->animeState = 1;
}

int SHINKA_DEMO_EFFECT_AnimIsState2(EffectModel *model)
{
    if (model->animeState == 2)
        return 1;
    return 0;
}

void SHINKA_DEMO_EFFECT_AnimSetState3(EffectModel *model)
{
    model->animeState = 3;
}

int SHINKA_DEMO_EFFECT_AnimIsState0(EffectModel *model)
{
    if (model->animeState == 0)
        return 1;
    return 0;
}
