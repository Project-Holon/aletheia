/*
 * file:     mb_util_msg_p01.c
 * unit:     yes
 * function: func_021F1404, func_021F1520, func_021F15B0, func_021F1628, func_021F1704, func_021F17E0
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
 *   func_021F18EC 0x021F18EC thumb ov107
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
 */
#include "../../matched/include/Obj22302.h"

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

typedef signed int     s32;

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
extern void func_021F18EC(void *);
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
extern s32 func_02028484(struct Blk *blk, void *h);
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
struct Work *func_021F1404(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021F1520(char *p);
void func_021F15B0(char *p);
void func_021F1628(Ov107Ctx_021F1628 *p, int mode);
void func_021F1704(Ov107Ctx_021F1704 *p, int a, int b);
void func_021F17E0(Ov107Ctx_021F17E0 *p, int a);
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
    if(P(0x24))func_021F18EC(p);
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
