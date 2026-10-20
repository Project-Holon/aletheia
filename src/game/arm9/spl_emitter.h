#ifndef GAME_ARM9_SPL_EMITTER_H
#define GAME_ARM9_SPL_EMITTER_H

/* Public functions of spl_emitter.c, prototypes copied from their definitions. */

struct SPLList;
struct SPLNode;
struct RandomVecRange;
struct RandomVecSource;
struct ScaledVecSource;
struct RigOffsetPair;
struct AxisAngleKey;
struct InterpTargetParam;
struct InterpTrack;
struct InterpState;
struct LerpSource;
struct LerpDest;
struct SPLParticle;
struct SPLResource;
struct SPLEmitter;
struct SPLParticleList;
struct RigObject;
struct RenderNode;
struct SPLManager;
struct SPLTexture;
struct ResourceSetup;
struct SplEmitterCfg;
struct VramTexHeap;
struct VramHeapHeader;
struct VramFreeList;
struct VramHeapHead;
typedef struct SPLList SPLList;
typedef struct SPLNode SPLNode;
typedef struct SPLParticle SPLParticle;
typedef struct SPLResource SPLResource;
typedef struct SPLEmitter SPLEmitter;
typedef struct SPLParticleList SPLParticleList;
typedef struct SPLManager SPLManager;
typedef struct SPLTexture SPLTexture;

#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

void SPLList_PushFront(SPLList *list, SPLNode *node);
SPLNode *SPLList_PopFront(SPLList *list);
SPLNode *SPLList_Erase(SPLList *list, SPLNode *node);
void SPL_EMITTER_AddVec(struct RandomVecRange *o, void *s, int *dst);
void SPL_EMITTER_UpdateNode(struct RandomVecRange *o, struct RandomVecSource *s, int *dst);
void SPL_EMITTER_AddScaledVec(struct ScaledVecSource *a, struct RigOffsetPair *b, volatile int *c);
void SPL_EMITTER_BuildFrame(struct AxisAngleKey *o, u8 *dst);
void SPL_EMITTER_InterpTarget(struct InterpTargetParam *a, struct InterpTrack *s, int unused, struct InterpState *c);
void SPL_EMITTER_LerpVec(struct LerpSource *a, struct LerpDest *b);
void SPLAnim_Scale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Color(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Alpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_Texture(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_ChildScale(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLAnim_ChildAlpha(SPLParticle *ptcl, SPLResource *res, int lifeRate);
void SPLEmitter_ComputeOrthogonalAxes(SPLEmitter *emtr);
void SPLUtil_TiltCoordinates(VecFx32 *out, const VecFx32 *src, const SPLEmitter *emtr);
void SPLEmitter_EmitParticles(SPLEmitter *emtr, SPLParticleList *list);
void SPLEmitter_EmitChildren(SPLParticle *ptcl, SPLEmitter *emtr, SPLParticleList *list);
void SPLUtil_DrawXYPlane(s32 s, s32 t, s32 x, s32 y);
void SPLUtil_DrawXZPlane(s32 s, s32 t, s32 x, s32 z);
void SPL_EMITTER_CalcRotMtx(s32 sn, s32 cs, MtxFx43 *m);
void SPL_EMITTER_SetRotMtx(s32 sn, s32 cs, MtxFx43 *m);
void SPL_EMITTER_UpdateFrame(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameEx(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateParticleMotion(SPLManager *mgr, SPLParticle *ptcl);
void SPL_EMITTER_UpdateParticleMotionEx(SPLManager *mgr, SPLParticle *ptcl);
void SPL_EMITTER_UpdateFrameA68(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameA68Ex(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameMain(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_UpdateFrameMainEx(struct RigObject *obj, struct RenderNode *s);
void SPL_EMITTER_SetTextureParam(SPLTexture *tex);
void SPL_EMITTER_Noop(SPLTexture *tex);
void SPL_EMITTER_SetupResource(volatile struct ResourceSetup *o, struct SplEmitterCfg *cfg, const VecFx32 *pos);
void SPL_EMITTER_UpdateParticles(SPLManager *mgr, SPLEmitter *emtr);
void SPL_EMITTER_UpdateSubB(struct RigObject *o);
void SPL_EMITTER_UpdateSubX(struct RigObject *o);
void SPL_EMITTER_UpdateSubC(struct RigObject *o);
int SPL_EMITTER_AllocTexVram(u32 szByte, u32 is4x4comp);
int SPL_EMITTER_AllocPlttVram(u32 szByte, u32 is4pltt);
void SPL_EMITTER_FreeNodeToHeap(struct VramTexHeap *h, struct VramHeapHeader *d);
void SPL_EMITTER_AllocTexVramDefault(u32 rigObject);
void SPL_EMITTER_AllocPlttVramDefault(u32 rigObject);
void SPL_EMITTER_FreeTexNode(struct VramFreeList *h);
void SPL_EMITTER_FreeNodeHeap(struct VramHeapHead *h, u32 a);
int SPL_EMITTER_AllocResource(char *p, int b, int c);
int SPL_EMITTER_AllocResourceEx(char *p, int b, void (*fn)(void *));
void SPL_EMITTER_FreeResource(char *p, char *q);
void SPL_EMITTER_FreeResourceList(void *p);

#endif
