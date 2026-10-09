/*
 * file:     mb_util_msg.c
 * unit:     yes
 * function: func_021F1404, func_021F1520, func_021F15B0, func_021F1628, func_021F1704, func_021F17E0, func_021F1898, func_021F18D8, func_021F18EC, func_021F1900, func_021F1918, func_021F1930, func_021F19B8, func_021F19C8, func_021F19E4, func_021F1A24, func_021F1A2C, func_021F1A58, func_021F1AFC, func_021F1B00, func_021F1B04, func_021F1B08, func_021F1B14, func_021F1B24, func_021F1B38
 * address:  0x021F1404
 * region:   ov107
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
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02194670 0x02194670 thumb ov021
 *   d_021F6E38 0x021F6E38 data a4
 *   ov021_id 0x00000015 data
 *   func_02194798 0x02194798 thumb ov021
 *   func_02027858 0x02027858 thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020310C4 0x020310C4 arm
 *   func_02028484 0x02028484 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_02027974 0x02027974 thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194A24  0x02194A24  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02028470  0x02028470  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02194A34  0x02194A34  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02027778 0x02027778 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 */
#include "../../matched/include/Obj22302.h"
#include "../../matched/include/Obj22304.h"
#include "../../matched/include/Obj06379.h"
#include "../../matched/include/Obj13765.h"
#include "../../matched/include/Obj13766.h"
#include "../../matched/include/Obj22305.h"
#include "../../matched/include/Obj13767.h"
#include "../../matched/include/Obj22306.h"
#include "../../matched/include/Obj22307.h"
#include "../../matched/include/Obj22310.h"

#define P(k) (*(void **)(p+(k)))
#define I(k) (*(int *)(p+(k)))
struct GfFont;
struct MsgBank;
struct R;
struct Tcbl;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenu;
struct TaskMenuState;
struct U16Vec;
struct Ctx;
struct Blk;
struct Cfg;
struct CharBuf;
struct WordSet;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Work {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 pad_4[4];
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u8 pad_28[8];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3C;
    u32 f40;
    u32 f44;
    u8 pad_48[8];
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
};

struct Arg {
    u16 h;
    u32 z;
    u32 f8;
    u16 c;
    u32 n;
    u8 a;
    u8 b;
};

typedef signed int     s32_021F1404;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
} Ov107Ctx_021F1628;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    int f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28[8];
    void *f30;
    int f34;
    int f38;
    unsigned char pad3C[0x18];
    void *f54;
    int f58;
    void *f5C;
} Ov107Ctx_021F1704;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    int f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28[8];
    void *f30;
    int f34;
    int f38;
    unsigned char pad3C[0x18];
    void *f54;
    int f58;
    void *f5C;
} Ov107Ctx_021F17E0;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
    unsigned char pad14[0x40];
    void *f54;
    unsigned char pad58[4];
    void *f5C;
} Ov107Ctx_021F1898;

typedef struct {
    unsigned short f00;
    unsigned char pad02[0x22];
    void *f24;
} Ov107Ctx_021F18D8;

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx_021F18EC;

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx_021F1900;

typedef struct {void *f00;u16 f04;u32 f08;} Entry;

typedef struct {u32 f00;u8 f04;Entry *f08;u32 f0C;u8 f10,f11,f12,f13;} Config;

typedef struct {
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
} Ov107Win;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0x44];
    Ov107Win win;
    unsigned char pad4E[2];
    void *f50;
} Ov107Ctx_021F19E4;

typedef short s16;

typedef signed char s8;

typedef int s32_021F19B8;

typedef struct {
    unsigned char pad00[0x50];
    void *f50;
} Ov107Ctx_021F1A2C;

typedef struct { u8 pad00[0x30]; struct PrintSys *f30; } Context;

