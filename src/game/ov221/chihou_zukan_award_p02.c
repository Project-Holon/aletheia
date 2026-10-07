/*
 * file:     chihou_zukan_award_p02.c
 * unit:     yes
 * function: func_021B9B18, func_021B9B84, func_021B9C4C, func_021B9CCC
 * address:  0x021B9B18
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040E78 0x02040E78 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045768 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BA2D8 0x021BA2D8 data a1
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9F90 0x021B9F90 thumb ov221
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BA140 0x021BA140 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../../matched/include/Obj02558.h"
#include "../../matched/include/Obj08453.h"
#include "../../matched/include/Obj06724.h"
#include "../../matched/include/Obj01592.h"
#include "../../matched/include/G_Vec2.h"
#include "../../matched/include/Obj02557.h"

struct Descriptor;
struct Cfg;
struct PrintSys;
struct CharBuf;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern unsigned char func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern void func_02040E78(u32,void*,u32,u32);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_02045768(struct Descriptor *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern void func_020409B4(u32);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_021B9F90(char *p);
extern struct Obj *func_0204B294(void *,unsigned,unsigned,unsigned,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
void func_021B9B18(unsigned char *p);
int func_021B9B64(unsigned char *p);
void func_021B9B84(char *p);
void func_021B9C4C(unsigned char *p);
void func_021B9CCC(char *p);
extern char d_021BA2D8[];
extern struct Vec2 d_021BA140;

void func_021B9B18(unsigned char *p)
{
    unsigned char i;
    unsigned char *row;
    struct Descriptor *resource;
    for(i=0;i<5;i++) {
        row=p+4*i;
        if(((struct Obj08453 *)row)->f30==0 && func_0201C6C4(*(struct PrintSys * *)&((struct Obj02558 *)p)->f10,func_02045770(*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C))==0) {
            resource=*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C;
            func_02045334(resource);
            func_02045374((struct Cfg *)resource);
            func_02041B6C(func_02045730(resource));
            ((struct Obj08453 *)row)->f30=1;
        }
    }
}

int func_021B9B64(unsigned char *p)
{
    unsigned char i;
    for(i=0;i<5;i++) if(*(int *)(p+0x30+4*i)==0) return 0;
    return 1;
}

void func_021B9B84(char *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=func_02030734(((struct Obj06724 *)p)->f0,32,1,d_021BA2D8,0x391);
 index=0;
 buf[0]=0;
 buf[1]=0x256c;
 buf[2]=0x4a74;
 buf[3]=0;
 func_02040E78(2,buf,32,480);
 func_020307B0(buf);
 func_02043B5C(func_02045770(*(void* *)&((struct Obj06724 *)p)->f20),3);
 func_02045334(*(void* *)&((struct Obj06724 *)p)->f20);
 tiles=func_02030734(((struct Obj06724 *)p)->f0,1536,1,d_021BA2D8,0x3a2);
 tile=func_02045768(*(void* *)&((struct Obj06724 *)p)->f20)|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 func_02041090(2,(u32)tiles,0,24,32,24);
 func_020409B4(2);
 func_020307B0(tiles);
}

void func_021B9C4C(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f4C=func_0204AC18((void *)((unsigned)h),0,0,0,0,2,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f48=func_0204A6C8((void *)((unsigned)h),3,0,0,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f50=func_0204AF28((void *)((unsigned)h),8,9,((struct Obj01592 *)p)->f0);
    func_02049238(h);
    *(struct Obj * *)&((struct Obj01592 *)p)->f54=func_0204B294((void *)func_021B9F90(((struct Obj01592 *)p)->f8),((struct Obj01592 *)p)->f48,((struct Obj01592 *)p)->f4C,((struct Obj01592 *)p)->f50,&d_021BA140,0,((struct Obj01592 *)p)->f0);
    func_0204B3DC(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
    func_0204B92C(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
}


void func_021B9CCC(char *p)
{
    func_0204B3B4(((struct Obj02557 *)p)->f54);
    func_0204AFD8((u32)(((struct Obj02557 *)p)->f50));
    func_0204A8D4((u32)(((struct Obj02557 *)p)->f48));
    func_0204ADA4((u32)(((struct Obj02557 *)p)->f4C));
}
