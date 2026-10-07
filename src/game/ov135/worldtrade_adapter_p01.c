/*
 * file:     worldtrade_adapter_p01.c
 * unit:     yes
 * function: func_021FB800, func_021FB964, func_021FB9E4, func_021FBA5C
 * address:  0x021FB800
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
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_022033F8  0x022033F8  data
 *   tbl_02203440  0x02203440  data  a4
 *   tbl_022032C6  0x022032C6  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FC008  0x021FC008  thumb
 *   func_021FBEB8  0x021FBEB8  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9CDC 0x021F9CDC thumb ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   func_020355C4  0x020355C4  arm
 */
#include "../../matched/include/Obj00194.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj05872.h"

struct WinMgr;
struct Obj;
struct Actor;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    int first;
    int count;
} Span;

typedef struct {
    void **strs;
    u8 pad4[8 - 4];
    u32 cursor;
    u8 padC[0x14 - 0xC];
    u32 cursor2;
    void *mgr;
    u8 pad1C[0x20 - 0x1C];
    void *bank;
    u8 pad24[0x38 - 0x24];
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x60 - 0x4C];
    u8 flags[0x7C - 0x60];
    u8 g[4];
} Obj;

extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(Obj *p, u32 mode);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FC008(void *p, u32 a);
extern void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern u16 func_0204B898(struct Obj *p);
extern int func_021F9CDC(void *p, u8 *flags);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(void *p, u32 mode);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
int func_021FB800(Obj *p);
int func_021FB964(u8 *p);
int func_021FB9E4(u8 *p);
int func_021FBA5C(u8 *p);
extern const int tbl_02203324[];
extern const Span tbl_022033F8[];
extern const u32 tbl_02203440[];
extern const Cell tbl_022032C6[];


int func_021FB800(Obj *p)
{
    int i;
    u16 color;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 5);
    func_02082BCC(p->flags, 1, 0x1A);
    func_021FBE84(p->mgr, p->bank, p->strs[0], p->layout + 0x74, 2, 0x3DC2, p->g);
    for (i = 1; i < 4; i++) {
        if (func_021FC008(p, tbl_02203324[p->layout] + i - 1) > 0) {
            color = 0x3DC2;
            p->flags[tbl_02203324[p->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            p->flags[tbl_02203324[p->layout] + i - 1] = 0;
        }
        func_021FBE84(p->mgr, p->bank, p->strs[i], tbl_02203440[tbl_022033F8[p->layout].first + i - 1], 5, color, p->g);
    }
    func_021FBEB8(p->mgr, p->bank, p->strs[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)p->cursor, 4);
    if (p->start < 0) {
        p->pos = 0;
    } else {
        p->pos = p->start;
    }
    func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)p->cursor, 1);
    }
    if (p->cursor2 != 0) {
        func_0204B3DC((struct Obj *)p->cursor2, 1);
    }
    p->state = 0x17;
    return -1;
}

int func_021FB964(u8 *p)
{
    int r;
    r = func_021F9CDC(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}

/*
 * Tail: two zero bytes of alignment padding after the return.
 */
int func_021FB9E4(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660(p, 5);
    if (((struct Obj00098 *)p)->f3A < 0) {
        ((struct Obj00098 *)p)->f48 = 21;
    } else {
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
    }
    return -1;
}


/*
 * State select before the notify call.
 */
int func_021FBA5C(u8 *p)
{
    u32 v;
    int n;

    ((struct Obj05872 *)p)->f48 = 0x16;
    ((struct Obj05872 *)p)->f44 = ((struct Obj05872 *)p)->f3A;
    if (func_020355C4() == 1) {
        v = ((struct Obj05872 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj05872 *)p)->f8;
        n = 1;
    }
    func_0204B3DC((struct Obj *)v, n);
    return -1;
}
