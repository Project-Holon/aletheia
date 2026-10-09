/*
 * file:     worldtrade_enter_p04.c
 * unit:     yes
 * function: func_021FB240, func_021FB26C, func_021FB2F0, func_021FB364, func_021FB3D8, func_021FB510, func_021FB588, func_021FB5E4, func_021FB614, func_021FB674, func_021FB704, func_021FB7A0
 * address:  0x021FB240
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
 *   func_0200D064  0x0200D064  thumb
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_02203220  0x02203220  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021F9EEC  0x021F9EEC  thumb
 *   func_021FBF04  0x021FBF04  thumb
 *   func_021FBEB8  0x021FBEB8  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9FF0 0x021F9FF0 thumb ov135
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_0201F868 0x0201F868 thumb
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   tbl_02203298 0x02203298 data a1
 *   func_021FA514 0x021FA514 thumb ov135
 *   tbl_022033FC 0x022033FC data a4
 */
#include "../../matched/include/Obj02490.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj02858.h"
#include "../../matched/include/Obj00195.h"
#include "../../matched/include/Obj02859.h"

struct Blk37;
struct Slot;
struct WinMgr;
struct CharBuf;
struct Descriptor;
struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

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

extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(Obj *p, u32 mode);
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
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(u8 *p, u32 k);
extern u32 func_0201F868(void *p);
extern void func_021FA9C8(u8 *p, int mode, int pos);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021FA514(void *p, u8 *flags);
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
void func_021FB2F0(Menu *m, int page, int total);
void func_021FB364(Menu *m, int page, int total);
int func_021FB3D8(Obj *p);
int func_021FB510(u8 *p);
int func_021FB588(u8 *p);
int func_021FB5E4(u8 *p);
int func_021FB614(u8 *p);
int func_021FB674(u8 *p);
int func_021FB704(u8 *p);
int func_021FB7A0(u8 *p);
extern const int tbl_02203324[];
extern const Cell tbl_02203220[];
extern u8 g_022033FC[];
extern const u8 tbl_02203298[][2];
extern const int tbl_022033FC[][2];




/*
 * Count the entries of a u16 table that the query accepts.
 */
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (func_0200D064((struct Blk37 *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}




int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = func_021F8498(0x48, 0, &count);
    func_021F84BC(kind, &start, &end);
    count = end - start;
    n = func_021FB240(x, (u32)bag, count, list, start, end);
    *menu = func_0201F81C(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (func_0200D064(bag, list[i]) != 0) {
            func_0201F878(*menu, (u32)msg, list[i], list[i], 0x48);
        }
    }
    func_020307B0(list);
    return n;
}




void func_021FB2F0(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 4 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 4 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}




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
    func_021FB2F0((Menu *)p, 0, p->count);
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



/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
int func_021FB588(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x0);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0xd : 0x9;
    return -1;
}


int func_021FB5E4(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,0);func_0201F868(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f3C; }


int func_021FB614(u8 *p)
{
    func_021FA9C8(p, 6, 0x20);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 18);
    func_0202CD64(((struct Obj02858 *)p)->f18, 0, -4, 0, 4);
    ((struct Obj02858 *)p)->f48 = 1;
    ((struct Obj02858 *)p)->f4C = 19;
    ((struct Obj02858 *)p)->f44 = 10;
    ((struct Obj02858 *)p)->f38 = -1;
    func_021F4FF4(((struct Obj02858 *)p)->f8, (tbl_02203298[((struct Obj02858 *)p)->f44][0] + 16) * 8, tbl_02203298[((struct Obj02858 *)p)->f44][1] * 8);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 6);
    return -1;
}


int func_021FB674(u8 *p)
{
    int r;
    r = func_021FA514(p, p + 0x60);
    switch ((u32)r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -1;
        break;
    case 10:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), 19);
        ((struct Obj00195 *)p)->f38 = r;
        ((struct Obj00195 *)p)->f48 = 20;
        break;
    }
    return -1;
}


int func_021FB704(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660(p, 6);
    if (((struct Obj00098 *)p)->f38 < 0) {
        if (((struct Obj00098 *)p)->f38 == -1) return -2;
        else if (((struct Obj00098 *)p)->f38 == -2) return 0;
    } else {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38][0] != 1) {
            ((struct Obj00098 *)p)->f48 = 22;
        } else {
            ((struct Obj00098 *)p)->f3A = 0;
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
        }
    }
    return -1;
}


int func_021FB7A0(u8 *p)
{
    func_021FA9C8(p, 6, 0x10);
    func_0204B878((struct Obj *)(((struct Obj02859 *)p)->f8), 18);
    func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f44 = ((struct Obj02859 *)p)->f38;
    func_021F4FF4(((struct Obj02859 *)p)->f8, (tbl_02203298[((struct Obj02859 *)p)->f44][0] + 16) * 8, tbl_02203298[((struct Obj02859 *)p)->f44][1] * 8);
    if (func_020355C4() == 1) func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 0);
    else func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f48 = 19;
    return -1;
}
