/*
 * file:     bmp_menu_p04.c
 * unit:     yes
 * function: func_0201F9D0, func_0201F9E8, func_0201FA04
 * address:  0x0201F9D0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F93C  0x0201F93C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201FAD0  0x0201FAD0  thumb
 */
#include "../../matched/include/Obj02993.h"

struct Obj;
struct D;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

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

extern void func_0201F93C(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f);
extern void func_02020D3C(struct D *p);
extern u32 func_020307B0(void *p);
extern u32  func_020362DC(void);
extern void func_020061E4(u32 id);
extern int  func_0201FAD0(struct Obj *o, u32 dir, u32 sound);
void func_0201F9D0(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f);


/*
 * A pass-through onto func_0201F93C: the four register arguments are never
 * touched and only the two stacked ones are copied down into the new frame.
 * The fifth is a halfword and needs `add r4, sp, #0x10` + `ldrh` because
 * Thumb has no halfword load with an sp base; the sixth is a word and loads
 * directly.
 *
 * Blocked on the `label` class: 0x0201F93C has no branch reference anywhere
 * in the image except the one in this function, and the range cannot be cut
 * smaller than the single function, so no witness exists.  0x0201F93C is a
 * 148-byte constructor (debug allocator at 0x02030734, 0x38 bytes, line 97,
 * a nine-word ldm/stm copy of the caller's descriptor, then func_0201FC1C)
 * and was not attempted in wave 20B for budget reasons, not for difficulty.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F9D0.c \
 *       --func func_0201F9D0 --addr 0x0201F9D0 --cc 1.1p1 --thumb
 */
void func_0201F9D0(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f)
{
    func_0201F93C(a, b, c, d, e, f);
}



void func_0201F9E8(struct Obj *o, u8 *out)
{
    if (out != 0) {
        *out = ((struct Obj02993 *)o)->f2D;
    }
    func_02020D3C((struct D *)(((struct Obj02993 *)o)->f24));
    func_020307B0(o);
}


/*
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
u32 func_0201FA04(struct Obj *o)
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
