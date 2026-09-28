/*
 * function: func_0216BB54
 * address:  0x0216BB54
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte at +1 of the block, or 0xff when there is none.
 *
 * symbols:
 *   func_02195E78  0x02195E78  arm  ov009
 */

extern unsigned char *func_02195E78(void);

int func_0216BB54(void)
{
    unsigned char *p = func_02195E78();

    return p ? *(unsigned char *)(p + 1) : 0xff;
}

