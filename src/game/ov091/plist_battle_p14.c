/*
 * file:     plist_battle_p14.c
 * unit:     yes
 * function: func_021BC628, func_021BC6A0, func_021BC6C0, func_021BC6CC, func_021BCC2C, func_021BCC40, func_021BCC80, func_021BCCCC, func_021BCD80, func_021BCDE8, func_021BCE84, func_021BCE9C
 * address:  0x021BC628
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC1D0  0x021BC1D0  thumb  ov091
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BC350  0x021BC350  thumb  ov091
 *   func_021BE2B4  0x021BE2B4  thumb  ov091
 *   func_021BB2C0  0x021BB2C0  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov091
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02018328 0x02018328 thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_021B9E44 0x021B9E44 thumb ov091
 *   d_021BECE4 0x021BECE4 data ov091 a2
 *   func_021BB9DC  0x021BB9DC  thumb  ov091
 *   func_021BCEAC  0x021BCEAC  thumb  ov091
 *   func_021BD05C  0x021BD05C  thumb  ov091
 *   func_021BD59C  0x021BD59C  thumb  ov091
 *   func_021BD61C  0x021BD61C  thumb  ov091
 *   func_021BD18C  0x021BD18C  thumb  ov091
 *   func_021BD058  0x021BD058  thumb  ov091
 *   func_021BD1BC  0x021BD1BC  thumb  ov091
 *   func_021BD504  0x021BD504  thumb  ov091
 *   func_021BD634  0x021BD634  thumb  ov091
 *   func_021BA4F8  0x021BA4F8  thumb  ov091
 *   func_0204B100 0x0204B100 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj07736.h"
#include "../../matched/include/Obj00047.h"
#include "../../matched/include/Obj07737.h"
#include "../../matched/include/Obj01888.h"
#include "../../matched/include/Obj20910.h"
#include "../../matched/include/Obj20911.h"
#include "../../matched/include/Obj20912.h"
#include "../../matched/include/Obj20913.h"
#include "../../matched/include/Obj20914.h"
#include "../../matched/include/Obj20915.h"
#include "../../matched/include/Obj20916.h"
#include "../../matched/include/Obj20917.h"
#include "../../matched/include/Obj20918.h"
#include "../../matched/include/Obj13261.h"
#include "../../matched/include/Obj20919.h"

#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define S ((u8 *)W(0x280))
#define T(k) (*(u32 *)(S+(k)))
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct StrObj;
struct U16Vec;
struct WordSet;
struct Bank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern int func_021BC1D0(int);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BB050(int unused, u8 *s, int k);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BC350(u8 *p, int v);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_020061E4(u32 a);
extern void func_021BBA70(int, int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 func_02017E1C(void *p,u32 id,u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32,u32,s16,s16,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9EB0(u8 *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void func_021B9E44(u8 *);
extern void func_021BB9DC(int, int, int, int);
extern void func_021BCEAC(u8 *p);
extern u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w);
extern void func_021BD59C(char *p);
extern void func_021BD61C(char *a);
extern void func_021BD18C(char *a, char *p);
extern void func_021BD058(char *a);
extern void func_021BD1BC(char *a, int *b);
extern void func_021BD504(char *a);
extern void func_021BD634(u8 *p);
extern void func_021BA4F8(u8 *a);
extern struct Bank *func_0204B100(int,u8,unsigned int);
extern u32 func_0204B1CC(struct Bank *bank);
void func_021BC628(int p);
void func_021BC6A0(char *p);
void func_021BC6C0(char *p);
void func_021BC6CC(u8 *p);
int func_021BCC2C(void *p, int i, int a2);
void func_021BCC40(int p, int id);
void func_021BCC80(int p, int id, int v);
void func_021BCCCC(int p);
void func_021BCD80(char *a);
void func_021BCDE8(char *a);
void func_021BCE84(char *p);
void func_021BCE9C(unsigned int p);
extern u16 d_021BECE4[];


void func_021BC628(int p)
{
    int n = func_021BC1D0(p);
    func_021BB7A4((void *)p, (u32 *)(*(int *)&((struct Obj00009 *)p)->f150));
    func_021BB050(p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)), 3);
    ((struct Obj00009 *)p)->f2C = n;
    *(int *)&((struct Obj00009 *)p)->f38 = (int)func_0201AB28(**(void ** *)&((struct Obj00009 *)p)->f280, n);
    func_021BC350((u8 *)p, 0);
    func_021BE2B4((void *)(*(int *)&((struct Obj00009 *)p)->f38),
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44), 0,
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x30), ((struct Obj00009 *)p)->f0);
    func_021BB2C0((u8 *)p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)));
    func_020061E4(0x56f);
}


void func_021BC6A0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 0;
    *(int *)(((struct Obj07736 *)p)->f280 + 0x50) = 0;
    func_021BBA70((int)p, ((struct Obj07736 *)p)->f150);
}


void func_021BC6C0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 6;
}

void func_021BC6CC(u8 *p)
{
    u8 i,j,x;
    u32 q,result,off;
    switch(p[0xe]) {
    case 0: {
        u8 flag;
        u32 delta,buf,tmp,text;
        int y;
        u16 width;
        flag=0;
        W(0x130)=func_020450F0(0,1,1,14,12,14,1);
        func_0201F73C((void *)W(0x130),1,1,12);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)W(0x130))),15);
        q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q));
        for(i=0;i<6;i++) {
            off=i; off=off*2;
            delta=func_02017E1C((void *)W(0x38),*(u16 *)((u8 *)d_021BECE4+off),0)-*(u16 *)(p+off+0x124);
            if(delta>=10) flag=1;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),i+0x95); y=i<<4;
            func_0201C724(W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),0,(s16)(i<<4),buf,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)func_020457B0(0x20,H(0)); text=(u32)func_0201EC64(H(0));
            func_0201EFA4((struct WordSet *)text,0,delta,3,0,1); func_0201F250((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            func_0201C724(W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),(s16)(104-width),(s16)y,tmp,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf); func_02045808((struct U16Vec *)tmp); func_0201ED04((struct WordSet *)text);
        }
        for(j=0;j<6;j++) {
            x=flag==1 ? 72 : 80;
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9b);
            func_0201C724(W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),x,(s16)(j<<4),buf,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf);
        }
        p[0xe]=1; break;
    }
    case 1:
        if(func_0201C6C4((struct PrintSys *)W(0x140),(void *)((u32)func_02045770((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q)); p[0xe]=2;
        } break;
    case 2:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) { func_020061E4(0x547); p[0xe]=3; }
        break;
    case 3: {
        u16 width;
        u32 delta,buf,tmp,text;
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)W(0x130))),0x50,0,0x20,0x60,15);
        for(i=0;i<6;i++) {
            delta=func_02017E1C((void *)W(0x38),d_021BECE4[i],0);
            buf=(u32)func_02045EC0((struct MsgBank *)W(0x134),0x9c); tmp=(u32)func_020457B0(0x20,H(0)); text=(u32)func_0201EC64(H(0));
            func_0201EFA4((struct WordSet *)text,0,delta,3,0,1); func_0201F250((struct WordSet *)text,(void *)tmp,(void *)buf);
            width=func_0201D304((struct StrObj *)tmp,W(0x138),0);
            func_0201C724(W(0x140),(u32)func_02045770((struct Descriptor *)W(0x130)),(s16)(104-width),(s16)(i<<4),tmp,W(0x138),0x440);
            func_02045808((struct U16Vec *)buf); func_02045808((struct U16Vec *)tmp); func_0201ED04((struct WordSet *)text);
        }
        p[0xe]=4; break;
    }
    case 4:
        if(func_0201C6C4((struct PrintSys *)W(0x140),(void *)((u32)func_02045770((struct Descriptor *)W(0x130))))==0) {
            q=W(0x130); func_02045334((struct Descriptor *)q); func_02045374((struct Cfg *)q); func_02041B6C(func_02045730((struct Descriptor *)q)); p[0xe]=5;
        } break;
    case 5:
        if((func_020362DC()&1)||(func_020362DC()&2)||func_02035C60()==1) {
            p[0xe]=6; func_020061E4(0x547); func_020456F8((struct Descriptor *)W(0x130)); func_0201F7A8((void *)W(0x130),1); func_020452E8((struct Descriptor *)W(0x130)); W(0x130)=0;
        } break;
    case 6:
        result=func_02018328((void *)W(0x38),(u32 *)(S+0x50),H(0)); func_021BB7A4(p,(u32 *)W(0x150));
        if(result==0) { p[0xe]=7; return; }
        if(result==0xfffe) { p[0xe]=7; return; }
        if(result&0x8000) {
            *(u16 *)(S+0x46)=result-0x8000;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,*(u16 *)(S+0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150));
        } else {
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,result);
            func_021B9788(p,0x29,1,(int)func_021BC6C0); func_021BB98C(p,W(0x150));
        } break;
    case 7:
        func_02017E1C((void *)W(0x38),5,0);
        if(func_0201B2B0((void *)T(0),(void *)W(0x38),0,*(u16 *)(S+0x30),S[0x5f],0,H(0))!=0) {
            p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=9;
        } else {
            T(0x34)=5; T(0x3c)=W(0x2c); T(0x40)=10; func_021B9E44(p);
        } break;
    }
}

int func_021BCC2C(void *p, int i, int a2) { int r = 0; if (func_02017E1C(p,i,0)) r=1; return r; }


void func_021BCC40(int p, int id)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB99C(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    func_021B9788((u8 *)p, id, 1, (int)func_021B9E44);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}


void func_021BCC80(int p, int id, int v)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB99C(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    func_021BB9DC(p, *(int *)&((struct Obj00009 *)p)->f150, 1, v);
    func_021B9788((u8 *)p, id, 1, (int)func_021B9E44);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}


void func_021BCCCC(int p)
{
    int r;
    func_021BCE84((char *)p);
    func_021BCEAC((u8 *)p);
    r = ((struct Obj00047 *)p)->f280;
    if (((struct Obj07737 *)r)->f8C == 1) {
        switch (((struct Obj07737 *)r)->f64) {
        case 1:
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x74), 10, 0, 2);
            break;
        case 2:
            ((struct Obj00047 *)p)->f1F0 = (int)func_021BD05C((u8 *)p, (u32 *)(r + 0x68), 0, 0, 0);
            ((struct Obj00047 *)p)->f1F4 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x74), 0xb, 0, 0);
            ((struct Obj00047 *)p)->f1F8 = (int)func_021BD05C((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x80), 0x16, 0, 0);
            break;
        }
    }
    r = ((struct Obj00047 *)p)->f280;
    ((struct Obj00047 *)p)->f20C = ((struct Obj07737 *)r)->f94;
    ((struct Obj00047 *)p)->f20D = 0;
    if (((struct Obj07737 *)r)->f90 == 1) {
        func_021BD59C((char *)p);
    }
    ((struct Obj00047 *)p)->f24E = 0;
}


void func_021BCD80(char *a)
{
    if (((struct Obj20910 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f90 == 1)
        func_021BD61C(a);
    if (((struct Obj20911 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20912 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f64) {
        case 1:
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F4));
            break;
        case 2:
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F0));
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F4));
            func_021BD18C(a, (char *)(((struct Obj01888 *)a)->f1F8));
            break;
        }
    }
    func_021BD058(a);
    func_021BCE9C((unsigned int)a);
}


void func_021BCDE8(char *a)
{
    if (((struct Obj20913 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20914 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64) {
        case 1:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            break;
        case 2:
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F0));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F4));
            func_021BD1BC(a, (int *)(((struct Obj00009 *)a)->f1F8));
            break;
        }
    }
    if (((struct Obj00009 *)a)->f20C != ((struct Obj20915 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 && ((struct Obj00009 *)a)->fC == 2) {
        func_021BD504(a);
        ((struct Obj00009 *)a)->f20C = ((struct Obj20916 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94;
    }
    if (((struct Obj20917 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f90 == 1)
        func_021BD634((u8 *)a);
    if (((struct Obj20918 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f63 == 1)
        func_021BA4F8((u8 *)a);
}

void func_021BCE84(char *p) { *(struct Bank * *)&((struct Obj13261 *)p)->f1EC=func_0204B100(36,8,((struct Obj13261 *)p)->f0); }

void func_021BCE9C(unsigned int p) { func_0204B1CC((struct Bank *)(((struct Obj20919 *)p)->f1EC)); }