typedef struct {
    unsigned char pad00[0x18];
    void *f18;
} Ov107Ctx_021F1B14;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0xC];
    void *f10;
    unsigned char pad14[0x24];
    int f38;
} Ov107Ctx_021F1B24;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern unsigned func_02028590(int, int, int, unsigned);
extern int func_02034AC4(int);
extern void *func_02194670(u16 *a);
extern void func_02194798(unsigned char *a);
extern void func_02027858(struct TaskMenu *m);
extern void func_0201FEF4(u8 *o);
extern void func_0202F038(u8 *p);
extern int func_02028604(int a0);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_02045334(struct Descriptor *);
extern void func_02027974(void *);
extern s32_021F1404 func_02028484(struct Blk *blk, void *h);
extern unsigned int func_0201C4E4(struct PrintSys *ps);
extern unsigned int func_0201C6B4(const struct PrintSys *p);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void *func_02045770(struct Descriptor *p);
void func_02043B5C(struct CharBuf *buf, u8 value);
void func_02045374(struct Cfg *cfg);
void func_020409B4(u32 index);
void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
int func_02194A24(void *, void *, int);
void func_0201F73C(void *, int, int, int);
void *func_0201CCE4(void *, int, int, void *, void *, int, void *, int, int, int);
void func_02028470(u8 *p, u32 v);
void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
int func_02194A34(void *, void *);
void func_0201F7A8(void *desc, u32 kind);
struct WordSet *func_0201EC64(u32 heap);
u32 func_0201ED04(struct WordSet *p);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
void *func_0201FDA0(Ov107Win *win, int base, int pal, int pos, int heap);
u32 func_0201FEBC(u8 *p);
struct Work *func_021F1404(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021F1520(char *p);
void func_021F15B0(char *p);
void func_021F1628(Ov107Ctx_021F1628 *p, int mode);
void func_021F1704(Ov107Ctx_021F1704 *p, int a, int b);
void func_021F17E0(Ov107Ctx_021F17E0 *p, int a);
void func_021F1898(Ov107Ctx_021F1898 *p);
void func_021F18D8(Ov107Ctx_021F18D8 *p);
void func_021F18EC(Ov107Ctx_021F18EC *p);
void func_021F1900(Ov107Ctx_021F1900 *p, int a, int b, int c);
void func_021F1918(unsigned char *a,int b,int c,int d);
void func_021F1930(char *p,int kind);
void func_021F19B8(unsigned char *a);
int func_021F19C8(unsigned char *a);
void func_021F19E4(Ov107Ctx_021F19E4 *p);
void func_021F1A24(u8 *p);
int func_021F1A2C(Ov107Ctx_021F1A2C *p);
void func_021F1A58(char *p,int a);
u32 func_021F1AFC(u8 *p);
u32 func_021F1B00(u8 *p);
unsigned int func_021F1B04(unsigned char *p);
int func_021F1B08(Context *p);
int func_021F1B14(Ov107Ctx_021F1B14 *p);
void func_021F1B24(Ov107Ctx_021F1B24 *p, int x);
void func_021F1B38(u8 *p, u32 v);
extern const char d_021F6E38[];
extern u8 ov021_id[];




/*
 * 2026-10-05 (wave P8 W4): 0x15 in the pool is an overlay id (ov021_id, passed to func_02034AC4). The sixth parameter is copied to an int local g first (stored to f8, later passed to func_02028590); without the local the copy is propagated and the frame is 4 bytes short. EXACT in c99 and c.
 */
struct Work *func_021F1404(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    struct Work *w;
    struct Arg t;
    int g;

    w = (struct Work *)func_02030734(heap, 0x60, 1, d_021F6E38, 0x66);
    w->f0 = heap;
    w->f2 = a;
    w->f3 = b;
    g = e;
    w->f8 = g;
    w->f10 = 0;
    w->f14 = (u32)func_0201D7EC(0x17, 0, 0, 0, w->f0);
    w->f1C = (u32)func_02045B38(0, 2, (u16)c, w->f0);
    func_0201F5BC(a, 1, 0xD, 0, w->f0);
    if (a < 4)
        func_02049B40(0x17, 5, 0, 0x1C0, 0x20, w->f0);
    else
        func_02049B40(0x17, 5, 4, 0x1C0, 0x20, w->f0);
    func_0201DD68();
    w->fC = (u32)func_0203101C(w->f0, w->f0, 3, 0x100);
    w->f18 = 0;
    w->f20 = 0;
    w->f24 = 0;
    w->f30 = func_0201C440((void *)w->f0);
    w->f40 = (u32)func_02027F60(w->f3, 10, w->f14, w->f30, w->f0);
    w->f3C = 0;
    w->f50 = 0;
    w->f44 = func_02028590(0xF, g, 1, w->f0);
    func_02034AC4((int)ov021_id);
    if (d == 1) {
        t.h = heap;
        t.z = 0;
        t.f8 = w->f14;
        t.c = 10;
        t.n = a;
        t.a = 12;
        t.b = 14;
        w->f54 = (u32)func_02194670(&t.h);
    } else {
        w->f54 = 0;
    }
    w->f34 = 0;
    w->f38 = 0;
    w->f58 = 0;
    w->f5C = 0;
    return w;
}



void func_021F1520(char *p)
{
    if(P(0x54))func_02194798(P(0x54));
    if(P(0x3C))func_02027858(P(0x3C));
    if(P(0x50))func_0201FEF4(P(0x50));
    if(P(0x5C)){func_0202F038(P(0x5C));P(0x5C)=0;}
    func_02028604((int)P(0x44));func_02027FD8(P(0x40));func_0201C4C0(P(0x30));
    if(P(0x18))func_0201CE48(P(0x18));
    if(P(0x20))func_02045808(P(0x20));
    if(P(0x24))func_021F18EC((Ov107Ctx_021F18EC *)p);
    func_02045C04(P(0x1C));
    if(P(0x10))func_020452E8(P(0x10));
    func_0201D83C(P(0x14));func_02031140(P(0x0C));func_020307B0(p);func_02034A5C((int)ov021_id);
}



void func_021F15B0(char *p)
{
    int done;
    func_020310C4(P(12));
    if(P(0x18)){
        done=func_02028484((struct Blk *)(p+0x28),P(0x18));
        func_020286C4(P(0x44),P(0x18),P(0x10));
        if(done==1){func_0201CE48(P(0x18));P(0x18)=0;}
    }
    func_0201C4E4(P(0x30));
    if(I(0x34)==1 && func_0201C6B4(P(0x30))==1){
        func_02045334(P(0x10));I(0x34)=0;
        if(I(0x58)==1){I(0x58)=0;P(0x5C)=func_0202EE8C((u32)P(12),P(0x10),15,16,((struct Obj22302 *)p)->f0);}
    }
    if(P(0x3C))func_02027974(P(0x3C));
}




void func_021F1628(Ov107Ctx_021F1628 *p, int mode)
{
    if (p->f04 != mode) {
        if (p->f10 != 0) {
            func_020452E8(p->f10);
            p->f10 = 0;
        }
        switch (mode) {
        case 0:
            break;
        case 1:
            p->f10 = (void *)func_020450F0(p->f02, 3, 8, 0x1A, 8, 0xE, 1);
            break;
        case 2:
            p->f10 = (void *)func_020450F0(p->f02, 3, 2, 0x1A, 0x12, 0xE, 1);
            break;
        case 3:
            p->f10 = (void *)func_020450F0(p->f02, 3, 2, 0x1A, 0x14, 0xE, 1);
            break;
        case 4:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x15, 0x1E, 2, 0xE, 1);
            break;
        case 5:
        case 8:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x13, 0x1E, 4, 0xE, 1);
            break;
        case 6:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x11, 0x1E, 6, 0xE, 1);
            break;
        case 7:
            p->f10 = (void *)func_020450F0(p->f02, 1, 1, 0x1E, 4, 0xE, 1);
            break;
        }
        p->f04 = mode;
    }
    func_02043B5C(func_02045770(p->f10), 0);
    func_02045334(p->f10);
    func_02045374(p->f10);
    func_020409B4(p->f02);
}




