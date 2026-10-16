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
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_02048A18 0x02048A18 arm
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
#include "shinka_demo_view_shared_types.h"

struct Ptc;

struct Anim;

struct Dst648;

struct Src648;

struct Rec;

struct Transform;

struct Arg;

struct G3dSys;

struct AnmCtl;

struct Ctx;

typedef struct EffectNode EffectNode;

typedef struct EffectModel {
    u16 heap;
    u16 pad02;
    u32 mode;
    u32 state;
    u32 wait;
    void *ptc;
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    EffectNode *nodes;
    u32 f24;
    u32 animeState;
} EffectModel;

typedef struct EmitParam {
    u32 f00;
    fx32 f04;
    fx32 f08;
    u32 f0c;
    u32 f10;
    fx32 f14;
    u32 f18;
    u32 f1c;
} EmitParam;

typedef struct Ptc {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 pad06;
    void *f08;
    u8 work[0x4800];
    void *spl;
    u8 f4810;
    u8 pad4811[3];
    u32 f4814;
    s32 f4818;
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

typedef struct EffectNode {u16 id;u16 pad02;fx32 tx,ty,tz,sx,sy,sz;u8 mtx[0x24];u32 f40;} EffectNode;

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern u32 GFL_HEAP_Free(void *p);

extern void MTX_Identity33_(MtxFx33 *m);

extern int SHINKA_DEMO_EFFECT_AnimIsState0(EffectModel *p);

extern void PARTICLE_InitManager(u32 heap);

extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);

extern int PARTICLE_ReleaseCamera(int a0);

extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);

extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);

extern u16 BUTTON_MAN_GetResourceType(void *res);

extern void PARTICLE_SetupSystem(void *spl, u32 res, u32 a2, u32 a3);

extern void PARTICLE_ExitManager(void);

extern int PARTICLE_StartEffect(void *p, int b, int c);

extern void PARTICLE_KillAllEffects(void *spl);

extern void PARTICLE_Main(void);

extern int G3D_UTIL_Create(int, int, int);

extern void G3D_UTIL_Delete(struct Rec *);

extern u32 func_02048A18(u8 *a0, int i);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

extern u16 G3D_UTIL_AddUnit(void *res, void *name);

extern u32 G3D_UTIL_GetUnitObjIdx(u8 *a0, int i);

extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);

Node *SHINKA_DEMO_EFFECT_CreateNodes(u16 heap, u16 n);

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

Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 a, void *b);

void SHINKA_DEMO_EFFECT_DeleteParticle(char *a);

void SHINKA_DEMO_EFFECT_UpdateParticle(EffectParticle *p);

void SHINKA_DEMO_EFFECT_DrawParticle(int a0);

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

Node *SHINKA_DEMO_EFFECT_CreateNodes(u16 heap, u16 n)
{
    Node *p = GFL_HEAP_Alloc(heap, n * sizeof(Node), 1, d_02208F7C, 0xe8);
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

void SHINKA_DEMO_EFFECT_FreeNode(void *p){GFL_HEAP_Free(p);}

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

void SHINKA_DEMO_EFFECT_Destroy(char *a)
{
    SHINKA_DEMO_EFFECT_RemoveUnit(a);
    SHINKA_DEMO_EFFECT_DeleteUnit(a);
    SHINKA_DEMO_EFFECT_DeleteParticle((char *)(((EffectModel *)a)->ptc));
    GFL_HEAP_Free(a);
}

void SHINKA_DEMO_EFFECT_Main(EffectModel *p)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        SHINKA_DEMO_EFFECT_AnimSetState1((EffectModel *)p);
        p->state = 3;
        break;
    case 3:
        if (SHINKA_DEMO_EFFECT_AnimIsState2((EffectModel *)p)) {
            p->state = 4;
            p->wait = 3;
            SHINKA_DEMO_EFFECT_SetParticleTimerRaw((EffectParticle *)p->ptc, 0);
        }
        break;
    case 4:
        if (p->wait == 0) {
            SHINKA_DEMO_EFFECT_AnimSetState3((EffectModel *)p);
            p->state = 5;
        } else {
            p->wait = p->wait - 1;
        }
        break;
    case 5:
        if (SHINKA_DEMO_EFFECT_AnimIsState0((EffectModel *)p))
            p->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    SHINKA_DEMO_EFFECT_UpdateAnime((char *)p);
    SHINKA_DEMO_EFFECT_UpdateParticle((EffectParticle *)p->ptc);
}

void SHINKA_DEMO_EFFECT_Draw(char *a)
{
    SHINKA_DEMO_EFFECT_DrawNodes((EffectModel *)((struct Anim *)a));
    SHINKA_DEMO_EFFECT_DrawParticle((int)((EffectModel *)a)->ptc);
}

void SHINKA_DEMO_EFFECT_Trigger(char *a)
{
    SHINKA_DEMO_EFFECT_SetParticleTimer((char *)(((EffectModel *)a)->ptc), 0x1e);
    if (((EffectModel *)a)->state == 1)
        ((EffectModel *)a)->state = 2;
}

