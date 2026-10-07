/*
 * file:     manual_common_p01.c
 * unit:     yes
 * function: func_021B9B3C, func_021B9BA4, func_021B9BC8, func_021B9BD4, func_021B9BE0, func_021B9BEC, func_021B9BF8, func_021B9C0C, func_021B9C20, func_021B9C28, func_021B9C34, func_021B9C40, func_021B9C50, func_021B9C58, func_021B9C98, func_021B9CB0, func_021B9CC8, func_021B9CDC, func_021B9CE0, func_021B9CF0, func_021B9CFC, func_021B9D0C, func_021B9D18, func_021B9DEC, func_021B9E60, func_021B9E80, func_021B9EE8, func_021B9F20, func_021B9F24, func_021B9F8C, func_021B9FBC, func_021BA068, func_021BA0F0, func_021BA154, func_021BA158, func_021BA15C, func_021BA160, func_021BA1C0
 * address:  0x021B9B3C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0204A39C 0x0204A39C arm
 *   file 0x021BBFF4 data ov225 a1
 *   func_020307B0 0x020307B0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02009210 0x02009210 thumb
 *   func_020090E0 0x020090E0 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200EDEC  0x0200EDEC  thumb
 *   func_0200EE14 0x0200EE14 thumb
 *   func_021B9900 0x021B9900 thumb ov225
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B90 0x02049B90 arm
 *   d_021BC004 0x021BC004 data ov225 a1
 *   func_02049238 0x02049238 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B99A0 0x021B99A0 thumb ov225
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B99F4 0x021B99F4 thumb ov225
 *   func_020862F0 0x020862F0 arm
 *   func_0207EB78 0x0207EB78 arm
 *   func_02040588 0x02040588 arm
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   d_021BC014 0x021BC014 data a1
 *   func_021BA1C4 0x021BA1C4 thumb ov225
 *   func_021BA41C 0x021BA41C thumb ov225
 *   func_021BA644 0x021BA644 thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA4D8 0x021BA4D8 thumb ov225
 *   func_021BA218 0x021BA218 thumb ov225
 *   func_021B639C 0x021B639C thumb ov067
 *   func_02034A5C 0x02034A5C arm
 *   func_021BA240 0x021BA240 thumb ov225
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021BA508 0x021BA508 thumb ov225
 *   d_021BBF2C 0x021BBF2C data a4
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BA28C 0x021BA28C thumb ov225
 *   func_021BA2B0 0x021BA2B0 thumb ov225
 *   func_021BA30C 0x021BA30C thumb ov225
 *   func_021BA368 0x021BA368 thumb ov225
 *   d_021BBF4C 0x021BBF4C data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_021B62E0 0x021B62E0 thumb ov067
 */
#include "../../matched/include/Obj08466.h"
#include "../../matched/include/Obj26135.h"
#include "../../matched/include/Obj26138.h"
#include "../../matched/include/Obj26140.h"
#include "../../matched/include/Obj26141.h"
#include "../../matched/include/Obj26142.h"
#include "../../matched/include/Obj26143.h"
#include "../../matched/include/Obj01787.h"
#include "../../matched/include/Obj08467.h"
#include "../../matched/include/Obj04650.h"
#include "../../matched/include/Obj06734.h"
#include "../../matched/include/Obj26144.h"
#include "../../matched/include/Obj14802.h"
#include "../../matched/include/Obj00367.h"
#include "../../matched/include/Obj03964.h"
#include "../../matched/include/Obj01788.h"
#include "../../matched/include/Obj26145.h"
#include "../../matched/include/Obj26146.h"
#include "../../matched/include/Obj08468.h"
#include "../../matched/include/Obj26147.h"
#include "../../matched/include/Obj26148.h"

struct Big;
struct Sub02009210Obj;
struct Sub020090B0Obj;
struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct PrintSys;
struct Node;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct State {
    void *owner; u16 heap,pad6; void *screen;
    struct GfFont *font; u32 str10,str14,str18;
    struct MsgBank *bank1,*bank2;
    void *arc1,*arc2,*assets; u16 id,pad32; void *group;
};

typedef struct S S;

struct Entry {unsigned word[7];};

typedef struct {u8 *f0;u32 f4;int f8;u32 fC,f10,f14;int f18,f1c;} A;

typedef struct {int f0;u32 f4;int f8;u8 sub[0x14];u8 elem[1];} R;

