/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202D5CC
 * packet:   pkt_0202D1AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKEGRA_GetTrainerArcID, POKEGRA_GetTrainerCgrArcIndex
 *
 * symbols:
 *   sub_0202D5D8_Table  0x020A023C  data
 *
 * The first two functions of the accessor run at 0x0202D5CC; the other
 * seven are src/matched/unit_0202D5F8.c. POKEGRA_GetTrainerArcID is not part of the
 * family, it is a two-value picker that happens to sit in front of it.
 *
 * Leaves with no prologue at all, so `disasm.py` labels none of them and
 * the whole 296-byte run at 0x0202D5CC arrives in the listing as `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Eight of
 * the nine are the same function with a different constant added to the
 * result: a 0x6A-entry byte table at 0x020A023C maps a small id to a
 * record index, the record is eight bytes wide, and the added constant is
 * which field of it the caller wants. The `flags & 1` arm bypasses the
 * table and uses the id as the index directly.
 *
 * The added constants run 0, 1, 7, 2, 3, 4, 5, 6 in address order, which
 * is the order the functions were written in and not the order of the
 * fields.
 *
 * The `lsls #0x18` / `lsrs #0x18` pair in the first arm is an explicit
 * `(u8)` cast, so the id parameter is wider than a byte and the
 * truncation is in the source; declaring the parameter `u8` truncates at
 * the caller and the pair disappears.
 *
 * Why the run is two files and not one: 0x020A023C is named by exactly
 * eight literal pool words in the whole image and they are the eight of
 * this run, so a single range covering all of them has no witness left
 * under the honesty rule and every relocation stays wildcarded. Cut
 * between 0x0202D5D8 and 0x0202D5F8 and each file is the other's witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, the
 * same remedy for a data address rather than a call target): this file
 * sees the seven pool words of unit_0202D5F8.c and that one sees the one at 0x0202D5F4 in this file.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202D5CC.c  *       --addr 0x0202D5CC --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 sub_0202D5D8_Table[];

u32 POKEGRA_GetTrainerArcID(u32 a)
{
    if (a != 0) {
        return 0x49;
    }
    return 0x48;
}

u32 POKEGRA_GetTrainerCgrArcIndex(u32 id, u32 flags)
{
    u32 v;

    if (flags & 1) {
        v = (u8)id;
    } else if (id > 0x69) {
        v = 0;
    } else {
        v = sub_0202D5D8_Table[id];
    }
    return v * 8;
}
