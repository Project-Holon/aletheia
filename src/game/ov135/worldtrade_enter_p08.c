/*
 * file:     worldtrade_enter_p08.c
 * unit:     yes
 * function: func_021F9890, func_021F9968, func_021F99D0
 * address:  0x021F9890
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
 *   func_02030734  0x02030734  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02202974  0x02202974  thumb
 *   func_022026D8  0x022026D8  thumb
 *   g_02203CD8     0x02203CD8  data  ov135
 *   func_02202744  0x02202744  thumb  ov135
 *   func_022029D4  0x022029D4  thumb  ov135
 */
#include "../../matched/include/Obj01259.h"
#include "../../matched/include/Obj12206.h"

struct WinMgr;
struct Obj;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    void *frm;
    u32 w24;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w28;
    u8 pad30[4];
    void *ctx;
    u16 h38;
    u16 h3a;
    u16 h3c;
    u16 h3e;
    u8 b40;
    u8 b41;
    u8 pad42[2];
    u32 w44;
    u32 w48;
    u8 pad4c[4];
    u32 a;
    u8 pad54[8];
    u32 b;
    u8 pad60[0x1a];
    u8 b7a;
    u8 pad7b;
    u8 sub[0x13c];
} Menu;

typedef signed int s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_02202974(u32 a, u32 b, u32 c, u32 heap);
extern void func_022026D8(void *ctx, u32 arg);
extern void func_02202744(u8 *p);
extern void func_022029D4(u8 *p);
extern void func_0202CA0C(struct WinMgr *mgr);
extern u32 func_020307B0(void *p);
Menu *func_021F9890(Init *init, u32 a, u32 b);
void func_021F9968(u8 *p, int mode);
void func_021F99D0(u8 *p);
extern u8 g_02203CD8[];


Menu *func_021F9890(Init *init, u32 a, u32 b)
{
    Menu *m;

    m = func_02030734(0x48, 0x1b8, 0, (const char *)g_02203CD8, 0x336);
    m->w00 = init->w00;
    m->w04 = init->w04;
    m->obj = init->obj;
    m->w0c = init->w0c;
    m->w10 = init->w10;
    m->w14 = init->w14;
    m->w18 = init->w18;
    m->w1c = init->w1c;
    m->w20 = init->w20;
    m->w24 = init->w24;
    m->w28 = init->w28;
    m->a = a;
    m->b = b;
    m->h38 = 0;
    m->h3a = 0;
    m->h3c = 0;
    m->h3e = 0;
    m->b40 = 0;
    m->b41 = 0;
    m->w44 = 0;
    m->b7a = 0;
    m->w48 = 0;
    m->frm = func_0202C9B4(2, 1, 0x48);
    func_0202CA3C(m->frm, 0, 2, 0x20, 0x14);
    func_021F4FF4(m->obj, 0x90, 0x28);
    func_0204B878((struct Obj *)m->obj, 4);
    func_0204B92C((struct Obj *)m->obj, 1);
    func_0204B3DC((struct Obj *)m->obj, 0);
    m->ctx = func_02202974(0xf, 0xe, 2, 0x48);
    func_022026D8(m->sub, init->arg);
    return m;
}

/*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
void func_021F9968(u8 *p, int mode)
{
    ((struct Obj01259 *)p)->f54 = mode;
    switch (mode) {
    case 0:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 6;
        return;
    case 3:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 18;
        return;
    case 1:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 30;
        return;
    case 2:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 33;
        break;
    }
}


/*
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */
void func_021F99D0(u8 *p)
{
    func_02202744(p + 0x7c);
    func_022029D4(*(u8 * *)&((struct Obj12206 *)p)->f34);
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj12206 *)p)->f18);
    func_020307B0((void *)((u32)p));
}
