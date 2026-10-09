/*
 * file:     ctvt_draw_p03.c
 * unit:     yes
 * function: func_021BE0A8, func_021BE0AC, func_021BE0B0, func_021BE0B4, func_021BE0B8, func_021BE0C8, func_021BE0CC, func_021BE0D0, func_021BE0D4, func_021BE0D8, func_021BE0EC, func_021BE0F0, func_021BE0F8, func_021BE0FC, func_021BE100, func_021BE11C, func_021BE1A4, func_021BE1E4, func_021BE210, func_021BE2E0, func_021BE2F0, func_021BE318, func_021BE34C, func_021BE364, func_021BE410, func_021BE43C
 * address:  0x021BE0A8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0202EB0C  0x0202EB0C  thumb
 *   unit_0202EB14  0x0202EB14  thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020456F8  0x020456F8  arm
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_021BD1AC 0x021BD1AC thumb ov172
 *   d_021C724C 0x021C724C data a4
 *   func_021BD3B8 0x021BD3B8 thumb ov172
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_021BD43C 0x021BD43C thumb ov172
 */
#include "../../matched/include/Obj24128.h"
#include "../../matched/include/Obj24129.h"
#include "../../matched/include/Obj24130.h"
#include "../../matched/include/Obj24131.h"
#include "../../matched/include/Obj14311.h"
#include "../../matched/include/Obj24132.h"
#include "../../matched/include/Obj24133.h"
#include "../../matched/include/Obj24134.h"
#include "../../matched/include/Obj24135.h"
#include "../../matched/include/Obj24136.h"
#include "../../matched/include/Obj24137.h"
#include "../../matched/include/Obj24138.h"
#include "../../matched/include/Obj24139.h"
#include "../../matched/include/Obj24140.h"
#include "../../matched/include/Obj08262.h"
#include "../../matched/include/Obj10667.h"
#include "../../matched/include/Obj24141.h"
#include "../../matched/include/Obj05448.h"
#include "../../matched/include/Obj03856.h"
#include "../../matched/include/Obj24143.h"
#include "../../matched/include/Obj24145.h"
#include "../../matched/include/Obj24146.h"
#include "../../matched/include/Obj24147.h"

struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct Descriptor;
struct CharBuf;
struct Actor;
struct Obj;
struct StrObj;
struct Vec2;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32_021BE0A8;

typedef signed int     s32;

typedef unsigned int   u32_021BE0AC;

typedef unsigned int   u32_021BE0B0;

typedef unsigned int   u32_021BE0B4;

typedef unsigned int   u32_021BE0B8;

typedef unsigned int   u32_021BE0C8;

typedef unsigned int u32_021BE0CC;

typedef unsigned long u32_021BE0D0;

typedef unsigned long u32_021BE0D4;

typedef unsigned int   u32_021BE0D8;

typedef unsigned int   u32_021BE0EC;

typedef unsigned int   u32_021BE0F0;

typedef unsigned int   u32_021BE0F8;

typedef unsigned int   u32_021BE0FC;

typedef unsigned int   u32_021BE100;

typedef unsigned int u32_021BE11C;

typedef struct { u32_021BE11C heap; u8 count; u8 pad[3]; void *items; u32_021BE11C zero; u8 a,b,c,d; } Descriptor;

typedef struct { u32_021BE11C handle; u16 value; u16 pad; u32_021BE11C zero; } Item;

typedef unsigned int   u32_021BE1A4;

typedef unsigned int u32_021BE1E4;

typedef unsigned int u32_021BE210;

struct Q { u8 b[4]; };

struct Pt { u16 x; u16 y; struct Q yv; struct Q xv; };

typedef unsigned int   u32_021BE2E0;

typedef unsigned int u32_021BE2F0;

typedef unsigned int   u32_021BE318;

typedef unsigned int   u32_021BE34C;

typedef unsigned int u32_021BE364;

typedef unsigned int u32_021BE410;

