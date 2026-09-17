/*
 * function: func_0202AB7C
 * address:  0x0202AB7C
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * A bare tail-call thunk to func_0202AB8C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB7C.c \
 *       --func func_0202AB7C --addr 0x0202AB7C --thumb --cc 1.1p1
 */

extern void func_0202AB8C(void);

void func_0202AB7C(void)
{
    func_0202AB8C();
}
