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
 *   BUTTON_MAN_GetBlock  0x02051788  arm  arm9
 */
#include "fld3d_ci_types.h"

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern void PARTICLE_InitManager(u32);

extern void *PARTICLE_CreateSystemDefault(int a, int b, int c, int d);

extern void *BUTTON_MAN_GetBlock(void *effect);

extern void G3D_CAMERA_SetNear(void *effect, const u32 *in);

extern void G3D_CAMERA_SetFar(void *effect, const u32 *in);

extern void PARTICLE_DeleteSystem(void *effect);

extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);

extern u32 PARTICLE_SetupSystem(u32, u32, u32, u32);

extern int PARTICLE_GetEffectCount(int **p);

extern u32 GFL_HEAP_Free(void *p);

extern void PARTICLE_ExitManager(void);

extern void PARTICLE_Main();

FldParticle *FLD_PARTICLE_Create(u32 heapId);

void *FLD_PARTICLE_CreateEffect(FldParticle *particle);

void FLD_PARTICLE_DeleteEffect(FldParticle *particle);

void *FLD_PARTICLE_LoadResource(FldParticle *particle, int kind, int resourceId);

int FLD_PARTICLE_StartEmitter(FldParticle *particle, u32 resource, u32 arg0, u32 arg1);

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
void *FLD_PARTICLE_CreateEffect(FldParticle *particle)
{
    u32 effectScale;
    u32 effectRange;
    void *effect;

    particle->effect = PARTICLE_CreateSystemDefault((int)particle->workBuffer, 0x4800, 1, particle->heapId);
    effect = BUTTON_MAN_GetBlock(particle->effect);
    effectScale = 1 << 12;
    effectRange = 0x384000;
    G3D_CAMERA_SetNear(effect, &effectScale);
    G3D_CAMERA_SetFar(effect, &effectRange);
    return particle->effect;
}

void FLD_PARTICLE_DeleteEffect(FldParticle *particle)
{
    void *effect = particle->effect;
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

int FLD_PARTICLE_StartEmitter(FldParticle *particle, u32 resource, u32 arg0, u32 arg1)
{
    return PARTICLE_SetupSystem((u32)particle->effect, resource, arg0, arg1);
}

/* Returns 1 when the effect is gone or finished. */
int FLD_PARTICLE_IsEffectFinished(FldParticle *particle)
{
    if (particle->effect == 0)
        return 1;
    if (PARTICLE_GetEffectCount((int **)particle->effect) == 0)
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
