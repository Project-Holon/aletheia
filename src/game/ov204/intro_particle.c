/*
 * file:     intro_particle.c
 * unit:     yes
 * function: INTRO_PARTICLE_Create, INTRO_PARTICLE_Delete, INTRO_PARTICLE_Main, INTRO_PARTICLE_StartEffect
 * address:  0x021BFC24
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_g3d.c by tools/splitfile.py.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021C0B30 0x021C0B30 data a1
 *   d_021C0B18 0x021C0B18 data a4
 *   d_021C0B0C 0x021C0B0C data a4
 *   d_021C0B24 0x021C0B24 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   PARTICLE_StartEffect  0x020515B4  arm
 */
#include "intro_types.h"

/* Opaque particle system (defined in arm9 particle.c). */
struct ParticleSys;

/*
 * Projection gIntroG3dUnitSetup for the particle camera. Mirrors arm9's
 * ParticleCameraParams (the record is not in a shared header).
 */
typedef struct IntroParticleCameraParams {
    u32 projType;
    u32 fovSin;
    u32 fovCos;
    u32 aspect;
    u32 orthoExtent;
    u32 nearZ;
    u32 farZ;
    u32 projScale;
} IntroParticleCameraParams;

/* One intro particle effect: 0x0C header plus the system's work buffer. */
typedef struct IntroParticleWork {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad_2[2];
    void *owner;                /* 0x04 */
    void *system;               /* 0x08 */
    unsigned char data[18432];  /* 0x0C: PARTICLE_CreateSystemDefault work */
} IntroParticleWork;

extern u32 func_020307B0(void *p);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void PARTICLE_InitManager(unsigned);

extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);

extern int PARTICLE_ReleaseCamera(int a0);

extern void PARTICLE_InitCamera(struct ParticleSys *sys, IntroParticleCameraParams *params, u16 a2, int *a3, int *a4, int *a5, u32 a6);

extern int PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);

extern void PARTICLE_SetupSystem(void *,unsigned,unsigned,unsigned);

extern void PARTICLE_ExitManager(void);

extern void PARTICLE_Main(void);

extern int PARTICLE_StartEffect(void *p, int b, int c);

char *INTRO_PARTICLE_Create(void *owner,unsigned heap);

void INTRO_PARTICLE_Delete(char *a);

void INTRO_PARTICLE_Main(int a0);

void INTRO_PARTICLE_StartEffect(u32 *a0, u32 a1, u32 a2, u32 a3);

extern const char d_021C0B30[];

extern int d_021C0B18[];

extern int d_021C0B0C[],d_021C0B24[];

char *INTRO_PARTICLE_Create(void *owner,unsigned heap)
{
    IntroParticleCameraParams config;
    IntroParticleWork *p;
    PARTICLE_InitManager(heap);
    p=func_02030734(heap,18444,1,d_021C0B30,86);
    p->system=(void *)PARTICLE_CreateSystemDefault((int)p->data,18432,1,heap);
    p->owner=owner;
    p->heapId=heap;
    config.projType=2;
    config.fovSin=16384;
    config.fovCos=-16384;
    config.aspect=-12288;
    config.orthoExtent=12288;
    config.nearZ=4096;
    config.farZ=4194304;
    config.projScale=4096;
    PARTICLE_ReleaseCamera((int)p->system);
    PARTICLE_InitCamera(p->system,&config,8192,d_021C0B18,d_021C0B0C,d_021C0B24,p->heapId);
    PARTICLE_SetupSystem(p->system,PARTICLE_LoadArchiveMember(6,6,p->heapId),1,0);
    return (char *)p;
}

void INTRO_PARTICLE_Delete(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}

void INTRO_PARTICLE_Main(int a0) { PARTICLE_Main(); }

void INTRO_PARTICLE_StartEffect(u32 *a0, u32 a1, u32 a2, u32 a3)
{
    u32 *p = a0;
    u32 buf[3] = { 0 };

    buf[0] = a1;
    buf[1] = a2;
    buf[2] = a3;
    PARTICLE_StartEffect((void *)p[2], 0, (int)buf);
    PARTICLE_StartEffect((void *)p[2], 1, (int)buf);
    PARTICLE_StartEffect((void *)p[2], 2, (int)buf);
}
