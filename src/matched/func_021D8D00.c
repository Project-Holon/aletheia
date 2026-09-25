/*
 * function: func_021D8D00
 * address:  0x021D8D00
 * packet:   pkt_021D8D00
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

void func_021D8D00(char *p)
{
    if (*(void (**)(void))(p + 0x2c) != 0) {
        (*(void (**)(char *))(p + 0x2c))(p);
        if (*(u32 *)(p + 8) != 0)
            *(u32 *)(p + 0x2c) = 0;
    }
}
