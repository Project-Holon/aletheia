/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x020090D8
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020090D8, sub_020090E0, sub_020090E8, sub_020090F0,
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29[3];
};

void sub_020090D8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk27 = value;
}

u8 sub_020090E0(const struct Sub020090B0Obj *obj)
{
    return obj->unk27;
}

void sub_020090E8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk28 = value;
}

u8 sub_020090F0(const struct Sub020090B0Obj *obj)
{
    return obj->unk28;
}

void sub_020090F8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk26 = value;
}

u8 sub_02009100(const struct Sub020090B0Obj *obj)
{
    return obj->unk26;
}

void sub_02009108(struct Sub020090B0Obj *obj, u16 value)
{
    obj->unk24 = value;
}

u16 sub_0200910C(const struct Sub020090B0Obj *obj)
{
    return obj->unk24;
}
