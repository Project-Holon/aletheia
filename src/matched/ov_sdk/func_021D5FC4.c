/*
 * function: func_021D5FC4
 * address:  0x021D5FC4
 * packet:   pkt_021D5FC4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5FC4 0x021D5FC4 arm
 *
 * Set one of two flags in the global object depending on the pointer argument.
 * Addresses are Black-image addresses.
 */

void func_021D5FC4(int x)
{
    unsigned char *p = *(unsigned char **)0x021DE680;
    int v = 1;

    if (x == (int)(p + 0x610))
        *(unsigned char *)(p + 0x67c) = v;
    else
        *(unsigned char *)(p + 0x67d) = v;
}

