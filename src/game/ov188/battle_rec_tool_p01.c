/*
 * file:     battle_rec_tool_p01.c
 * unit:     yes
 * function: func_021EE920, func_021EEBF0, func_021EEE78
 * address:  0x021EE920
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02019A50 0x02019A50 thumb
 *   func_02019C38 0x02019C38 thumb
 *   func_02019A9C 0x02019A9C thumb
 *   func_021EEFA4  0x021EEFA4  thumb  ov188
 *   func_021EF014  0x021EF014  thumb  ov188
 *   func_021EF1AC  0x021EF1AC  thumb  ov188
 *   func_021EF1F4  0x021EF1F4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 */
#include "../../matched/include/Obj00685.h"
#include "../../matched/include/Obj01968.h"
#include "../../matched/include/Obj02905.h"
#include "../../matched/include/Obj24888.h"
#include "../../matched/include/Obj24889.h"
#include "../../matched/include/Obj00506.h"
#include "../../matched/include/Obj01969.h"
#include "../../matched/include/Obj02906.h"
#include "../../matched/include/Obj24890.h"
#include "../../matched/include/Obj24891.h"
#include "../../matched/include/G_BattleRec.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 a:1,b:1,c:1,mode:8,pad:5; } Flags;

typedef struct { u32 a:5,b:5,c:5,d:5,e:5,f:5,g:1,h:1; } Packed;

typedef struct { u8 a:1,b:2,c:5; } Byte;

struct Mon { u32 seed; Flags flags; u16 check; u8 block[0x80]; };

extern void func_02082BCC(void *,int,u32);
extern void func_02019A50(u16 *,u32,u32);
extern void *func_02019C38(struct Mon *,u32,u32);
extern u16 func_02019A9C(const u16 *,u32);
extern void func_021EEFA4(int *a, char *p);
extern void func_021EF014(u8 *a, u8 *b);
extern int func_021EF1AC(char *p, char *q);
extern int func_021EF1F4(const u8 *a, u8 *b);
void func_021EE920(struct Mon *p,char *q);
void func_021EEBF0(char *p,struct Mon *q);
void func_021EEE78(void *p);
extern struct BattleRec *g_0214616C;

