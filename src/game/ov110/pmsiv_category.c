/*
 * file:     pmsiv_category.c
 * unit:     yes
 * function: func_021BB280, func_021BB290, func_021BB2CC, func_021BB328, func_021BB3F4, func_021BB4F4, func_021BB5A0, func_021BB5E0, func_021BB61C, func_021BB658, func_021BB6A0, func_021BB76C, func_021BB784, func_021BB7A0, func_021BB7B8, func_021BB804, func_021BB814, func_021BB82C, func_021BB838, func_021BB854, func_021BB870, func_021BB8AC, func_021BB8B8, func_021BB8D8, func_021BB954, func_021BB958, func_021BB9C0, func_021BB9E8, func_021BBA10, func_021BBB0C, func_021BBB84, func_021BBC10, func_021BBC5C, func_021BBCF0, func_021BBD60
 * address:  0x021BB280
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C37B1 0x021C37B1 data a1
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   d_021C3C44 0x021C3C44 data a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040618 0x02040618 arm
 *   func_0207D658 0x0207D658 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021C38C4 0x021C38C4 data ov110 a1
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020457B0 0x020457B0 arm
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB1F8 0x021BB1F8 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   d_021C38D0 0x021C38D0 data ov110 a2
 *   func_021BAC3C 0x021BAC3C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BC8FC 0x021BC8FC thumb ov110
 *   func_021BC93C 0x021BC93C thumb ov110
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_021BC868 0x021BC868 thumb ov110
 *   func_021BC898 0x021BC898 thumb ov110
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020499D4 0x020499D4 arm
 *   func_02049238 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BF7D4 0x021BF7D4 thumb ov110
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_02040804 0x02040804 arm
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_021BF814 0x021BF814 thumb ov110
 *   func_0201C724 0x0201C724 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   d_021C3C58 0x021C3C58 data a1
 *   func_02020D18 0x02020D18 thumb
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02020D3C 0x02020D3C thumb
 *   func_021BC068 0x021BC068 thumb ov110
 *   func_021BC120 0x021BC120 thumb ov110
 *   func_021BC160 0x021BC160 thumb ov110
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BC1B8 0x021BC1B8 thumb ov110
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CB18 0x0202CB18 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CC58 0x0202CC58 thumb
 */
#include "../../matched/include/Obj03751.h"
#include "../../matched/include/Obj03752.h"
#include "../../matched/include/Obj03240.h"
#include "../../matched/include/Obj22359.h"
#include "../../matched/include/Obj22360.h"
#include "../../matched/include/Obj04444.h"
#include "../../matched/include/Obj04445.h"
#include "../../matched/include/Obj22365.h"
#include "../../matched/include/Obj22366.h"
#include "../../matched/include/Obj22367.h"
#include "../../matched/include/Obj13779.h"
#include "../../matched/include/Obj22368.h"
#include "../../matched/include/Obj10275.h"
#include "../../matched/include/Obj02460.h"
#include "../../matched/include/Obj05289.h"
#include "../../matched/include/Obj05290.h"
#include "../../matched/include/Obj04446.h"
#include "../../matched/include/Obj01392.h"
#include "../../matched/include/Obj01248.h"
#include "../../matched/include/Obj01922.h"

#define WININ (*(volatile u16 *)0x04000048)
#define WINOUT (*(volatile u16 *)0x0400004a)
struct Descriptor;
struct Obj;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
struct Vec2_021BB280;
struct PrintSys;
struct Actor;
struct WinMgr;
struct D;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16_021BB3F4;

typedef short s16_021BB4F4;

typedef short s16_021BB61C;

typedef struct { int a,b,c; } Triple;

typedef signed short s16_021BB6A0;

typedef struct { s16_021BB6A0 x, y; } Vec2_021BB280;

typedef short s16_021BB76C;

typedef short s16_021BB784;

typedef short s16_021BB7A0;

typedef short s16_021BB814;

typedef short s16_021BB838;

typedef unsigned int u32_021BB838;

typedef short s16_021BB854;

typedef unsigned int u32_021BB854;

typedef unsigned int   u32_021BB870;

typedef short s16_021BB8B8;

typedef unsigned int u32_021BB8B8;

typedef unsigned int   u32_021BB8D8;

typedef short s16_021BB954;

