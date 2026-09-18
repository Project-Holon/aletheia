/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * second pool word, file_020A79C0, whose only literal pool in the whole image
 * is this function's own, at 0x0203653C and therefore inside the compared
 * range.  The `string` class cannot stand in for it either: 0x020A79C0 holds
 * the one-character string "0" (the listing shows `.word 0x00000030` there,
 * preceded by the terminator of "pDataArea"), and attest_string() requires at
 * least four printable characters before the NUL, so the address is refused by
 * rule 2.  It closes the day the same string address is referenced from a pool
 * outside this range, or the rule's four-character floor is revisited for
 * one-character strings.  The three other sites resolve: func_020364D4 and
 * func_02034714 as `label`, file_020A79A4 as `literal`.
 *
 * function: func_02036500
 * address:  0x02036500
 * packet:   pkt_0203640C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_020364D4    0x020364D4  arm
 *   func_02034714    0x02034714  arm
 *   file_020A79A4    0x020A79A4  data
 *   file_020A79C0    0x020A79C0  data
 *
 * A byte out of a one-byte scratch slot, or an assert: the scratch slot's
 * address goes to func_020364D4 together with two literal 1s, and only an
 * answer of exactly 1 yields the byte that was written there.  Anything else
 * reports through func_02034714 with the source file at 0x020A79A4 and line
 * 0x6C (108) and the message at 0x020A79C0, then returns 0.  Both pool words
 * are string addresses fixed by the packed string area, and the whole
 * conditional prologue is the compiler's `return`-in-`if` shape: the byte is
 * loaded only on the equal path and the epilogue is shared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02036500.c \
 *       --func func_02036500 --addr 0x02036500 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020364D4(u32 a, void *out, u32 b, u32 c);
extern void func_02034714(const char *file, u32 line, const char *fmt);
extern const char file_020A79A4[];
extern const char file_020A79C0[];

u32 func_02036500(u32 a)
{
    u8 b;

    if (func_020364D4(a, &b, 1, 1) == 1)
        return b;
    func_02034714(file_020A79A4, 0x6C, file_020A79C0);
    return 0;
}
