/*
 * file:     worldtrade_adapter_p03.c
 * unit:     yes
 * function: func_021FBCB8, func_021FBCF4, func_021FBD68, func_021FBD94, func_021FBDD0, func_021FBE54, func_021FBE84, func_021FBEB8, func_021FBF04
 * address:  0x021FBCB8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FAAD4  0x021FAAD4  thumb  ov135
 *   func_021F4FF4  0x021F4FF4  thumb  ov135
 *   g_0220320E  0x0220320E  data  ov135
 *   g_0220320F  0x0220320F  data  ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA15C 0x021FA15C thumb ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   func_021FAB70  0x021FAB70  thumb  ov135
 *   g_02203216  0x02203216  data  ov135
 *   g_02203217  0x02203217  data  ov135
 *   func_021FA394 0x021FA394 thumb ov135
 *   func_0201F868 0x0201F868 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045808  0x02045808  arm
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02202A50  0x02202A50  thumb
 *   func_02202B20  0x02202B20  thumb
 */
#include "../../matched/include/Obj04906.h"
#include "../../matched/include/Obj02202.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj00474.h"
#include "../../matched/include/Obj01746.h"

struct Obj;
struct Actor;
struct MsgBank;
struct U16Vec;
struct WinMgr;
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

extern void func_021FAAD4(u8 *p);
extern void func_021F4FF4(u32 v, u32 a, u32 b);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u16 func_0204B898(struct Obj *p);
extern int func_021FA15C(void *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(void *,u32);
extern void func_021FAB70(u8 *p);
extern int func_021FA394(void *p);
extern u32 func_0201F868(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02202A50(void *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
extern void func_02202B20(struct Obj *p, int arg1, void *arg2, int arg3, int arg4);
int func_021FBCB8(u8 *p);
int func_021FBCF4(u8 *p);
int func_021FBD68(u8 *p);
int func_021FBD94(u8 *p);
int func_021FBDD0(u8 *p);
int func_021FBE54(u8 *p);
void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern u8 g_0220320E[];
extern u8 g_0220320F[];
extern u8 g_02203216[];
extern u8 g_02203217[];


/*
 * Reset, re-arm the 6 frame, then index the two parallel stride-2 tables from the cursor at +0x44.
 */
int func_021FBCB8(u8 *p)
{
    u32 i;

    ((struct Obj04906 *)p)->f44 = 0;
    func_021FAAD4(p);
    func_0204B878((struct Obj *)(((struct Obj04906 *)p)->f8), 6);
    i = ((struct Obj04906 *)p)->f44;
    func_021F4FF4(((struct Obj04906 *)p)->f8, g_0220320E[i * 2], g_0220320F[i * 2]);
    ((struct Obj04906 *)p)->f48 = 1;
    ((struct Obj04906 *)p)->f4C = 0x1f;
    return -1;
}

/*
 * Tail: two zero bytes of alignment padding after the return.
 */
int func_021FBCF4(u8 *p)
{
    int r;
    r = func_021FA15C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02202 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02202 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02202 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02202 *)p)->f8)) + 9);
        ((struct Obj02202 *)p)->f48 = 3;
        ((struct Obj02202 *)p)->f4C = 32;
        ((struct Obj02202 *)p)->f40 = r;
        break;
    }
    return -1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021FBD68(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,1);return ((struct Obj00098 *)p)->f40; }


int func_021FBD94(u8 *p)
{
    u32 i;

    ((struct Obj00474 *)p)->f44 = 0;
    func_021FAB70(p);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    i = ((struct Obj00474 *)p)->f44;
    func_021F4FF4(((struct Obj00474 *)p)->f8, g_02203216[i * 2], g_02203217[i * 2]);
    ((struct Obj00474 *)p)->f48 = 1;
    ((struct Obj00474 *)p)->f4C = 0x22;
    return -1;
}

int func_021FBDD0(u8 *p)
{
    int r;
    r = func_021FA394(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj01746 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj01746 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj01746 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj01746 *)p)->f8)) + 9);
        ((struct Obj01746 *)p)->f48 = 3;
        ((struct Obj01746 *)p)->f4C = 35;
        ((struct Obj01746 *)p)->f41 = *(u32 *)(*(u8 * *)&((struct Obj01746 *)p)->f30 + (r + ((struct Obj01746 *)p)->f56 * 4) * 8 + 4);
        break;
    }
    return -1;
}

int func_021FBE54(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,2);func_0201F868(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f41; }


void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_021FAC50(mgr, win, str, x, color, g);
    func_02045808(str);
}


void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_022028C8(win, 0, str, 0, 0, 0, 0x3DC2, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
    func_02045808(str);
}


void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages)
{
    func_02043B5C(func_02045770(win), 8);
    func_02202A50(ctx, page + 1, 2, 1, win, 0, 0);
    func_02202B20(ctx, 0, win, 0x10, 0);
    func_02202A50(ctx, pages, 2, 0, win, 0x18, 0);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
}
