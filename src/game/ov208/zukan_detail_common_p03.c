/*
 * file:     zukan_detail_common_p03.c
 * unit:     yes
 * function: func_021BC508, func_021BC518, func_021BC520, func_021BC560, func_021BC610, func_021BC61C, func_021BC678, func_021BC6BC, func_021BC6C8, func_021BC6D8, func_021BC6F8, func_021BC718, func_021BC738, func_021BC758, func_021BC7B4, func_021BC844, func_021BC97C, func_021BC99C, func_021BC9BC, func_021BCA54, func_021BCA68, func_021BCB4C, func_021BCBB4, func_021BCC80, func_021BCC84, func_021BCD68
 * address:  0x021BC508
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D67C  0x0207D67C  arm
 *   func_02030734 0x02030734 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   d_021C8D98 0x021C8D98 data a1
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02021D50 0x02021D50  thumb
 *   func_02021660 0x02021660 thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_0202173C 0x0202173C thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8D98  0x021C8D98  data
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 *   func_0203FB44 0x0203FB44 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BCE10 0x021BCE10 thumb
 *   func_021BCEC0 0x021BCEC0 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA54 0x0200CA54 thumb
 *   func_021BD8C0 0x021BD8C0 thumb
 *   func_021BE710 0x021BE710 thumb
 *   func_021BC35C 0x021BC35C thumb
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_021BC26C 0x021BC26C thumb ov208
 *   func_021BC39C 0x021BC39C thumb ov208
 *   func_021BE778 0x021BE778 thumb ov208
 *   func_021BD954 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021BC274 0x021BC274 thumb
 *   func_021BDB08 0x021BDB08 thumb
 *   func_021BDB54 0x021BDB54 thumb
 *   func_021BC2F0 0x021BC2F0 thumb
 *   func_021BD974 0x021BD974 thumb
 *   func_021BE7A4 0x021BE7A4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BCF18 0x021BCF18 thumb
 *   func_021BCF2C 0x021BCF2C thumb
 *   func_021BC310 0x021BC310 thumb
 *   func_021BCF3C 0x021BCF3C thumb
 *   func_021BC240 0x021BC240 thumb
 *   func_021BEA00 0x021BEA00 thumb
 *   func_021BF784 0x021BF784 thumb ov208
 *   func_021C255C 0x021C255C thumb
 *   func_021C3B68 0x021C3B68 thumb
 *   d_021C8DB0 0x021C8DB0 data a1
 *   d_021C8508 0x021C8508 data a4
 *   d_021C8590 0x021C8590 data a4
 *   d_021C86F0 0x021C86F0 data a4
 *   d_021C881C 0x021C881C data a4
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021C8164 0x021C8164 data a2
 */
#include "../../matched/include/Obj02544.h"
#include "../../matched/include/Obj04893.h"
#include "../../matched/include/Obj18185.h"
#include "../../matched/include/Obj18186.h"
#include "../../matched/include/Obj18187.h"
#include "../../matched/include/Obj18188.h"
#include "../../matched/include/Obj18189.h"
#include "../../matched/include/Obj02252.h"
#include "../../matched/include/Obj12112.h"
#include "../../matched/include/Obj07226.h"
#include "../../matched/include/Obj02253.h"

#define REG60 (*(volatile u16 *)0x04000060)
struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
struct S02021D50;
struct Obj0203159C;
struct Blk37;
struct GfFont;
struct Ov208Icon;
struct Ov208Mode;
struct Ov208Slot;
struct PrintSys;
struct Node;
struct Ov208Mgr;
struct S020315D4;
struct State;
struct Ov208Fade;
struct Ov208Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {void *task,*memory,*slots;u16 mask,pad;u32 mode;} PalFade;

struct Ov208Gfx { int f0; int f4; void *gfx; };

struct Ov208PalFade {
    u32 f0;
    u32 f4;
    void *slots;
    u16 mask;
};

typedef unsigned char  u8;

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  kind;
};

struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };

struct Ov208Main_021BCA68 {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    int f20; int f24; int f28;
};

typedef signed int     s32;

struct Ov208Main_021BCBB4 {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    void *obj; int f24; int f28;
};

