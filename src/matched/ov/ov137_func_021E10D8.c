/*
 * function: GURU2_MAIN_UpdateEntranceEffect, GURU2_MAIN_EntranceEffectTask
 * unit: yes
 * address: 0x021E10D8
 * packet: pkt_ov137_021E10D8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_AddBounceEffectsForActivePlayers 0x021E0E50 thumb ov137
 *   GURU2_MAIN_IsBounceEffectActive 0x021E0E8C thumb ov137
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj04541.h"
typedef unsigned char u8;
typedef struct {unsigned state;int active,other,timer,speed;} State;
extern void GURU2_MAIN_AddBounceEffectsForActivePlayers(char *p);
extern int GURU2_MAIN_IsBounceEffectActive(char *p);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void GURU2_MAIN_UpdateEntranceEffect(u8 *p,State *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Obj04541 *)b)->f34-=4096;
        if(((struct Obj04541 *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Obj04541 *)b)->f34+=8192;
        if(((struct Obj04541 *)b)->f34>=0) {
            ((struct Obj04541 *)b)->f34=0;
            GURU2_MAIN_AddBounceEffectsForActivePlayers((char *)p);
            s->active=1;s->state++;
            GFL_USE_PlaySeDefaultVolume(0x55e);
        }
        break;
    case 4:
        ((struct Obj04541 *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {((struct Obj04541 *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!GURU2_MAIN_IsBounceEffectActive((char *)p)) {
            s->other=0;s->active=0;s->state=0;
            GFL_USE_PlaySeDefaultVolume(0x76d);
        }
        break;
    case 0:break;
    }
}
void GURU2_MAIN_EntranceEffectTask(void *unused,u8 *p)
{
    GURU2_MAIN_UpdateEntranceEffect(p,(State *)(p+0xc74));
}
