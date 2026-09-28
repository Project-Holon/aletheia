/*
 * function: func_021FA15C
 * address:  0x021FA15C
 * packet:   pkt_021FA15C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
 * symbols:
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_021F9A1C  0x021F9A1C  thumb
 */

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
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int pos;
} Obj;

extern const Cell tbl_0220320E[];
extern const int tbl_02203250[];

extern u32 func_020362DC(void);
extern int func_020355C4(void);
extern void func_0204B3DC(u32 obj, int on);
extern void func_020355D8(int v);
extern void func_020061E4(u32 se);
extern u32 func_0203633C(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(u32 v, int k);
extern int func_021F9A1C(Obj *p, int mode);

int func_021FA15C(Obj *p)
{
    int old = p->pos;
    int r;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 1);
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
            func_0204B878(p->cursor, 5);
        } else {
            func_0204B878(p->cursor, 6);
        }
    }
    r = func_021F9A1C(p, 1);
    if (r != -1) {
        func_020355D8(1);
        func_021F4FF4(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            func_0204B878(p->cursor, 5);
        } else {
            func_0204B878(p->cursor, 6);
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
        func_0204B878(p->cursor, 5);
        return -2;
    }
    return -1;
}
