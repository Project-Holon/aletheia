/*
 * function: BR_UTIL_EffectSpiral
 * address: 0x021FD9A0
 * packet: pkt_ov186_021FD9A0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_InitOrbit 0x021FE2BC thumb ov186
 *   BR_UTIL_StepOrbit 0x021FE2F8 thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 */
typedef unsigned short u16;
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[6][32];char padD8[0x120];void *handles[12];int timer; } Motion;
struct Pair;
extern int BR_UTIL_InitOrbit(unsigned char *p, const struct Pair *origin, u16 a, u16 b, u16 c, u16 d, int duration);
extern int BR_UTIL_StepOrbit(char *,int *,int);
struct Obj;
typedef unsigned char  u8;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_AddActorSurfacePos(void *,const ShortPair *,u16);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
void BR_UTIL_EffectSpiral(int unused,int *state,Motion *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            int angle;
            angle=i*0xffff/6;
            BR_UTIL_InitOrbit((unsigned char *)p->record[i],(const struct Pair *)p,8,20,angle,angle+0x3333,15);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepOrbit(p->record[i],(int *)&full,p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        if(p->timer++>15) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(p->task,(int)BR_UTIL_EffectIdle);
        break;
    }
}
