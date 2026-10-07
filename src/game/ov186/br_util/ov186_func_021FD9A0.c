/*
 * function: func_021FD9A0
 * address: 0x021FD9A0
 * packet: pkt_ov186_021FD9A0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE2BC 0x021FE2BC thumb ov186
 *   func_021FE2F8 0x021FE2F8 thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 */
typedef unsigned short u16;
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[6][32];char padD8[0x120];void *handles[12];int timer; } Motion;
struct Pair;
extern int func_021FE2BC(unsigned char *p, const struct Pair *origin, u16 a, u16 b, u16 c, u16 d, int duration);
extern int func_021FE2F8(char *,int *,int);
struct Obj;
typedef unsigned char  u8;
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B404(void *,const ShortPair *,u16);
extern int *func_021FD73C(int *p, int v);
extern void func_021FD964(void *unused, int *state, u8 *p);
void func_021FD9A0(int unused,int *state,Motion *p)
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
            func_021FE2BC((unsigned char *)p->record[i],(const struct Pair *)p,8,20,angle,angle+0x3333,15);
            func_0204B3DC(p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE2F8(p->record[i],(int *)&full,p->timer);
            pos.x=full.x;pos.y=full.y;
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        if(p->timer++>15) *state=2;
        break;
    case 2:
        func_021FD73C(p->task,(int)func_021FD964);
        break;
    }
}
