/*
 * file:     worldtrade_enter_p03.c
 * unit:     yes
 * function: func_021FA7C4, func_021FA85C, func_021FA9C8, func_021FAAD4, func_021FAB70, func_021FAC50, func_021FAC84, func_021FAC8C, func_021FAD08, func_021FAD24, func_021FAD84, func_021FADA8, func_021FADF0, func_021FAE2C, func_021FAE8C, func_021FAEE0, func_021FAFF0, func_021FB164, func_021FB1E4, func_021FB220
 * address:  0x021FA7C4
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
 *   func_021F9EEC  0x021F9EEC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021FB364  0x021FB364  thumb
 *   func_021FBF04  0x021FBF04  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203633C  0x0203633C  arm
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021FA760  0x021FA760  thumb
 *   tbl_02203236   0x02203236  data  a1
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_02082BCC 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FC014 0x021FC014 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_021F87E0 0x021F87E0 thumb ov135
 *   func_021FB2F0 0x021FB2F0 thumb ov135
 *   tbl_02203220 0x02203220 data a1
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9A88 0x021F9A88 thumb ov135
 *   func_0204B898 0x0204B898 arm
 *   func_021F9660 0x021F9660 thumb ov135
 *   tbl_022033FC 0x022033FC data a4
 *   tbl_022032C6 0x022032C6 data a1
 *   ov135_func_021F9260  0x021F9260  thumb
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FBF6C  0x021FBF6C  thumb
 *   tbl_02203324   0x02203324  data
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 *   func_021F9CDC 0x021F9CDC thumb ov135
 */
#include "../../matched/include/Obj01744.h"
#include "../../matched/include/Obj03296.h"
#include "../../matched/include/Obj00474.h"
#include "../../matched/include/Obj01745.h"
#include "../../matched/include/Obj09234.h"
#include "../../matched/include/Obj03297.h"
#include "../../matched/include/Obj07245.h"
#include "../../matched/include/Obj05414.h"
#include "../../matched/include/Obj05415.h"
#include "../../matched/include/Obj00246.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj01160.h"
#include "../../matched/include/Obj00194.h"
#include "../../matched/include/Obj09235.h"

struct Obj;
struct WinMgr;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct Actor;
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
} Menu_021FA7C4;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int cur;
} Menu_021FA85C;

typedef signed int s32;

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

extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_020061E4(u32 se);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021FB364(Menu_021FA7C4 *m, int page, int total);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern int func_021F9A1C(void *p, int mode);
extern int func_021FA760(Menu_021FA85C *m, int key);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_02082BCC(void *, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern int func_021FC014(void *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021F87E0(void **, void *, int);
extern void func_021FB2F0(void *, int, int);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern u32 func_021F9A88(void *, void *);
extern u16 func_0204B898(struct Obj *p);
extern void func_021F9660(void *, int);
extern void ov135_func_021F9260(Menu *m, u32 mode);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FBF6C(Menu *m, u32 idx);
extern int func_021F9CDC(void *p, u8 *flags);
void func_021FA7C4(Menu_021FA7C4 *m, int dir);
int func_021FA85C(Menu_021FA85C *m);
void func_021FA9C8(u8 *p, int mode, int pos);
void func_021FAAD4(u8 *p);
void func_021FAB70(u8 *p);
void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
int func_021FAC84(void);
int func_021FAC8C(u8 *p);
int func_021FAD08(u8 *p);
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
extern const CurPos tbl_02203236[];
extern const CurPos tbl_02203220[];
extern const int tbl_022033FC[][2];
extern const CurPos tbl_022032C6[];
extern const int tbl_02203324[];
extern const Range tbl_022033F8[];
extern const u32 tbl_02203440[];




void func_021FA7C4(Menu_021FA7C4 *m, int dir)
{
    int last;

    last = func_021F9EEC((u8 *)m->total, 5) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->down, 1);
        func_0204B878((struct Obj *)m->down, 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->up, 1);
        func_0204B878((struct Obj *)m->up, 0x26);
        if (m->page < last) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB364((Menu_021FA7C4 *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[5], m->page, func_021F9EEC((u8 *)m->total, 5));
}





int func_021FA85C(Menu_021FA85C *m)
{
    int old;
    int r;

    old = m->cur;
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)m->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (m->cur != 0) {
            m->cur = m->cur - 1;
        } else {
            m->cur = 5;
        }
    } else if (func_0203633C() & 0x80) {
        if (m->cur != 5) {
            m->cur = m->cur + 1;
        } else {
            m->cur = 0;
        }
    } else if (func_0203633C() & 0x20) {
        func_021FA7C4((Menu_021FA7C4 *)m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021FA7C4((Menu_021FA7C4 *)m, 1);
    }
    if (old != m->cur) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203236[m->cur].x, tbl_02203236[m->cur].y);
        if (m->cur == 5) {
            func_0204B878((struct Obj *)m->cursor, 5);
        } else {
            func_0204B878((struct Obj *)m->cursor, 7);
        }
    }
    r = func_021F9A1C(m, 3);
    if (r != -1) {
        if ((u32)r < 6) {
            func_021F4FF4(m->cursor, tbl_02203236[r].x, tbl_02203236[r].y);
            if (r == 5) {
                func_0204B878((struct Obj *)m->cursor, 5);
            } else {
                m->cur = r;
                func_0204B878((struct Obj *)m->cursor, 7);
            }
        }
        r = func_021FA760((Menu_021FA85C *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA760((Menu_021FA85C *)m, m->cur);
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)m->cursor, 5);
        return -2;
    }
    return -1;
}




