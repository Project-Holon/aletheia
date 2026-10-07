/*
 * file:     unit_0220BC70_p03.c
 * unit:     yes
 * function: func_0220C2F8, func_0220C398, func_0220C42C, func_0220C4DC, func_0220C5AC, func_0220C60C, func_0220C67C, func_0220C688, func_0220C694, func_0220C714
 * address:  0x0220C2F8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0202D01C 0x0202D01C thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02043B5C 0x02043B5C arm
 */
#include "../../matched/include/Obj08357.h"
#include "../../matched/include/Obj05523.h"
#include "../../matched/include/Obj25133.h"
#include "../../matched/include/Obj25134.h"
#include "../../matched/include/Obj25135.h"
#include "../../matched/include/Obj04599.h"
#include "../../matched/include/Obj14555.h"
#include "../../matched/include/Obj25136.h"
#include "../../matched/include/Obj25137.h"
#include "../../matched/include/Obj04600.h"
#include "../../matched/include/Obj25138.h"
#include "../../matched/include/Obj25139.h"
#include "../../matched/include/Obj25140.h"
#include "../../matched/include/Obj10841.h"
#include "../../matched/include/Obj25141.h"
#include "../../matched/include/Obj00507.h"
#include "../../matched/include/Obj25142.h"
#include "../../matched/include/Obj08358.h"
#include "../../matched/include/Obj25143.h"
#include "../../matched/include/Obj25144.h"
#include "../../matched/include/Obj00508.h"
#include "../../matched/include/Obj14556.h"
#include "../../matched/include/Obj25145.h"
#include "../../matched/include/Obj25146.h"
#include "../../matched/include/Obj25147.h"
#include "../../matched/include/Obj25148.h"
#include "../../matched/include/Obj25149.h"
#include "../../matched/include/Obj25150.h"
#include "../../matched/include/Obj25151.h"

struct Descriptor;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct StrObj;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_0220C2F8;

typedef unsigned int u32;

typedef short s16_0220C42C;

typedef short s16_0220C4DC;

typedef short s16_0220C60C;

struct Flags { u8 pad[0x2177]; u8 low:4; u8 high:4; };

typedef short s16_0220C694;

typedef short s16_0220C714;

struct Bits7 { unsigned char value:7; unsigned char flag:1; };

extern int func_022110D4(u8 *,int);
extern u8 func_0202D01C(u32,u32,u32);
extern int func_0202D034(u32,u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
void func_0220C2F8(u8 *p,int slot,int index,u16 value,u8 extra);
void func_0220C398(u8 *p,int slot,int index);
void func_0220C42C(char *p, int i, int index);
void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16_0220C4DC y,u32 color);
void func_0220C5AC(char *p, int i, u16 x, u16 y);
void func_0220C60C(char *p, int id);
void func_0220C67C(char *p);
void func_0220C688(char *p);
void func_0220C694(char *p, int i, int id);
void func_0220C714(u8 *p,int index);

/*
 * lever: u16 value and u8 width/return preserve stack-store scheduling.
 */