typedef signed char s8;

typedef unsigned int u32_021BB954;

typedef int s32;

typedef unsigned int u32_021BB958;

typedef signed short   s16_021BB958;

typedef short s16_021BB9C0;

typedef unsigned int u32_021BB9C0;

typedef short s16_021BB9E8;

typedef unsigned int u32_021BB9E8;

typedef short s16_021BBA10;

typedef unsigned u32_021BBA10;

typedef unsigned int   u32_021BBB0C;

typedef signed short s16_021BBB84;

typedef struct { s16_021BBB84 x, y; } Vec2_021BB82C;

typedef unsigned int   u32_021BBB84;

typedef unsigned int   u32_021BBC10;

typedef unsigned int u32_021BBC5C;

typedef unsigned int   u32_021BBCF0;

typedef unsigned u32_021BBD60;

typedef short s16_021BBD60;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040618(u32, u32, u32);
extern void func_0207D658(u32, int, int);
extern void func_020409B4(u32);
extern u32 func_021BAC44(u8 *);
extern u32 func_021B999C(u8 *, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *, s16_021BB3F4, s16_021BB3F4, void *, void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021BB1F4(void);
extern void func_021BB1F8(u32,void *);
extern void func_021BB224(u32,int *,int *);
extern void func_021BAC64(void *,Triple *,int,int);
extern struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_021BF6DC(u8 *);
extern unsigned func_021BAC3C(u8 *);
extern void func_021BCF7C(u8 *, int, int);
extern void func_0204B404(struct Obj *p, const struct Vec2_021BB280 *delta, u32 which);
extern void func_021BC8FC(u8 *,int,int,int,int);
extern int func_021BC93C(u8 *);
extern void func_021BC78C(u8 *,int,int,int,int);
extern int func_021BC7DC(u8 *p);
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
extern int func_021BC898(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02041EE4(u32_021BB8B8,u32_021BB8B8,u32_021BB8B8);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32_021BB8D8 func_020499D4(void *a0, u32_021BB8D8 a1, u32_021BB8D8 a2, u32_021BB8D8 a3, u32_021BB8D8 a4, u32_021BB8D8 a5, u32_021BB8D8 a6, u16 a7);
extern void func_02049238(void *);
extern void func_02041B6C(unsigned);
extern void func_021BF7D4(u8 *p, void *q);
extern u8 func_021BF7FC(u8 *p);
extern u32_021BB9E8 func_02040804(unsigned);
extern u32_021BBA10 func_021BAC4C(u8 *);
extern void func_021BF814(u8 *p, u32_021BBA10 a, int b);
extern void func_0201C724(void *,u32_021BBA10,u32_021BBA10,u32_021BBA10,u32_021BBA10,u32_021BBA10,u16);
extern u32_021BBB0C func_0201C6C4(struct PrintSys *p, void *v);
extern u32_021BBB84 func_0204B3F4(struct Obj *p);
extern u16 func_0204B898(struct Obj *p);
extern u32_021BBC10 func_0204B98C(struct Actor *a);
extern void *func_02020D18(unsigned);
extern struct WinMgr *func_0202C9B4(u32_021BBC5C a0, u32_021BBC5C a1, u32_021BBC5C heap);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_02030EAC(struct Node *n);
extern void func_02020D3C(struct D *p);
extern void func_021BC068(u8 *,void *);
extern void func_021BC120(u8 *);
extern void func_021BC160(void *);
extern void func_021BC23C(void *);
extern void func_021BC1B8(u8 *);
extern void func_0202CA3C(struct WinMgr *mgr, u32_021BBD60 idx, u32_021BBD60 bg, u32_021BBD60 w, u32_021BBD60 h);
extern void func_0202CB18(struct WinMgr *mgr, u32_021BBD60 idx, void *arc, u32_021BBD60 member, u32_021BBD60 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32_021BBD60 idx, s8 x, s8 y);
extern void func_0202CEBC(struct WinMgr *mgr, u32_021BBD60 idx, void *a);
extern void func_0202CC58(struct WinMgr *mgr, u32_021BBD60 idx);
u8 func_021BB280(u32 i);
u8 *func_021BB290(u32 a,u8 *b,u32 c);
void func_021BB2CC(u8 *p);
void func_021BB328(u8 *p, u32 data);
u8 *func_021BB3F4(u8 *p, u8 *q);
u8 *func_021BB4F4(u8 *p,u8 *q);
u8 *func_021BB5A0(u8 *p,u8 *q);
void func_021BB5E0(u8 *p);
void func_021BB61C(u8 *p);
void func_021BB658(u8 *p, int enable);
void func_021BB6A0(u8 *p, unsigned index);
void func_021BB76C(u8 *p);
int func_021BB784(u8 *p);
void func_021BB7A0(u8 *p);
int func_021BB7B8(u8 *p);
void func_021BB804(u8 *a0);
void func_021BB814(u8 *p);
int func_021BB82C(u8 *p);
void func_021BB838(u8 *p);
int func_021BB854(u8 *p);
void func_021BB870(u8 *p);
int func_021BB8AC(u8 *p);
void func_021BB8B8(u8 *p);
void func_021BB8D8(u8 *p);
int func_021BB954(u8 *a0);
void func_021BB958(char *p);
void func_021BB9C0(u8 *p,int flag);
void func_021BB9E8(u8 *p,u32_021BB9E8 unused);
void func_021BBA10(u8 *p,unsigned n);
int func_021BBB0C(u8 *p, int a);
void func_021BBB84(u8 *p, unsigned index);
int func_021BBC10(u8 *p);
u8 *func_021BBC5C(void *a, u8 *b, void *c);
void func_021BBCF0(u8 *p);
void func_021BBD60(u8 *p,u32_021BBD60 a);
extern const u8 d_021C37B1[];
extern const char d_021C3C44[];
extern const u8 d_021C38C4[];
extern const Vec2_021BB280 d_021C38D0;
extern const char d_021C3C58[];





u8 func_021BB280(u32 i) { return *(const u8 *)(d_021C37B1+i*10); }





u8 *func_021BB290(u32 a,u8 *b,u32 c) { u8 *p; p=func_02030734(42,164,0,d_021C3C44,220); ((struct Obj03751 *)p)->f0=a; *(u8 * *)&((struct Obj03751 *)p)->f4=b; ((struct Obj03751 *)p)->f8=c; ((struct Obj03751 *)p)->fC=0; ((struct Obj03751 *)p)->f14=0; ((struct Obj03751 *)p)->f54=0; ((struct Obj03751 *)p)->f58=0; *(u8 * *)&((struct Obj03751 *)p)->f5C=func_021BF6D4(b); return p; }





/*
 * extent: trailing two-byte zero padding
 */
void func_021BB2CC(u8 *p) {
    u8 i;
    if(((struct Obj03752 *)p)->f54) func_0204B3B4(((struct Obj03752 *)p)->f54);
    for(i=0;i<12;i++) if(*(void **)(p+0x60+i*4)) func_020452E8(*(void **)(p+0x60+i*4));
    if(((struct Obj03752 *)p)->f90) func_020452E8(((struct Obj03752 *)p)->f90);
    if(((struct Obj03752 *)p)->f94) func_020452E8(((struct Obj03752 *)p)->f94);
    if(((struct Obj03752 *)p)->f98) func_020452E8(((struct Obj03752 *)p)->f98);
    func_020307B0(p);
}





static inline void inside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}





static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}