void func_021FA9C8(u8 *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(((struct Obj01744 *)p)->f18, 0, 96, mode == 6 ? 27 : 28, 1);
    func_0202CF84(((struct Obj01744 *)p)->f18, 0);
    func_021F9260(p, mode);
    func_021FBEB8(((struct Obj01744 *)p)->f18, ((struct Obj01744 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, i + 116);
        if (mode == 4) {
            if (func_021FBFB0(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        } else {
            if (func_021FC014(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        }
        func_021FAC50(((struct Obj01744 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    if (mode == 6) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, 188);
        func_021FAC50(((struct Obj01744 *)p)->f18, (*(void ***)p)[15], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_0202CB4C(((struct Obj01744 *)p)->f18, 0, pos, 0);
    func_0202CC58(((struct Obj01744 *)p)->f18, 0);
}



void func_021FAAD4(u8 *p)
{
    int i;
    void *str;
    func_0202CAE4(((struct Obj03296 *)p)->f18, 0, 96, 25, 1);
    func_0202CF84(((struct Obj03296 *)p)->f18, 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(((struct Obj03296 *)p)->f20, i + 130);
        func_021FAC50(((struct Obj03296 *)p)->f18, (*(void ***)p)[i], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_021FBEB8(((struct Obj03296 *)p)->f18, ((struct Obj03296 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj03296 *)p)->f18, 0, 32, 0);
    func_0202CC58(((struct Obj03296 *)p)->f18, 0);
    func_0202CD64(((struct Obj03296 *)p)->f18, 0, -4, 0, 4);
}



void func_021FAB70(u8 *p)
{
    func_0202CAE4(((struct Obj00474 *)p)->f18, 0, 96, 29, 1);
    func_0202CF84(((struct Obj00474 *)p)->f18, 0);
    func_021F9260(p, 2);
    if (((struct Obj00474 *)p)->f5C == 1)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 1);
    else if (((struct Obj00474 *)p)->f5C == 0)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 0);
    func_021FB2F0(p, 0, ((struct Obj00474 *)p)->f58);
    ((struct Obj00474 *)p)->f56 = 0;
    func_021FBF04(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f34, (*(void ***)p)[4], ((struct Obj00474 *)p)->f56, func_021F9EEC((u8 *)(((struct Obj00474 *)p)->f58), 4));
    func_021FBEB8(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj00474 *)p)->f18, 0, 32, 0);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    ((struct Obj00474 *)p)->f7A = 0;
    *(int *)&((struct Obj00474 *)p)->f44 = 0;
    func_021F4FF4(((struct Obj00474 *)p)->f8, tbl_02203220[*(int *)(p + 68)].x, tbl_02203220[*(int *)(p + 68)].y);
    func_0202CC58(((struct Obj00474 *)p)->f18, 0);
    func_0202CD64(((struct Obj00474 *)p)->f18, 0, -4, 0, 4);
    *(int *)&((struct Obj00474 *)p)->f48 = 34;
}




void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    func_022028C8(win, 0, str, x, 0, 0, color, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
}



int func_021FAC84(void)
{
    return -1;
}



/*
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 */
int func_021FAC8C(u8 *p)
{
    if (!func_0202CE40(*(struct WinMgr * *)&((struct Obj01745 *)p)->f18, 0)) {
        if (func_020355C4() == 1)
            func_0204B3DC(((struct Obj01745 *)p)->f8, 0);
        else
            func_0204B3DC(((struct Obj01745 *)p)->f8, 1);
        if (((struct Obj01745 *)p)->f54 == 2) {
            func_0204B92C(((struct Obj01745 *)p)->fC, 0);
            func_0204B92C(((struct Obj01745 *)p)->f10, 0);
            func_0204B878(((struct Obj01745 *)p)->fC, 38);
            func_0204B878(((struct Obj01745 *)p)->f10, 39);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->fC, 228, 120);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->f10, 154, 120);
            func_0204B3DC(((struct Obj01745 *)p)->fC, 1);
            func_0204B3DC(((struct Obj01745 *)p)->f10, 1);
        }
        ((struct Obj01745 *)p)->f48 = ((struct Obj01745 *)p)->f4C;
    }
    return -1;
}




/*
 * Flush the queued value when the probe reports empty, then answer -1.
 */
int func_021FAD08(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj09234 *)p)->f18, 0) == 0) {
        ((struct Obj09234 *)p)->f48 = ((struct Obj09234 *)p)->f4C;
    }
    return -1;
}


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