struct Ov208Mode { int f0; int mode; };

struct Ov208Slot {
    u16 heap; u16 pad;
    int f4; int f8; int fc; int f10; int f14; int f18; int f1c;
    void *obj;
    void *mem;
};

typedef enum {ShadeToon=0,ShadeHighlight=1} GXShading;

extern void func_0207D67C(unsigned int, int, int, int, int, int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02021518(u32);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct Ctx *c);
extern u32 func_02021ED8(const char *ptr);
extern void func_02021D50(struct S02021D50 *p);
extern void func_02021660(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern int func_0202173C(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *h);
extern void func_02041B6C(u32 bit);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0203064C(u32 src, u32 heap, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern char *func_021BCE10(u32 display, u32 heap, int threeD);
extern void func_021BCEC0(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern int func_020056A0(void (*fn)(void), void *arg, int n);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA54(struct Blk37 *p);
extern char *func_021BD8C0(u16 heap, unsigned arg);
extern struct Ov208Icon *func_021BE710(u16 heap, unsigned arg);
extern void *func_021BC35C(u32 heap, void *a, void *b, void *c, void *d, void *e, void *f, int g, u16 h, void *i);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021BC26C(void *);
extern void func_021BC39C(void *);
extern void func_021BE778(struct Ov208Mgr *m);
extern void func_021BD954(struct Ov208Mgr *m);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_021BC274(struct State *p, int arg);
extern unsigned func_021BDB08(const struct State *p);
extern unsigned func_021BDB54(const struct State *p);
extern void func_021BC2F0(char *p, int a, int b);
extern void func_021BD974(struct Ov208Fade *m);
extern void func_021BE7A4(struct Ov208Icon *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BCF18(char *p);
extern void func_021BCF2C(char *p);
extern void func_021BC310(char *p, int v);
extern void func_021BCF3C(char *p);
extern struct Ov208Obj *func_021BC240(void *owner, int val, u32 heap);
extern void func_021BEA00(void *mem, u32 heap);
extern void func_021BF784(u16 *p, u16 v);
extern void func_021C255C(u16 *dst, u16 value);
extern void func_021C3B68(u16 *p, u32 value);
extern void func_020434DC(unsigned,unsigned);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
void func_021BC508(int flag, int *p);
void func_021BC518(int *p);
void func_021BC520(int flag, int *p);
PalFade *func_021BC560(u32 heap,u16 mask);
void *func_021BC610(u32 heap);
void func_021BC61C(char *p);
void func_021BC678(char *p);
void func_021BC6BC(char *p);
int func_021BC6C8(char *p);
void func_021BC6D8(char *p);
void func_021BC6F8(char *p);
void func_021BC718(char *p);
void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
void ov208_func_021BC758(struct Ov208PalFade *p);
void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d);
struct Ov208Win *ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
void func_021BC97C(char *p);
void func_021BC99C(char *p);
u32 ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);
void func_021BCA54(u32 a, u32 packed);
int func_021BCA68(void *owner, int unused, struct Ov208Args *args);
int func_021BCB4C(void *a,int b,int c,char *p);
int func_021BCBB4(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main_021BCBB4 *m);
void func_021BCC80(void);
void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s);
void func_021BCD68(void);
extern const char d_021C8D98[];
extern const char data_021C8D98[];
extern const u8 data_021C80E0[2][4];
extern const u8 data_021C80E8[2][4];
extern const struct Ov208BgArc data_021C80F0[2];
extern const char d_021C8DB0[];
extern void *d_021C8508[];
extern void *d_021C8590[];
extern void *d_021C86F0[];
extern void *d_021C881C[];
extern const u16 d_021C8164[][4];


void func_021BC508(int flag, int *p)
{
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    func_021BC520(flag, p);
}

/*
 * Writes 0x2D to the first two words.
 */
void func_021BC518(int *p)
{
    p[0] = 0x2d;
    p[1] = 0x2d;
}


void func_021BC520(int flag, int *p)
{
    if (flag == 0) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], 0, p[2] - 0x10);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], 0, p[2] - 0x10);
    }
}

