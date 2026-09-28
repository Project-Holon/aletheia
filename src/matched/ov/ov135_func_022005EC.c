/*
 * function: func_022005EC
 * address:  0x022005EC
 * packet:   pkt_022005EC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220052C  0x0220052C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   tbl_022038E0   0x022038E0  data  a2
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0xC0 - 0x2C];
    u16 sel;
    u8 padC2[0xBF4 - 0xC2];
    u32 cursor;
} Work;

extern const Pos tbl_022038E0[];

extern int func_0220052C(void);
extern void func_020061E4(u32 se);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B3DC(u32 v, int k);
extern void func_0204B878(u32 v, int k);
extern void func_020355D8(int v);
extern u32 func_020362DC(void);
extern int func_020355C4(void);
extern void func_0204B9A0(u32 v);

int func_022005EC(Work *p)
{
    int r;

    r = func_0220052C();
    if (r != -1) {
        p->sel = r;
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC(p->cursor, 1);
        func_0204B878(p->cursor, 1);
        p->state = 0xE;
        func_020355D8(1);
        if (p->sel == 2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return 2;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return 2;
    }
    if (func_020362DC() & 2) {
        p->sel = 2;
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC(p->cursor, 1);
        func_0204B878(p->cursor, 1);
        p->state = 0xE;
        func_020061E4(0x551);
    } else if (func_020362DC() & 1) {
        func_0204B3DC(p->cursor, 1);
        func_0204B878(p->cursor, 1);
        p->state = 0xE;
        func_020061E4(0x54C);
    } else if (func_020362DC() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            func_020061E4(0x548);
            func_0204B3DC(p->cursor, 1);
            func_0204B9A0(p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (func_020362DC() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            func_020061E4(0x548);
            func_0204B3DC(p->cursor, 1);
            func_0204B9A0(p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}
