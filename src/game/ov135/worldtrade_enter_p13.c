/*
 * file:     worldtrade_enter_p13.c
 * unit:     yes
 * function: func_021FA514, func_021FA760
 * address:  0x021FA514
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
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021FA4FC  0x021FA4FC  thumb
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *   func_021FA7C4  0x021FA7C4  thumb
 */
struct Obj;
typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 up;
    u8 down;
    u8 left;
    u8 right;
} Link;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int pos;
    u8 pad48[0x7A - 0x48];
    u8 last;
} Obj;

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

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021F9A1C(void *p, int mode);
extern int func_021FA4FC(int unused, int mode);
extern void func_021FA7C4(Menu *m, int dir);
int func_021FA514(Obj *p, u8 *enable);
int func_021FA760(Menu *m, int key);
extern const Link tbl_0220339C[];
extern const Cell tbl_02203298[];


/*
 * Cursor input for the eleven-entry mode-6 menu: a 3-column grid of nine
 * entries plus two buttons (9, 10). Leaving a button with up or down
 * returns to the last grid entry (+0x7A) moved to the bottom or top row.
 * A touch (func_021F9A1C) or A selects. Returns the entry, -2 for cancel
 * (B or entry 9), -1 for nothing or a grid entry `enable` marks off.
 */
int func_021FA514(Obj *p, u8 *enable)
{
    int old = p->pos;
    int r;

    if (old < 9) {
        p->last = old;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        p->pos = tbl_0220339C[p->pos].up;
    } else if (func_0203633C() & 0x80) {
        p->pos = tbl_0220339C[p->pos].down;
    } else if (func_0203633C() & 0x20) {
        p->pos = tbl_0220339C[p->pos].left;
    } else if (func_0203633C() & 0x10) {
        p->pos = tbl_0220339C[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (func_0203633C() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (func_0203633C() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, (tbl_02203298[p->pos].x + 0x10) * 8, tbl_02203298[p->pos].y * 8);
        switch (p->pos) {
        case 9:
            func_0204B878((struct Obj *)p->cursor, 5);
            break;
        case 10:
            func_0204B878((struct Obj *)p->cursor, 6);
            break;
        default:
            func_0204B878((struct Obj *)p->cursor, 0x12);
            break;
        }
    }
    r = func_021F9A1C(p, 6);
    if (r != -1) {
        func_021F4FF4(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            func_0204B878((struct Obj *)p->cursor, 5);
            break;
        case 10:
            func_0204B878((struct Obj *)p->cursor, 6);
            break;
        default:
            func_0204B878((struct Obj *)p->cursor, 0x12);
            p->pos = r;
            break;
        }
        r = func_021FA4FC((int)p, r);
        if (r == -2) {
            func_020061E4(0x551);
        } else if (r == 10 || enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
        } else {
            r = -1;
        }
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)p->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        r = func_021FA4FC((int)p, p->pos);
        if (r == -2) {
            func_020061E4(0x551);
            return r;
        }
        if (r == 10 || enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            return r;
        }
    } else if (func_020362DC() & 2) {
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)p->cursor, 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}


int func_021FA760(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 5:
        func_020061E4(0x551);
        return -2;
    case 6:
        func_021FA7C4(m, -1);
        return -1;
    case 7:
        func_021FA7C4(m, 1);
        return -1;
    }
    idx = key + m->page * 5;
    if (idx < m->total) {
        func_020061E4(0x54C);
        return m->items[idx].val;
    }
    return -1;
}