void func_021BB328(u8 *p, u32 data)
{
    u32 bytes, q;
    func_020498F4((void *)data, 27, 1, 0, 0, 0, 42);
    bytes = func_02049658((void *)data, 15, 1, 0, 0, 0, 42);
    q = (u32)func_021BB3F4(p, (u8 *)(bytes / 32));
    q = (u32)func_021BB4F4(p, (u8 *)q);
    func_021BB5A0(p, (u8 *)q);
    func_021BB5E0(p);
    func_02040618(1, 0, -4);
    func_02040618(1, 3, 16);
    func_021BB61C(p);
    func_0207D658(0x04000050, 2, -10);
    inside(31, 1);
    outside(29, 1);
    *(volatile u16 *)0x04000040 = 255;
    *(volatile u16 *)0x04000044 = 168;
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000) | 0x2000;
    func_020409B4(1);
}





u8 *func_021BB3F4(u8 *p, u8 *q)
{
    int x, y;
    void *bank;
    u32 font;
    int i;
    void *str, *win;
    u32 width;
    font = func_021BAC44(*(u8 * *)&((struct Obj03240 *)p)->f0);
    bank = func_02045B38(0, 2, 145, 42);
    x = 1;
    y = 9;
    for (i = 0; i < 12; i++) {
        if (i != 0 && i % 3 == 0) { x = 1; y += 3; }
        if (func_021B999C(*(u8 * *)&((struct Obj03240 *)p)->f8, i)) {
            str = func_02045EC0(bank, d_021C38C4[i]);
            func_0201DD78(1, 2, 15);
        } else {
            str = func_02045EC0(bank, 13);
            func_0201DD78(3, 4, 15);
        }
        win = (void *)func_020450F0(1, (u8)x, (u8)y, 9, 2, 12, 1);
        func_02043B5C(func_02045770(win), 15);
        width = 72 - func_0201D304(str, font, 0);
        func_0201C7A4(func_02045770(win), width >> 1, 0, str, (void *)font);
        func_02045374(win);
        func_02045334(win);
        func_02045808(str);
        *(void **)(p + i * 4 + 0x60) = win;
        q += 18;
        x += 10;
    }
    func_02045C04(bank);
    return q;
}





