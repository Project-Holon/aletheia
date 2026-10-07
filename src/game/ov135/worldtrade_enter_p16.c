/*
 * file:     worldtrade_enter_p16.c
 * unit:     yes
 * function: func_021FAD24, func_021FAD84, func_021FADA8, func_021FADF0, func_021FAE2C, func_021FAE8C, func_021FAEE0, func_021FAFF0, func_021FB164, func_021FB1E4, func_021FB220
 * address:  0x021FAD24
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
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202CD64 0x0202CD64 thumb
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_021F9A88 0x021F9A88 thumb ov135
 *   func_0204B898 0x0204B898 arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   tbl_022033FC 0x022033FC data a4
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_02082BCC 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_020355C4 0x020355C4 arm
 *   tbl_022032C6 0x022032C6 data a1
 *   ov135_func_021F9260  0x021F9260  thumb
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FBF6C  0x021FBF6C  thumb
 *   tbl_02203324   0x02203324  data
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 *   func_021F9CDC 0x021F9CDC thumb ov135
 */
#include "../../matched/include/Obj03297.h"
#include "../../matched/include/Obj07245.h"
#include "../../matched/include/Obj05414.h"
#include "../../matched/include/Obj05415.h"
#include "../../matched/include/Obj00246.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj01160.h"
#include "../../matched/include/Obj00194.h"
#include "../../matched/include/Obj09235.h"

struct WinMgr;
struct Actor;
struct Obj;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int s32;

typedef struct { u8 x; u8 y; } CurPos;

typedef struct {
    int first;
    int count;
} Range;

typedef struct {
    void **wins;
    u8 pad4[8 - 4];
    u32 cursor;
    u8 padC[0x18 - 0xC];
    void *mgr;
    u8 pad1C[0x20 - 0x1C];
    void *bank;
    u8 pad24[0x38 - 0x24];
    s16 page;
    s16 sel;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x60 - 0x4C];
    u8 flags[0x1C];
    u8 g[4];
} Menu;

extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021FA9C8(u8 *,int,int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32,u32,u32);
extern u32 func_021F9A88(void *, void *);
extern u16 func_0204B898(struct Obj *p);
extern void func_021F9660(void *, int);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_02082BCC(void *, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern u8 func_020355C4(void);
extern void ov135_func_021F9260(Menu *m, u32 mode);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FBF6C(Menu *m, u32 idx);
extern int func_021F9CDC(void *p, u8 *flags);
int func_021FAD24(u8 *p);
int func_021FAD84(u8 *p);
int func_021FADA8(u8 *p);
void func_021FADF0(u8 *p);
int func_021FAE2C(u8 *p);
int func_021FAE8C(u8 *p);
int func_021FAEE0(u8 *p);
int func_021FAFF0(Menu *m);
int func_021FB164(u8 *p);
int func_021FB1E4(u8 *p);
int func_021FB220(u8 *p);
extern const int tbl_022033FC[][2];
extern const CurPos tbl_022032C6[];
extern const int tbl_02203324[];
extern const Range tbl_022033F8[];
extern const u32 tbl_02203440[];

/*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 */
int func_021FAD24(u8 *p)
{
    if (func_0204B98C(((struct Obj03297 *)p)->f8)) return -1;
    func_0204B3DC(((struct Obj03297 *)p)->f8, 0);
    func_0204B3DC(((struct Obj03297 *)p)->fC, 0);
    func_0204B3DC(((struct Obj03297 *)p)->f10, 0);
    if (((struct Obj03297 *)p)->f54 == 3 && ((struct Obj03297 *)p)->f4C == 28)
        func_0202CD64(((struct Obj03297 *)p)->f18, 0, 6, 0, 6);
    else
        func_0202CD64(((struct Obj03297 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj03297 *)p)->f48 = 4;
    return -1;
}


/*
 * Drain the queue then flush the shadowed value, always answering -1.
 */
int func_021FAD84(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0) == 0) {
        func_0202CC70(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0);
        ((struct Obj07245 *)p)->f48 = ((struct Obj07245 *)p)->f4C;
    }
    return -1;
}

