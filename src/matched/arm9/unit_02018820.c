/*
 * unit:     yes
 * address:  0x02018820
 * packet:   pkt_0201862C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetHiddenPowerPower
 *
 * Folds the six ids 0x46 to 0x4B, the six 5 bit fields of substruct B +0x10
 * that POKE_TOOL_GetBoxValueRaw reads, into a 0 to 63 index on bit 1 of each and scales
 * it to 30..70.  Its neighbour func_02018790 is the same fold on bit 0 with a
 * table lookup at the end, and the two are the pair a Hidden Power power and
 * type are computed with.
 *
 * The range is one function on purpose.  func_02018790, immediately before,
 * reads a byte table at 0x0209E288 whose only reference anywhere in the image
 * is the pool word under test, so it caps at MATCH however it is written; and
 * func_020188AC, immediately after, is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk whose pool word is the
 * only reference to POKE_TOOL_CheckBoxTmCompat in the image, so it caps too.  Both are
 * byte-correct and neither can be cut free; this middle function is what is
 * left, and it is clean.
 *
 * The six tests are `(x & 3) > 1` rather than a bit test, which is `movs #3` /
 * `ands` / `cmp #1` / `bls`; the accumulator takes `adds rD, rN, #imm3` for 1,
 * 2 and 4 and `adds rD, #imm8` from 8 up, which is encoding and not source.
 * The scale is one `muls` by 40 and one `_u32_div_f` by 63, so the division is
 * unsigned and written as `n * 40 / 63 + 30`; `+ 30` folds into the `adds`
 * after the call.
 *
 * Nothing here is version specific: the six ids are structure field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018820.c \
 *       --addr 0x02018820 --thumb
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);

u32 POKE_TOOL_GetHiddenPowerPower(void *p)
{
    u32 n = 0;

    if ((func_02017E1C(p, 0x46, 0) & 3) > 1) {
        n += 1;
    }
    if ((func_02017E1C(p, 0x47, 0) & 3) > 1) {
        n += 2;
    }
    if ((func_02017E1C(p, 0x48, 0) & 3) > 1) {
        n += 4;
    }
    if ((func_02017E1C(p, 0x49, 0) & 3) > 1) {
        n += 8;
    }
    if ((func_02017E1C(p, 0x4A, 0) & 3) > 1) {
        n += 16;
    }
    if ((func_02017E1C(p, 0x4B, 0) & 3) > 1) {
        n += 32;
    }
    return n * 40 / 63 + 30;
}
