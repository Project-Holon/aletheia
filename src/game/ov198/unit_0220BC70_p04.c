/*
 * file:     unit_0220BC70_p04.c
 * unit:     yes
 * function: func_0220C2F8, func_0220C398, func_0220C42C, func_0220C4DC, func_0220C5AC, func_0220C60C, func_0220C67C, func_0220C688, func_0220C694, func_0220C714, func_0220C8F0, func_0220C9F0, func_0220CAF0, func_0220CBF0, func_0220CCF0, func_0220CDF0, func_0220CFC4, func_0220D034, func_0220D090, func_0220D1BC, func_0220D218, func_0220D348, func_0220D3B4, func_0220D418, func_0220D494, func_0220D628, func_0220D6AC, func_0220D6DC, func_0220D884, func_0220D920, func_0220D988
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
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0220E13C 0x0220E13C thumb ov198
 *   func_0220BEB8  0x0220BEB8  thumb  ov198
 *   func_020276C4  0x020276C4  thumb
 *   d_02211AFF  0x02211AFF  data  a1
 *   func_0220C16C 0x0220C16C thumb ov198
 *   func_0220C0D0 0x0220C0D0 thumb ov198
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
#include "../../matched/include/Obj01579.h"
#include "../../matched/include/Obj25152.h"
#include "../../matched/include/Obj01580.h"
#include "../../matched/include/Obj25153.h"
#include "../../matched/include/Obj01581.h"
#include "../../matched/include/Obj25154.h"
#include "../../matched/include/Obj01582.h"
#include "../../matched/include/Obj25155.h"
#include "../../matched/include/Obj00509.h"
#include "../../matched/include/Obj14557.h"
#include "../../matched/include/Obj25156.h"
#include "../../matched/include/Obj25157.h"
#include "../../matched/include/Obj25158.h"
#include "../../matched/include/Obj25159.h"
#include "../../matched/include/Obj25160.h"
#include "../../matched/include/Obj25161.h"
#include "../../matched/include/Obj25162.h"
#include "../../matched/include/Obj25163.h"
#include "../../matched/include/Obj06650.h"
#include "../../matched/include/Obj25164.h"
#include "../../matched/include/Obj25165.h"
#include "../../matched/include/Obj25166.h"
#include "../../matched/include/Obj10842.h"
#include "../../matched/include/Obj25167.h"
#include "../../matched/include/Obj02533.h"
#include "../../matched/include/Obj10843.h"
#include "../../matched/include/Obj25168.h"
#include "../../matched/include/Obj02534.h"
#include "../../matched/include/Obj10844.h"
#include "../../matched/include/Obj25169.h"
#include "../../matched/include/Obj25170.h"
#include "../../matched/include/Obj08359.h"
#include "../../matched/include/Obj25171.h"
#include "../../matched/include/Obj25172.h"
#include "../../matched/include/Obj05524.h"
#include "../../matched/include/Obj25173.h"
#include "../../matched/include/Obj25174.h"
#include "../../matched/include/Obj25175.h"
#include "../../matched/include/Obj02247.h"
#include "../../matched/include/Obj01077.h"
#include "../../matched/include/Obj25176.h"
#include "../../matched/include/Obj25177.h"
#include "../../matched/include/Obj25178.h"
#include "../../matched/include/Obj25179.h"
#include "../../matched/include/Obj25180.h"
#include "../../matched/include/Obj25181.h"
#include "../../matched/include/Obj25182.h"

#define P ((struct Ov198P *)p)
struct Descriptor;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct StrObj;
struct CharBuf;
struct Rec;
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

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    unsigned short f10;
} Sub;

typedef struct {
    Sub *f0;
    char pad04[0x1ea0 - 4];
    int f1ea0;
    int f1ea4;
    int f1ea8;
    int f1eac;
    char pad1eb0[0x1f98 - 0x1eb0];
    int f1f98;
    unsigned char f1f9c;
    char pad1f9d[0x1fe0 - 0x1f9d];
    int f1fe0;
    unsigned char f1fe4;
} Big;

typedef short s16_0220CDF0;

typedef short s16_0220CFC4;

typedef signed short   s16_0220D090;

typedef signed int     s32;

typedef signed short   s16_0220D218;

typedef short s16_0220D348;

typedef short s16_0220D3B4;

typedef signed short s16_0220D494;

struct Ov198Hdr { char pad[0xC]; u32 font; u16 f10; };

struct Ov198P { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };

typedef short s16_0220D628;

typedef short s16_0220D6DC;

typedef signed short s16_0220D884;

typedef struct {u8 lo:7,hi:1;} Bits;

typedef struct { u8 pad0[4]; void *obj; u16 cnt; u8 pad1[0x1B-0xA]; Bits fl; u8 pad2[0x4C-0x1C]; } Rec;

typedef signed short s16_0220D920;

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
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0220E13C(u8 *);
extern void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern int func_020276C4(int a0);
extern void func_0220C16C(u8 *,int,int,u8,u8);
extern void func_0220C0D0(u8 *,int,int,u16,u8);
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
void func_0220C8F0(Big *a0, int i);
void func_0220C9F0(char *p, int i);
void func_0220CAF0(char *p, int i);
void func_0220CBF0(char *p, int i);
void func_0220CCF0(char *p, int i);
void func_0220CDF0(u8 *p,int index);
void func_0220CFC4(char *p, int index);
void func_0220D034(char *p, int i);
void func_0220D090(char *p, int a1, int a2);
void func_0220D1BC(char *p, int i);
void func_0220D218(char *p, int a1, u32 a2);
void func_0220D348(char *p, int i, int id);
void func_0220D3B4(char *p, int i);
void func_0220D418(char *p, int i, int selector);
void func_0220D494(u8 *p, int slot, int a2, int a3);
void func_0220D628(char *p, int i);
void func_0220D6AC(u8 *p);
void func_0220D6DC(char *p,u8 *record,int slot);
void func_0220D884(u8 *p);
void func_0220D920(u8 *p, int i);
void func_0220D988(u8 *p,int a);
extern u8 d_02211AFF[];


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



static inline void put(Big *a0, int win, int sel, int x, int h, int color)
{
    func_0201C724((void *)win, (int)func_02045770((struct Descriptor *)sel), x, 0, h, a0->f0->fc, color);
}



/*
 * lever: both 0201C724 calls are one static inline helper; the centred x is a u8 local declared after v
 */