/*
 * extent: trailing two-byte zero padding
 * lever: signed loop counter; string pointer declared before counter.
 */
u8 *func_021BB4F4(u8 *p,u8 *q) {
    u32 n,w,a;
    void *str;
    int i;
    int x,y;
    w=func_021BAC44(*(u8 * *)&((struct Obj03240 *)p)->f0);
    a=func_020450F0(1,1,8,30,14,12,1);
    str=func_020457B0(4,42);
    func_02043B5C(func_02045770((struct Descriptor *)a),15);
    n=func_021BB1F4();
    for(i=0;i<n;i++) {
        func_021BB1F8(i,str);
        func_021BB224(i,&x,&y);
        func_0201DD78(1,2,15);
        func_0201C7A4(func_02045770((struct Descriptor *)a),x+5,y,str,(void *)w);
    }
    func_02045334((struct Descriptor *)a);
    func_02045808(str);
    p+=0x90;
    *(u32 *)&((struct Obj03240 *)p)->f0=a;
    return q+0x1a4;
}




u8 *func_021BB5A0(u8 *p,u8 *q) {
    u32 a;
    a=func_020450F0(1,10,3,11,2,12,1);
    func_02043B5C(func_02045770((struct Descriptor *)a),1);
    func_02045334((struct Descriptor *)a);
    ((struct Obj22359 *)p)->f94=a;
    return q+0x16;
}




void func_021BB5E0(u8 *p) { u32 win; win=func_020450F0(6,1,1,30,22,0,1); func_02045374((struct Cfg *)win); func_020409B4(6); func_02040618(6,3,-192); ((struct Obj22360 *)p)->f98=win; }



void func_021BB61C(u8 *p) { Triple t; func_021BAC64(((struct Obj03240 *)p)->f0,&t,0,0); ((struct Obj03240 *)p)->f54=func_021BAC78(((struct Obj03240 *)p)->f0,(u32 *)(&t),48,64,3,1); func_0204B878(((struct Obj03240 *)p)->f54,4); func_0204B3DC(((struct Obj03240 *)p)->f54,0); }



/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021BB658(u8 *p, int enable)
{
    if (enable) {
        if (**(int * *)&((struct Obj04444 *)p)->f5C == 0) {
            func_0204B3DC(((struct Obj04444 *)p)->f54, 1);
            if (func_021BF6DC(*(u8 * *)&((struct Obj04444 *)p)->f4) == 0) {
                func_0204B878(((struct Obj04444 *)p)->f54, 4);
            } else {
                func_0204B878(((struct Obj04444 *)p)->f54, 6);
            }
        } else {
            func_0204B3DC(((struct Obj04444 *)p)->f54, 0);
        }
    } else {
        func_0204B3DC(((struct Obj04444 *)p)->f54, 0);
    }
}



/*
 * lever: ordered if/else chain, not switch dispatch; template word is 0x012C0190.
 */
