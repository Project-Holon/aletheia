/*
 * file:     pmsiv_wordwin_p10.c
 * unit:     yes
 * function: func_021BFF7C, func_021C00AC, func_021C00FC, func_021C0134, func_021C01E4, func_021C022C
 * address:  0x021BFF7C
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
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_0204B528 0x0204B528 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF758 0x021BF758 thumb ov110
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_020439A0 0x020439A0 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   overlay_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02024988 0x02024988 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02031324 0x02031324 arm
 *   func_021C0490 0x021C0490 thumb ov110
 *   func_021C05B0 0x021C05B0 thumb ov110
 *   func_0203133C 0x0203133C arm
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202DC98 0x0202DC98 thumb
 */
#include "../../matched/include/Obj01533.h"
#include "../../matched/include/Obj06393.h"
#include "../../matched/include/Obj05298.h"
#include "../../matched/include/Obj01713.h"
#include "../../matched/include/Obj06394.h"
#include "../../matched/include/Obj13806.h"
#include "../../matched/include/Obj22406.h"

struct Actor;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Bmp;
struct Vec2;
struct GfFont;
struct MsgBank;
struct Obj0203159C;
struct PrintSys;
struct Rec;
struct S020314B8;
struct S020315D4;
struct Obj0202DC98;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

struct Pt { u16 x, y; };

typedef struct { s16 x,y; } Vec2;

typedef signed int     s32;

extern u32 func_021BAC44(u8 *);
extern u32 func_021BF734(u8 *);
extern u8 func_021BF6DC(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_0204B528(struct Actor *, const struct Pt *);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_021BF758(u8 *p, u32 a, int b);
extern void func_0201DD68(void);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_020439A0(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern int func_02034AC4(s32 handle);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02024988(int a0);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern void *func_02031324(int a0);
extern void func_021C0490(u8 *);
extern void func_021C05B0(char *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_0202DC98(struct Obj0202DC98 *o);
void func_021BFF7C(u8 *p, u32 n, u32 y);
void func_021C00AC(u8 *p, unsigned i);
int func_021C00FC(u8 *p);
int func_021C0134(void *owner,int unused,void **input);
int func_021C01E4(void *p, int a, int b, char *q);
int func_021C022C(u8 *p);
void func_021C0250(int *out,u8 *p,int value);
extern const u8 overlay_id[];
extern char ov067_id[];

void func_021BFF7C(u8 *p, u32 n, u32 y)
{
    u32 font;
    struct Pt pos;
    u32 wrap, x;
    struct Bmp *dest;
    font = func_021BAC44(*(u8 * *)&((struct Obj01533 *)p)->f0);
    if (n < 2 || n >= func_021BF734(*(u8 * *)&((struct Obj01533 *)p)->f4)) return;
    if (!func_021BF6DC(*(u8 * *)&((struct Obj01533 *)p)->f4) && func_021BF724(*(u8 * *)&((struct Obj01533 *)p)->f4) == 11) {
        x = 24 + 112 * ((n - 2) & 1);
        n = (n - 2) * 4;
        pos.x = x;
        pos.y = y - 8;
        p += 32;
        func_0204B528(*(struct Actor **)(p + n), &pos);
        func_0204B3DC(*(struct Obj **)(p + n), 1);
        return;
    }
    func_021BF758(*(u8 * *)&((struct Obj01533 *)p)->f4, n - 2, (int)(((struct Obj01533 *)p)->f48));
    func_0201DD68();
    if (y <= 240) {
        func_0201C7A4(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 112 * ((n - 2) & 1), y, ((struct Obj01533 *)p)->f48, (void *)font);
    } else {
        wrap = 256 - y;
        func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0);
        func_0201C7A4(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0, 0, ((struct Obj01533 *)p)->f48, (void *)font);
        n = 112 * ((n - 2) & 1);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        func_020439A0(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, 0, n, y, 96, wrap, 65535);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        func_020439A0(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, wrap, n, 0, 96, 16 - wrap, 65535);
    }
}

void func_021C00AC(u8 *p, unsigned i) {
    Vec2 pos;
    ((struct Obj06393 *)p)->f18=func_0204B3F4(((struct Obj06393 *)p)->f14);
    func_0204B3DC(((struct Obj06393 *)p)->f14,1);
    if (i != -1) {
        pos.x=0x70*(i&1)+0x3e;
        pos.y=0x18*((i>>1)+1);
        func_0204B404(((struct Obj06393 *)p)->f14,(const struct Vec2 *)(&pos),0);
        func_0204B878(((struct Obj06393 *)p)->f14,0x1c);
    }
}

int func_021C00FC(u8 *p) { if(func_0204B898(((struct Obj05298 *)p)->f14)!=28) return 1; if(!func_0204B98C(((struct Obj05298 *)p)->f14)) { func_0204B3DC(((struct Obj05298 *)p)->f14,((struct Obj05298 *)p)->f18); func_0204B878(((struct Obj05298 *)p)->f14,8); ((struct Obj05298 *)p)->f18=0; return 1; } return 0; }

int func_021C0134(void *owner,int unused,void **input) {
    u8 *p;
    func_02034AC4((unsigned)overlay_id);
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_0203064C(1,81,0x1c000);
    p=func_0203159C(owner,176,81);
    func_02082BCC(p,0,176);
    ((struct Obj01713 *)p)->f4=81;
    ((struct Obj01713 *)p)->f1C=*input;
    ((struct Obj01713 *)p)->f20=func_02024988((int)(*input));
    *(void ** *)&((struct Obj01713 *)p)->f0=input;
    ((struct Obj01713 *)p)->f58=func_0201D7EC(23,0,0,0,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f60=func_02045B38(0,2,146,((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f5C=(void *)func_0201C440((void *)(((struct Obj01713 *)p)->f4));
    ((struct Obj01713 *)p)->fAC=func_02031324(((struct Obj01713 *)p)->f4);
    ((struct Obj01713 *)p)->f94=255;
    ((struct Obj01713 *)p)->f95=255;
    func_021C0490(p);
    return 1;
}

int func_021C01E4(void *p, int a, int b, char *q) {
    func_021C05B0(q);
    func_0203133C(((struct Obj06394 *)q)->fAC);
    func_0201C6EC(((struct Obj06394 *)q)->f5C);
    func_0201C4C0(((struct Obj06394 *)q)->f5C);
    func_02045C04(((struct Obj06394 *)q)->f60);
    func_0201D83C(((struct Obj06394 *)q)->f58);
    func_020315D4(p);
    func_020306F0(0x51);
    func_02034A5C((int)ov067_id);
    return 1;
}

int func_021C022C(u8 *p) { if(func_0201C6B4(((struct Obj13806 *)p)->f5C) && func_0202DC98(((struct Obj13806 *)p)->f8C)) return 1; return 0; }

void func_021C0250(int *out,u8 *p,int value) { *out=value; ((struct Obj22406 *)p)->f9C=0; }