struct Block {u32 words[16];};

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0204A39C(void *, int, int, u32, u32 *);
extern u32 func_020307B0(void *p);
extern void *func_02012EBC(struct Big *);
extern struct Sub02009210Obj *func_02009210(void *);
extern u8 func_020090E0(const struct Sub020090B0Obj *);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_020142E8(void *,int);
extern void *func_0200ED48(void *p);
extern int func_0200EDEC(char *obj, int i);
extern void func_0200EE14(char *obj, int i);
extern void *func_021B9900(u32,u32);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_021B99A0(char *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern void func_021B99F4(char *);
extern void func_020862F0(const void *,unsigned);
extern void func_0207EB78(const void *,unsigned,unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02034AC4(int);
extern void func_021BA1C4(char *);
extern void func_021BA41C(char *);
extern void func_021BA644(char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021BA4D8(char *);
extern void func_021BA218(char *);
extern void func_021B639C(unsigned char *);
extern void func_02034A5C(int);
extern void func_021BA240(char *);
extern void func_021B63D0(struct S *p);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern void func_021BA508(char *);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_021BA28C(char *);
extern void func_021BA2B0(char *);
extern void func_021BA30C(char *);
extern void func_021BA368(char *);
extern void func_02082BCC(void *,u8,u32);
extern u32 func_021B9A08(const u8 *p);
extern R *func_021B62E0(A *,int);
void *func_021B9B3C(void *narc, u32 heap);
void func_021B9BA4(char *p);
u16 func_021B9BC8(char *p,int index);
u16 func_021B9BD4(char *p,int index);
u16 func_021B9BE0(char *p,int index);
u16 func_021B9BEC(char *p,int index);
u16 func_021B9BF8(char *p, int idx, int c);
u16 func_021B9C0C(char *p, int idx, int c);
u16 func_021B9C20(const char *p);
u16 func_021B9C28(char *p,int index);
u16 func_021B9C34(char *p,int index);
u16 func_021B9C40(char *p, int idx, int c);
u16 func_021B9C50(const char *p);
int func_021B9C58(void *unused,int kind,void *save);
int func_021B9C98(void *unused, int b, int c);
void func_021B9CB0(void *unused,int code,struct Big *save);
int func_021B9CC8(unsigned unused,unsigned key);
int func_021B9CDC(void *a0);
int func_021B9CE0(char *p, int idx);
unsigned short func_021B9CF0(char *p,unsigned i);
int func_021B9CFC(char *p, int idx);
unsigned short func_021B9D0C(char *p,unsigned i);
void *func_021B9D18(void *owner,u16 heap);
void func_021B9DEC(char *p);
void func_021B9E60(char *p);
void func_021B9E80(char *p,unsigned id);
void func_021B9EE8(void *a0);
void func_021B9F20(void *a0);
void *func_021B9F24(char *owner);
void func_021B9F8C(char *p);
void func_021B9FBC(char *p);
void func_021BA068(char *p,unsigned state);
void func_021BA0F0(char *p,unsigned b,unsigned c);
unsigned func_021BA154(char *p);
unsigned func_021BA158(char *p);
void func_021BA15C(void *task,void *data);
void func_021BA160(char *p);
void func_021BA1C0(void *a0);
extern char file[];
extern const char d_021BC004[];
extern const char ov067_id[];
extern const char d_021BC014[];
extern const struct Entry d_021BBF2C[];
extern const struct Block d_021BBF4C;

void *func_021B9B3C(void *narc, u32 heap)
{
    void **p = func_02030734(heap, 16, 1, file, 0x9c);
    u32 size;
    p[0] = func_0204A39C(narc, 11, 0, heap, &size);
    p[1] = func_0204A39C(narc, 12, 0, heap, &size);
    p[2] = func_0204A39C(narc, 9, 0, heap, &size);
    p[3] = func_0204A39C(narc, 10, 0, heap, &size);
    return p;
}

void func_021B9BA4(char *p) {func_020307B0(((struct Obj08466 *)p)->fC);func_020307B0(((struct Obj08466 *)p)->f8);func_020307B0(((struct Obj08466 *)p)->f4);func_020307B0(((struct Obj08466 *)p)->f0);func_020307B0(p);}

u16 func_021B9BC8(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+6);}

u16 func_021B9BD4(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+8);}

u16 func_021B9BE0(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+10);}

u16 func_021B9BEC(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+12);}


/*
 * Addresses are Black-image addresses.
 */
u16 func_021B9BF8(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CE0(p, idx))[(c << 1) + 7];
}


u16 func_021B9C0C(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CE0(p, idx))[(c << 1) + 8];
}

u16 func_021B9C20(const char *p) {return **(u16 * *)&((struct Obj26135 *)p)->f4;}

u16 func_021B9C28(char *p,int index) {return *(u16 *)(func_021B9CFC(p,index)+2);}

u16 func_021B9C34(char *p,int index) {return *(u16 *)(func_021B9CFC(p,index)+4);}


u16 func_021B9C40(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CFC(p, idx))[c + 3];
}

