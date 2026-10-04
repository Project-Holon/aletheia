/*
 * function: func_021FA394
 * address:  0x021FA394
 * packet:   pkt_021FA394
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
 *   func_021FA2B0  0x021FA2B0  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021FA330  0x021FA330  thumb
 *   tbl_02203216   0x02203216  data  a1
 */

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

extern const CurPos tbl_02203216[];

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_021FA2B0(Menu *m, int dir);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(u32 v, int k);
extern int func_021F9A1C(void *p, int mode);
extern int func_021FA330(Menu *m, int key);

int func_021FA394(Menu *m)
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
        func_021FA2B0(m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021FA2B0(m, 1);
    }
    if (old != m->cur) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203216[m->cur].x, tbl_02203216[m->cur].y);
        if (m->cur == 4) {
            func_0204B878(m->cursor, 5);
        } else {
            func_0204B878(m->cursor, 6);
        }
    }
    r = func_021F9A1C(m, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                func_0204B878(m->cursor, 5);
            } else {
                m->cur = r;
                func_0204B878(m->cursor, 6);
            }
        }
        r = func_021FA330(m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA330(m, m->cur);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878(m->cursor, 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}
