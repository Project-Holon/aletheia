/*
 * function: func_0202B8F4
 * address:  0x0202B8F4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Artifact, not C: 0x0202B8F4 is a four-byte linker veneer
 * (`00 4b 18 47` = ldr r3, [pc, #0]; bx r3; .word 0x0202BAF5) sitting in a
 * run of identical veneers at 0x0202B8F4/0x0202B8FC/0x0202B904/0x0202B90C.
 * No C spelling produces this shape; reported in
 * docs/notes/pkt_0202B7BC.func_0202B8F4.c.txt and left parked.
 *
 * A bare tail-call thunk to func_0202BAF4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B8F4.c \
 *       --func func_0202B8F4 --addr 0x0202B8F4 --thumb --cc 1.1p1
 */

extern void func_0202BAF4(void);

void func_0202B8F4(void)
{
    func_0202BAF4();
}
