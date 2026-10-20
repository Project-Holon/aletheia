#ifndef GAME_ARM9_PARTICLE_H
#define GAME_ARM9_PARTICLE_H

/* Public functions of particle.c, prototypes copied from their definitions. */

struct ParticleSys;
struct TaskNode;
struct ParticleCameraParams;
struct Obj3D;

#include "../types.h"
#include "../arm9/billboard_act_shared_types.h"
#include "../arm9/billboard_act_shared_types.h"
#include "../arm9/billboard_act_shared_types.h"

void PARTICLE_InitManager(u32 heapId);
void PARTICLE_Main(void);
struct ParticleSys *PARTICLE_CreateSystemDefault(u32 workBuf, u32 workSize, u32 withCamera, u32 heapId);
struct ParticleSys *PARTICLE_CreateSystem(u32 workBuf, u32 workSize, u32 withCamera, u32 limitA, u32 limitB, u32 maxResIndex, u32 heapId);
void PARTICLE_DeleteSystem(struct ParticleSys *sys);
void PARTICLE_ExitManager(void);
void *PARTICLE_AllocWorkSlot0(u32 size);
void *PARTICLE_AllocWorkSlot1(u32 size);
void *PARTICLE_AllocWorkSlot2(u32 size);
void *PARTICLE_AllocWorkSlot3(u32 size);
void *PARTICLE_AllocWorkSlot4(u32 size);
void *PARTICLE_AllocWorkSlot5(u32 size);
void *PARTICLE_AllocWorkSlot6(u32 size);
void *PARTICLE_AllocWorkSlot7(u32 size);
void *PARTICLE_AllocWorkSlot8(u32 size);
void *PARTICLE_AllocWorkSlot9(u32 size);
void *PARTICLE_AllocWorkSlot10(u32 size);
void *PARTICLE_AllocWorkSlot11(u32 size);
void *PARTICLE_AllocWorkSlot12(u32 size);
void *PARTICLE_AllocWorkSlot13(u32 size);
void *PARTICLE_AllocWorkSlot14(u32 size);
void *PARTICLE_AllocWorkSlot15(u32 size);
void *PARTICLE_LoadArchiveMember(u32 archiveId, u32 member, u32 heapId);
void PARTICLE_SetupSystem(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr);
void PARTICLE_SetupSystemBorrowed(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr);
void PARTICLE_SetupSystemNoHandlers(struct ParticleSys *sys, void *block);
void PARTICLE_ApplyLoadHandlers(struct ParticleSys *sys);
void PARTICLE_ApplyLoadHandlersTask(struct TaskNode *task, struct ParticleSys *sys);
void PARTICLE_DrawSystem(struct ParticleSys *sys);
int PARTICLE_UpdateSystem(struct ParticleSys *sys);
int PARTICLE_CountSystems(void);
int PARTICLE_DrawAllSystems(void);
int PARTICLE_UpdateAllSystems(void);
int PARTICLE_StartEffect(struct ParticleSys *sys, int resId, int arg);
int PARTICLE_StartEffectWithCallback(struct ParticleSys *sys, int resId, void (*callback)(void *), int userArg);
int PARTICLE_GetEffectCount(struct ParticleSys *sys);
void PARTICLE_KillAllEffects(struct ParticleSys *sys);
void PARTICLE_KillEffect(struct ParticleSys *sys, void *effect);
void *PARTICLE_GetWorkBase(struct ParticleSys *sys);
void PARTICLE_InitCamera(struct ParticleSys *sys, struct ParticleCameraParams *params, u16 angle, Vec3 *pos, Vec3 *target, Vec3 *up, u32 heapId);
int PARTICLE_ReleaseCamera(struct ParticleSys *sys);
u32 PARTICLE_GetCallbackArg(void);
int PARTICLE_EMITTER_GetBlock(struct Obj3D *p);
void PARTICLE_EMITTER_GetPos(struct Obj3D *p, Vec3 *out);
void PARTICLE_EMITTER_SetPos(struct Obj3D *p, const Vec3 *v);
int PARTICLE_EMITTER_GetScaleX(struct Obj3D *p);
void PARTICLE_EMITTER_SetScaleX(struct Obj3D *p, int v);
int PARTICLE_EMITTER_GetScaleY(struct Obj3D *p);
void PARTICLE_EMITTER_SetScaleY(struct Obj3D *p, int v);
short PARTICLE_EMITTER_GetOffsetX(struct Obj3D *p);
void PARTICLE_EMITTER_SetOffsetX(struct Obj3D *p, int v);
short PARTICLE_EMITTER_GetOffsetY(struct Obj3D *p);
void PARTICLE_EMITTER_SetOffsetY(struct Obj3D *p, int v);
short PARTICLE_EMITTER_GetAngle(struct Obj3D *p);
unsigned short PARTICLE_EMITTER_GetAlpha(struct Obj3D *p);
void PARTICLE_EMITTER_SetEmitPos(struct Obj3D *e, const Vec3 *q);
void PARTICLE_EMITTER_SetAngle(struct Obj3D *o, u32 v);
void PARTICLE_EMITTER_SetAlpha(struct Obj3D *o, u16 v);
void *PARTICLE_EMITTER_FindBehaviorData(struct Obj3D *obj, int kind);
void PARTICLE_EMITTER_SetBehavior2Data(struct Obj3D *p, Vec3 *q);
void PARTICLE_EMITTER_SetBehavior3Half(struct Obj3D *p, u16 *q);
void PARTICLE_EMITTER_SetBehavior5Data(struct Obj3D *p, Vec3 *q);
void PARTICLE_EMITTER_SetCallback(struct Obj3D *p, int v);
void PARTICLE_EMITTER_SetUserData(struct Obj3D *p, int v);
int PARTICLE_EMITTER_GetUserData(struct Obj3D *p);
unsigned int PARTICLE_AllocTexVramOffset(int szByte, int is4x4comp, int unused2, int unused3);
u32 PARTICLE_AllocTexVramTracked(u32 szByte, u32 is4x4comp);
int PARTICLE_AllocVramOffset(int a, int b);
u32 PARTICLE_AllocPlttVramTracked(u32 a, u32 b);
u16 PARTICLE_RESOURCE_GetType(void *res);
int G2_GetBGCharPtrById(int i);

#endif
