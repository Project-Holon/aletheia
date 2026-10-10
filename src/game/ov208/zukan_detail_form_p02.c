/*
 * file:     zukan_detail_form_p02.c
 * unit:     yes
 * function: func_021C5F34, func_021C625C, func_021C66C8, func_021C6760, func_021C68D4, func_021C692C, func_021C6A10, func_021C6AFC, func_021C6BB4, func_021C6C00, func_021C6D10, func_021C6D6C, func_021C6DD8, func_021C6E30
 * address:  0x021C5F34
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
 *   func_021BC3A4  0x021BC3A4  thumb
 *   func_021BC3B4  0x021BC3B4  thumb
 *   func_021BC3B8  0x021BC3B8  thumb
 *   func_021BC3BC  0x021BC3BC  thumb
 *   func_021C5200  0x021C5200  thumb
 *   func_021BDC48  0x021BDC48  thumb
 *   func_021BDBAC  0x021BDBAC  thumb
 *   func_021C80AC  0x021C80AC  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021BDAAC  0x021BDAAC  thumb
 *   func_021BDBEC  0x021BDBEC  thumb
 *   func_021BE82C  0x021BE82C  thumb
 *   func_021BDBA0  0x021BDBA0  thumb
 *   func_021C50F8  0x021C50F8  thumb
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021BDC14  0x021BDC14  thumb
 *   func_021C7534  0x021C7534  thumb
 *   func_021C4F30  0x021C4F30  thumb
 *   func_021C4EAC  0x021C4EAC  thumb
 *   func_021C6AFC  0x021C6AFC  thumb
 *   func_021C68D4  0x021C68D4  thumb
 *   data_021C87A0  0x021C87A0  data
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   ov208_func_021BDC48 0x021BDC48 thumb ov208
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B404        0x0204B404  arm
 *   func_02035CB8  0x02035CB8  arm
 *   ov208_func_021C6E60  0x021C6E60  thumb
 *   ov208_func_021C5C64  0x021C5C64  thumb
 */
#include "../../matched/include/Obj00124.h"
#include "../../matched/include/Obj03367.h"
#include "../../matched/include/Obj03368.h"
#include "../../matched/include/Obj05545.h"
#include "../../matched/include/Obj02258.h"
#include "../../matched/include/Obj01979.h"
#include "../../matched/include/Obj25526.h"

#define FALSE 0
#define TRUE 1
#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define RES(k) (*(u32 *)(p + (k) * 4 + 0x5c0))
#define F32(b, o) (*(u32 *)((b) + (o)))
#define ST(i) (*(u32 *)(p + (i) * 0x28 + 0x614))
#define OBJ(i) (*(u32 *)(p + (i) * 0x28 + 0x618))
#define STB(i) (*(u32 *)(p + 0x614 + (i) * 0x28))
#define OBJB(i) (*(u32 *)(p + 0x618 + (i) * 0x28))
#define B8(i) (*(p + (i) * 0x28 + 0x608))
struct Obj;
struct Actor;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef enum { SIDE_0 = 0, SIDE_1 = 1 } Side;

typedef short          s16_021C5F34;

struct Ov208CellHdr {
    s16_021C5F34 x;
    s16_021C5F34 y;
    s16_021C5F34 z;
    u8  a;
    u8  b;
};

typedef signed int     s32;

typedef signed short   s16_021C66C8;

typedef struct {
    s16_021C66C8 x;
    s16_021C66C8 y;
} Ov208Pos;

struct Ov208Cursor {
    u8  slot;
    u8  pad;
    s16_021C66C8 x;
    s16_021C66C8 y;
};

