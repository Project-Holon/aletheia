/*
 * function: func_021FDE88
 * address: 0x021FDE88
 * packet: pkt_ov186_021FDE88
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE3B4 0x021FE3B4 thumb ov186
 *   func_021FE3E4 0x021FE3E4 thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;char pad10[8];char record[6][32];char padD8[0x120];int handles[12];int timer; } Motion;
extern void func_021FE3B4(void *,void *,unsigned short,unsigned short,int),func_0204B3DC(int,int),func_0204B404(int,ShortPair *,unsigned short),func_020061E4(int);
extern int func_021FE3E4(void *,Pair *,int);
void func_021FDE88(int unused,int *state,Motion *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE3B4(p->record[i],p,15,(i*0xFFFF)/6,90);
            func_0204B3DC(p->handles[i],1);
        }
        func_020061E4(0x705);
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE3E4(p->record[i],&full,p->timer);
            pos.x=full.x;pos.y=full.y;
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        break;
    }
}
