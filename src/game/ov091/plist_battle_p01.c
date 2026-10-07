/*
 * file:     plist_battle_p01.c
 * unit:     yes
 * function: func_021B8DB4, func_021B8F68, func_021B8FC4, func_021B9020, func_021B907C, func_021B90F8, func_021B916C, func_021B9750, func_021B9788, func_021B97D4, func_021B9804, func_021B981C, func_021B9968, func_021B999C, func_021B99E4, func_021B9A84, func_021B9AA0, func_021B9AB4, func_021B9AC8, func_021B9BF4, func_021B9C1C
 * address:  0x021B8DB4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   func_021BB3FC  0x021BB3FC  thumb  ov091
 *   func_02035C08  0x02035C08  arm
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 *   func_021BB3D4  0x021BB3D4  thumb  ov091
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021BBBD8  0x021BBBD8  thumb  ov091
 *   func_021BBBE4  0x021BBBE4  thumb  ov091
 *   func_0207D658  0x0207D658  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_021BBBA0  0x021BBBA0  thumb  ov091
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_0207D63C  0x0207D63C  arm
 *   func_02041570  0x02041570  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021BB714 0x021BB714 thumb ov091
 *   func_021BB7E8 0x021BB7E8 thumb ov091
 *   func_021BBAF8 0x021BBAF8 thumb ov091
 *   func_021B8418 0x021B8418 thumb ov091
 *   func_021BB4A0 0x021BB4A0 thumb ov091
 *   func_021BB440 0x021BB440 thumb ov091
 *   func_021BB43C 0x021BB43C thumb ov091
 *   func_021BA394 0x021BA394 thumb ov091
 *   func_0215EA14 0x0215EA14 thumb ov010
 *   func_02013E04 0x02013E04 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021BBDEC 0x021BBDEC thumb ov091
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_021BC1B4 0x021BC1B4 thumb ov091
 *   func_021BC1D0 0x021BC1D0 thumb ov091
 *   func_021BC2C8 0x021BC2C8 thumb ov091
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021B9F34 0x021B9F34 thumb ov091
 *   func_021BA004 0x021BA004 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B8180 0x021B8180 thumb ov091
 *   func_021BC17C 0x021BC17C thumb ov091
 *   func_021BDD78 0x021BDD78 thumb ov091
 *   func_021BC350 0x021BC350 thumb ov091
 *   func_021BE2B4 0x021BE2B4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 *   func_021BDCC0 0x021BDCC0 thumb ov091
 *   func_021BDD58 0x021BDD58 thumb ov091
 *   func_021BC30C 0x021BC30C thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BB9BC 0x021BB9BC thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021BA5B4 0x021BA5B4 thumb ov091
 *   func_021BA60C 0x021BA60C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 *   func_021BA098 0x021BA098 thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_021BB8FC 0x021BB8FC thumb ov091
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021BB860  0x021BB860  thumb  ov091
 *   func_021BBB40  0x021BBB40  thumb  ov091
 *   func_021BB1A0 0x021BB1A0 thumb ov091
 *   func_021BB0C4 0x021BB0C4 thumb ov091
 *   func_0201AB8C 0x0201AB8C thumb
 *   func_0202130C 0x0202130C thumb
 *   func_020188AC 0x020188AC thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 */
#include "../../matched/include/Obj09925.h"
#include "../../matched/include/Obj01229.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20860.h"
#include "../../matched/include/Obj20861.h"
#include "../../matched/include/Obj20862.h"
#include "../../matched/include/Obj13241.h"

#define reg_G2_WIN0H  (*(volatile u16 *)0x04000040)
#define reg_G2_WIN0V  (*(volatile u16 *)0x04000044)
#define reg_G2_WININ  (*(volatile u16 *)0x04000048)
#define reg_G2_WINOUT (*(volatile u16 *)0x0400004A)
#define reg_G2_BLDCNT (*(volatile u16 *)0x04000050)
#define S (*(u8 **)(p+0x280))
#define H(k) (*(u16 *)(S+(k)))
#define T(k) (*(u32 *)(S+(k)))
#define A (*(int **)((p+W(0x2c)*4)+0x160))
#define ROW(i) (*(u8 **)(p + (i) * 4 + 0x160))
struct Obj;
struct Vec2;
struct Sub02008F80Obj;
struct Party;
struct MsgBank;
struct U16Vec;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Rect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} Rect;