extern int func_021BC3A4(int *p);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern u16  func_021BC3BC(char *p);
extern void func_021C5200(int *p);
extern void func_021BDC48(void *s, u32 on);
extern void func_021BDBAC(void *s, int v);
extern void func_021C80AC(int a, int b, int c);
extern void func_02015C48(void *p, u32 *src);
extern void func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void func_021BDBEC(void *s, int v);
extern void func_021BE82C(void *icon, int kind);
extern void func_021BDBA0(void *s);
extern void func_021C50F8(u32 obj, Vec *out);
extern int func_02012BF8(int a0, int a1);
extern void func_021BDC14(char *p, int b);
extern void func_021C7534(void *a0, u8 *p, void *ctx);
extern void func_021C4F30(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void func_021C6AFC(void *a0, u8 *p, void *ctx);
extern void func_021C68D4(void *a0, u8 *p, void *ctx);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, int v, int n);
extern struct Obj *func_0204B294(void *sys, unsigned int chr, unsigned int pal, unsigned int cell, const void *hdr, u16 a,
                                u16 heap);
extern void func_0204B92C(struct Obj *obj, u32 on);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void *ov208_func_021BC3B4(int key);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32  func_02035CB8(u32 *x, u32 *y);
extern u16  ov208_func_021C6E60(void *a0, u8 *p, int key, u16 skip, u16 want);
extern void ov208_func_021C5C64(void *a0, u8 *p, int key);
void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev);
void ov208_func_021C625C(u16 *heap, u8 *p, int key);
void func_021C66C8(void *unused,u8 *p);
int ov208_func_021C6760(void *unused, u8 *p, int key);
void ov208_func_021C68D4(void *unused, u8 *p);
void ov208_func_021C692C(u16 *heap, u8 *p, int key);
void ov208_func_021C6A10(void *unused, u8 *p, void *unused2);
void ov208_func_021C6AFC(void *a0, u8 *p, int a2);
void ov208_func_021C6BB4(void *a0, u8 *p, int key);
u32 ov208_func_021C6C00(void *a0, u8 *p, int key);
int ov208_func_021C6D10(void *a0, u8 *p, int a2);
void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi);
u16 ov208_func_021C6DD8(u16 n, u8 x);
u16 ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop);
extern const u8 data_021C87A0[4][8];