void func_021BB6A0(u8 *p, unsigned index)
{
    Vec2_021BB280 pos;
    int x, y;
    int state;
    u8 *q;
    pos = d_021C38D0;
    if (func_021BF6DC(*(u8 * *)&((struct Obj04445 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 4;
    } else {
        q = (u8 *)func_021BAC3C(*(u8 * *)&((struct Obj04445 *)p)->f0);
        state = 16;
        if (index == 252) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 0, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 253) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 1, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 254) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 2, 1);
            else func_021BCF7C(q, 0, 0);
        } else {
            func_021BCF7C(q, 0, 0);
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 6;
        }
    }
    func_0204B404(((struct Obj04445 *)p)->f54, (const struct Vec2_021BB280 *)(&pos), 0);
    func_0204B878(((struct Obj04445 *)p)->f54, state);
}



void func_021BB76C(u8 *p) { ((struct Obj22365 *)p)->f10=0; func_021BC8FC(p+24,2,-10,0,16); }



int func_021BB784(u8 *p) { if (((struct Obj22366 *)p)->f10==0 && func_021BC93C(p+24)!=0) return 1; return 0; }



/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BB7A0(u8 *p) { ((struct Obj22367 *)p)->f10=0; func_021BC78C(p+56,1,1,0,6); }



/*
 * extent: includes the unlabelled tail-call stub at 0x021BB804.
 */
int func_021BB7B8(u8 *p)
{
    switch (((struct Obj13779 *)p)->f10) {
    case 0:
        if (func_021BC7DC(p + 0x38)) {
            func_021BC8FC(p + 0x18, 2, 0, -10, 16);
            ++((struct Obj13779 *)p)->f10;
        }
        break;
    case 1:
        return func_021BC93C(p + 0x18);
    }
    return 0;
}



void func_021BB804(u8 *a0)
{
    func_02040618(1, 3, 16);
}



/*
 * extent: two-byte alignment padding then existing ov110_func_021BB82C.c follower.
 */
void func_021BB814(u8 *p) { func_021BC8FC(p+24,2,0,-10,16); }


int func_021BB82C(u8 *p) { return func_021BC93C(p+0x18); }


void func_021BB838(u8 *p) { func_021BC868(p+24,2,63,124,0,12); }


int func_021BB854(u8 *p) { if (func_021BC898(p+24)!=0) { func_02040588(1,0); return 1; } return 0; }


/*
 * extent: includes the unlabelled forwarding stub at 0x021BB8AC.
 */
void func_021BB870(u8 *p)
{
    func_0207D63C((void *)0x04000050, 2, 63, 0, 16);
    func_02040588(1, 1);
    func_021BC868(p + 0x18, 2, 63, 0, 124, 12);
}


int func_021BB8AC(u8 *p)
{
    return func_021BC898(p + 0x18);
}


void func_021BB8B8(u8 *p) { int v; if (func_021BF6DC(*(u8 * *)&((struct Obj22368 *)p)->f4)==0) v=-4; else v=0; func_02041EE4(1,0,v); }


void func_021BB8D8(u8 *p)
{
    void *handle;
    int i;
    handle = func_020490F4(43, 42);
    if (func_021BF6DC(*(u8 * *)&((struct Obj10275 *)p)->f4) == 0) {
        func_020499D4(handle, 27, 1, 0, 0, 0, 0, 42);
        for (i = 0; i < 12; i++) func_02045374(*(void **)(p + 0x60 + i * 4));
    } else {
        func_020499D4(handle, 26, 1, 0, 0, 0, 0, 42);
        func_02045374(((struct Obj10275 *)p)->f90);
        func_02045374(((struct Obj10275 *)p)->f94);
    }
    func_02049238(handle);
    func_02041B6C(1);
}



int func_021BB954(u8 *a0) { return 1; }


void func_021BB958(char *p)
{
    u32_021BB958 r7 = func_021BAC44((u8 *)(*(u32_021BB958 *)p));
    void *r4 = *(void **)(p + 0x94);
    void *r6 = func_020457B0(14, 42);
    func_021BF7D4((u8 *)(*(u32_021BB958 *)(p + 4)), r6);
    func_02043B5C(func_02045770(r4), 1);
    func_0201DD78(15, 14, 1);
    func_0201C7A4(func_02045770(r4), 0, 0, r6, (void *)r7);
    func_02045808(r6);
    func_02045374(r4);
    func_02045334(r4);
    func_02041B6C(1);
}


