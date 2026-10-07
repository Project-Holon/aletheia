/*
 * file:     unit_021D85C0_p05.c
 * unit:     yes
 * function: func_021D97FC, func_021D9838, func_021D9890, func_021D99F0, func_021D9AB0, func_021D9BEC, func_021D9D44, func_021D9E48, func_021D9E60, func_021D9E98, func_021D9EE8, func_021D9F40, func_021D9FF0, func_021DA004, func_021DA158, func_021DA164, func_021DA1A8, func_021DA320, func_021DA3B8, func_021DA3D0, func_021DA3FC, func_021DA42C, func_021DA454, func_021DA524, func_021DA578
 * address:  0x021D97FC
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02021640 0x02021640 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0202590C  0x0202590C  thumb
 *   func_02025538  0x02025538  thumb
 *   func_0202570C 0x0202570C thumb
 *   func_02025588 0x02025588 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02043678 0x02043678 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020255A0 0x020255A0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045374 0x02045374 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj14057.h"
#include "../../matched/include/Obj02483.h"
#include "../../matched/include/Obj06480.h"
#include "../../matched/include/Obj10500.h"
#include "../../matched/include/Obj02185.h"
#include "../../matched/include/Obj06481.h"
#include "../../matched/include/Obj00501.h"
#include "../../matched/include/Obj00913.h"
#include "../../matched/include/Obj14058.h"
#include "../../matched/include/Obj14059.h"
#include "../../matched/include/Obj14060.h"
#include "../../matched/include/Obj02186.h"
#include "../../matched/include/Obj04507.h"
#include "../../matched/include/Obj10501.h"
#include "../../matched/include/Obj02187.h"
#include "../../matched/include/Obj03283.h"
#include "../../matched/include/Obj10502.h"
#include "../../matched/include/Obj14061.h"
#include "../../matched/include/Obj08140.h"
#include "../../matched/include/Obj23118.h"
#include "../../matched/include/Obj08141.h"

struct Cfg;
struct Bank;
struct PalAnmSlot;
struct Descriptor;
struct Obj;
struct Actor;
struct Vec2;
struct PtS;
struct Grid;
struct Bmp;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct StrObj;
struct Sys;
struct U16Vec;
struct CharBuf;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021D97FC;

typedef unsigned int u32;

typedef struct  {
    unsigned words[7];
}
Config;

typedef signed int     s32_021D9890;

typedef struct { u16 x,y,frame; u8 speed,flag; } Params;

typedef short s16_021D9D44;

typedef signed char s8;

typedef int s32_021D9D44;

typedef struct {
    s16_021D9D44 x;
    s16_021D9D44 y;
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} L;

typedef short s16_021D9E60;

typedef struct { s16_021D9E60 x,y; } Pair_021D9E60;

typedef struct { u16 x,y; } Pair_021D9E98;

typedef struct { u16 x,y; } Pair_021D9EE8;

typedef signed short   s16_021D9FF0;

typedef short s16_021DA004;

typedef short s16_021DA1A8;

typedef struct { s16_021DA1A8 x,y,z,w; } Position;

typedef short s16_021DA320;

typedef struct { s16_021DA320 x,y; } Pair_021DA320;

typedef short s16_021DA3D0;

typedef short s16_021DA3FC;

typedef short s16_021DA42C;

typedef short s16_021DA454;

struct Param { void *bmp; s16_021DA454 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

typedef short s16_021DA578;

extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void func_020434DC(unsigned,unsigned);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32_021D9890 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202590C(struct Grid *g, s16_021D9FF0 x, s16_021D9FF0 y);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_0202570C(struct Grid *);
extern void func_02025588(void *);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *,u32,u32,u32,u16);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *,s16_021DA454,s16_021DA454,void *,void *,u16);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_020257D0(struct Obj *o);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045374(struct Cfg *cfg);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *,s16_021DA578,s16_021DA578,void *,void *);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045334(struct Descriptor *d);
extern void func_020409B4(u32);
int func_021D97FC(u8 *p,int value);
void func_021D9838(char *p,unsigned a);
void func_021D9890(char *p);
void func_021D99F0(char *p);
void func_021D9AB0(char *p);
void func_021D9BEC(char *p);
void func_021D9D44(char *p);
void func_021D9E48(char *p, int i, int a);
void func_021D9E60(u8 *p,int n);
void func_021D9E98(char *p,int i);
void func_021D9EE8(char *p,int i,int j);
void func_021D9F40(char *p);
void func_021D9FF0(char *p, int a, int b);
void func_021DA004(char *p);
int func_021DA158(int x,int flag);
void func_021DA164(void *p);
void func_021DA1A8(char *p,int animate);
void func_021DA320(char *p);
void func_021DA3B8(char *p);
void func_021DA3D0(u8 *p);
void func_021DA3FC(u8 *p);
void func_021DA42C(u8 *p);
void func_021DA454(u8 *p, int i, int a2, int a3, int a4);
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h);
void func_021DA578(void *p,int a,void *b,u32 c);
extern const Config d_020A1448;

/*
 * trailing: Two zero alignment bytes.
 * note: 2026-10-05 the count field is read in the loop condition and again at the return (as written by hand); this closed the count/flag register swap.
 */