/*
 * Move the ov195 scene object to state 1 with a 0x26c timer.  Labelled leaf.
 */
void SHINKA_DEMO_EFFECT_StartIntro(int *p)
{
    void SHINKA_DEMO_EFFECT_SetParticleActive(char *p);

    SHINKA_DEMO_EFFECT_SetParticleActive((char *)p[4]);
    p[2] = 1;
    p[3] = 0x26c;
}

/*
 * Flag bump on the ov195 scene object (+8 == 1 -> 2); unlabelled leaf.
 */
void SHINKA_DEMO_EFFECT_AdvanceState(int *p)
{
    if (p[2] == 1)
        p[2] = 2;
}

/*
 * True when the ov195 scene object's +8 state is 4; unlabelled leaf.
 */
int SHINKA_DEMO_EFFECT_IsState4(int *p)
{
    if (p[2] == 4)
        return 1;
    return 0;
}

/*
 * Camera-state predicate on the ov195 scene object's +8/+0xc words:
 * state 4 with +0xc <= 1, or state 5.  Unlabelled leaf.
 */
int SHINKA_DEMO_EFFECT_IsCameraReady(int *p)
{
    if (p[2] == 4 && (unsigned)p[3] <= 1)
        return 1;
    if (p[2] == 5)
        return 1;
    return 0;
}

/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   call at +0xD8 to the unlabelled ARM leaf 0x02051B04, closed when that
 *   leaf was seeded in layout/function_starts.txt and matched
 *   (src/matched/BUTTON_MAN_GetResourceType.c); all 13 relocations resolve.
 */
Ptc *SHINKA_DEMO_EFFECT_CreateParticle(u16 heap, u16 a, void *b)
{
    VecFx32 v1 = d_02208F24;
    VecFx32 v2 = d_02208F30;
    VecFx32 v3 = {0, 0, 0};
    EmitParam prm;
    Ptc *p;
    u32 res;

    prm.f00 = 0;
    prm.f04 = FX_SinCosTable_[0xe3 * 2];
    prm.f08 = FX_SinCosTable_[0xe3 * 2 + 1];
    prm.f0c = 0x1555;
    prm.f10 = 0;
    prm.f14 = 0x1000;
    prm.f18 = 0x400000;
    prm.f1c = 0;

    p = GFL_HEAP_Alloc(heap, sizeof(Ptc), 1, d_02208F7C, 0x2e5);
    p->f00 = 0;
    p->f02 = 0;
    p->f04 = a;
    p->f08 = b;
    p->f4814 = 0;
    p->f4818 = -1;
    PARTICLE_InitManager(heap);
    p->spl = PARTICLE_CreateSystem((u32)p->work, sizeof(p->work), 1, 5, 6, 0x3b, heap);
    PARTICLE_ReleaseCamera((int)p->spl);
    PARTICLE_InitCamera(p->spl, (struct Src648 *)(&prm), 0x2000, (int *)(&v1), (int *)(&v2), (int *)(&v3), heap);
    res = PARTICLE_LoadArchiveMember(d_02208E9C[0], d_02208E9C[1], heap);
    p->f4810 = BUTTON_MAN_GetResourceType((void *)res);
    PARTICLE_SetupSystem(p->spl, res, 1, 0);
    return p;
}

void SHINKA_DEMO_EFFECT_DeleteParticle(char *a)
{
    PARTICLE_ExitManager();
    GFL_HEAP_Free(a);
}

void SHINKA_DEMO_EFFECT_UpdateParticle(EffectParticle *p)
{
    if (p->active != 0) {
        VecFx32 v = {0, 0, 0};
        Cue *c;

        for (; p->cue < p->ncue; p->cue++) {
            if (p->frame != p->cues[(int)p->cue].frame)
                break;
            c = &p->cues[p->cue];
            PARTICLE_StartEffect(p->emit[c->emit].spl, c->id, (int)(&v));
        }
        p->frame++;
    }
    if (p->timer >= 0) {
        if (p->timer == 0)
            PARTICLE_KillAllEffects(p->emit[0].spl);
        p->timer--;
    }
}

void SHINKA_DEMO_EFFECT_DrawParticle(int a0){PARTICLE_Main();}

void SHINKA_DEMO_EFFECT_SetParticleActive(char *p){((EffectParticle *)p)->active=1;}

void SHINKA_DEMO_EFFECT_SetParticleTimer(char *p,u32 v) { ((EffectParticle *)p)->active=0; ((EffectParticle *)p)->timer=v; }

void SHINKA_DEMO_EFFECT_SetParticleTimerRaw(EffectParticle *p, s32 timer)
{
    p->timer = timer;
}

void SHINKA_DEMO_EFFECT_InitUnit(char *a)
{
    *(int *)&((EffectModel *)a)->res = G3D_UTIL_Create(4, 1, ((EffectModel *)a)->heap);
    ((EffectModel *)a)->count = 0;
}

