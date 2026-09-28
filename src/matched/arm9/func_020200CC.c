/*
 * function: func_020200CC
 * address:  0x020200CC
 * packet:   pkt_020200CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02020970  0x02020970  thumb
 *
 * The per-frame key handler of the menu-cursor object built by
 * func_0201FF30: same shape as func_0201FA04 one block down, over the wider
 * struct that unit_020206C0.c already spells out.  Sound ids 0x54C / 0x551 /
 * 0x548 sit in the trailing pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020200CC.c \
 *       --func func_020200CC --addr 0x020200CC --thumb
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/func_020200CC.c.txt,
 * 81 bytes out).  The note read the residue as an allocator choice (`tst`
 * versus a copy and `ands`); it was a misread of the image.  In the
 * f1Amid == 2 arm the masks are derived from the 0x80 still live in r2:
 * `lsls r1, r2, #2` is 0x200 and `adds r2, #0x80` is 0x100, so the arm reads
 * the L and R shoulder buttons (0x200, 0x100), not up/down (0x40, 0x80).
 * With the right constants the 0x40 test becomes a plain `tst` by itself,
 * and the switch closes once case 0 and default share one arm.
 * func_02020970's prototype is the EXACT one (u8 scalar parameters).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Elem {
    void *unk00;
    s32   f4;
};

struct Obj {
    struct Elem *arr;
    u8  pad_04[0x12 - 0x04];
    u16 f12;
    u8  pad_14[0x1A - 0x14];
    u16 f1Alo : 7;
    u16 f1Amid : 2;
    u16 f1Atop : 7;
    u8  pad_1C[0x40 - 0x1C];
    u16 f40;
    u16 f42;
    u8  pad_44[3];
    u8  f47;
    u8  pad_48[2];
    u8  f4A;
};

extern u32  func_020362DC(void);
extern u32  func_0203633C(void);
extern void func_020061E4(u32 id);
extern u32  func_02020970(struct Obj *o, u8 a, u8 b, u8 c);

s32 func_020200CC(struct Obj *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;
    u32 held = func_0203633C();

    o->f47 = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->arr[o->f40 + o->f42].f4;
    }
    if (o->f4A == 0) {
        u32 two = 2;
        if (keys & two) {
            func_020061E4(0x551);
            return two - 4;
        }
    }
    if (held & 0x40) {
        if (func_02020970(o, 1, 1, 0) == 0) {
            func_020061E4(0x548);
            o->f47 = 1;
        }
        return -1;
    }
    if (held & 0x80) {
        if (func_02020970(o, 1, 1, 1) == 0) {
            func_020061E4(0x548);
            o->f47 = 2;
        }
        return -1;
    }
    {
        u16 h, v;
        switch (o->f1Amid) {
        case 0:
        default:
            h = 0;
            v = 0;
            break;
        case 1:
            h = (u16)(held & 0x20);
            v = (u16)(held & 0x10);
            break;
        case 2:
            h = (u16)(held & 0x200);
            v = (u16)(held & 0x100);
            break;
        }
        if (h != 0) {
            if (func_02020970(o, 1, (u8)o->f12, 0) == 0) {
                func_020061E4(0x548);
                o->f47 = 3;
            }
            return -1;
        }
        if (v != 0) {
            if (func_02020970(o, 1, (u8)o->f12, 1) == 0) {
                func_020061E4(0x548);
                o->f47 = 4;
            }
            return -1;
        }
    }
    return -1;
}
