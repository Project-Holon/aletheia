/*
 * function: func_021E2FB0
 * address: 0x021E2FB0
 * packet: pkt_ov119_021E2FB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0205121C 0x0205121C arm
 *   func_02087A3C 0x02087A3C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystemBorrowed 0x02051360 arm
 */
#include "../include/Obj08068.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void *func_02087A3C(int,int);
extern int func_020056BC(void *);
extern void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
void func_021E2FB0(char *p) {
    int i;
    ((struct Obj08068 *)p)->fB4=(void *)func_0205121C((int)0x67,(int)0x35,(u16)((((struct Obj08068 *)p)->fBA&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        int x=func_020056BC(func_02087A3C(1,1));
        PARTICLE_SetupSystemBorrowed(((void **)p)[i],(unsigned int)(((struct Obj08068 *)p)->fB4),1,x);
    }
}
