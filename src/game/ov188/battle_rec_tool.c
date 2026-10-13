/*
 * file:     battle_rec_tool.c
 * unit:     yes
 * function: func_021EE920, func_021EEBF0, func_021EEE78, func_021EEEA8, func_021EEED8, func_021EEF2C, func_021EEFA4, func_021EEFE4, func_021EF014, func_021EF090, func_021EF0F4, func_021EF140, func_021EF1AC, func_021EF1D8, func_021EF1F4
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
 *   g_0214616C     0x0214616C  data
 *   func_021EF2D4  0x021EF2D4  thumb  ov188
 *   func_0201AA14   0x0201AA14  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201A954 0x0201A954 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 *   func_02008494 0x02008494 thumb
 *   func_02045A38 0x02045A38 arm
 *   func_02045924 0x02045924 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02082D44  0x02082D44  arm
 *   CONFIG_Copy  0x02008314  thumb
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
#include "../../matched/include/Obj10803.h"
#include "../../matched/include/Obj14491.h"
#include "../../matched/include/Obj08341.h"
#include "../../matched/include/Obj14492.h"
#include "../../matched/include/Obj02238.h"
#include "../../matched/include/Obj02528.h"
#include "../../matched/include/Obj01970.h"
#include "../../matched/include/Obj02529.h"
#include "../../matched/include/Obj14493.h"
#include "../../matched/include/Obj24896.h"
#include "../../matched/include/Obj02907.h"
#include "../../matched/include/Obj24897.h"

struct Mon;
struct Party;
struct PartyMon;
struct U16Vec;
struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 a:1,b:1,c:1,mode:8,pad:5; } Flags;

typedef struct { u32 a:5,b:5,c:5,d:5,e:5,f:5,g:1,h:1; } Packed;

typedef struct { u8 a:1,b:2,c:5; } Byte;

struct Mon { u32 seed; Flags flags; u16 check; u8 block[0x80]; };

typedef signed int     s32;

typedef struct { u32 w[4]; } Block16;

typedef struct { u32 w[6]; } Block24;

typedef struct { unsigned char low:5, high:3; } Bits50;

typedef struct { unsigned char low:4, mid:3, high:1; } Bits51;

extern void func_02082BCC(void *,int,u32);
extern void func_02019A50(u16 *,u32,u32);
extern void *func_02019C38(struct Mon *,u32,u32);
extern u16 func_02019A9C(const u16 *,u32);
extern int func_021EF2D4(u8 *a, const u8 *b);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_020173EC(void);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void func_02017E40(void *,u32,u32);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern void func_02008494(void *, void *);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02082D44(void *, void *, int);
extern void CONFIG_Copy(void *a, void *b);
void func_021EE920(struct Mon *p,char *q);
void func_021EEBF0(char *p,struct Mon *q);
void func_021EEE78(void *p);
void func_021EEEA8(void *p, u32 c);
void func_021EEED8(int a, char *p);
void func_021EEF2C(u8 *a,void *b,u32 c);
void func_021EEFA4(int *a, char *p);
void func_021EEFE4(void *p, char *b, u32 c);
void func_021EF014(u8 *a, u8 *b);
void func_021EF090(u8 *a, u8 *b);
void func_021EF0F4(u8 *a, u8 *b);
void func_021EF140(u8 *a, u8 *b);
int func_021EF1AC(char *p, char *q);
int func_021EF1D8(char *p, char *a1);
int func_021EF1F4(const u8 *a, u8 *b);
extern struct BattleRec *g_0214616C;
extern char d_021EF360[];



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




void func_021EEEA8(void *p, u32 c)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    func_021EEFE4(p, q, c);
    func_021EF090(p, (u8 *)q);
    func_021EF1D8(p, q);
    func_021EF2D4(p, (const u8 *)q);
}




/*
 * Clear a 0x2A4-byte record, copy the pair of counts out of a and release
 *   each of the 0x70-byte subrecords through 0x21EE920.
 */
void func_021EEED8(int a, char *p)
{
    int i;
    func_02082BCC((void *)((int)p), 0, 0x2A4);
    if (func_0201AA18((void *)a) == 0)
        return;
    ((struct Obj10803 *)p)->f0 = func_0201AA14((void *)a);
    ((struct Obj10803 *)p)->f2 = func_0201AA18((void *)a);
    for (i = 0; i < ((struct Obj10803 *)p)->f2; i++)
        func_021EE920((struct Mon *)((int)func_0201AB28((void *)a, i)), p + 4 + i * 0x70);
}



void func_021EEF2C(u8 *a,void *b,u32 c)
{
    int i;
    u8 *p;
    p=func_02030734((u16)((c & 0x7FFF)|0x8000),func_020173EC(),1,d_021EF360,173);
    func_0201A954(b,((struct Obj14491 *)a)->f0);
    for(i=0;i<((struct Obj14491 *)a)->f2;i++) {
        func_021EEBF0((char *)(a+4+i*112),(struct Mon *)p);
        func_02017E40(p,159,0);
        func_0201A98C(b,(const struct PartyMon *)p);
    }
    func_020307B0(p);
}




void func_021EEFA4(int *a, char *p)
{
    char *base;
    unsigned int i;
    func_02082BCC((void *)((int)(p + 0xC38)), 0, 0xA90);
    base = p + 0xC38;
    for (i = 0; i < 4; i++) {
        int v = a[9 + i];
        if (v != 0)
            func_021EEED8(v, base + i * 0x2A4);
    }
}



void func_021EEFE4(void *p, char *b, u32 c)
{
    char *base;
    u32 i = 0;

    base = b + 0xc38;
    for (; i < 4; i++) {
        u32 v = *(u32 *)((char *)p + i * 4 + 0x24);

        if (v != 0)
            func_021EEF2C((u8 *)(base + i * 0x2a4), (void *)v, c);
    }
}


