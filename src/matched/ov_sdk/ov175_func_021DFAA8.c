/*
 * function: func_021DFAA8
 * address:  0x021DFAA8
 * packet:   pkt_021DFAA8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DF928  0x021DF928  arm
 *
 * Fire-and-forget wrapper: kick 0x021DF928 and report success.
 */

extern void func_021DF928(char *obj, int v);

int func_021DFAA8(char *a, int b)
{
    func_021DF928(a, b);
    return 0;
}

