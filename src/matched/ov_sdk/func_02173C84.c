/*
 * function: func_02173C84
 * address:  0x02173C84
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +0x16 of the block, or 0xff when there is none.
 *
 * symbols:
 *   func_021763AC  0x021763AC  arm  ov009
 */

extern unsigned char *func_021763AC(void);

int func_02173C84(void)
{
    unsigned char *p = func_021763AC();

    return p == 0 ? 0xff : *(unsigned char *)(p + 0x16);
}

