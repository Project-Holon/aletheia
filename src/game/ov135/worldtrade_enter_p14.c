/*
 * file:     worldtrade_enter_p14.c
 * unit:     yes
 * function: func_021FA85C, func_021FA9C8
 * address:  0x021FA85C
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
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   func_021FA7C4  0x021FA7C4  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
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
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 */
#include "../../matched/include/Obj01744.h"

struct Obj;
struct WinMgr;
struct MsgBank;
struct U16Vec;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int cur;
} Menu;

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021FA7C4(Menu *m, int dir);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021F9A1C(void *p, int mode);
extern int func_021FA760(Menu *m, int key);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_02082BCC(void *, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern int func_021FC014(void *, int);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
int func_021FA85C(Menu *m);
void func_021FA9C8(u8 *p, int mode, int pos);
extern const CurPos tbl_02203236[];


int func_021FA85C(Menu *m)
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
        func_021FA7C4(m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021FA7C4(m, 1);
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
        r = func_021FA760(m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA760(m, m->cur);
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
