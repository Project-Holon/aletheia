/*
 * unit:     no
 * function: sub_02046180
 * address:  0x02046180
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020461B8  0x020461B8  arm
 *   sub_02046110  0x02046110  arm
 *
 * Re-read the clamped index for the header at +0 and, if it moved, record
 * it at +0x1a and redraw through sub_02046110 when the enable byte at +0x1b
 * says so.
 *
 * The two guards do not share an exit: the first `popeq` returns from the
 * comparison itself and the second `popne` from the enable test, which is
 * what a plain chain of early returns compiles to.  The enable byte is read
 * one instruction before the store to +0x1a: both are separate fields of
 * the same struct, so the compiler is free to schedule the load first and
 * does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046180.c \
 *       --func sub_02046180 --addr 0x02046180 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Header {
    u8 unk_00[1];
};

struct Obj {
    struct Header *header;
    u8             pad_04[0x16];
    u8             index;
    u8             enabled;
};

extern s32  sub_020461B8(struct Header *h);
struct MsgData;
extern void sub_02046110(struct MsgData *msg);

void sub_02046180(struct Obj *o)
{
    s32 index = sub_020461B8(o->header);

    if (o->index == index) {
        return;
    }
    if (o->enabled != 1) {
        o->index = (u8)index;
        return;
    }
    o->index = (u8)index;
    sub_02046110((struct MsgData *)o);
}
