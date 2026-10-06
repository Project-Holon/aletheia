/*
 * function: func_021FDFF4
 * address: 0x021FDFF4
 * packet: pkt_ov186_021FDFF4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   func_021FE2BC 0x021FE2BC thumb ov186
 *   func_021FE2F8 0x021FE2F8 thumb ov186
 *   func_021FE4D8 0x021FE4D8 thumb ov186
 *   func_021FE54C 0x021FE54C thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;int target;int heap;char pad10[8];char record[6][32];char padD8[0xC0];int positions[12][2];void *handles[12];int timer; } Motion;
struct Obj;
struct Pair;
extern void func_021FD73C(int *,int);
extern void func_021FD964(void *unused, int *state, u8 *p);
extern int func_021FE2BC(u8 *p, const struct Pair *origin, u16 a, u16 b, u16 c, u16 d, int duration);
extern void func_021FE4D8(int *p, int a, const int *values, int duration);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B404(void *,ShortPair *,u16);
extern int func_021FE2F8(char *p, int *out, int step);
extern int func_021FE54C(char *p, int *out);
void func_021FDFF4(int *obj,int *state,Motion *p)
{
    ShortPair pos;
    ShortPair pos2;
    int i;
    int all;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE2BC((u8 *)p->record[i],(const struct Pair *)p,8,20,(i*0xFFFF)/6,(i*0xFFFF)/6+0x3333,16);
            func_0204B3DC((struct Obj *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE2F8(p->record[i],p->positions[i],p->timer);
            pos.x=p->positions[i][0];pos.y=p->positions[i][1];
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        if(p->timer++>16) *state=2;
        break;
    case 2:
        *state=3;
        break;
    case 3:
        for(i=0;i<6;i++)
            func_021FE4D8((int *)p->record[i],p->target,p->positions[i],0x4000-(i*0x99A)/2);
        *state=4;
    case 4:
        all=1;
        for(i=0;i<6;i++) {
            all&=func_021FE54C(p->record[i],p->positions[i]);
            pos2.x=p->positions[i][0];pos2.y=p->positions[i][1];
            func_0204B404(p->handles[i],&pos2,p->heap);
        }
        if(all) *state=5;
        break;
    case 5:
        func_021FD73C(obj,(int)func_021FD964);
        break;
    }
}
