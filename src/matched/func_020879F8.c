/*
 * function: func_020879F8
 * address:  0x020879F8
 * packet:   pkt_020879F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020879F8    0x020879F8  arm
*/

extern void func_020879F8(void);

asm void func_020879F8(void)
{
    subs	r0, r0, #4
    bhs	func_020879F8
    bx	lr
}
