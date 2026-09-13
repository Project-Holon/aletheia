/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008D1C
 * packet:   pkt_02008CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008D1C, sub_02008D58
 *
 * alias: the first half of the clamped read-modify-write layer over the save
 * block with id 0x26 (src/matched/unit_02008C58.c).  Each of these takes the
 * block and a counter index, looks the counter's ceiling up with
 * sub_02008CF8, unlocks the block with sub_02008C94, writes through
 * sub_02008CD4 and re-checksums with sub_02008C64.
 *
 * The cut at 0x02008DAC is the one the header of unit_02008C58.c recorded as
 * viable: sub_02008CF8, sub_02008C64, sub_02008C94, sub_02008CB4 and
 * sub_02008CD4 are each called from both halves, so each half is the other's
 * outside witness and no site is left without one.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008D1C.c \
 *       --addr 0x02008D1C --thumb
 */

typedef unsigned int u32;

struct Sub02008C20Obj;

extern u32  sub_02008CF8(int i);
extern void sub_02008C64(struct Sub02008C20Obj *obj, int i);
extern void sub_02008C94(struct Sub02008C20Obj *obj, int i);
extern u32  sub_02008CB4(struct Sub02008C20Obj *obj, int i);
extern u32  sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value);

u32 sub_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    if (value < max) {
        result = sub_02008CD4(obj, i, value);
    } else {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}

u32 sub_02008D58(struct Sub02008C20Obj *obj, int i, u32 limit)
{
    u32 max = sub_02008CF8(i);
    u32 result;

    sub_02008C94(obj, i);
    result = sub_02008CB4(obj, i);
    if (limit > max) {
        limit = max;
    }
    if (result < limit) {
        result = sub_02008CD4(obj, i, limit);
    } else if (result > max) {
        result = sub_02008CD4(obj, i, max);
    }
    sub_02008C64(obj, i);
    return result;
}