u16 func_021B9C50(const char *p) {return **(u16 * *)&((struct Obj26138 *)p)->fC;}

int func_021B9C58(void *unused,int kind,void *save)
{
    int result=0;
    switch(kind) {
    case 0:result=1;break;
    case 1:
        if(func_020090E0((const struct Sub020090B0Obj *)func_02009210(func_02012EBC((struct Big *)save)))!=0)result=1;
        break;
    case 2:
        if(func_020142E8((void *)func_0201296C(save),2400)!=0)result=1;
        break;
    }
    return result;
}


int func_021B9C98(void *unused, int b, int c)
{
    return func_0200EDEC(func_0200ED48(func_02012EBC((struct Big *)c)), b);
}

void func_021B9CB0(void *unused,int code,struct Big *save) {func_0200EE14(func_0200ED48(func_02012EBC(save)),code);}

int func_021B9CC8(unsigned unused,unsigned key) {if(key!=65535)return 1;return 0;}

int func_021B9CDC(void *a0){return 0x48;}


int func_021B9CE0(char *p, int idx)
{
    return func_021B9CF0(p, idx) + ((struct Obj26140 *)p)->f0;
}

unsigned short func_021B9CF0(char *p,unsigned i){return *(unsigned short *)(((struct Obj26141 *)p)->f4+i*2+2);}


int func_021B9CFC(char *p, int idx)
{
    return func_021B9D0C(p, idx) + ((struct Obj26142 *)p)->f8;
}

unsigned short func_021B9D0C(char *p,unsigned i){return *(unsigned short *)(((struct Obj26143 *)p)->fC+i*2+2);}

void *func_021B9D18(void *owner,u16 heap)
{
    struct State *p=func_02030734(heap,0x38,1,d_021BC004,0x4b);
    p->owner=owner; p->heap=heap;
    p->screen=func_021B9900(1,p->heap);
    p->font=func_0201D7EC(23,0,0,0,p->heap);
    p->str10=func_0201C440((void *)(u32)p->heap);
    p->str14=func_0201C440((void *)(u32)p->heap);
    p->str18=func_0201C440((void *)(u32)p->heap);
    p->bank1=func_02045B38(0,2,61,p->heap);
    p->bank2=func_02045B38(0,2,62,p->heap);
    p->arc1=func_020490F4(223,p->heap);
    p->arc2=func_020490F4(231,p->heap);
    func_02049B90(23,5,4,0,64,32,p->heap);
    p->assets=func_021B9B3C(p->arc1,p->heap);
    func_021B9EE8(p);
    p->id=65535;
    func_021B9E80((char *)p,func_021B9CDC(p->assets));
    p->group=func_021B9F24((char *)p);
    return p;
}

void func_021B9DEC(char *p)
{
    func_021B9F8C(((struct Obj01787 *)p)->f34);func_021B9E80(p,0xffff);func_021B9F20(p);
    func_021B9BA4(((struct Obj01787 *)p)->f2C);func_02049238(((struct Obj01787 *)p)->f24);func_02049238(((struct Obj01787 *)p)->f28);
    func_02045C04(*(struct Rec * *)&((struct Obj01787 *)p)->f1C);func_02045C04(*(struct Rec * *)&((struct Obj01787 *)p)->f20);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);func_0201C4C0(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);
    func_0201D83C(((struct Obj01787 *)p)->fC);func_021B99A0(*(char * *)&((struct Obj01787 *)p)->f8);func_020307B0(p);
}

void func_021B9E60(char *p){func_0201C4E4(*(struct PrintSys * *)&((struct Obj08467 *)p)->f10);func_0201C4E4(*(struct PrintSys * *)&((struct Obj08467 *)p)->f14);func_0201C4E4(*(struct PrintSys * *)&((struct Obj08467 *)p)->f18);func_021B99F4(*(char * *)&((struct Obj08467 *)p)->f8);}

void func_021B9E80(char *p,unsigned id)
{
    if(((struct Obj04650 *)p)->f30!=id) {
        unsigned size;
        void *buf;
        ((struct Obj04650 *)p)->f30=id;
        if(((struct Obj04650 *)p)->f30==0xffff) {
            buf=func_02030734(((struct Obj04650 *)p)->f4,0x18000,1,d_021BC004,245);
            size=0x18000;
        } else {
            buf=func_0204A39C(((struct Obj04650 *)p)->f28,((struct Obj04650 *)p)->f30,1,((struct Obj04650 *)p)->f4,&size);
        }
        func_020862F0(buf,size);func_0207EB78(buf,0,0x18000);func_020307B0(buf);
    }
}

/*
 * volatile: 021B9EEC,021B9EF8 re-read 0400000C;021B9F02 read 04000008.
 */