/*
 * prototype-evidence: BF7FC's legacy source says void; this caller uses r0
 * at 0x021BB9CC/0x021BB9CE, so its observed unsigned result is retained.
 */
void func_021BB9C0(u8 *p,int flag) { u32_021BB9C0 n=func_021BF7FC(*(u8 * *)&((struct Obj02460 *)p)->f4); if(n>22)n=22; if(flag)func_021BBA10(p,n);else func_021BB9E8(p,n); }


/*
 * extent: two bytes of zero alignment padding after return.
 * lever: bind the step arithmetic to a local before the outer call; the
 * inline argument form adds a saved register and changes scheduling.
 */
void func_021BB9E8(u8 *p,u32_021BB9E8 unused) { int step=-192-func_02040804(6); func_021BC78C(p+56,6,1,step,8); }


void func_021BBA10(u8 *p,unsigned n)
{
    u32_021BBA10 owner,font;
    void *str;
    int i,x,height,base;
    owner=func_021BAC4C(*(u8 * *)&((struct Obj02460 *)p)->f0);
    font=func_021BAC44(*(u8 * *)&((struct Obj02460 *)p)->f0);
    str=func_020457B0(15,42);
    func_02043B5C(func_02045770(((struct Obj02460 *)p)->f98),15);
    ((struct Obj02460 *)p)->f9C=((struct Obj02460 *)p)->f98;
    p[0xa0]=0;
    for(i=0;i<n;i++) {
        if(i%2==0) x=8; else x=128;
        func_021BF814(*(u8 * *)&((struct Obj02460 *)p)->f4,i,(int)str);
        func_0201C724((void *)owner,(u32_021BBA10)func_02045770(((struct Obj02460 *)p)->f9C),(s16_021BBA10)x,(s16_021BBA10)((i/2)*16),(u32_021BBA10)str,font,1103);
        p[0xa0]=1;
    }
    func_02045808(str);
    base=func_02040804(6)+192;
    height=((n+1)/2)*16+8;
    if(height>192) height=192;
    else if(height<48) height=48;
    func_021BC78C(p+0x38,6,1,height-base,8);
    func_02045374(((struct Obj02460 *)p)->f98);
    func_02041B6C(6);
    func_02040588(6,1);
}


int func_021BBB0C(u8 *p, int a)
{
    unsigned owner;
    int ready;
    int result;
    owner = func_021BAC4C(*(u8 * *)&((struct Obj05289 *)p)->f0);
    ready = 1;
    if (a) {
        if (p[0xa0]) {
            if (func_0201C6C4((struct PrintSys *)owner, (void *)((unsigned)func_02045770(((struct Obj05289 *)p)->f9C))) == 0) {
                func_02045334(((struct Obj05289 *)p)->f9C);
                p[0xa0] = 0;
            }
        }
        ready = p[0xa0] == 0 ? 1 : 0;
    }
    result = func_021BC7DC(p + 0x38);
    if (ready && result) {
        if (a == 0) func_02040588(6, 0);
        return 1;
    }
    return 0;
}


