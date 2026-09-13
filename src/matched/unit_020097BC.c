/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x020097BC
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020097BC
 *
 * alias: wifilist.c.  The original file name is in the image: the allocator at
 * 0x020097C4 passes 0x020A7198 to the debug allocator at 0x02030734 and those
 * bytes spell "wifilist.c".  This is the four byte function that returns the
 * record's size, and 0x7C4 is exactly what the constructor at 0x02009800
 * clears, which is what ties the two together.
 *
 * NEAR MISS, 0x020097C4, 34 bytes, MATCH with every concrete byte right,
 * skipped.  It is the allocator,
 *
 *   struct WifiList *sub_020097C4(u32 heap)
 *   {
 *       struct WifiList *p = sub_02030734((u16)heap, 0x7C4, 1,
 *                                         sub_020097C4_File, 57);
 *       sub_02009800(p);
 *       return p;
 *   }
 *
 * and the pool word holding 0x020A7198 is the only reference to that address in
 * the image.  The `string` class cannot attest it either: the run in front of
 * "wifilist.c" is the static table at 0x020A7174, not a string, so condition 5
 * of the rule refuses.  Exactly the shape of the "mail.c" case; see
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020097BC.c \
 *       --addr 0x020097BC --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020097BCObj {
    u8 unk000[0x7C4];
};

u32 sub_020097BC(void)
{
    return sizeof(struct Sub020097BCObj);
}
