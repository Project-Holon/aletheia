/*
 * file:     worldtrade_enter_p18.c
 * unit:     yes
 * function: func_021FB364, func_021FB3D8, func_021FB510
 * address:  0x021FB364
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_02203220  0x02203220  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021FB26C  0x021FB26C  thumb
 *   func_021FB2F0  0x021FB2F0  thumb
 *   func_021F9EEC  0x021F9EEC  thumb
 *   func_021FBF04  0x021FBF04  thumb
 *   func_021FBEB8  0x021FBEB8  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9FF0 0x021F9FF0 thumb ov135
 */
#include "../../matched/include/Obj02490.h"

struct WinMgr;
struct CharBuf;
struct Descriptor;
struct Obj;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[0xC - 4];
    u32 up;
    u32 down;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    u8 pad1C[0x30 - 0x1C];
    Item *items;
    void *num;
    u8 pad38[0x56 - 0x38];
    s16 page;
    int total;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Menu;

typedef signed int s32;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    void **strs;
    u8 pad4[8 - 4];
    u32 cursor;
    u32 left;
    u32 right;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    u8 pad28[0x2C - 0x28];
    u32 x2c;
    void *menu;
    void *list;
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x56 - 0x4C];
    s16 page;
    int count;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Obj;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(Obj *p, u32 mode);
extern int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
extern void func_021FB2F0(Obj *p, int page, int total);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u16 func_0204B898(struct Obj *p);
extern int func_021F9FF0(void *p);
extern void func_020061E4(u32 se);
void func_021FB364(Menu *m, int page, int total);
int func_021FB3D8(Obj *p);
int func_021FB510(u8 *p);
extern const int tbl_02203324[];
extern const Cell tbl_02203220[];


void func_021FB364(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 5 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 5 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}


int func_021FB3D8(Obj *p)
{
    u8 pages;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1D, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 0);
    p->count = func_021FB26C(&p->menu, p->msg, p->bank, p->x2c, tbl_02203324[p->layout] + p->start, p->bag);
    p->page = 0;
    func_021FB2F0(p, 0, p->count);
    pages = func_021F9EEC((u8 *)p->count, 4);
    func_021FBF04(p->mgr, p->list, p->strs[4], p->page, pages);
    func_021FBEB8(p->mgr, p->bank, p->strs[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)p->cursor, 6);
    p->pos = 0;
    func_021F4FF4(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    func_021F4FF4(p->left, 0xE4, 0x78);
    func_021F4FF4(p->right, 0x9A, 0x78);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)p->cursor, 1);
    }
    if (pages == 1) {
        func_0204B878((struct Obj *)p->left, 0x3D);
        func_0204B878((struct Obj *)p->right, 0x3E);
    } else {
        func_0204B878((struct Obj *)p->left, 0x26);
        func_0204B878((struct Obj *)p->right, 0x27);
    }
    func_0204B92C((struct Obj *)p->left, 0);
    func_0204B92C((struct Obj *)p->right, 0);
    func_0204B3DC((struct Obj *)p->left, 1);
    func_0204B3DC((struct Obj *)p->right, 1);
    p->state = 0xF;
    return -1;
}

int func_021FB510(u8 *p)
{
    int r;
    r = func_021F9FF0(p);
    switch (r) {
    case -2:
        func_020061E4(0x551);
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 16;
        ((struct Obj02490 *)p)->f3C = -1;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 3;
        ((struct Obj02490 *)p)->f4C = 17;
        ((struct Obj02490 *)p)->f3C = r;
        break;
    }
    return -1;
}
