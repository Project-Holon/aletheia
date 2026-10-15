/*
 * function: POKETRADE_3D_InitParticleSystems
 * address: 0x021E2F34
 * packet: pkt_ov119_021E2F34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_InitManager 0x02050B80 arm
 *   func_02030734 0x02030734 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   gParticleBufferAllocTag 0x021E81C0 data a4
 */
#include "../include/Obj04480.h"
typedef unsigned short u16;
extern char gParticleBufferAllocTag[];
typedef unsigned int   u32;
extern void PARTICLE_InitManager(u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
void POKETRADE_3D_InitParticleSystems(char *p) {
    int i,flag;
    PARTICLE_InitManager(((struct Obj04480 *)p)->fBA);
    ((struct Obj04480 *)p)->fB4=0;
    for(i=0;i<9;i++) {
        ((void **)p)[9+i]=func_02030734(((struct Obj04480 *)p)->fBA,0x4800,1,gParticleBufferAllocTag,0x201);
        switch(i) {
        case 0: case 1: case 2: case 5: case 6: case 8: flag=0; break;
        case 3: case 4: case 7: default: flag=1; break;
        }
        ((void **)p)[i]=(void *)PARTICLE_CreateSystemDefault((int)(((void **)p)[9+i]),0x4800,flag,((struct Obj04480 *)p)->fBA);
    }
}
