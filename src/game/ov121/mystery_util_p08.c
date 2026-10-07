/*
 * file:     mystery_util_p08.c
 * unit:     yes
 * function: func_021DA890, func_021DA898, func_021DA8AC, func_021DA8B0, func_021DA8B8, func_021DA8C0, func_021DA8C4, func_021DA8CC, func_021DA958, func_021DA978, func_021DA994, func_021DA9EC, func_021DA9F0, func_021DA9F8, func_021DAA28
 * address:  0x021DA890
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 */
#include "../../matched/include/Obj13955.h"
#include "../../matched/include/Obj06451.h"
#include "../../matched/include/Obj08095.h"
#include "../../matched/include/Obj10414.h"
#include "../../matched/include/Obj10415.h"
#include "../../matched/include/Obj03787.h"
#include "../../matched/include/Obj22897.h"
#include "../../matched/include/Obj05358.h"
#include "../../matched/include/Obj02470.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct U16Vec;
struct CharBuf;
struct Obj;
struct MsgBank;
struct PrintSys;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc;

typedef struct { int x,y; } Pair;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_020457B0(int,u16);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020257D0(struct Obj *o);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void func_021DA890(void *p);
void func_021DA898(char *p);
int func_021DA8AC(u32 *p);
void func_021DA8B0(u32 *p,u32 a);
void func_021DA8B8(u32 *p);
void func_021DA8C0(u32 *p,u32 a);
void func_021DA8C4(u32 *p);
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap);
void func_021DA958(u8 *p);
void func_021DA978(char *p);
void func_021DA994(char *p,int a,int b,int c);
void func_021DA9EC(u8 *p,int a);
void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c);
int func_021DA9F8(u8 *p);
void func_021DAA28(char *p,int a,int *out);
extern char d_021DFBA0[];

void func_021DA890(void *p) { func_020307B0(p); }


void func_021DA898(char *p)
{
    if (((struct Obj13955 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13955 *)p)->fC);
}


int func_021DA8AC(u32 *p) { return p[1]; }


void func_021DA8B0(u32 *p,u32 a) { p[0]=a; p[2]=0; }


void func_021DA8B8(u32 *p) { p[1]=1; }


void func_021DA8C0(u32 *p,u32 a) { p[4]=a; }


void func_021DA8C4(u32 *p) { p[2]=p[4]; }

/*
 * lever: a and b are u16; the descriptor input pointer is const.
 */
void *func_021DA8CC(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    func_02082BCC(out,0,36);
    ((struct Obj06451 *)out)->f20=g;
    ((struct Obj06451 *)out)->f18=func_020457B0(128,heap);
    ((struct Obj06451 *)out)->f0=func_02043678(a,b,32,heap);
    func_02082BCC(&desc,0,24);
    desc.win=((struct Obj06451 *)out)->f0;
    desc.x=((struct Obj08095 *)p)->f0;
    desc.y=((struct Obj08095 *)p)->f2;
    desc.z=c;
    desc.a=((struct Obj08095 *)p)->f6;
    desc.c=e;
    desc.d=e;
    desc.b=((struct Obj08095 *)p)->f7;
    desc.pal=d;
    ((struct Obj06451 *)out)->f1C=func_020255A0(f,(const struct Param *)(&desc));
    return out;
}

void func_021DA958(u8 *p) { func_0202570C(((struct Obj10414 *)p)->f1C); func_020437AC(((struct Obj10414 *)p)->f0); func_02045808(((struct Obj10414 *)p)->f18); func_020307B0(p); }


/*
 * Addresses are Black-image addresses.
 */
void func_021DA978(char *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj10415 *)p)->f0), (unsigned char)(((struct Obj10415 *)p)->f4 & 0x1f));
    func_020257D0(((struct Obj10415 *)p)->f1C);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    func_02043B5C((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    func_02045CAC((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    func_021DAA28(p,c,xy);
    func_0201C724(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],(u32)(((struct Obj03787 *)p)->f18),c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}


void func_021DA9EC(u8 *p,int a) { ((struct Obj22897 *)p)->f4=a; }


void func_021DA9F0(u32 *p,u32 a,u32 b,u32 c) { p[3]=a; p[4]=b; p[5]=c; }

int func_021DA9F8(u8 *p) { if(((struct Obj05358 *)p)->f8) { if(func_0201C6C4((struct PrintSys *)(((struct Obj05358 *)p)->f20),(void *)(((struct Obj05358 *)p)->f0))==0) { func_020257D0(((struct Obj05358 *)p)->f1C); ((struct Obj05358 *)p)->f8=0; } } if(((struct Obj05358 *)p)->f8==0) return 1; return 0; }

/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: case 0 is an eight-byte aggregate copy (existing pair-copy idiom).
 */
void func_021DAA28(char *p,int a,int *out)
{
    int x,y;
    switch(((struct Obj02470 *)p)->f14) {
    case 0:
        *(Pair *)out=*(Pair *)(p+12);
        break;
    case 1:
        x=func_020437DC((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        y=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D304(((struct Obj02470 *)p)->f18,a,0)/2;
        y-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=x+((struct Obj02470 *)p)->fC;
        out[1]=y+((struct Obj02470 *)p)->f10;
        break;
    case 2:
        x=func_020437E4((const struct Bmp *)(((struct Obj02470 *)p)->f0))/2;
        x-=func_0201D42C(((struct Obj02470 *)p)->f18,(void *)a)/2;
        out[0]=((struct Obj02470 *)p)->fC;
        out[1]=x+((struct Obj02470 *)p)->f10;
        break;
    }
}