void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev)
{
    void *scene;
    void *icon;
    int flag;
    Side idx;
    Vec v;
    Vec v2;

    scene = (void *)func_021BC3B4(ctx);
    icon = (void *)func_021BC3B8(ctx);
    flag = 0;
    switch (W(0x6b8)) {
    case 0:
        switch (ev) {
        case 1:
            if (W(0x6c4) == 0) {
                func_021C5200((int *)(p + 0x94));
                func_021C5200((int *)(p + 0xd8));
                W(0x6c4) = 1;
            }
            break;
        case 2:
            W(0x6cc) = 0;
            W(0x6d0) = 0;
            if (H(0x548) >= 2) {
                W(0x6c8) = 1;
                func_021C7534(a0, p, ctx);
            }
            break;
        }
        break;
    case 1:
        if (ev == 0 && W(0x694) == 5)
            func_021BDC48(scene, 1);
        break;
    case 2:
        if (ev == 3)
            func_021BDBAC(scene, 0);
        break;
    case 3:
        if (ev == 4) {
            flag = 1;
            if (H(0x548) >= 2) {
                if (W(0xc) != 0) {
                    func_021C80AC((int)(p + 0xc), 1, (int)(&v));
                    func_02015C48((void *)W(0xc), (u32 *)(&v));
                }
                if (W(0x50) != 0) {
                    func_021C80AC((int)(p + 0x50), 1, (int)(&v));
                    func_02015C48((void *)W(0x50), (u32 *)(&v));
                }
                if (W(0x94) != 0) {
                    func_021C80AC((int)(p + 0x94), 2, (int)(&v));
                    func_02015C48((void *)W(0x94), (u32 *)(&v));
                }
                if (W(0xd8) != 0) {
                    func_021C80AC((int)(p + 0xd8), 2, (int)(&v));
                    func_02015C48((void *)W(0xd8), (u32 *)(&v));
                }
            }
            func_021BDAAC(scene, 2, 3, func_021BC3BC(ctx) > 1);
            if (H(0x548) >= 3)
                func_021BDBEC(scene, 1);
            else
                func_021BDBEC(scene, 0);
            func_021BE82C(icon, 4);
        }
        break;
    case 4:
        switch (ev) {
        case 5:
            if (W(0x6bc) == 0) {
                W(0x6bc) = 1;
                W(0x6c0) = 0;
            }
            break;
        case 6:
            W(0x6cc) = 0;
            W(0x6d0) = 0;
            break;
        }
        break;
    case 5:
        if (ev == 4 && W(0x6d8) != 0) {
            W(0x6dc) = 1;
            if (W(0x6e0) != 0) {
                W(0x6d8) = 0;
                func_021BDBA0(scene);
            }
        }
        break;
    case 6:
        if (ev == 7)
            func_021BDBAC(scene, 0);
        break;
    case 7:
        if (ev == 0) {
            flag = 1;
            if (H(0x548) >= 2) {
                if (W(0xc) != 0) {
                    func_021C80AC((int)(p + 0xc), 0, (int)(&v2));
                    func_02015C48((void *)W(0xc), (u32 *)(&v2));
                }
                if (W(0x50) != 0) {
                    func_021C80AC((int)(p + 0x50), 0, (int)(&v2));
                    func_02015C48((void *)W(0x50), (u32 *)(&v2));
                }
                idx = W(0x124) != 0 ? SIDE_0 : SIDE_1;
                func_021C50F8(*(u32 *)(p + idx * 0x44 + 0xc), &v2);
                if (W(0x94) != 0) {
                    func_021C80AC((int)(p + 0x94), 2, (int)(&v2));
                    func_02015C48((void *)W(0x94), (u32 *)(&v2));
                }
                if (W(0xd8) != 0) {
                    func_021C80AC((int)(p + 0xd8), 2, (int)(&v2));
                    func_02015C48((void *)W(0xd8), (u32 *)(&v2));
                }
            }
            func_021BDAAC(scene, 0, 3, func_021BC3BC(ctx) > 1);
            func_021BDC14(scene, func_02012BF8(func_021BC3A4(ctx), 0x14));
            func_021BE82C(icon, 3);
            if (H(0x548) >= 2) {
                W(0x6c8) = 1;
                func_021C7534(a0, p, ctx);
            }
        }
        break;
    }
    W(0x6b8) = ev;
    if (flag) {
        func_021C4F30(a0, p, ctx);
        func_021C4EAC(a0, p, ctx);
        ov208_func_021C6A10(a0, p, ctx);
        func_021C6AFC(a0, p, ctx);
        func_021C68D4(a0, p, ctx);
        W(0x694) = 5;
        func_021BDC48(scene, 1);
    }
}



