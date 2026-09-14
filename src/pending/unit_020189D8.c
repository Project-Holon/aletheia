/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x020189D8..0x02018A00, 40 bytes, two functions
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * The near miss the header of src/matched/unit_020188B4.c already records, now
 * written out.  func_020189D8 reads id 0x70 of the record, truncates it to a
 * byte and hands it to func_020189F0, which indexes an s8[][5] table at
 * 0x0209E2A4 with it; the second index arrives as the caller's own argument
 * and is applied with the register-offset `ldrsb`, which is what fixes the row
 * stride at five.  Same shape as src/matched/sub_02019B44.c over the table at
 * 0x0209E324.
 *
 * Why it is capped: the pool word at 0x020189FC is the only word in the image
 * that holds 0x0209E2A4.  func_020189F0's only caller is func_020189D8, so the
 * two cannot be split apart either.
 *
 * VERSION SENSITIVITY: the table is content data indexed by a record field;
 * expected identical in a White build, but it is data.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_020189D8.c \
 *       --addr 0x020189D8 --thumb
 *
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209E2A4 is a table.
 *
 * symbols:
 *   func_020189F0_Table  0x0209E2A4  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed char   s8;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern const s8 func_020189F0_Table[][5];

s8 func_020189F0(u32 a, u32 b);

s8 func_020189D8(void *p, u32 b)
{
    return func_020189F0((u8)func_02017E88(p, 0x70, 0), b);
}

s8 func_020189F0(u32 a, u32 b)
{
    return func_020189F0_Table[a][b];
}
