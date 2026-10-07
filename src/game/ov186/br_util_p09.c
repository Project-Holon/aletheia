/*
 * file:     br_util_p09.c
 * unit:     yes
 * function: func_021FDE88, func_021FDF40
 * address:  0x021FDE88
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FE3B4 0x021FE3B4 thumb ov186
 *   func_021FE3E4 0x021FE3E4 thumb ov186
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020061E4 0x020061E4 thumb
 */
struct Obj;
struct Pair;
typedef struct { int x,y; } Pair;

typedef struct { short x,y; } ShortPair;

typedef struct { int x,y;char pad8[4];int heap;char pad10[8];char record[6][32];char padD8[0x120];int handles[12];int timer; } Motion;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern int func_021FE3B4(u8 *p, const struct Pair *origin, u16 a, u16 b, int duration);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B404(int,ShortPair *,unsigned short);
extern void func_020061E4(u32 a);
extern int func_021FE3E4(char *p, int *out, int step);
void func_021FDE88(int unused,int *state,Motion *p);
void func_021FDF40(int unused,int *state,Motion *p);
void func_021FDFF0(void);

void func_021FDE88(int unused,int *state,Motion *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE3B4((u8 *)p->record[i],(const struct Pair *)p,15,(i*0xFFFF)/6,90);
            func_0204B3DC((struct Obj *)p->handles[i],1);
        }
        func_020061E4(0x705);
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE3E4(p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        break;
    }
}

/*
 * follower: empty return at 021FDFF0; trailing two zero alignment bytes excluded.
 */
void func_021FDF40(int unused,int *state,Motion *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE3B4((u8 *)p->record[i],(const struct Pair *)p,10,(i*0xFFFF)/6,90);
            func_0204B3DC((struct Obj *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE3E4(p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            func_0204B404(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        break;
    }
}

void func_021FDFF0(void)
{
}
