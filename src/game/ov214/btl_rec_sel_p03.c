/*
 * file:     btl_rec_sel_p03.c
 * unit:     yes
 * function: func_021BA074, func_021BA0B0, func_021BA0DC, func_021BA108, func_021BA16C, func_021BA190, func_021BA254, func_021BA2B8, func_021BA2F4, func_021BA39C, func_021BA3A0, func_021BA3C4
 * address:  0x021BA074
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02035630 0x02035630 arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C38 0x02035C38 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0203FA08 0x0203FA08 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02030734 0x02030734 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021BB658 0x021BB658 data a1
 *   func_0201FDA0 0x0201FDA0 thumb
 *   func_020450F0 0x020450F0 arm
 *   d_021BB480 0x021BB480 data a1
 */
#include "../../matched/include/Obj10935.h"
#include "../../matched/include/Obj25724.h"
#include "../../matched/include/Obj14700.h"
#include "../../matched/include/Obj01782.h"
#include "../../matched/include/Obj04632.h"
#include "../../matched/include/Obj01082.h"
#include "../../matched/include/Obj04633.h"
#include "../../matched/include/Obj10937.h"
#include "../../matched/include/Obj00182.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct Rec;
struct PrintSys;
struct WinDat;
struct BmpMenu;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct {u8 a,b,c,d,e,f;} Rec;

typedef struct {Rec r[4];} Table;

extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_02041B6C(unsigned);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned char func_02045730(struct Descriptor *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern void*func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern u8 func_02035630(void);
extern unsigned func_0201CE30(void*);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void*);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(unsigned);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern unsigned func_0203FA08(unsigned,unsigned,unsigned);
extern void func_0203FB44(unsigned,unsigned,unsigned);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void*func_02030734(unsigned,unsigned,int,const char*,u16);
extern void func_02040E78(unsigned,void*,unsigned,unsigned);
extern u32 func_020307B0(void *p);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
void func_021BA074(int unused,char *p);
void func_021BA0A4(int unused,char *p);
void func_021BA0B0(int unused, char *p);
void func_021BA0DC(int unused,char *p);
void func_021BA108(int unused,char*p,unsigned entry,int v);
int func_021BA16C(int a,char *p);
int func_021BA190(int unused,char*p);
void func_021BA254(void*obj,char*p,unsigned entry);
u32 func_021BA2B8(int unused,u8 *p);
void func_021BA2F4(int unused,char*p);
void func_021BA39C(int unused, char *p);
void func_021BA3A0(int unused,u8 *p);
void func_021BA3C4(int unused,char*p);
extern const char d_021BB658[];
extern const Table d_021BB480;

/*
 * Parameter evidence: original narrows third input to u16 before func_0201F73C.
 */
void func_021BA074(int unused,char *p){struct Descriptor *d;func_0201F73C(((struct Obj10935 *)p)->f6C,1,(unsigned short)(((struct Obj10935 *)p)->f74),10);d=*(struct Descriptor * *)&((struct Obj10935 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}

void func_021BA0A4(int unused,char *p){func_0201F7A8(((struct Obj25724 *)p)->f6C,(int)1);}

void func_021BA0B0(int unused, char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(((struct Obj14700 *)p)->f6C), 15);
    d = ((struct Obj14700 *)p)->f6C;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
}

/*
 * Tail: two zero alignment bytes at 021BA106.
 */
void func_021BA0DC(int unused,char *p){struct Descriptor *d;func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C),0);d=*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));}

/*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 */
void func_021BA108(int unused,char*p,unsigned entry,int v)
{
    int x;
    func_02043B5C(func_02045770(*(void* *)&((struct Obj01782 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01782 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj01782 *)p)->f5C);
    if(*(void* *)&((struct Obj01782 *)p)->f78)func_02045808(*(void* *)&((struct Obj01782 *)p)->f78);
    *(void* *)&((struct Obj01782 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01782 *)p)->f58,entry);
    x=func_02012FFC();
    *(void* *)&((struct Obj01782 *)p)->f5C=func_0201CCE4(*(unsigned *)&((struct Obj01782 *)p)->f6C,0,0,*(unsigned *)&((struct Obj01782 *)p)->f78,((struct Obj01782 *)p)->f8,x,((struct Obj01782 *)p)->f68,2,((struct Obj01782 *)p)->f0,15);
    ((struct Obj01782 *)p)->f60=v;
}

