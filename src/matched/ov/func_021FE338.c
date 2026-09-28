/*
 * function: func_021FE338
 * address:  0x021FE338
 * packet:   pkt_021FE338
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FE254  0x021FE254  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_021FEAE0  0x021FEAE0  thumb
 *   func_021FE9B0  0x021FE9B0  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_021F7B9C  0x021F7B9C  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021FF4D0  0x021FF4D0  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_021FE9DC  0x021FE9DC  thumb
 *   tbl_02203D46   0x02203D46  data  a2
 *
 * Menu input handler. A touch on an entry (func_021FE254) selects it and
 * acts at once; otherwise the d-pad moves the cursor (func_021FE9DC) and A
 * acts on the current entry, B jumps to the last entry of page 1. Entry 1
 * hands the +0xB56 record to func_021F7B9C, entry 5 compares the two
 * records, entry 4 depends on the +0xD0 word; every path picks the next
 * state (+0x28) and a sound. Always returns 2.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
    u16 anim2;
} CurPos;

typedef struct {
    s16 a;
    s8 b;
    s8 c;
    s8 d;
    s8 pad;
} Rec;

typedef struct {
    u8 pad0[0x20];
    u32 f20;
    int page;
    int row0;
    int row1;
} State;

typedef struct {
    u8 pad0[0x28];
    int next;
    u8 pad2C[0xD0 - 0x2C];
    u32 fD0;
    u8 padD4[0xB56 - 0xD4];
    Rec rec[2];
    u16 padB62;
    u32 fB64;
    u8 padB68[0xBF4 - 0xB68];
    u32 cursor;
    u8 padBF8[0xE00 - 0xBF8];
    State *st;
    u8 padE04[0xF84 - 0xE04];
    u32 fF84;
} Work;

extern const CurPos tbl_02203D46[];

extern int func_021FE254(void);
extern void func_020355D8(int v);
extern void func_021FEAE0(Work *p, int i);
extern int func_021FE9B0(Work *p);
extern u32 func_0201ADE4(u16 a, u16 b, u16 heap);
extern u32 func_0201AE1C(u32 h, u32 k);
extern void func_0201AE14(u32 h);
extern int func_021F7B9C(Rec *p, u32 event);
extern void func_0204B3DC(u32, int);
extern void func_0204B878(u32, u16);
extern void func_020061E4(u32 se);
extern int func_021FF4D0(Rec *x, Rec *y, u32 m, u32 n);
extern u32 func_020362DC(void);
extern int func_020355C4(void);
extern void func_021FE9DC(Work *p);

int func_021FE338(Work *p)
{
    int sel = func_021FE254();

    if (sel != -1) {
        func_020355D8(1);
        func_021FEAE0(p, sel);
        sel = func_021FE9B0(p);
        switch (sel) {
        case 1:
            if (p->rec[0].a != 0) {
                u32 h = func_0201ADE4(p->rec[0].a, 0, 0x48);
                u32 v = func_0201AE1C(h, 0x14);
                func_0201AE14(h);
                p->st->f20 = v;
                if (func_021F7B9C(&p->rec[0], p->st->f20) != 0) {
                    func_0204B3DC(p->cursor, 1);
                    func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    func_020061E4(0x557);
                    return 2;
                }
            }
            func_0204B3DC(p->cursor, 1);
            func_020061E4(0x54C);
            func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        case 5:
            if (p->rec[0].a == 0 || func_021FF4D0(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                func_020061E4(0x557);
            } else {
                func_020061E4(0x54C);
            }
            func_0204B3DC(p->cursor, 1);
            func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        case 4:
            if (p->fD0 != 0) {
                func_0204B3DC(p->cursor, 1);
                func_020061E4(0x54C);
                func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
            } else {
                func_0204B3DC(p->cursor, 1);
                func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                func_020061E4(0x557);
                p->next = 0x25;
            }
            break;
        default:
            func_0204B3DC(p->cursor, 1);
            if (sel == 6) {
                func_020061E4(0x551);
            } else {
                func_020061E4(0x54C);
            }
            func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x23;
            break;
        }
    } else if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return 2;
    } else {
        func_021FE9DC(p);
        if (func_020362DC() & 1) {
            sel = func_021FE9B0(p);
            switch (sel) {
            case 1:
                if (p->rec[0].a != 0) {
                    u32 h = func_0201ADE4(p->rec[0].a, 0, 0x48);
                    u32 v = func_0201AE1C(h, 0x14);
                    func_0201AE14(h);
                    p->st->f20 = v;
                    if (func_021F7B9C(&p->rec[0], p->st->f20) != 0) {
                        func_0204B3DC(p->cursor, 1);
                        func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                        func_020061E4(0x557);
                        return 2;
                    }
                }
                func_0204B3DC(p->cursor, 1);
                func_020061E4(0x54C);
                func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            case 5:
                if (p->rec[0].a == 0 || func_021FF4D0(&p->rec[0], &p->rec[1], p->fF84, p->fB64) != 0) {
                    func_020061E4(0x557);
                } else {
                    func_020061E4(0x54C);
                }
                func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            case 4:
                if (p->fD0 != 0) {
                    func_020061E4(0x54C);
                    func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    p->next = 0x23;
                } else {
                    func_0204B3DC(p->cursor, 1);
                    func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                    func_020061E4(0x557);
                    p->next = 0x25;
                }
                break;
            default:
                if (sel == 6) {
                    func_020061E4(0x551);
                } else {
                    func_020061E4(0x54C);
                }
                func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
                p->next = 0x23;
                break;
            }
        } else if (func_020362DC() & 2) {
            p->st->page = 1;
            p->st->row1 = 2;
            func_0204B878(p->cursor, tbl_02203D46[func_021FE9B0(p)].anim2);
            p->next = 0x24;
            func_020061E4(0x551);
        }
    }
    return 2;
}
