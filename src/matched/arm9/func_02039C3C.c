/*
 * function: func_02039C3C
 * address:  0x02039C3C
 * packet:   pkt_02039B5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020395EC  0x020395EC  arm
 *
 * Arm one pending vote on the record at `p`: park the tag at +0x46, mark the
 * slot unresolved with 0xff at +0x48, and record at +0x49 whether the record
 * is NOT the own link -- func_020395EC returning 0xff is the own link, which
 * is the one case that stores zero.
 *
 * The record pointer is copied to r4 before the two stores because the call
 * clobbers r0; the boolean is built with the `moveq`/`movne` pair rather than
 * a branch, which is 1.1p1's normal shape for a comparison stored straight to
 * memory.  The pair's ORDER is the source order of the arms: written as
 * `p->remote = (... != 0xff)` or as a ternary, 1.1p1 emits `movne r0,#1`
 * first and is 4 bytes out; the explicit if/else with the `== 0xff` arm first
 * puts `moveq r0,#0` first, as the image has it
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039C3C.c \
 *       --func func_02039C3C --addr 0x02039C3C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8  pad_00[0x46];
    u16 tag;
    u8  slot;
    u8  remote;
};

extern int func_020395EC(struct Rec *p);

void func_02039C3C(struct Rec *p, u16 tag)
{
    p->tag = tag;
    p->slot = 0xff;
    if (func_020395EC(p) == 0xff) {
        p->remote = 0;
    } else {
        p->remote = 1;
    }
}