void func_021BBB84(u8 *p, unsigned index)
{
    Vec2_021BB82C pos;
    int x, y;
    int state;
    ((struct Obj05290 *)p)->f58 = func_0204B3F4(((struct Obj05290 *)p)->f54);
    func_0204B3DC(((struct Obj05290 *)p)->f54, 1);
    if (func_021BF6DC(*(u8 * *)&((struct Obj05290 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 31;
    } else {
        state = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 30;
            break;
        }
    }
    func_0204B404(((struct Obj05290 *)p)->f54, (const struct Vec2_021BB280 *)((const struct Vec2_021BB82C *)(&pos)), 0);
    func_0204B878(((struct Obj05290 *)p)->f54, state);
}


int func_021BBC10(u8 *p)
{
    u16 state = func_0204B898(((struct Obj04446 *)p)->f54);
    if (state != 31 && state != 30) return 1;
    if (func_0204B98C(((struct Obj04446 *)p)->f54) == 0) {
        func_0204B3DC(((struct Obj04446 *)p)->f54, ((struct Obj04446 *)p)->f58);
        func_0204B878(((struct Obj04446 *)p)->f54, func_021BF6DC(*(u8 * *)&((struct Obj04446 *)p)->f4) == 0 ? 4 : 6);
        *(int *)&((struct Obj04446 *)p)->f58 = 0;
        return 1;
    }
    return 0;
}


u8 *func_021BBC5C(void *a, u8 *b, void *c)
{
    u8 *p;
    p = func_02030734(42, 444, 1, d_021C3C58, 211);
    ((struct Obj01392 *)p)->f0 = a;
    *(u8 * *)&((struct Obj01392 *)p)->f4 = b;
    ((struct Obj01392 *)p)->f8 = c;
    *(u8 * *)&((struct Obj01392 *)p)->f1A0 = func_021BF6D4(b);
    ((struct Obj01392 *)p)->f14 = 0;
    ((struct Obj01392 *)p)->f18 = 0;
    ((struct Obj01392 *)p)->f1A4 = 0;
    ((struct Obj01392 *)p)->f30 = func_020457B0(128, 42);
    ((struct Obj01392 *)p)->f2C = func_02045B38(0, 2, 146, 42);
    ((struct Obj01392 *)p)->f34 = func_02020D18(42);
    ((struct Obj01392 *)p)->f198 = 0;
    ((struct Obj01392 *)p)->f19A = 0;
    ((struct Obj01392 *)p)->f1A8 = 0;
    ((struct Obj01392 *)p)->f1AC = 0;
    ((struct Obj01392 *)p)->f1B0 = 0;
    ((struct Obj01392 *)p)->f1B4 = func_0202C9B4(1, 1, 42);
    return p;
}


void func_021BBCF0(u8 *p)
{
    func_0202CA0C(((struct Obj01248 *)p)->f1B4);
    if (((struct Obj01248 *)p)->f1B0) func_02030EAC(((struct Obj01248 *)p)->f1B0);
    if (((struct Obj01248 *)p)->f1A4) func_02030EAC(((struct Obj01248 *)p)->f1A4);
    if (((struct Obj01248 *)p)->f34) func_02020D3C(((struct Obj01248 *)p)->f34);
    if (((struct Obj01248 *)p)->f14) func_0204B3B4(((struct Obj01248 *)p)->f14);
    if (((struct Obj01248 *)p)->f18) func_0204B3B4(((struct Obj01248 *)p)->f18);
    if (((struct Obj01248 *)p)->f2C) func_02045C04(((struct Obj01248 *)p)->f2C);
    if (((struct Obj01248 *)p)->f30) func_02045808(((struct Obj01248 *)p)->f30);
    func_020452E8(((struct Obj01248 *)p)->fC);
    func_020452E8(((struct Obj01248 *)p)->f10);
    func_020307B0(p);
}


/*
 * prototype: legacy 02040618 fourth input is unused by its full 02042360 target; caller sets only r0-r2.
 */
void func_021BBD60(u8 *p,u32_021BBD60 a)
{
    func_021BC068(p,(void *)a);
    func_020498F4((void *)a,25,0,0,0,0,42);
    func_020498F4((void *)a,25,4,0,0,0,42);
    ((struct Obj01922 *)p)->f19A=-192;
    func_02040618(4,3,((struct Obj01922 *)p)->f19A);
    func_02049658((void *)a,14,0,0,0,0,42);
    func_02049658((void *)a,14,4,0,0,0,42);
    *(u32_021BBD60 *)&((struct Obj01922 *)p)->fC=func_020450F0(0,3,1,28,4,0,1);
    *(u32_021BBD60 *)&((struct Obj01922 *)p)->f10=func_020450F0(4,3,1,28,4,0,1);
    func_02045374(((struct Obj01922 *)p)->fC);
    func_02045374(((struct Obj01922 *)p)->f10);
    func_021BC120(p);
    func_021BC160(p);
    func_021BC23C(p);
    func_021BC1B8(p);
    func_0202CA3C(((struct Obj01922 *)p)->f1B4,0,0,32,6);
    func_0202CB18(((struct Obj01922 *)p)->f1B4,0,(void *)a,25,0);
    func_0202CB4C(((struct Obj01922 *)p)->f1B4,0,0,0);
    func_0202CEBC(((struct Obj01922 *)p)->f1B4,0,((struct Obj01922 *)p)->fC);
    func_0202CC58(((struct Obj01922 *)p)->f1B4,0);
    ((struct Obj01922 *)p)->f1B8=0;
}