typedef struct Rect4 {
    Rect r[4];
} Rect4;

typedef int BOOL;

typedef struct { int v[4]; } Four;

typedef short s16;

extern int func_021BB3C4(void *unused, u32 p);
extern void func_021BB3FC(int unused, u8 *s, u8 *out);
extern int func_02035C08(const void *p);
extern int func_021BB468(int unused, int *p);
extern void func_020061E4(u32 id);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
extern void func_021BBE5C(int h, int f);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021BB3D4(void *a, u8 *s, u16 *out);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BBBD8(int unused, int *q);
extern unsigned int func_021BBBE4(int a, unsigned char *b);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02041B6C(u32 bit);
extern void func_020355D8(int a);
extern void func_021BBBA0(unsigned char *a, unsigned char *b);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_0207D63C(u16 *r, int a, int b, int c, int d);
extern void func_02041570(int channel, u16 val);
extern u8 func_020355C4(void);
extern void func_020409B4(u32 index);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void func_021B8180(u8 *);
extern int func_021BC17C(unsigned short *p, int id);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BC350(u8 *,int);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB200(u8 *a, u8 *s, int p, int q);
extern void func_021BB2C0(u8 *a, u8 *s);
extern u32 func_021BA670(u8 *p, u16 id);
extern int func_021BDCC0(char *p, u32 a1);
extern void func_021BDD58(u32 p, void *m);
extern void func_021BC30C(int p);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021BB9BC(int a, u32 b, u32 c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(char *p);
extern void func_021BDC3C(u32 p, void *m);
extern u32 func_021BA5B4(u8 *p, void *q);
extern void func_021BA60C(u8 *p, void *q);
extern void func_021B9E3C(char *p);
extern void func_021BA4E4(u8 *p);
extern void func_021BA098(u8 *p);
extern void func_021B9EB0(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
extern void func_021B7B98(u8 *);
extern int func_021BC1B4(unsigned short *p, void *id);
extern int func_021BC1D0(u8 *);
extern void func_021BC2C8(int p);
extern u32 func_021BA65C(u8 *p, u16 id);
extern int func_021BDC5C(u8 *,u32);
extern void func_021BDCA0(u32 p, void *m);
extern void func_021B9F34(u8 *p);
extern void func_021BA004(u8 *p);
extern void func_021B9E20(u8 *p);
extern void func_021BB714(void *,u32 *,u32);
extern void func_021BB7E8(u8 *,u32 *,u32);
extern void func_021BBAF8(u8 *,u8 *,int *);
extern void func_021B8418(u8 *);
extern int func_021BB4A0(u8 *,int *);
extern void func_021BB440(u8 *p, u32 *q, int v);
extern int func_021BB43C(int *);
extern void func_021BA394(u8 *p);
extern int func_0215EA14(int a0, int a1);
extern u32 func_02013E04(u32 id);
extern int func_021BB8FC(void *unused, u32 p);
extern unsigned func_020362DC(void);
extern int func_02035C60(void);
extern void func_021BB860(u8 *a, u32 *s, u32 x, u32 y);
extern void func_021BBB40(u8 *a, u8 *b);
extern void func_021BB1A0(int, u8 *, int);
extern void func_021BB0C4(u8 *p, const u8 *s, int d);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern u32 func_0201B2B0(void *,void *,u32,u32,u8,u32 *,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
void func_021B8DB4(u8 *p);
void func_021B8F68(u8 *p, int idx);
void func_021B8FC4(u8 *p, int idx);
void func_021B9020(u8 *p);
void func_021B907C(u8 *p);
void func_021B90F8(u8 *p);
void func_021B916C(u8 *p);
void func_021B9750(unsigned p);
void func_021B9788(u8 *p, int a1, int a2, int a3);
void func_021B97D4(u8 *p);
void func_021B9804(u8 *p, int a1);
void func_021B981C(u8 *p);
void func_021B9968(unsigned char *p);
void func_021B999C(u8 *p);
int func_021B99E4(void *p, int i);
int func_021B9A84(u32 p);
int func_021B9AA0(u32 p);
int func_021B9AB4(u8 *p);
int func_021B9AC8(u8 *p, void *mon, u8 bit);
u32 func_021B9BF4(u8 *p, void *mon, u32 param);
void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
extern Rect4 d_021BEC2C;
extern const Four d_021BEC0C,d_021BEC1C;


#define W(o) (*(int *)(p + (o)))


void func_021B8DB4(u8 *p)
{
    Rect list[7];
    Rect4 fixed;
    u8 map[6];
    u8 i;
    u8 n;
    int hit;
    int old;
    int r;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (func_021BB3C4(p, *(int *)(p + i * 4 + 0x160)) == 1) {
            map[n] = i;
            func_021BB3FC((int)p, (u8 *)(*(int *)(p + i * 4 + 0x160)), (u8 *)(&list[n]));
            n++;
        }
    }
    list[n].top = 0xff;
    hit = func_02035C08(list);
    if (hit != -1) {
        if (W(0x28) == 0 && hit <= 5 && func_021BB468((int)p, (int *)(*(int *)(p + hit * 4 + 0x160))) == 1) {
            func_020061E4(0x557);
        } else {
            p[0xf] = 3;
            old = W(0x2c);
            W(0x2c) = map[hit];
            if (old <= 5) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
            }
            if (W(0x2c) <= 5) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC((struct Obj *)W(0x1d8), 0);
            }
            p[0x100] = 0xc;
        }
        W(8) = 1;
    }
    if (hit == -1) {
        fixed = d_021BEC2C;
        if (func_021B9A84((u32)p) == 1) {
            if (func_021B9AA0((u32)p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xb0;
                fixed.r[1].right = 0xff;
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0x60;
                fixed.r[0].right = 0xb0;
            } else {
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0xb0;
                fixed.r[0].right = 0xff;
            }
        } else {
            if (func_021B9AB4(p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xe0;
                fixed.r[1].right = 0xf8;
            }
            if (W(0x14) == 1) {
                fixed.r[2].top = 0xa8;
                fixed.r[2].bottom = 0xc0;
                fixed.r[2].left = 0xc8;
                fixed.r[2].right = 0xe0;
            }
        }
        r = func_02035C08(&fixed);
        if (r != -1) {
            p[0xf] = r;
            W(8) = 1;
        }
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B8F68(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1d8), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1d8), 1);
    func_0204B84C(W(0x1d8), 3);
    if (idx == 0) {
        func_0204B878((struct Obj *)W(0x1d8), 0);
    } else {
        func_0204B878((struct Obj *)W(0x1d8), 1);
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B8FC4(u8 *p, int idx)
{
    int buf;

    func_021BB3D4(p, (u8 *)(*(int *)(p + idx * 4 + 0x160)), (u16 *)(&buf));
    func_0204B404((struct Obj *)W(0x1dc), (const struct Vec2 *)(&buf), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 1);
    func_0204B84C(W(0x1dc), 2);
    if (idx == 0) {
        func_0204B878((struct Obj *)W(0x1dc), 2);
    } else {
        func_0204B878((struct Obj *)W(0x1dc), 3);
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B9020(u8 *p)
{
    int r;

    switch (p[0xe]) {
    case 0:
        func_021B907C(p);
        p[0xe] = 1;
        break;
    case 1:
        func_021BBBD8((int)p, (int *)W(0x154));
        r = func_021BBBE4((int)p, (unsigned char *)((int *)W(0x154)));
        if (r != 0x17) {
            W(0x3c) = r;
            p[0xe] = 2;
        }
        if (*(u8 *)(W(0x280) + 0x63) == 1) {
            p[0xe] = 2;
        }
        break;
    case 2:
        func_021B90F8(p);
        func_021B916C(p);
        break;
    }
}


static inline void G2_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2_BLDCNT, plane, brightness);
}


static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    reg_G2_WIN0H = (u16)(((x1 << 8) & 0xff00) | ((x2 << 0) & 0x00ff));
    reg_G2_WIN0V = (u16)(((y1 << 8) & 0xff00) | ((y2 << 0) & 0x00ff));
}


static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WININ = (u16)tmp;
}


static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WINOUT = (u16)tmp;
}

