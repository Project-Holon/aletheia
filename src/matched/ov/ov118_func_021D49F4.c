/*
 * function: POKETRADE_DEMO_UP_UpdateEmitterA
 * address: 0x021D49F4
 * packet: pkt_ov118_021D49F4
 * region: ov118
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PARTICLE_EMITTER_GetUserData 0x02051A34 arm
 *   ICA_ANIME_GetTranslate 0x02011610 thumb
 *   PARTICLE_EMITTER_SetEmitPos 0x02051838 arm
 */
#include "../include/Obj13873.h"
#include "../include/Obj22658.h"
#include "../include/Obj22659.h"
typedef struct { int x,y,z; } Vec;
extern int PARTICLE_EMITTER_GetUserData(void *p);
struct IcaAnime;
struct Rec12;
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *p, struct Rec12 *dst);
extern void PARTICLE_EMITTER_SetEmitPos(void *, Vec *);
void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on) {
 int buf[3]; Vec *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)PARTICLE_EMITTER_GetUserData(obj);
 if (((struct Obj22658 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98!=0) {
 v=(Vec *)buf; v->x=0; v->y=0; v->z=0;
 ICA_ANIME_GetTranslate(((struct Obj22659 *)(*(char * *)&((struct Obj13873 *)w)->fC))->f98,(struct Rec12 *)v);
 PARTICLE_EMITTER_SetEmitPos(obj,v);
 }
 }
}