int func_021D97FC(u8 *p,int value) { int i; int flag=0; for(i=0;i<*(int *)(p+0x23C);i++) { if(value==*(int *)(p+i*28+4)) flag=1; else if(flag==1) return i-1; } return *(int *)(p+0x23C)-1; }

void func_021D9838(char *p,unsigned a)  {
    Config c = d_020A1448;
    ((unsigned char *)&c)[8] = 16;
    ((unsigned char *)&c)[9] = 112;
    func_0204A48C((const struct Cfg *)(&c),a,50);
    func_020434DC(16,1);
    ((struct Obj14057 *)p)->f25C=func_0204B100(64,0,50);
    func_0204B270(((struct Obj14057 *)p)->f25C);
}

void func_021D9890(char *p)
{
    void *pal=((struct Obj02483 *)p)->f290;
    void *arc=((struct Obj02483 *)p)->f258;
    func_02049658(arc,6,1,0,0,0,50);
    func_020498F4(arc,10,1,0,0,0,50);
    func_02021640(pal,59,1,50,0,64,0);
    func_02049658(arc,7,5,0,0,0,50);
    func_020498F4(arc,11,5,0,0,0,50);
    func_02049B68(arc,2,4,0,0,50);
    ((struct Obj02483 *)p)->f260=func_0204ABF0(arc,0,0,0,50);
    ((struct Obj02483 *)p)->f26C=func_0204A6C8(arc,5,0,0,50);
    ((struct Obj02483 *)p)->f284=func_0204AF28(arc,12,15,50);
    ((struct Obj02483 *)p)->f268=func_0204ABF0(arc,4,0,32,50);
    ((struct Obj02483 *)p)->f274=func_0204A6C8(arc,9,0,0,50);
    ((struct Obj02483 *)p)->f28C=func_0204AF28(arc,14,17,50);
    ((struct Obj02483 *)p)->f264=func_0204ABF0(arc,3,0,64,50);
    ((struct Obj02483 *)p)->f270=func_0204A6C8(arc,8,0,0,50);
    ((struct Obj02483 *)p)->f288=func_0204AF28(arc,13,16,50);
    func_0201F5BC(4,1,11,0,50);
    func_02049B40(23,5,4,384,32,50);
}

/*
 * Extent ends with two bytes of zero alignment padding.
 */
void func_021D99F0(char *p)  {
    int i;
    char *q;
    for(i=0;i<((struct Obj10500 *)p)->f23C;i++) func_0204B3B4((struct Obj *)(*(int *)(p+i*28+12)));
    for(i=0;i<2;i++)  {
        q=p+i*28;
        func_0204B3B4((struct Obj *)(((struct Obj06480 *)q)->f15C));
        func_0204B3B4((struct Obj *)(((struct Obj06480 *)q)->f1E8));
    }
    for(i=0;i<3;i++) func_0204B3B4((struct Obj *)(*(int *)(p+i*28+0x194)));
    func_021DA3D0((u8 *)p);
    func_020452E8((struct Descriptor *)(((struct Obj10500 *)p)->f310));
    for(i=0;i<3;i++)  {
        q=p+i*4;
        func_0204ADA4(((struct Obj06480 *)q)->f260);
        func_0204A8D4(((struct Obj06480 *)q)->f26C);
        func_0204AFD8(((struct Obj06480 *)q)->f284);
    }
    func_0204B1CC((struct Bank *)(((struct Obj10500 *)p)->f25C));
    func_0204A5AC();
}

