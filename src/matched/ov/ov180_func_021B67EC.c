/*
 * function: HALL_OF_FAME_CreateBackdropParticle
 * address: 0x021B67EC
 * packet: pkt_ov180_021B67EC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 */
#include "../include/Obj14400.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void PARTICLE_SetupSystem(void *,void *,int,int);
void HALL_OF_FAME_CreateBackdropParticle(char *p){((struct Obj14400 *)p)->f2C=(void *)PARTICLE_CreateSystemDefault((int)(p+18480),18432,1,141);PARTICLE_SetupSystem(((struct Obj14400 *)p)->f2C,(void *)PARTICLE_LoadArchiveMember(216,51,141),1,0);}
