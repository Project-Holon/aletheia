/*
 * file:     unit_021F604C.c
 * unit:     yes
 * function: func_021F604C, func_021F6060, func_021F6114, func_021F6158, func_021F6164, func_021F6194, func_021F6228, func_021F6280, func_021F62C8, func_021F62CC, func_021F62FC, func_021F6328
 * address:  0x021F604C
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_02035C38 0x02035C38 arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0203FA08 0x0203FA08 arm
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021F71A4 0x021F71A4 data a2
 */
#include "../../matched/include/Obj01296.h"
#include "../../matched/include/Obj02926.h"
#include "../../matched/include/Obj25747.h"
#include "../../matched/include/Obj10939.h"
#include "../../matched/include/Obj01590.h"
#include "../../matched/include/Obj02261.h"
#include "../../matched/include/Obj10940.h"
#include "../../matched/include/Obj05550.h"
#include "../../matched/include/Obj08425.h"
#include "../../matched/include/Obj06706.h"
#include "../../matched/include/Obj25748.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WordSet;
struct WinDat;
struct BmpMenu;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,unsigned,unsigned,void *,unsigned,unsigned,void *,unsigned,u16,u16);
extern unsigned func_0201CE30(void *);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE38(void *);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern unsigned func_0201FEBC(u8 *);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,unsigned short,unsigned char,unsigned char,unsigned short);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
void func_021F604C(void);
void func_021F6060(int unused,char *p);
void func_021F6114(void *unused,char *p);
void func_021F6158(void *unused, char *p);
void func_021F6164(void *unused, char *p);
void func_021F6194(char *object,char *p,unsigned entry);
int func_021F6228(void *unused,char *p);
void func_021F6280(int unused, unsigned char *q);
void func_021F62C8(int a0, char *a1);
void func_021F62CC(void *unused, char *p);
int func_021F62FC(int a,char *p);
int func_021F6324(int a,char *p);
void func_021F6328(void);
extern const u16 d_021F71A4[];


void func_021F604C(void)
{
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x3c);
}

