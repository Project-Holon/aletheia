/*
 * file:     fld_particle.c
 * unit:     yes
 * function: FLD_PARTICLE_Create, FLD_PARTICLE_CreateEffect, FLD_PARTICLE_DeleteEffect, FLD_PARTICLE_LoadResource, FLD_PARTICLE_StartEmitter, FLD_PARTICLE_IsEffectFinished, FLD_PARTICLE_Delete, FLD_PARTICLE_Exit
 * address:  0x021C1A08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_player_grid_event.c, fld3d_ci.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   PARTICLE_InitManager  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   PARTICLE_ExitManager  0x02050ED4  arm
 *   PARTICLE_Main  0x02050BE8  arm
 *   PARTICLE_CreateSystemDefault  0x02050C04  arm  arm9
 *   PARTICLE_LoadArchiveMember  0x0205121C  arm  arm9
 *   PARTICLE_GetEffectCount  0x02051614  arm  arm9
 *   PARTICLE_EMITTER_GetBlock  0x02051788  arm  arm9
 *   G3D_CAMERA_SetFar            0x02048B6C  arm
 *   G3D_CAMERA_SetNear           0x02048B60  arm
 */
#include "fld3d_ci_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/particle.h"
struct ParticleSys;

struct Obj3D;

struct G3dCamera;

#include "../arm9/g3d_camera.h"









FldParticle *FLD_PARTICLE_Create(u32 heapId);

struct ParticleSys *FLD_PARTICLE_CreateEffect(FldParticle *particle);

void FLD_PARTICLE_DeleteEffect(FldParticle *particle);

void *FLD_PARTICLE_LoadResource(FldParticle *particle, int kind, int resourceId);

void FLD_PARTICLE_StartEmitter(FldParticle *particle, void *resource, u32 applyNow, u32 taskMgr);

int FLD_PARTICLE_IsEffectFinished(FldParticle *particle);

u32 FLD_PARTICLE_Delete(FldParticle *particle);

void FLD_PARTICLE_Exit(void);

extern u8 d_021DE3C8;

FldParticle *FLD_PARTICLE_Create(u32 heapId)
{
    FldParticle *particle;

    particle = GFL_HEAP_Alloc(heapId, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    particle->heapId = heapId;
    PARTICLE_InitManager(heapId);
    particle->workBuffer = GFL_HEAP_Alloc(heapId, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return particle;
}

/*
 * Creates the effect instance and sets its two scale parameters.
 */
struct ParticleSys *FLD_PARTICLE_CreateEffect(FldParticle *particle)
{
    u32 effectScale;
    u32 effectRange;
    struct G3dCamera *effect;

    particle->effect = PARTICLE_CreateSystemDefault((sptr)particle->workBuffer, 0x4800, 1, particle->heapId);
    effect = (struct G3dCamera *)PARTICLE_EMITTER_GetBlock((struct Obj3D *)particle->effect);
    effectScale = 1 << 12;
    effectRange = 0x384000;
    G3D_CAMERA_SetNear(effect, &effectScale);
    G3D_CAMERA_SetFar(effect, &effectRange);
    return particle->effect;
}

void FLD_PARTICLE_DeleteEffect(FldParticle *particle)
{
    struct ParticleSys *effect = particle->effect;
    if (effect != 0) {
        PARTICLE_DeleteSystem(effect);
        particle->effect = 0;
    }
}

/*
 * Loads a resource with the owner's heap id (tail call).
 */
void *FLD_PARTICLE_LoadResource(FldParticle *particle, int kind, int resourceId)
{
    return (void *)PARTICLE_LoadArchiveMember(kind, resourceId, particle->heapId);
}

void FLD_PARTICLE_StartEmitter(FldParticle *particle, void *resource, u32 applyNow, u32 taskMgr)
{
    PARTICLE_SetupSystem(particle->effect, resource, applyNow, taskMgr);
}

/* Returns 1 when the effect is gone or finished. */
int FLD_PARTICLE_IsEffectFinished(FldParticle *particle)
{
    if (particle->effect == 0)
        return 1;
    if (PARTICLE_GetEffectCount(particle->effect) == 0)
        return 1;
    return 0;
}

u32 FLD_PARTICLE_Delete(FldParticle *particle)
{
    FLD_PARTICLE_DeleteEffect(particle);
    PARTICLE_ExitManager();
    GFL_HEAP_Free(particle->workBuffer);
    return GFL_HEAP_Free(particle);
}

/*
 * Tail-call thunk: forwards to PARTICLE_Main with no argument change.
 */
void FLD_PARTICLE_Exit(void)
{
    PARTICLE_Main();
}
