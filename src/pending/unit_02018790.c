/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x02018790..0x02018820
 * note:     144 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * The type half of the Hidden Power pair; the power half is
 * src/matched/unit_02018820.c and is EXACT.  It folds bit 0 of each of the six
 * 5 bit fields at substruct B +0x10 into a 0..63 index, scales it by 15/63,
 * reduces it below 17 with a subtract loop rather than a modulo, and indexes a
 * byte table at 0x0209E288.
 *
 * Why it is capped: the pool word at 0x0201881C is the only word in the whole
 * image that holds 0x0209E288, so the `literal` class discards its only
 * witness and the table cannot be attested.  Same shape as
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md.  No cut helps:
 * the load and the pool word are in the one function.
 *
 * The reduction is a `while (n > 16) n -= 16;` and not `n %= 16`, which would
 * be a single `ands`; and the division is unsigned, so the whole expression is
 * `n * 15 / 63`.
 *
 * VERSION SENSITIVITY: the 17 byte table at 0x0209E288 is type ids, which is
 * content numbering; it is expected to be identical in a White build, but it
 * is data rather than structure and should be re-read.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02018790.c \
 *       --addr 0x02018790 --thumb
 *
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209E288 is a table.
 *
 * symbols:
 *   func_02018790_Table  0x0209E288  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern const u8 func_02018790_Table[];

u32 func_02018790(void *p)
{
    u32 n = 0;

    if (func_02017E1C(p, 0x46, 0) & 1) {
        n += 1;
    }
    if (func_02017E1C(p, 0x47, 0) & 1) {
        n += 2;
    }
    if (func_02017E1C(p, 0x48, 0) & 1) {
        n += 4;
    }
    if (func_02017E1C(p, 0x49, 0) & 1) {
        n += 8;
    }
    if (func_02017E1C(p, 0x4A, 0) & 1) {
        n += 16;
    }
    if (func_02017E1C(p, 0x4B, 0) & 1) {
        n += 32;
    }
    n = n * 15 / 63;
    while (n > 16) {
        n -= 16;
    }
    return func_02018790_Table[n];
}
