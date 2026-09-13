/*
 * A single matched function.
 *
 * unit:     yes
 * address:  0x02016374
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02016374
 *
 * symbols:
 *   func_02064CBC  0x02064CBC  arm
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to func_02064CBC. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func sub_02016374 --addr 0x02016374 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern void func_02064CBC(void *p);

void sub_02016374(void *obj)
{
    func_02064CBC((u8 *)obj + 0x34);
}
