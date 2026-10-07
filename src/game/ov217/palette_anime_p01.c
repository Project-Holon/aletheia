/*
 * file:     palette_anime_p01.c
 * unit:     yes
 * function: func_021C0EF4, func_021C0F48, func_021C0F5C, func_021C0F78, func_021C0FF8, func_021C1038, func_021C1090, func_021C10C8, func_021C10D8, func_021C10E8, func_021C1124, func_021C112C, func_021C1154, func_021C1160, func_021C116C, func_021C1178, func_021C1184, func_021C118C, func_021C1194
 * address:  0x021C0EF4
 * region:   ov217
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
 *   func_020450F0 0x020450F0 arm
 *   d_021C4058 0x021C4058 data a1
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045798 0x02045798 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_020413B0 0x020413B0 arm
 *   _fflt  0x0209BDBC  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_021C1D64  0x021C1D64  thumb  ov217
 *   func_021C1DBC  0x021C1DBC  thumb  ov217
 *   func_021C1D74  0x021C1D74  thumb  ov217
 *   func_021C1DE8  0x021C1DE8  thumb  ov217
 *   func_021C1704  0x021C1704  thumb  ov217
 *   func_021C1720  0x021C1720  thumb  ov217
 *   func_021C17C4  0x021C17C4  thumb  ov217
 *   func_021C1850  0x021C1850  thumb  ov217
 *   func_021C18C4  0x021C18C4  thumb  ov217
 *   func_021C18F8  0x021C18F8  thumb  ov217
 *   func_021C15B8  0x021C15B8  thumb  ov217
 *   func_021C124C  0x021C124C  thumb  ov217
 *   func_021C13E8  0x021C13E8  thumb  ov217
 *   func_021C14DC  0x021C14DC  thumb  ov217
 *   func_021C1D24  0x021C1D24  thumb  ov217
 *   func_021C16DC  0x021C16DC  thumb  ov217
 *   func_021C1A58  0x021C1A58  thumb  ov217
 *   func_021C1A5C  0x021C1A5C  thumb  ov217
 *   func_021C1A64  0x021C1A64  thumb  ov217
 */
#include "../../matched/include/Obj26004.h"
#include "../../matched/include/Obj26005.h"
#include "../../matched/include/Obj06716.h"
#include "../../matched/include/Obj03954.h"
#include "../../matched/include/Obj14757.h"
#include "../../matched/include/Obj26006.h"

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct Cfg;
struct CharBuf;
struct StrObj;
struct Big;
struct Pos;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Config { u8 a,b,c,d,e,f,g,h; u32 i,j; };

struct Record { struct Config config; u32 a,b,handle,active; };

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *w, s16 x, s16 y, void *text, void *font, u16 color);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);
extern void func_020456F8(struct Descriptor *);
extern void func_02045798(struct Descriptor *,u8);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern u8 func_02045748(struct Descriptor *);
extern u8 func_02045750(struct Descriptor *);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_021C1D64(u32);
extern u32 func_021C1DBC(u32);
extern void func_021C1D74(u32);
extern u32 func_021C1DE8(void *a0);
extern u32 func_021C1704(void *a0);
extern void func_021C1720(u8 *p, u8 *e);
extern void func_021C17C4(u8 *p);
extern void func_021C1850(u8 *p);
extern void func_021C18C4(u8 *p);
extern void func_021C18F8(u8 *p);
extern void func_021C15B8(u8 *p);
extern void func_021C124C(u8 *p);
extern void func_021C13E8(struct Big *p);
extern void func_021C14DC(u8 *p);
extern u32 func_021C1D24(void *);
extern void func_021C16DC(u32 *p, u32 a1);
extern void func_021C1A58(void *h, u32 v);
extern void func_021C1A5C(void *h, u32 v);
extern void func_021C1A64(u8 *p, const struct Pos *v);
struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
void func_021C0F48(u8 *p);
u32 func_021C0F5C(u32 a0, u32 a1);
void func_021C0F78(u8 *p, struct U16Vec *text);
void func_021C0FF8(u8 *p,int visible);
void func_021C1038(u8 *p,u8 palette);
int func_021C1090(u8 *p, void *a1);
u32 func_021C10C8(u32 a0);
u32 func_021C10D8(void *a0);
void func_021C10E8(u8 *p, u8 *tab, int n);
void func_021C1124(u8 *p);
void func_021C112C(u8 *p);
void func_021C1154(u8 *h);
void func_021C1160(u8 *h);
void func_021C116C(u8 *h);
void func_021C1178(u8 *h);
void func_021C1184(u8 *h, u32 v);
void func_021C118C(u8 *h, u32 v);
void func_021C1194(u8 *p, struct Pos *v);
extern const char d_021C4058[];

struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap)
{
    struct Record *p = func_02030734(heap,32,0,d_021C4058,55);
    p->config = *config;
    p->a=a;
    p->b=b;
    p->handle=func_020450F0(config->a,config->b,config->c,config->d,config->e,config->h,0);
    p->active=1;
    return p;
}