void func_021F6060(int unused,char *p)
{
    func_02049B40(23,5,0,32,32,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f5C=func_020450F0(1,0,0,1,1,1,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01296 *)p)->f5C)),0);
    func_02045334((struct Descriptor *)((struct Obj01296 *)p)->f5C);
    ((struct Obj01296 *)p)->f58=func_020450F0(1,1,19,30,4,1,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01296 *)p)->f58)),15);
    func_02045334((struct Descriptor *)((struct Obj01296 *)p)->f58);
    ((struct Obj01296 *)p)->f60=(u32)func_0201F5DC((void *)1,2,0,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f64=(u32)func_02045B38(0,3,260,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f54=(u32)func_0203101C(((struct Obj01296 *)p)->f0,((struct Obj01296 *)p)->f0,1,0);
    func_0201DD78(1,2,15);
    func_02041B6C(1);
    ((struct Obj01296 *)p)->f50=0;
    ((struct Obj01296 *)p)->f68=0;
    ((struct Obj01296 *)p)->f6C=0;
    func_02040588(1,0);
}

void func_021F6114(void *unused,char *p)
{
    if(((struct Obj02926 *)p)->f50) func_0201CE48(((struct Obj02926 *)p)->f50);
    if(((struct Obj02926 *)p)->f68) func_02045808(((struct Obj02926 *)p)->f68);
    func_02031140(((struct Obj02926 *)p)->f54);
    func_02045C04(((struct Obj02926 *)p)->f64);
    func_0203FB44(1,(u16)((struct Obj02926 *)p)->f60,(u16)(((struct Obj02926 *)p)->f60>>16));
    func_020452E8(((struct Obj02926 *)p)->f58);
    func_020452E8(((struct Obj02926 *)p)->f5C);
}

void func_021F6158(void *unused, char *p)
{
    func_020310C4(((struct Obj25747 *)p)->f54);
}

void func_021F6164(void *unused, char *p)
{
    void *obj;
    func_0201F73C(((struct Obj10939 *)p)->f58, 0, (u16)(((struct Obj10939 *)p)->f60), 2);
    obj = ((struct Obj10939 *)p)->f58;
    func_02045334(obj);
    func_02045374(obj);
    func_020409B4(func_02045730(obj));
}

/*
 * evidence: CCE4 return widened because original stores live r0 after call.
 */
void func_021F6194(char *object,char *p,unsigned entry)
{
    void *text,*words,*buffer;
    func_02043B5C(func_02045770(((struct Obj01590 *)p)->f58),15);
    if(((struct Obj01590 *)p)->f50) func_0201CE48(((struct Obj01590 *)p)->f50);
    if(((struct Obj01590 *)p)->f68) func_02045808(((struct Obj01590 *)p)->f68);
    text=func_02045EC0(((struct Obj01590 *)p)->f64,entry);
    words=func_0201EC64(((struct Obj01590 *)p)->f0);
    func_0201EE84(words,0,((struct Obj02261 *)object)->f4);
    buffer=func_020457B0(256,((struct Obj01590 *)p)->f0);
    ((struct Obj01590 *)p)->f68=buffer;
    func_0201F250(words,buffer,text);
    func_0201ED04(words);
    func_02045808(text);
    ((struct Obj01590 *)p)->f50=func_0201CCE4(((struct Obj01590 *)p)->f58,0,0,((struct Obj01590 *)p)->f68,((struct Obj01590 *)p)->f8,func_02012FFC(),((struct Obj01590 *)p)->f54,2,((struct Obj01590 *)p)->f0,15);
}

int func_021F6228(void *unused,char *p)
{
    int result=0;
    switch(func_0201CE30(((struct Obj10940 *)p)->f50)) {
    case 0:
        if((func_0203630C()&3)!=0 || func_02035C38()!=0)
            func_0201CE5C(((struct Obj10940 *)p)->f50,0);
        break;
    case 1:
        if((func_020362DC()&3)!=0 || func_02035C60()!=0)
            func_0201CE38(((struct Obj10940 *)p)->f50);
        break;
    case 2:
        result=1;
        break;
    }
    return result;
}


void func_021F6280(int unused, unsigned char *q)
{
    int h = func_0203FA08(1, 0x500, 1);

    func_0203FB44(1, h, 0x500);
    q[0x70] = 1;
    q[0x71] = 0x18;
    q[0x72] = 0xd;
    q[0x73] = 1;
    ((struct Obj05550 *)q)->f74 = h;
    ((struct Obj05550 *)q)->f7C = 2;
}

void func_021F62C8(int a0, char *a1)
{

}

void func_021F62CC(void *unused, char *p)
{
    unsigned result;
    int flag;
    switch (((struct Obj08425 *)p)->f20) {
    case 0:
        break;
    case 1:
        result = func_0201FEBC(*(u8 * *)&((struct Obj08425 *)p)->f78);
        if (result != 0xffffffff) {
            if (result == 0) flag = 1;
            else flag = 0;
            ((struct Obj08425 *)p)->f7C = flag;
            ((struct Obj08425 *)p)->f20 = 2;
        }
        break;
    }
}

int func_021F62FC(int a,char *p){*(struct BmpMenu * *)&((struct Obj06706 *)p)->f78=func_0201FDA0((const struct WinDat *)(p+0x70),((struct Obj06706 *)p)->f60,2,0,((struct Obj06706 *)p)->f0);((struct Obj06706 *)p)->f7C=2;((struct Obj06706 *)p)->f20=1;return 1;}

/*
 * extent: includes cleared tiny follower func_021F6324; no further code included.
 */
int func_021F6324(int a,char *p){return ((struct Obj25748 *)p)->f7C;}

static inline void SetPriority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3)|(priority<<0));
}

/*
 * volatile: hardware 021F6336,6342,634E,6358,6362,636E,6392.
 */
void func_021F6328(void)
{
    unsigned i;
    func_020434DC(1,1);
    SetPriority(0);
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3002)|2);
    *(volatile u16 *)0x04000060 &= ~0x3010;
    *(volatile u16 *)0x04000060 &= ~0x3004;
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3000)|8);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,d_021F71A4+i*4);
    func_02046BE0(0,0);
}
