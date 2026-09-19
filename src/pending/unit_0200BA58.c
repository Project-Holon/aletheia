/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x0200BA58..0x0200BA78 and 0x0200BAC8..0x0200BAD4
 * note:     three
 *           eight-byte tail calls in pkt_0200B938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * func_0200BA58 and func_0200BA68 hold their argument in a pool word rather
 * than in a `movs`, and 0xBC fits a `movs` immediate, so the argument is not
 * an integer literal: it is an R_ARM_ABS32 against a symbol whose absolute
 * value is 0x000000BC.  A linker-defined overlay id is what that looks like
 * on this SDK, and 188 is a real overlay number.  Six spellings of a plain
 * constant (u32, int, void *, const char *, unsigned long, float) all give
 * `movs r0, #0xbc` and 12 bytes; only a symbol reference gives the original
 * 16.  The address appears in no other literal pool in the image, so the
 * `literal` class discards its only witness and no cut helps, because
 * shrinking the range to one function keeps that function own pool word in
 * it.
 *
 * func_0200BAC8 loads 0x020271CC into its pool word, and nothing else in the
 * image branches to that address or holds a pointer to it, so `label` and
 * `literal` are both empty.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0200BA58.c
 *       --addr 0x0200BA58 --thumb
 * over the first two functions; func_0200BAC8 is kept here for the record and
 * verifies on its own at 0x0200BAC8.
 *
 * The `matched` class does not reach either half: 0xBC is an absolute symbol
 * value rather than a code address, and 0x020271CC is not matched.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov188_id       0x000000BC  data
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 ov188_id[];

extern void *func_02034AC4(void *a);
extern void *func_02034A5C(void *a);
extern void *func_020271CC(void *a, u32 id);

void *func_0200BA58(void)
{
    return func_02034AC4(ov188_id);
}

void *func_0200BA68(void)
{
    return func_02034A5C(ov188_id);
}
