/*
 * function: EGG_DEMO_VIEW_CreateParticles
 * address: 0x021F6DB4
 * packet: pkt_ov215_021F6DB4
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7300 0x021F7300 data a4
 */
#include "../include/Obj03373.h"
typedef unsigned short u16;
struct Pair { unsigned archive,member; };
extern const char d_021F73F4[];
extern const unsigned long long d_021F7300;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void PARTICLE_InitManager(unsigned);
extern int PARTICLE_CreateSystemDefault(int,int,int,int);
extern int PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);
extern u16 BUTTON_MAN_GetResourceType(void *);
extern void PARTICLE_SetupSystem(void *,unsigned,unsigned,unsigned);
char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table)
{
    char *p;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    p=func_02030734(heap,0x481C,1,d_021F73F4,0x502);
    ((struct Obj03373 *)p)->f0=0;
    ((struct Obj03373 *)p)->f2=0;
    ((struct Obj03373 *)p)->f4=count;
    *(const void * *)&((struct Obj03373 *)p)->f8=table;
    ((struct Obj03373 *)p)->f4814=0;
    ((struct Obj03373 *)p)->f4818=-1;
    PARTICLE_InitManager(heap);
    *(int *)&((struct Obj03373 *)p)->f480C=PARTICLE_CreateSystemDefault((int)(p+12),0x4800,1,heap);
    config=d_021F7300;
    resource=PARTICLE_LoadArchiveMember((unsigned)config,(unsigned)(config>>32),heap);
    ((struct Obj03373 *)p)->f4810=BUTTON_MAN_GetResourceType((void *)resource);
    PARTICLE_SetupSystem(((struct Obj03373 *)p)->f480C,resource,1,0);
    return p;
}