void ov208_func_021C625C(u16 *heap, u8 *p, int key)
{
    struct Ov208CellHdr hdr[2];
    void *h;
    u8 i;
    const u8 *t;
    u8 *e;

    h = func_020490F4(0x9f, *heap);
    W(0x5c4) = func_0204AC18(h, 3, 0, 0, 0, 3, *heap);
    W(0x5c0) = func_0204A6C8(h, 0xd, 0, 0, *heap);
    W(0x5c8) = func_0204AF28(h, 0x1b, 0x2c, *heap);
    W(0x5d0) = func_0204AC18(h, 0, 0, 0x60, 0, 1, *heap);
    W(0x5cc) = func_0204A6C8(h, 0xa, 0, 0, *heap);
    W(0x5d4) = func_0204AF28(h, 0x1a, 0x2b, *heap);
    W(0x5dc) = func_0204AC18(h, 6, 0, 0x80, 0, 2, *heap);
    W(0x5d8) = func_0204A6C8(h, 0x10, 0, 0, *heap);
    W(0x5e0) = func_0204AF28(h, 0x1d, 0x2e, *heap);
    func_02049238(h);
    for (i = 0; i < 4; i++) {
        func_02082BCC(&hdr[1], 0, 8);
        t = data_021C87A0[i];
        hdr[1].x = t[0];
        hdr[1].y = t[1];
        hdr[1].z = t[2];
        hdr[1].a = t[3];
        hdr[1].b = t[4];
        *(u32 *)(p + i * 4 + 0x5e4) = (u32)func_0204B294((void *)W(0), RES(t[5]), RES(t[6]), RES(t[7]), &hdr[1], 0, *heap);
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0x5e4), 1);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x5e4), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x5e4)), 1);
    }
    ((struct Obj00124 *)p)->f5F4 = 0x40;
    ((struct Obj00124 *)p)->f5F6 = 0x98;
    ((struct Obj00124 *)p)->f5F8 = 0x0;
    ((struct Obj00124 *)p)->f5FC = 0x1;
    ((struct Obj00124 *)p)->f600 = 0x2;
    ((struct Obj00124 *)p)->f604 = 0x40;
    ((struct Obj00124 *)p)->f605 = 0x98;
    ((struct Obj00124 *)p)->f606 = 0x40;
    ((struct Obj00124 *)p)->f607 = 0x10;
    ((struct Obj00124 *)p)->f608 = 0x18;
    ((struct Obj00124 *)p)->f609 = 0x1a;
    ((struct Obj00124 *)p)->f60C = 0x4;
    ((struct Obj00124 *)p)->f610 = 0x54c;
    ((struct Obj00124 *)p)->f614 = 0x0;
    ((struct Obj00124 *)p)->f618 = 0x0;
    ((struct Obj00124 *)p)->f61C = 0x80;
    ((struct Obj00124 *)p)->f61E = 0x98;
    ((struct Obj00124 *)p)->f620 = 0x0;
    ((struct Obj00124 *)p)->f624 = 0x1;
    ((struct Obj00124 *)p)->f628 = 0x2;
    ((struct Obj00124 *)p)->f62C = 0x80;
    ((struct Obj00124 *)p)->f62D = 0x98;
    ((struct Obj00124 *)p)->f62E = 0x40;
    ((struct Obj00124 *)p)->f62F = 0x10;
    ((struct Obj00124 *)p)->f630 = 0x17;
    ((struct Obj00124 *)p)->f631 = 0x19;
    ((struct Obj00124 *)p)->f634 = 0x8;
    ((struct Obj00124 *)p)->f638 = 0x54c;
    ((struct Obj00124 *)p)->f63C = 0x0;
    ((struct Obj00124 *)p)->f640 = 0x0;
    ((struct Obj00124 *)p)->f644 = 0x80;
    ((struct Obj00124 *)p)->f646 = 0x60;
    ((struct Obj00124 *)p)->f648 = 0x6;
    ((struct Obj00124 *)p)->f64C = 0x7;
    ((struct Obj00124 *)p)->f650 = 0x8;
    ((struct Obj00124 *)p)->f654 = 0x0;
    ((struct Obj00124 *)p)->f655 = 0x0;
    ((struct Obj00124 *)p)->f656 = 0x18;
    ((struct Obj00124 *)p)->f657 = 0x10;
    ((struct Obj00124 *)p)->f658 = 0x4;
    ((struct Obj00124 *)p)->f659 = 0x5;
    ((struct Obj00124 *)p)->f65C = 0x200;
    ((struct Obj00124 *)p)->f660 = 0x54a;
    ((struct Obj00124 *)p)->f664 = 0x0;
    ((struct Obj00124 *)p)->f668 = 0x0;
    ((struct Obj00124 *)p)->f66C = 0xe4;
    ((struct Obj00124 *)p)->f66E = 0x60;
    ((struct Obj00124 *)p)->f670 = 0x6;
    ((struct Obj00124 *)p)->f674 = 0x7;
    ((struct Obj00124 *)p)->f678 = 0x8;
    ((struct Obj00124 *)p)->f67C = 0xe8;
    ((struct Obj00124 *)p)->f67D = 0x0;
    ((struct Obj00124 *)p)->f67E = 0x18;
    ((struct Obj00124 *)p)->f67F = 0x10;
    ((struct Obj00124 *)p)->f680 = 0x2;
    ((struct Obj00124 *)p)->f681 = 0x3;
    ((struct Obj00124 *)p)->f684 = 0x100;
    ((struct Obj00124 *)p)->f688 = 0x54a;
    ((struct Obj00124 *)p)->f68C = 0x0;
    ((struct Obj00124 *)p)->f690 = 0x0;
    for (i = 0; i < 4; i++) {
        func_02082BCC(&hdr[0], 0, 8);
        e = p + i * 0x28;
        hdr[0].x = ((struct Obj03367 *)e)->f5F4;
        hdr[0].y = ((struct Obj03367 *)e)->f5F6;
        hdr[0].z = ((struct Obj03367 *)e)->f608;
        hdr[0].a = 0;
        hdr[0].b = 3;
        ((struct Obj03367 *)e)->f618 = (u32)func_0204B294((void *)W(0), RES(((struct Obj03367 *)e)->f5F8), RES(((struct Obj03367 *)e)->f5FC),
                                            RES(((struct Obj03367 *)e)->f600), &hdr[0], 0, *heap);
        func_0204B92C((struct Obj *)((struct Obj03367 *)e)->f618, 1);
        func_0204B688((struct Actor *)(((struct Obj03367 *)e)->f618), 1);
    }
    W(0x694) = 5;
}