void func_021B9EE8(void *a0){*(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;*(volatile unsigned short *)0x0400000C=(unsigned short)(*(volatile unsigned short *)0x0400000C&~3);*(volatile unsigned short *)0x04000008&=~0x40;func_02040588(2,1);}

void func_021B9F20(void *a0){}

void *func_021B9F24(char *owner)
{
    char *p;
    func_02034AC4((int)ov067_id);
    p=func_02030734(((struct Obj26144 *)owner)->f4,0x4c,1,d_021BC014,235);
    ((struct Obj06734 *)p)->f0=owner;func_021BA160(p);func_021BA1C0(p);func_021BA1C4(p);func_021BA41C(p);
    ((struct Obj06734 *)p)->f8=4;p[0xc]=0;p[0xd]=0;func_021BA068(p,0);func_021BA644(p);
    ((struct Obj06734 *)p)->f48=func_020056A0((unsigned)func_021BA15C,(unsigned)p,1);
    return p;
}

void func_021B9F8C(char *p){func_02030EAC(((struct Obj14802 *)p)->f48);func_021BA4D8(p);func_021BA218(p);func_021B639C(*(unsigned char * *)&((struct Obj14802 *)p)->f4);func_020307B0(p);func_02034A5C((int)ov067_id);}

void func_021B9FBC(char *p)
{
    ((struct Obj00367 *)p)->f24=-1;((struct Obj00367 *)p)->f28=-1;func_021BA240(p);
    if(((struct Obj00367 *)p)->f20==1) {((struct Obj00367 *)p)->f20=0;return;}
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==2) {
        func_021B63D0(*(S * *)&((struct Obj00367 *)p)->f4);
        if(((struct Obj00367 *)p)->f20==0) {
            int result=func_021B6470(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=2;((struct Obj00367 *)p)->f24=result;}
        } else {
            int result=func_021B6448(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=1;((struct Obj00367 *)p)->f28=result;}
        }
    }
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==3) {
        func_021BA508(p);
        if(((struct Obj00367 *)p)->f20==0) {
            if(((struct Obj00367 *)p)->f44==1) {((struct Obj00367 *)p)->f20=3;*(unsigned *)&((struct Obj00367 *)p)->f24=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        } else {
            if(((struct Obj00367 *)p)->f44==3) {((struct Obj00367 *)p)->f20=1;*(unsigned *)&((struct Obj00367 *)p)->f28=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        }
    }
}

void func_021BA068(char *p,unsigned state)
{
    if(((struct Obj03964 *)p)->f8==state)return;
    switch(((struct Obj03964 *)p)->f8) {
    case 0:func_021B6558(((struct Obj03964 *)p)->f4,0,0);break;
    case 3:func_0204B3DC(*(struct Obj * *)&((struct Obj03964 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj03964 *)p)->f3C,0);break;
    case 1:case 2:case 4:break;
    }
    ((struct Obj03964 *)p)->f8=state;func_021BA644(p);
    switch(((struct Obj03964 *)p)->f8) {
    case 0:func_021B6558(((struct Obj03964 *)p)->f4,0,1);func_021BA28C(p);break;
    case 1:func_021BA2B0(p);break;
    case 2:func_021BA30C(p);break;
    case 3:case 4:break;
    }
}

/*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 */
void func_021BA0F0(char *p,unsigned b,unsigned c)
{
    p[0xc]=b;p[0xd]=c;
    if(((struct Obj01788 *)p)->f8==3) {
        if(((struct Obj01788 *)p)->fC<=1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);func_021BA28C(p);return;
        }
        if(((struct Obj01788 *)p)->fD==0) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        } else if(((struct Obj01788 *)p)->fD==b-1) {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);
        } else {
            func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);func_0204B3DC(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        }
        func_021BA368(p);
    }
}

unsigned func_021BA154(char *p){return ((struct Obj26145 *)p)->f28;}

unsigned func_021BA158(char *p){return ((struct Obj26146 *)p)->f24;}

void func_021BA15C(void *task,void *data)
{
}

/*
 * lever: args before table declaration puts the 64-byte copy at sp+0.
 */
void func_021BA160(char *p)
{
    A args;
    struct Block table=d_021BBF4C;
    func_02082BCC(&args,0,sizeof(args));
    args.f0=(u8 *)&table;args.f4=2;
    args.f8=(int)func_021B9A08(((struct Obj26147 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f8);
    args.fC=6;args.f10=3;args.f14=1;args.f18=0;
    *(R * *)&((struct Obj08468 *)p)->f4=func_021B62E0(&args,((struct Obj26148 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f4);
    func_021B6558(((struct Obj08468 *)p)->f4,0,0);
}

void func_021BA1C0(void *a0){}
