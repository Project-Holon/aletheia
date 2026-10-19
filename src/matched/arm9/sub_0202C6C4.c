/*
 * unit:     no
 * function: ISS_SWITCH_GetVolume
 * address:  0x0202C6C4
 * packet:   pkt_0202C6C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *   _s32_div_f    0x0209C0A4  arm
 *
 * A dense switch over the window's state accessor
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), the third
 * of the family after src/matched/unit_0202C760.c and the near miss at
 * 0x0202C5F0. It converts the window's open/close animation counter into a
 * 0..0x7F fraction: states 0 and 1 are the two endpoints and return a
 * constant, states 2 and 3 scale unk04 against unk06 and differ only in
 * which end of the range they measure from.
 *
 * The result local is left uninitialised on the default path, which is why
 * the `bhi` over the table lands on the shared `adds r0, r5, #0` tail and
 * not on a `movs r0, #0`: the source switch has no default arm and no
 * trailing return. Both divisions are signed, so both operands promote to
 * `int` even though the fields are `u16`, and the helper the relocation
 * names is _s32_div_f rather than the unsigned twin
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * This file exists as a single rather than inside a unit with 0x0202C710
 * because 0x0202C710's `bl` at 0x0202C716 is the only reference to
 * 0x0202C6C4 in the whole image: one range holding both destroys the only
 * witness, and an EXACT entry here supplies it through the `matched` class
 * instead (docs/MATCHING.md, "The matched class"). Same move as
 * src/matched/unit_0202C760.c made for sub_0202C688.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_GetVolume.c \
 *       --func ISS_SWITCH_GetVolume --addr 0x0202C6C4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj0202C6C4 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
};

struct Obj0202C6B8;
extern u32 sub_0202C6B8(struct Obj0202C6B8 *p);

u32 ISS_SWITCH_GetVolume(struct Obj0202C6C4 *p)
{
    u32 v;

    switch (sub_0202C6B8((struct Obj0202C6B8 *)p)) {
    case 0:
        return 0x7F;
    case 1:
        return 0;
    case 2:
        v = p->unk04 * 0x7F / p->unk06;
        break;
    case 3:
        v = 0x7F - p->unk04 * 0x7F / p->unk06;
        break;
    }
    return v;
}
