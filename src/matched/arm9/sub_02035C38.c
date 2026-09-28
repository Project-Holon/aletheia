/*
 * function: sub_02035C38
 * address:  0x02035C38
 * packet:   pkt_02035C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A two-call forwarder in the ARM SDK-style block at 0x02035000..0x02038000:
 * "push {r3, lr}; bl sub_02035224; bl sub_02035C20; pop {r3, pc}", sixteen
 * bytes, no register setup between the calls so nothing about the argument
 * count is visible.
 *
 * Byte-correct.  sub_02035224 resolves on the `label` class (58 branches to
 * it image-wide, e.g. 0x02035460).  sub_02035C20 does not: this call is its
 * only reference anywhere in the image, so that site stays wildcarded and
 * caps the file at MATCH.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035C38.c \
 *       --func sub_02035C38 --addr 0x02035C38 --cc 1.1p1 --arm
 */

extern void sub_02035224(void);
extern void sub_02035C20(void);

void sub_02035C38(void)
{
    sub_02035224();
    sub_02035C20();
}