PalFade *func_021BC560(u32 heap,u16 mask)
{
    PalFade *p=func_02030734(heap,20,1,d_021C8D98,0x1e5);
    p->memory=func_02030734(heap,func_02030CB0(2),1,d_021C8D98,0x1e8);
    p->task=func_02030CBC(2,p->memory);
    p->slots=func_02021518(heap);
    func_02021EE4(p->slots,1);
    p->mask=mask;
    if(p->mask&1)func_0202155C(p->slots,0,0x1a0,heap);
    if(p->mask&4)func_0202155C(p->slots,2,0x100,heap);
    if(p->mask&2)func_0202155C(p->slots,1,0x1a0,heap);
    if(p->mask&8)func_0202155C(p->slots,3,0x1c0,heap);
    p->mode=0;
    return p;
}

void *func_021BC610(u32 heap)
{
    return func_021BC560(heap, 0xf);
}

void func_021BC61C(char *p)
{
    if(((struct Obj02544 *)p)->fC&8)func_020215A0(((struct Obj02544 *)p)->f8,3);
    if(((struct Obj02544 *)p)->fC&2)func_020215A0(((struct Obj02544 *)p)->f8,1);
    if(((struct Obj02544 *)p)->fC&4)func_020215A0(((struct Obj02544 *)p)->f8,2);
    if(((struct Obj02544 *)p)->fC&1)func_020215A0(((struct Obj02544 *)p)->f8,0);
    func_02021540(((struct Obj02544 *)p)->f8);
    func_02030DA4(((struct Obj02544 *)p)->f0);
    func_020307B0((void *)(((struct Obj02544 *)p)->f4));
    func_020307B0((void *)((unsigned)p));
}


/*
 * Releases +0 and re-checks the handle at +8 for the two armed states at +0x10.
 */
void func_021BC678(char *p)
{
    func_02030D28((struct Ctx *)(((struct Obj04893 *)p)->f0));
    switch (((struct Obj04893 *)p)->f10) {
    case 0:
    case 1:
        break;
    case 2:
        if (func_02021ED8((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 0;
        break;
    case 3:
        if (func_02021ED8((const char *)(((struct Obj04893 *)p)->f8)) == 0)
            ((struct Obj04893 *)p)->f10 = 1;
        break;
    }
}


/*
 * Loads the word at +8 and tail-calls the function at 0x02021D51 (the thumb
 * address of the ARM9 function at 0x02021D50).
 */
void func_021BC6BC(char *p)
{
    func_02021D50((struct S02021D50 *)(((struct Obj18185 *)p)->f8));
}



/*
 * True when the word at +0x10, less two, is 0 or 1.
 */
int func_021BC6C8(char *p)
{
    unsigned int v = ((struct Obj18186 *)p)->f10;

    v -= 2;
    return v <= 1;
}


void func_021BC6D8(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, -1, 0x10, 0);
    ((struct Obj18187 *)p)->f10 = 2;
}


void func_021BC6F8(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, -1, 0, 0x10);
    ((struct Obj18188 *)p)->f10 = 3;
}


/*
 * Runs the idle transition with 0x10 twice and marks state 1.
 */
void func_021BC718(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, 0, 0x10, 0x10);
    ((struct Obj18189 *)p)->f10 = 1;
}

void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g)
{
    func_02021660(p->gfx, (void *)a, b, c, d, e, f, g);
}


void ov208_func_021BC758(struct Ov208PalFade *p)
{
    if (p->mask & 1)
        func_020216D4(p->slots, 0, 0, 0x1a0);
    if (p->mask & 4)
        func_020216D4(p->slots, 2, 0, 0x100);
    if (p->mask & 2)
        func_020216D4(p->slots, 1, 0, 0x1a0);
    if (p->mask & 8)
        func_020216D4(p->slots, 3, 0, 0x1c0);
}

void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d)
{
    if(((struct Obj02252 *)p)->fC&1)func_0202173C(((struct Obj02252 *)p)->f8,1,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&4)func_0202173C(((struct Obj02252 *)p)->f8,4,0xff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&2)func_0202173C(((struct Obj02252 *)p)->f8,2,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&8)func_0202173C(((struct Obj02252 *)p)->f8,8,0x3fff,b,c,d,0,((struct Obj02252 *)p)->f0);
}


