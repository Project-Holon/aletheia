/*
 * function: func_021FDA7C
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
 *   func_021FE444 0x021FE444 thumb ov186
 *   func_021FE478 0x021FE478 thumb ov186
 *   func_021FE4D8 0x021FE4D8 thumb ov186
 *   func_021FE54C 0x021FE54C thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   d_02200AD0 0x02200AD0 data a4
 *   d_02200AE8 0x02200AE8 data a4
 */
typedef unsigned short u16;
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[12][32];Pair positions[12];void *handles[12];int timer,flag,done[12]; } Motion;
extern const Pair d_02200AD0,d_02200AE8;
extern void func_021FE444(int *,Pair *,const Pair *,int,int),func_021FE4D8(int *,int,const int *,int);
extern int func_021FE478(int *,Pair *,int),func_021FE54C(int *,Pair *);
struct Obj;
typedef unsigned char  u8;
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B404(void *,const ShortPair *,u16);
extern void func_021FD73C(int *,int);
extern void func_021FD964(void *unused, int *state, u8 *p);
void func_021FDA7C(int unused,int *state,Motion *p)
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
            func_0204B3DC(p->handles[i],1);
        }
        func_021FE444((int *)p->record[0],&p->positions[0],&d_02200AE8,0,50);
        for(i=1;i<12;i++) func_021FE4D8((int *)p->record[i],(int)&p->positions[i-1],(int *)&p->positions[i],0x4000-i*0x666/2);
        *state=1;
    case 1:
        i=1;
        p->flag=func_021FE478((int *)p->record[0],&p->positions[0],p->timer);
        done=1;
        done&=p->flag;
        for(;i<12;i++) done&=func_021FE54C((int *)p->record[i],&p->positions[i]);
        for(i=0;i<12;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        if(done) *state=2;
        break;
    case 2: func_021FD73C(p->task,(int)func_021FD964);break;
    }
}
