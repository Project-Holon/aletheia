/*
 * file:     field_wfbc_p13.c
 * unit:     yes
 * function: func_02196ECC, func_02196F44, func_02196FF0, func_02196FFC, func_02197058, func_0219707C, func_02197190
 * address:  0x02196ECC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02196E70  0x02196E70  thumb  ov021
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196EC8  0x02196EC8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02051C88  0x02051C88  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3FC8     0x021D3FC8  data  ov021  a1
 *   d_021D3FB0     0x021D3FB0  data  ov021  a1
 *   d_021D3FA8     0x021D3FA8  data  ov021  a1
 *   d_021D3FA0     0x021D3FA0  data   a1
 *   d_021D3F8C     0x021D3F8C  data   a1
 *   d_021D3F94     0x021D3F94  data   a1
 */
#include "../../matched/include/Obj05003.h"
#include "../../matched/include/Obj17949.h"
#include "../../matched/include/Obj04220.h"
#include "../../matched/include/Obj00093.h"

struct Actor;
struct Cmd;
struct Obj_02196F44;
struct Ctx;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Obj_02196ECC { u32 x0; u32 x4; u32 x8; u8 pad[0x288]; void *objs[27]; u32 mode; } Obj_02196ECC;

typedef struct { u16 x0; Obj_02196ECC *a; void (*cb)(); } Req;

typedef signed int     s32;

typedef struct { u8 pad[0x294]; void *arr[5]; } Obj_02196F44;

typedef struct { u8 v[5]; } B5;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef struct { u16 a, b, c; u8 d, e; } Rect;

typedef struct { u8 v[3]; } B3;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub sub;
} Obj;

extern void func_02196E70(u8 *p);
extern void func_0204B92C(struct Obj_02196ECC *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_02196034(Obj_02196ECC *, void (*)(), u32);
extern void func_02196EC8();
extern void func_020061E4(u32 a);
extern s32 func_02051C88(struct Ctx *c);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *h, u32 b, u32 c, u32 d, u16 e);
extern s32 func_0204AC18(void *h, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *h, u32 b, u32 c, u32 d);
extern void func_02049238(void *h);
extern void func_0204B3B4(struct Obj_02196F44 *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_02196ECC(Obj_02196ECC *a);
int func_02196F44(u32 v, u8 *p);
void func_02196FF0(u8 *p);
void func_02196FFC(u8 *p);
void func_02197058(Obj_02196F44 *a);
void func_0219707C(u8 *p);
void func_02197190(Obj *p);
extern B5 d_021D3FC8;
extern B5 d_021D3FB0;
extern B5 d_021D3FA8;
extern const B3 d_021D3FA0;
extern const B3 d_021D3F8C;
extern const B3 d_021D3F94;




/*
 * Addresses are Black-image addresses.
 */
void func_02196ECC(Obj_02196ECC *a)
{
    Req r;
    int i;

    switch (a->x8) {
    case 1:
        i = 0;
        break;
    case 2:
        i = 1;
        break;
    case 3:
        i = 2;
        break;
    case 4:
        i = 3;
        break;
    default:
        i = 4;
        break;
    }
    r.x0 = 0;
    r.a = a;
    r.cb = func_02196E70;
    func_0204B92C((struct Obj_02196ECC *)(a->objs[i]), 1);
    func_0204BA00(a->objs[i], (const struct Cmd *)(&r));
    func_0204B9A0(a->objs[i]);
    func_02196034((Obj_02196ECC *)a, func_02196EC8, 0x58F);
}






/*
 * Handler: stores the request at +0x300 and dispatches on it (five cases).
 *
 * Addresses are Black-image addresses.
 */
int func_02196F44(u32 v, u8 *p)
{
    int r = 0;

    ((struct Obj05003 *)p)->f300 = v;
    switch (v) {
    case 0:
        func_020061E4(0x73B);
        r = 1;
        ((struct Obj05003 *)p)->f8 = 1;
        func_02196034((Obj_02196ECC *)p, func_02196ECC, 0x5B1);
        break;
    case 1:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 2;
        func_02196034((Obj_02196ECC *)p, func_02196ECC, 0x5B7);
        r = 1;
        break;
    case 2:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 3;
        func_02196034((Obj_02196ECC *)p, func_02196ECC, 0x5BD);
        r = 1;
        break;
    case 3:
        func_020061E4(0x73B);
        ((struct Obj05003 *)p)->f8 = 4;
        func_02196034((Obj_02196ECC *)p, func_02196ECC, 0x5C3);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        ((struct Obj05003 *)p)->f8 = 0xC;
        func_02196034((Obj_02196ECC *)p, func_02196ECC, 0x5C9);
        break;
    }
    return r;
}







/*
 * Untraced thunk: tail call on the word at +0x24 into the ARM9 image.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FF0(u8 *p)
{
    func_02051C88((struct Ctx *)(((struct Obj17949 *)p)->f24));
}







/*
 * Builds three objects on one owner handle and stores them at +0x274,
 * +0x27C and +0x284.
 *
 * Addresses are Black-image addresses.
 */
void func_02196FFC(u8 *p)
{
    void *h = func_020490F4(0x1D, ((struct Obj04220 *)p)->f10);

    ((struct Obj04220 *)p)->f27C = func_0204A6C8(h, 5, 0, 1, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f274 = func_0204AC18(h, 3, 1, 0, 0, 0xA, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f284 = func_0204AF28(h, 7, 0x10, ((struct Obj04220 *)p)->f10);
    func_02049238(h);
}





void func_02197058(Obj_02196F44 *a)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (a->arr[i] != 0) {
            func_0204B3B4((struct Obj_02196F44 *)(a->arr[i]));
            a->arr[i] = 0;
        }
    }
}



void func_0219707C(u8 *p)
{
    B5 xs = d_021D3FC8;
    B5 ys = d_021D3FB0;
    B5 zs = d_021D3FA8;
    Pos pos;
    int i;

    func_02197058((Obj_02196F44 *)p);
    for (i = 0; i < 5; i++) {
        pos.x = xs.v[i];
        pos.y = ys.v[i];
        pos.z = zs.v[i];
        pos.a = 0;
        pos.b = 1;
        *(u32 *)(p + i * 4 + 0x294) = (u32)func_0204B294((void *)*(u32 *)&((struct Obj00093 *)p)->f26C, *(u32 *)&((struct Obj00093 *)p)->f27C,
            *(u32 *)&((struct Obj00093 *)p)->f274, *(u32 *)&((struct Obj00093 *)p)->f284, &pos, 1, ((struct Obj00093 *)p)->f10);
        func_0204B92C((struct Obj_02196ECC *)((struct Obj *)*(u32 *)(p + i * 4 + 0x294)), 0);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x294), 1);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x294)), 1);
    }
}


void func_02197190(Obj *p)
{
    B3 x0 = d_021D3FA0;
    B3 x1 = d_021D3F8C;
    B3 x2 = d_021D3F94;
    Rect r;
    int i;

    func_02197058((Obj_02196F44 *)p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)func_0204B294((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C((struct Obj_02196ECC *)((struct Obj *)p->sub.arr[i]), 0);
        func_0204B3DC((struct Obj *)p->sub.arr[i], 1);
        func_0204B688((struct Actor *)p->sub.arr[i], 1);
    }
}
