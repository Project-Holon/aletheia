/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_02019C38
 * address:  0x02019C38
 * note:     28 bytes including its pool word, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT, every concrete byte right (0 differing bytes, 28 of 28)
 *
 * The substruct permuter the whole poke_tool.c field machinery reaches every
 * block through: bits 13 to 17 of the personality word select one of 32
 * orderings, and the ordering's n-th byte is the offset of the n-th 0x20 byte
 * substruct inside the 0x80 byte block area at +0x08, so the table at
 * 0x0209E3A4 is 32 rows of four offsets drawn from 0x00, 0x20, 0x40 and 0x60.
 * src/matched/sub_02019388.c, src/matched/unit_020188B4.c and
 * src/pending/sub_02018E34.c all index through it, and ov188 calls it eight
 * more times.
 *
 * Why it is capped: the one relocation is an ABS32 against the table at
 * 0x0209E3A4, and a scan of every word in all 242 regions finds exactly one
 * occurrence of that address, the pool word at 0x02019C50 inside this
 * function.  The `literal` class discards its only witness under the honesty
 * rule and no cut helps, because the range cannot be made smaller than the one
 * function that holds the pool word.  The `matched` class never applies to
 * data (docs/MATCHING.md, "The matched class"), so this is the same shape as
 * src/matched/sub_02013FA8.c's private table and not the same shape as
 * sub_02018E34's runtime helper.  It closes the day anything else in the image
 * names 0x0209E3A4, or the day the table itself is a matched data entry.
 *
 * The neighbour func_02019C54, which is the one-entry memo in front of this
 * function, has no such site and was cut off into
 * src/matched/unit_02019C54.c rather than left capped with it
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md is the same
 * remedy applied to a data reference).
 *
 * What pinned the source: the mask is written `(pid & 0x3E000) >> 13` and not
 * `(pid >> 13) & 0x1F`.  The first is the `movs #0x3E` / `lsls #0xC` / `ands`
 * / `lsrs #0xD` the original has; the second folds to a `lsrs` and an `ands`
 * against a pooled 0x1F.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_02019C38.c \
 *       --addr 0x02019C38 --thumb
 *
 * symbols:
 *   gBlockOrder  0x0209E3A4  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mon {
    u32 unk00;
    u16 flags;
    u16 unk06;
    u8  block[0x80];
};

extern const u8 gBlockOrder[32][4];

void *func_02019C38(struct Mon *p, u32 pid, u32 n)
{
    return &p->block[gBlockOrder[(pid & 0x3E000) >> 13][n]];
}
