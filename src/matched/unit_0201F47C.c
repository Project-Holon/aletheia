/*
 * unit:     yes
 * address:  0x0201F47C
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0201F47C
 *
 * "Is this string a packed nine-bit run", the predicate func_0201F4A0 tests
 * before unpacking.  A non-empty string whose first character is 0xF100 is
 * one; the marker is materialised as `movs r0, #0xF1` / `lsls r0, #8` rather
 * than from a pool word, so it is a plain constant.
 *
 * The two tests share one `movs r0, #0; pop` exit and neither jumps over an
 * inline epilogue, which is the single-conjunction shape of
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md:
 * written as two separate early returns the function grows a second epilogue.
 *
 * This is its own file rather than part of src/pending/sub_0201F4A0.c
 * because func_0201F4A0 holds the only call to it in the image.  Matched
 * apart, that call is an ordinary `label` witness from outside this range,
 * and the `matched` class then carries the site in func_0201F4A0 itself.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F47C.c \
 *       --addr 0x0201F47C --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_020458F8(void *s);
extern u16 *func_02045A90(void *s);

u32 func_0201F47C(void *s)
{
    if (func_020458F8(s) != 0 && *func_02045A90(s) == 0xF100) {
        return 1;
    }
    return 0;
}