struct Ov208Win *ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = func_02030734(heap, sizeof(*w), 1, data_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = func_020490F4(0x9f, heap);
    func_02049BDC(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    func_02049BDC(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = func_02049740(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    func_02049990(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0x15, 0x20, 3, pal);
    func_020413B0(layer, 0, 0, 0x20, 0x15, objPal);
    func_02049238(h);
    func_02041B6C(layer);
    w->layer = layer;
    w->kind = 4;
    return w;
}


/*
 * Passes the byte at +4 and the two halfwords of the word at +0 on, then re-inits the object.
 */
void func_021BC97C(char *p)
{
    unsigned int w;

    w = ((struct Obj12112 *)p)->f0;
    func_0203FB44(((struct Obj12112 *)p)->f4, (unsigned short)w, (unsigned short)(w >> 16));
    func_020307B0((void *)((int)p));
}


void func_021BC99C(char *p)
{
    unsigned char c;

    c = ((struct Obj07226 *)p)->f5;
    if (c == 0) {
        func_02041EE4(((struct Obj07226 *)p)->f4, 1, 1);
        ((struct Obj07226 *)p)->f5 = 4;
    } else {
        ((struct Obj07226 *)p)->f5 = c - 1;
    }
}


u32 ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc,
                        u32 chr, u32 scr, u32 cell, u32 chrOfs)
{
    void *h;
    u32 type;

    type = 0;
    if (layer >= 4)
        type = 4;
    h = func_020490F4(arc, heap);
    if (skip == 0)
        func_02049BDC(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = func_02049740(h, scr, layer, 0, 0, heap);
    func_02049990(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0, 0x20, 0x18, pal);
    func_02049238(h);
    func_02041B6C(layer);
    return chrOfs;
}

void func_021BCA54(u32 a, u32 packed)
{
    func_0203FB44(a, (u16)packed, (u16)(packed >> 16));
}

/*
 * 2026-10-02: only func_021BCC80 (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee func_021BC35C is declared void in its matched file but returns the new object (caller stores r0).
 */
int func_021BCA68(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main_021BCA68 *p;
    func_0203064C(1, 0x95, 0x90000);
    p = func_0203159C(owner, 0x2c, 0x95);
    func_02082BCC(p, 0, 0x2c);
    p->heap = 0x95;
    args->f10 = 0;
    p->disp = func_021BCE10(0, p->heap, 1);
    func_021BCEC0(p->disp);
    p->disp = func_021BCE10(0, p->heap, 0);
    p->font = func_0201D7EC(0x17, 0, 0, 0, p->heap);
    p->gfx = (void *)func_0201C440((void *)p->heap);
    p->task = func_020056A0(func_021BCC80, p, 1);

    p->f14 = func_021BD8C0(p->heap, func_0200CA54(func_0200CA1C(args->src)));
    p->f18 = func_021BE710(p->heap, (unsigned int)p->font);
    p->fsm = func_021BC35C(p->heap, args->src, p->disp, p->font, p->gfx, p->f14, p->f18, args->f8, args->fc, &args->fe);
    p->f20 = 0;
    p->f24 = 0;
    func_021BCC84((struct Ov208Mode *)args, (struct Ov208Slot *)p);
    p->f28 = 0;
    func_0204E720(3, 0, 0, 0);
    func_0203D34C(1, p->heap);
    return 1;
}

/*
 * extent: 102 code bytes, then two zero alignment bytes at 021BCBB2.
 */
int func_021BCB4C(void *a,int b,int c,char *p)
{
    func_0204E720(3,16,16,0);
    if(((struct Obj02253 *)p)->f20)func_021BC26C(((struct Obj02253 *)p)->f20);
    if(((struct Obj02253 *)p)->f24)func_020307B0((void *)(((struct Obj02253 *)p)->f24));
    func_021BC39C(((struct Obj02253 *)p)->f1C);
    func_021BE778(((struct Obj02253 *)p)->f18);
    func_021BD954(((struct Obj02253 *)p)->f14);
    func_02030EAC(((struct Obj02253 *)p)->f10);
    func_0201C6EC((struct PrintSys *)(*(unsigned *)&((struct Obj02253 *)p)->fC));
    func_0201C4C0(((struct Obj02253 *)p)->fC);
    func_0201D83C(((struct Obj02253 *)p)->f8);
    func_021BCEC0(*(char * *)&((struct Obj02253 *)p)->f4);
    func_020315D4(a);
    func_020306F0(149);
    return 1;
}

int func_021BCBB4(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main_021BCBB4 *m)
{
    int done = 0;
    u32 v;
    if (*cnt <= 8)
        *cnt = *cnt + 1;
    if (func_021BC274(m->obj, (int)m->fsm) != 0) {
        if (m->f28 != 0) {
            a->f4 = m->f28;
            func_021BCC84((struct Ov208Mode *)a, (struct Ov208Slot *)m);
            m->f28 = 0;
            done = 1;
        } else {
            return 1;
        }
    }
    if (done == 0) {
        v = func_021BDB08(m->f14);
        if (v == 0)
            v = func_021BDB54(m->f14);
        func_021BC2F0(m->obj, (int)m->fsm, v);
        switch (v) {
        case 1: a->f10 = 0; break;
        case 2: a->f10 = 1; break;
        case 6: m->f28 = 1; break;
        case 7: m->f28 = 2; break;
        case 8: m->f28 = 3; break;
        case 9: m->f28 = 4; break;
        }
    }
    func_021BD974(m->f14);
    func_021BE7A4(m->f18);
    func_0201C4E4(m->gfx);
    func_021BCF18(m->disp);
    func_021BCF2C(m->disp);
    if (done == 0)
        func_021BC310(m->obj, (int)m->fsm);
    func_021BCF3C(m->disp);
    return 0;
}

void func_021BCC80(void)
{
}

/*
 * 2026-10-04 (D2-16): callee func_021BF784 filed EXACT as src/matched/ov/ov208_func_021BF784.c (strh leaf). Still MATCH only because no
 * shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BF784 (init for mode 2, another lane) has no witness yet; bytes match.
 */
void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s)
{
    void **tbl;
    void *mem;
    if (s->obj != 0)
        func_021BC26C(s->obj);
    if (s->mem != 0)
        func_020307B0(s->mem);
    switch (m->mode) {
    case 1:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1c3);
        func_021BEA00(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8508;
        break;
    case 2:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1cb);
        func_021BF784(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8590;
        break;
    case 3:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1d3);
        func_021C255C(mem, s->heap);
        s->mem = mem;
        tbl = d_021C86F0;
        break;
    case 4:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1db);
        func_021C3B68(mem, s->heap);
        s->mem = mem;
        tbl = d_021C881C;
        break;
    }
    s->obj = func_021BC240(tbl, (int)s->mem, s->heap);
}

