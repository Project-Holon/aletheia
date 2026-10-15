/*
 * function: BR_UTIL_EffectFollow6
 * address: 0x021FDBF4
 * packet: pkt_ov186_021FDBF4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_InitLine 0x021FE444 thumb ov186
 *   BR_UTIL_StepLine 0x021FE478 thumb ov186
 *   BR_UTIL_Init 0x021FE4D8 thumb ov186
 *   BR_UTIL_StepFollow 0x021FE54C thumb ov186
 *   BR_UTIL_InitSpiral 0x021FE3B4 thumb ov186
 *   BR_UTIL_StepSpiral 0x021FE3E4 thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_02200AD0 0x02200AD0 data a4
 */
typedef unsigned short u16;
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { Pair first,second,third; } Table;
typedef struct { int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[12][32];Pair positions[12];void *handles[12];int timer,flag,done[12]; } Motion;
extern const Table d_02200AD0;
extern void BR_UTIL_InitLine(int *,Pair *,const Pair *,int,int),BR_UTIL_Init(int *,int,const int *,int);
extern int BR_UTIL_StepLine(int *,Pair *,int);
extern int BR_UTIL_StepFollow(char *p, int *out);
typedef unsigned char  u8;
struct Pair;
extern int BR_UTIL_InitSpiral(u8 *p, const struct Pair *origin, u16 a, u16 b, int duration);
extern int BR_UTIL_StepSpiral(char *p, int *out, int step);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int),CLACT_AddActorSurfacePos(void *,const ShortPair *,u16);
void BR_UTIL_EffectFollow6(int unused,int *state,Motion *p)
{
    ShortPair pos;
    ShortPair pos2;
    Pair initial;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0.third;
        for(i=0;i<6;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        BR_UTIL_InitLine((int *)p->record[0],&p->positions[0],&d_02200AD0.second,0,36);
        for(i=1;i<6;i++) BR_UTIL_Init((int *)p->record[i],(int)&p->positions[i-1],(int *)&p->positions[i],0x3800-i*0xb33/2);
        *state=1;
    case 1:
        p->done[1]=BR_UTIL_StepLine((int *)p->record[0],&p->positions[0],p->timer);
        for(i=1;i<6;i++) p->done[i+1]=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<6;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        if(p->done[1]) {CLACT_SetActorDrawEnable(p->handles[0],0);*state=2;}
        break;
    case 2:
        p->timer=0;
        for(i=6;i<12;i++) {
            BR_UTIL_InitSpiral((u8 *)p->record[i],(void *)&d_02200AD0.second,15,(i*0xffff-0x5fffa)/6,90);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=3;
    case 3:
        for(i=6;i<12;i++) BR_UTIL_StepSpiral(p->record[i],(int *)(&p->positions[i]),p->timer);
        for(i=1;i<6;i++) {
            p->done[i+1]=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
            if(p->done[i+1]) CLACT_SetActorDrawEnable(p->handles[i],0);
        }
        for(i=0;i<12;i++) {
            pos2.x=p->positions[i].x;pos2.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos2,p->heap);
        }
        p->flag=1;
        p->timer++;
        break;
    }
}