#undef W

#define W(o) (*(int *)(p + (o)))


/*
 * volatile: WININ 0x04000048 and WINOUT 0x0400004A read-modify-written by the SDK inlines G2_SetWnd0InsidePlane/G2_SetWndOutsidePlane; WIN0H/WIN0V/BLDCNT hardware registers
 */
void func_021B907C(u8 *p)
{
    p[0xc] = 6;
    p[0xe] = 0;
    G2_SetBlendBrightness(0x1e, 8);
    G2_SetWnd0Position(0xe0, 0xa8, 0xf8, 0xc0);
    G2_SetWnd0InsidePlane(0x1f, 0);
    G2_SetWndOutsidePlane(0x1f, 1);
    W(0x10) = 1;
    func_0204B3DC((struct Obj *)W(0x1e4), 0);
    func_0204B3DC((struct Obj *)W(0x1e0), 0);
    func_02041B6C(0);
    func_020355D8(W(8));
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B90F8(u8 *p)
{
    func_021BBBA0((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    func_021BB7A4(p, (u32 *)W(0x150));
    if (func_021B9A84((u32)p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
    if (W(0x3c) != 4 && W(0x3c) != 5) {
        func_0207D63C((u16 *)0x04000050, 0x14, 8, 0x10, 0xa);
        W(0x10) = 0;
    }
    func_02041570(0, 0);
    W(8) = func_020355C4();
}

#undef W
#define W(k) (*(u32 *)(p+(k)))

void func_021B916C(u8 *p)
{
    struct { u32 n; Four b; Four a; } L;
    u32 old;
    int r,level;
    u32 flag;
    u8 i;
    u8 *q;
    if (S[0x63] == 1) { p[0xc]=19; return; }
    switch (W(0x3c)) {
    case 6:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 3:
        func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c));
        W(0x30)=W(0x2c); p[0xc]=3; W(0x38)=0; W(0x14)=0;
        func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),11);
        func_021B8418(p); return;
    case 4:
        L.a=d_021BEC0C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.a.v); func_020409B4(0); return;
    case 5:
        L.b=d_021BEC1C;
        func_021B907C(p); func_021BB714(p,(u32 *)W(0x150),2);
        func_021BB7E8(p,(u32 *)W(0x150),19);
        func_021BBAF8(p,(u8 *)W(0x154),L.b.v); func_020409B4(0); return;
    case 0:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=1; return;
    case 20:
        q=(u8 *)T(0x14); flag=0;
        r=func_021BB4A0(p,A);
        if (r == 0) {
            func_021BB440(p,(u32 *)A,p[0x105]); p[0x105]=p[0x105]+1;
            func_021B7B98(p);
            if (p[0x105] == q[3]) flag=1;
            p[0xc]=2;
        } else if (r == 2) {
            func_021B9788(p,0x90,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 3) {
            func_021B9788(p,0x91,1,(int)func_021B9E20); func_020061E4(0x557);
        } else if (r == 4) {
            func_021B9788(p,q[3]+0x5c,1,(int)func_021B9E20); func_020061E4(0x557);
        }
        W(0x38)=0;
        if (flag==1) {
            func_021BAFA0(p,(u8 *)((u32)A),0); W(0x2c)=6;
            if (W(8)==0) {
                func_021BBE5C(*(int *)((p+(u8)(W(0x2c)-6)*4)+0x108),1);
                func_0204B3DC((struct Obj *)W(0x1d8),0); return;
            }
        } else if (W(8)==0) func_021B8F68(p,W(0x2c));
        return;
    case 21:
        level=func_021BB43C(A);
        for (i=0; i<6; i++) {
            r=func_021BB43C(*(int **)((p+i*4)+0x160));
            if (r <= 5 && r > level) func_021BB440(p,(u32 *)(*(int **)((p+i*4)+0x160)),r-1);
        }
        func_021BB440(p,(u32 *)A,6); p[0x105]=p[0x105]-1;
        if (W(8)==0) func_021B8F68(p,W(0x2c));
        W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    case 10:
        old=func_02017E1C((void *)W(0x38),6,0);
        func_021BC24C(p,(void *)W(0x38),0); func_021BC288((int)p,(int)((void *)W(0x38)),0);
        if (old==0) {
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021B9788(p,0x3d,1,(int)func_021B9E20); func_021BB98C(p,W(0x150)); return;
        }
        if (func_021BA65C(p,old)==999) {
            func_021B9788(p,0x3f,1,(int)func_021B9E20); return;
        }
        func_021BA624(p,(void *)W(0x38),0); func_021BB2C0(p,(u8 *)((u32)A));
        func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
        if (func_021BDC5C(p,W(0x38))==1) {
            func_021BDCA0((u32)p,(void *)W(0x38)); func_021B9788(p,0x3e,1,(int)func_021BA4E4); W(0x264)=2;
        } else func_021B9788(p,0x3e,1,(int)func_021B9E20);
        func_021BB98C(p,W(0x150)); return;
    case 11:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 9:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=3; return;
    case 12:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=7; return;
    case 13:
        func_021B9788(p,0x17,0,(int)func_021BA394); return;
    case 7:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 16: case 17: case 18: case 19:
        if (T(0x34)==5) {
            if (func_021BDD78((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),*(u16 *)p)==1) {
                old=func_02017E1C((void *)W(0x38),W(0x3c)+0x26,0);
                func_020409B4(0); func_021BC350(p,old);
                func_021BE2B4((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),H(0x30),*(u16 *)p);
                func_021BB2C0(p,(u8 *)((u32)A)); func_021BA670(p,H(0x44)); func_020061E4(0x56f);
            } else func_021BC30C((int)p);
            return;
        }
        r=func_021B99E4((void *)W(0x38),(u8)(W(0x3c)-16));
        if ((u32)(r-22)<=1) {
            if (func_02013E04(H(0x30))==0) {
                func_021B9788(p,0x50,1,(int)func_021B9E20); return;
            }
            L.n=func_02017E1C((void *)W(0x38),0xa1,0);
            old=func_02017E1C((void *)W(0x38),0xa0,0);
            if (old > L.n/5) {
                func_021B8F68(p,W(0x2c)); func_021B8FC4(p,W(0x2c)); W(0x34)=W(0x2c);
                p[0xc]=4; W(0x38)=0; W(0x14)=0;
                func_021BB714(p,(u32 *)W(0x150),0); func_021BB7E8(p,(u32 *)W(0x150),17);
                func_021B8418(p);
            } else func_021B9788(p,0x6b,1,(int)func_021B9E20);
            return;
        }
        switch (func_0215EA14(r-11,(int)(S+0x1c))) {
        case 0: p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=r; return;
        case 1: func_021B9788(p,0x50,1,(int)func_021B9E20); return;
        case 2: func_021B9788(p,0x38,1,(int)func_021B9E20); return;
        case 3: func_021B9788(p,0x9f,1,(int)func_021B9E20); return;
        case 4: func_021B9788(p,0x4f,1,(int)func_021B9E20); return;
        }
        return;
    default:
        func_021B8F68(p,W(0x2c)); W(0x38)=0; p[0xc]=2; func_021B7B98(p); return;
    }
}

void func_021B9750(unsigned p) { if(func_021BB8FC((void *)p,((struct Obj09925 *)p)->f150)==1) { if(func_020362DC()&1) ((struct Obj09925 *)p)->f8=0; if(func_02035C60()==1) ((struct Obj09925 *)p)->f8=1; (*(void (**)(unsigned))(p+328))(p); } }

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B9788(u8 *p, int a1, int a2, int a3)
{
    p[0xc] = 7;
    W(0x144) = a2;
    W(0x148) = a3;
    func_021BB714(p, (u32 *)W(0x150), 3);
    func_021BB860(p, (u32 *)W(0x150), a1, a2);
    func_0204B3DC((struct Obj *)W(0x1e0), 0);
    func_0204B3DC((struct Obj *)W(0x1e4), 0);
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B97D4(u8 *p)
{
    int r;

    func_021BBBD8((int)p, (int *)W(0x154));
    r = func_021BBBE4((int)p, (unsigned char *)((int *)W(0x154)));
    if (r != 0x17) {
        ((void (*)(u8 *, int))W(0x14c))(p, r);
        func_021BBBA0((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    }
}


/*
 * func_021B9804 is an unlabelled tail-call stub inside the extent.
 */
void func_021B9804(u8 *p, int a1)
{
    p[0xc] = 9;
    W(0x14c) = a1;
    func_021BBB40(p, (u8 *)W(0x154));
}

#undef W
#define W(o) (*(int *)(p + (o)))

void func_021B981C(u8 *p)
{
    switch (p[0xe]) {
    case 3:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]++;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] >= 16) {
            func_0201AB8C((struct Party *)(*(int *)W(0x280)), W(0x2c), W(0x30), ((struct Obj01229 *)p)->f0);
            func_021BB200(p, ROW(W(0x2c)), (int)func_0201AB28(*(void **)W(0x280), W(0x2c)), p[0x104]);
            func_021BB200(p, ROW(W(0x30)), (int)func_0201AB28(*(void **)W(0x280), W(0x30)), p[0x104]);
            p[0xe] = 4;
            func_020061E4(0x642);
        }
        break;
    case 4:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]--;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] == 0)
            func_021B999C(p);
        break;
    }
}

