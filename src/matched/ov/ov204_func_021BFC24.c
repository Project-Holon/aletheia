/*
 * function: INTRO_PARTICLE_Create
 * address: 0x021BFC24
 * packet: pkt_ov204_021BFC24
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_InitManager 0x02050B80 arm
 *   func_02030734 0x02030734 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021C0B30 0x021C0B30 data a1
 *   d_021C0B18 0x021C0B18 data a4
 *   d_021C0B0C 0x021C0B0C data a4
 *   d_021C0B24 0x021C0B24 data a4
 *   gIntroSite  0x021C0AE4  data
 */
#include "../include/Obj03923.h"
typedef unsigned short u16;
typedef struct { int a,b,c,d,e,f,g,h; } Config;
extern void PARTICLE_InitManager(unsigned);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *gIntroSite, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_ReleaseCamera(int a0);
struct Dst648;
struct Src648;
extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);
extern void PARTICLE_SetupSystem(void *,unsigned,unsigned,unsigned);
extern const char d_021C0B30[];
extern int d_021C0B18[];
extern int d_021C0B0C[],d_021C0B24[];
char *INTRO_PARTICLE_Create(void *owner,unsigned heap)
{
    Config config;
    char *p;
    PARTICLE_InitManager(heap);
    p=func_02030734(heap,18444,1,d_021C0B30,86);
    ((struct Obj03923 *)p)->f8=(void *)PARTICLE_CreateSystemDefault((int)(p+12),18432,1,heap);
    ((struct Obj03923 *)p)->f4=owner;
    ((struct Obj03923 *)p)->f0=heap;
    config.a=2;
    config.b=16384;
    config.c=-16384;
    config.d=-12288;
    config.e=12288;
    config.f=4096;
    config.g=4194304;
    config.h=4096;
    PARTICLE_ReleaseCamera((int)(((struct Obj03923 *)p)->f8));
    PARTICLE_InitCamera(((struct Obj03923 *)p)->f8,(struct Src648 *)(&config),8192,d_021C0B18,d_021C0B0C,d_021C0B24,((struct Obj03923 *)p)->f0);
    PARTICLE_SetupSystem(((struct Obj03923 *)p)->f8,PARTICLE_LoadArchiveMember(6,6,((struct Obj03923 *)p)->f0),1,0);
    return p;
}
