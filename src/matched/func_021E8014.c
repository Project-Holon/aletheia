/*
 * function: func_021E8014
 * address:  0x021E8014
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
 * Forward and then return a status constant.
 */

extern void func_020307B0(void *);

int func_021E8014(char *p)
{
    func_020307B0(*(void **)(*(char **)(p + 0x2c) + 0x60));
    return 0x56;
}