typedef unsigned int u32_021BE43C;

extern u32_021BE100 sub_0202EB0C(void);
extern int unit_0202EB14(void);
extern void *func_02045EC0(struct MsgBank *bank, u32_021BE11C index);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void func_02045334(struct Descriptor *);
extern int func_021BE05C(void *p);
extern u32_021BE210 func_021B8BA4(int unused, char *base, int i);
extern u32_021BE210 func_021B8B8C(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void *func_02008510(void *a, int tag);
extern u32_021BE210 func_0201D304(struct StrObj *s, u32_021BE210 a, u32_021BE210 b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BE210 which);
extern void func_0204B3DC(struct Obj *p, u32_021BE210 v);
extern void func_0204B9A0(struct Actor *a);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32_021BE2F0 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32_021BE2F0 val);
extern u8 *func_0202EE8C(u32_021BE318 a, void *b, u8 c, u8 d, u16 e);
extern void func_0202F038(u8 *p);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021BE364 size, u32_021BE364 heap);
extern void *func_02030734(u32_021BE364,u32_021BE364,int,const char *,u16);
extern void *func_020124F4(u16 heap);
extern unsigned int func_0203630C(void);
extern void func_021BD1AC(char *self);
extern void func_021BD3B8(u8 *p);
extern u32_021BE410 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int h);
extern u32_021BE43C func_0200FB24(void);
extern void func_0200FB38(void);
extern int func_021BD43C(char *ctx); /* ov172 definition: src/pending/ov/ov172_func_021BD43C.c (one argument; r1 is overwritten before use) */
void func_021BE0A8(void *p, u32_021BE0A8 v);
u32_021BE0AC func_021BE0AC(void *p);
void func_021BE0B0(void *p, u32_021BE0B0 v);
u32_021BE0B4 func_021BE0B4(void *p);
void func_021BE0B8(void *p);
u32_021BE0C8 func_021BE0C8(void *p);
void func_021BE0CC(void *p, u32_021BE0CC v);
u32_021BE0D0 func_021BE0D0(void *p);
void func_021BE0D4(void *p, u32_021BE0D4 v);
int func_021BE0D8(void *p);
u32_021BE0EC func_021BE0EC(void *p);
void func_021BE0F0(u8 *c);
u32_021BE0F8 func_021BE0F8(void *p);
void func_021BE0FC(void *p, u32_021BE0FC v);
int func_021BE100(void);
u32_021BE11C func_021BE11C(u8 *p);
void func_021BE1A4(char *p);
void func_021BE1E4(u8 *p);
void func_021BE210(char *a, u8 idx);
void func_021BE2E0(void *p);
void func_021BE2F0(u32_021BE2F0 *p, void *q);
void func_021BE318(char *a0, void *a1);
void func_021BE34C(void *p);
int func_021BE364(struct Obj0203159C *obj,int unused,u8 *arg);
int func_021BE410(void *a, void *b, int c, u32_021BE410 *p);
int func_021BE43C(void *a, void *b, void *c, u32_021BE43C *p);
extern const struct Q d_021C7048;
extern const struct Q d_021C704C;
extern u8 d_021C724C[];


