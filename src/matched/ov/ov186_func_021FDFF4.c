/*
 * function: BR_UTIL_EffectToTarget
 * address: 0x021FDFF4
 * packet: pkt_ov186_021FDFF4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 *   BR_UTIL_InitOrbit 0x021FE2BC thumb ov186
 *   BR_UTIL_StepOrbit 0x021FE2F8 thumb ov186
 *   BR_UTIL_Init 0x021FE4D8 thumb ov186
 *   BR_UTIL_StepFollow 0x021FE54C thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;int target;int heap;char pad10[8];char record[6][32];char padD8[0xC0];int positions[12][2];void *handles[12];int timer; } Motion;
struct Obj;
struct Pair;
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
extern int BR_UTIL_InitOrbit(u8 *p, const struct Pair *origin, u16 a, u16 b, u16 c, u16 d, int duration);
extern void BR_UTIL_Init(int *p, int a, const int *values, int duration);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_AddActorSurfacePos(void *,ShortPair *,u16);
extern int BR_UTIL_StepOrbit(char *p, int *out, int step);
extern int BR_UTIL_StepFollow(char *p, int *out);
void BR_UTIL_EffectToTarget(int *obj,int *state,Motion *p)
{
    ShortPair pos;
    ShortPair pos2;
    int i;
    int all;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            BR_UTIL_InitOrbit((u8 *)p->record[i],(const struct Pair *)p,8,20,(i*0xFFFF)/6,(i*0xFFFF)/6+0x3333,16);
            CLACT_SetActorDrawEnable((struct Obj *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepOrbit(p->record[i],p->positions[i],p->timer);
            pos.x=p->positions[i][0];pos.y=p->positions[i][1];
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        if(p->timer++>16) *state=2;
        break;
    case 2:
        *state=3;
        break;
    case 3:
        for(i=0;i<6;i++)
            BR_UTIL_Init((int *)p->record[i],p->target,p->positions[i],0x4000-(i*0x99A)/2);
        *state=4;
    case 4:
        all=1;
        for(i=0;i<6;i++) {
            all&=BR_UTIL_StepFollow(p->record[i],p->positions[i]);
            pos2.x=p->positions[i][0];pos2.y=p->positions[i][1];
            CLACT_AddActorSurfacePos(p->handles[i],&pos2,p->heap);
        }
        if(all) *state=5;
        break;
    case 5:
        BR_UTIL_SetTaskStep(obj,(int)BR_UTIL_EffectIdle);
        break;
    }
}
