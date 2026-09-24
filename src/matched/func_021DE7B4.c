/*
 * function: func_021DE7B4
 * address:  0x021DE7B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *
 * Tail call func_020307B0 with the pooled-offset word.
 */

extern void func_020307B0(void *);

void func_021DE7B4(char *p)
{
    func_020307B0(*(void **)(*(char **)(p + 0x2c) + 0xA190));
}