void func_0220C8F0(Big *a0, int i)
{
    char *entry = (char *)a0 + 4 + func_022110D4((u8 *)a0, i) * 0x4c;
    int h1;
    int h2;
    int p;
    int v;
    unsigned char x;

    h1 = (int)func_02045EC0((struct MsgBank *)a0->f1ea0, 0x2a);
    put(a0, a0->f1eac, a0->f1fe0, 0, h1, 0x3dc0);
    a0->f1fe4 = 1;
    func_02045808((struct U16Vec *)h1);

    h2 = (int)func_02045EC0((struct MsgBank *)a0->f1ea0, 0x2b);
    p = (int)func_020457B0(8, a0->f0->f10);
    func_0201EFA4((struct WordSet *)a0->f1ea4, 0, *(unsigned short *)(entry + 6), 3, 0, 1);
    func_0201F250((struct WordSet *)a0->f1ea4, (void *)p, (void *)h2);

    v = (unsigned char)func_0201D304((struct StrObj *)p, a0->f0->fc, 0);
    x = (func_02045738((struct Descriptor *)a0->f1f98) << 3) - v;
    put(a0, a0->f1eac, a0->f1f98, x, p, 0x2120);
    a0->f1f9c = 1;
    func_02045808((struct U16Vec *)h2);
    func_02045808((struct U16Vec *)p);
}