void func_021EE920(struct Mon *p,char *q)
{
    char *a,*b,*c,*d;
    int i;
    func_02082BCC(q,0,0x70);
    if (!p->flags.a) {
        func_02019A50((u16 *)((char *)p+0x88),0x54,p->seed);
        func_02019A50((u16 *)p->block,0x80,p->check);
    }
    a=func_02019C38(p,p->seed,0);
    b=func_02019C38(p,p->seed,1);
    c=func_02019C38(p,p->seed,2);
    d=func_02019C38(p,p->seed,3);
    ((struct Obj00685 *)q)->f0=p->seed;
    ((Flags *)(q+4))->a=0;
    ((Flags *)(q+4))->b=0;
    ((Flags *)(q+4))->c=p->flags.c;
    ((Flags *)(q+4))->mode=((struct Obj24888 *)b)->f19;
    ((struct Obj00685 *)q)->f6=((struct Obj01968 *)a)->f0;
    ((struct Obj00685 *)q)->f8=((struct Obj01968 *)a)->f2;
    ((struct Obj00685 *)q)->fC=((struct Obj01968 *)a)->f4;
    ((struct Obj00685 *)q)->f10=((struct Obj01968 *)a)->f8;
    ((struct Obj00685 *)q)->f14=((struct Obj01968 *)a)->fC;
    ((struct Obj00685 *)q)->f15=((struct Obj01968 *)a)->fD;
    ((struct Obj00685 *)q)->f16=((struct Obj01968 *)a)->f10;
    ((struct Obj00685 *)q)->f17=((struct Obj01968 *)a)->f11;
    ((struct Obj00685 *)q)->f18=((struct Obj01968 *)a)->f12;
    ((struct Obj00685 *)q)->f19=((struct Obj01968 *)a)->f13;
    ((struct Obj00685 *)q)->f1A=((struct Obj01968 *)a)->f14;
    ((struct Obj00685 *)q)->f1B=((struct Obj01968 *)a)->f15;
    ((struct Obj00685 *)q)->f59=((struct Obj01968 *)a)->fF;
    for(i=0;i<4;i++) {
        *(u16 *)(q+2*i+0x1c)=*(u16 *)(b+2*i);
        *(u8 *)(q+i+0x24)=*(u8 *)(b+i+8);
        *(u8 *)(q+i+0x28)=*(u8 *)(b+i+0xc);
    }
    ((Packed *)(q+0x2c))->a=((Packed *)(b+0x10))->a;
    ((Packed *)(q+0x2c))->b=((Packed *)(b+0x10))->b;
    ((Packed *)(q+0x2c))->c=((Packed *)(b+0x10))->c;
    ((Packed *)(q+0x2c))->d=((Packed *)(b+0x10))->d;
    ((Packed *)(q+0x2c))->e=((Packed *)(b+0x10))->e;
    ((Packed *)(q+0x2c))->f=((Packed *)(b+0x10))->f;
    ((Packed *)(q+0x2c))->g=((Packed *)(b+0x10))->g;
    ((Packed *)(q+0x2c))->h=((Packed *)(b+0x10))->h;
    ((Byte *)(q+0x30))->a=((Byte *)(b+0x18))->a;
    ((Byte *)(q+0x30))->b=((Byte *)(b+0x18))->b;
    ((Byte *)(q+0x30))->c=((Byte *)(b+0x18))->c;
    for(i=0;i<11;i++) *(u16 *)(q+2*i+0x32)=*(u16 *)(c+2*i);
    for(i=0;i<8;i++) *(u16 *)(q+2*i+0x48)=*(u16 *)(d+2*i);
    ((struct Obj00685 *)q)->f58=((struct Obj24889 *)d)->f1B;
    ((struct Obj00685 *)q)->f5C=((struct Obj02905 *)p)->f88;
    ((struct Obj00685 *)q)->f60=((struct Obj02905 *)p)->f8C;
    ((struct Obj00685 *)q)->f61=((struct Obj02905 *)p)->f8D;
    ((struct Obj00685 *)q)->f62=((struct Obj02905 *)p)->f8E;
    ((struct Obj00685 *)q)->f64=((struct Obj02905 *)p)->f90;
    ((struct Obj00685 *)q)->f66=((struct Obj02905 *)p)->f92;
    ((struct Obj00685 *)q)->f68=((struct Obj02905 *)p)->f94;
    ((struct Obj00685 *)q)->f6A=((struct Obj02905 *)p)->f96;
    ((struct Obj00685 *)q)->f6C=((struct Obj02905 *)p)->f98;
    ((struct Obj00685 *)q)->f6E=((struct Obj02905 *)p)->f9A;
    if (!p->flags.a) {
        func_02019A50((u16 *)((char *)p+0x88),0x54,p->seed);
        func_02019A50((u16 *)p->block,0x80,p->check);
    }
}

