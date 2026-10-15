/*
 * function: EGG_DEMO_VIEW_UpdateParticles
 * address: 0x021F6E5C
 * packet: pkt_ov215_021F6E5C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 * symbols:
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   d_021F73B4 0x021F73B4 data a4
 */
#include "../include/Obj02263.h"
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
extern const Vec d_021F73B4;
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillAllEffects(void *);
void EGG_DEMO_VIEW_UpdateParticles(char *p)
{
    if (((struct Obj02263 *)p)->f4814) {
        Vec v=d_021F73B4;
        while (((struct Obj02263 *)p)->f2<((struct Obj02263 *)p)->f4) {
            const char *table=*(const char * *)&((struct Obj02263 *)p)->f8;
            unsigned index=((struct Obj02263 *)p)->f2;
            u16 frame=((struct Obj02263 *)p)->f0;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            PARTICLE_StartEffect(*(void **)(p+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),(int)(&v));
            (((struct Obj02263 *)p)->f2)++;
        }
        (((struct Obj02263 *)p)->f0)++;
    }
    if (((struct Obj02263 *)p)->f4818>=0) {
        if (((struct Obj02263 *)p)->f4818==0) PARTICLE_KillAllEffects(((struct Obj02263 *)p)->f480C);
        (((struct Obj02263 *)p)->f4818)--;
    }
}
