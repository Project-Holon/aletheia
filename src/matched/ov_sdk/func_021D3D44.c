/*
 * function: func_021D3D44
 * address:  0x021D3D44
 * packet:   pkt_021D3D44
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D3D44 0x021D3D44 arm
 *
 * Only from the three live modes, tear the sound system down and park it at mode 2.
 * Addresses are Black-image addresses.
 */

extern void func_021D3CD0(void);
extern int func_021D3638(void);

int func_021D3D44(void)
{
    unsigned char mode = *(unsigned char *)(*(int *)0x021DE668 + 0xa90);

    if (mode != 1 && mode != 0x1a && mode != 0x1d)
        return 0;
    func_021D3CD0();
    func_021D3638();
    *(unsigned char *)(*(int *)0x021DE668 + 0xa90) = 2;
    return 1;
}

