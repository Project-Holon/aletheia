/*
 * function: func_021BCB28
 * address:  0x021BCB28
 * packet:   pkt_021BCB28
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BCB28 0x021BCB28 arm
 *
 * If the signed byte at global+0x16 is -1, overwrite it with the argument.
 * Addresses are Black-image addresses.
 */

void func_021BCB28(signed char v)
{
    unsigned char *p = *(unsigned char **)0x021DE508;

    if (*(signed char *)(p + 0x16) == -1)
        *(signed char *)(p + 0x16) = v;
}

