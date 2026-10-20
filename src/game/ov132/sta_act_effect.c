/*
 * file:     sta_act_effect.c
 * unit:     yes
 * function: STA_ACTING_SetCameraHoldScript, STA_ACTING_GetElapsedTicks, STA_ACT_EFFECT_Noop, STA_ACT_EFFECT_Create, STA_ACT_EFFECT_Delete, STA_ACT_EFFECT_Update, STA_ACT_EFFECT_Draw, STA_ACT_EFFECT_StartSystem, STA_ACT_EFFECT_KillSystem, STA_ACT_EFFECT_StartEffect, STA_ACT_EFFECT_KillEffect, STA_ACT_EFFECT_SetEmitterPos
 * address:  0x021F9E40
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   STA_ACT_EFFECT_Delete 0x021F9E94 thumb ov132
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACT_EFFECT_Update 0x021F9ECC thumb ov132
 *   STA_ACT_EFFECT_Draw 0x021F9ED4 thumb ov132
 *   STA_ACT_EFFECT_Create 0x021F9E50 thumb ov132
 *   STA_ACT_EFFECT_StartSystem  0x021F9EDC  thumb
 *   STA_ACT_EFFECT_KillSystem  0x021F9F58  thumb
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   PARTICLE_InitManager 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillEffect  0x02051630  arm
 *   PARTICLE_EMITTER_SetEmitPos  0x02051838  arm
 */
#include "ov132_types.h"
#include "sta_acting_shared_types.h"
#include "sta_act_effect_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/particle.h"




struct ParticleSys;


struct TcbList;

#include "../arm9/gfl_use.h"







void STA_ACTING_SetCameraHoldScript(u8 *p,u32 v);

u32 STA_ACTING_GetElapsedTicks(u8 *p);

void STA_ACTING_SetCameraHoldScript(u8 *p,u32 hold) { ((struct ActingScene *)p)->cameraHoldScript=hold; }

u32 STA_ACTING_GetElapsedTicks(u8 *p) { return ((struct ActingScene *)p)->elapsedTicks; }

void STA_ACT_EFFECT_Noop(u8 *scene) { }

char *STA_ACT_EFFECT_Create(unsigned heap);

void STA_ACT_EFFECT_Delete(u8 *p);

int STA_ACT_EFFECT_Update(u8 *manager);

int STA_ACT_EFFECT_Draw(u8 *manager);

char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);

void STA_ACT_EFFECT_KillSystem(u8 *unused,u8 *p);

void STA_ACT_EFFECT_StartEffect(char *p, unsigned i, StaActingVec *v);

void STA_ACT_EFFECT_KillEffect(char *p, int i);

void STA_ACT_EFFECT_SetEmitterPos(char *p, int i, int a);

extern const char d_021FDCB0[];

char *STA_ACT_EFFECT_Create(unsigned heap)
{
    u8 i = 0;
    char *p = GFL_HEAP_Alloc(heap, 0x24244, 0, d_021FDCB0, 76);
    ((ActEffectManager *)p)->heapId = heap;
    PARTICLE_InitManager(heap);
    for (; i < 8; i++)
        *(int *)(p + i * 0x4848 + 4) = 0;
    return p;
}

/*
 * lever: the load uses p+index*0x4848+4, while the outgoing pointer uses p+4+index*0x4848; the latter keeps p+4 hoisted in r6. Using the load's grouping for both gave 49 concrete byte differences.
 */
void STA_ACT_EFFECT_Delete(u8 *p) { u8 i; for(i=0;i<8;i++) { if(*(u32 *)(p+i*0x4848+4)==1) STA_ACT_EFFECT_KillSystem(p,p+4+i*0x4848); } PARTICLE_ExitManager(); GFL_HEAP_Free(p); }

int STA_ACT_EFFECT_Update(u8 *manager) { return PARTICLE_UpdateAllSystems(); }

int STA_ACT_EFFECT_Draw(u8 *manager) { return PARTICLE_DrawAllSystems(); }

char *STA_ACT_EFFECT_StartSystem(char *p, u32 memberIndex)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    ((ActEffectSystem *)q)->system.p = (void *)PARTICLE_CreateSystemDefault((sptr)(q + 4), 0x4800, 0, ((ActEffectManager *)p)->heapId);
    v = (void *)PARTICLE_LoadArchiveMember(47, memberIndex, ((ActEffectManager *)p)->heapId);
    PARTICLE_SetupSystem(((ActEffectSystem *)q)->system.p, v, 0, (uptr)GFL_USE_GetMainTaskList());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    ((ActEffectSystem *)q)->active.s = 1;
    return q;
}

void STA_ACT_EFFECT_KillSystem(u8 *unused,u8 *p) { ((ActEffectSystem *)p)->active.u=0; PARTICLE_KillAllEffects((struct ParticleSys *)(((ActEffectSystem *)p)->system.u)); PARTICLE_DeleteSystem((struct ParticleSys *)(((ActEffectSystem *)p)->system.u)); }

static inline void set(StaActingVec *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}

/*
 * lever: Non-const StaActingVec source preserves alias dependence: inline setter
 * arguments load z, y, x after the handle store and before vector stores.
 * const int * and const StaActingVec * sources both gave DIFF, 19 concrete bytes.
 */
void STA_ACT_EFFECT_StartEffect(char *p, unsigned index, StaActingVec *pos)
{
    int a = PARTICLE_StartEffect(((ActEffectSystem *)p)->system.p, index, (sptr)pos);
    if (a == 0 || index < 4) {
        ((ActEffectSystem *)p)->part[index].a = a;
        set(&((ActEffectSystem *)p)->part[index].v, pos->x, pos->y, pos->z);
    }
}

/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x02051630 now has an
 * EXACT arm9 shard entry (pkt_02051630), so the blx at +0012 resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void STA_ACT_EFFECT_KillEffect(char *p, int index)
{
    int v = *(int *)(p + index * 16 + 0x4808);

    if (v != 0)
        PARTICLE_KillEffect(((ActEffectSystem *)p)->system.p, (void *)v);
}

/*
 * Addresses are Black-image addresses.
 */
void STA_ACT_EFFECT_SetEmitterPos(char *p, int index, int position)
{
    void *v = *(void **)(p + index * 16 + 0x4808);

    if (v != 0)
        PARTICLE_EMITTER_SetEmitPos((struct Obj3D *)v, (const Vec3 *)position);
}
