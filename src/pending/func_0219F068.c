/*
 * function: func_0219F068
 * address:  0x0219F068
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the object 0x60 bytes in.
 *
 * symbols:
 *   func_0219F7B4  0x0219F7B4  arm
 */

extern void func_0219F7B4(char *p);

void func_0219F068(char *p)
{
    func_0219F7B4(p + 0x60);
}

