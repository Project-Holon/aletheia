/*
 * function: func_02189140
 * address:  0x02189140
 * packet:   pkt_ov021_02189140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02061CA4  0x02061CA4  arm
 */

typedef enum { B_FALSE, B_TRUE } Bool;

void func_02061CA4(int on, int b, void *c, int d);

/* Callback: forwards its last three arguments, with the first folded to 0/1. */
void func_02189140(int x, int b, void *c, int d)
{
    func_02061CA4(x == 0 ? B_FALSE : B_TRUE, b, c, d);
}