int func_021BA16C(int a,char *p){int result=func_021BA190(a,p);if(result==0){if(func_02035630()==30)result=func_021BA190(a,p);}return result;}

int func_021BA190(int unused,char*p)
{
    int result=0;
    switch(func_0201CE30(*(void* *)&((struct Obj04632 *)p)->f5C)){
    case 0:
        if((func_0203630C()&3)||func_02035C38()){
            func_0201CE5C(*(void* *)&((struct Obj04632 *)p)->f5C,0);
            if(func_0203630C()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 1:
        if((func_020362DC()&3)||func_02035C60()){
            func_020061E4(0x547);
            func_0201CE38(*(void* *)&((struct Obj04632 *)p)->f5C);
            if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 2:
        if(((struct Obj04632 *)p)->f64)--((struct Obj04632 *)p)->f64;
        else if(((struct Obj04632 *)p)->f60){
            if((func_020362DC()&3)||func_02035C60()){
                if(func_020362DC()&3)func_020355D8(0);else func_020355D8(1);
                ((struct Obj04632 *)p)->f60=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}

void func_021BA254(void*obj,char*p,unsigned entry)
{
    func_02043B5C(func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01082 *)p)->f5C)func_0201CE48(*(void* *)&((struct Obj01082 *)p)->f5C);
    *(int *)&((struct Obj01082 *)p)->f5C=0;
    if(*(void* *)&((struct Obj01082 *)p)->f78)func_02045808(*(void* *)&((struct Obj01082 *)p)->f78);
    *(void* *)&((struct Obj01082 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01082 *)p)->f58,entry);
    *(int *)&((struct Obj01082 *)p)->f7C=0;
    func_0201C6FC(*(void* *)&((struct Obj01082 *)p)->fC,(unsigned)func_02045770(*(void* *)&((struct Obj01082 *)p)->f6C),0,0,*(void* *)&((struct Obj01082 *)p)->f78,((struct Obj01082 *)p)->f8);
    func_021BA2B8((int)obj,(u8 *)p);
}

u32 func_021BA2B8(int unused,u8 *p){struct Descriptor *d;if(((struct Obj01082 *)p)->f7C==0){if(func_0201C6C4(*(struct PrintSys * *)&((struct Obj01082 *)p)->fC,func_02045770(*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C))==0){d=*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C;func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));((struct Obj01082 *)p)->f7C=1;}}return ((struct Obj01082 *)p)->f7C;}

void func_021BA2F4(int unused,char*p)
{
    unsigned off;
    u16*colors;
    off=func_0203FA08(1,0x500,1);
    func_0203FB44(1,off,0x500);
    func_02049B40(0x17,5,0,0x160,0x20,((struct Obj04633 *)p)->f0);
    colors=func_02030734(((struct Obj04633 *)p)->f0,6,1,d_021BB658,0x6f9);
    colors[0]=0x294b;colors[1]=0x5694;colors[2]=0x7fff;
    func_02040E78(2,colors,6,0x17a);
    func_020307B0(colors);
    ((struct Obj04633 *)p)->f80=1;((struct Obj04633 *)p)->f81=0x18;((struct Obj04633 *)p)->f82=0xd;((struct Obj04633 *)p)->f83=0xb;
    ((struct Obj04633 *)p)->f84=off;
}

void func_021BA39C(int unused, char *p){}

void func_021BA3A0(int unused,u8 *p){*(struct BmpMenu * *)&((struct Obj10937 *)p)->f88=func_0201FDA0((const struct WinDat *)(p+0x80),((struct Obj10937 *)p)->f74,10,0,((struct Obj10937 *)p)->f0);}

void func_021BA3C4(int unused,char*p)
{
    Table t=d_021BB480;
    u8 i;
    for(i=0;i<4;i++){
        *(unsigned*)(p+i*4+0x8c)=func_020450F0(t.r[i].a,t.r[i].b,t.r[i].c,t.r[i].d,t.r[i].e,9,t.r[i].f);
        func_02043B5C(func_02045770(*(void**)(p+i*4+0x8c)),0);
        *(int*)(p+i*4+0x9c)=1;
    }
    ((struct Obj00182 *)p)->fBC=0;
    ((struct Obj00182 *)p)->fC0=0;
}