void func_021EF014(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        if (*(void **)(a+0x48+i*4)) {
            func_021EF0F4(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 2;
        } else if (*(void **)(a+0x34+i*4)) {
            func_02008494(*(void **)(a+0x34+i*4), b+0x16CC+i*0x44);
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 1;
        } else {
            p = b+i*0x44;
            ((struct Obj08341 *)p)->f16C8 = 0;
        }
        ((struct Obj08341 *)p)->f16CA = a[0x44+i];
    }
}


void func_021EF090(u8 *a, u8 *b)
{
    unsigned i;
    u8 *p;
    for(i=0;i<4;i++) {
        p = b+i*0x44;
        switch(((struct Obj14492 *)p)->f16C8) {
        case 1: func_02008494(b+0x16CC+i*0x44, *(void **)(a+0x34+i*4)); break;
        case 2: func_021EF140(*(u8 **)(a+0x48+i*4), b+0x16CC+i*0x44); break;
        }
        a[0x44+i] = ((struct Obj14492 *)p)->f16CA;
    }
}


void func_021EF0F4(u8 *a, u8 *b)
{
    unsigned i;
    ((struct Obj02528 *)b)->f4 = ((struct Obj02238 *)a)->f0;
    ((struct Obj02528 *)b)->f6 = ((struct Obj02238 *)a)->f4;
    ((struct Obj02528 *)b)->f0 = ((struct Obj02238 *)a)->f8;
    ((struct Obj02528 *)b)->f30 = ((struct Obj02238 *)a)->f18;
    ((struct Obj02528 *)b)->f32 = ((struct Obj02238 *)a)->f1A;
    ((struct Obj02528 *)b)->f34 = ((struct Obj02238 *)a)->f1C;
    ((struct Obj02528 *)b)->f36 = ((struct Obj02238 *)a)->f1E;
    ((struct Obj02528 *)b)->f38 = ((struct Obj02238 *)a)->f20;
    ((struct Obj02528 *)b)->f3A = ((struct Obj02238 *)a)->f22;
    ((struct Obj02528 *)b)->f3C = ((struct Obj02238 *)a)->f24;
    ((struct Obj02528 *)b)->f3E = ((struct Obj02238 *)a)->f26;
    for(i=0;i<4;i++) *(u16 *)(b+8+i*2) = *(u16 *)(a+12+i*2);
    func_02045A38(((struct Obj02238 *)a)->f14, (u16 *)(b+16), 16);
}


void func_021EF140(u8 *a, u8 *b)
{
    unsigned i;
    u16 *p;
    ((struct Obj01970 *)a)->f0 = ((struct Obj02529 *)b)->f4;
    ((struct Obj01970 *)a)->f4 = ((struct Obj02529 *)b)->f6;
    ((struct Obj01970 *)a)->f8 = ((struct Obj02529 *)b)->f0;
    ((struct Obj01970 *)a)->f18 = ((struct Obj02529 *)b)->f30;
    ((struct Obj01970 *)a)->f1A = ((struct Obj02529 *)b)->f32;
    ((struct Obj01970 *)a)->f1C = ((struct Obj02529 *)b)->f34;
    ((struct Obj01970 *)a)->f1E = ((struct Obj02529 *)b)->f36;
    ((struct Obj01970 *)a)->f20 = ((struct Obj02529 *)b)->f38;
    ((struct Obj01970 *)a)->f22 = ((struct Obj02529 *)b)->f3A;
    ((struct Obj01970 *)a)->f24 = ((struct Obj02529 *)b)->f3C;
    ((struct Obj01970 *)a)->f26 = ((struct Obj02529 *)b)->f3E;
    for(i=0;i<4;i++) *(u16 *)(a+12+i*2) = *(u16 *)(b+8+i*2);
    func_02045924(((struct Obj01970 *)a)->f14, (u16 *)(b+16));
    p = STRBUF_GetChars(((struct Obj01970 *)a)->f14);
    while (*p != func_02045A98()) p++;
}



int func_021EF1AC(char *p, char *q)
{
    u32 a = ((struct Obj14493 *)p)->f94;

    if (a != 0) {
        u32 b = ((struct Obj14493 *)p)->f98;

        if (b < 0xc00) {
            ((struct Obj24896 *)q)->f34 = b;
            func_02082D44((void *)a, q + 0x38, b);
            return 1;
        }
    }
    return 0;
}



int func_021EF1D8(char *p, char *a1)
{
    int v = ((struct Obj24897 *)a1)->f34;

    ((struct Obj02907 *)p)->f98 = v;
    func_02082D44(a1 + 0x38, ((struct Obj02907 *)p)->f94, v);
    return 1;
}



int func_021EF1F4(const u8 *a, u8 *b)
{
    int f;
    *(Block16 *)(b + 24) = *(const Block16 *)(a + 8);
    *(Block24 *)b = *(const Block24 *)(a + 156);
    *(u16 *)(b + 44) = *(const u16 *)(a + 24);
    *(u16 *)(b + 46) = *(const u16 *)(a + 26);
    ((Bits50 *)(b + 50))->low = *(const u32 *)a;
    ((Bits51 *)(b + 51))->low = *(const u32 *)(a + 4);
    ((Bits51 *)(b + 51))->mid = a[34];
    *(u16 *)(b + 48) = *(const u16 *)(a + 134);
    ((Bits50 *)(b + 50))->high = a[33];
    f = (a[127] != 0);
    ((Bits51 *)(b + 51))->high = f;
    CONFIG_Copy(*(void **)(a + 92), b + 40);
    return 1;
}