static inline void SetShading(GXShading shading) {REG60=(u16)((REG60 & ~0x3002)|(shading<<1));}

static inline void AntiAlias(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x10);else REG60&=(u16)~0x3010;}

static inline void AlphaTest(int enable,int ref) {if(enable){REG60=(u16)((REG60 & ~0x3000)|4);*(volatile u16 *)0x04000340=(u16)ref;}else REG60&=(u16)~0x3004;}

static inline void AlphaBlend(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|8);else REG60&=(u16)~0x3008;}

static inline void EdgeMarking(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x20);else REG60&=(u16)~0x3020;}

/*
 * lever: SDK g3x.h shading enum and boolean inline bodies preserve the hardware mask sequence; pool word at 021BCE04 is BFFF0000.
 * volatile: hardware 04000008 and 04000060 read/write at 021BCD78-021BCDBA; 04000580 write at 021BCDD8.
 */
void func_021BCD68(void)
{
    unsigned i;
    func_020434DC(1,1);
    *(volatile u16 *)0x04000008=(*(volatile u16 *)0x04000008 & ~3)|1;
    SetShading(ShadeHighlight);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580=0xbfff0000;
    for(i=0;i<4;i++)func_02046A94((unsigned char)i,d_021C8164[i]);
    func_02046BE0(0,0);
}