void func_021C66C8(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*0x28+0x618));
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*4+0x5e4));
    func_0204ADA4(((struct Obj03368 *)p)->f5C4);
    func_0204A8D4(((struct Obj03368 *)p)->f5C0);
    func_0204AFD8(((struct Obj03368 *)p)->f5C8);
    func_0204ADA4(((struct Obj03368 *)p)->f5D0);
    func_0204A8D4(((struct Obj03368 *)p)->f5CC);
    func_0204AFD8(((struct Obj03368 *)p)->f5D4);
    func_0204ADA4(((struct Obj03368 *)p)->f5DC);
    func_0204A8D4(((struct Obj03368 *)p)->f5D8);
    func_0204AFD8(((struct Obj03368 *)p)->f5E0);
}



int ov208_func_021C6760(void *unused, u8 *p, int key)
{
    void *sys;
    enum { HIT_NONE = 5 } hit;
    u32 type;
    u32 x;
    u32 y;
    u8 i;
    u8 *b;
    u8 *c;
    u8 j;
    int partner;
    int o;
    u8 *q;
    int k;
    sys = ov208_func_021BC3B4(key);
    hit = HIT_NONE;
    if (hit == 5) {
        for (i = 0; i < 4; i++) {
            b = p + i * 0x28;
            if (func_0204B3F4((void *)F32(b, 0x618)) != 0) {
                if ((func_020362DC() & F32(b, 0x60c)) != 0) {
                    type = 0;
                    hit = i;
                    break;
                }
                if (i == 2 || i == 3) {
                    if ((func_0203633C() & F32(b, 0x60c)) != 0) {
                        type = 0;
                        hit = i;
                        break;
                    }
                }
            }
        }
    }
    if (hit == 5) {
        if (func_02035D20(&x, &y) != 0) {
            k = 0x604;
            for (j = 0; j < 4; j++) {
                c = p + j * 0x28;
                if (func_0204B3F4((void *)F32(c, 0x618)) != 0) {
                    if ((u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                        && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                        type = 1;
                        hit = j;
                        break;
                    }
                }
            }
        }
    }
    if (hit != 5) {
        if (F32(p, 0x694) != 5) {
            hit = 6;
        } else {
            func_020355D8(type);
            ov208_func_021BDC48(sys, 0);
            o = hit * 0x28;
            *(u32 *)(p + 0x614 + o) = 1;
            func_0204B878((void *)*(u32 *)(p + 0x618 + o), *(u8 *)(p + 0x609 + o));
            func_020061E4(*(u32 *)(p + 0x610 + o));
            partner = 5;
            if (hit == 2)
                partner = 3;
            else if (hit == 3)
                partner = 2;
            if (partner != 5) {
                q = p + 0x618;
                func_0204B92C((void *)F32(q, partner * 0x28), 0);
                func_0204B8C4((void *)F32(q, partner * 0x28), 0);
            }
            F32(p, 0x694) = hit;
        }
    }
    return hit;
}



void ov208_func_021C68D4(void *unused, u8 *p)
{
    int on = 0;

    switch (((struct Obj05545 *)p)->f6B8) {
    case 0:
        if (((struct Obj05545 *)p)->f548 >= 2)
            on = 1;
        break;
    case 4:
        break;
    }
    if (on) {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 1);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 0);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 0);
    }
}



