/*
 * file:     p_sta_oam_p10.c
 * unit:     yes
 * function: func_021D6614, func_021D67EC, func_021D6808, func_021D6810, func_021D694C
 * address:  0x021D6614
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7460 0x021D7460 thumb ov131
 *   func_021D6F54 0x021D6F54 thumb ov131
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015C78 0x02015C78 thumb
 *   func_02015D30 0x02015D30 thumb
 *   func_02048AFC 0x02048AFC arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021DC234 0x021DC234 data a4
 *   d_021DC228 0x021DC228 data a4
 *   d_021DC198 0x021DC198 data a4
 *   d_021DC210 0x021DC210 data a4
 *   d_021DC170 0x021DC170 data a4
 *   d_021DC178 0x021DC178 data a4
 *   d_021DC168 0x021DC168 data a4
 *   func_020498F4  0x020498F4  arm
 *   func_021D6CDC 0x021D6CDC thumb ov131
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021DC158 0x021DC158 data a1
 *   d_021DC160 0x021DC160 data a1
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../../matched/include/Obj00200.h"
#include "../../matched/include/Obj05385.h"
#include "../../matched/include/Obj00993.h"
#include "../../matched/include/Obj05386.h"
#include "../../matched/include/Obj10507.h"

struct Light;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct {int x,y,z;} Vec;

typedef struct {int v[2];} Pair;

typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;

extern void func_021D7460(u8 *,u8 *);
extern void func_021D6F54(u8 *,u8 *);
extern void func_021D79A8(void *,u8 *,int);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015D30(void *p, u32 *src);
extern void func_02048AFC(void *,const Vec *);
extern void func_02048AD0(struct Light *l);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_021D6CDC(unsigned char *a, unsigned char *b);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
void func_021D6614(u8 *a,u8 *p);
void func_021D67EC(u16 *p, int a, void *b);
void func_021D6808(void *a,void *b);
void func_021D6810(u8 *a,u8 *p);
void func_021D694C(void *a,unsigned char *p);
extern const s16 d_020A1B38[];
extern const Vec d_021DC234,d_021DC228,d_021DC198,d_021DC210;
extern const Pair d_021DC170,d_021DC178,d_021DC168;
extern const u8 d_021DC158[];
extern const u8 d_021DC160[];

void func_021D6614(u8 *a,u8 *p) {
    u32 st=((struct Obj00200 *)p)->f8;
    if(st==0 || st==2) {
        func_021D7460(a,p);
        func_021D6F54(a,p);
        return;
    }
    if(st==3) {
        Vec v48=d_021DC234;
        Vec v3c=d_021DC228;
        Vec v30={0,0,0};
        u8 c;
        p[0x9b]=p[0x9b]+1;
        if(p[0x9b]>5 && ((struct Obj00200 *)p)->fC==0) {
            func_02015EB0(((struct Obj00200 *)p)->f0);
            func_02015EA0(((struct Obj00200 *)p)->f4);
            ((struct Obj00200 *)p)->fC=1;
        }
        c=p[0x9b];
        if(c>=10) {
            func_021D79A8(a,p,0);
            ((struct Obj00200 *)p)->f8=0;
        } else {
            u16 ang;
            v48.x=c*0x19000/10-0x42000;
            ang=(p[0x9b]<<15)/10;
            v30.y=d_020A1B38[(ang>>4)*2]<<5;
            if(((struct Obj00200 *)p)->f10==1) v30.y=0;
            func_021D79A8(a,p,v30.y);
        }
        func_02015C78(((struct Obj00200 *)p)->f0,(u32 *)(&v30));
        func_02015C78(((struct Obj00200 *)p)->f4,(u32 *)(&v30));
        func_02015D30(((struct Obj00200 *)p)->f0,(u32 *)(&v3c));
        func_02048AFC(((struct Obj05385 *)a)->f70,&v48);
        func_02048AD0(((struct Obj05385 *)a)->f70);
    } else if(st==1) {
        Vec v24=d_021DC198;
        Vec v18=d_021DC210;
        u8 c;
        p[0x9b]=p[0x9b]+1;
        c=p[0x9b];
        if(c<3) {
            Pair t1=d_021DC170;
            Pair t2=d_021DC178;
            Pair t3=d_021DC168;
            u8 k=c-1;
            v18.x=t1.v[k];
            v18.y=t2.v[k];
            v24.x=t3.v[k];
            func_02048AFC(((struct Obj05385 *)a)->f70,&v24);
            func_02048AD0(((struct Obj05385 *)a)->f70);
            func_02015D30(((struct Obj00200 *)p)->f0,(u32 *)(&v18));
        } else {
            func_02015EA0(((struct Obj00200 *)p)->f0);
            func_02015EB0(((struct Obj00200 *)p)->f4);
            func_02015D30(((struct Obj00200 *)p)->f4,(u32 *)(&v18));
            func_02048AFC(((struct Obj05385 *)a)->f70,&v24);
            func_02048AD0(((struct Obj05385 *)a)->f70);
            ((struct Obj00200 *)p)->fC=0;
            ((struct Obj00200 *)p)->f8=2;
            ((struct Obj00200 *)p)->f6C=0;
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D67EC(u16 *p, int a, void *b)
{
    func_020498F4(b, 0x3e, 2, 0, 0, 0, *p);
}

void func_021D6808(void *a,void *b) {
 func_021D6CDC(a,b);
}

void func_021D6810(u8 *a,u8 *p) {
    ObjPos pos[4];
    u8 i;
    u32 *e;
    pos[3].x=168;
    pos[3].y=8;
    pos[3].priority=10;
    pos[3].flags=1;
    pos[3].z=0;
    ((struct Obj05386 *)p)->f20=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD0,((struct Obj00993 *)a)->f9C,((struct Obj00993 *)a)->f104,&pos[3],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f20,0);
    pos[2].y=128;
    pos[2].priority=10;
    pos[2].flags=1;
    for(i=0;i<8;i++) {
        pos[2].x=d_021DC158[i];
        pos[2].z=d_021DC160[i];
        e=(u32 *)(p+i*4);
        e[9]=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fD4,((struct Obj00993 *)a)->fA0,((struct Obj00993 *)a)->f108,&pos[2],0,((struct Obj00993 *)a)->f0);
        func_0204B3DC((struct Obj *)e[9],1);
    }
    pos[1].x=236;
    pos[1].y=26;
    pos[1].priority=10;
    pos[1].flags=1;
    pos[1].z=0;
    ((struct Obj05386 *)p)->f44=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF0,((struct Obj00993 *)a)->fBC,((struct Obj00993 *)a)->f120,&pos[1],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f44,0);
    pos[0].x=241;
    pos[0].y=31;
    pos[0].priority=10;
    pos[0].flags=1;
    pos[0].z=0;
    ((struct Obj05386 *)p)->f48=(u32)func_0204B294((void *)((struct Obj00993 *)a)->f174,((struct Obj00993 *)a)->fF4,((struct Obj00993 *)a)->fC0,((struct Obj00993 *)a)->f124,&pos[0],0,((struct Obj00993 *)a)->f0);
    func_0204B3DC((struct Obj *)((struct Obj05386 *)p)->f48,0);
}

void func_021D694C(void *a,unsigned char *p) {
 u8 i;
 func_0204B3B4(((struct Obj10507 *)p)->f48);
 func_0204B3B4(((struct Obj10507 *)p)->f44);
 for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+0x24+i*4));
 func_0204B3B4(((struct Obj10507 *)p)->f20);
}
