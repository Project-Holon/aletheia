/*
 * file:     worldtrade_enter_p09.c
 * unit:     yes
 * function: func_021F99F0, func_021F9A1C, func_021F9A88
 * address:  0x021F99F0
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
 *   tbl_02203C48  0x02203C48  data  a4
 *   func_02202770  0x02202770  thumb
 *   func_022029F8  0x022029F8  thumb
 *   func_02035C08  0x02035C08  arm
 *   tbl_02203370   0x02203370  data  a1
 *   tbl_022033C8   0x022033C8  data  a1
 *   tbl_022032DE   0x022032DE  data  a1
 *   tbl_02203270   0x02203270  data  a1
 *   tbl_022032FE   0x022032FE  data  a1
 *   tbl_02203284   0x02203284  data  a1
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_02034714  0x02034714  arm
 *   tbl_02203348   0x02203348  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 */
struct WinMgr;
struct Obj_021F9A88;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct Obj_021F99F0 Obj_021F99F0;

struct Obj_021F99F0 {
    u8 pad0[0x18];
    void *mgr;
    u8 pad1C[0x34 - 0x1C];
    void *printer;
    u8 pad38[0x48 - 0x38];
    int state;
    u8 pad4C[0x7C - 0x4C];
    u8 g[4];
};

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
} Obj_021F9A88;

extern void func_0202CD94(struct WinMgr *mgr);
extern void func_02202770(void *g);
extern void func_022029F8(void *printer);
extern int func_02035C08(const void *p);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj_021F9A88 *, unsigned int);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj_021F9A88 *p, u16 value);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_021F99F0(Obj_021F99F0 *p);
int func_021F9A1C(void *p, int mode);
int func_021F9A88(Obj_021F9A88 *p, u8 *enable);
extern u8 tbl_02203370[];
extern u8 tbl_022033C8[];
extern u8 tbl_022032DE[];
extern u8 tbl_02203270[];
extern u8 tbl_022032FE[];
extern u8 tbl_02203284[];
extern const Link tbl_02203348[];
extern const Cell tbl_022032C6[];

extern int (*const tbl_02203C48[])(Obj_021F99F0 *p);


int func_021F99F0(Obj_021F99F0 *p)
{
    int r = tbl_02203C48[p->state](p);

    func_0202CD94(p->mgr);
    func_02202770(p->g);
    func_022029F8(p->printer);
    return r;
}


/*
 * Touch hit test against the rectangle table of screen mode `mode`
 * (0..7; modes 0/2 and 5/7 share a table). Any other mode falls off the
 * end and hands back the first argument still in r0.
 */
int func_021F9A1C(void *p, int mode)
{
    switch (mode) {
    case 4:
        return func_02035C08(tbl_02203370);
    case 6:
        return func_02035C08(tbl_022033C8);
    case 0:
    case 2:
        return func_02035C08(tbl_022032DE);
    case 1:
        return func_02035C08(tbl_02203270);
    case 3:
        return func_02035C08(tbl_022032FE);
    case 5:
    case 7:
        return func_02035C08(tbl_02203284);
    }
}


/*
 * Cursor input for the ten-entry mode-4 menu: the mode-6 grid of nine
 * entries with one button (9). Returns the entry, -2 for cancel (B or
 * the button), -1 for nothing or an entry `enable` marks off. A grid
 * position past 9 under A reports through func_02034714 (raw address
 * 0x02203CEC, a plain constant as in func_02202B20).
 */
int func_021F9A88(Obj_021F9A88 *p, u8 *enable)
{
    int old = p->pos;
    int r;
    int ret;

    if (old < 9) {
        p->last = old;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj_021F9A88 *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        p->pos = tbl_02203348[p->pos].up;
    } else if (func_0203633C() & 0x80) {
        p->pos = tbl_02203348[p->pos].down;
    } else if (func_0203633C() & 0x20) {
        p->pos = tbl_02203348[p->pos].left;
    } else if (func_0203633C() & 0x10) {
        p->pos = tbl_02203348[p->pos].right;
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
        func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
        if (p->pos == 9) {
            func_0204B878((struct Obj_021F9A88 *)p->cursor, 5);
        } else {
            func_0204B878((struct Obj_021F9A88 *)p->cursor, 0x12);
        }
    }
    ret = -1;
    r = func_021F9A1C(p, 4);
    if (r != ret) {
        func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            func_0204B878((struct Obj_021F9A88 *)p->cursor, 5);
        } else {
            p->pos = r;
            func_0204B878((struct Obj_021F9A88 *)p->cursor, 0x12);
        }
        if (r == 9) {
            func_020061E4(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            ret = r;
        }
        if (ret == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj_021F9A88 *)p->cursor, 0);
        }
        func_020355D8(1);
        return ret;
    }
    if (func_020362DC() & 1) {
        if (p->pos == 9) {
            func_020061E4(0x551);
            return -2;
        }
        if (p->pos >= 9) {
            func_02034714((void *)0x02203CEC, 0, (void *)0x02203CEC);
        }
        if (enable == 0 || enable[p->pos] != 0) {
            func_020061E4(0x54C);
            return p->pos;
        }
    } else if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_0204B878((struct Obj_021F9A88 *)p->cursor, 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}