void func_021EEBF0(char *p,struct Mon *q)
{
    char *a,*b,*c,*d;
    int i;
    func_02082BCC(q,0,0xdc);
    a=func_02019C38(q,((struct Obj00506 *)p)->f0,0);
    b=func_02019C38(q,((struct Obj00506 *)p)->f0,1);
    c=func_02019C38(q,((struct Obj00506 *)p)->f0,2);
    d=func_02019C38(q,((struct Obj00506 *)p)->f0,3);
    q->seed=((struct Obj00506 *)p)->f0;
    q->flags.a=0;
    q->flags.b=0;
    q->flags.c=((Flags *)(p+4))->c;
    ((struct Obj01969 *)a)->f0=((struct Obj00506 *)p)->f6;
    ((struct Obj01969 *)a)->f2=((struct Obj00506 *)p)->f8;
    ((struct Obj01969 *)a)->f4=((struct Obj00506 *)p)->fC;
    ((struct Obj01969 *)a)->f8=((struct Obj00506 *)p)->f10;
    ((struct Obj01969 *)a)->fC=((struct Obj00506 *)p)->f14;
    ((struct Obj01969 *)a)->fD=((struct Obj00506 *)p)->f15;
    ((struct Obj01969 *)a)->f10=((struct Obj00506 *)p)->f16;
    ((struct Obj01969 *)a)->f11=((struct Obj00506 *)p)->f17;
    ((struct Obj01969 *)a)->f12=((struct Obj00506 *)p)->f18;
    ((struct Obj01969 *)a)->f13=((struct Obj00506 *)p)->f19;
    ((struct Obj01969 *)a)->f14=((struct Obj00506 *)p)->f1A;
    ((struct Obj01969 *)a)->f15=((struct Obj00506 *)p)->f1B;
    ((struct Obj01969 *)a)->fF=((struct Obj00506 *)p)->f59;
    for(i=0;i<4;i++) {
        *(u16 *)(b+2*i)=*(u16 *)(p+2*i+0x1c);
        *(u8 *)(b+i+8)=*(u8 *)(p+i+0x24);
        *(u8 *)(b+i+0xc)=*(u8 *)(p+i+0x28);
    }
    ((Packed *)(b+0x10))->a=((Packed *)(p+0x2c))->a;
    ((Packed *)(b+0x10))->b=((Packed *)(p+0x2c))->b;
    ((Packed *)(b+0x10))->c=((Packed *)(p+0x2c))->c;
    ((Packed *)(b+0x10))->d=((Packed *)(p+0x2c))->d;
    ((Packed *)(b+0x10))->e=((Packed *)(p+0x2c))->e;
    ((Packed *)(b+0x10))->f=((Packed *)(p+0x2c))->f;
    ((Packed *)(b+0x10))->g=((Packed *)(p+0x2c))->g;
    ((Packed *)(b+0x10))->h=((Packed *)(p+0x2c))->h;
    ((Byte *)(b+0x18))->a=((Byte *)(p+0x30))->a;
    ((Byte *)(b+0x18))->b=((Byte *)(p+0x30))->b;
    ((Byte *)(b+0x18))->c=((Byte *)(p+0x30))->c;
    ((struct Obj24890 *)b)->f19=((Flags *)(p+4))->mode;
    for(i=0;i<11;i++) *(u16 *)(c+2*i)=*(u16 *)(p+2*i+0x32);
    for(i=0;i<8;i++) *(u16 *)(d+2*i)=*(u16 *)(p+2*i+0x48);
    ((struct Obj24891 *)d)->f1B=((struct Obj00506 *)p)->f58;
    ((struct Obj02906 *)q)->f88=((struct Obj00506 *)p)->f5C;
    ((struct Obj02906 *)q)->f8C=((struct Obj00506 *)p)->f60;
    ((struct Obj02906 *)q)->f8D=((struct Obj00506 *)p)->f61;
    ((struct Obj02906 *)q)->f8E=((struct Obj00506 *)p)->f62;
    ((struct Obj02906 *)q)->f90=((struct Obj00506 *)p)->f64;
    ((struct Obj02906 *)q)->f92=((struct Obj00506 *)p)->f66;
    ((struct Obj02906 *)q)->f94=((struct Obj00506 *)p)->f68;
    ((struct Obj02906 *)q)->f96=((struct Obj00506 *)p)->f6A;
    ((struct Obj02906 *)q)->f98=((struct Obj00506 *)p)->f6C;
    ((struct Obj02906 *)q)->f9A=((struct Obj00506 *)p)->f6E;
    func_02019A50((u16 *)((char *)q+0x88),0x54,q->seed);
    q->check=func_02019A9C((u16 *)q->block,0x80);
    func_02019A50((u16 *)q->block,0x80,q->check);
}


void func_021EEE78(void *p)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    func_021EEFA4(p, q);
    func_021EF014(p, (u8 *)q);
    func_021EF1AC(p, q);
    func_021EF1F4(p, (u8 *)q);
}
