/*
 * function: func_02011CF0
 * address:  0x02011CF0
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011610  0x02011610  thumb
 *   func_02048AFC  0x02048AFC  arm
 *
 * Twelve bytes of stack filled by func_02011610 from the *second* argument
 * (the first word handed to it is r1, not r0), then the buffer goes to the ARM
 * function func_02048AFC together with the original first argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011CF0.c \
 *       --func func_02011CF0 --addr 0x02011CF0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern void func_02011610(void *a1, u8 *buf);
extern void func_02048AFC(void *a0, const u8 *buf);

void func_02011CF0(void *a0, void *a1)
{
    u8 buf[0xc];

    func_02011610(a1, buf);
    func_02048AFC(a0, buf);
}