/*
 * Set the u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0A8(void *p, u32_021BE0A8 v)
{
    ((struct Obj24128 *)p)->f19 = v;
}


/*
 * Field getter, u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0AC func_021BE0AC(void *p)
{
    return ((struct Obj24129 *)p)->f20;
}


/*
 * Set the u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0B0(void *p, u32_021BE0B0 v)
{
    ((struct Obj24130 *)p)->f20 = v;
}


/*
 * Field getter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0B4 func_021BE0B4(void *p)
{
    return ((struct Obj24131 *)p)->f24;
}


/*
 * Invert the flag at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0B8(void *p)
{
    u32_021BE0B8 v = ((struct Obj14311 *)p)->f24;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    ((struct Obj14311 *)p)->f24 = v;
}


/*
 * Field getter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0C8 func_021BE0C8(void *p)
{
    return ((struct Obj24132 *)p)->f28;
}

void func_021BE0CC(void *p, u32_021BE0CC v)
{
    ((struct Obj24133 *)p)->f28 = v;
}


u32_021BE0D0 func_021BE0D0(void *p)
{
    return ((struct Obj24134 *)p)->f2C;
}


void func_021BE0D4(void *p, u32_021BE0D4 v)
{
    ((struct Obj24135 *)p)->f2C = v;
}


/*
 * Test word 1 of the object behind +0x1f8 against 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE0D8(void *p)
{
    void *q = ((struct Obj24136 *)p)->f1F8;
    if (((struct Obj24137 *)q)->f4 == 3) {
        return 1;
    }
    return 0;
}


u32_021BE0EC func_021BE0EC(void *p)
{
    return ((struct Obj24138 *)p)->f30;
}


void func_021BE0F0(u8 *c)
{
    *(u32_021BE0F0 *)(c + 0x30) = 0;
}


/*
 * Field getter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
u32_021BE0F8 func_021BE0F8(void *p)
{
    return ((struct Obj24139 *)p)->f34;
}


/*
 * Set the u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE0FC(void *p, u32_021BE0FC v)
{
    ((struct Obj24140 *)p)->f34 = v;
}


int func_021BE100(void)
{
    if (sub_0202EB0C() == 1 && unit_0202EB14() == 0) {
        return 1;
    }
    return 0;
}

u32_021BE11C func_021BE11C(u8 *p)
{
    Descriptor x={0};
    Item items[2]={0};
    u32_021BE11C result;
    items[0].handle=(u32_021BE11C)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),34);
    items[1].handle=(u32_021BE11C)func_02045EC0((struct MsgBank *)(((struct Obj08262 *)p)->f1CC),35);
    items[0].value=14819;
    items[1].value=14819;
    items[0].zero=0;
    items[1].zero=0;
    x.heap=((struct Obj08262 *)p)->f0;
    x.count=2;
    x.items=items;
    x.a=24;
    x.b=6;
    x.c=8;
    x.d=3;
    x.zero=0;
    result=(u32_021BE11C)func_02027778((struct TaskMenuTmpl *)(&x),(void *)(((struct Obj08262 *)p)->f1D4));
    func_02045808((struct U16Vec *)items[0].handle);
    func_02045808((struct U16Vec *)items[1].handle);
    return result;
}


/*
 * Releases the four +0x1b8 slots and clears the two +0x1b4 bytes.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE1A4(char *p)
{
    u8 i;

    p[0x1b4] = 0;
    p[0x1b5] = 0;
    for (i = 0; i < 4; i++) {
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(u32_021BE1A4 *)(p + i * 4 + 0x1b8))), 0);
        if (((struct Obj10667 *)p)->f8 != 3) {
            func_020456F8((struct Descriptor *)(*(u32_021BE1A4 *)(p + i * 4 + 0x1b8)));
        }
    }
}

void func_021BE1E4(u8 *p)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        func_02043B5C((struct CharBuf *)((u32_021BE1E4)func_02045770((struct Descriptor *)*(u32_021BE1E4 *)(p + i * 4 + 0x1b8))), 0);
        func_02045334((struct Descriptor *)*(u32_021BE1E4 *)(p + i * 4 + 0x1b8));
    }
}

/*
 * Places a slot marker: k = idx (2 or 3 for slots 0/1 in mode 1), checks the slot with
 * func_021B8BA4 and func_021B8B8C, then sets the sprite position from the xv/yv byte tables.
 * idx is a u8 slot index (the sibling func_021BDD6C walks the same slots with a u8 i). The u8
 * parameter is what keeps the third-call idx reload after the byte copies (wD9r lane48).
 */
