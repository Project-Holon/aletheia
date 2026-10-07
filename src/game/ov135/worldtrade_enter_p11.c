/*
 * file:     worldtrade_enter_p11.c
 * unit:     yes
 * function: func_021F9FF0, func_021FA15C, func_021FA2B0
 * address:  0x021F9FF0
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
 *   func_021F9F58  0x021F9F58  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021F9F00  0x021F9F00  thumb
 *   tbl_02203220   0x02203220  data  a1
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   func_021F9EEC  0x021F9EEC  thumb
 *   func_0204B92C  0x0204B92C  arm
 *   func_021FB2F0  0x021FB2F0  thumb
 *   func_021FBF04  0x021FBF04  thumb
 */
struct Obj;
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
} Menu_021F9FF0;

typedef signed int s32;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int pos;
} Obj;

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
} Menu_021FA2B0;

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021F9F58(Menu_021F9FF0 *m, int dir);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021F9A1C(void *p, int mode);
extern int func_021F9F00(Menu_021F9FF0 *m, int key);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_0204B92C(struct Obj *v, u32 k);
extern void func_021FB2F0(Menu_021FA2B0 *m, int page, int total);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
int func_021F9FF0(Menu_021F9FF0 *m);
int func_021FA15C(Obj *p);
void func_021FA2B0(Menu_021FA2B0 *m, int dir);
extern const CurPos tbl_02203220[];
extern const Cell tbl_0220320E[];
extern const int tbl_02203250[];


int func_021F9FF0(Menu_021F9FF0 *m)
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
            m->cur = 4;
        }
    } else if (func_0203633C() & 0x80) {
        if (m->cur != 4) {
            m->cur = m->cur + 1;
        } else {
            m->cur = 0;
        }
    } else if (func_0203633C() & 0x20) {
        func_021F9F58(m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021F9F58(m, 1);
    }
    if (old != m->cur) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203220[m->cur].x, tbl_02203220[m->cur].y);
        if (m->cur == 4) {
            func_0204B878((struct Obj *)m->cursor, 5);
        } else {
            func_0204B878((struct Obj *)m->cursor, 6);
        }
    }
    r = func_021F9A1C(m, 0);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203220[r].x, tbl_02203220[r].y);
            if (r == 4) {
                func_0204B878((struct Obj *)m->cursor, 5);
            } else {
                m->cur = r;
                func_0204B878((struct Obj *)m->cursor, 6);
            }
        }
        r = func_021F9F00(m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021F9F00(m, m->cur);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)m->cursor, 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}


int func_021FA15C(Obj *p)
{
    int old = p->pos;
    int r;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (p->pos != 0) {
            p->pos = p->pos - 1;
        } else {
            p->pos = 3;
        }
    } else if (func_0203633C() & 0x80) {
        if (p->pos != 3) {
            p->pos = p->pos + 1;
        } else {
            p->pos = 0;
        }
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, tbl_0220320E[p->pos].x, tbl_0220320E[p->pos].y);
        if (p->pos == 3) {
            func_0204B878((struct Obj *)p->cursor, 5);
        } else {
            func_0204B878((struct Obj *)p->cursor, 6);
        }
    }
    r = func_021F9A1C(p, 1);
    if (r != -1) {
        func_020355D8(1);
        func_021F4FF4(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            func_0204B878((struct Obj *)p->cursor, 5);
        } else {
            func_0204B878((struct Obj *)p->cursor, 6);
        }
        r = tbl_02203250[r];
        if (r == -2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return r;
    }
    if (func_020362DC() & 1) {
        if (tbl_02203250[p->pos] == -2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return tbl_02203250[p->pos];
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)p->cursor, 5);
        return -2;
    }
    return -1;
}


void func_021FA2B0(Menu_021FA2B0 *m, int dir)
{
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->down, 1);
        func_0204B878((struct Obj *)m->down, 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = 2;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->up, 1);
        func_0204B878((struct Obj *)m->up, 0x26);
        if (m->page < 2) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0(m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}
