/*
 * function: func_021F9A88
 * address:  0x021F9A88
 * packet:   pkt_021F9A88
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *   func_02034714  0x02034714  arm
 *   tbl_02203348   0x02203348  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 *
 * Cursor input for the ten-entry mode-4 menu: the mode-6 grid of nine
 * entries with one button (9). Returns the entry, -2 for cancel (B or
 * the button), -1 for nothing or an entry `enable` marks off. A grid
 * position past 9 under A reports through func_02034714 (raw address
 * 0x02203CEC, a plain constant as in func_02202B20).
 */

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

extern const Link tbl_02203348[];
extern const Cell tbl_022032C6[];

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(u32, u16);
extern int func_021F9A1C(void *p, int mode);
extern void func_02034714(const char *expr, u32 line, const char *file);

int func_021F9A88(Obj *p, u8 *enable)
{
    int old = p->pos;
    int r;
    int ret;

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
            func_0204B878(p->cursor, 5);
        } else {
            func_0204B878(p->cursor, 0x12);
        }
    }
    ret = -1;
    r = func_021F9A1C(p, 4);
    if (r != ret) {
        func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            func_0204B878(p->cursor, 5);
        } else {
            p->pos = r;
            func_0204B878(p->cursor, 0x12);
        }
        if (r == 9) {
            func_020061E4(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            ret = r;
        }
        if (ret == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)p->cursor, 0);
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
        func_0204B878(p->cursor, 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}
