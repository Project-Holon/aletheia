/*
 * file:     br_util_p01.c
 * unit:     yes
 * function: func_021FC6A4, func_021FC734, func_021FC754, func_021FC7C4, func_021FC830
 * address:  0x021FC6A4
 * region:   ov186
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
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D5C 0x02200D5C data a1
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021FC870 0x021FC870 thumb ov186
 *   func_0201C724 0x0201C724 thumb
 *   func_02045838 0x02045838 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 */
#include "../../matched/include/Obj02901.h"
#include "../../matched/include/Obj10791.h"
#include "../../matched/include/Obj02902.h"
#include "../../matched/include/Obj02903.h"
#include "../../matched/include/Obj05502.h"

struct CharBuf;
struct Descriptor;
struct Cfg;
struct U16Vec;
struct MsgBank;
struct PrintSys;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Pair {int x,y;} Pair;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_020457B0(unsigned,unsigned short);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021FC870(int,Pair *,const void *,void *,void *,Pair *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap);
void func_021FC734(u8*p);
void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value);
void func_021FC7C4(char *p,void *text,void *font,unsigned short value);
int func_021FC830(u8*p);
extern const char d_02200D5C[];

void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap)
{
    char *p;
    void *bmp;
    p=func_02030734(heap,0x24,0,d_02200D5C,0x5f);
    func_02082BCC(p,0,0x24);
    ((struct Obj02901 *)p)->f14=0;
    ((struct Obj02901 *)p)->f8=owner;
    ((struct Obj02901 *)p)->f16=plane;
    ((struct Obj02901 *)p)->f10=func_020457B0(0xff,heap);
    bmp=(void *)func_020450F0((unsigned char)plane,a,b,c,d,e,1);
    ((struct Obj02901 *)p)->fC=bmp;
    ((struct Obj02901 *)p)->f0=bmp;
    p[4]=0;
    func_02043B5C(func_02045770(bmp),((struct Obj02901 *)p)->f14);
    bmp=((struct Obj02901 *)p)->fC;
    func_02045334(bmp);
    func_02045374(bmp);
    func_020409B4(func_02045730(bmp));
    return p;
}

void func_021FC734(u8*p){func_020456F8(*(void* *)&((struct Obj10791 *)p)->fC);func_020452E8(*(void* *)&((struct Obj10791 *)p)->fC);func_02045808(*(void* *)&((struct Obj10791 *)p)->f10);func_020307B0(p);}

void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    func_02043B5C(func_02045770(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f14);
    func_02045CAC(a,(u32)b,((struct Obj02902 *)p)->f10);
    func_021FC870(((struct Obj02902 *)p)->f18,(Pair *)(p+28),func_02045770(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f10,font,&xy);
    owner=((struct Obj02902 *)p)->f8;
    func_0201C724(owner,(u32)func_02045770(((struct Obj02902 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02902 *)p)->f10),(u32)font,value);
    p[4]=1;
}

void func_021FC7C4(char *p,void *text,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    func_02043B5C(func_02045770(((struct Obj02903 *)p)->fC),((struct Obj02903 *)p)->f14);
    func_02045838(((struct Obj02903 *)p)->f10,text);
    func_021FC870(((struct Obj02903 *)p)->f18,(Pair *)(p+28),func_02045770(((struct Obj02903 *)p)->fC),((struct Obj02903 *)p)->f10,font,&xy);
    owner=((struct Obj02903 *)p)->f8;
    func_0201C724(owner,(u32)func_02045770(((struct Obj02903 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02903 *)p)->f10),(u32)font,value);
    p[4]=1;
}

int func_021FC830(u8*p){void*owner=*(void* *)&((struct Obj05502 *)p)->f8;if(p[4]){if(!func_0201C6C4(owner,func_02045770(*(void* *)&((struct Obj05502 *)p)->f0))){func_02045334(*(void* *)&((struct Obj05502 *)p)->f0);p[4]=0;}}if(!p[4])return 1;return 0;}
