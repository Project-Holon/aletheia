/*
 * function: func_021D3D8C
 * address:  0x021D3D8C
 * packet:   pkt_021D3D8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D3D8C 0x021D3D8C arm
 *
 * Advance the state byte at +0xa90 from 5 to 6.
 * Addresses are Black-image addresses.
 */

extern void func_021D21CC(void);

int func_021D3D8C(void)
{
    char *p = *(char **)0x021DE668;

    if (*(unsigned char *)(p + 0xa90) != 5)
        return 0;
    *(unsigned char *)(p + 0xa90) = 6;
    func_021D21CC();
    return 1;
}
