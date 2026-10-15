/*
 * function: BMP_MENUWORK_GetPlttFileId
 * address:  0x0201F548
 * packet:   pkt_0201F4A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted from src/pending/BMP_MENUWORK_GetPlttFileId.c on 2026-09-22 (family wave 5,
 * wordset.c).  Every concrete byte was already reproduced; only the one
 * relocation was open.
 *
 * The second of the two three-instruction byte-table lookups behind
 * src/matched/unit_0201F554.c -- BMP_MENUWORK_GetCharFileId reads the table at 0x0209E8C8
 * and this one the table at 0x0209E8CA, two bytes further on.  Both are
 * `return table[i];` and nothing else.
 *
 * WHAT CHANGED.  The blocker was the ABS32 against 0x0209E8CA.  Its only
 * literal-pool referrer anywhere in the image is the word at 0x0201F550
 * inside this very function (layout/data_objects.txt), which every
 * second-referrer class discards as lying inside the range under test, and
 * 0x0209E8CA is interior to the datum the listings start at 0x0209E8C8, so
 * `sole-ref/data` refuses it as not-a-start.  It is now carried by
 * `sole-ref/self`: the target is in a data section and the ROM word at the
 * relocation site already names exactly the address the relocation writes
 * there, which is the whole of that sub-kind's evidence.  The sibling
 * BMP_MENUWORK_GetCharFileId reaches EXACT by the stronger `sole-ref/data` instead,
 * because 0x0209E8C8 IS the datum start.
 *
 * Addresses are Black-image addresses.  The table's contents are a glyph
 * index map and are content data, not code shape; if it is ever sized
 * differently between Black and White that is a data-layout question, not a
 * code one.
 *
 * symbols:
 *   sub_0209E8CA_Map  0x0209E8CA  data  a1
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_GetPlttFileId.c \
 *       --func BMP_MENUWORK_GetPlttFileId --addr 0x0201F548 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern u8 sub_0209E8CA_Map[];

u8 BMP_MENUWORK_GetPlttFileId(int i)
{
    return sub_0209E8CA_Map[i];
}
