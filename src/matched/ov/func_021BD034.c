/*
 * function: func_021BD034
 * address:  0x021BD034
 * packet:   pkt_021BD034
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020419E4 0x020419E4  arm
 *
 * Tail call to the ARM9 function at 0x020419E4: loads the pointer from the pool and branches through it.
 */

extern void func_020419E4(void);

void func_021BD034(char *a0)
{
    func_020419E4();
}
