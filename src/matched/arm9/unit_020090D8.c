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
 * function: CGEAR_SAVE_SetObtained, CGEAR_SAVE_GetObtained, CGEAR_SAVE_SetPowerSetting, CGEAR_SAVE_GetPowerSetting,
 *           CGEAR_SAVE_SetGsyncState, CGEAR_SAVE_GetGsyncState, CGEAR_SAVE_SetGsyncId, CGEAR_SAVE_GetGsyncId
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/CGEAR_SAVE_GetSize.c.  Seven of the eight carry no label in the
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

void CGEAR_SAVE_SetObtained(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk27 = value;
}

u8 CGEAR_SAVE_GetObtained(const struct Sub020090B0Obj *obj)
{
    return obj->unk27;
}

void CGEAR_SAVE_SetPowerSetting(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk28 = value;
}

u8 CGEAR_SAVE_GetPowerSetting(const struct Sub020090B0Obj *obj)
{
    return obj->unk28;
}

void CGEAR_SAVE_SetGsyncState(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk26 = value;
}

u8 CGEAR_SAVE_GetGsyncState(const struct Sub020090B0Obj *obj)
{
    return obj->unk26;
}

void CGEAR_SAVE_SetGsyncId(struct Sub020090B0Obj *obj, u16 value)
{
    obj->unk24 = value;
}

u16 CGEAR_SAVE_GetGsyncId(const struct Sub020090B0Obj *obj)
{
    return obj->unk24;
}