void func_021D9AB0(char *p)
{
    Params s;
    int j=0;
    int h=((struct Obj02185 *)p)->f25C;
    int i,k=0;
    unsigned q;
    s.x=0; s.y=0; s.frame=0; s.speed=10; s.flag=0;
    for(i=0;i<(int)((unsigned)((struct Obj02185 *)p)->f23C+2);i++) {
        q=(unsigned)p+(unsigned)k*28;
        if(i==(int)((unsigned)k+(unsigned)((struct Obj06481 *)q)->f150+1)) {
            s.x=76+(unsigned)i*8; s.y=24; s.frame=22;
            ((struct Obj06481 *)q)->f15C=(int)func_0204B294((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            k++;
        } else {
            s.x=76+(unsigned)i*8; s.y=24;
            q=(unsigned)p+(unsigned)j*28;
            s.frame=func_021DA158(((struct Obj06481 *)q)->f0,((struct Obj06481 *)q)->f8);
            ((struct Obj06481 *)q)->fC=(int)func_0204B294((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            j++;
        }
    }
    if(((struct Obj02185 *)p)->f334==0 && ((struct Obj02185 *)p)->f338==0) {
        func_0204B3DC((struct Obj *)((struct Obj02185 *)p)->f15C,0);
        func_0204B3DC((struct Obj *)((struct Obj02185 *)p)->f178,0);
    }
}

void func_021D9BEC(char *p)
{
    Params s;
    int h=((struct Obj00501 *)p)->f25C;
    s.x=0; s.y=0; s.frame=0; s.speed=0; s.flag=0;
    ((struct Obj00501 *)p)->f194=(int)func_0204B294((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1B0=(int)func_0204B294((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1CC=(int)func_0204B294((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    func_021D9E60((u8 *)p,0);
    func_0204B878((struct Obj *)(((struct Obj00501 *)p)->f194),0);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f194,1);
    ((struct Obj00501 *)p)->f1B8=0; ((struct Obj00501 *)p)->f1BA=0;
    ((struct Obj00501 *)p)->f1A4=1;
    func_021D9E98(p,0);
    func_0204B878((struct Obj *)(((struct Obj00501 *)p)->f1B0),((struct Obj00501 *)p)->f1A4);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f1B0,1);
    func_0204B688((struct Actor *)(((struct Obj00501 *)p)->f1B0),1);
    ((struct Obj00501 *)p)->f1D4=0; ((struct Obj00501 *)p)->f1D6=0;
    ((struct Obj00501 *)p)->f1C0=1;
    func_021D9E98(p,0);
    func_0204B878((struct Obj *)(((struct Obj00501 *)p)->f1CC),((struct Obj00501 *)p)->f1C0);
    func_0204B688((struct Actor *)(((struct Obj00501 *)p)->f1CC),1);
    func_0204B92C((struct Obj *)((struct Obj00501 *)p)->f1CC,1);
    func_021D9E48(p,1,0);
    func_021D9E48(p,2,0);
}


void func_021D9D44(char *p)
{
    L s;
    int h = ((struct Obj00913 *)p)->f25C;
    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 10;
    s.e = 0;
    ((struct Obj00913 *)p)->f1E8 = (int)func_0204B294((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    ((struct Obj00913 *)p)->f204 = (int)func_0204B294((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    s.x = (((struct Obj00913 *)p)->f2F2 + ((struct Obj00913 *)p)->f2F3) / 2;
    s.y = (((struct Obj00913 *)p)->f2F0 + ((struct Obj00913 *)p)->f2F1) / 2;
    func_0204B404((struct Obj *)(((struct Obj00913 *)p)->f1E8), (const struct Vec2 *)(&s), 0);
    func_0204B878((struct Obj *)(((struct Obj00913 *)p)->f1E8), 0);
    s.x = (((struct Obj00913 *)p)->f2F6 + ((struct Obj00913 *)p)->f2F7) / 2;
    s.y = (((struct Obj00913 *)p)->f2F4 + ((struct Obj00913 *)p)->f2F5) / 2;
    func_0204B404((struct Obj *)(((struct Obj00913 *)p)->f204), (const struct Vec2 *)(&s), 0);
    func_0204B878((struct Obj *)(((struct Obj00913 *)p)->f204), 0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D9E48(char *p, int i, int a)
{
    func_0204B3DC(*(void **)(p + i * 0x1c + 0x194), a);
}

/*
 * lever: Load actor into a local before the current-index store.
 */
void func_021D9E60(u8 *p,int n) { Pair_021D9E60 s; void *actor; actor=*(void **)(p+n*28+12); ((struct Obj14058 *)p)->f188=n; func_0204B454(actor,(struct PtS *)&s,0); s.y+=16; func_0204B404(((struct Obj14058 *)p)->f194,(const struct Vec2 *)(&s),0); }

void func_021D9E98(char *p,int i)
{
    Pair_021D9E98 s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    func_0204B404((struct Obj *)(((struct Obj14059 *)p)->f1B0),(const struct Vec2 *)(&s),0);
    func_0204B8C4((struct Obj *)(((struct Obj14059 *)p)->f1B0),0);
}

void func_021D9EE8(char *p,int i,int j)
{
    Pair_021D9EE8 s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    func_0204B404((struct Obj *)(*(int *)((p+0x194)+j*0x1c)),(const struct Vec2 *)(&s),0);
    func_0204B8C4((struct Obj *)(*(int *)((p+0x194)+j*0x1c)),0);
}

void func_021D9F40(char *p)
{
    int i;
    for(i=1;i<3;i++){
        int a=func_0204B898(*(void **)(p+i*0x1c+0x194));
        if(a==3){
            if(func_0204B98C(*(void **)(p+i*0x1c+0x194))==0){
                func_0204B878(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
                func_021D9E48(p,2,0);
            }
        }else{
            if(a!=*(int *)(p+i*0x1c+0x188)) func_0204B878(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
            if(func_0204B898(*(void **)(p+i*0x1c+0x194))!=3){
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
            }
        }
    }
}


void func_021D9FF0(char *p, int a, int b)
{
    if (p != 0)
        func_0202590C((struct Grid *)p, (short)a, (short)b);
}

/*
 * Extent ends with two bytes of zero alignment padding.
 * Lever: declare the 4-byte-stride pointer before the 28-byte-stride pointer.
 */
void func_021DA004(char *p)
{
    int i;
    char *r,*q;
    s16_021DA004 x,y;
    for(i=0;i<2;i++) {
        r=p+i*4;
        x=((struct Obj04507 *)r)->f2F2+20;
        y=(((struct Obj04507 *)r)->f2F0+((struct Obj04507 *)r)->f2F1)/2;
        y-=7;
        q=p+i*28;
        switch(((struct Obj02186 *)q)->f1DC) {
        case 0:
            ((struct Obj02186 *)q)->f1F4=0;
            break;
        case 1:
            ((struct Obj02186 *)q)->f1F4+=1;
            if(((struct Obj02186 *)q)->f1F4==1) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),1);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==2) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),2);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==10) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
                ((struct Obj02186 *)q)->f1DC+=1;
            }
            break;
        default:
            func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
            func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            ((struct Obj02186 *)q)->f1DC=0;
            break;
        }
    }
}

int func_021DA158(int x,int flag) { int n; n=0; if(!flag) n=11; return n+x; }


void func_021DA164(void *p)
{
    unsigned char *b = (unsigned char *)p;
    int i;

    for (i = 0; i < ((struct Obj10501 *)b)->f23C; i++)
    {
        if (i >= ((struct Obj10501 *)b)->f248 && i < ((struct Obj10501 *)b)->f24C)
            *(int *)(b + i * 0x1c + 8) = 1;
        else
            *(int *)(b + i * 0x1c + 8) = 0;
    }
}

/*
 * Lever: declare i before y, initialise j after loading y, and keep the equality arm separate.
 */
void func_021DA1A8(char *p,int animate)
{
    Position s;
    int i,j;
    s16_021DA1A8 y=*(s16_021DA1A8 *)((unsigned)p+(unsigned)((struct Obj03283 *)p)->f240*2+0x214);
    unsigned q;
    j=0;
    for(i=0;i<((struct Obj03283 *)p)->f23C;i++) {
        if(i>=((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) {
            if(i==((struct Obj03283 *)p)->f248) y+=20;
            else y+=32;
        } else {
            if(i==0) y+=20;
            else y+=8;
        }
        q=(unsigned)p+(unsigned)i*28;
        func_0204B454((struct Actor *)((struct Obj02187 *)q)->fC,(struct PtS *)&s.z,0);
        if(animate==0) {
            s.z=y;
            func_0204B404((struct Obj *)(((struct Obj02187 *)q)->fC),(const struct Vec2 *)(&s.z),0);
        } else {
            ((struct Obj02187 *)q)->f14=(y-s.z)/4;
            ((struct Obj02187 *)q)->f16=0;
            ((struct Obj02187 *)q)->f18=4;
            ((struct Obj02187 *)q)->f19=0;
        }
        q=(unsigned)p+(unsigned)j*28;
        if(i==((struct Obj02187 *)q)->f150 && j!=2) {
            func_0204B454((struct Actor *)((struct Obj02187 *)q)->f15C,(struct PtS *)&s,0);
            if(((struct Obj03283 *)p)->f248==((struct Obj03283 *)p)->f24C) y+=8;
            else {
                if(i>((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) y+=20;
                else y+=8;
            }
            if(animate==0) {
                s.x=y;
                func_0204B404((struct Obj *)(((struct Obj02187 *)q)->f15C),(const struct Vec2 *)(&s),0);
            } else {
                ((struct Obj02187 *)q)->f164=(y-s.x)/4;
                ((struct Obj02187 *)q)->f166=0;
                ((struct Obj02187 *)q)->f168=4;
            }
            j++;
        }
    }
}

void func_021DA320(char *p)
{
    int i;
    int x,y;
    Pair_021DA320 s;
    for(i=0;i<((struct Obj10502 *)p)->f23C;i++){
        if(i>=((struct Obj10502 *)p)->f248 && i<((struct Obj10502 *)p)->f24C){
            x=16;
            y=16;
        }else{
            x=4;
            y=8;
        }
        func_0204B454(*(void **)(p+i*0x1c+12),(struct PtS *)&s,0);
        (*(u8 **)(p+i*0x1c+16))[0]=s.y-y;
        (*(u8 **)(p+i*0x1c+16))[2]=s.x-x;
        (*(u8 **)(p+i*0x1c+16))[1]=s.y+y;
        (*(u8 **)(p+i*0x1c+16))[3]=s.x+x;
    }
}


void func_021DA3B8(char *p)
{
    void *x = func_02025538(0x32, ((struct Obj14061 *)p)->f25C);

    ((struct Obj14061 *)p)->f300 = x;
}

/*
 * trailing: Two zero alignment bytes.
 */
void func_021DA3D0(u8 *p) { func_0204ADA4(((struct Obj08140 *)p)->f30C); func_0202570C(*(struct Grid * *)&((struct Obj08140 *)p)->f304); func_0202570C(*(struct Grid * *)&((struct Obj08140 *)p)->f308); func_02025588(((struct Obj08140 *)p)->f300); }

void func_021DA3FC(u8 *p) { void *f; f=func_020490F4(23,50); ((struct Obj23118 *)p)->f30C=func_0204ACEC(f,5,0,128,50); func_02049238(f); }

/*
 * prototype: Original calls visibly load r2/r3 and outgoing stack zero; retain those arguments despite the matched callee declaring only two.
 */
void func_021DA42C(u8 *p) { int zero; func_021DA3FC(p); zero=0; func_021DA454(p,0,78,165,zero); func_021DA454(p,1,172,165,zero); }

/*
 * lever: Expand each coordinate base at its read; binding the base to a
 * pointer local swaps r2/r3 and leaves six bytes different.
 */
void func_021DA454(u8 *p, int i, int a2, int a3, int a4)
{
    void *bank,*msg,*bmp;
    struct Param q;
    s16_021DA454 y;
    u16 x;
    int zero=0;
    bank=func_02045B38(0,2,25,50);
    msg=func_02045EC0(bank,i+3);
    bmp=func_02043678(10,2,32,50);
    func_0201C7D0(bmp,(80-(int)func_0201D304(msg,*(u32 *)&((struct Obj08141 *)p)->f314,0))/2,0,msg,((struct Obj08141 *)p)->f314,0x3dc0);
    x=(p+(i+22)*4)[0x29a]+20;
    y=((p+(i+22)*4)[0x298]+(p+(i+22)*4)[0x299])/2;
    q.bmp=bmp;
    q.x=x;
    q.y=y-7;
    q.f8=((struct Obj08141 *)p)->f264;
    q.fc=zero;
    q.f10=zero;
    q.f11=zero;
    q.f12=zero;
    q.f14=zero;
    *(void **)(p+0x304+i*4)=func_020255A0(((struct Obj08141 *)p)->f300,&q);
    func_020257D0(*(void **)(p+0x304+i*4));
    func_020437AC(bmp);
    func_02045808(msg);
    func_02045C04(bank);
}

/*
 * extent: Two zero alignment bytes at 0x021DA576; next labelled function is 0x021DA578.
 */
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h)
{
    *p=(void *)func_020450F0((u8)b,(u8)c,(u8)d,(u8)e,f,12,1);
    func_0201F73C(*p,2,1,11);
    func_02045374(*p);
    func_021DA578(*p,a,(void *)g,h);
}

void func_021DA578(void *p,int a,void *b,u32 c)
{
    void *ws=func_0201EC64(50);
    void *bank=func_02045B38(0,2,25,50);
    void *msg=func_02045EC0(bank,a);
    void *out=func_020457B0(88,50);
    func_0201EFA4(ws,0,c,2,2,1);
    func_0201F250(ws,out,msg);
    func_02043B5C(func_02045770(p),15);
    func_0201C7A4(func_02045770(p),0,0,out,b);
    func_02045808(out);
    func_02045808(msg);
    func_02045C04(bank);
    func_0201ED04(ws);
    func_02045334(p);
    func_020409B4(4);
}
