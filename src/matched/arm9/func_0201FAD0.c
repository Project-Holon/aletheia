/*
 * function: func_0201FAD0
 * address:  0x0201FAD0
 * packet:   pkt_0201FA04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201FB30  0x0201FB30  thumb
 *   func_0201FD54  0x0201FD54  thumb
 *   func_0201FD18  0x0201FD18  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020061E4  0x020061E4  thumb
 *
 * Commit a cursor move: remember where the cursor was, ask func_0201FB30 to
 * step it, and on a refusal answer 0 without side effects.  On a move, redraw
 * from the old cell through func_0201FD54 into an on-stack pair, repaint at
 * the new position with func_02043AF4 and play the sound id the caller passed
 * in r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201FAD0.c \
 *       --func func_0201FAD0 --addr 0x0201FAD0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Obj {
    u32 f00;
    u32 f04;
    u8  pad_08[0x25];
    u8  f2D;
    u8  pad_2E[3];
    u8  f31;
    u8  f32;
};

extern int  func_0201FB30(struct Obj *o, u32 dir);
extern void func_0201FD54(struct Obj *o, u8 *outA, u8 *outB, u32 old);
extern void func_0201FD18(struct Obj *o);
extern u32  func_02045770(u32 p);
extern void func_02043AF4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020061E4(u32 id);

int func_0201FAD0(struct Obj *o, u32 dir, u32 sound)
{
    u8 cell[2];
    u8 old;

    old = o->f2D;
    if (func_0201FB30(o, dir) == 0) {
        return 0;
    }

    func_0201FD54(o, &cell[1], &cell[0], old);
    func_02043AF4(func_02045770(o->f04), cell[1], cell[0], o->f31,
                  o->f32, 0xff);
    func_0201FD18(o);
    func_020061E4(sound);
    return 1;
}