void func_021F1704(Ov107Ctx_021F1704 *p, int a, int b)
{
    void *s;

    if (p->f18 != 0) {
        func_0201CE48(p->f18);
        p->f18 = 0;
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
    p->f38 = 0;
    p->f58 = 0;
    if (p->f20 != 0) {
        func_02045808(p->f20);
        p->f20 = 0;
    }
    func_02043B5C(func_02045770(p->f10), 0xF);
    p->f20 = func_02045EC0(p->f1C, a);
    if (p->f24 != 0) {
        s = func_020457B0(0x17B, p->f00);
        func_0201F250(p->f24, s, p->f20);
        func_02045808(p->f20);
        p->f20 = s;
    }
    p->f18 = func_0201CCE4(p->f10, 0, 0, p->f20, p->f14, b, p->f0C, 2, p->f00, 0xF);
    if (p->f04 == 8) {
        func_02194A24(p->f54, p->f10, 0);
    } else {
        func_0201F73C(p->f10, 1, 1, 0xD);
    }
    if (p->f08 == 1) {
        func_02028470(p->f28, 6);
    } else {
        func_02028470(p->f28, 4);
    }
}




void func_021F17E0(Ov107Ctx_021F17E0 *p, int a)
{
    void *s;

    if (p->f18 != 0) {
        func_0201CE48(p->f18);
        p->f18 = 0;
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
    if (p->f20 != 0) {
        func_02045808(p->f20);
        p->f20 = 0;
    }
    func_02043B5C(func_02045770(p->f10), 0xF);
    p->f20 = func_02045EC0(p->f1C, a);
    if (p->f24 != 0) {
        s = func_020457B0(0x17B, p->f00);
        func_0201F250(p->f24, s, p->f20);
        func_02045808(p->f20);
        p->f20 = s;
    }
    func_0201C6FC(p->f30, (u32)func_02045770(p->f10), 0, 0, p->f20, (u32)p->f14);
    p->f34 = 1;
    if (p->f04 == 8) {
        func_02194A24(p->f54, p->f10, 0);
        func_020409B4(p->f02);
    } else {
        func_0201F73C(p->f10, 1, 1, 0xD);
    }
}




void func_021F1898(Ov107Ctx_021F1898 *p)
{
    func_02043B5C(func_02045770(p->f10), 0);
    if (p->f04 == 8) {
        func_02194A34(p->f54, p->f10);
        func_020409B4(p->f02);
    } else {
        func_0201F7A8(p->f10, 1);
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
}




void func_021F18D8(Ov107Ctx_021F18D8 *p)
{
    if (p->f24 == 0) {
        p->f24 = func_0201EC64(p->f00);
    }
}




void func_021F18EC(Ov107Ctx_021F18EC *p)
{
    if (p->f24 != 0) {
        func_0201ED04(p->f24);
        p->f24 = 0;
    }
}




void func_021F1900(Ov107Ctx_021F1900 *p, int a, int b, int c)
{
    func_0201EFA4(p->f24, a, b, c, 0, 1);
}



/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void func_021F1918(unsigned char *a,int b,int c,int d) { func_0201EFA4(((struct Obj22304 *)a)->f24,b,c,d,2,1); }



void func_021F1930(char *p,int kind)
{
    Entry entries[2];
    Config config;
    entries[0].f00=func_02045EC0(((struct Obj06379 *)p)->f1C,18);
    entries[1].f00=func_02045EC0(((struct Obj06379 *)p)->f1C,19);
    entries[0].f04=0x39E3;entries[1].f04=0x39E3;
    entries[0].f08=0;entries[1].f08=0;
    config.f00=((struct Obj06379 *)p)->f0;config.f04=2;config.f08=entries;config.f0C=0;
    switch(kind){
    case 0:config.f10=24;config.f11=6;break;
    case 1:config.f10=24;config.f11=12;break;
    case 2:config.f10=24;config.f11=18;break;
    }
    config.f12=8;config.f13=3;
    ((struct Obj06379 *)p)->f3C=func_02027778((struct TaskMenuTmpl *)(&config),((struct Obj06379 *)p)->f40);
    func_02045808(entries[0].f00);func_02045808(entries[1].f00);
}


void func_021F19B8(unsigned char *a) { func_02027858(*(struct TaskMenu * *)&((struct Obj13765 *)a)->f3C); ((struct Obj13765 *)a)->f3C=0; }


int func_021F19C8(unsigned char *a) { if(func_020279E8(((struct Obj13766 *)a)->f3C)==1) return func_02027A04(((struct Obj13766 *)a)->f3C)+1; return 0; }



void func_021F19E4(Ov107Ctx_021F19E4 *p)
{
    p->win.f00 = p->f03;
    p->win.f01 = 0x18;
    p->win.f02 = 0xD;
    p->win.f03 = 0xE;
    p->win.f04 = 0;
    p->f50 = func_0201FDA0(&p->win, 1, 0xD, 0, p->f00);
}



void func_021F1A24(u8 *p) { ((struct Obj22305 *)p)->f50 = 0; }



int func_021F1A2C(Ov107Ctx_021F1A2C *p)
{
    int r = func_0201FEBC(p->f50);
    if (r == 0) {
        p->f50 = 0;
        return 1;
    }
    if (r == -2) {
        p->f50 = 0;
        return 2;
    }
    return 0;
}


void func_021F1A58(char *p,int a)
{
    void *s;
    s=func_02045B38(0,3,158,((struct Obj13767 *)p)->f0);
    if(P(0x18)){func_0201CE48(P(0x18));P(0x18)=0;}
    I(0x38)=0;I(0x58)=0;
    if(P(0x20)){func_02045808(P(0x20));P(0x20)=0;}
    func_02043B5C(func_02045770(P(0x10)),15);
    P(0x20)=func_02045EC0(s,22);
    P(0x18)=func_0201CCE4(P(0x10),0,0,P(0x20),P(0x14),a,P(12),2,((struct Obj13767 *)p)->f0,15);
    func_0201F73C(P(0x10),1,1,13);
    func_02045C04(s);
    if(I(8)==1)func_02028470((u8 *)(p+0x28),6);else func_02028470((u8 *)(p+0x28),4);
}



u32 func_021F1AFC(u8 *p) { return ((struct Obj22306 *)p)->f1C; }



u32 func_021F1B00(u8 *p) { return ((struct Obj22307 *)p)->f24; }


/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
unsigned int func_021F1B04(unsigned char *p)
{
    return *(unsigned int *)(p + 0x14);
}


/*
 * leaf: parent cleared original 12-byte Thumb tail getter. Full matched
 * 0201C6B4 returns only0/1 and reads its first input's pointer field10.
 */
int func_021F1B08(Context *p)
{
    return func_0201C6B4(p->f30);
}



int func_021F1B14(Ov107Ctx_021F1B14 *p)
{
    if (p->f18 == 0) {
        return 1;
    }
    return 0;
}



void func_021F1B24(Ov107Ctx_021F1B24 *p, int x)
{
    p->f38 = x;
    func_02045374(p->f10);
    func_020409B4(p->f02);
}



void func_021F1B38(u8 *p, u32 v) { ((struct Obj22310 *)p)->f58 = v; }