void func_021B9968(unsigned char *p) { p[12]=5; p[14]=3; p[260]=0; func_020061E4(0x641); func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1D8,0); func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1DC,0); }

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B999C(u8 *p)
{
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x30) = 9;
    *(int *)(W(0x280) + 0x3c) = W(0x2c);
    func_021B7B98(p);
}


int func_021B99E4(void *p, int i)
{
    switch (func_02017E1C(p, i + 0x36, 0)) {
    case 0xf:
        return 0xb;
    case 0x13:
        return 0xf;
    case 0x39:
        return 0xc;
    case 0x46:
        return 0xe;
    case 0x7f:
        return 0xd;
    case 0x94:
        return 0x10;
    case 0x64:
        return 0x11;
    case 0x5b:
        return 0x12;
    case 0xe6:
        return 0x13;
    case 0x1c0:
        return 0x14;
    case 0x123:
        return 0x15;
    case 0xd0:
        return 0x16;
    case 0x87:
        return 0x17;
    }
    return 0;
}

int func_021B9A84(u32 p) {
    u32 v = *(u32 *)(((struct Obj20860 *)p)->f280 + 52);
    if (v == 1 || v == 22 || v == 23) return 1;
    return 0;
}

int func_021B9AA0(u32 p) {
    if (*(u32 *)(((struct Obj20861 *)p)->f280 + 52) != 1) return 1;
    return 0;
}