void func_021BE210(char *a, u8 idx)
{
    struct Pt rc;
    void *h;
    u32_021BE210 v;
    int mode;
    u32_021BE210 k;
    mode = func_021BE05C(a);
    k = idx;
    if (*(int *)(a + 8) == 3) return;
    if (mode == 1) k = (k == 0) ? 2 : 3;
    if (func_021B8BA4((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    if (func_021B8B8C((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    rc.xv = d_021C704C;
    rc.yv = d_021C7048;
    h = func_02008510(func_021B8B94((int)a, *(char **)(a + 0x1E4), idx), *(u16 *)a);
    v = (u8)func_0201D304(h, *(u32_021BE210 *)(a + 0x1C8), 0);
    func_02045808(h);
    { u32_021BE210 xk = rc.xv.b[k]; rc.x = xk + (v >> 1); }
    rc.y = rc.yv.b[k];
    func_0204B404(*(void **)(a + 0x1B0), (const struct Vec2 *)(&rc), 0);
    func_0204B3DC(*(void **)(a + 0x1B0), 1);
    func_0204B9A0(*(void **)(a + 0x1B0));
}


void func_021BE2E0(void *p)
{
    func_0204B3DC((struct Obj *)((struct Obj24141 *)p)->f1B0, 0);
}

void func_021BE2F0(u32_021BE2F0 *p, void *q)
{
    void *l = func_0200ED48((void *)func_02012EBC((struct Big *)(*(u32_021BE2F0 *)p[0x7e])));
    func_0200ED54(l, func_02008530(q));
}


/*
 * Rebuilds the +0x1dc record from the +0x1d8 source, retiring the old one first.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE318(char *a0, void *a1)
{
    if (((struct Obj05448 *)a0)->f1DC != 0)
        func_021BE34C(a0);

    ((struct Obj05448 *)a0)->f1DC =
        (u32_021BE318)func_0202EE8C(((struct Obj05448 *)a0)->f1D8, (void *)a1, 0xf, 0x10, ((struct Obj05448 *)a0)->f0);
}


void func_021BE34C(void *p)
{
    u32_021BE34C v = ((struct Obj05448 *)p)->f1DC;
    if (v != 0) {
        func_0202F038((u8 *)v);
        ((struct Obj05448 *)p)->f1DC = 0;
    }
}

int func_021BE364(struct Obj0203159C *obj,int unused,u8 *arg)
{
    u8 *p;
    if (arg && ((struct Obj24143 *)arg)->f4==3) func_0203064C(1,109,0xd0000);
    else func_0203064C(1,109,0xe8000);
    p=func_0203159C(obj,0x1fc,109);
    ((struct Obj03856 *)p)->f0=109;
    if (arg==0) {
        *(u8 * *)&((struct Obj03856 *)p)->f1F8=func_02030734(1,16,1,(const char *)d_021C724C,1357);
        **(u32_021BE364 * *)&((struct Obj03856 *)p)->f1F8=(u32_021BE364)func_020124F4(1);
        ((struct Obj24145 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=0;
        if (func_0203630C() & 0x100) ((struct Obj24146 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=1;
        if (func_0203630C() & 0x400) ((struct Obj24147 *)(*(u8 * *)&((struct Obj03856 *)p)->f1F8))->f4=2;
    } else *(u8 * *)&((struct Obj03856 *)p)->f1F8=arg;
    ((struct Obj03856 *)p)->f14=0;
    func_021BD1AC((char *)p);
    return 1;
}

int func_021BE410(void *a, void *b, int c, u32_021BE410 *p)
{
    func_021BD3B8((u8 *)p);
    if (c == 0) {
        func_020307B0((void *)p[0x7e]);
    }
    func_020315D4(a);
    func_020306F0(0x6d);
    return 1;
}

int func_021BE43C(void *a, void *b, void *c, u32_021BE43C *p)
{
    if (func_0200FB24() != 0 && p[5] == 0) {
        func_0200FB38();
        p[5] = 1;
    }
    if (func_021BD43C((char *)p) == 1) {
        return 1;
    }
    return 0;
}
