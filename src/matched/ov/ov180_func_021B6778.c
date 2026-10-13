/*
 * function: func_021B6778
 * address: 0x021B6778
 * packet: pkt_ov180_021B6778
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021B8108 0x021B8108 data a4
 */
#include "../include/Obj10718.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int d_021B8108;
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void PARTICLE_SetupSystem(void *,void *,int,int);
void func_021B6778(char *p){((struct Obj10718 *)p)->f28=(void *)PARTICLE_CreateSystemDefault((int)(p+48),18432,1,141);PARTICLE_SetupSystem(((struct Obj10718 *)p)->f28,(void *)PARTICLE_LoadArchiveMember(216,*(int *)((u32)&d_021B8108+((struct Obj10718 *)p)->f915A*4),141),1,0);}
