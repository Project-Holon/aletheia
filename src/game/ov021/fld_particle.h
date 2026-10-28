#ifndef GAME_OV021_FLD_PARTICLE_H
#define GAME_OV021_FLD_PARTICLE_H
struct TcbList;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_particle.c, prototypes copied from their definitions. */

struct ParticleSys;

#include "../ov021/fld3d_ci_types.h"
#include "../types.h"

FldParticle *FLD_PARTICLE_Create(u32 heapId);
struct ParticleSys *FLD_PARTICLE_CreateEffect(FldParticle *particle);
void FLD_PARTICLE_DeleteEffect(FldParticle *particle);
void *FLD_PARTICLE_LoadResource(FldParticle *particle, int kind, int resourceId);
void FLD_PARTICLE_StartEmitter(FldParticle *particle, void *resource, u32 applyNow, struct TcbList *taskMgr);
int FLD_PARTICLE_IsEffectFinished(FldParticle *particle);
u32 FLD_PARTICLE_Delete(FldParticle *particle);
void FLD_PARTICLE_Exit(void);
/* END mkheaders: generated region */

#endif