int func_021B9AB4(u8 *p) { return ((struct Obj20862 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34 != 21; }

int func_021B9AC8(u8 *p, void *mon, u8 bit)
{
    int empty = 0;
    u8 i;
    u32 a, b, c;
    u32 v;
    if (*(int *)(p + 0x18) == 1) {
        a = *(u16 *)(*(u8 **)(p + 0x280) + 0x46);
        if (a == 0xfffe) {
            a = 0x152;
            b = a - 0x1f;
            c = a - 0x1e;
        } else if (a == 0xfffd) {
            a = 0x280;
            a = a - 0x78;
            b = 0x280;
            b = b - 0x79;
            c = 0x280 - 0x7a;
        } else {
            b = a;
            c = a;
        }
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == a || v == b || v == c) return 3;
            if (v == 0) empty = 1;
        }
        if ((*(u8 *)(*(u8 **)(p + 0x280) + 0x5e) & (1 << bit)) != 0) {
            if (empty == 1) return 0;
            return 1;
        } else return 2;
    } else {
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == *(u16 *)(*(u8 **)(p + 0x280) + 0x46)) return 3;
            if (v == 0) empty = 1;
        }
        if (*(u16 *)(*(u8 **)(p + 0x280) + 0x44) != 0) {
            u32 id = func_0202130C(*(u16 *)(*(u8 **)(p + 0x280) + 0x44));
            if (id != 0xff && func_020188AC(mon, id) == 1) {
                int result = 0;
                if (empty != 1) result = 1;
                return result;
            } else return 2;
        } else {
            int result = 0;
            if (empty != 1) result = 1;
            return result;
        }
    }
}

u32 func_021B9BF4(u8 *p, void *mon, u32 param) { u8 *s=*(u8 * *)&((struct Obj00009 *)p)->f280; return func_0201B2B0(((struct Obj13241 *)s)->f0,mon,3,param,s[0x5f],0,((struct Obj00009 *)p)->f0); }

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color)
{
    void *text;

    text = func_02045EC0((void *)W(0x134), id);
    func_0201C724((void *)W(0x140), (u32)func_02045770((struct Descriptor *)win), (s16)x, (s16)y, (u32)text, W(0x138), color);
    func_02045808(text);
}