int func_021FADA8(u8 *p)
{
    if (func_0204B98C(((struct Obj05414 *)p)->f8)) return -1;
    func_0204B3DC(((struct Obj05414 *)p)->f8, 0);
    func_0204B3DC(((struct Obj05414 *)p)->fC, 0);
    func_0204B3DC(((struct Obj05414 *)p)->f10, 0);
    func_0202CD64(((struct Obj05414 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj05414 *)p)->f48 = 2;
    return -1;
}

void func_021FADF0(u8 *p) {func_021FA9C8(p,4,32);func_0204B878(((struct Obj05415 *)p)->f8,18);func_021F4FF4(*(u32 *)&((struct Obj05415 *)p)->f8,144,40);func_0202CD64(((struct Obj05415 *)p)->f18,0,-4,0,4);((struct Obj05415 *)p)->f48=1;((struct Obj05415 *)p)->f4C=7;((struct Obj05415 *)p)->f38=-1;}

int func_021FAE2C(u8 *p)
{
    u32 sel = func_021F9A88(p, p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
            func_0204B878(((struct Obj00246 *)p)->f8, 19);
            ((struct Obj00246 *)p)->f48 = 8;
            ((struct Obj00246 *)p)->f38 = sel;
        }
    } else {
        func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
        func_0204B878(((struct Obj00246 *)p)->f8, func_0204B898(((struct Obj00246 *)p)->f8) + 9);
        ((struct Obj00246 *)p)->f48 = 3;
        ((struct Obj00246 *)p)->f4C = 8;
        ((struct Obj00246 *)p)->f38 = -1;
    }
    return -1;
}

int func_021FAE8C(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8)) return -1;
    func_021F9660(p, 4);
    func_0204B3DC(((struct Obj00098 *)p)->f8, 0);
    if (((struct Obj00098 *)p)->f38 >= 0) {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38][0] != 1)
            ((struct Obj00098 *)p)->f48 = 10;
        else {
            ((struct Obj00098 *)p)->f3A = 0;
            ((struct Obj00098 *)p)->f48 = 14;
        }
    } else return -2;
    return -1;
}

int func_021FAEE0(u8 *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(((struct Obj01160 *)p)->f18, 0, 96, 28, 1);
    func_0202CF84(((struct Obj01160 *)p)->f18, 0);
    func_021F9260(p, 4);
    func_021FBEB8(((struct Obj01160 *)p)->f18, ((struct Obj01160 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p + 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01160 *)p)->f20, i + 116);
        if (func_021FBFB0(p, i) == 1) {
            color = 0x3dc2;
            p[i + 96] = 1;
        } else {
            color = 0x2122;
            p[i + 96] = 0;
        }
        func_021FAC50(((struct Obj01160 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    func_0202CB4C(((struct Obj01160 *)p)->f18, 0, 16, 0);
    func_0202CC58(((struct Obj01160 *)p)->f18, 0);
    func_0204B878((struct Obj *)(((struct Obj01160 *)p)->f8), 18);
    func_021F4FF4(((struct Obj01160 *)p)->f8, (tbl_022032C6[*(s16 *)(p + 56)].x + 16) * 8, tbl_022032C6[*(s16 *)(p + 56)].y * 8);
    ((struct Obj01160 *)p)->f44 = ((struct Obj01160 *)p)->f38;
    func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    ((struct Obj01160 *)p)->f48 = 7;
    if (func_020355C4() == 1)
        func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 0);
    else
        func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    return -1;
}


int func_021FAFF0(Menu *m)
{
    int i;
    u16 color;

    i = 1;
    func_0202CAE4(m->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(m->mgr, 0);
    ov135_func_021F9260(m, 5);
    func_02082BCC(m->flags, 1, 0x1A);
    func_021FBE84(m->mgr, m->bank, m->wins[0], m->page + 0x74, 2, 0x3DC2, m->g);
    for (i = 1; i < tbl_022033F8[m->page].count + 1; i++) {
        if (func_021FBF6C(m, tbl_02203324[m->page] + i - 1) > 0) {
            color = 0x3DC2;
            m->flags[tbl_02203324[m->page] + i - 1] = 1;
        } else {
            color = 0x2122;
            m->flags[tbl_02203324[m->page] + i - 1] = 0;
        }
        func_021FBE84(m->mgr, m->bank, m->wins[i], tbl_02203440[i + tbl_022033F8[m->page].first - 1], 5, color, m->g);
    }
    func_021FBEB8(m->mgr, m->bank, m->wins[14], 0x4A, m->g);
    func_0202CB4C(m->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)m->cursor, 4);
    if (m->sel < 0) {
        m->pos = 0;
    } else {
        m->pos = m->sel;
    }
    func_021F4FF4(m->cursor, (tbl_022032C6[m->pos].x + 0x10) * 8, tbl_022032C6[m->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)m->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)m->cursor, 1);
    }
    m->state = 0xB;
    return -1;
}

int func_021FB164(u8 *p)
{
    int r;
    r = func_021F9CDC(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 12;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 12;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}

int func_021FB1E4(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,5);if(((struct Obj00098 *)p)->f3A>=0)*(u32 *)&((struct Obj00098 *)p)->f48=14;else *(u32 *)&((struct Obj00098 *)p)->f48=9;return -1; }


/*
 * State select before the notify call.
 */
int func_021FB220(u8 *p)
{
    u32 v;
    int n;

    if (func_020355C4() == 1) {
        v = ((struct Obj09235 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj09235 *)p)->f8;
        n = 1;
    }
    func_0204B3DC((struct Obj *)v, n);
    ((struct Obj09235 *)p)->f48 = 0xa;
    return -1;
}
