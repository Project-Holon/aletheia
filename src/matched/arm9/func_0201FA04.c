/*
 * function: func_0201FA04
 * address:  0x0201FA04
 * packet:   pkt_0201FA04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201FAD0  0x0201FAD0  thumb
 *
 * The menu's per-frame input step.  Field +0x33 is cleared first and holds
 * the direction that was accepted this frame (1..4).  A is a confirm: it
 * plays 0x54C and answers the selected entry's second word.  Any bit in the
 * caller-supplied cancel mask at +0x28 plays 0x551 and answers -2.  The four
 * direction bits each ask func_0201FAD0 to move the cursor with its own
 * sound id; a successful move records the direction at +0x33.  Every
 * direction path answers -1, and a frame with nothing pressed answers -1 as
 * well, spelled off the last mask constant so it costs no extra byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201FA04.c \
 *       --func func_0201FA04 --addr 0x0201FA04 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct Elem {
    u32 f0;
    s32 f4;
};

struct Obj {
    struct Elem *arr;
    u8  pad_04[0x24];
    u32 cancel_mask;
    u8  pad_2C;
    u8  cursor;
    u8  pad_2E[5];
    u8  last_dir;
};

extern u32  func_020362DC(void);
extern void func_020061E4(u32 id);
extern int  func_0201FAD0(struct Obj *o, u32 dir, u32 sound);

s32 func_0201FA04(struct Obj *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;

    o->last_dir = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->arr[o->cursor].f4;
    }
    if (keys & o->cancel_mask) {
        func_020061E4(0x551);
        return one - 3;
    }
    if (keys & 0x40) {
        if (func_0201FAD0(o, 0, 0x548) == 1) {
            o->last_dir = (u8)one;
        }
        return -1;
    }
    if (keys & 0x80) {
        if (func_0201FAD0(o, one, 0x548) == 1) {
            o->last_dir = 2;
        }
        return -1;
    }
    if (keys & 0x20) {
        if (func_0201FAD0(o, 2, 0x548) == 1) {
            o->last_dir = 3;
        }
        return -1;
    }
    if (keys & 0x10) {
        if (func_0201FAD0(o, 3, 0x548) == 1) {
            o->last_dir = 4;
        }
        return -1;
    }
    return 0x10 - 0x11;
}
