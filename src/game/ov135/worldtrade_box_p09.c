/*
 * file:     worldtrade_box_p09.c
 * unit:     yes
 * function: func_021F5E44, func_021F5F60, func_021F5F9C
 * address:  0x021F5E44
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
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   func_021F68A4  0x021F68A4  thumb
 *   tbl_02202D24  0x02202D24  data
 *   func_021F4FF4  0x021F4FF4  thumb
 */
struct Obj;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[0xC4];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xD2C - 0xBF8];
    u32 arrows[2];
} Work;

typedef struct {
    u16 x;
    u16 y;
} Pos;

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F68A4(Work *p, int box);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B84C(u32 obj, int k);
void func_021F5E44(Work *p);
void func_021F5F60(u32 cursor, int i);
int func_021F5F9C(int a, int b, int c);
extern const u8 tbl_02202DA4[][4];
extern const Pos tbl_02202D24[];


void func_021F5E44(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        func_020061E4(0x548);
        return;
    }
    if (func_020362DC() & 0x40) {
        dir = 1;
    } else if (func_020362DC() & 0x80) {
        dir = 2;
    } else if (func_020362DC() & 0x20) {
        dir = 3;
    } else if (func_020362DC() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                func_0204B92C((struct Obj *)p->arrows[k], 1);
                func_0204B878((struct Obj *)p->arrows[k], k + 0x26);
                p->box = func_021F5F9C(p->box, p->boxes, dir - 0x64);
                func_021F68A4(p, p->box);
                func_020061E4(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        func_020061E4(0x548);
    }
    func_021F5F60(p->cursor, p->slot);
}


void func_021F5F60(u32 cursor, int i)
{
    func_021F4FF4(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        func_0204B84C(cursor, 0);
    } else {
        func_0204B84C(cursor, 1);
    }
}

/*
 * Byte-index arithmetic with 0xff as the out-of-range marker.
 */
int func_021F5F9C(int a, int b, int c)
{
    if (a == 0xff) {
        if (c > 0) {
            return 0;
        }
        if (c < 0) {
            return b - 1;
        }
        return a;
    }
    a += c;
    if (a < 0) {
        return 0xff;
    }
    if (a == b) {
        return 0xff;
    }
    return a;
}
