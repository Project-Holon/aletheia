/*
 * file:     psel_p05.c
 * unit:     yes
 * function: func_021BA8D0, func_021BA984, func_021BAA30
 * address:  0x021BA8D0
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC520 0x021BC520 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021BAA5C 0x021BAA5C thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../../matched/include/Obj02939.h"
#include "../../matched/include/Obj00211.h"

struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Request {u16 x,y,z;u8 a,b;};

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(unsigned,int,int,int,int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,unsigned);
extern unsigned func_021BC520(unsigned char *p);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BAA5C(char *p, int flag);
extern void func_0204B3B4(struct Obj *);
extern void func_0204AFD8(u32),func_0204A8D4(u32),func_0204ADA4(u32);
void func_021BA8D0(char *p);
void func_021BA984(char *p);
void func_021BAA30(char *p);

void func_021BA8D0(char *p)
{
    u8 i;
    switch(((struct Obj02939 *)p)->f214) {
    case 1:
        for(i=0;i<3;i++) func_0204B3DC(*(void **)(p+i*148+108),1);
        ((struct Obj02939 *)p)->f214=2;
        break;
    case 2:
        if(((struct Obj02939 *)p)->f210<16) {
            ++((struct Obj02939 *)p)->f210;
            if(((struct Obj02939 *)p)->f210==16) {
                for(i=0;i<3;i++) func_0204B688(*(void **)(p+i*148+108),0);
                ((struct Obj02939 *)p)->f214=3;
            }
            func_0207D63C(0x04001050,0,63,((struct Obj02939 *)p)->f210,16-((struct Obj02939 *)p)->f210);
        } else ((struct Obj02939 *)p)->f214=3;
        break;
    case 3:
        func_0207D63C(0x04001050,4,63,8,8);
        ((struct Obj02939 *)p)->f214=0;
        break;
    }
}

void func_021BA984(char *p)
{
    void *object;
    struct Request request;
    object=func_020490F4(205,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f21C=func_0204AC18(object,11,0,0,0,1,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f218=func_0204A6C8(object,17,0,0,((struct Obj00211 *)p)->f0);
    ((struct Obj00211 *)p)->f220=func_0204AF28(object,24,28,((struct Obj00211 *)p)->f0);
    func_02049238(object);
    func_02082BCC(&request,0,8);
    request.x=66;request.y=39;request.z=0;request.a=0;request.b=2;
    ((struct Obj00211 *)p)->f224=func_0204B294((void *)func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj00211 *)p)->f218,((struct Obj00211 *)p)->f21C,((struct Obj00211 *)p)->f220,&request,0,((struct Obj00211 *)p)->f0);
    func_0204B92C(((struct Obj00211 *)p)->f224,1);
    func_021BAA5C(p,0);
}

void func_021BAA30(char *p) {u32 off;off=0x224;func_0204B3B4(*(struct Obj **)(p+off));func_0204AFD8(*(u32 *)(p+off-4));func_0204A8D4(*(u32 *)(p+off-12));off-=8;func_0204ADA4(*(u32 *)(p+off));}