void func_0220C9F0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01579 *)p)->f1EA0, 0x2c);
    x = ((struct Obj01579 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01579 *)p)->f1FE8);
    func_0201C724((void *)x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01579 *)p)->f1FEC = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01579 *)p)->f1EA0, 0x2d);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01579 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01579 *)p)->f1EA4, 0, ((struct Obj25152 *)elem)->f8, 3, 0, 1);
    func_0201F250(((struct Obj01579 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01579 *)p)->f1FA0) << 3) - b;
    d = ((struct Obj01579 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01579 *)p)->f1FA0);
    func_0201C724((void *)d, e, c, 0, h, *(u32 *)(((struct Obj01579 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01579 *)p)->f1FA4 = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}



void func_0220CAF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01580 *)p)->f1EA0, 0x32);
    x = ((struct Obj01580 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01580 *)p)->f1FF0);
    func_0201C724((void *)x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01580 *)p)->f1FF4 = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01580 *)p)->f1EA0, 0x33);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01580 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01580 *)p)->f1EA4, 0, ((struct Obj25153 *)elem)->fA, 3, 0, 1);
    func_0201F250(((struct Obj01580 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01580 *)p)->f1FA8) << 3) - b;
    d = ((struct Obj01580 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01580 *)p)->f1FA8);
    func_0201C724((void *)d, e, c, 0, h, *(u32 *)(((struct Obj01580 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01580 *)p)->f1FAC = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}



void func_0220CBF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2e);
    x = ((struct Obj01581 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01581 *)p)->f1FF8);
    func_0201C724((void *)x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01581 *)p)->f1FFC = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01581 *)p)->f1EA0, 0x2f);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01581 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01581 *)p)->f1EA4, 0, ((struct Obj25154 *)elem)->fC, 3, 0, 1);
    func_0201F250(((struct Obj01581 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01581 *)p)->f1FB0) << 3) - b;
    d = ((struct Obj01581 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01581 *)p)->f1FB0);
    func_0201C724((void *)d, e, c, 0, h, *(u32 *)(((struct Obj01581 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01581 *)p)->f1FB4 = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}



void func_0220CCF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x30);
    x = ((struct Obj01582 *)p)->f1EAC;
    y = (u32)func_02045770(((struct Obj01582 *)p)->f2000);
    func_0201C724((void *)x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01582 *)p)->f2004 = 1;
    func_02045808(t);
    t2 = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x31);
    h = (u32)func_020457B0(8, *(u16 *)(((struct Obj01582 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01582 *)p)->f1EA4, 0, ((struct Obj25155 *)elem)->fE, 3, 0, 1);
    func_0201F250(((struct Obj01582 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0);
    c = (func_02045738(((struct Obj01582 *)p)->f1FB8) << 3) - b;
    d = ((struct Obj01582 *)p)->f1EAC;
    e = (u32)func_02045770(((struct Obj01582 *)p)->f1FB8);
    func_0201C724((void *)d, e, c, 0, h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01582 *)p)->f1FBC = 1;
    func_02045808(t2);
    func_02045808((void *)h);
}


void func_0220CDF0(u8 *p,int index)
{
    u8 *elem;
    void *text;
    void *buf;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    u16 x;
    elem=p+4+func_022110D4(p,index)*0x4C;
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x26);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1FD8),0,0,(u32)text,((struct Obj25156 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x3DC0);
    ((struct Obj00509 *)p)->f1FDC=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x29);
    width=func_0201D304(text,((struct Obj25157 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    x=((func_02045738(((struct Obj00509 *)p)->f1F90)<<3)-width)>>1;
    secondContext=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),(s16_0220CDF0)x,0,(u32)text,((struct Obj25158 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x27);
    buf=func_020457B0(8,((struct Obj25159 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f10,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25160 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),(s16_0220CDF0)(x-otherWidth),0,(u32)buf,((struct Obj25161 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    func_02045808(buf);
    text=func_02045EC0(((struct Obj00509 *)p)->f1EA0,0x28);
    buf=func_020457B0(8,((struct Obj25162 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->f10);
    func_0201EFA4(((struct Obj00509 *)p)->f1EA4,0,((struct Obj14557 *)elem)->f12,3,0,1);
    func_0201F250(((struct Obj00509 *)p)->f1EA4,buf,text);
    context=((struct Obj00509 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(((struct Obj00509 *)p)->f1F90),(s16_0220CDF0)(x+width),0,(u32)buf,((struct Obj25163 *)(*(u8 * *)&((struct Obj00509 *)p)->f0))->fC,0x2120);
    ((struct Obj00509 *)p)->f1F94=1;
    func_02045808(text);
    func_02045808(buf);
}


void func_0220CFC4(char *p, int index)
{
    char *elem;
    void *bank;
    void *t;
    void *f;
    elem = p + 4 + func_022110D4((u8 *)p, index) * 0x4C;
    bank = func_02045B38(0, 2, 0xB7, ((struct Obj25164 *)(*(char * *)&((struct Obj06650 *)p)->f0))->f10);
    t = func_02045EC0(bank, ((struct Obj25165 *)elem)->f18);
    f = ((struct Obj06650 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(((struct Obj06650 *)p)->f1F80), 0, 0, (u32)t, ((struct Obj25166 *)(*(char * *)&((struct Obj06650 *)p)->f0))->fC, 0x2120);
    ((struct Obj06650 *)p)->f1F84 = 1;
    func_02045808(t);
    func_02045C04(bank);
}


void func_0220D034(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10842 *)p)->f1EA0, 0x3D);
    f = ((struct Obj10842 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25167 *)(*(char * *)&((struct Obj10842 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}



void func_0220D090(char *p, int a1, int a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 == 0) {
        u32 f;

        t = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w = (func_02045738((void *)handle) << 3) - w;
        f = ((struct Obj02533 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16_0220D090)w, 0,
                      (u32)t, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3e);
        h = (u32)func_020457B0(8, *(u16 *)(((struct Obj02533 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02533 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02533 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w2 = (func_02045738((void *)handle) << 3) - w0;
        f = ((struct Obj02533 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16_0220D090)w2, 0,
                      h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t2);
        func_02045808((void *)h);
    }
}


void func_0220D1BC(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj10843 *)p)->f1EA0, 0x3A);
    f = ((struct Obj10843 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25168 *)(*(char * *)&((struct Obj10843 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}



void func_0220D218(char *p, int a1, u32 a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 <= 1) {
        u32 f;

        t = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w = (func_02045738((void *)handle) << 3) - w;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16_0220D218)w, 0,
                      (u32)t, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02534 *)p)->f1EA0, 0x3b);
        h = (u32)func_020457B0(8, *(u16 *)(((struct Obj02534 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02534 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02534 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0);
        w2 = (func_02045738((void *)handle) << 3) - w0;
        f = ((struct Obj02534 *)p)->f1EAC;
        func_0201C724((void *)f,
                      (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16_0220D218)w2, 0,
                      h, *(u32 *)(((struct Obj02534 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        func_02045808(t2);
        func_02045808((void *)h);
    }
}


void func_0220D348(char *p, int i, int id)
{
    void *bank;
    void *t;
    void *f;
    bank = func_02045B38(0, 2, 0xCA, ((struct Obj25169 *)(*(char * *)&((struct Obj10844 *)p)->f0))->f10);
    t = func_02045EC0(bank, id);
    f = ((struct Obj10844 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25170 *)(*(char * *)&((struct Obj10844 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
    func_02045C04(bank);
}


void func_0220D3B4(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(((struct Obj08359 *)p)->f1EA0, 0x3F);
    func_0201D304(t, ((struct Obj25171 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0);
    f = ((struct Obj08359 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, ((struct Obj25172 *)(*(char * *)&((struct Obj08359 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}


/*
 * note: the switch has no default; a selector outside 0..2 branches from
 *   0220D42C straight to the print tail with r7 (t) never assigned, as the
 *   image does. The earlier `default: return;` spelling was a guard the
 *   original lacks.
 */
void func_0220D418(char *p, int i, int selector)
{
    struct U16Vec *t;
    void *f;
    switch (selector) {
    case 0: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x41); break;
    case 1: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x40); break;
    case 2: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x42); break;
    }
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, (u32)func_02045770(*(struct Descriptor **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}



/*
 * Near miss: the body is byte-for-byte right in shape; the residue is pure
 * register allocation / frame packing. The original keeps `handle` in r7
 * (used only for the 45738 call, then r7 is recycled by the shifted coordinate)
 * with `base` in [sp+0x1c] and `off` in r6, and packs the frame as
 * push {r3,r4,r5,r6,r7,lr} / sub sp,#0x40.  Naming base/off or inlining the
 * array, splitting f/y per block, and hoisting handle all leave the allocator
 * choosing a different split (5-reg push + #0x44) and one extra instruction.
 * Needs a different spelling of the three draw blocks; not an evidence problem.
 *
 * Re-verified (DIFF fixer): still 391 concrete bytes; all 15 relocations
 * resolve, so it is a frame-packing/allocation residue, not evidence.
 */
void func_0220D494(u8 *p, int slot, int a2, int a3)
{
    u8 *tab;
    void *handle;
    void *text;
    u32 w1;
    u32 x;
    u32 ctx1;
    u8 *fl;
    void *text2;
    void *h2;
    u32 w2;
    u32 ctx2;
    void *text3;
    void *h3;
    u32 ctx3;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    text = func_02045EC0(P->f1EA0, 0x38);
    w1 = func_0201D304(text, P->hdr->font, 0);
    x = ((func_02045738(handle) << 3) - w1) >> 1;
    ctx1 = P->f1EAC;
    func_0201C724((void *)ctx1, (u32)func_02045770(*(void **)(tab + slot)), (s16_0220D494)x, (s16_0220D494)0, (u32)text, P->hdr->font, (u32)0x3DC0);
    fl = p + 0x1F74;
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 0x36);
    h2 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a2, 3, 0, 1);
    func_0201F250(P->f1EA4, h2, text2);
    w2 = func_0201D304(h2, P->hdr->font, 0);
    ctx2 = P->f1EAC;
    func_0201C724((void *)ctx2, (u32)func_02045770(*(void **)(tab + slot)), (s16_0220D494)(x - w2), (s16_0220D494)0, (u32)h2, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    func_02045808(h2);
    text3 = func_02045EC0(P->f1EA0, 0x37);
    h3 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a3, 3, 0, 1);
    func_0201F250(P->f1EA4, h3, text3);
    ctx3 = P->f1EAC;
    func_0201C724((void *)ctx3, (u32)func_02045770(*(void **)(tab + slot)), (s16_0220D494)(x + w1), (s16_0220D494)0, (u32)h3, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
    func_02045808(h3);
}


void func_0220D628(char *p, int i)
{
    void *t;
    void *f;
    u32 width;
    if (((struct Obj25173 *)(*(char * *)&((struct Obj05524 *)p)->f0))->f4B == 4)
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x45);
    else
        t = func_02045EC0(((struct Obj05524 *)p)->f1EA0, 0x44);
    width = func_0201D304(t, ((struct Obj25174 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0);
    f = ((struct Obj05524 *)p)->f1EAC;
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), (s16_0220D628)((96 - width) >> 1), 5, (u32)t, ((struct Obj25175 *)(*(char * *)&((struct Obj05524 *)p)->f0))->fC, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}


void func_0220D6AC(u8 *p){void *s=func_02045EC0(*(struct MsgBank * *)&((struct Obj02247 *)p)->f1EA0,70);func_0201F250(*(struct WordSet * *)&((struct Obj02247 *)p)->f1EA4,((struct Obj02247 *)p)->f1EA8,s);func_02045808(s);func_0220E13C(p);}


void func_0220D6DC(char *p,u8 *record,int slot)
{
    void *buf;
    void *text;
    void *context;
    void *secondContext;
    u32 width;
    u32 otherWidth;
    buf=func_020457B0(6,((struct Obj25176 *)(*(char * *)&((struct Obj01077 *)p)->f0))->f10);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x35);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),40,24,(u32)text,((struct Obj25177 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x38);
    width=func_0201D304(text,((struct Obj25178 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    secondContext=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(secondContext,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),80,24,(u32)text,((struct Obj25179 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x37);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[3],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    context=((struct Obj01077 *)p)->f1EAC;
    width+=80;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16_0220D6DC)width,24,(u32)buf,((struct Obj25180 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    text=func_02045EC0(((struct Obj01077 *)p)->f1EA0,0x36);
    func_0201EFA4(((struct Obj01077 *)p)->f1EA4,0,record[2],2,0,1);
    func_0201F250(((struct Obj01077 *)p)->f1EA4,buf,text);
    otherWidth=func_0201D304(buf,((struct Obj25181 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0);
    context=((struct Obj01077 *)p)->f1EAC;
    func_0201C724(context,(u32)func_02045770(*(void **)(p+0x1F70+slot*8)),(s16_0220D6DC)(80-otherWidth),24,(u32)buf,((struct Obj25182 *)(*(char * *)&((struct Obj01077 *)p)->f0))->fC,0x3DC0);
    *(u8 *)(p+0x1F74+slot*8)=1;
    func_02045808(text);
    func_02045808(buf);
}


void func_0220D884(u8 *p)
{
    s16_0220D884 i;
    int idx;

    *(void **)(p + 0x253C) = d_02211AFF;
    for (i = 0; i < 6; i++) {
        func_02043B5C((struct CharBuf *)func_02045770(*(struct Descriptor **)(p + i * 8 + 0x1F70)), 0);
        idx = func_022110D4(p, i);
        if (((Rec *)p)[idx].cnt == 0) {
            *(u8 *)(p + i * 8 + 0x1F74) = 1;
        } else {
            func_0220BEB8(p, i, (u16)i, 0x20, 7);
            if (!((Rec *)p)[idx].fl.hi) {
                func_0220D920(p, (u8)i);
            }
            if (func_020276C4((int)(((Rec *)p)[idx].obj)) == 8) {
                func_0220D988(p, (u8)i);
            }
        }
    }
}


void func_0220D920(u8 *p, int i)
{
    char *base;
    base = (char *)p + 0x1f70;
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 92, 32, 24, 8, 0);
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 64, 24, 64, 8, 0);
    func_0220C16C(p, i, i, 92, 32);
    func_0220C2F8(p, i, i, 64, 24);
}


void func_0220D988(u8 *p,int a){if(((Bits *)(p+(u32)func_022110D4(p,a)*76+0x1b))->hi==0)func_0220C0D0(p,a,a,8,32);}