void ov208_func_021C692C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u32 other;

    scene = (void *)func_021BC3B4((int *)key);
    if (W(0x694) == 5)
        return;
    switch (STB(W(0x694))) {
    case 0:
        break;
    case 1:
        STB(W(0x694)) = 2;
        return;
    case 2:
        if (func_0204B98C((struct Actor *)OBJ(W(0x694))) != 0)
            break;
        ST(W(0x694)) = 3;
        return;
    case 3:
        func_0204B878((struct Obj *)OBJ(W(0x694)), B8(W(0x694)));
        ST(W(0x694)) = 0;
        other = 5;
        if (W(0x694) == 2)
            other = 3;
        else if (W(0x694) == 3)
            other = 2;
        if (other != 5 && ST(other) == 0) {
            func_0204B92C((struct Obj *)OBJB(other), 1);
            func_0204B878((struct Obj *)OBJB(other), B8(other));
        }
        W(0x694) = 5;
        if (W(0x6b8) == 0 || W(0x6b8) == 4)
            ov208_func_021BDC48(scene, 1);
        break;
    }
}



void ov208_func_021C6A10(void *unused, u8 *p, void *unused2)
{
    int show = 1;
    int multi = 0;
    int v;
    int w;
    Ov208Pos pos;

    switch (((struct Obj02258 *)p)->f6B8) {
    case 0:
        show = 1;
        break;
    case 4:
        if (((struct Obj02258 *)p)->f548 >= 2)
            multi = 1;
        break;
    }
    if (show && multi) {
        pos.x = 0;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5EC), (const struct Vec2 *)(&pos), 0);
        pos.x = 0x80;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5F0), (const struct Vec2 *)(&pos), 0);
    } else if (show) {
        pos.x = 0x40;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5EC), (const struct Vec2 *)(&pos), 0);
    }
    if (*(u32 *)(p + ((struct Obj02258 *)p)->f54E * 16 + 0x14c) == 2)
        v = 1;
    else
        v = 0;
    func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5EC, 1);
    func_0204B878((struct Obj *)(((struct Obj02258 *)p)->f5EC), (u8)v);
    if (multi) {
        w = *(u32 *)(p + ((struct Obj02258 *)p)->f550 * 16 + 0x14c) == 2;
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 1);
        func_0204B878((struct Obj *)(((struct Obj02258 *)p)->f5F0), (u8)w);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 0);
    }
}



void ov208_func_021C6AFC(void *a0, u8 *p, int a2)
{
    int on = 0;
    u16 n;
    u8 mid;
    Ov208Pos pos;

    switch (((struct Obj01979 *)p)->f6B8) {
    case 0:
        break;
    case 4:
        if (((struct Obj01979 *)p)->f548 >= 3)
            on = 1;
        break;
    }
    if (on) {
        n = ov208_func_021C6E30(a0, p, a2, ((struct Obj01979 *)p)->f54E, ((struct Obj01979 *)p)->f550);
        ov208_func_021C6D6C((u16)(((struct Obj01979 *)p)->f548 - 1), n, 0, &mid, 0);
        pos.x = mid;
        pos.y = 0x30;
        func_0204B404((struct Obj *)(((struct Obj01979 *)p)->f5E8), (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E4, 1);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E8, 1);
        ((struct Obj01979 *)p)->f698 = 0;
        ((struct Obj01979 *)p)->f6D4 = 0;
        ((struct Obj01979 *)p)->f69C = 0;
    } else {
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E4, 0);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E8, 0);
    }
}



