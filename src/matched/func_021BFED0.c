/*
 * function: func_021BFED0
 * address:  0x021BFED0
 * packet:   pkt_021BFED0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BFED0   0x021BFED0  arm
 *   func_021C0328   0x021C0328  arm
 *
 * Publish a new entry in the live table's byte 0x62, driving the changed flag both ways.
 * Addresses are Black-image addresses.
 */

extern void func_021C0328(int, int);

void func_021BFED0(int a)
{
    unsigned char **g = (unsigned char **)0x021DE560;
    unsigned char *p = *g;

    if (a == *(signed char *)(p + 0x62))
        return;
    func_021C0328(a, 1);
    func_021C0328(*(signed char *)(*g + 0x62), 0);
    *(char *)(*g + 0x62) = a;
}