/*
 * Two-call wrapper: field +0x18, then the object itself.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0F48(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj26004 *)p)->f18));
    func_020307B0(p);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0F5C(u32 a0, u32 a1)
{
    u32 v1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj26005 *)(((u8*)a0)))->f14), a1);
    func_021C0F78((u8 *)a0, (void *)v1);
    return func_020307B0((void *)v1);
}


/*
 * y = p[6] written in both arms of the x if/else: the join value has no known range, so the s16 argument is sign-extended (lsls/asrs) as in the original.
 */
void func_021C0F78(u8 *p, struct U16Vec *text)
{
    u16 color;
    void *w;
    int x;
    int y;
    void *font;
    void *obj;
    color = ((p[8] & 31) << 10) | ((p[9] & 31) << 5) | (p[10] & 31);
    w = func_02045770(*(void **)(p + 0x18));
    func_02043B5C(w, p[10]);
    if (*(int *)(p + 0xC) != 0) {
        x = p[5] + func_021C1090(p, text);
        y = p[6];
    } else {
        x = p[5];
        y = p[6];
    }
    font = *(void **)(p + 0x10);
    func_0201C7D0(w, x, y, text, font, color);
    if (*(int *)(p + 0x1C) != 0) {
        obj = *(void **)(p + 0x18);
        func_02045334(obj);
        func_02045374(obj);
        func_02041B6C(func_02045730(obj));
    }
}

/*
 * tail: two zero padding bytes at 0x021C1036, not a follower.
 */
void func_021C0FF8(u8 *p,int visible)
{
    if (((struct Obj06716 *)p)->f1C==0 && visible!=0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_02045334(d);
        func_02045374((struct Cfg *)d);
        func_02041B6C(func_02045730(d));
    } else if (((struct Obj06716 *)p)->f1C!=0 && visible==0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_020456F8(d);
        func_02041B6C(func_02045730(d));
    }
    ((struct Obj06716 *)p)->f1C=visible;
}

void func_021C1038(u8 *p,u8 palette)
{
    u32 layer;
    u8 x,y,width,height;
    func_02045798(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18,palette);
    layer=func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    x=func_02045758(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    y=func_02045760(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    width=func_02045748(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    height=func_02045750(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    func_020413B0(layer,x,y,width,height,palette);
    if (((struct Obj03954 *)p)->f1C!=0) func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18));
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C1090(u8 *p, void *a1)
{
    int r;
    int x;
    x = func_02045738((struct Descriptor *)(((struct Obj14757 *)p)->f18)) * 8;
    x = x - func_0201D304((struct StrObj *)a1, ((struct Obj14757 *)p)->f10, 0);
    r = (int)(0.5f * (float)x);
    if (r < 0) {
        r = 0;
    }
    return r;
}

u32 func_021C10C8(u32 a0)
{
    u32 v1 = func_021C1DBC(a0);
    func_021C1D64(v1);
    return v1;
}

u32 func_021C10D8(void *a0)
{
    func_021C1D74((u32)a0);
    return func_021C1DE8(a0);
}


void func_021C10E8(u8 *p, u8 *tab, int n)
{
    int i;
    func_021C1704((void *)p);
    for (i = 0; i < n; i++)
        func_021C1720(p, tab + i * 16);
    func_021C17C4(p);
    func_021C1850(p);
    func_021C18C4(p);
    func_021C18F8(p);
}


/*
 * Tail-call veneer: branch to func_021C15B8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1124(u8 *p)
{
    func_021C15B8(p);
}

/*
 * When func_021C1D24() reports 1 and the +8 field is set, runs the
 * +0x3C update triplet.
 *
 * Addresses are Black-image addresses.
 */
void func_021C112C(u8 *p)
{
    if (func_021C1D24(p) == 1) {
    if (((struct Obj26006 *)p)->f8 != 0) {
    func_021C14DC(p);
    func_021C124C(p);
    func_021C13E8((struct Big *)p);
    }
    }
}


void func_021C1154(u8 *h)
{
    func_021C16DC((u32 *)h, 1);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 2 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1160(u8 *h)
{
    func_021C16DC((u32 *)h, 2);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 3 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C116C(u8 *h)
{
    func_021C16DC((u32 *)h, 3);
}


/*
 * Tail-call veneer: forwards arg(s) a0, 5 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1178(u8 *h)
{
    func_021C16DC((u32 *)h, 5);
}


void func_021C1184(u8 *h, u32 v)
{
    func_021C1A58(h, v);
}


/*
 * Tail-call veneer: branch to func_021C1A5C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C118C(u8 *h, u32 v)
{
    func_021C1A5C(h, v);
}

void func_021C1194(u8 *p, struct Pos *v)
{
    func_021C1A64(p, v);
    func_021C18F8(p);
}
