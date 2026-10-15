/*
 * function: BR_UTIL_EffectFollow12
 * address: 0x021FDA7C
 * packet: pkt_ov186_021FDA7C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: ShortPair declared before Pair gives +2C and +24 stack objects; initialize reused i=1 before FE478 so the call precedes its loop without relocating movs.
 * symbols:
 *   BR_UTIL_InitLine 0x021FE444 thumb ov186
 *   BR_UTIL_StepLine 0x021FE478 thumb ov186
 *   BR_UTIL_Init 0x021FE4D8 thumb ov186
 *   BR_UTIL_StepFollow 0x021FE54C thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 *   d_02200AD0 0x02200AD0 data a4
 *   d_02200AE8 0x02200AE8 data a4
 */
typedef unsigned short u16;
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[12][32];Pair positions[12];void *handles[12];int timer,flag,done[12]; } Motion;
extern const Pair d_02200AD0,d_02200AE8;
extern void BR_UTIL_InitLine(int *,Pair *,const Pair *,int,int),BR_UTIL_Init(int *,int,const int *,int);
extern int BR_UTIL_StepLine(int *,Pair *,int);
extern int BR_UTIL_StepFollow(char *p, int *out);
struct Obj;
typedef unsigned char  u8;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_AddActorSurfacePos(void *,const ShortPair *,u16);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
void BR_UTIL_EffectFollow12(int unused,int *state,Motion *p)
{
    ShortPair pos;
    Pair initial;
    int i,done;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0;
        for(i=0;i<12;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        BR_UTIL_InitLine((int *)p->record[0],&p->positions[0],&d_02200AE8,0,50);
        for(i=1;i<12;i++) BR_UTIL_Init((int *)p->record[i],(int)&p->positions[i-1],(int *)&p->positions[i],0x4000-i*0x666/2);
        *state=1;
    case 1:
        i=1;
        p->flag=BR_UTIL_StepLine((int *)p->record[0],&p->positions[0],p->timer);
        done=1;
        done&=p->flag;
        for(;i<12;i++) done&=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<12;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        if(done) *state=2;
        break;
    case 2: BR_UTIL_SetTaskStep(p->task,(int)BR_UTIL_EffectIdle);break;
    }
}
