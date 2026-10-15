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
 * function: WORDSET_CheckF47C
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
 *
 * symbols:
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_GetLength  0x020458F8  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);

u32 WORDSET_CheckF47C(void *s)
{
    if (STRBUF_GetLength(s) != 0 && *STRBUF_GetChars(s) == 0xF100) {
        return 1;
    }
    return 0;
}