void ov208_func_021C6BB4(void *a0, u8 *p, int key)
{
    if ((W(0x6b8) == 4 && W(0x6b4) != 0 && W(0x694) == 5) || W(0x6d4) != 0) {
        if (ov208_func_021C6D10(a0, p, key) == 0)
            ov208_func_021C6C00(a0, p, key);
    }
}



u32 ov208_func_021C6C00(void *a0, u8 *p, int key)
{
    u32 x;
    u32 y;
    s16_021C66C8 pos[2];
    void *scene;
    int moved;
    u16 old;

    scene = (void *)func_021BC3B4((int *)key);
    moved = 0;
    if (W(0x69c) != 0) {
        if (func_02035CB8(&x, &y) == 0) {
            W(0x69c) = 0;
            func_021BDC48(scene, 1);
        }
    } else if (H(0x548) >= 3) {
        if (func_02035D20(&x, &y) != 0 && x >= 0x90 && x <= 0xe7 && y >= 0x28 && y <= 0x3f) {
            W(0x69c) = 1;
            func_021BDC48(scene, 0);
            moved = 1;
        }
    }
    if (W(0x69c) != 0) {
        old = H(0x550);
        x = x > 0xdc ? 0xdc : (x < 0x9c ? 0x9c : x);
        pos[0] = x;
        pos[1] = 0x30;
        func_0204B404((struct Obj *)W(0x5e8), (const struct Vec2 *)pos, 0);
        H(0x550) = ov208_func_021C6E60(a0, p, key, H(0x54e),
                                       ov208_func_021C6DD8(H(0x548) - 1, x));
        if (old != H(0x550)) {
            ov208_func_021C5C64(a0, p, key);
            moved = 1;
        }
    }
    if (moved)
        func_020061E4(0x645);
    if (W(0x69c) != 0)
        func_020355D8(1);
    return W(0x69c);
}



int ov208_func_021C6D10(void *a0, u8 *p, int a2)
{
    struct Ov208Cursor c;
    int moved;
    u16 i;

    moved = 0;
    if (W(0x698) != 0) {
        i = ov208_func_021C6E30(a0, p, a2, H(0x54e), H(0x550));
        ov208_func_021C6D6C((u16)(H(0x548) - 1), i, 0, &c.slot, 0);
        c.x = c.slot;
        c.y = 0x30;
        func_0204B404((struct Obj *)W(0x5e8), (const struct Vec2 *)(&c.x), 0);
        moved = 1;
    }
    return moved;
}



void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi)
{
    u8 a = i * 65 / n + 0x9c;
    u8 b = (i + 1) * 65 / n + 0x9c;
    u8 m;

    if (i == 0)
        m = a;
    else if (i == n - 1)
        m = b - 1;
    else if (a >= b)
        m = a;
    else
        m = (a + b - 1) / 2;
    if (lo != 0)
        *lo = a;
    if (hi != 0)
        *hi = b;
    if (mid != 0)
        *mid = m;
}



u16 ov208_func_021C6DD8(u16 n, u8 x)
{
    u8 b[3];
    u16 i;

    for (i = 0; i < n; i++) {
        ov208_func_021C6D6C(n, i, &b[2], &b[1], &b[0]);
        if (i == 0) {
            if (x < b[0])
                break;
        } else {
            if (i == n - 1)
                break;
            if (b[2] <= x && x < b[0])
                break;
        }
    }
    return i;
}



u16 ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop)
{
    u16 n = 0;
    u16 i;

    for (i = 0; i < ((struct Obj25526 *)p)->f548; i++) {
        if (i == skip)
            continue;
        if (i == stop)
            break;
        n++;
    }
    return n;
}