void func_0220C2F8(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    u8 color=1;
    u8 width=func_0202D01C(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12,48);
    switch(func_0202D034(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12)) {
    case 3: return;
    case 0: color=1; break;
    case 1: color=3; break;
    case 2: color=5; break;
    }
    func_02043AF4((struct Bmp *)((u32)func_02045770(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16_0220C2F8)(extra+3),width,(u8)1,(u8)color);
    color++;
    func_02043AF4((struct Bmp *)((u32)func_02045770(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16_0220C2F8)(extra+4),width,(u8)1,(u8)color);
}

void func_0220C398(u8 *p,int slot,int index)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    u32 buf=(u32)func_020457B0(16,((struct Obj25133 *)(*(char * *)&((struct Obj05523 *)p)->f0))->f10);
    void *text=func_02045EC0(((struct Obj05523 *)p)->f1EA0,14);
    u32 context;
    u32 surface;
    func_0201EF8C(((struct Obj05523 *)p)->f1EA4,0,((struct Obj25134 *)elem)->f18);
    func_0201F250(((struct Obj05523 *)p)->f1EA4,(void *)buf,text);
    context=((struct Obj05523 *)p)->f1EAC;
    surface=(u32)func_02045770(*(void **)(p+slot*8+0x1F70));
    func_0201C724((void *)context,surface,0,0,buf,((struct Obj25135 *)(*(char * *)&((struct Obj05523 *)p)->f0))->fC,0x3DC0);
    (p+slot*8)[0x1F74]=1;
    func_02045808(text);
    func_02045808((void *)buf);
}

void func_0220C42C(char *p, int i, int index)
{
    char *elem;
    void *t;
    void *format;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    if (((struct Obj14555 *)elem)->f1A == 0)
        t = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 0x1E);
    else {
        t = (void *)func_020457B0(0x12, ((struct Obj25136 *)(*(char * *)&((struct Obj04599 *)p)->f0))->f10);
        format = func_02045EC0(((struct Obj04599 *)p)->f1EA0, 15);
        func_0201EF40(((struct Obj04599 *)p)->f1EA4, 0, ((struct Obj14555 *)elem)->f1A);
        func_0201F250(((struct Obj04599 *)p)->f1EA4, (void *)((u32)t), format);
        func_02045808(format);
    }
    f = ((struct Obj04599 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25137 *)(*(char * *)&((struct Obj04599 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}

void func_0220C4DC(char *p,int value,int slot,int id,u16 x,s16_0220C4DC y,u32 color)
{
    void *handle;
    void *buf;
    void *text;
    void *context;
    u32 width;
    handle=*(void **)(p+0x1F70+slot*8);
    buf=func_020457B0(16,((struct Obj25138 *)(*(char * *)&((struct Obj04600 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj04600 *)p)->f1EA0,id);
    func_0201EF34(((struct Obj04600 *)p)->f1EA4,0,value);
    func_0201F250(((struct Obj04600 *)p)->f1EA4,buf,text);
    if (x==0xFFFF) {
        width=func_02045738(handle);
        x=((width<<3)-func_0201D304(buf,((struct Obj25139 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,0))>>1;
    }
    context=((struct Obj04600 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16_0220C4DC)x,y,(u32)buf,((struct Obj25140 *)(*(char * *)&((struct Obj04600 *)p)->f0))->fC,(u16)color);
    *(u8 *)(p+slot*8+0x1F74)=1;
    func_02045808(text);
    func_02045808(buf);
}

void func_0220C5AC(char *p, int i, u16 x, u16 y)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10841 *)p)->f1EA0, 0x14);
    f = ((struct Obj10841 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, y, (u32)t, ((struct Obj25141 *)(*(char * *)&((struct Obj10841 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}

void func_0220C60C(char *p, int id)
{
    void *t;
    void *f;
    func_02043B5C((void *)func_02045770(((struct Obj00507 *)p)->f1F60), 15);
    t = func_02045EC0(((struct Obj00507 *)p)->f1EA0, id);
    f = ((struct Obj00507 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(((struct Obj00507 *)p)->f1F60), 0, 0, (u32)t, ((struct Obj25142 *)(*(char * *)&((struct Obj00507 *)p)->f0))->fC, 0x440);
    ((struct Obj00507 *)p)->f1F64 = 1;
    func_02045808(t);
    ((struct Flags *)p)->high = 1;
}

void func_0220C67C(char *p){func_0220C60C(p,9);}

void func_0220C688(char *p){func_0220C60C(p,10);}

void func_0220C694(char *p, int i, int id)
{
    void *t;
    void *handle;
    void *f;
    u32 width;
    u32 font;
    s16_0220C694 x;
    handle = *(void **)(p + 0x1F70 + i * 8);
    t = func_02045EC0(((struct Obj08358 *)p)->f1EA0, id);
    width = func_0201D304(t, ((struct Obj25143 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC, 0);
    font = ((struct Obj25144 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC;
    x = (s16_0220C694)(((func_02045738(handle) << 3) - width) >> 1);
    f = ((struct Obj08358 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), x, 5, (u32)t, font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}

void func_0220C714(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    void *thirdContext;
    u32 width;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x21);
    context=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00508 *)p)->f2008),0,0,(u32)text,((struct Obj25145 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f200C=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x22);
    buf=func_020457B0(8,((struct Obj25146 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Bits7 *)(elem+0x16))->value,3,0,1);
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    secondContext=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(((struct Obj00508 *)p)->f1FC8),0,0,(u32)buf,((struct Obj25147 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f1FCC=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x23);
    thirdContext=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(thirdContext,(u32)func_02045770(((struct Obj00508 *)p)->f2010),0,0,(u32)text,((struct Obj25148 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00508 *)p)->f2014=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00508 *)p)->f1EA0,0x24);
    buf=func_020457B0(14,((struct Obj25149 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->f10);
    if (((struct Bits7 *)(elem+0x16))->value<100) {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,((struct Obj14556 *)elem)->f24-((struct Obj14556 *)elem)->f1C,6,1,1);
    } else {
        func_0201EFA4(((struct Obj00508 *)p)->f1EA4,0,0,6,1,1);
    }
    func_0201F250(((struct Obj00508 *)p)->f1EA4,buf,text);
    width=func_02045738(((struct Obj00508 *)p)->f1FD0);
    x=(width<<3)-func_0201D304(buf,((struct Obj25150 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0);
    context=((struct Obj00508 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00508 *)p)->f1FD0),(s16_0220C714)x,0,(u32)buf,((struct Obj25151 *)(*(u8 * *)&((struct Obj00508 *)p)->f0))->fC,0x2120);
    ((struct Obj00508 *)p)->f1FD4=1;
    func_02045808(text);
    func_02045808(buf);
}