void SHINKA_DEMO_EFFECT_DeleteUnit(char *p) { G3D_UTIL_Delete(*(struct Rec * *)&((EffectModel *)p)->res); }

void SHINKA_DEMO_EFFECT_DrawNodes(EffectModel *p) { u16 i; EffectNode *n; for(i=0;i<p->count;i++) { n=p->nodes+i; if(n->f40) G3D_SYSTEM_DrawObject((void *)func_02048A18(p->res,n->id),(struct Arg *)((struct Transform *)&n->tx)); } }

/*
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   two calls to the unlabelled ARM leaf 0x0204784C (sites +0x8E, +0x98),
 *   closed when that leaf was seeded in layout/function_starts.txt and
 *   matched (src/matched/G3D_SYSTEM_SetObjectAnimeFrame.c); all 11 relocations resolve.
 */
void SHINKA_DEMO_EFFECT_SetupNode(EffectModel *p)
{
    u32 x;
    void *q;
    u16 i;
    EffectNode *n;
    u16 id;

    p->f18 = G3D_UTIL_AddUnit(p->res, d_02208EC0);
    p->count = 1;
    p->nodes = (EffectNode *)SHINKA_DEMO_EFFECT_CreateNodes(p->heap, p->count);
    id = G3D_UTIL_GetUnitObjIdx(p->res, p->f18);
    n = p->nodes;
    p->f1a = 0;
    n->id = id;
    n->tx = 0;
    n->ty = 0;
    n->tz = 0;
    n->f40 = 1;
    for (i = 0; i < p->count; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->res, p->nodes[i].id), 0);
    p->f24 = 0;
    q = (void *)func_02048A18(p->res, p->nodes[p->f1a].id);
    x = 0;
    p->animeState = 0;
    G3D_SYSTEM_EnableObjectAnime(q, 1);
    G3D_SYSTEM_EnableObjectAnime(q, 2);
    G3D_SYSTEM_SetObjectAnimeFrame(q, 1, (s32 *)(&x));
    G3D_SYSTEM_SetObjectAnimeFrame(q, 2, (s32 *)(&x));
}

void SHINKA_DEMO_EFFECT_RemoveUnit(char *a)
{
    G3D_UTIL_RemoveUnit((struct Ctx *)(*(int *)&((EffectModel *)a)->res), ((EffectModel *)a)->f18);
    SHINKA_DEMO_EFFECT_FreeNode((void *)(((EffectModel *)a)->nodes));
    ((EffectModel *)a)->count = 0;
}

/*
 * blocker resolved: 0x02047910 and 0x020478B8 were matched in arm9
 *           (src/matched/G3D_SYSTEM_LoopObjectAnimeFrame.c, src/matched/G3D_SYSTEM_IncObjectAnimeFrame.c;
 *           shards pkt_02047910 and pkt_020478B8), so their call sites now
 *           attest as `matched`.  0x02048A18 already resolved via matched;
 *           all 164 bytes are correct.
 */
void SHINKA_DEMO_EFFECT_UpdateAnime(char *p)
{
    unsigned short i;
    int j = 0;
    int v2;

    for (i = 0; i < ((EffectModel *)p)->count; i++) {
        unsigned short v = *(unsigned short *)((u8 *)((EffectModel *)p)->nodes + i * 0x44);
        int x = func_02048A18((u8 *)(((EffectModel *)p)->res), v);

        G3D_SYSTEM_LoopObjectAnimeFrame((void *)x, j, 0x1000);
    }
    ((EffectModel *)p)->f24 = ((EffectModel *)p)->f24 + 1;
    v2 = func_02048A18((u8 *)(((EffectModel *)p)->res),
                       *(unsigned short *)((u8 *)((EffectModel *)p)->nodes +
                                           ((EffectModel *)p)->f1a * 0x44));
    if (((EffectModel *)p)->animeState == 1) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, 0x5000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, 0x5000);

        if (a == 0 && b == 0)
            ((EffectModel *)p)->animeState = 2;
    } else if (((EffectModel *)p)->animeState == 3) {
        int a = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 1, -0x2000);
        int b = G3D_SYSTEM_IncObjectAnimeFrame((void *)v2, 2, -0x2000);

        if (a == 0 && b == 0)
            ((EffectModel *)p)->animeState = 0;
    }
}

void SHINKA_DEMO_EFFECT_AnimSetState1(EffectModel *p)
{
    p->animeState = 1;
}

int SHINKA_DEMO_EFFECT_AnimIsState2(EffectModel *p)
{
    if (p->animeState == 2)
        return 1;
    return 0;
}

void SHINKA_DEMO_EFFECT_AnimSetState3(EffectModel *p)
{
    p->animeState = 3;
}

int SHINKA_DEMO_EFFECT_AnimIsState0(EffectModel *p)
{
    if (p->animeState == 0)
        return 1;
    return 0;
}
