/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200A840
 * packet:   pkt_0200A848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200A840
 *
 * 8 bytes, 0x0200A840..0x0200A848, one function, which carries no label in
 * the generated listing: it is the three-instruction size getter that opens
 * every save block file in this region, and it has no prologue.
 *
 * The size it returns, 0x2DC, is what fixes the tail of the record.  The
 * constructor in the next function hands out the two sub-objects at +0x1E8
 * and +0x1FC, so the only free choice left is how much follows the second
 * one, and 0xE0 is what makes sizeof agree with the getter.
 *
 * Near miss, and the reason this unit stops at 0x0200A848: func_0200A848, 28
 * bytes, reproduces every concrete byte and caps at MATCH.  It is
 *
 *     void func_0200A848(struct Rec2DC *p)
 *     {
 *         EVENT_FIELD_PROCLINK_InitEventdataSystem(p);
 *         EVENT_FIELD_PROCLINK_InitIdList(p->unk1E8);
 *         EVENT_FIELD_PROCLINK_InitReturnHeader(p->unk1FC);
 *     }
 *
 * and all three callees live in overlay space.  0x02161D98 is attested by the
 * overlay-resident callee class (label x1, witness 0x02012674).  The other
 * two are not: 0x02161EEC has exactly two branch witnesses image wide, one of
 * them this call and the other 0x02186378, and 0x02161F00 has exactly one,
 * this call.  Neither address carries a func_ label in any overlay that
 * contains it, which is part 1 of the overlay rule, so neither can be
 * attested and no cut helps: the only witness is the call that needs it.  It
 * closes the day disasm.py labels either address.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec2DC {
    u8 unk000[0x1E8];
    u8 unk1E8[0x14];
    u8 unk1FC[0xE0];
};

u32 func_0200A840(void)
{
    return sizeof(struct Rec2DC);
}
