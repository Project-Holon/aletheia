/*
 * function: func_021B9AD0
 * address:  0x021B9AD0
 * packet:   pkt_021B9AD0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0201C4E4(int);
extern void func_020310C4(int);

void func_021B9AD0(char *p)
{
    func_0201C4E4(*(int *)(p + 0x10));
    func_020310C4(*(int *)(p + 4));
}
